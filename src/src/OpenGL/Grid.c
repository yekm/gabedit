/* Grid.c */
/**********************************************************************************************************
Copyright (c) 2002 Abdul-Rahman Allouche. All rights reserved

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
#include "GlobalOrb.h"
#include "StatusOrb.h"
#include "ColorMap.h"

/**************************************************************/
gfloat get_value_GTF(gfloat x,gfloat y,gfloat z,gint i,gint n)
{
	gfloat v = 0.0;
    gfloat d = 0;
	gfloat xi = x-AOrb[i].Gtf[n].C[0];
	gfloat yi = y-AOrb[i].Gtf[n].C[1];
	gfloat zi = z-AOrb[i].Gtf[n].C[2];

    d = (xi*xi)+(yi*yi)+(zi*zi);
	d *=AOrb[i].Gtf[n].Ex;
        if(d>40)
	  return 0.0;
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
gfloat get_value_CGTF(gfloat x,gfloat y,gfloat z,gint i)
{
	gfloat v = 0.0;
	gint n;

        for(n=0;n<AOrb[i].N;n++)
	   v+= get_value_GTF(x,y,z,i,n);

	return v;
}
/**************************************************************/
gfloat get_value_orbital(gfloat x,gfloat y,gfloat z,gint k)
{
	
	gfloat v=0.0;
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
gfloat get_value_electronic_density_on_atom(gfloat x,gfloat y,gfloat z,gint n)
{
	
	gfloat v1 = 0.0;
	gfloat v2 = 0.0;
	gfloat cgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gfloat *PhiAlpha = g_malloc(GeomOrb[n].NAlphaOrb*sizeof(gfloat));
	gfloat *PhiBeta  = g_malloc(GeomOrb[n].NBetaOrb*sizeof(gfloat));

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
gfloat get_value_electronic_density_atomic(gfloat x,gfloat y,gfloat z,gint dump)
{
	gfloat v = 0.0;
	gint i;
	for(i=0;i<Ncenters;i++)
		v += get_value_electronic_density_on_atom(x,y,z,i);
		
	return v;
}

/**************************************************************/
gfloat get_value_electronic_density(gfloat x,gfloat y,gfloat z,gint dump)
{
	
	gfloat v1 = 0.0;
	gfloat v2 = 0.0;
	gfloat cgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gfloat *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gfloat));
	gfloat *PhiBeta  = g_malloc(NBetaOrb*sizeof(gfloat));

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
gfloat get_value_electronic_density_bonds(gfloat x,gfloat y,gfloat z,gint dump)
{
	gfloat v = 0.0;
	v = get_value_electronic_density(x,y,z,dump);
	v -= get_value_electronic_density_atomic(x,y,z,dump);
	return v;
}
/**************************************************************/
gfloat get_value_spin_density(gfloat x,gfloat y,gfloat z,gint dump)
{
	
	gfloat v1 = 0.0;
	gfloat v2 = 0.0;
	gfloat cgv = 0.0;
	gint i;
	gint k1;
	gint k2;
	gfloat *PhiAlpha = g_malloc(NAlphaOrb*sizeof(gfloat));
	gfloat *PhiBeta  = g_malloc(NBetaOrb*sizeof(gfloat));

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

	}
	if(grid)
		set_status_label_info("Grid","Ok");
	else
		set_status_label_info("Grid","Nothing");
	return grid;
}
/**************************************************************/

