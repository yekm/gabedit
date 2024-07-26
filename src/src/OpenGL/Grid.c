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
#include "ColorMap.h"

/************************************************************************/
static gdouble get_value_elf_becke(gfloat x,gfloat y,gfloat z,gint dump);
static gdouble get_value_elf_savin(gfloat x,gfloat y,gfloat z,gint dump);
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
/*
        printf("C = %f %f %f\n",AOrb[i].Gtf[n].C[0],AOrb[i].Gtf[n].C[1],AOrb[i].Gtf[n].C[2]);
        printf("Ex Coef = %f %f \n",AOrb[i].Gtf[n].Ex,AOrb[i].Gtf[n].Coef);
        printf("c1 = %f  \n", pow(x-AOrb[i].Gtf[n].C[0],AOrb[i].Gtf[n].l[0]));
        printf("c2 = %f  \n", pow(y-AOrb[i].Gtf[n].C[1],AOrb[i].Gtf[n].l[1]));
        printf("c3 = %f  \n", pow(z-AOrb[i].Gtf[n].C[2],AOrb[i].Gtf[n].l[2]));
*/
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
gdouble get_value_orbital(gfloat x,gfloat y,gfloat z,gint k)
{
	
	gdouble v=0.0;
	gint i;

	if(TypeSelOrb == 1)
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefAlphaOrbitals[k][i])>1e-10)
			v+=CoefAlphaOrbitals[k][i]*get_value_CGTF(x,y,z,i);
	}
	else
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefBetaOrbitals[k][i])>1e-10)
			v+=CoefBetaOrbitals[k][i]*get_value_CGTF(x,y,z,i);
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
		
		cgv = get_value_CGTF(x,y,z,GeomOrb[n].NumOrb[i]);
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
		
		cgv = get_value_CGTF(x,y,z,i);
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
		
		cgv = get_value_CGTF(x,y,z,i);
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
Grid* free_grid(Grid* grid)
{
	gint i,j;
	if(!grid)
		return NULL;
	for(i=0;i< grid->N[0] ;i++)
	{
		for(j=0;j< grid->N[1] ;j++)
			g_free(grid->point[i][j]);
		g_free(grid->point[i]);
	}
	g_free(grid->point);
	g_free(grid);
	grid=NULL;
	{
		GtkWidget* handleBoxColorMapGrid = g_object_get_data(G_OBJECT(PrincipalWindow), "HandleboxColorMapGrid ");
		color_map_hide(handleBoxColorMapGrid);
	}
	return grid;
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
	
	progress_orb(0,1,TRUE);
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
			progress_orb(0,1,TRUE);
			break;
		}

		progress_orb(scale,1,FALSE);
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
	
	progress_orb(0,1,TRUE);
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
			progress_orb(0,1,TRUE);
			break;
		}
		progress_orb(scale,1,FALSE);
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
	
	progress_orb(0,1,TRUE);
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
			progress_orb(0,1,TRUE);
			break;
		}
		progress_orb(scale,1,FALSE);
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
static gdouble get_grad_value_orbital(gfloat x,gfloat y,gfloat z,gint k, gint id)
{
	
	gdouble v=0.0;
	gint i;

	if(TypeSelOrb == 1)
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefAlphaOrbitals[k][i])>1e-10)
			v+=CoefAlphaOrbitals[k][i]*get_grad_value_CGTF(x,y,z,i,id);
	}
	else
	for(i=0;i<NAOrb;i++)
	{
		if(fabs(CoefBetaOrbitals[k][i])>1e-10)
			v+=CoefBetaOrbitals[k][i]*get_grad_value_CGTF(x,y,z,i,id);
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
		
		cgv = get_value_CGTF(x,y,z,i);
		dcgv = get_grad_value_CGTF(x,y,z,i,id);
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
		
		cgv = get_value_CGTF(x,y,z,i);
		dcgvX = get_grad_value_CGTF(x,y,z,i,0);
		dcgvY = get_grad_value_CGTF(x,y,z,i,1);
		dcgvZ = get_grad_value_CGTF(x,y,z,i,2);
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
		
		cgv = get_value_CGTF(x,y,z,i);
		dcgvX = get_grad_value_CGTF(x,y,z,i,0);
		dcgvY = get_grad_value_CGTF(x,y,z,i,1);
		dcgvZ = get_grad_value_CGTF(x,y,z,i,2);
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
