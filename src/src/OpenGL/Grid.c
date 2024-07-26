/* Grid.c */
/**********************************************************************************************************
Copyright (c) 2002-2007 Abdul-Rahman Allouche. All rights reserved

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files (the Gabedit), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions
  of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED
TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.
************************************************************************************************************/


#include "../../Config.h"
#include "../Utils/Constantes.h"
#include "GlobalOrb.h"
#include "StatusOrb.h"
#include "UtilsOrb.h"
#include "ColorMap.h"
#include "../MultiGrid/PoissonMG.h"
#include "../Utils/UtilsInterface.h"

/************************************************************************/
static gdouble get_value_elf_becke(gfloat x,gfloat y,gfloat z,gint dump);
static gdouble get_value_elf_savin(gfloat x,gfloat y,gfloat z,gint dump);
static gdouble get_value_sas(gfloat x,gfloat y,gfloat z,gint dump);
/************************************************************************/
gdouble get_value_STF(gfloat x,gfloat y,gfloat z,gint i,gint n)
{
	gdouble v = 0.0;
	gdouble d = 0;
	gdouble de = 0;
	gdouble xi = x-SAOrb[i].Stf[n].C[0];
	gdouble yi = y-SAOrb[i].Stf[n].C[1];
	gdouble zi = z-SAOrb[i].Stf[n].C[2];
	gint ll = 	SAOrb[i].Stf[n].l[0]+ 
	    		SAOrb[i].Stf[n].l[1]+
	    		SAOrb[i].Stf[n].l[2];

	d = (xi*xi)+(yi*yi)+(zi*zi);
	d = sqrt(d);
	de =d*SAOrb[i].Stf[n].Ex;
        if(de>40) return 1e-14;
	v = SAOrb[i].Stf[n].Coef*pow(d,SAOrb[i].Stf[n].pqn-1-ll)*
	    pow(xi,SAOrb[i].Stf[n].l[0])*
	    pow(yi,SAOrb[i].Stf[n].l[1])*
	    pow(zi,SAOrb[i].Stf[n].l[2])*
	    exp(-de);
	return v;
}
/**************************************************************/
gdouble get_value_CSTF(gfloat x,gfloat y,gfloat z,gint i)
{
	gdouble v = 0.0;
	gint n;

        for(n=0;n<SAOrb[i].N;n++)
	   v+= get_value_STF(x,y,z,i,n);

	return v;
}
/************************************************************************/
gdouble get_value_GTF(gfloat x,gfloat y,gfloat z,gint i,gint n)
{
	gdouble v = 0.0;
	gdouble d = 0;
	gdouble xi = x-AOrb[i].Gtf[n].C[0];
	gdouble yi = y-AOrb[i].Gtf[n].C[1];
	gdouble zi = z-AOrb[i].Gtf[n].C[2];

	d = (xi*xi)+(yi*yi)+(zi*zi);
	d *=AOrb[i].Gtf[n].Ex;
        if(d>40) return 1e-14;
	v = AOrb[i].Gtf[n].Coef*
	    pow(xi,AOrb[i].Gtf[n].l[0])*
	    pow(yi,AOrb[i].Gtf[n].l[1])*
	    pow(zi,AOrb[i].Gtf[n].l[2])*
	    exp(-d);
	return v;
}
/**************************************************************/
gdouble get_value_CGTF(gfloat x,gfloat y,gfloat z,gint i)
{
	gdouble v = 0.0;
	gint n;

        for(n=0;n<AOrb[i].N;n++)
	   v+= get_value_GTF(x,y,z,i,n);

	return v;
}
/**************************************************************/
gdouble get_value_CBTF(gfloat x,gfloat y,gfloat z,gint i)
{
	if(AOrb) return get_value_CGTF(x, y, z, i);
	else if(SAOrb) return get_value_CSTF(x, y, z, i);
	else return 0;
}
/**************************************************************/
gdouble get_value_orbital(gfloat x,gfloat y,gfloat z,gint k)
{
	
	gdouble v=0.0;
	gint i;

	if(TypeSelOrb == 1)
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefAlphaOrbitals[k][i])>1e-10)
			v+=CoefAlphaOrbitals[k][i]*get_value_CBTF(x,y,z,i);
	}
	else
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefBetaOrbitals[k][i])>1e-10)
			v+=CoefBetaOrbitals[k][i]*get_value_CBTF(x,y,z,i);
	}
	return v;
}
/**************************************************************/
gdouble get_value_electronic_density_on_atom(gfloat x,gfloat y,gfloat z,gint n)
{
	
	gdouble v1 = 0.0;
	gdouble v2 = 0.0;
	gdouble cgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gdouble *PhiAlpha = g_malloc(GeomOrb[n].NAlphaOrb*sizeof(gdouble));
	gdouble *PhiBeta  = g_malloc(GeomOrb[n].NBetaOrb*sizeof(gdouble));

	for(k1=0;k1<GeomOrb[n].NAlphaOrb;k1++)
			PhiAlpha[k1] = 0.0;
	for(k2=0;k2<GeomOrb[n].NBetaOrb;k2++)
			PhiBeta[k2] = 0.0;

	for(i=0;i<GeomOrb[n].NAOrb;i++)
	{
		
		cgv = get_value_CBTF(x,y,z,GeomOrb[n].NumOrb[i]);
		for(k1=0;k1<GeomOrb[n].NAlphaOrb;k1++)
				PhiAlpha[k1] += GeomOrb[n].CoefAlphaOrbitals[k1][i]*cgv;
		
		for(k2=0;k2<GeomOrb[n].NBetaOrb;k2++)
				PhiBeta[k2]  += GeomOrb[n].CoefBetaOrbitals[k2][i]*cgv;
 	}
	v1 = 0.0;
	for(k1=0;k1<GeomOrb[n].NAlphaOrb;k1++)
		if(GeomOrb[n].OccAlphaOrbitals[k1]>1e-8)
			v1 += GeomOrb[n].OccAlphaOrbitals[k1]*PhiAlpha[k1]*PhiAlpha[k1];
	v2 = 0.0;
	for(k2=0;k2<GeomOrb[n].NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
			v2 += GeomOrb[n].OccBetaOrbitals[k2]*PhiBeta[k2]*PhiBeta[k2];

	g_free(PhiAlpha);
	g_free(PhiBeta);
	return v1+v2;
}
/**************************************************************/
gdouble get_value_electronic_density_atomic(gfloat x,gfloat y,gfloat z,gint dump)
{
	gdouble v = 0.0;
	gint i;
	for(i=0;i<Ncenters;i++)
		v += get_value_electronic_density_on_atom(x,y,z,i);
		
	return v;
}

/**************************************************************/
gdouble get_value_electronic_density(gfloat x,gfloat y,gfloat z,gint dump)
{
	
	gdouble v1 = 0.0;
	gdouble v2 = 0.0;
	gdouble cgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gdouble *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *PhiBeta  = g_malloc(NBetaOrb*sizeof(gdouble));

	for(k1=0;k1<NAlphaOrb;k1++)
			PhiAlpha[k1] = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
			PhiBeta[k2] = 0.0;

	for(i=0;i<NAOrb;i++)
	{
		
		cgv = get_value_CBTF(x,y,z,i);
		for(k1=0;k1<NAlphaOcc;k1++)
				PhiAlpha[k1] += CoefAlphaOrbitals[k1][i]*cgv;
		
		for(k2=0;k2<NBetaOcc;k2++)
				PhiBeta[k2]  += CoefBetaOrbitals[k2][i]*cgv;
 	}
	v1 = 0.0;
	for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
			v1 += OccAlphaOrbitals[k1]*PhiAlpha[k1]*PhiAlpha[k1];
	v2 = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
			v2 += OccBetaOrbitals[k2]*PhiBeta[k2]*PhiBeta[k2];

	g_free(PhiAlpha);
	g_free(PhiBeta);
	return v1+v2;
}
/**************************************************************/
gdouble get_value_electronic_density_bonds(gfloat x,gfloat y,gfloat z,gint dump)
{
	gdouble v = 0.0;
	v = get_value_electronic_density(x,y,z,dump);
	v -= get_value_electronic_density_atomic(x,y,z,dump);
	return v;
}
/**************************************************************/
gdouble get_value_spin_density(gfloat x,gfloat y,gfloat z,gint dump)
{
	
	gdouble v1 = 0.0;
	gdouble v2 = 0.0;
	gdouble cgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gdouble *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *PhiBeta  = g_malloc(NBetaOrb*sizeof(gdouble));

	for(k1=0;k1<NAlphaOrb;k1++)
			PhiAlpha[k1] = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
			PhiBeta[k2] = 0.0;

	for(i=0;i<NAOrb;i++)
	{
		
		cgv = get_value_CBTF(x,y,z,i);
		for(k1=0;k1<NAlphaOcc;k1++)
				PhiAlpha[k1] += CoefAlphaOrbitals[k1][i]*cgv;
		
		for(k2=0;k2<NBetaOcc;k2++)
				PhiBeta[k2]  += CoefBetaOrbitals[k2][i]*cgv;
 	}
	v1 = 0.0;
	for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
			v1 += OccAlphaOrbitals[k1]*PhiAlpha[k1]*PhiAlpha[k1];
	v2 = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
			v2 += OccBetaOrbitals[k2]*PhiBeta[k2]*PhiBeta[k2];

	g_free(PhiAlpha);
	g_free(PhiBeta);
	return v1-v2;
}
/*********************************************************************************/
gboolean test_grid_all_positive(Grid* grid)
{
	gint i;
	gint j;
	gint k;
	if(!grid) return FALSE;

	for(i=0;i<grid->N[0];i++)
		for(j=0;j<grid->N[1];j++)
			for(k=0;k<grid->N[2];k++)
				if(grid->point[i][j][k].C[3]<0 && fabs(grid->point[i][j][k].C[3])>1e-10) return FALSE;
	return TRUE;
}
/**************************************************************/
void reset_limits_for_grid(Grid* grid)
{
	gint i,j,k;
	gdouble v;
	gboolean begin = TRUE;
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				v = grid->point[i][j][k].C[3];
				if(begin)
				{
					begin = FALSE;
        				grid->limits.MinMax[0][3] =  v;
        				grid->limits.MinMax[1][3] =  v;
				}
                		else
				{
        				if(grid->limits.MinMax[0][3]>v) grid->limits.MinMax[0][3] =  v;
        				if(grid->limits.MinMax[1][3]<v) grid->limits.MinMax[1][3] =  v;
				}
			}
		}
	}
}
/**************************************************************/
Grid* grid_point_alloc(gint N[],GridLimits limits)
{
	Grid* grid = g_malloc(sizeof(Grid));
	gint i,j;
  	
	grid->N[0] = N[0];
	grid->N[1] = N[1];
	grid->N[2] = N[2];
	grid->point = g_malloc( grid->N[0]*sizeof(Point5**));
	for(i=0;i< grid->N[0] ;i++)
	{
		grid->point[i] = g_malloc(grid->N[1]*sizeof(Point5*));
		for(j=0;j< grid->N[1] ;j++)
			grid->point[i][j] = g_malloc(grid->N[2]*sizeof(Point5));
	}
		
	grid->limits = limits;
	grid->mapped  = FALSE;
	return grid;
}
/**************************************************************/
Grid* free_grid(Grid* localGrid)
{
	gint i,j;
	gboolean id = (localGrid==grid);
	if(!localGrid) return NULL;
	for(i=0;i< localGrid->N[0] ;i++)
	{
		for(j=0;j< localGrid->N[1] ;j++)
			g_free(localGrid->point[i][j]);
		g_free(localGrid->point[i]);
	}
	g_free(localGrid->point);
	g_free(localGrid);
	localGrid=NULL;
	if(id)
	{
		GtkWidget* handleBoxColorMapGrid = g_object_get_data(G_OBJECT(PrincipalWindow), "HandleboxColorMapGrid ");
		color_map_hide(handleBoxColorMapGrid);
	}
	return localGrid;
}
/**************************************************************/
Grid* copyGrid(Grid* grid)
{
	Grid *newGrid = NULL;
	gint i,j,k;

	newGrid = grid_point_alloc(grid->N,grid->limits);
	
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				newGrid->point[i][j][k].C[0] = grid->point[i][j][k].C[0];
				newGrid->point[i][j][k].C[1] = grid->point[i][j][k].C[1];
				newGrid->point[i][j][k].C[2] = grid->point[i][j][k].C[2];
				newGrid->point[i][j][k].C[3] = grid->point[i][j][k].C[3];
			}
		}
	}
 
	return newGrid;
}
/**************************************************************/
void print_grid_point(Grid* grid)
{
	gint i;
	gint j;
	gint k;
	gint n=-1;
	printf("%d %d %d \n",grid->N[0],grid->N[1],grid->N[2]);
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				n++;
				printf("%f %f %f %f \n",
				grid->point[i][j][k].C[0],
				grid->point[i][j][k].C[1],
				grid->point[i][j][k].C[2],
				grid->point[i][j][k].C[3]);
			}
		}
	}
	printf("Vlimits = %f %f \n", grid->limits.MinMax[0][3] , grid->limits.MinMax[1][3] );

}
/**************************************************************/
Grid* define_grid_point(gint N[],GridLimits limits,Func3d func)
{
	Grid* grid;
	gint i;
	gint j;
	gint k;
	gfloat x;
	gfloat y;
	gfloat z;
	gfloat v;
	gboolean beg = TRUE;
	gfloat scale;
	gfloat V0[3];
	gfloat V1[3];
	gfloat V2[3];
	gfloat firstPoint[3];

	grid = grid_point_alloc(N,limits);
	for(i=0;i<3;i++)
	{
	V0[i] = firstDirection[i] *(grid->limits.MinMax[1][0]-grid->limits.MinMax[0][0]);
	V1[i] = secondDirection[i]*(grid->limits.MinMax[1][1]-grid->limits.MinMax[0][1]);
	V2[i] = thirdDirection[i] *(grid->limits.MinMax[1][2]-grid->limits.MinMax[0][2]);
	}
	for(i=0;i<3;i++)
	{
		firstPoint[i] = V0[i] + V1[i] + V2[i];
		firstPoint[i] = originOfCube[i] - firstPoint[i]/2;
	}
	for(i=0;i<3;i++)
	{
		V0[i] /= grid->N[0]-1;
		V1[i] /= grid->N[1]-1;
		V2[i] /= grid->N[2]-1;
	}
	
	progress_orb(0,GABEDIT_PROGORB_COMPGRID,TRUE);
	scale = (gfloat)1.01/grid->N[0];
 
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				x = firstPoint[0] + i*V0[0] + j*V1[0] +  k*V2[0]; 
				y = firstPoint[1] + i*V0[1] + j*V1[1] +  k*V2[1]; 
				z = firstPoint[2] + i*V0[2] + j*V1[2] +  k*V2[2]; 
				
				v = func( x, y, z,NumSelOrb);
				grid->point[i][j][k].C[0] = x;
				grid->point[i][j][k].C[1] = y;
				grid->point[i][j][k].C[2] = z;
				grid->point[i][j][k].C[3] = v;
				if(beg)
				{
					beg = FALSE;
        				grid->limits.MinMax[0][3] =  v;
        				grid->limits.MinMax[1][3] =  v;
				}
                		else
				{
        				if(grid->limits.MinMax[0][3]>v)
        					grid->limits.MinMax[0][3] =  v;
        				if(grid->limits.MinMax[1][3]<v)
        					grid->limits.MinMax[1][3] =  v;
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPGRID,TRUE);
			break;
		}

		progress_orb(scale,GABEDIT_PROGORB_COMPGRID,FALSE);
	}

	if(CancelCalcul)
	{
		grid = free_grid(grid);
	}
	return grid;
}
/**************************************************************/
Grid* define_grid(gint N[],GridLimits limits)
{
	Grid *grid = NULL;
	set_status_label_info("Grid","Computing");
	CancelCalcul = FALSE;
	switch(TypeGrid)
	{
		case GABEDIT_TYPEGRID_ORBITAL :
			grid = define_grid_point(N,limits,get_value_orbital);
			break;
		case GABEDIT_TYPEGRID_EDENSITY :
			grid = define_grid_point(N,limits,get_value_electronic_density);
			break;
		case GABEDIT_TYPEGRID_DDENSITY :
			grid = define_grid_point(N,limits,get_value_electronic_density_bonds);
			break;
		case GABEDIT_TYPEGRID_ADENSITY :
			grid = define_grid_point(N,limits,get_value_electronic_density_atomic);
			break;
		case GABEDIT_TYPEGRID_SDENSITY :
			grid = define_grid_point(N,limits,get_value_spin_density);
			break;
		case GABEDIT_TYPEGRID_ELFBECKE :
			grid = define_grid_point(N,limits,get_value_elf_becke);
			break;
		case GABEDIT_TYPEGRID_ELFSAVIN :
			grid = define_grid_point(N,limits,get_value_elf_savin);
			break;
		case GABEDIT_TYPEGRID_SAS :
			grid = define_grid_point(N,limits,get_value_sas);
			break;
		case GABEDIT_TYPEGRID_MEP_CHARGES :
			grid = compute_mep_grid_using_partial_charges(N, limits);
			break;
		case GABEDIT_TYPEGRID_MEP_MULTIPOL :
			grid = compute_mep_grid_using_multipol_from_orbitals(N, limits, 2);
			break;
		case GABEDIT_TYPEGRID_MEP_CG :
			grid = solve_poisson_equation_from_orbitals(N,limits, GABEDIT_CG);
			break;
		case GABEDIT_TYPEGRID_MEP_MG :
			grid = solve_poisson_equation_from_orbitals(N,limits, GABEDIT_MG);
			break;

	}
	if(grid)
		set_status_label_info("Grid","Ok");
	else
		set_status_label_info("Grid","Nothing");
	return grid;
}
/*********************************************************************************/
static void getCoefsLaplacian(gint nBoundary, gdouble xh, gdouble yh, gdouble zh,
		gdouble* fcx, gdouble* fcy, gdouble* fcz, gdouble* cc)
{
	gdouble* coefs =  g_malloc((nBoundary+1)*sizeof(gdouble));
	gdouble x2h = 1.0 / (xh * xh);
	gdouble y2h = 1.0 / (yh * yh);
	gdouble z2h = 1.0 / (zh * zh);
	gint i;
	
	switch(nBoundary)
	{
		case 1:{
				gdouble c[] = {-2.0, 1.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i];
				break;
			}
		case 2:{
				gdouble denom = 12.0;
				gdouble c[] = {-30.0, 16.0, -1.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 3:{
				gdouble denom = 180.0;
				gdouble c[] = {-490.0, 270.0,-27.0, 2.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 4:{
				gdouble denom = 5040.0;
				gdouble c[] = {-14350.0, 8064.0, -1008.0, 128.0, -9.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 5:{
				gdouble denom = 25200.0;
				gdouble c[] = {-73766.0, 42000.0, -6000.0, 1000.0, -125.0, 8.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 6:{
				gdouble denom = 831600.0;
			 	gdouble c[] = {-2480478.0,1425600.0,-222750.0,44000.0,-7425.0,864.0,-50.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 7:{
				gdouble denom = 75675600.0;
				gdouble c[] = {-228812298.0,132432300.0,-22072050.0,4904900.0,-1003275.0, 160524.0,-17150.0,900.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 8:{
				gdouble denom = 302702400.0;
				gdouble c[] = {-924708642.0,538137600.0,-94174080.0,22830080.0,-5350800.0,1053696.0,-156800.0,15360.0,-735.0};
				for(i=0;i<=nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
	}

	*cc = x2h + y2h + z2h;
	*cc *= coefs[0];

	for(i=1;i<=nBoundary;i++)
	{
		fcx[i] =  x2h * coefs[i];
		fcy[i] =  y2h * coefs[i];
		fcz[i] =  z2h * coefs[i];
	}

	g_free(coefs);
}
/*******************************************************************************************/
static void reset_boundary(Grid* grid, gint nBoundary)
{
	gint i;
	gint j;
	gint k;

	/* left */
	for(i=0;i<nBoundary;i++)
	for(j=0;j<grid->N[1];j++)
		for(k=0;k<grid->N[2];k++)
			grid->point[i][j][k].C[3] = grid->point[nBoundary][j][k].C[3];
	/* right */
	for(i=grid->N[0]-nBoundary;i<grid->N[0];i++)
	for(j=0;j<grid->N[1];j++)
		for(k=0;k<grid->N[2];k++)
			grid->point[i][j][k].C[3] = grid->point[grid->N[0]-nBoundary-1][j][k].C[3];

	/* front */
	for(j=0;j<nBoundary;j++)
	for(i=0;i<grid->N[0];i++)
		for(k=0;k<grid->N[2];k++)
			grid->point[i][j][k].C[3] = grid->point[i][nBoundary][k].C[3];
	/* back */
	for(j=grid->N[1]-nBoundary;j<grid->N[1];j++)
	for(i=0;i<grid->N[0];i++)
		for(k=0;k<grid->N[2];k++)
			grid->point[i][j][k].C[3] = grid->point[i][grid->N[1]-nBoundary-1][k].C[3];

	/* top */
	for(k=0;k<nBoundary;k++)
	for(j=0;j<grid->N[1];j++)
		for(i=0;i<grid->N[0];i++)
			grid->point[i][j][k].C[3] = grid->point[i][j][nBoundary].C[3];
	/* bottom */
	for(k=grid->N[2]-nBoundary;k<grid->N[2];k++)
	for(j=0;j<grid->N[1];j++)
		for(i=0;i<grid->N[0];i++)
			grid->point[i][j][k].C[3] = grid->point[i][j][grid->N[2]-nBoundary-1].C[3];

}
/*******************************************************************************************/
Grid* get_grid_laplacian(Grid* grid, gint nBoundary)
{
	gint i;
	gint j;
	gint k;
	gdouble v;
	Grid* lapGrid =  NULL;
	gdouble xh, yh, zh;
	gdouble a, b, c;
	gint N[3] = {0,0,0};
	gdouble* fcx =  NULL;
	gdouble* fcy =  NULL;
	gdouble* fcz =  NULL;
	gdouble cc = 0;
	GridLimits limits;
	gdouble scale = 0;
	gint n;
	gboolean beg = TRUE;

	if(grid==NULL) return NULL;
	if(nBoundary<1) return NULL;
	if(grid->N[0]<=2*nBoundary) return NULL;
	if(grid->N[1]<=2*nBoundary) return NULL;
	if(grid->N[2]<=2*nBoundary) return NULL;

	for(n=0;n<3;n++) N[n] = grid->N[n];


	i = 1; j = 0; k = 0;
	a = grid->point[i][j][k].C[0]-grid->point[0][0][0].C[0];
	b = grid->point[i][j][k].C[1]-grid->point[0][0][0].C[1];
	c = grid->point[i][j][k].C[2]-grid->point[0][0][0].C[2];
	xh = sqrt(a*a+b*b+c*c);

	i = 0; j = 1; k = 0;
	a = grid->point[i][j][k].C[0]-grid->point[0][0][0].C[0];
	b = grid->point[i][j][k].C[1]-grid->point[0][0][0].C[1];
	c = grid->point[i][j][k].C[2]-grid->point[0][0][0].C[2];
	yh = sqrt(a*a+b*b+c*c);

	i = 0; j = 0; k = 1;
	a = grid->point[i][j][k].C[0]-grid->point[0][0][0].C[0];
	b = grid->point[i][j][k].C[1]-grid->point[0][0][0].C[1];
	c = grid->point[i][j][k].C[2]-grid->point[0][0][0].C[2];
	zh = sqrt(a*a+b*b+c*c);

	fcx =  g_malloc((nBoundary+1)*sizeof(gdouble));
	fcy =  g_malloc((nBoundary+1)*sizeof(gdouble));
	fcz =  g_malloc((nBoundary+1)*sizeof(gdouble));
	getCoefsLaplacian(nBoundary, xh, yh, zh,  fcx,  fcy, fcz, &cc);

	limits.MinMax[0][0] = grid->limits.MinMax[0][0];
	limits.MinMax[1][0] = grid->limits.MinMax[1][0];

	limits.MinMax[0][1] = grid->limits.MinMax[0][1];
	limits.MinMax[1][1] = grid->limits.MinMax[1][1];

	limits.MinMax[0][2] = grid->limits.MinMax[0][2];
	limits.MinMax[1][2] = grid->limits.MinMax[1][2];


	lapGrid = grid_point_alloc(N,limits);
	
	progress_orb(0,GABEDIT_PROGORB_COMPLAPGRID,TRUE);
	scale = (gdouble)1.01/lapGrid->N[0];

	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				lapGrid->point[i][j][k].C[0] = grid->point[i][j][k].C[0];
				lapGrid->point[i][j][k].C[1] = grid->point[i][j][k].C[1];
				lapGrid->point[i][j][k].C[2] = grid->point[i][j][k].C[2];
				lapGrid->point[i][j][k].C[3] = 0;
			}
		}
	}
 
	for(i=nBoundary;i<grid->N[0]-nBoundary;i++)
	{
		for(j=nBoundary;j<grid->N[1]-nBoundary;j++)
		{
			for(k=nBoundary;k<grid->N[2]-nBoundary;k++)
			{
				v = cc*grid->point[i][j][k].C[3];
				for(n=1;n<=nBoundary;n++)
				{
					v += fcx[n] *(grid->point[i-n][j][k].C[3]+grid->point[i+n][j][k].C[3]);
					v += fcy[n] *(grid->point[i][j-n][k].C[3]+grid->point[i][j+n][k].C[3]);
					v += fcz[n] *(grid->point[i][j][k-n].C[3]+grid->point[i][j][k+n].C[3]);
				}
				lapGrid->point[i][j][k].C[3] = v;
				if(beg)
				{
					beg = FALSE;
        				lapGrid->limits.MinMax[0][3] =  v;
        				lapGrid->limits.MinMax[1][3] =  v;
				}
                		else
				{
        				if(lapGrid->limits.MinMax[0][3]>v)
        					lapGrid->limits.MinMax[0][3] =  v;
        				if(lapGrid->limits.MinMax[1][3]<v)
        					lapGrid->limits.MinMax[1][3] =  v;
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPLAPGRID,TRUE);
			break;
		}
		progress_orb(scale,GABEDIT_PROGORB_COMPLAPGRID,FALSE);
	}

	if(CancelCalcul)
	{
		lapGrid = free_grid(lapGrid);
	}
	else
	{
		reset_boundary(lapGrid, nBoundary);
	}
	g_free(fcx);
	g_free(fcy);
	g_free(fcz);
	return lapGrid;
}
/*************************************************************************************/
static void getCoefsGradient(gint nBoundary, gdouble xh, gdouble yh, gdouble zh,
		gdouble* fcx, gdouble* fcy, gdouble* fcz, gdouble* cc)
{
	gdouble* coefs =  g_malloc((nBoundary+1)*sizeof(gdouble));
	gdouble xxh = 1.0;
	gdouble yyh = 1.0;
	gdouble zzh = 1.0;
	gint i;
	
	switch(nBoundary)
	{
		case 1:{
				gdouble denom = 2.0;
				gdouble c[] = {-1.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 2:{
				gdouble denom =12.0;
				gdouble c[] = { 1.0, -8.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 3:{
				gdouble denom =60.0;
				gdouble c[] = { -1.0, +9.0, -45.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 4:{
				gdouble denom =840.0;
				gdouble c[] = { 3.0, -32.0, +168.0, -672.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 5:{
				gdouble denom =2520.0 ;
				gdouble c[] = { -2.0, +25.0, -150.0,+600.0, -2100.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 6:{
				gdouble denom =27720.0 ;
				gdouble c[] = { 5.0, -72.0, +495.0, -2200.0, +7425.0, -23760.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 7:{
				gdouble denom =360360.0;
				gdouble c[] = { -15.0, +245.0, -1911.0, +9555.0, -35035.0, +105105.0, -315315.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
		case 8:{
				gdouble denom =720720.0;
				gdouble c[] = { 7.0, -128.0, +1120.0, -6272.0, +25480.0, -81536.0, +224224.0, -640640.0};
				for(i=0;i<nBoundary;i++)
					coefs[i] = c[i]/denom;
				break;
			}
	}

	xxh = 1.0 / (xh);
	yyh = 1.0 / (yh);
	zzh = 1.0 / (zh);

	for(i=0;i<nBoundary;i++)
	{
		fcx[i] =  xxh * coefs[i];
		fcy[i] =  yyh * coefs[i];
		fcz[i] =  zzh * coefs[i];
	}

	g_free(coefs);
}
/*************************************************************************************/
Grid* get_grid_norm_gradient(Grid* grid, gint nBoundary)
{
	gint i;
	gint j;
	gint k;
	gint kn;
	Grid* gardGrid =  NULL;
	gdouble xh, yh, zh;
	gdouble a, b, c;
	gint N[3] = {0,0,0};
	gdouble* fcx =  NULL;
	gdouble* fcy =  NULL;
	gdouble* fcz =  NULL;
	gdouble cc = 0;
	GridLimits limits;
	gdouble scale = 0;
	gint n;
	gboolean beg = TRUE;
	gdouble gx, gy, gz;

	if(grid==NULL) return NULL;
	if(nBoundary<1) return NULL;
	if(grid->N[0]<=2*nBoundary) return NULL;
	if(grid->N[1]<=2*nBoundary) return NULL;
	if(grid->N[2]<=2*nBoundary) return NULL;

	for(n=0;n<3;n++) N[n] = grid->N[n];


	i = 1; j = 0; k = 0;
	a = grid->point[i][j][k].C[0]-grid->point[0][0][0].C[0];
	b = grid->point[i][j][k].C[1]-grid->point[0][0][0].C[1];
	c = grid->point[i][j][k].C[2]-grid->point[0][0][0].C[2];
	xh = sqrt(a*a+b*b+c*c);

	i = 0; j = 1; k = 0;
	a = grid->point[i][j][k].C[0]-grid->point[0][0][0].C[0];
	b = grid->point[i][j][k].C[1]-grid->point[0][0][0].C[1];
	c = grid->point[i][j][k].C[2]-grid->point[0][0][0].C[2];
	yh = sqrt(a*a+b*b+c*c);

	i = 0; j = 0; k = 1;
	a = grid->point[i][j][k].C[0]-grid->point[0][0][0].C[0];
	b = grid->point[i][j][k].C[1]-grid->point[0][0][0].C[1];
	c = grid->point[i][j][k].C[2]-grid->point[0][0][0].C[2];
	zh = sqrt(a*a+b*b+c*c);

	fcx =  g_malloc((nBoundary)*sizeof(gdouble));
	fcy =  g_malloc((nBoundary)*sizeof(gdouble));
	fcz =  g_malloc((nBoundary)*sizeof(gdouble));
	getCoefsGradient(nBoundary, xh, yh, zh,  fcx,  fcy, fcz, &cc);

	limits.MinMax[0][0] = grid->limits.MinMax[0][0];
	limits.MinMax[1][0] = grid->limits.MinMax[1][0];

	limits.MinMax[0][1] = grid->limits.MinMax[0][1];
	limits.MinMax[1][1] = grid->limits.MinMax[1][1];

	limits.MinMax[0][2] = grid->limits.MinMax[0][2];
	limits.MinMax[1][2] = grid->limits.MinMax[1][2];


	gardGrid = grid_point_alloc(N,limits);
	
	progress_orb(0,GABEDIT_PROGORB_COMPGRADGRID,TRUE);
	scale = (gdouble)1.01/gardGrid->N[0];

	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				gardGrid->point[i][j][k].C[0] = grid->point[i][j][k].C[0];
				gardGrid->point[i][j][k].C[1] = grid->point[i][j][k].C[1];
				gardGrid->point[i][j][k].C[2] = grid->point[i][j][k].C[2];
				gardGrid->point[i][j][k].C[3] = 0;
			}
		}
	}
 
	for(i=nBoundary;i<grid->N[0]-nBoundary;i++)
	{
		for(j=nBoundary;j<grid->N[1]-nBoundary;j++)
		{
			for(k=nBoundary;k<grid->N[2]-nBoundary;k++)
			{
				gx = gy = gz = 0.0;
				for(n=-nBoundary, kn=0 ; kn<nBoundary ; n++, kn++)
				{
					gx += fcx[kn] * (grid->point[i+n][j][k].C[3]-grid->point[i-n][j][k].C[3]);
					gy += fcy[kn] * (grid->point[i][j+n][k].C[3]-grid->point[i][j-n][k].C[3]);
					gz += fcz[kn] * (grid->point[i][j][k+n].C[3]-grid->point[i][j][k-n].C[3]) ;
				}
				gardGrid->point[i][j][k].C[3] = sqrt(gx*gx+gy*gy+gz*gz);
				if(beg)
				{
					beg = FALSE;
        				gardGrid->limits.MinMax[0][3] =  gardGrid->point[i][j][k].C[3];
        				gardGrid->limits.MinMax[1][3] =  gardGrid->point[i][j][k].C[3];
				}
                		else
				{
        				if(gardGrid->limits.MinMax[0][3]>gardGrid->point[i][j][k].C[3])
        					gardGrid->limits.MinMax[0][3] =  gardGrid->point[i][j][k].C[3];
        				if(gardGrid->limits.MinMax[1][3]<gardGrid->point[i][j][k].C[3])
        					gardGrid->limits.MinMax[1][3] =  gardGrid->point[i][j][k].C[3];
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPGRADGRID,TRUE);
			break;
		}
		progress_orb(scale,GABEDIT_PROGORB_COMPGRADGRID,FALSE);
	}

	if(CancelCalcul)
	{
		gardGrid = free_grid(gardGrid);
	}
	else
	{
		reset_boundary(gardGrid, nBoundary);
	}
	g_free(fcx);
	g_free(fcy);
	g_free(fcz);
	return gardGrid;
}
/*********************************************************************************/
static gdouble get_grad_value_STF(gfloat x,gfloat y,gfloat z,gint i,gint n,gint id)
{
	/*
	gdouble v = 0.0;
	gdouble d = 0;
	gdouble xi = x-SAOrb[i].Stf[n].C[0];
	gdouble yi = y-SAOrb[i].Stf[n].C[1];
	gdouble zi = z-SAOrb[i].Stf[n].C[2];
	gint l[3] = {SAOrb[i].Stf[n].l[0],SAOrb[i].Stf[n].l[1],SAOrb[i].Stf[n].l[2]};

	d = (xi*xi)+(yi*yi)+(zi*zi);
	d *=SAOrb[i].Stf[n].Ex;
        if(d>40) return 1e-14;
	d = exp(-d);

	l[id]++;

	v = -2*SAOrb[i].Stf[n].Ex*SAOrb[i].Stf[n].Coef*
	    pow(xi,l[0])* pow(yi,l[1])* pow(zi,l[2])*d;

	l[id]-=2;
	if(l[id]>=0)
		v+= (l[id]+1)*SAOrb[i].Stf[n].Coef*
	    	pow(xi,l[0])* pow(yi,l[1])* pow(zi,l[2])*d;

	return v;
	*/
	return 0;
}
/*********************************************************************************/
static gdouble get_grad_value_CSTF(gfloat x,gfloat y,gfloat z,gint i, gint id)
{
	gdouble v = 0.0;
	gint n;

        for(n=0;n<SAOrb[i].N;n++)
	   v+= get_grad_value_STF(x,y,z,i,n,id);

	return v;
}
/*********************************************************************************/
static gdouble get_grad_value_GTF(gfloat x,gfloat y,gfloat z,gint i,gint n,gint id)
{
	gdouble v = 0.0;
	gdouble d = 0;
	gdouble xi = x-AOrb[i].Gtf[n].C[0];
	gdouble yi = y-AOrb[i].Gtf[n].C[1];
	gdouble zi = z-AOrb[i].Gtf[n].C[2];
	gint l[3] = {AOrb[i].Gtf[n].l[0],AOrb[i].Gtf[n].l[1],AOrb[i].Gtf[n].l[2]};

	d = (xi*xi)+(yi*yi)+(zi*zi);
	d *=AOrb[i].Gtf[n].Ex;
        if(d>40) return 1e-14;
	d = exp(-d);

	l[id]++;

	v = -2*AOrb[i].Gtf[n].Ex*AOrb[i].Gtf[n].Coef*
	    pow(xi,l[0])* pow(yi,l[1])* pow(zi,l[2])*d;

	l[id]-=2;
	if(l[id]>=0)
		v+= (l[id]+1)*AOrb[i].Gtf[n].Coef*
	    	pow(xi,l[0])* pow(yi,l[1])* pow(zi,l[2])*d;

	return v;
}
/*********************************************************************************/
static gdouble get_grad_value_CGTF(gfloat x,gfloat y,gfloat z,gint i, gint id)
{
	gdouble v = 0.0;
	gint n;

        for(n=0;n<AOrb[i].N;n++)
	   v+= get_grad_value_GTF(x,y,z,i,n,id);

	return v;
}
/*********************************************************************************/
static gdouble get_grad_value_CBTF(gfloat x,gfloat y,gfloat z,gint i, gint id)
{
	if(AOrb) return get_grad_value_CGTF(x, y, z, i, id);
	else if(SAOrb) return get_grad_value_CSTF(x, y, z, i,id);
	else return 0;
}
/*********************************************************************************/
static gdouble get_grad_value_orbital(gfloat x,gfloat y,gfloat z,gint k, gint id)
{
	
	gdouble v=0.0;
	gint i;

	if(TypeSelOrb == 1)
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefAlphaOrbitals[k][i])>1e-10)
			v+=CoefAlphaOrbitals[k][i]*get_grad_value_CBTF(x,y,z,i,id);
	}
	else
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefBetaOrbitals[k][i])>1e-10)
			v+=CoefBetaOrbitals[k][i]*get_grad_value_CBTF(x,y,z,i,id);
	}
	return v;
}
/*********************************************************************************/
static gdouble get_norm2_grad_value_orbital(gfloat x,gfloat y,gfloat z,gint k)
{
	gdouble vx = get_grad_value_orbital( x, y, z, k, 0);
	gdouble vy = get_grad_value_orbital( x, y, z, k, 1);
	gdouble vz = get_grad_value_orbital( x, y, z, k, 2);

	return vx*vx+vy*vy+vz*vz; 
}
/*********************************************************************************/
/*
static gfloat get_norm_grad_value_orbital(gfloat x,gfloat y,gfloat z,gint k)
{
	return sqrt(get_norm2_grad_value_orbital(x,y,z,k));
}
*/
/*********************************************************************************/
static gdouble get_grad_value_electronic_density(gfloat x,gfloat y,gfloat z,gint id)
{
	
	gdouble v1 = 0.0;
	gdouble v2 = 0.0;
	gdouble cgv = 0.0;
	gdouble dcgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gdouble *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlpha = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *PhiBeta  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBeta  = g_malloc(NBetaOrb*sizeof(gdouble));

	for(k1=0;k1<NAlphaOrb;k1++)
	{
			PhiAlpha[k1] = 0.0;
			dPhiAlpha[k1] = 0.0;
	}
	for(k2=0;k2<NBetaOrb;k2++)
	{
			PhiBeta[k2] = 0.0;
			dPhiBeta[k2] = 0.0;
	}

	for(i=0;i<NAOrb;i++)
	{
		
		cgv = get_value_CBTF(x,y,z,i);
		dcgv = get_grad_value_CBTF(x,y,z,i,id);
		for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
		{
				PhiAlpha[k1] += CoefAlphaOrbitals[k1][i]*cgv;
				dPhiAlpha[k1] += CoefAlphaOrbitals[k1][i]*dcgv;
		}
		
		for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
		{
				PhiBeta[k2]  += CoefBetaOrbitals[k2][i]*cgv;
				dPhiBeta[k2]  += CoefBetaOrbitals[k2][i]*dcgv;
		}
 	}
	v1 = 0.0;
	for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
			v1 += OccAlphaOrbitals[k1]*PhiAlpha[k1]*dPhiAlpha[k1];
	v2 = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
			v2 += OccBetaOrbitals[k2]*PhiBeta[k2]*dPhiBeta[k2];

	g_free(PhiAlpha);
	g_free(dPhiAlpha);
	g_free(PhiBeta);
	g_free(dPhiBeta);
	return 2*(v1+v2);
}
/*********************************************************************************/
static gdouble get_norm2_grad_value_electronic_density(gfloat x,gfloat y,gfloat z)
{
	gdouble vx = get_grad_value_electronic_density( x, y, z, 0);
	gdouble vy = get_grad_value_electronic_density( x, y, z, 1);
	gdouble vz = get_grad_value_electronic_density( x, y, z, 2);

	return vx*vx+vy*vy+vz*vz; 
}
/*********************************************************************************/
static gdouble get_value_elf_becke(gfloat x,gfloat y,gfloat z,gint dump)
{
	gdouble grho2 = 0;
	gdouble rho = 0;
	gdouble sphi = 0;
	gdouble D = 0;
	gdouble Dh = 0;
	gdouble co = 3.0/5.0*pow(6*PI*PI,2.0/3);
	gdouble XBE2 = 0;

	gdouble v1X = 0.0;
	gdouble v1Y = 0.0;
	gdouble v1Z = 0.0;
	gdouble v2X = 0.0;
	gdouble v2Y = 0.0;
	gdouble v2Z = 0.0;
	gdouble vX = 0.0;
	gdouble vY = 0.0;
	gdouble vZ = 0.0;
	gdouble cgv = 0.0;
	gdouble dcgvX = 0.0;
	gdouble dcgvY = 0.0;
	gdouble dcgvZ = 0.0;
	gint i;
	gint k1;
	gint k2;
	gdouble *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlphaX = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlphaY = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlphaZ = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *PhiBeta  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBetaX  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBetaY  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBetaZ  = g_malloc(NBetaOrb*sizeof(gdouble));

	for(k1=0;k1<NAlphaOrb;k1++)
	{
			PhiAlpha[k1] = 0.0;
			dPhiAlphaX[k1] = 0.0;
			dPhiAlphaY[k1] = 0.0;
			dPhiAlphaZ[k1] = 0.0;
	}
	for(k2=0;k2<NBetaOrb;k2++)
	{
			PhiBeta[k2] = 0.0;
			dPhiBetaX[k2] = 0.0;
			dPhiBetaY[k2] = 0.0;
			dPhiBetaZ[k2] = 0.0;
	}

	for(i=0;i<NAOrb;i++)
	{
		
		cgv = get_value_CBTF(x,y,z,i);
		dcgvX = get_grad_value_CBTF(x,y,z,i,0);
		dcgvY = get_grad_value_CBTF(x,y,z,i,1);
		dcgvZ = get_grad_value_CBTF(x,y,z,i,2);
		for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
		{
				PhiAlpha[k1] += CoefAlphaOrbitals[k1][i]*cgv;
				dPhiAlphaX[k1] += CoefAlphaOrbitals[k1][i]*dcgvX;
				dPhiAlphaY[k1] += CoefAlphaOrbitals[k1][i]*dcgvY;
				dPhiAlphaZ[k1] += CoefAlphaOrbitals[k1][i]*dcgvZ;
		}
		
		for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
		{
				PhiBeta[k2]  += CoefBetaOrbitals[k2][i]*cgv;
				dPhiBetaX[k2]  += CoefBetaOrbitals[k2][i]*dcgvX;
				dPhiBetaY[k2]  += CoefBetaOrbitals[k2][i]*dcgvY;
				dPhiBetaZ[k2]  += CoefBetaOrbitals[k2][i]*dcgvZ;
		}
 	}
	v1X = 0.0;
	v1Y = 0.0;
	v1Z = 0.0;
	rho = 0;
	for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
		{
			v1X += OccAlphaOrbitals[k1]*PhiAlpha[k1]*dPhiAlphaX[k1];
			v1Y += OccAlphaOrbitals[k1]*PhiAlpha[k1]*dPhiAlphaY[k1];
			v1Z += OccAlphaOrbitals[k1]*PhiAlpha[k1]*dPhiAlphaZ[k1];
			rho += OccAlphaOrbitals[k1]*PhiAlpha[k1]*PhiAlpha[k1];
			sphi += OccAlphaOrbitals[k1]*(
					  dPhiAlphaX[k1]*dPhiAlphaX[k1]
					+ dPhiAlphaY[k1]*dPhiAlphaY[k1]
					+ dPhiAlphaZ[k1]*dPhiAlphaZ[k1]
					);
		}
	v2X = 0.0;
	v2Y = 0.0;
	v2Z = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
		{
			v2X += OccBetaOrbitals[k2]*PhiBeta[k2]*dPhiBetaX[k2];
			v2Y += OccBetaOrbitals[k2]*PhiBeta[k2]*dPhiBetaY[k2];
			v2Z += OccBetaOrbitals[k2]*PhiBeta[k2]*dPhiBetaZ[k2];
			rho += OccBetaOrbitals[k2]*PhiBeta[k2]*PhiBeta[k2];
			sphi +=OccBetaOrbitals[k2]*(
					  dPhiBetaX[k2]*dPhiBetaX[k2]
					+ dPhiBetaY[k2]*dPhiBetaY[k2]
					+ dPhiBetaZ[k2]*dPhiBetaZ[k2]
					);
		}
	vX = (v1X+v2X)*2;
	vY = (v1Y+v2Y)*2;
	vZ = (v1Z+v2Z)*2;
	grho2 = vX*vX + vY*vY +vZ*vZ ;

	g_free(PhiAlpha);
	g_free(dPhiAlphaX);
	g_free(dPhiAlphaY);
	g_free(dPhiAlphaZ);
	g_free(PhiBeta);
	g_free(dPhiBetaX);
	g_free(dPhiBetaY);
	g_free(dPhiBetaZ);
	
	D = sphi - grho2/4.0/rho;
	Dh = co*pow(rho,5.0/3.0);
	XBE2 = D/Dh;
	XBE2 = XBE2*XBE2;

	return 1.0/(1.0+XBE2);
}
/*********************************************************************************/
static gdouble get_value_elf_savin(gfloat x,gfloat y,gfloat z,gint dump)
{
	gdouble grho2 = 0;
	gdouble rho = 0;
	gdouble sphi = 0;
	gdouble t = 0;
	gdouble th = 0;
	gdouble cf = 3.0/10.0*pow(3*PI*PI,2.0/3);
	gdouble XS2 = 0;
	gdouble epsilon = 2.87e-5; /* This value constrains ELF to be less than 0.5 for rho<1e-3*/
	                           /* see Can. J. Chem. Vol. 74,1996 page 1088 */

	gdouble v1X = 0.0;
	gdouble v1Y = 0.0;
	gdouble v1Z = 0.0;
	gdouble v2X = 0.0;
	gdouble v2Y = 0.0;
	gdouble v2Z = 0.0;
	gdouble vX = 0.0;
	gdouble vY = 0.0;
	gdouble vZ = 0.0;
	gdouble cgv = 0.0;
	gdouble dcgvX = 0.0;
	gdouble dcgvY = 0.0;
	gdouble dcgvZ = 0.0;
	gint i;
	gint k1;
	gint k2;
	gdouble *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlphaX = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlphaY = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *dPhiAlphaZ = g_malloc(NAlphaOrb*sizeof(gdouble));
	gdouble *PhiBeta  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBetaX  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBetaY  = g_malloc(NBetaOrb*sizeof(gdouble));
	gdouble *dPhiBetaZ  = g_malloc(NBetaOrb*sizeof(gdouble));

	for(k1=0;k1<NAlphaOrb;k1++)
	{
			PhiAlpha[k1] = 0.0;
			dPhiAlphaX[k1] = 0.0;
			dPhiAlphaY[k1] = 0.0;
			dPhiAlphaZ[k1] = 0.0;
	}
	for(k2=0;k2<NBetaOrb;k2++)
	{
			PhiBeta[k2] = 0.0;
			dPhiBetaX[k2] = 0.0;
			dPhiBetaY[k2] = 0.0;
			dPhiBetaZ[k2] = 0.0;
	}

	for(i=0;i<NAOrb;i++)
	{
		
		cgv = get_value_CBTF(x,y,z,i);
		dcgvX = get_grad_value_CBTF(x,y,z,i,0);
		dcgvY = get_grad_value_CBTF(x,y,z,i,1);
		dcgvZ = get_grad_value_CBTF(x,y,z,i,2);
		for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
		{
				PhiAlpha[k1] += CoefAlphaOrbitals[k1][i]*cgv;
				dPhiAlphaX[k1] += CoefAlphaOrbitals[k1][i]*dcgvX;
				dPhiAlphaY[k1] += CoefAlphaOrbitals[k1][i]*dcgvY;
				dPhiAlphaZ[k1] += CoefAlphaOrbitals[k1][i]*dcgvZ;
		}
		
		for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
		{
				PhiBeta[k2]  += CoefBetaOrbitals[k2][i]*cgv;
				dPhiBetaX[k2]  += CoefBetaOrbitals[k2][i]*dcgvX;
				dPhiBetaY[k2]  += CoefBetaOrbitals[k2][i]*dcgvY;
				dPhiBetaZ[k2]  += CoefBetaOrbitals[k2][i]*dcgvZ;
		}
 	}
	v1X = 0.0;
	v1Y = 0.0;
	v1Z = 0.0;
	rho = 0;
	for(k1=0;k1<NAlphaOrb;k1++)
		if(OccAlphaOrbitals[k1]>1e-8)
		{
			v1X += OccAlphaOrbitals[k1]*(PhiAlpha[k1]*dPhiAlphaX[k1]);
			v1Y += OccAlphaOrbitals[k1]*(PhiAlpha[k1]*dPhiAlphaY[k1]);
			v1Z += OccAlphaOrbitals[k1]*(PhiAlpha[k1]*dPhiAlphaZ[k1]);
			rho += OccAlphaOrbitals[k1]*PhiAlpha[k1]*PhiAlpha[k1];
			sphi += OccAlphaOrbitals[k1]*(
					  dPhiAlphaX[k1]*dPhiAlphaX[k1]
					+ dPhiAlphaY[k1]*dPhiAlphaY[k1]
					+ dPhiAlphaZ[k1]*dPhiAlphaZ[k1]
					);
		}
	v2X = 0.0;
	v2Y = 0.0;
	v2Z = 0.0;
	for(k2=0;k2<NBetaOrb;k2++)
		if(OccBetaOrbitals[k2]>1e-8)
		{
			v2X += OccBetaOrbitals[k2]*(PhiBeta[k2]*dPhiBetaX[k2]);
			v2Y += OccBetaOrbitals[k2]*(PhiBeta[k2]*dPhiBetaY[k2]);
			v2Z += OccBetaOrbitals[k2]*(PhiBeta[k2]*dPhiBetaZ[k2]);
			rho += OccBetaOrbitals[k2]*PhiBeta[k2]*PhiBeta[k2];
			sphi +=OccBetaOrbitals[k2]*(
					  dPhiBetaX[k2]*dPhiBetaX[k2]
					+ dPhiBetaY[k2]*dPhiBetaY[k2]
					+ dPhiBetaZ[k2]*dPhiBetaZ[k2]
					);
		}
	vX = (v1X+v2X)*2;
	vY = (v1Y+v2Y)*2;
	vZ = (v1Z+v2Z)*2;
	grho2 = vX*vX + vY*vY +vZ*vZ ;

	g_free(PhiAlpha);
	g_free(dPhiAlphaX);
	g_free(dPhiAlphaY);
	g_free(dPhiAlphaZ);
	g_free(PhiBeta);
	g_free(dPhiBetaX);
	g_free(dPhiBetaY);
	g_free(dPhiBetaZ);
	
	t = sphi/2 - grho2/8.0/rho;
	th = cf*pow(rho,5.0/3.0);
	XS2 = (t+epsilon)/th;
	XS2 = XS2*XS2;
	return 1.0/(1.0+XS2);
}
/*********************************************************************************/
static gdouble get_value_sas(gfloat x,gfloat y,gfloat z,gint dump)
{
	gdouble RProb = solventRadius*ANG_TO_BOHR;
	gdouble ri2 = 0;
	gdouble ri6 = 0;
	gdouble xi = 0;
	gdouble yi = 0;
	gdouble zi = 0;
	gdouble sigmai = 0;
	gdouble sigmai2 = 0;
	gdouble sigmai6 = 0;
	gdouble v = 0;
	gdouble t = 0;
	gint i;
	gdouble PRECISION = 1e-10;
	for(i=0;i<Ncenters;i++)
	{
		xi = x-GeomOrb[i].C[0];
		yi = y-GeomOrb[i].C[1];
		zi = z-GeomOrb[i].C[2];
		ri2 = xi*xi+yi*yi+zi*zi;
		ri2 += PRECISION;
		ri6 = ri2*ri2*ri2;
		sigmai = GeomOrb[i].Prop.vanDerWaalsRadii + RProb;
		sigmai2 = sigmai*sigmai;
		sigmai6 = sigmai2*sigmai2*sigmai2;
		t = sigmai6/ri6;
		v += t*t - t;

 	}
	if(v>1e10) v = 1e10;
	return v;
}
/*********************************************************************************/
gdouble** compute_multipol_from_grid(Grid* grid, gint lmax)
{
	gint i;
	gint j;
	gint k;
	gint l;
	gint m;
	gfloat x;
	gfloat y;
	gfloat z;
	gfloat r;
	gfloat temp;
	gfloat p;
	gdouble** Q = g_malloc(lmax*sizeof(gdouble*));
	Slm** slm = g_malloc(lmax*sizeof(Slm*));
	gdouble PRECISION = 1e-13;
	gdouble dv = 0;
	gfloat scale;

	for(l=0;l<=lmax;l++)
	{
		Q[l] = g_malloc((2*l+1)*sizeof(gdouble));
		slm[l] = g_malloc((2*l+1)*sizeof(Slm));

		for(m=-l;m<=l;m++)
		{
			Q[l][l+m] = 0.0;
			slm[l][l+m]=GetCoefSlm(l,m);
		}
	}

	dv = (grid->point[1][0][0].C[0]-grid->point[0][0][0].C[0])*
	     (grid->point[0][1][0].C[1]-grid->point[0][0][0].C[1])*
	     (grid->point[0][0][1].C[2]-grid->point[0][0][0].C[2]);
	dv = -fabs(dv);

	progress_orb(0,GABEDIT_PROGORB_COMPMULTIPOL,TRUE);
	scale = (gfloat)1.01/grid->N[0];
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				x = grid->point[i][j][k].C[0];
				y = grid->point[i][j][k].C[1];
				z = grid->point[i][j][k].C[2];
				r = sqrt(x*x +  y*y + z*z+PRECISION);
				temp = grid->point[i][j][k].C[3]*dv;
				x /= r;
				y /= r;
				z /= r;
                                for(l=0; l<=lmax; l++)
				{
					p = temp*pow(r,l);
					for(m=-l; m<=l; m++)
					{
						Q[l][m+l] += p*slmGetValue(&slm[l][m+l],x,y,z);
					}
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPMULTIPOL,TRUE);
			break;
		}
		progress_orb(scale,GABEDIT_PROGORB_COMPMULTIPOL,FALSE);
	}
	for(l=0;l<=lmax;l++)
		if(slm[l])g_free(slm[l]);
	if(slm) g_free(slm);
	if(CancelCalcul) 
	{
		if(Q)
		{
			for(l=0;l<=lmax;l++)
				if(Q[l])g_free(Q[l]);
			g_free(Q);
		}
		Q = NULL;
	}
	return Q;

}
/**************************************************************/
static void define_xyz_grid(Grid*grid)
{
	gint i;
	gint j;
	gint k;
	gfloat x;
	gfloat y;
	gfloat z;
	gfloat V0[3];
	gfloat V1[3];
	gfloat V2[3];
	gfloat firstPoint[3];

	for(i=0;i<3;i++)
	{
	V0[i] = firstDirection[i] *(grid->limits.MinMax[1][0]-grid->limits.MinMax[0][0]);
	V1[i] = secondDirection[i]*(grid->limits.MinMax[1][1]-grid->limits.MinMax[0][1]);
	V2[i] = thirdDirection[i] *(grid->limits.MinMax[1][2]-grid->limits.MinMax[0][2]);
	}
	for(i=0;i<3;i++)
	{
		firstPoint[i] = V0[i] + V1[i] + V2[i];
		firstPoint[i] = originOfCube[i] - firstPoint[i]/2;
	}
	for(i=0;i<3;i++)
	{
		V0[i] /= grid->N[0]-1;
		V1[i] /= grid->N[1]-1;
		V2[i] /= grid->N[2]-1;
	}
	
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				x = firstPoint[0] + i*V0[0] + j*V1[0] +  k*V2[0]; 
				y = firstPoint[1] + i*V0[1] + j*V1[1] +  k*V2[1]; 
				z = firstPoint[2] + i*V0[2] + j*V1[2] +  k*V2[2]; 
				
				grid->point[i][j][k].C[0] = x;
				grid->point[i][j][k].C[1] = y;
				grid->point[i][j][k].C[2] = z;
			}
		}
	}
}
/*********************************************************************************/
Grid* compute_mep_grid_using_partial_charges_cube_grid(Grid* grid)
{
	gint i;
	gint j;
	gint k;
	gfloat x;
	gfloat y;
	gfloat z;
	gfloat r;
	gfloat temp;
	gdouble PRECISION = 1e-13;
	Grid* esp = NULL;
	gdouble invR = 1.0;
	gdouble v;
	gint n;
	gboolean beg = TRUE;
	gfloat scale;

	if(!grid) return NULL;
	esp = grid_point_alloc(grid->N,grid->limits);

	progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
	scale = (gfloat)1.01/grid->N[0];
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				x = grid->point[i][j][k].C[0];
				y = grid->point[i][j][k].C[1];
				z = grid->point[i][j][k].C[2];

				esp->point[i][j][k].C[0] = x;
				esp->point[i][j][k].C[1] = y;
				esp->point[i][j][k].C[2] = z;

				r = sqrt(x*x +  y*y + z*z+PRECISION);
				invR = 1.0 /r;
				temp = esp->point[i][j][k].C[3];
				x *= invR;
				y *= invR;
				z *= invR;
				v = 0;
				for(n=0;n<Ncenters;n++)
				{
					x = esp->point[i][j][k].C[0]-GeomOrb[n].C[0];
					y = esp->point[i][j][k].C[1]-GeomOrb[n].C[1];
					z = esp->point[i][j][k].C[2]-GeomOrb[n].C[2];
					r = sqrt(x*x +  y*y + z*z+PRECISION);
					invR = 1.0 /r;
					v+= invR*GeomOrb[n].partialCharge;
				}
				esp->point[i][j][k].C[3]=v;
				if(beg)
				{
					beg = FALSE;
        				esp->limits.MinMax[0][3] =  v;
        				esp->limits.MinMax[1][3] =  v;
				}
                		else
				{
        				if(esp->limits.MinMax[0][3]>v) esp->limits.MinMax[0][3] =  v;
        				if(esp->limits.MinMax[1][3]<v) esp->limits.MinMax[1][3] =  v;
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
			break;
		}
		progress_orb(scale,GABEDIT_PROGORB_COMPMEPGRID,FALSE);
	}
	if(CancelCalcul)
	{
		esp = free_grid(esp);
	}
	return esp;

}
/*********************************************************************************/
Grid* compute_mep_grid_using_partial_charges(gint N[], GridLimits limits)
{
	gint i;
	gint j;
	gint k;
	gfloat x;
	gfloat y;
	gfloat z;
	gfloat r;
	gfloat temp;
	gdouble PRECISION = 1e-13;
	Grid* esp = NULL;
	gdouble invR = 1.0;
	gdouble v;
	gint n;
	gboolean beg = TRUE;
	gfloat scale;

	esp = grid_point_alloc(N,limits);
	define_xyz_grid(esp);

	progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
	scale = (gfloat)1.01/N[0];
	for(i=0;i<N[0];i++)
	{
		for(j=0;j<N[1];j++)
		{
			for(k=0;k<N[2];k++)
			{
				x = esp->point[i][j][k].C[0];
				y = esp->point[i][j][k].C[1];
				z = esp->point[i][j][k].C[2];

				r = sqrt(x*x +  y*y + z*z+PRECISION);
				invR = 1.0 /r;
				temp = esp->point[i][j][k].C[3];
				x *= invR;
				y *= invR;
				z *= invR;
				v = 0;
				for(n=0;n<Ncenters;n++)
				{
					x = esp->point[i][j][k].C[0]-GeomOrb[n].C[0];
					y = esp->point[i][j][k].C[1]-GeomOrb[n].C[1];
					z = esp->point[i][j][k].C[2]-GeomOrb[n].C[2];
					r = sqrt(x*x +  y*y + z*z+PRECISION);
					invR = 1.0 /r;
					v+= invR*GeomOrb[n].partialCharge;
				}
				esp->point[i][j][k].C[3]=v;
				if(beg)
				{
					beg = FALSE;
        				esp->limits.MinMax[0][3] =  v;
        				esp->limits.MinMax[1][3] =  v;
				}
                		else
				{
        				if(esp->limits.MinMax[0][3]>v) esp->limits.MinMax[0][3] =  v;
        				if(esp->limits.MinMax[1][3]<v) esp->limits.MinMax[1][3] =  v;
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
			break;
		}
		progress_orb(scale,GABEDIT_PROGORB_COMPMEPGRID,FALSE);
	}
	if(CancelCalcul)
	{
		esp = free_grid(esp);
	}
	return esp;

}
/*********************************************************************************/
Grid* compute_mep_grid_using_multipol_from_density_grid(Grid* grid, gint lmax)
{
	gint i;
	gint j;
	gint k;
	gint l;
	gint m;
	gfloat x;
	gfloat y;
	gfloat z;
	gfloat r;
	gfloat temp;
	gdouble PRECISION = 1e-13;
	Grid* esp = NULL;
	gdouble** Q = NULL;
	gdouble invR = 1.0;
	gdouble v;
	Slm** slm = NULL;
	gint n;
	gboolean beg = TRUE;
	gfloat scale;

	if(!test_grid_all_positive(grid))
	{
		Message("Sorry\n The current grid is not a grid for electronic density","Error",TRUE);
		return NULL;
	}

	Q = compute_multipol_from_grid(grid,lmax);
	if(!Q) return NULL;

	esp = grid_point_alloc(grid->N,grid->limits);
	slm = g_malloc(lmax*sizeof(Slm*));

	for(l=0;l<=lmax;l++)
	{
		slm[l] = g_malloc((2*l+1)*sizeof(Slm));
		for(m=-l;m<=l;m++)
			slm[l][l+m]=GetCoefSlm(l,m);
	}

	printf("Electronic values. All values in AU\n");
	for(l=0; l<=lmax; l++)
		for(m=-l; m<=l; m++)
		{

			unsigned int absm = abs(m);
			gdouble Norm = sqrt((2*l+1)/(4*PI))*sqrt(fact[l+absm]/fact[l-absm]);
			if(m!=0) Norm *= sqrt(2.0);
			Norm = 1/Norm;
			Q[l][m+l] *= Norm;
			printf("Q[%d][%d] = %f\n",l,m,Q[l][m+l]);
			Q[l][m+l] *= Norm;
		}

	progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
	scale = (gfloat)1.01/grid->N[0];
	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				x = grid->point[i][j][k].C[0];
				y = grid->point[i][j][k].C[1];
				z = grid->point[i][j][k].C[2];

				esp->point[i][j][k].C[0] = x;
				esp->point[i][j][k].C[1] = y;
				esp->point[i][j][k].C[2] = z;

				r = sqrt(x*x +  y*y + z*z+PRECISION);
				invR = 1.0 /r;
				temp = grid->point[i][j][k].C[3];
				x *= invR;
				y *= invR;
				z *= invR;
				v = 0;
                                for(l=0; l<=lmax; l++)
				{
					temp = pow(invR,l+1);
					for(m=-l; m<=l; m++)
					{
						if(fabs(Q[l][m+l])<10*PRECISION) continue;
						v += temp*slmGetValue(&slm[l][m+l],x,y,z)*Q[l][m+l];
					}
				}
				for(n=0;n<Ncenters;n++)
				{
					x = grid->point[i][j][k].C[0]-GeomOrb[n].C[0];
					y = grid->point[i][j][k].C[1]-GeomOrb[n].C[1];
					z = grid->point[i][j][k].C[2]-GeomOrb[n].C[2];
					r = sqrt(x*x +  y*y + z*z+PRECISION);
					invR = 1.0 /r;
					v+= invR*GeomOrb[n].nuclearCharge;
				}
				esp->point[i][j][k].C[3]=v;
				if(beg)
				{
					beg = FALSE;
        				esp->limits.MinMax[0][3] =  v;
        				esp->limits.MinMax[1][3] =  v;
				}
                		else
				{
        				if(esp->limits.MinMax[0][3]>v) esp->limits.MinMax[0][3] =  v;
        				if(esp->limits.MinMax[1][3]<v) esp->limits.MinMax[1][3] =  v;
				}
			}
		}
		if(CancelCalcul) 
		{
			progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
			break;
		}
		progress_orb(scale,GABEDIT_PROGORB_COMPMEPGRID,FALSE);
	}
	if(Q)
	{
		for(l=0;l<=lmax;l++)
			if(Q[l])g_free(Q[l]);
		g_free(Q);
	}
	if(slm)
	{
		for(l=0;l<=lmax;l++)
			if(slm[l])g_free(slm[l]);
		g_free(slm);
	}
	if(CancelCalcul)
	{
		esp = free_grid(esp);
	}
	return esp;

}
/*********************************************************************************/
Grid* compute_mep_grid_using_multipol_from_orbitals(gint N[],GridLimits limits, gint lmax)
{
	Grid* eGrid = NULL;
	Grid* esp = NULL;

	TypeGrid = GABEDIT_TYPEGRID_EDENSITY;
	eGrid = define_grid_point(N,limits,get_value_electronic_density);
	esp = compute_mep_grid_using_multipol_from_density_grid(eGrid, lmax);
	eGrid=free_grid(eGrid);
	set_status_label_info("Grid"," ");
	return esp;
}
/*********************************************************************************/
Grid* solve_poisson_equation_from_density_grid(Grid* grid, PoissonSolverMethod psMethod)
{
	gint i;
	gint j;
	gint k;
	Grid* esp = NULL;
	DomainMG domain;
	gdouble xL;
	gdouble yL;
	gdouble zL;
	GridMG* source = NULL;
	GridMG* potential = NULL;
	gdouble fourPI = -4*PI;
	PoissonMG* ps= NULL;
	gint Nx, Ny, Nz;
	LaplacianOrderMG laplacianOrder= GABEDIT_LAPLACIAN_2;
	gdouble PRECISION = 1e-13;

	if(!test_grid_all_positive(grid))
	{
		Message("Sorry\n The current grid is not a grid for electronic density","Error",TRUE);
		return NULL;
	}

	if(!grid) return NULL;

	Nx = grid->N[0]-laplacianOrder;
	Ny = grid->N[1]-laplacianOrder;
	Nz = grid->N[2]-laplacianOrder;

	if(Nx%2==0 || Ny%2==0 || Nz%2==0)
	{
		printf("The number of step should be odd\n");
		return NULL;
	}
	xL = fabs(limits.MinMax[1][0]-limits.MinMax[0][0]);
	yL = fabs(limits.MinMax[1][1]-limits.MinMax[0][1]);
	zL = fabs(limits.MinMax[1][2]-limits.MinMax[0][2]);

	domain = getDomainMG(Nx,Ny,Nz, 
			limits.MinMax[0][0], limits.MinMax[0][1], limits.MinMax[0][2], 
			xL, yL, zL, laplacianOrder);
	/* printDomain(&domain);*/
	source = getNewGridMGUsingDomain(&domain);
	potential = getNewGridMGUsingDomain(&domain);

	progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
	setTextInProgress("Compute of the source grid for the Poisson equation");
	for(i=0;i<grid->N[0];i++)
		for(j=0;j<grid->N[1];j++)
			for(k=0;k<grid->N[2];k++)
			{
				setValGridMG(source,i,j,k,grid->point[i][j][k].C[3]*fourPI);
			}
	ps = getPoissonMG(potential, source);
	setTextInProgress("Set boundary values from multipole ");
	tradesBoundaryPoissonMG(ps);
	setTextInProgress("Solve the Poisson equation");
	/* solve poisson */
	/*solveMGPoissonMG(ps, domain.maxLevel);*/
	if(psMethod==GABEDIT_CG)
		solveCGPoissonMG(ps, 200, 1e-6);
	else
		solveMGPoissonMG3(ps, domain.maxLevel, 20, 1e-6, 0);
	if(CancelCalcul)
	{
		destroyPoissonMG(ps); /* destroy of source and potential Grid */
		esp = free_grid(esp);
		return NULL;
	}
	progress_orb(0,GABEDIT_PROGORB_COMPMEPGRID,TRUE);
	setTextInProgress("End the rsolution of the Poisson equation");
	/*smootherPoissonMG(ps,100);*/

	esp = copyGrid(grid);
	for(i=0;i<esp->N[0];i++)
		for(j=0;j<esp->N[1];j++)
			for(k=0;k<esp->N[2];k++)
			{
				gdouble v = 0;
				gint n;
				gdouble x,y,z,r,invR;
				for(n=0;n<Ncenters;n++)
				{
					x = esp->point[i][j][k].C[0]-GeomOrb[n].C[0];
					y = esp->point[i][j][k].C[1]-GeomOrb[n].C[1];
					z = esp->point[i][j][k].C[2]-GeomOrb[n].C[2];
					r = sqrt(x*x +  y*y + z*z+PRECISION);
					invR = 1.0 /r;
					v+= invR*GeomOrb[n].nuclearCharge;
				}
				esp->point[i][j][k].C[3] = v-getValGridMG(ps->potential, i, j, k);
			}
	destroyPoissonMG(ps); /* destroy of source and potential Grid */
	reset_limits_for_grid(esp);

	return esp;
}
/*********************************************************************************/
Grid* solve_poisson_equation_from_orbitals(gint N[],GridLimits limits, PoissonSolverMethod psMethod)
{
	Grid* eGrid = NULL;
	Grid* esp = NULL;

	TypeGrid = GABEDIT_TYPEGRID_EDENSITY;
	eGrid = define_grid_point(N,limits,get_value_electronic_density);
	if(psMethod == GABEDIT_CG) TypeGrid = GABEDIT_TYPEGRID_MEP_CG;
	else TypeGrid = GABEDIT_TYPEGRID_MEP_MG;
	if(!eGrid) return NULL;
	esp = solve_poisson_equation_from_density_grid(eGrid, psMethod);
	eGrid=free_grid(eGrid);
	set_status_label_info("Grid"," ");
	return esp;
}
