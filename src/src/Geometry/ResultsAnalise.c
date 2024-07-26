/* ResultsAnalise.c */
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
#include "../Common/Global.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "../Geometry/ResultsAnalise.h"
#include "../Geometry/EnergiesCurves.h"
#include "../Common/Run.h"
#include "../OpenGL/ViewOrb.h"

/*********************************************************************/
DataGeomConv free_geom_conv(DataGeomConv GeomConv)
{
 gint i,j;

 for(i = 0;i<GeomConv.Ntype;i++)
		if(GeomConv.TypeData[i])
			g_free(GeomConv.TypeData[i]);

 if(GeomConv.GeomFile)
		g_free(GeomConv.GeomFile);
 GeomConv.GeomFile = NULL;
 if(GeomConv.TypeData)
		g_free(GeomConv.TypeData);
 GeomConv.TypeData = NULL;

 if(GeomConv.TypeCalcul)
		g_free(GeomConv.TypeCalcul);
 GeomConv.TypeCalcul = NULL;

  if( GeomConv.Npoint<1)
  {
	if(GeomConv.Data)
		g_free(GeomConv.Data);
        GeomConv.Data = NULL;
	if(GeomConv.NumGeom)
		g_free(GeomConv.NumGeom);
	GeomConv.NumGeom = NULL;
	return GeomConv;
  }
 for(j = 0;j<GeomConv.Ntype;j++)
 {
  	if(GeomConv.Data[j])
  	for(i = 0;i<GeomConv.Npoint;i++)
		if(GeomConv.Data[j][i])
			g_free(GeomConv.Data[j][i]);

  	if(GeomConv.Data[j])
		g_free(GeomConv.Data[j]);

  	GeomConv.Data[j] = NULL;
 }  
 GeomConv.Npoint = 0;
 GeomConv.Ntype  = 0;

 return GeomConv;
}
/*********************************************************************/
DataGeomConv init_geom_dalton_conv(gchar *namefile)
{
	DataGeomConv GeomConv;
	gint i;
	GeomConv.Npoint = 0;
	GeomConv.Ntype  = 2;
	GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
	GeomConv.fileType = GABEDIT_TYPEFILE_DALTON;
	GeomConv.TypeData[0] = g_strdup(" Energy ");
	GeomConv.TypeData[1] = g_strdup(" Norm Step ");
	GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
	for(i = 0;i<GeomConv.Ntype;i++) GeomConv.Data[i] = NULL;
	GeomConv.TypeCalcul = NULL;
	GeomConv.NumGeom = NULL;
	GeomConv.GeomFile = g_strdup(namefile);

	return GeomConv;
}
/*********************************************************************/
DataGeomConv init_geom_mpqc_conv(gchar *namefile)
{
	DataGeomConv GeomConv;
	gint i;
	GeomConv.Npoint = 0;
	GeomConv.Ntype  = 3;
	GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
	GeomConv.fileType = GABEDIT_TYPEFILE_MPQC;
	GeomConv.TypeData[0] = g_strdup(" Energy ");
	GeomConv.TypeData[1] = g_strdup(" Max Gradient ");
	GeomConv.TypeData[2] = g_strdup(" Max Displacement ");
	GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
	for(i = 0;i<GeomConv.Ntype;i++) GeomConv.Data[i] = NULL;
	GeomConv.TypeCalcul = NULL;
	GeomConv.NumGeom = NULL;
	GeomConv.GeomFile = g_strdup(namefile);

	return GeomConv;
}
/*********************************************************************/
void find_energy_mpqc_output(gchar* NomFichier)
{
	gchar *pdest;
	guint  i=0;
	guint  j=0;
	guint  k=0;
	gchar *temp =  g_malloc(50*sizeof(char));	
	guint taille=BSIZE;
	gchar *t;
	FILE *fd;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;
	gboolean newGeom = FALSE;
	gboolean mp2 = FALSE;

        
        Ncalculs++;
	GeomConv =  g_malloc(sizeof(DataGeomConv) );
  	GeomConv[Ncalculs-1] = init_geom_mpqc_conv(NomFichier);

	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r"); 
        if(!fd)
	{
		g_free(t);
		t = g_strdup_printf(" Error : I can not open file %s\n",NomFichier);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return;
	}
        
	 while(!feof(fd))
	{
		pdest = NULL;
		 fgets(t,taille,fd);
		 /*
                 if( strlen(t)>2 && strstr(t,"changing atomic coordinates:") )
		 {
         		Ncalculs++;
			GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
  			GeomConv[Ncalculs-1] = init_geom_mpqc_conv(NomFichier);
			GeomConv[Ncalculs-1].TypeCalcul = g_malloc(100*sizeof(char));
                 	sscanf(t,"%s",GeomConv[Ncalculs-1].TypeCalcul);
		 }
		 */
                 if(strstr(t,"changing atomic coordinates:"))
		 {
			GeomConv[Ncalculs-1].TypeCalcul = g_malloc(100*sizeof(char));
                 	sscanf(t,"%s",GeomConv[Ncalculs-1].TypeCalcul);
			newGeom = TRUE;
			if(strstr(t,"MBPT2")) mp2 = TRUE;
		 }

          	if(newGeom && mp2)
		{
			pdest = NULL;
    		 	pdest = strstr( t,"MP2");
    		 	if(pdest)
			{
				if(strstr(t,"correlation")) pdest = NULL;
				else pdest = strstr( t,"energy");
   				if( pdest != NULL ) pdest = strstr( t,":");
			}
		}
		if(newGeom && !mp2)
		{
			pdest = NULL;
			pdest = strstr( t,"total scf energy");
   			if( pdest != NULL ) pdest = strstr( t,"=");
		}

   		if( pdest != NULL )
		{
			pdest++;
			GeomConv[Ncalculs-1].Npoint++;
			if(GeomConv[Ncalculs-1].Npoint == 1 )
			{
				GeomConv[Ncalculs-1].NumGeom =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
					GeomConv[Ncalculs-1].Data[i] =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
			}
		  	else
		  	{
				GeomConv[Ncalculs-1].NumGeom =  g_realloc(GeomConv[Ncalculs-1].NumGeom,GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
					GeomConv[Ncalculs-1].Data[i] =  g_realloc(GeomConv[Ncalculs-1].Data[i],GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  	}
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
            		{
		 		GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 		GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1][0] = '\0';
                 	}
		 	GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 	sscanf(pdest,"%s", GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1]);
		}
			
                 pdest = NULL;
    		 pdest = strstr( t,"Max Gradient");
                 if( pdest != NULL && GeomConv[Ncalculs-1].Npoint>0)
		 {
    		 	pdest = strstr( t,":");
			if(pdest)
			{
				pdest++;
                 		sscanf(pdest,"%s",GeomConv[Ncalculs-1].Data[1][GeomConv[Ncalculs-1].Npoint-1]);
			}
		 }
    		 pdest = strstr( t,"Max Displacement");
                 if( pdest != NULL && GeomConv[Ncalculs-1].Npoint>0)
		 {
    		 	pdest = strstr( t,":");
			if(pdest)
			{
				pdest++;
                 		sscanf(pdest,"%s",GeomConv[Ncalculs-1].Data[2][GeomConv[Ncalculs-1].Npoint-1]);
			}
		 }
	}

	fclose(fd);
   
	if( Ncalculs>0 && GeomConv[Ncalculs-1].Npoint == 0)
	{
		GeomConv[Ncalculs-1] =  free_geom_conv(GeomConv[Ncalculs-1]);
		Ncalculs--;
		if(Ncalculs>0)
			GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
		else
		{
			g_free(GeomConv);
			GeomConv =  NULL;
		}
	}

	/*
    printf("Npoint  = %d\n ",GeomConv[Ncalculs-1].Npoint);
    printf("TypeCalcul  = %s\n ",GeomConv[Ncalculs-1].TypeCalcul);
   for(i=0;i<GeomConv[Ncalculs-1].Npoint;i++)
   {
   	for(j=0;j<GeomConv[Ncalculs-1].Ntype;j++)
          	printf("%s ",GeomConv[Ncalculs-1].Data[j][i]);
       	printf("\n ");
	
   }
   */

	k = 0;
	for(i=0;(gint)i<Ncalculs;i++)
	{
		for(j=0;(gint)j<GeomConv[i].Npoint;j++)
		{
			k++;
			GeomConv[i].NumGeom[j] = k;
		}
		k++;
	}
	create_energies_curves(GeomConv,Ncalculs);
	g_free(t);
	g_free(temp);
}
/*********************************************************************/
DataGeomConv init_geom_xyz_conv(gchar *namefile)
{
	DataGeomConv GeomConv;
	GeomConv.Npoint = 0;
	GeomConv.Ntype  = 1;
	GeomConv.fileType = GABEDIT_TYPEFILE_XYZ;
	GeomConv.TypeCalcul = g_strdup("Geometries for an xyz file");
	GeomConv.NumGeom = NULL;
	GeomConv.GeomFile = g_strdup(namefile);
	GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
	GeomConv.TypeData[0] = g_strdup(" Geometry number ");
	GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
	GeomConv.Data[0] = NULL;
	return GeomConv;
}
/*********************************************************************/
static void find_energy_xyz(gchar* fileName)
{
	gint  i=0;
	gint  j=0;
	guint taille=BSIZE;
	gchar t[BSIZE];
	FILE *file;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;
	gint ne;
	gint nAtoms;

	GeomConv = NULL;
        
 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		sprintf(t," Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		return;
	}
        
	 while(!feof(file))
	{
		if(!fgets(t,taille,file))break;
		ne = sscanf(t,"%d",&nAtoms);
		if(ne==1 && nAtoms>0)
		 {
         		if(Ncalculs==0)
			{
				Ncalculs = 1;
				GeomConv =  g_malloc(sizeof(DataGeomConv) );
  				GeomConv[0] = init_geom_xyz_conv(fileName);
			}
		 	if(!fgets(t,taille,file)) break; /* title */
			GeomConv[0].Npoint++;
			for(i=0;i<nAtoms;i++)
				if(!fgets(t,taille,file))break;
		 }
		else
			break;
	}

	fclose(file);
   
	if(GeomConv)
	{
		if(GeomConv[0].Npoint == 0)
		{
			GeomConv[0] =  free_geom_conv(GeomConv[0]);
			g_free(GeomConv);
			GeomConv =  NULL;
			Ncalculs = 0;
		}
		else
		{
			GeomConv[0].NumGeom = g_malloc(GeomConv[0].Npoint*sizeof(gint));	
			GeomConv[0].Data[0] = g_malloc(GeomConv[0].Npoint*sizeof(gchar*));	
			for(j=0;(gint)j<GeomConv[0].Npoint;j++)
			{
				GeomConv[0].NumGeom[j] = j+1;
		 		GeomConv[0].Data[0][j] = g_strdup_printf("%d",j+1);
			}
		}
	}
	create_energies_curves(GeomConv,Ncalculs);
}
/*********************************************************************/
DataGeomConv init_geom_gauss_conv(gchar *namefile)
{
  DataGeomConv GeomConv;
  gint i;
  GeomConv.Npoint = 0;
  GeomConv.Ntype  = 5;
  GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
  GeomConv.fileType = GABEDIT_TYPEFILE_GAUSSIAN;
 GeomConv.TypeData[0] = g_strdup(" Energy ");
 GeomConv.TypeData[1] = g_strdup(" Force Max ");
 GeomConv.TypeData[2] = g_strdup(" Force RMS ");
 GeomConv.TypeData[3] = g_strdup(" Dep. Max ");
 GeomConv.TypeData[4] = g_strdup(" Dep. RMS ");
 GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
 for(i = 0;i<GeomConv.Ntype;i++)
 	GeomConv.Data[i] = NULL;
 GeomConv.TypeCalcul = NULL;
 GeomConv.NumGeom = NULL;
 GeomConv.GeomFile = g_strdup(namefile);

  return GeomConv;
}
/*********************************************************************/
DataGeomConv init_geom_molpro_conv(gchar* namefile)
{
  DataGeomConv GeomConv;
 gint i;
  GeomConv.Npoint = 0;
  GeomConv.Ntype  = 2;
  GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
  GeomConv.fileType = GABEDIT_TYPEFILE_MOLPRO;
 GeomConv.TypeData[0] = g_strdup(" Energy ");
 GeomConv.TypeData[1] = g_strdup(" Convergence ");
 GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
 for(i = 0;i<GeomConv.Ntype;i++)
 	GeomConv.Data[i] = NULL;
 GeomConv.TypeCalcul = NULL;
 GeomConv.NumGeom = NULL;
 GeomConv.GeomFile = g_strdup(namefile);
 return GeomConv;
}
/*********************************************************************/
void find_energy_dalton_output(gchar* NomFichier)
{
	guint  i=0;
	guint  j=0;
	guint  k=0;
	gchar *temp =  g_malloc(50*sizeof(char));	
	gchar *tmp =  g_malloc(50*sizeof(char));	
	guint taille=BSIZE;
	gchar *t;
	FILE *fd;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;
	gboolean OK;

        
	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r"); 
        if(!fd)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",NomFichier);
		Message(t," Error ",TRUE);
		if(t)
			g_free(t);
		return;
	}
        
	while(!feof(fd))
	{
		 fgets(t,taille,fd);
                 if(strstr(t,"Optimization Control Center") && Ncalculs <1)
		 {
         		Ncalculs = 1;
                        GeomConv =  g_malloc(sizeof(DataGeomConv) );
  			GeomConv[Ncalculs-1] = init_geom_dalton_conv(NomFichier);
		 }
                 if(strstr(t,"Optimization Control Center") )
		 {
			OK = TRUE;
			while(!feof(fd) && OK )
			{
		 		if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
				if(strstr(t,"Next geometry") || strstr(t,"Final geometry"))
				{
		 			if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
		 			if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;

			OK = TRUE;
			while(!feof(fd) && OK )
			{
		 		if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
				if(strstr(t,"Energy at this geometry is"))
				{
		 			gchar* t1 = strstr(t,":");
					if(t1) sscanf(t1+1,"%s",tmp); /* energy */
					else { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;
			OK = TRUE;
			while(!feof(fd) && OK )
			{
		 		if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
				if(strstr(t,"Norm of step"))
				{
		 			gchar* t1 = strstr(t,":");
					if(t1) sscanf(t1+1,"%s",temp); /* rmsStep */
					else { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;
		
		  	GeomConv[Ncalculs-1].Npoint++;
		  	if(GeomConv[Ncalculs-1].Npoint == 1 )
		  	{
				GeomConv[Ncalculs-1].NumGeom =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++) GeomConv[Ncalculs-1].Data[i] =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  	}
		  	else
		  	{
				GeomConv[Ncalculs-1].NumGeom =  g_realloc(GeomConv[Ncalculs-1].NumGeom,GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				GeomConv[Ncalculs-1].Data[i] =  g_realloc(GeomConv[Ncalculs-1].Data[i],GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  	}
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
                 	{
		 		GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 		GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1][0] = '\0';
                 	}
		 	GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
		 	GeomConv[Ncalculs-1].TypeCalcul = g_strdup(" ");
                 	sprintf(GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1], tmp);
                 	sprintf(GeomConv[Ncalculs-1].Data[1][GeomConv[Ncalculs-1].Npoint-1], temp);
		}
	}
	fclose(fd);
   
	if( Ncalculs>0 && GeomConv[Ncalculs-1].Npoint == 0)
	{
		GeomConv[Ncalculs-1] =  free_geom_conv(GeomConv[Ncalculs-1]);
		Ncalculs--;
		if(Ncalculs>0) GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
		else
		{
			g_free(GeomConv);
			GeomConv =  NULL;
		}
	}
	k = 0;
	for(i=0;(gint)i<Ncalculs;i++)
   	for(j=0;(gint)j<GeomConv[i].Npoint;j++)
	{
	   k++;
	   GeomConv[i].NumGeom[j] = k;
	}
	create_energies_curves(GeomConv,Ncalculs);
	g_free(t);
	g_free(temp);
	g_free(tmp);
}
/*********************************************************************/
DataGeomConv init_geom_gamess_conv(gchar *namefile)
{
	DataGeomConv GeomConv;
	gint i;
	GeomConv.Npoint = 0;
	GeomConv.Ntype  = 3;
	GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
	GeomConv.fileType = GABEDIT_TYPEFILE_GAMESS;
	GeomConv.TypeData[0] = g_strdup(" Energy ");
	GeomConv.TypeData[1] = g_strdup(" MAX Gradient ");
	GeomConv.TypeData[2] = g_strdup(" RMS Gradient ");
	GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
	for(i = 0;i<GeomConv.Ntype;i++) GeomConv.Data[i] = NULL;
	GeomConv.TypeCalcul = NULL;
	GeomConv.NumGeom = NULL;
	GeomConv.GeomFile = g_strdup(namefile);

	return GeomConv;
}
/*********************************************************************/
void find_energy_gamess_output(gchar* NomFichier)
{
	guint  i=0;
	guint  j=0;
	guint  k=0;
	gchar *maxgrad =  g_malloc(50*sizeof(char));	
	gchar *rmsgrad =  g_malloc(50*sizeof(char));	
	gchar *tmp =  g_malloc(50*sizeof(char));	
	guint taille=BSIZE;
	gchar *t;
	FILE *fd;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;
	gboolean OK;

        
	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r"); 
        if(!fd)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",NomFichier);
		Message(t," Error ",TRUE);
		if(t)
			g_free(t);
		return;
	}
        
	while(!feof(fd))
	{
		 fgets(t,taille,fd);
                 if(strstr(t,"BEGINNING GEOMETRY SEARCH POINT NSERCH") && Ncalculs <1)
		 {
         		Ncalculs = 1;
                        GeomConv =  g_malloc(sizeof(DataGeomConv) );
  			GeomConv[Ncalculs-1] = init_geom_gamess_conv(NomFichier);
		 }
                 if(strstr(t,"COORDINATES OF ALL ATOMS ARE (ANGS)") )
		 {
			OK = TRUE;
			while(!feof(fd) && OK )
			{
		 		if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
				if(strstr(t,"NSERCH") && strstr(t,"ENERGY="))
				{
		 			gchar* t1 = strstr(t,"ENERGY=");
					if(t1) sscanf(t1+7,"%s",tmp); /* energy */
					else { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;
			OK = TRUE;
			while(!feof(fd) && OK )
			{
		 		if(!fgets(t, BSIZE,fd)) { OK = FALSE; break; }
				if(strstr(t,"MAXIMUM GRADIENT =")&& strstr(t,"RMS GRADIENT ="))
				{
		 			gchar* t1 = strstr(t,"MAXIMUM GRADIENT =");
					if(t1) sscanf(t1+19,"%s",maxgrad); /* maxGrad */
					else { OK = FALSE; break; }
		 			t1 = strstr(t,"RMS GRADIENT =");
					if(t1) sscanf(t1+15,"%s",rmsgrad); /* rmsGrad */
					else { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;
		
		  	GeomConv[Ncalculs-1].Npoint++;
		  	if(GeomConv[Ncalculs-1].Npoint == 1 )
		  	{
				GeomConv[Ncalculs-1].NumGeom =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++) GeomConv[Ncalculs-1].Data[i] =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  	}
		  	else
		  	{
				GeomConv[Ncalculs-1].NumGeom =  g_realloc(GeomConv[Ncalculs-1].NumGeom,GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				GeomConv[Ncalculs-1].Data[i] =  g_realloc(GeomConv[Ncalculs-1].Data[i],GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  	}
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
                 	{
		 		GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 		GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1][0] = '\0';
                 	}
		 	GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
		 	GeomConv[Ncalculs-1].TypeCalcul = g_strdup(" ");
                 	sprintf(GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1], tmp);
                 	sprintf(GeomConv[Ncalculs-1].Data[1][GeomConv[Ncalculs-1].Npoint-1], maxgrad);
                 	sprintf(GeomConv[Ncalculs-1].Data[2][GeomConv[Ncalculs-1].Npoint-1], rmsgrad);
		}
	}
	fclose(fd);
   
	if( Ncalculs>0 && GeomConv[Ncalculs-1].Npoint == 0)
	{
		GeomConv[Ncalculs-1] =  free_geom_conv(GeomConv[Ncalculs-1]);
		Ncalculs--;
		if(Ncalculs>0) GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
		else
		{
			g_free(GeomConv);
			GeomConv =  NULL;
		}
	}
	k = 0;
	for(i=0;(gint)i<Ncalculs;i++)
   	for(j=0;(gint)j<GeomConv[i].Npoint;j++)
	{
	   k++;
	   GeomConv[i].NumGeom[j] = k+1;
	}
	create_energies_curves(GeomConv,Ncalculs);
	g_free(t);
	g_free(tmp);
	g_free(maxgrad);
	g_free(rmsgrad);
}
/*********************************************************************/
void find_energy_gauss_output(gchar* NomFichier)
{
	gchar* pdest = NULL;
	guint  i=0;
	guint  j=0;
	guint  k=0;
	gchar *temp =  g_malloc(50*sizeof(char));	
	guint taille=BSIZE;
	gchar *t;
	FILE *fd;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;

        
        Ncalculs++;
/*
	if(GeomConv) 
		*GeomConv =  free_geom_conv(*GeomConv);
        else
*/
		GeomConv =  g_malloc(sizeof(DataGeomConv) );
		
  	GeomConv[Ncalculs-1] = init_geom_gauss_conv(NomFichier);

	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r"); 
        if(!fd)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",NomFichier);
		Message(t," Error ",TRUE);
		if(t)
			g_free(t);
		return;
	}
        
	 while(!feof(fd))
	{
		 fgets(t,taille,fd);
                 if( strlen(t)>2 && strstr(t,"Normal termination of Gaussian") )
		 {
         		Ncalculs++;
			GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
  			GeomConv[Ncalculs-1] = init_geom_gauss_conv(NomFichier);
		 }
		 g_strup(t);
                 if( strlen(t)>2 && t[1] == '#' && !GeomConv[Ncalculs-1].TypeCalcul)
		 {
			GeomConv[Ncalculs-1].TypeCalcul = g_malloc(100*sizeof(char));
                 	sscanf(t,"%s %s", temp, GeomConv[Ncalculs-1].TypeCalcul);
		 }
    		 pdest = strstr( t,"SCF DONE");
   		if( pdest != NULL )
		{
    		 pdest = strstr( t,"=");
		}
          	if(!pdest)
		{
    		 pdest = strstr( t,"ENERGY=");
          	 if(pdest && t[1] == 'E' )
    		 	pdest = strstr( t,"=");
                 else
    		 	pdest = NULL;
			
		}

   		if( pdest != NULL )
		{
		  pdest++;
		  GeomConv[Ncalculs-1].Npoint++;
		  if(GeomConv[Ncalculs-1].Npoint == 1 )
		  {
			GeomConv[Ncalculs-1].NumGeom =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				GeomConv[Ncalculs-1].Data[i] =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  }
		  else
		  {
			GeomConv[Ncalculs-1].NumGeom =  g_realloc(GeomConv[Ncalculs-1].NumGeom,GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				GeomConv[Ncalculs-1].Data[i] =  g_realloc(GeomConv[Ncalculs-1].Data[i],GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  }
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
            {
		 	GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 	GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1][0] = '\0';
                 }
		 GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 sscanf(pdest,"%s", GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1]);
		}
			
                 pdest = NULL;
    		 pdest = strstr( t,"CONVERGED?");
                 if( pdest != NULL && GeomConv[Ncalculs-1].Npoint>0)
		 {
			for(i=1;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
			{
		 		fgets(t,taille,fd);
                 		sscanf(t,"%s %s %s", temp,temp,GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1]);
			}
		 }
	}

    fclose(fd);
   
    if( Ncalculs>0 && GeomConv[Ncalculs-1].Npoint == 0)
    {
	GeomConv[Ncalculs-1] =  free_geom_conv(GeomConv[Ncalculs-1]);
	Ncalculs--;
	if(Ncalculs>0)
		GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
	else
	{
		g_free(GeomConv);
		GeomConv =  NULL;
	}
    }
/*
    printf("Npoint  = %d\n ",GeomConv[Ncalculs-1].Npoint);
    printf("TypeCalcul  = %s\n ",GeomConv[Ncalculs-1].TypeCalcul);
   for(i=0;i<GeomConv[Ncalculs-1].Npoint;i++)
   {
   	for(j=0;j<GeomConv[Ncalculs-1].Ntype;j++)
          	printf("%s ",GeomConv[Ncalculs-1].Data[j][i]);
       	printf("\n ");
	
   }
*/
   k = 0;
   for(i=0;(gint)i<Ncalculs;i++)
   {
   	for(j=0;(gint)j<GeomConv[i].Npoint;j++)
	{
	   k++;
	   GeomConv[i].NumGeom[j] = k;
	}
        k++;
  }
  create_energies_curves(GeomConv,Ncalculs);
  g_free(t);
  g_free(temp);
}
/*************************************************************************************/
static DataGeomConv init_geom_molden_gabedit_conv(gchar *fileName, GabEditTypeFile type)
{
	DataGeomConv GeomConv;
	gint i;
	GeomConv.Npoint = 0;
	GeomConv.Ntype  = 5;
	GeomConv.TypeData = g_malloc(GeomConv.Ntype*sizeof(gchar*) );
  	GeomConv.fileType = type;
	GeomConv.TypeData[0] = g_strdup(" Energy ");
	GeomConv.TypeData[1] = g_strdup(" Force Max ");
	GeomConv.TypeData[2] = g_strdup(" Force RMS ");
	GeomConv.TypeData[3] = g_strdup(" Dep. Max ");
	GeomConv.TypeData[4] = g_strdup(" Dep. RMS ");
	GeomConv.Data = g_malloc(GeomConv.Ntype*sizeof(gchar**) );
	for(i = 0;i<GeomConv.Ntype;i++)
		GeomConv.Data[i] = NULL;
	GeomConv.TypeCalcul = NULL;
	GeomConv.NumGeom = NULL;
	GeomConv.GeomFile = g_strdup(fileName);

	return GeomConv;
}
/*********************************************************************/
void find_energy_molpro_log(gchar* NomFichier)
{
	gchar *pdest;
	guint  i=0;
	guint  j=0;
	guint  k=0;
	gchar *temp =  g_malloc(50*sizeof(char));	
	guint taille=BSIZE;
	gchar *t;
	FILE *fd;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;
	gboolean Ok;

        
	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r"); 
        if(!fd)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",NomFichier);
		Message(t," Error ",TRUE);
		if(t)
			g_free(t);
		return;
	}
        
	 while(!feof(fd))
	{
		 fgets(t,taille,fd);
                 if( strlen(t)>2 && strstr(t,"GEOMETRY OPTIMIZATION STEP  1") )
		 {
         		Ncalculs++;
                        if(Ncalculs == 1)
				GeomConv =  g_malloc(sizeof(DataGeomConv) );
			else
				GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
  			GeomConv[Ncalculs-1] = init_geom_molpro_conv(NomFichier);
		 }
    		 pdest = strstr( t,"Optimization point");

   		if( pdest != NULL  && Ncalculs>0)
		{
		  GeomConv[Ncalculs-1].Npoint++;
		  if(GeomConv[Ncalculs-1].Npoint == 1 )
		  {
			GeomConv[Ncalculs-1].NumGeom =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				GeomConv[Ncalculs-1].Data[i] =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  }
		  else
		  {
			GeomConv[Ncalculs-1].NumGeom =  g_realloc(GeomConv[Ncalculs-1].NumGeom,GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				GeomConv[Ncalculs-1].Data[i] =  g_realloc(GeomConv[Ncalculs-1].Data[i],GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
		  }
			for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
                 {
		 	GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
                 	GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1][0] = '\0';
                 }
		 GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 

		 Ok = TRUE;
                 while(!feof(fd) && Ok )
		 {
		 	if(!fgets(t,taille,fd))
			{
				Ok = FALSE;
				break;
			}
			else
			{
				if(strstr(t,"(") && strstr(t,")"))
				{
					Ok = TRUE;
					break;
				}

			}
		 }
		 if(!Ok) break;
                 sscanf(t,"%s %s %s %s %s",temp,temp,temp,temp,GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1]);
		 g_strup(t);
		 GeomConv[Ncalculs-1].TypeCalcul = g_malloc(100*sizeof(char));
    		 pdest = strstr( t,"(");
                 pdest++;
                 sscanf(pdest,"%s)",GeomConv[Ncalculs-1].TypeCalcul);
                 for(i=0;i<strlen(GeomConv[Ncalculs-1].TypeCalcul);i++)
		 {
			if(GeomConv[Ncalculs-1].TypeCalcul[i] == ')')
				GeomConv[Ncalculs-1].TypeCalcul[i] = ' ';
		 }

                 do
                 {
		 fgets(t,taille,fd);
                 }while(strstr(t,"Convergence:")==NULL && !feof(fd) ) ;
                 if(strstr(t,"Convergence:")!=NULL)
                 	sscanf(t,"%s %s %s %s %s ", temp,temp,temp,temp,GeomConv[Ncalculs-1].Data[1][GeomConv[Ncalculs-1].Npoint-1]);
		else
		 	GeomConv[Ncalculs-1].Data[1][GeomConv[Ncalculs-1].Npoint-1] = " ";
		}
			
	}

    fclose(fd);
   
    if( Ncalculs>0 && GeomConv[Ncalculs-1].Npoint == 0)
    {
	GeomConv[Ncalculs-1] =  free_geom_conv(GeomConv[Ncalculs-1]);
	Ncalculs--;
	if(Ncalculs>0)
		GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
	else
	{
		g_free(GeomConv);
		GeomConv =  NULL;
	}
    }
   k = 0;
   for(i=0;(gint)i<Ncalculs;i++)
   	for(j=0;(gint)j<GeomConv[i].Npoint;j++)
	{
	   k++;
	   GeomConv[i].NumGeom[j] = k;
	}
  create_energies_curves(GeomConv,Ncalculs);
  g_free(t);
  g_free(temp);
}
/*********************************************************************/
static void find_energy_molden_gabedit(gchar* FileName, GabEditTypeFile type)
{
	guint  i=0;
	guint  j=0;
	guint  k=0;
	guint taille=BSIZE;
	gchar temp[BSIZE];
	gchar t[BSIZE];
	FILE *fd;
        gint Ncalculs = 0;
  	static DataGeomConv* GeomConv =NULL;
	gint nn = 0;
        
 	fd = FOpen(FileName, "r"); 
        if(!fd)
	{
		sprintf(t," Error : I can not open file %s\n",FileName);
		Message(t," Error ",TRUE);
		return;
	}
        
	 while(!feof(fd))
	{
		if(Ncalculs==0 || !strstr(t,"[GEOCONV]"))
		 fgets(t,taille,fd);
		 g_strup(t);
                 if(strstr(t,"[GEOCONV]") )
		 {
		 	/* printf("OK GEOCONV %s\n",t);*/
         		Ncalculs++;
			if(Ncalculs==1)
				GeomConv =  g_malloc(sizeof(DataGeomConv) );
			else
				GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
  			GeomConv[Ncalculs-1] = init_geom_molden_gabedit_conv(FileName, type);
			GeomConv[Ncalculs-1].TypeCalcul = g_malloc(100*sizeof(char));
			GeomConv[Ncalculs-1].fileType = type;
                 	nn = sscanf(t,"%s %s", temp, GeomConv[Ncalculs-1].TypeCalcul);
			if(nn<2) sprintf(GeomConv[Ncalculs-1].TypeCalcul," ");
		 	if(!fgets(t,taille,fd)) break;
		 	g_strup(t);
		 }

		 /* printf("%s\n",t);*/

   		if( strstr( t,"ENERGY") != NULL )
		{
	 		while(!feof(fd))
			{
		 		if(!fgets(t,taille,fd)) break;

				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
		 		if(!isFloat(t))
				{
					/* printf("%s is not a real \n",t);*/
					break;
				}
				GeomConv[Ncalculs-1].Npoint++;
				if(GeomConv[Ncalculs-1].Npoint == 1 )
				{
					GeomConv[Ncalculs-1].NumGeom =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
					for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
						GeomConv[Ncalculs-1].Data[i] =  g_malloc(GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
				}
				else
				{
					GeomConv[Ncalculs-1].NumGeom =  g_realloc(GeomConv[Ncalculs-1].NumGeom,GeomConv[Ncalculs-1].Npoint*sizeof(gint));	
					for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
						GeomConv[Ncalculs-1].Data[i] =  g_realloc(GeomConv[Ncalculs-1].Data[i],GeomConv[Ncalculs-1].Npoint*sizeof(char*));	
				}
				for(i=0;(gint)i<GeomConv[Ncalculs-1].Ntype;i++)
				{
					GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
					GeomConv[Ncalculs-1].Data[i][GeomConv[Ncalculs-1].Npoint-1][0] = '\0';
				}
				GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1] = g_malloc(50*sizeof(char)); 
				sscanf(t,"%s", GeomConv[Ncalculs-1].Data[0][GeomConv[Ncalculs-1].Npoint-1]);
			}
			if(GeomConv[Ncalculs-1].Npoint<1) continue;
	 		while(!feof(fd))
			{
		 		g_strup(t);
   				if( strstr( t,"MAX-FORCE") != NULL )
				{
					for(i=0;(gint)i<GeomConv[Ncalculs-1].Npoint;i++)
					{
		 				if(!fgets(t,taille,fd)) break;
						str_delete_n(t);
						delete_last_spaces(t);
						delete_first_spaces(t);
		 				if(!isFloat(t)) break;
						sscanf(t,"%s", GeomConv[Ncalculs-1].Data[1][i]);
					}
				}
   				if( strstr( t,"RMS-FORCE") != NULL )
				{
					for(i=0;(gint)i<GeomConv[Ncalculs-1].Npoint;i++)
					{
		 				if(!fgets(t,taille,fd)) break;
						str_delete_n(t);
						delete_last_spaces(t);
						delete_first_spaces(t);
		 				if(!isFloat(t)) break;
						sscanf(t,"%s", GeomConv[Ncalculs-1].Data[2][i]);
					}
				}
   				if( strstr( t,"MAX-STEP") != NULL )
				{
					for(i=0;(gint)i<GeomConv[Ncalculs-1].Npoint;i++)
					{
		 				if(!fgets(t,taille,fd)) break;
						str_delete_n(t);
						delete_last_spaces(t);
						delete_first_spaces(t);
		 				if(!isFloat(t)) break;
						sscanf(t,"%s", GeomConv[Ncalculs-1].Data[3][i]);
					}
				}
   				if( strstr( t,"RMS-STEP") != NULL )
				{
					for(i=0;(gint)i<GeomConv[Ncalculs-1].Npoint;i++)
					{
		 				if(!fgets(t,taille,fd)) break;
						str_delete_n(t);
						delete_last_spaces(t);
						delete_first_spaces(t);
		 				if(!isFloat(t)) break;
						sscanf(t,"%s", GeomConv[Ncalculs-1].Data[4][i]);
					}
				}
                 		if(strstr(t,"[GEOCONV]") ) break;
		 		if(!fgets(t,taille,fd)) break;
			}
                 	if(strstr(t,"[GEOCONV]") ) continue;
		 	if(!fgets(t,taille,fd)) break;
		}
	}

	fclose(fd);
   
	if( Ncalculs>0 && GeomConv[Ncalculs-1].Npoint == 0)
	{
		GeomConv[Ncalculs-1] =  free_geom_conv(GeomConv[Ncalculs-1]);
		Ncalculs--;
		if(Ncalculs>0)
			GeomConv =  g_realloc(GeomConv, Ncalculs*sizeof(DataGeomConv) );
		else
		{
			g_free(GeomConv);
			GeomConv =  NULL;
		}
	}
	/*
	printf("Ncalculs  = %d\n ",Ncalculs);
	if(Ncalculs>0)
	{
		printf("Npoint  = %d\n ",GeomConv[Ncalculs-1].Npoint);
		printf("TypeCalcul  = %s\n ",GeomConv[Ncalculs-1].TypeCalcul);
		for(i=0;i<GeomConv[Ncalculs-1].Npoint;i++)
		{
			for(j=0;j<GeomConv[Ncalculs-1].Ntype;j++)
          			printf("%s ",GeomConv[Ncalculs-1].Data[j][i]);
       			printf("\n ");
		}
	}
	*/

	k = 0;
	for(i=0;(gint)i<Ncalculs;i++)
	{
		for(j=0;(gint)j<GeomConv[i].Npoint;j++)
		{
			k++;
			GeomConv[i].NumGeom[j] = k;
		}
	}
	create_energies_curves(GeomConv,Ncalculs);
}
/*********************************************************************/
void find_energy_gamess_gauss_molcas_molpro_mpqc(GtkWidget *wid,gpointer data)
{
 	gchar* fileName = g_strdup_printf("%s%s%s",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.logfile);
	if( iprogram == PROG_IS_GAMESS) find_energy_gamess_output(fileName);
	if( iprogram == PROG_IS_GAUSS) find_energy_gauss_output(fileName);
	if( iprogram == PROG_IS_MPQC) find_energy_mpqc_output(fileName);
	if( iprogram == PROG_IS_MOLPRO) find_energy_molpro_log(fileName);
	if( iprogram == PROG_IS_MOLCAS)
	{
 		gchar* fileName = g_strdup_printf("%s%s%s.geomConv.molden",fileopen.localdir,G_DIR_SEPARATOR_S,fileopen.projectname);
		find_energy_molden_gabedit(fileName,GABEDIT_TYPEFILE_MOLDEN);
		g_free(fileName);
	}
	g_free(fileName);
}
/************************************************************************************/
void read_geometries_conv_dalton(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *fileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
 	find_energy_dalton_output(fileName);
}
/************************************************************************************/
void read_geometries_conv_gamess(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *fileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
 	find_energy_gamess_output(fileName);
}
/************************************************************************************/
void read_geometries_conv_gaussian(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *fileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
 	find_energy_gauss_output(fileName);
}
/************************************************************************************/
void read_geometries_conv_molpro(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *fileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
 	find_energy_molpro_log(fileName);
}
/*************************************************************************************/
void read_geometries_conv_gabedit(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *FileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
	find_energy_molden_gabedit(FileName,GABEDIT_TYPEFILE_GABEDIT);
}
/************************************************************************************/
void read_geometries_conv_molden(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *FileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
	find_energy_molden_gabedit(FileName,GABEDIT_TYPEFILE_MOLDEN);
}
/************************************************************************************/
void read_geometries_conv_mpqc(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *fileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
	find_energy_mpqc_output(fileName);
}
/************************************************************************************/
void read_geometries_conv_xyz(GabeditFileChooser *SelecFile, gint response_id)
{       
 	gchar *fileName;

 	if(response_id != GTK_RESPONSE_OK) return;
 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
		Message("Sorry\n No selected file"," Error ",TRUE);
    		return ;
 	}
	find_energy_xyz(fileName);
}
/********************************************************************************/
/********************************************************************************/
static void sensitive_password()
{
	GtkWidget* Table;
	Table = g_object_get_data(G_OBJECT (ResultRemoteFrame), "PasswordTable");
	if(fileopen.netWorkProtocol==GABEDIT_NETWORK_FTP_RSH)
		gtk_widget_show(Table);
	else
	{
#ifdef G_OS_WIN32
		gtk_widget_show(Table);
#else
		gtk_widget_hide(Table);
#endif
	}
}
/********************************************************************************/
static void sensitive_buttons_false()
{
	sensitive_password();
  	gtk_widget_set_sensitive(ResultRemoteFrame, FALSE);
}
/********************************************************************************/
static void sensitive_buttons_true()
{
	sensitive_password();
  	gtk_widget_set_sensitive(ResultRemoteFrame, TRUE);
	if(
		fileopen.remotehost && !this_is_a_backspace(fileopen.remotehost) &&
		fileopen.remoteuser && !this_is_a_backspace(fileopen.remoteuser) 
	)
	{
		if(iprogram == PROG_IS_GAUSS)
		{
			GtkWidget* button = g_object_get_data(G_OBJECT(ResultRemoteFrame), "OutButton");
  			gtk_widget_set_sensitive(button, FALSE);
			button = g_object_get_data(G_OBJECT(ResultRemoteFrame),"AuxButton");
  			gtk_widget_set_sensitive(button, FALSE);
		}
		else
		{
			GtkWidget* button = g_object_get_data(G_OBJECT(ResultRemoteFrame),"OutButton");
  			gtk_widget_set_sensitive(button, TRUE);
			button = g_object_get_data(G_OBJECT(ResultRemoteFrame),"AuxButton");
  			gtk_widget_set_sensitive(button, TRUE);
		}
	}
	else
  		gtk_widget_set_sensitive(ResultRemoteFrame, FALSE);

	
}
/*********************************************************************/
void set_sensitive_remote_frame(gboolean sensitive)
{
	if(sensitive)
		sensitive_buttons_true();
	else
		sensitive_buttons_false();
}
/*********************************************************************/
void create_bar_result(GtkWidget* Vbox)
{
    GtkWidget *Button;
    GtkWidget *vboxframe;
    GtkWidget *frame;
    GtkWidget *handlebox;
    GtkWidget *vbox;
    GtkWidget *Table;
    GtkWidget *Label;
    GtkWidget *hseparator;
    static gint log = LOGFILE;
    static gint out = OUTFILE;
    static gint mol = MOLDENFILE;
    static gint all = ALLFILES;
  
/* here  init_geom_gauss_conv();
*/

  handlebox =gtk_handle_box_new ();
  gtk_widget_ref (handlebox);
  gtk_container_add( GTK_CONTAINER (Vbox), handlebox);
  gtk_handle_box_set_shadow_type (GTK_HANDLE_BOX(handlebox),GTK_SHADOW_IN);
/*
  GTK_SHADOW_NONE,
  GTK_SHADOW_IN,
  GTK_SHADOW_OUT,
  GTK_SHADOW_ETCHED_IN,
  GTK_SHADOW_ETCHED_OUT 
*/
  gtk_handle_box_set_handle_position  (GTK_HANDLE_BOX(handlebox),GTK_POS_TOP);   
  gtk_widget_show (handlebox);

  vbox = gtk_vbox_new (FALSE, 2);
  gtk_container_add( GTK_CONTAINER(handlebox), vbox);
  gtk_widget_show (vbox);

  frame = gtk_frame_new ("Local");
  gtk_container_set_border_width (GTK_CONTAINER (frame), 2);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_box_pack_start (GTK_BOX(vbox), frame, FALSE, TRUE, 2); 
  gtk_widget_show (frame);


  vboxframe = create_vbox(frame);
  ResultLocalFrame = frame;



  /* The Update Button */
  Button = create_button(Fenetre,"Update");
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(Button);
  gtk_widget_show(Button);
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)view_result,NULL);

  Button = create_button(Fenetre,"Go to end");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)goto_end_result,NULL);
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);

  Button = create_button(Fenetre,"Update/end");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)view_result_end,NULL);
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);

  Button = create_button(Fenetre,"Geom. Conv.");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)find_energy_gamess_gauss_molcas_molpro_mpqc,NULL);
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);

  Button = create_button(Fenetre,"Dens. Orb.");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)draw_density_orbitals_gamess_or_gauss_or_molcas_or_molpro,NULL);
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);

  frame = gtk_frame_new ("Remote");
  gtk_container_set_border_width (GTK_CONTAINER (frame), 2);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_box_pack_start (GTK_BOX(vbox), frame, FALSE, TRUE, 2); 
  gtk_widget_show (frame);
  vboxframe = create_vbox(frame);

  Table = gtk_table_new(3,1,FALSE);
  gtk_container_add(GTK_CONTAINER(vboxframe),Table);
  gtk_widget_show_all(vboxframe);
  Label = add_label_table(Table,"Password : ",0,0);
  ResultEntryPass = gtk_entry_new(); 
  gtk_entry_set_max_length  (GTK_ENTRY(ResultEntryPass),15);
  gtk_widget_set_size_request (ResultEntryPass,(gint)(ScreenHeight*0.05),-1);
  gtk_entry_set_visibility(GTK_ENTRY (ResultEntryPass),FALSE);

  gtk_table_attach(GTK_TABLE(Table),ResultEntryPass,0,1,1,2,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);
  hseparator = gtk_hseparator_new ();
  gtk_table_attach(GTK_TABLE(Table),hseparator,0,1,2,3,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);


  ResultRemoteFrame = frame;
  gtk_widget_set_sensitive(ResultRemoteFrame, FALSE);
  g_object_set_data(G_OBJECT (ResultRemoteFrame), "PasswordTable",Table);

  Button = create_button(Fenetre,"Get All files");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)get_file_frome_remote_host,&all);
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);
  g_object_set_data(G_OBJECT (ResultRemoteFrame), "AllButton",Button);
  g_signal_connect_swapped(G_OBJECT (ResultEntryPass), "activate",
			(GtkSignalFunc) gtk_button_clicked,
			GTK_OBJECT (Button));

  Button = create_button(Fenetre,"Get log file");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)get_file_frome_remote_host,&log);
  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);
  g_object_set_data(G_OBJECT (ResultRemoteFrame), "LogButton",Button);

  Button = create_button(Fenetre,"Get out file");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)get_file_frome_remote_host,&out);

  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);
  g_object_set_data(G_OBJECT (ResultRemoteFrame), "OutButton",Button);

  Button = create_button(Fenetre,"Get aux. files");
  g_signal_connect(G_OBJECT(Button), "clicked",(GtkSignalFunc)get_file_frome_remote_host,&mol);

  gtk_box_pack_start (GTK_BOX(vboxframe ), Button, FALSE, TRUE, 2);
  GTK_WIDGET_SET_FLAGS(Button, GTK_CAN_DEFAULT);
  gtk_widget_show(Button);
  g_object_set_data(G_OBJECT (ResultRemoteFrame), "AuxButton",Button);
}

