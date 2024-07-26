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
#include <stdlib.h>
#include "GlobalOrb.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "../Utils/UtilsInterface.h"
#include "../OpenGL/StatusOrb.h"
#include "../OpenGL/GLArea.h"
#include "../OpenGL/AnimationGeomConv.h"
#include "../OpenGL/GeomOrbXYZ.h"
#include "../OpenGL/AtomicOrbitals.h"
#include "../Files/FileChooser.h"
#include "../Geometry/GeomGlobal.h"
#include "../Files/FolderChooser.h"
#include "../Files/GabeditFolderChooser.h"
#include "../Common/Help.h"
#include "../Common/StockIcons.h"
#include "../OpenGL/PovrayGL.h"
#include "../OpenGL/Images.h"

static	GtkWidget *WinDlg = NULL;
static	GtkWidget *EntryVelocity = NULL;
static	GtkWidget *PlayButton = NULL;
static	GtkWidget *StopButton = NULL;
static	GtkTreeView *treeView = NULL;
static gboolean play = FALSE;

static GtkWidget *buttonCheckFilm = NULL;
static GtkWidget *buttonDirFilm = NULL;
static GtkWidget* comboListFilm = NULL;
static gboolean createFilm = FALSE;
static gint numFileFilm = 0;
static gchar formatFilm[100] = "BMP";

static gint rowSelected = -1;

/********************************************************************************/
static void animate();
static void rafreshList();
static void stopAnimation(GtkWidget *win, gpointer data);
static void playAnimation(GtkWidget *win, gpointer data);
static gboolean set_geometry(gint k);
/********************************************************************************/
static void reset_last_directory(GtkWidget *dirSelector, gpointer data)
{
	gchar* dirname = gabedit_folder_chooser_get_current_folder(GABEDIT_FOLDER_CHOOSER(dirSelector));
	gchar* filename = NULL;

	if(dirname && strlen(dirname)>0)
	{
		if(dirname[strlen(dirname)-1] != G_DIR_SEPARATOR)
			filename = g_strdup_printf("%s%sdump.txt",dirname,G_DIR_SEPARATOR_S);
		else
			filename = g_strdup_printf("%sdump.txt",dirname);
	}
	else
	{
		dirname = g_strdup(g_get_home_dir());
		filename = g_strdup_printf("%s%sdump.txt",dirname,G_DIR_SEPARATOR_S);
	}
	if(dirname) g_free(dirname);
	if(filename)
	{
		set_last_directory(filename);
		g_free(filename);
	}
}
/********************************************************************************/
static void set_directory(GtkWidget *win, gpointer data)
{
	GtkWidget *dirSelector;
	dirSelector = selctionOfDir(reset_last_directory, "Set folder", GABEDIT_TYPEWIN_ORB);
	gtk_window_set_modal (GTK_WINDOW (dirSelector), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(dirSelector),GTK_WINDOW(PrincipalWindow));
	gtk_window_set_transient_for(GTK_WINDOW(dirSelector),GTK_WINDOW(WinDlg));
}
/********************************************************************************/
void initGeometryConvergence()
{
	geometryConvergence.fileName = NULL;
	geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_UNKNOWN;
	geometryConvergence.numberOfGeometries = 0;
	geometryConvergence.numGeometry = NULL;
	geometryConvergence.velocity = 0.1;
	geometryConvergence.energy = NULL;
	geometryConvergence.maxForce = NULL;
	geometryConvergence.rmsForce= NULL;
	geometryConvergence.maxStep = NULL;
	geometryConvergence.rmsStep = NULL;
	geometryConvergence.geometries = NULL;
	geometryConvergence.comments = NULL;
	rowSelected = -1;
}
/********************************************************************************/
void freeGeometryConvergence()
{
	static gboolean begin = TRUE;

	if(begin)
	{
		begin  = FALSE;
		initGeometryConvergence();
		return;
	}
	if(geometryConvergence.fileName) g_free(geometryConvergence.fileName);
	if(geometryConvergence.numGeometry) g_free(geometryConvergence.numGeometry);
	if(geometryConvergence.energy) g_free(geometryConvergence.energy);
	if(geometryConvergence.maxForce) g_free(geometryConvergence.maxForce);
	if(geometryConvergence.rmsForce) g_free(geometryConvergence.rmsForce);
	if(geometryConvergence.maxStep) g_free(geometryConvergence.maxStep);
	if(geometryConvergence.rmsStep) g_free(geometryConvergence.rmsStep);
	if(geometryConvergence.geometries)
	{
		gint i;
		Geometry* geometries = geometryConvergence.geometries;
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
		{
			if(geometries[i].listOfAtoms) g_free(geometries[i].listOfAtoms);
		}
		g_free(geometries);
	}
	if(geometryConvergence.comments)
	{
		gint i;
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(geometryConvergence.comments[i]) g_free(geometryConvergence.comments[i]);
		g_free(geometryConvergence.comments);
	}

	initGeometryConvergence();
}
/********************************************************************************/
static void delete_one_geometry()
{

	gint j;
	gint k = rowSelected;

	if(k<0 || k >= geometryConvergence.numberOfGeometries) return;
	if(!geometryConvergence.geometries) return;
	if(geometryConvergence.numberOfGeometries==1)
	{
		freeGeometryConvergence();
		rafreshList();
		return;
	}

	if(geometryConvergence.geometries)
			if(geometryConvergence.geometries[k].listOfAtoms) g_free(geometryConvergence.geometries[k].listOfAtoms);
	for(j=k;j<geometryConvergence.numberOfGeometries-1;j++)
	{
		if(geometryConvergence.energy) geometryConvergence.energy[j] = geometryConvergence.energy[j+1];
		if(geometryConvergence.maxForce) geometryConvergence.maxForce[j] = geometryConvergence.maxForce[j+1];
		if(geometryConvergence.rmsForce) geometryConvergence.rmsForce[j] = geometryConvergence.rmsForce[j+1];
		if(geometryConvergence.maxStep) geometryConvergence.maxStep[j] = geometryConvergence.maxStep[j+1];
		if(geometryConvergence.rmsStep) geometryConvergence.rmsStep[j] = geometryConvergence.rmsStep[j+1];
		if(geometryConvergence.numGeometry) geometryConvergence.numGeometry[j] = geometryConvergence.numGeometry[j+1];
		if(geometryConvergence.comments) geometryConvergence.comments[j] = geometryConvergence.comments[j+1];
		if(geometryConvergence.geometries)
		{
			geometryConvergence.geometries[j] = geometryConvergence.geometries[j+1];
		}
	}
	geometryConvergence.numberOfGeometries--;
	if(geometryConvergence.energy)
		geometryConvergence.energy = g_realloc(geometryConvergence.energy, geometryConvergence.numberOfGeometries*sizeof(gfloat));
	if(geometryConvergence.maxForce)
		geometryConvergence.maxForce = g_realloc(geometryConvergence.maxForce, geometryConvergence.numberOfGeometries*sizeof(gfloat));
	if(geometryConvergence.rmsForce)
		geometryConvergence.rmsForce = g_realloc(geometryConvergence.rmsForce, geometryConvergence.numberOfGeometries*sizeof(gfloat));
	if(geometryConvergence.maxStep)
		geometryConvergence.maxStep = g_realloc(geometryConvergence.maxStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));
	if(geometryConvergence.rmsStep)
		geometryConvergence.rmsStep = g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));
	if(geometryConvergence.numGeometry)
		geometryConvergence.numGeometry = g_realloc(geometryConvergence.numGeometry, geometryConvergence.numberOfGeometries*sizeof(gint));
	if(geometryConvergence.geometries)
	{
		geometryConvergence.geometries = g_realloc(geometryConvergence.geometries, geometryConvergence.numberOfGeometries*sizeof(Geometry));
	}
	rafreshList();

	return;
}
/*************************************************************************************************************/
static gboolean read_molden_gabedit_file_geomi(gchar *fileName, gint geometryNumber, GabEditTypeFile type, Geometry* geometry)
{
	gchar* t;
	gboolean OK;
	gchar* AtomCoord[5];
	FILE *file;
	gint i;
	gint j;
	gint l;
	gint numgeom;
	gchar *pdest;
	gint nn;
    	Atom* listOfAtoms = NULL;

	file = FOpen(fileName, "r");

	if(file ==NULL)
	{
		t = g_strdup_printf("Sorry\nI can not open %s  file ",fileName);
		Message(t," Error ",TRUE);
		g_free(t);
		return FALSE;
	}
	t = g_malloc(BSIZE*sizeof(gchar));
	for(i=0;i<5;i++) AtomCoord[i] = g_malloc(BSIZE*sizeof(gchar));

	numgeom =0;
	OK=TRUE;
	while(!feof(file))
	{
		if(!fgets(t, BSIZE,file))break;
		pdest = strstr( t, "[GEOMETRIES]");
		if(pdest && strstr(t,"ZMAT"))
		{
			if(type == GABEDIT_TYPEFILE_MOLDEN)
				sprintf(t,"Sorry\nMolden file with ZMAT coordinate is not supported by Gabedit");
			if(type == GABEDIT_TYPEFILE_GABEDIT)
				sprintf(t,"Sorry\nGabedit file with ZMAT coordinate is not supported by Gabedit");

			Message(t," Error ",TRUE);
			g_free(t);
			return FALSE;
		}	
 		if (pdest)
		{
			while(!feof(file))
			{
				if(!fgets(t, BSIZE,file))break;

				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
				if(!isInteger(t))break;
               			numgeom++;
				if(numgeom == geometryNumber)
				{
					nn = atoi(t);
					if(nn<1)break;
    					listOfAtoms = g_malloc(nn*sizeof(Atom));
					if(!fgets(t, BSIZE,file))break; /* title */
					for(j=0; j<nn; j++)
					{
						if(!fgets(t, BSIZE,file))break;
    						sscanf(t,"%s %s %s %s",AtomCoord[0],AtomCoord[1],AtomCoord[2],AtomCoord[3]);
						{
							gint i;
							for(i=0;i<(gint)strlen(AtomCoord[0]);i++) if(isdigit(AtomCoord[0][i])) AtomCoord[0][i] = ' ';
							delete_all_spaces(AtomCoord[0]);
						}
						AtomCoord[0][0]=toupper(AtomCoord[0][0]);
						l=strlen(AtomCoord[0]);
						if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);
    						sprintf(listOfAtoms[j].symbol,"%s",AtomCoord[0]);
    						for(i=0;i<3;i++) listOfAtoms[j].C[i]=atof(AtomCoord[i+1])*ANG_TO_BOHR;
					}
 					geometry->numberOfAtoms = nn;
 					geometry->listOfAtoms = listOfAtoms;
					OK = TRUE;
					break;
				}
				else
				{
					nn = atoi(t);
					if(!fgets(t, BSIZE,file)) break;
					for(i=0; i<nn; i++)
						if(!fgets(t, BSIZE,file))break;
					if(i!=nn) { OK = FALSE; break;}
				}
				if(!OK) break;
			}
		}
		if(!OK) break;
	}

	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(geometry->numberOfAtoms == 0 )
	{
		if(geometry->listOfAtoms) g_free(geometry->listOfAtoms);
	}
	return TRUE;
}
/********************************************************************************/
static gboolean read_dalton_file_geomi(gchar *FileName, gint num, Geometry* geometry)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *file;
 	guint i;
 	gint j=0;
 	gint l;
 	guint numgeom;
	Atom* listOfAtoms = NULL;
	gchar dum[100];
	gint kk;

  
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return FALSE ;
 	}

 	file = FOpen(FileName, "r");
 	if(file ==NULL)
 	{
  		Message("Sorry\nI can not open this file","Error",TRUE);
  		return FALSE;
 	}
 	t=g_malloc(BSIZE);
 	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(BSIZE*sizeof(char));

 	numgeom =1;
 	do 
 	{
 		OK=FALSE;
 		while(!feof(file))
		{
			fgets(t,BSIZE,file);
			/* if (strstr(t,"Next geometry"))*/
			if(strstr(t,"Next geometry") || strstr(t,"Final geometry"))
			{
	  			fgets(t,BSIZE,file);
	  			fgets(t,BSIZE,file);
 				numgeom++;
                		OK = TRUE;
	  			break;
	  		}
        	}
 		if(!OK && (numgeom == 1) )
		{
  			Message("Sorry\nI can not read geometry in this file","Error",TRUE);
 			fclose(file);
 			g_free(t);
 			for(i=0;i<5;i++) g_free(AtomCoord[i]);
			return FALSE;
    		}
 		if(!OK)break;

  		j=-1;
  		while(!feof(file) )
  		{
			fgets(t,BSIZE,file);
			if (!strcmp(t,"\n"))
			{
				break;
			}
    			j++;
    			if(listOfAtoms == NULL) listOfAtoms = g_malloc(sizeof(Atom));
    			else listOfAtoms = g_realloc(listOfAtoms, (j+1)*sizeof(Atom));

			kk = sscanf(t,"%s %s %s %s %s",AtomCoord[0],AtomCoord[1], AtomCoord[2],AtomCoord[3], dum);
			if(kk==5) sscanf(t,"%s %s %s %s %s",AtomCoord[0],dum, AtomCoord[1], AtomCoord[2],AtomCoord[3]);

			for(i=0;i<(gint)strlen(AtomCoord[0]);i++) if(isdigit(AtomCoord[0][i])) AtomCoord[0][i] = ' ';
			delete_all_spaces(AtomCoord[0]);
			AtomCoord[0][0]=toupper(AtomCoord[0][0]);
	 		l=strlen(AtomCoord[0]);
          		if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);


    			sprintf(listOfAtoms[j].symbol,"%s",AtomCoord[0]);
    			for(i=0;i<3;i++) listOfAtoms[j].C[i]=atof((AtomCoord[i+1]));
  		}
		if(num >0 && (gint)numgeom-1 == num) break;
			
 	}while(!feof(file));

 	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(j+1 == 0 && listOfAtoms )
	{
		g_free(listOfAtoms);
	}
 	else
	{
		geometry->numberOfAtoms = j+1;
		geometry->listOfAtoms = listOfAtoms;
	}
	return TRUE;
}
/********************************************************************************/
static gboolean read_gamess_file_geomi(gchar *FileName, gint num, Geometry* geometry)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *file;
 	guint i;
 	gint j=0;
 	gint l;
 	guint numgeom;
	Atom* listOfAtoms = NULL;
	gchar dum[100];

  
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return FALSE ;
 	}

 	file = FOpen(FileName, "r");
 	if(file ==NULL)
 	{
  		Message("Sorry\nI can not open this file","Error",TRUE);
  		return FALSE;
 	}
 	t=g_malloc(BSIZE);
 	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(BSIZE*sizeof(char));

 	numgeom =1;
 	do 
 	{
 		OK=FALSE;
 		while(!feof(file))
		{
			fgets(t,BSIZE,file);
			if(strstr(t,"COORDINATES OF ALL ATOMS ARE (ANGS)"))
			{
	  			fgets(t,BSIZE,file);
	  			fgets(t,BSIZE,file);
 				numgeom++;
                		OK = TRUE;
	  			break;
	  		}
        	}
 		if(!OK && (numgeom == 1) )
		{
  			Message("Sorry\nI can not read geometry in this file","Error",TRUE);
 			fclose(file);
 			g_free(t);
 			for(i=0;i<5;i++) g_free(AtomCoord[i]);
			return FALSE;
    		}
 		if(!OK)break;

  		j=-1;
  		while(!feof(file) )
  		{
			fgets(t,BSIZE,file);
			if (!strcmp(t,"\n"))
			{
				break;
			}
    			j++;
    			if(listOfAtoms == NULL) listOfAtoms = g_malloc(sizeof(Atom));
    			else listOfAtoms = g_realloc(listOfAtoms, (j+1)*sizeof(Atom));

			sscanf(t,"%s %s %s %s %s",AtomCoord[0],dum, AtomCoord[1], AtomCoord[2],AtomCoord[3]);

			for(i=0;i<(gint)strlen(AtomCoord[0]);i++) if(isdigit(AtomCoord[0][i])) AtomCoord[0][i] = ' ';
			delete_all_spaces(AtomCoord[0]);
			AtomCoord[0][0]=toupper(AtomCoord[0][0]);
	 		l=strlen(AtomCoord[0]);
          		if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);


    			sprintf(listOfAtoms[j].symbol,"%s",AtomCoord[0]);
    			for(i=0;i<3;i++) listOfAtoms[j].C[i]=atof((AtomCoord[i+1]))*ANG_TO_BOHR;
  		}
		if(num >0 && (gint)numgeom-1 == num) break;
			
 	}while(!feof(file));

 	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(j+1 == 0 && listOfAtoms )
	{
		g_free(listOfAtoms);
	}
 	else
	{
		geometry->numberOfAtoms = j+1;
		geometry->listOfAtoms = listOfAtoms;
	}
	return TRUE;
}
/********************************************************************************/
static gboolean read_gamess_output(gchar* fileName)
{
	gchar *pdest;
	gint  k=0;
	gchar *maxGrad =  NULL;
	gchar *rmsGrad =  NULL;
	gchar *temp =  NULL;
	gchar *tmp =  NULL;
	gchar *t = NULL;
	FILE *file;
	gboolean OK;
        
	temp = get_name_file(fileName);
	set_status_label_info("File Name",temp);
	g_free(temp);
	set_status_label_info("File Type","Gamess");

 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return FALSE;
	}
	t=g_malloc(BSIZE*sizeof(gchar));
	maxGrad =  g_malloc(50*sizeof(gchar));	
	rmsGrad =  g_malloc(50*sizeof(gchar));	
	temp =  g_malloc(50*sizeof(gchar));	
	tmp =  g_malloc(50*sizeof(gchar));	
        
	OK = TRUE;
	while(!feof(file))
	{
		if(!fgets(t,BSIZE,file)) break;
		pdest = strstr( t,"BEGINNING GEOMETRY SEARCH POINT NSERCH");
   		if( pdest != NULL )
		{
			OK = TRUE;
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
				if(strstr(t,"COORDINATES OF ALL ATOMS ARE (ANGS)"))
				{
		 			if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
		 			if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;

			OK = TRUE;
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
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
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
				if(strstr(t,"MAXIMUM GRADIENT =")&& strstr(t,"RMS GRADIENT ="))
				{
		 			gchar* t1 = strstr(t,"MAXIMUM GRADIENT =");
					if(t1) sscanf(t1+19,"%s",maxGrad); /* maxGrad */
					else { OK = FALSE; break; }
		 			t1 = strstr(t,"RMS GRADIENT =");
					if(t1) sscanf(t1+15,"%s",rmsGrad); /* rmsGrad */
					else { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;
		}
   		if(pdest != NULL)
		{
			geometryConvergence.numberOfGeometries++;
		  	if(geometryConvergence.numberOfGeometries == 1 )
		  	{
				geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_GAMESS;
				geometryConvergence.fileName = g_strdup(fileName);
				geometryConvergence.numGeometry =  g_malloc(sizeof(gint));	
				geometryConvergence.numGeometry[0] =  1;
				geometryConvergence.energy =  g_malloc(sizeof(gfloat));	
				geometryConvergence.energy[0] = atof(tmp);
				geometryConvergence.maxStep =  g_malloc(sizeof(gfloat));	
				geometryConvergence.maxStep[0] = atof(maxGrad);
				geometryConvergence.rmsStep =  g_malloc(sizeof(gfloat));	
				geometryConvergence.rmsStep[0] = atof(rmsGrad);
		  	}
		  	else
		  	{
				geometryConvergence.numGeometry =  
				g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
				k = geometryConvergence.numberOfGeometries-1;
				geometryConvergence.numGeometry[k] =  k+1;
				geometryConvergence.energy =  
				g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.energy[k] = atof(tmp);

				geometryConvergence.maxStep =  g_realloc(geometryConvergence.maxStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.maxStep[k] = atof(maxGrad);
				geometryConvergence.rmsStep =  g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.rmsStep[k] = atof(rmsGrad);
		  	}
			OK = TRUE;
		}
	}
	if(!OK)
	{
		freeGeometryConvergence();
		sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
		Message(t," Error ",TRUE);
		OK = FALSE;
	 }

	fclose(file);
	g_free(t);
	g_free(temp);
	g_free(maxGrad);
	g_free(rmsGrad);
	g_free(tmp);
	if(geometryConvergence.numberOfGeometries>0)
	{
		gint i;
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_gamess_file_geomi(fileName,geometryConvergence.numGeometry[i], &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
  	rafreshList();
	return OK;
}
/*****************************************************************************************************/
static gboolean read_gaussian_file_geomi_str(gchar *FileName, gint num, gchar* str, Geometry* geometry)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *file;
 	guint idummy;
 	guint i;
 	gint j=0;
 	gint l;
 	guint numgeom;
 	gchar *pdest;
 	gint result;
 	guint itype=0;
	Atom* listOfAtoms = NULL;

  
 	file = FOpen(FileName, "r");

	t=g_malloc(BSIZE);
 	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(BSIZE*sizeof(char));

	numgeom =1;
 	do 
 	{
 		OK=FALSE;
 		while(!feof(file))
		{
	  		fgets(t,BSIZE,file);
			pdest = strstr( t,str);
			result = pdest - t ;
	 		if ( result >0 )
	  		{
	  			fgets(t,BSIZE,file);
	  			fgets(t,BSIZE,file);
	  			fgets(t,BSIZE,file);
				pdest = strstr( t, "Type" );
				result = pdest - t ;
				if(result>0) itype=1;
				else itype=0;
	  			fgets(t,BSIZE,file);
                		numgeom++;
				OK = TRUE;
				break;
	  		}
		}
 		if(!OK && (numgeom == 1) )
		{
 			fclose(file);
 			g_free(t);
 			for(i=0;i<5;i++) g_free(AtomCoord[i]);
			return FALSE;
		}
 		if(!OK)break;

  		j=-1;
  		while(!feof(file) )
  		{
    			fgets(t,BSIZE,file);
    			pdest = strstr( t, "----------------------------------" );
    			result = pdest - t ;
    			if ( result >0 )
    			{
      				break;
    			}
    			j++;
    			if(listOfAtoms == NULL) listOfAtoms = g_malloc(sizeof(Atom));
    			else listOfAtoms = g_realloc(listOfAtoms, (j+1)*sizeof(Atom));

    			if(itype==0) sscanf(t,"%d %s %s %s %s",&idummy,AtomCoord[0],AtomCoord[1],AtomCoord[2],AtomCoord[3]);
    			else sscanf(t,"%d %s %d %s %s %s",&idummy,AtomCoord[0],&idummy,AtomCoord[1],AtomCoord[2],AtomCoord[3]);

			AtomCoord[0][0]=toupper(AtomCoord[0][0]);
	 		l=strlen(AtomCoord[0]);
          		if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);

    			sprintf(listOfAtoms[j].symbol,"%s",symb_atom_get((guint)atoi(AtomCoord[0])));
    			for(i=0;i<3;i++) listOfAtoms[j].C[i]=atof(ang_to_bohr(AtomCoord[i+1]));
		}
		if(num >0 && (gint)numgeom-1 == num) break;
 	}while(!feof(file));

 	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);

 	if(j+1 == 0 && listOfAtoms )
	{
		g_free(listOfAtoms);
		listOfAtoms = NULL;
	}
 	else
	{
		geometry->numberOfAtoms = j+1;
		geometry->listOfAtoms = listOfAtoms;
	}
	return TRUE;
}
/********************************************************************************/
static gboolean read_gaussian_file_geomi(gchar *FileName, gint num, Geometry* geometry)
{
	FILE* file;
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return FALSE;
 	}
 	file = FOpen(FileName, "r");
 	if(file ==NULL)
 	{
  		Message("Sorry\nI can not open this file","Error",TRUE);
  		return FALSE;
 	}
	fclose(file);


	if(read_gaussian_file_geomi_str(FileName,num,"Standard orientation:", geometry)) return TRUE;
	if(read_gaussian_file_geomi_str(FileName,num,"Input orientation:", geometry)) return TRUE;
	/* for calculation with nosym option */
	if(!read_gaussian_file_geomi_str(FileName,num,"Z-Matrix orientation:", geometry))
	{
  		Message("Sorry\nI can not read geometry in this file","Error",TRUE);
		return FALSE;
	}
	return TRUE;

}
/********************************************************************************/
static gboolean read_molpro_file_geomi(gchar *FileName, gint num, Geometry* geometry)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *file;
 	guint idummy;
 	guint i;
 	gint j=0;
 	gint l;
 	guint numgeom;
	Atom* listOfAtoms = NULL;

  
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return FALSE ;
 	}

 	file = FOpen(FileName, "r");
 	if(file ==NULL)
 	{
  		Message("Sorry\nI can not open this file","Error",TRUE);
  		return FALSE;
 	}
 	t=g_malloc(BSIZE);
 	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(BSIZE*sizeof(char));

 	numgeom =1;
 	do 
 	{
 		OK=FALSE;
 		while(!feof(file))
		{
			fgets(t,BSIZE,file);
			if ( !strcmp(t," ATOMIC COORDINATES\n"))
			{
	  			fgets(t,BSIZE,file);
	  			fgets(t,BSIZE,file);
				if(strstr(t,"Q_EFF"))continue;
	  			fgets(t,BSIZE,file);
 				numgeom++;
                		OK = TRUE;
	  			break;
	  		}
        	}
 		if(!OK && (numgeom == 1) )
		{
  			Message("Sorry\nI can not read geometry in this file","Error",TRUE);
 			fclose(file);
 			g_free(t);
 			for(i=0;i<5;i++) g_free(AtomCoord[i]);
			return FALSE;
    		}
 		if(!OK)break;

  		j=-1;
  		while(!feof(file) )
  		{
			fgets(t,BSIZE,file);
			if ( !strcmp(t,"\n"))
			{
				break;
			}
    			j++;
    			if(listOfAtoms == NULL) listOfAtoms = g_malloc(sizeof(Atom));
    			else listOfAtoms = g_realloc(listOfAtoms, (j+1)*sizeof(Atom));

			sscanf(t,"%d %s %s %s %s %s",&idummy, AtomCoord[0],AtomCoord[1],AtomCoord[1], AtomCoord[2],AtomCoord[3]);

			for(i=0;i<(gint)strlen(AtomCoord[0]);i++) if(isdigit(AtomCoord[0][i])) AtomCoord[0][i] = ' ';
			delete_all_spaces(AtomCoord[0]);

			AtomCoord[0][0]=toupper(AtomCoord[0][0]);
	 		l=strlen(AtomCoord[0]);
          		if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);

    			sprintf(listOfAtoms[j].symbol,"%s",AtomCoord[0]);
    			for(i=0;i<3;i++) listOfAtoms[j].C[i]=atof((AtomCoord[i+1]));
  		}
		if(num >0 && (gint)numgeom-1 == num) break;
			
 	}while(!feof(file));

 	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(j+1 == 0 && listOfAtoms )
	{
		g_free(listOfAtoms);
	}
 	else
	{
		geometry->numberOfAtoms = j+1;
		geometry->listOfAtoms = listOfAtoms;
	}
	return TRUE;
}
/********************************************************************************/
static gboolean read_mpqc_file_geomi(gchar *fileName,gint numGeometry, Geometry* geometry)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *file;
 	guint idummy;
 	guint i;
 	gint j=0;
 	gint l;
 	guint numGeom;
	gdouble tmpReal;
	Atom* listOfAtoms = NULL;

  
 	file = FOpen(fileName, "r");

 	if(file ==NULL)
 	{
  		Message("Sorry\nI can not open this file","Error",TRUE);
  		return FALSE;
 	}

	t=g_malloc(BSIZE);
 	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(BSIZE*sizeof(char));

	numGeom = 0;
	do 
	{
		gboolean unitOfOutAng = FALSE;
		OK=FALSE;
		while(!feof(file))
		{
			if(!fgets(t,BSIZE,file)) break;
			if (strstr(t,"<Molecule>"))
			{
				gboolean OkUnit = FALSE;
				do{
		 			if(!fgets(t,BSIZE,file))break;
					if(strstr(t,"unit"))
					{
						OkUnit = TRUE;
						if(strstr(t,"angstrom"))unitOfOutAng=TRUE;
						break;
					};
					
				}while(!feof(file));
				if(!OkUnit) break;
				numGeom++;
	       			if((gint)numGeom == numGeometry )
				{
					OK = TRUE;
		 			break;
				}
	       			if(numGeometry<0 )
				{
					OK = TRUE;
		 			break;
				}
			}
	       }
		if(!OK && (numGeom == 0) )
		{
	 		g_free(t);
	 		t = g_strdup_printf("Sorry\nI can read Geometry from %s  file ",fileName);
	 		Message(t," Error ",TRUE);
	 		g_free(t);
			for(i=0;i<5;i++) g_free(AtomCoord[i]);
	 		return FALSE;
		}
		if(!OK) break;
		OK = FALSE;
		while(!feof(file) )
		{
	   		if(!fgets(t,BSIZE,file))break;
			if ( !(strstr(t,"atoms") && strstr(t,"geometry"))) continue;
			OK = TRUE;
			break;
		}
		if(!OK)
		{
	 		g_free(t);
	 		t = g_strdup_printf("Sorry\nI can read Geometry from %s  file ",fileName);
	 		Message(t," Error ",TRUE);
	 		g_free(t);
			for(i=0;i<5;i++) g_free(AtomCoord[i]);
	 		return FALSE;
		}

		j=-1;
		while(!feof(file) )
		{
	   		if(!fgets(t,BSIZE,file))break;
	   		if(strstr(t,"}"))break;
			j++;

    			if(listOfAtoms==NULL) listOfAtoms=g_malloc(sizeof(Atom));
    			else listOfAtoms=g_realloc(listOfAtoms,(j+1)*sizeof(Atom));

			for(i=0;i<strlen(t);i++) if(t[i]=='[' || t[i] ==']') t[i]=' ';
			sscanf(t,"%d %s %s %s %s",&idummy,AtomCoord[0],AtomCoord[1],AtomCoord[2],AtomCoord[3]);
			for(i=1;i<=3;i++)
			{
				tmpReal = atof(AtomCoord[i]);
				sprintf(AtomCoord[i],"%f",tmpReal);
			}

			AtomCoord[0][0]=toupper(AtomCoord[0][0]);

			l=strlen(AtomCoord[0]);

			if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);

    			sprintf(listOfAtoms[j].symbol,"%s",AtomCoord[0]);
    			for(i=0;i<3;i++)
				if(unitOfOutAng)
    					listOfAtoms[j].C[i]=atof(ang_to_bohr(AtomCoord[i+1]));
				else
    					listOfAtoms[j].C[i]=atof(AtomCoord[i+1]);

		}

		if(numGeometry<0) continue;
		if(OK) break;
	}while(!feof(file));

 	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(j+1 == 0 && listOfAtoms )
	{
		g_free(listOfAtoms);
		listOfAtoms = NULL;
	}
 	else
	{
		geometry->numberOfAtoms = j + 1;
		geometry->listOfAtoms = listOfAtoms;
	}
	return TRUE;
}
/*********************************************************************/
static gboolean read_xyz_file_geomi(gchar *fileName, gint geometryNumber, Geometry* geometry)
{
	gchar* t;
	gboolean OK;
	gchar* AtomCoord[5];
	FILE *file;
	gint i;
	gint j;
	gint l;
	gint numgeom;
	gint nn = 0;
	Atom* listOfAtoms = NULL;

	file = FOpen(fileName, "r");

	if(file ==NULL)
	{
		t = g_strdup_printf("Sorry\nI can not open %s  file ",fileName);
		Message(t," Error ",TRUE);
		g_free(t);
		return FALSE;
	}
	t = g_malloc(BSIZE*sizeof(gchar));
	for(i=0;i<5;i++) AtomCoord[i] = g_malloc(BSIZE*sizeof(gchar));

	numgeom =0;
	OK=TRUE;
	while(!feof(file))
	{
		if(!fgets(t, BSIZE,file))break;

		str_delete_n(t);
		delete_last_spaces(t);
		delete_first_spaces(t);
		if(!isInteger(t))break;
		numgeom++;
		if(numgeom == geometryNumber)
		{
			nn = atoi(t);
			if(nn<1)break;
    			listOfAtoms=g_malloc(nn*sizeof(Atom));
			if(!fgets(t, BSIZE,file))break; /* title */
			for(j=0; j<nn; j++)
			{
				if(!fgets(t, BSIZE,file))break;
    				sscanf(t,"%s %s %s %s",AtomCoord[0],AtomCoord[1],AtomCoord[2],AtomCoord[3]);
				AtomCoord[0][0]=toupper(AtomCoord[0][0]);
				l=strlen(AtomCoord[0]);
				if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);
    				sprintf(listOfAtoms[j].symbol,"%s",AtomCoord[0]);
    				for(i=0;i<3;i++) listOfAtoms[j].C[i]=atof(AtomCoord[i+1])*ANG_TO_BOHR;
			}
			OK = TRUE;
			break;
		}
		else
		{
			nn = atoi(t);
			if(!fgets(t, BSIZE,file)) break;
			for(i=0; i<nn; i++)
				if(!fgets(t, BSIZE,file))break;
			if(i!=nn) { OK = FALSE; break;}
		}
		if(!OK) break;
	}

	fclose(file);
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(nn == 0 )
	{
		if(listOfAtoms) g_free(listOfAtoms);
		listOfAtoms = NULL;
	}
 	else
	{
		geometry->numberOfAtoms = nn;
		geometry->listOfAtoms = listOfAtoms;
	}

	return TRUE;
}
/********************************************************************************/
static gboolean save_geometry_convergence_gabedit_format(gchar *FileName)
{
 	FILE *file;
	gint j;
	gboolean OK = TRUE;

 	file = FOpen(FileName, "w");
	if(file == NULL)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I  can not create '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}
	fprintf(file,"[Gabedit Format]\n");
	fprintf(file,"\n");
	fprintf(file,"[GEOCONV]\n");
	if(geometryConvergence.energy)
	{
		fprintf(file," energy\n");
		for(j=0;j<geometryConvergence.numberOfGeometries;j++)
			fprintf(file," %f\n", geometryConvergence.energy[j]);
	}
	else
	{
		fprintf(file," energy\n");
		for(j=0;j<geometryConvergence.numberOfGeometries;j++) fprintf(file," %f\n",j+1.0);
	}
	if(geometryConvergence.maxForce)
	{
		fprintf(file," max-force\n");
		for(j=0;j<geometryConvergence.numberOfGeometries;j++)
			fprintf(file," %f\n", geometryConvergence.maxForce[j]);
	}
	if(geometryConvergence.rmsForce)
	{
		fprintf(file," rms-force\n");
		for(j=0;j<geometryConvergence.numberOfGeometries;j++)
			fprintf(file," %f\n", geometryConvergence.rmsForce[j]);
	}
	if(geometryConvergence.maxStep)
	{
		fprintf(file," max-step\n");
		for(j=0;j<geometryConvergence.numberOfGeometries;j++)
			fprintf(file," %f\n", geometryConvergence.maxStep[j]);
	}
	if(geometryConvergence.rmsStep)
	{
		fprintf(file," rms-step\n");
		for(j=0;j<geometryConvergence.numberOfGeometries;j++)
			fprintf(file," %f\n", geometryConvergence.rmsStep[j]);
	}
	fprintf(file,"\n");
	if(!geometryConvergence.numGeometry) { fclose(file); return FALSE;}
	fprintf(file,"[GEOMETRIES]\n");
	for(j=0;j<geometryConvergence.numberOfGeometries;j++)
	{
		gint i;
		gint nAtoms = geometryConvergence.geometries[j].numberOfAtoms;
		Atom* listOfAtoms = geometryConvergence.geometries[j].listOfAtoms;
		if(nAtoms<1 || !listOfAtoms) { OK = FALSE; break;}
		fprintf(file," %d\n", nAtoms);
		fprintf(file," All coordinates are in Angshtrom\n");
		for(i=0;i<nAtoms;i++)
		{
			fprintf(file," %s %f %f %f\n", 
				listOfAtoms[i].symbol,
				listOfAtoms[i].C[0]*BOHR_TO_ANG,
				listOfAtoms[i].C[1]*BOHR_TO_ANG,
				listOfAtoms[i].C[2]*BOHR_TO_ANG
				);
		}
	}
	fclose(file);
	return OK;
}
/********************************************************************************/
static void reset_parameters(GtkWidget *win, gpointer data)
{
	gdouble velo = atof(gtk_entry_get_text(GTK_ENTRY(EntryVelocity)));
	gchar* t;

	if(velo<0)
	{

		velo = -velo;
		t = g_strdup_printf("%f",velo);
		gtk_entry_set_text(GTK_ENTRY(EntryVelocity),t);
		g_free(t);
	}

	geometryConvergence.velocity = velo;
	if(!play) stopAnimation(NULL,NULL);

}
/********************************************************************************/
static gboolean read_gabedit_molden_rms_conv(FILE* file)
{
 	gchar* t = g_malloc(BSIZE*sizeof(gchar));
	gboolean OK = FALSE;
	gint i;

	fseek(file, 0L, SEEK_SET);
	OK = FALSE;
 	while(!feof(file))
	{
		if(!fgets(t, BSIZE,file)) break;
		if(strstr(t,"[GEOCONV]")) { OK = TRUE; break;}
	}
	if(!OK)
	{
		g_free(t);
		return FALSE;
	}
 	while(!feof(file))
	{
		if(!fgets(t, BSIZE,file)) break;
		g_strup(t);
   		if( strstr( t,"ENERGY") != NULL )
		{
			geometryConvergence.energy = g_malloc(geometryConvergence.numberOfGeometries*sizeof(gfloat));
			for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			{
		 		if(!fgets(t,BSIZE,file)) break;
				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
		 		if(!isFloat(t)) break;
				geometryConvergence.energy[i] = atof(t);
			}
			if(i!=geometryConvergence.numberOfGeometries)
			{
				g_free(geometryConvergence.energy);
				geometryConvergence.energy = NULL;
			}
		}
   		if( strstr( t,"MAX-FORCE") != NULL )
		{
			geometryConvergence.maxForce = g_malloc(geometryConvergence.numberOfGeometries*sizeof(gfloat));
			for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			{
		 		if(!fgets(t,BSIZE,file)) break;
				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
		 		if(!isFloat(t)) break;
				geometryConvergence.maxForce[i] = atof(t);
			}
			if(i!=geometryConvergence.numberOfGeometries)
			{
				g_free(geometryConvergence.maxForce);
				geometryConvergence.maxForce = NULL;
			}
		}
   		if( strstr( t,"RMS-FORCE") != NULL )
		{
			geometryConvergence.rmsForce = g_malloc(geometryConvergence.numberOfGeometries*sizeof(gfloat));
			for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			{
		 		if(!fgets(t,BSIZE,file)) break;
				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
		 		if(!isFloat(t)) break;
				geometryConvergence.rmsForce[i] = atof(t);
			}
			if(i!=geometryConvergence.numberOfGeometries)
			{
				g_free(geometryConvergence.rmsForce);
				geometryConvergence.rmsForce = NULL;
			}
		}
   		if( strstr( t,"MAX-STEP") != NULL )
		{
			geometryConvergence.maxStep = g_malloc(geometryConvergence.numberOfGeometries*sizeof(gfloat));
			for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			{
		 		if(!fgets(t,BSIZE,file)) break;
				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
		 		if(!isFloat(t)) break;
				geometryConvergence.maxStep[i] = atof(t);
			}
			if(i!=geometryConvergence.numberOfGeometries)
			{
				g_free(geometryConvergence.maxStep);
				geometryConvergence.maxStep = NULL;
			}
		}
   		if( strstr( t,"RMS-STEP") != NULL )
		{
			geometryConvergence.rmsStep = g_malloc(geometryConvergence.numberOfGeometries*sizeof(gfloat));
			for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			{
		 		if(!fgets(t,BSIZE,file)) break;
				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
		 		if(!isFloat(t)) break;
				geometryConvergence.rmsStep[i] = atof(t);
			}
			if(i!=geometryConvergence.numberOfGeometries)
			{
				g_free(geometryConvergence.rmsStep);
				geometryConvergence.rmsStep = NULL;
			}
		}
   		if( strstr( t,"[GEOMETRIES]") != NULL ) break;
	}
	return TRUE;

}
/********************************************************************************/
static gboolean read_gabedit_molden_geom_conv(gchar *fileName, GabEditTypeFile type)
{
 	gchar* t;
 	gchar* tmp;
 	gchar* sdum;
 	gchar* pdest;
 	gfloat fdum1, fdum2, fdum3;
 	gboolean OK;
 	FILE *file;
	gint i;
	gint ne;
	gint numgeom = 0;

	tmp = get_name_file(fileName);
	set_status_label_info("File Name",tmp);
	g_free(tmp);
	if(type== GABEDIT_TYPEFILE_GABEDIT) set_status_label_info("File Type","Gabedit");
	if(type== GABEDIT_TYPEFILE_MOLDEN) set_status_label_info("File Type","Molden");

 	file = FOpen(fileName, "r");
	t = g_malloc(BSIZE*sizeof(gchar));
	if(file ==NULL)
	{
		sprintf(t,"Sorry\nI can not open %s  file ",fileName);
		Message(t," Error ",TRUE);
		g_free(t);
		return FALSE;
	}
	sdum = g_malloc(BSIZE*sizeof(gchar));
	numgeom =0;
	OK=TRUE;
	while(!feof(file))
	{
		if(!fgets(t, BSIZE,file))break;
		pdest = strstr( t, "[GEOMETRIES]");
		if(pdest && strstr(t,"ZMAT"))
		{
			if(type == GABEDIT_TYPEFILE_MOLDEN) sprintf(t,"Sorry\nMolden file with ZMAT coordinate is not supported by Gabedit");
			if(type == GABEDIT_TYPEFILE_GABEDIT) sprintf(t,"Sorry\nGabedit file with ZMAT coordinate is not supported by Gabedit");
			Message(t," Error ",TRUE);
			return FALSE;
		}	
 		if (pdest)
		{
			while(!feof(file))
			{
				if(!fgets(t,BSIZE,file))break;
				str_delete_n(t);
				delete_last_spaces(t);
				delete_first_spaces(t);
				if(!isInteger(t))break;
               			numgeom++;
				OK = TRUE;
				if(numgeom==1)
				{
					geometryConvergence.fileName = g_strdup(fileName);
					geometryConvergence.typeOfFile = type;
					geometryConvergence.numberOfGeometries = 1;
					geometryConvergence.numGeometry = g_malloc(sizeof(gint));
					geometryConvergence.numGeometry[0] = 1;
				}
				else
				{
					geometryConvergence.numberOfGeometries = numgeom;
					geometryConvergence.numGeometry = 
						g_realloc(geometryConvergence.numGeometry, geometryConvergence.numberOfGeometries*sizeof(gint));
					geometryConvergence.numGeometry[numgeom-1] = numgeom;
				}
				ne = atoi(t);
				if(!fgets(t,BSIZE,file)) break;
				for(i=0; i<ne; i++)
				{
					if(!fgets(t,BSIZE,file))break;
					if(sscanf(t,"%s %f %f %f",sdum, &fdum1, &fdum2, &fdum3)!=4) break;
				}
				if(i!=ne) { OK = FALSE;break;}
			}
			if(!OK) break;
		}
	}
	/* energy and rms and max */
	if(OK)
	{
		OK = read_gabedit_molden_rms_conv(file);
			
		if(!geometryConvergence.energy)
		{
			freeGeometryConvergence();
			sprintf(t,"Sorry\nI can not read energy from %s file ",fileName);
			Message(t," Error ",TRUE);
			OK = FALSE;
		}
	}

	fclose(file);
 	g_free(t);
 	g_free(sdum);
	if(!OK) freeGeometryConvergence();
	if(geometryConvergence.numberOfGeometries>0)
	{
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_molden_gabedit_file_geomi(fileName,geometryConvergence.numGeometry[i], geometryConvergence.typeOfFile, &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
	rafreshList();


	return TRUE;
}
/********************************************************************************/
static gboolean read_dalton_output(gchar* fileName)
{
	gchar *pdest;
	gint  k=0;
	gchar *temp =  NULL;
	gchar *tmp =  NULL;
	gchar *t = NULL;
	FILE *file;
	gboolean OK;
        
	temp = get_name_file(fileName);
	set_status_label_info("File Name",temp);
	g_free(temp);
	set_status_label_info("File Type","Dalton");

 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return FALSE;
	}
	t=g_malloc(BSIZE*sizeof(gchar));
	temp =  g_malloc(50*sizeof(char));	
	tmp =  g_malloc(50*sizeof(char));	
        
	OK = TRUE;
	while(!feof(file))
	{
		if(!fgets(t,BSIZE,file)) break;
		pdest = strstr( t,"Optimization Control Center");
   		if( pdest != NULL )
		{
			OK = TRUE;
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
				if(strstr(t,"Next geometry") || strstr(t,"Final geometry"))
				{
		 			if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
		 			if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;

			OK = TRUE;
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
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
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break; }
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
		}
   		if(pdest != NULL)
		{
			geometryConvergence.numberOfGeometries++;
		  	if(geometryConvergence.numberOfGeometries == 1 )
		  	{
				geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_DALTON;
				geometryConvergence.fileName = g_strdup(fileName);
				geometryConvergence.numGeometry =  g_malloc(sizeof(gint));	
				geometryConvergence.numGeometry[0] =  1;
				geometryConvergence.energy =  g_malloc(sizeof(gfloat));	
				geometryConvergence.energy[0] = atof(tmp);
				geometryConvergence.rmsStep =  g_malloc(sizeof(gfloat));	
				geometryConvergence.rmsStep[0] = atof(temp);
		  	}
		  	else
		  	{
				geometryConvergence.numGeometry =  
				g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
				k = geometryConvergence.numberOfGeometries-1;
				geometryConvergence.numGeometry[k] =  k+1;
				geometryConvergence.energy =  
				g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.energy[k] = atof(tmp);

				geometryConvergence.rmsStep =  g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.rmsStep[k] = atof(temp);
		  	}
			OK = TRUE;
		}
	}
	if(!OK)
	{
		freeGeometryConvergence();
		sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
		Message(t," Error ",TRUE);
		OK = FALSE;
	 }

	fclose(file);
	g_free(t);
	g_free(temp);
	g_free(tmp);
	if(geometryConvergence.numberOfGeometries>0)
	{
		gint i;
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_dalton_file_geomi(fileName,geometryConvergence.numGeometry[i], &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
  	rafreshList();
	return OK;
}
/********************************************************************************/
static gboolean read_gaussian_output(gchar* fileName)
{
	gchar *pdest;
	gint  k=0;
	gchar *temp =  NULL;
	gchar *t = NULL;
	FILE *file;
	gint nE = 0;
	gint nSF = 0;
	gboolean OK;
        
	temp = get_name_file(fileName);
	set_status_label_info("File Name",temp);
	g_free(temp);
	set_status_label_info("File Type","Gaussian output");

 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return FALSE;
	}
	t=g_malloc(BSIZE*sizeof(gchar));
	temp =  g_malloc(50*sizeof(char));	
        
	OK = TRUE;
	while(!feof(file))
	{
		if(!fgets(t,BSIZE,file)) break;
		g_strup(t);
    		pdest = strstr( t,"SCF DONE");
   		if( pdest != NULL ) pdest = strstr( t,"=");
         	if(!pdest)
		{
    		 	pdest = strstr( t,"ENERGY=");
          	 	if(pdest && t[1] == 'E' ) pdest = strstr( t,"=");
			else pdest = NULL;
		}
   		if(pdest != NULL)
		{
			pdest++;
			geometryConvergence.numberOfGeometries++;
			nE++;
		  	if(geometryConvergence.numberOfGeometries == 1 )
		  	{
				geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_GAUSSIAN;
				geometryConvergence.fileName = g_strdup(fileName);
				geometryConvergence.numGeometry =  g_malloc(sizeof(gint));	
				geometryConvergence.numGeometry[0] =  1;
				geometryConvergence.energy =  g_malloc(sizeof(gfloat));	
				geometryConvergence.energy[0] = atof(pdest);
				geometryConvergence.maxForce =  g_malloc(sizeof(gfloat));	
				geometryConvergence.rmsForce =  g_malloc(sizeof(gfloat));	
				geometryConvergence.maxStep =  g_malloc(sizeof(gfloat));	
				geometryConvergence.rmsStep =  g_malloc(sizeof(gfloat));	
		  	}
		  	else
		  	{
				geometryConvergence.numGeometry =  
				g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
				k = geometryConvergence.numberOfGeometries-1;
				geometryConvergence.numGeometry[k] =  k+1;
				geometryConvergence.energy =  
				g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.energy[k] = atof(pdest);

				geometryConvergence.maxForce =  g_realloc(geometryConvergence.maxForce,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.rmsForce =  g_realloc(geometryConvergence.rmsForce, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.maxStep =  g_realloc(geometryConvergence.maxStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.rmsStep =  g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
		  	}
		}
                pdest = NULL;
    		pdest = strstr( t,"CONVERGED?");
                if( pdest != NULL && geometryConvergence.numberOfGeometries>0)
		{
			nSF++;
			if(nSF != nE)
			{
				OK = FALSE;
				break;
			}
			k = geometryConvergence.numberOfGeometries-1;
		 	fgets(t,BSIZE,file);
                 	sscanf(t,"%s %s %f", temp,temp,&geometryConvergence.maxForce[k]);
		 	fgets(t,BSIZE,file);
                 	sscanf(t,"%s %s %f", temp,temp,&geometryConvergence.rmsForce[k]);
		 	fgets(t,BSIZE,file);
                 	sscanf(t,"%s %s %f", temp,temp,&geometryConvergence.maxStep[k]);
		 	fgets(t,BSIZE,file);
                 	sscanf(t,"%s %s %f", temp,temp,&geometryConvergence.rmsStep[k]);
		}
	}
	if(!OK)
	{
		freeGeometryConvergence();
		sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
		Message(t," Error ",TRUE);
		OK = FALSE;
	 }
	if(nSF<nE)
	{
		if(nSF>0)
		{
			geometryConvergence.numberOfGeometries = nSF;
			geometryConvergence.numGeometry =  
			g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
			geometryConvergence.energy =  
			g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
			geometryConvergence.maxForce =  g_realloc(geometryConvergence.maxForce,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
			geometryConvergence.rmsForce =  g_realloc(geometryConvergence.rmsForce, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
			geometryConvergence.maxStep =  g_realloc(geometryConvergence.maxStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.rmsStep =  g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	

		}
		else
		{
			freeGeometryConvergence();
			sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
			Message(t," Error ",TRUE);
			OK = FALSE;
		}

	}
	fclose(file);
	g_free(t);
	g_free(temp);
	if(geometryConvergence.numberOfGeometries>0)
	{
		gint i;
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_gaussian_file_geomi(fileName,geometryConvergence.numGeometry[i], &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
  	rafreshList();
	return OK;
}
/********************************************************************************/
static gboolean read_molpro_log(gchar* fileName)
{
	gchar *pdest;
	gint  k=0;
	gchar *temp =  NULL;
	gchar *tmp =  NULL;
	gchar *t = NULL;
	FILE *file;
	gint nE = 0;
	gint nSF = 0;
	gboolean OK;
        
	temp = get_name_file(fileName);
	set_status_label_info("File Name",temp);
	g_free(temp);
	set_status_label_info("File Type","Molpro log");

 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return FALSE;
	}
	t=g_malloc(BSIZE*sizeof(gchar));
	temp =  g_malloc(50*sizeof(char));	
	tmp =  g_malloc(50*sizeof(char));	
        
	OK = TRUE;
	while(!feof(file))
	{
		if(!fgets(t,BSIZE,file)) break;
		pdest = strstr( t,"Optimization point");
   		if( pdest != NULL )
		{
			OK = TRUE;
			while(!feof(file) && OK )
			{
		 		if(!fgets(t, BSIZE,file))
				{
					OK = FALSE;
					break;
				}
				if(strstr(t,"(") && strstr(t,")"))
				{
					OK = TRUE;
					break;
				}
		 	}
		 	if(!OK) break;
		}
   		if(pdest != NULL)
		{
                 	sscanf(t,"%s %s %s %s %s",temp,temp,temp,temp,tmp);
			geometryConvergence.numberOfGeometries++;
			nE++;
		  	if(geometryConvergence.numberOfGeometries == 1 )
		  	{
				geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_MOLPRO_LOG;
				geometryConvergence.fileName = g_strdup(fileName);
				geometryConvergence.numGeometry =  g_malloc(sizeof(gint));	
				geometryConvergence.numGeometry[0] =  1;
				geometryConvergence.energy =  g_malloc(sizeof(gfloat));	
				geometryConvergence.energy[0] = atof(tmp);
				geometryConvergence.rmsStep =  g_malloc(sizeof(gfloat));	
		  	}
		  	else
		  	{
				geometryConvergence.numGeometry =  
				g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
				k = geometryConvergence.numberOfGeometries-1;
				geometryConvergence.numGeometry[k] =  k+1;
				geometryConvergence.energy =  
				g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.energy[k] = atof(tmp);

				geometryConvergence.rmsStep =  g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
		  	}
			OK = TRUE;
                 	do
                 	{
		 		if(!fgets(t, BSIZE,file)) { OK = FALSE; break;}
                 	}while(strstr(t,"Convergence:")==NULL && !feof(file) ) ;
			if(!OK) break;
                 	if(strstr(t,"Convergence:")!=NULL)
			{
				nSF++;
				k = geometryConvergence.numberOfGeometries-1;
                 		sscanf(t,"%s %s %s %s %s ", temp,temp,temp,temp,tmp);
                 		geometryConvergence.rmsStep[k] = atof(tmp);
			}
		}
	}
	if(!OK)
	{
		freeGeometryConvergence();
		sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
		Message(t," Error ",TRUE);
		OK = FALSE;
	 }
	if(nSF<nE)
	{
		if(nSF>0)
		{
			geometryConvergence.numberOfGeometries = nSF;
			geometryConvergence.numGeometry =  
			g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
			geometryConvergence.energy =  
			g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
			geometryConvergence.rmsStep =  g_realloc(geometryConvergence.rmsStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	

		}
		else
		{
			freeGeometryConvergence();
			sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
			Message(t," Error ",TRUE);
			OK = FALSE;
		}

	}

	fclose(file);
	g_free(t);
	g_free(temp);
	g_free(tmp);
	if(geometryConvergence.numberOfGeometries>0)
	{
		gint i;
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_molpro_file_geomi(fileName,geometryConvergence.numGeometry[i], &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
  	rafreshList();
	return OK;
}
/********************************************************************************/
static gboolean read_mpqc_output(gchar* fileName)
{
	gchar *pdest;
	gint  k=0;
	gchar *temp =  NULL;
	gchar *t = NULL;
	FILE *file;
	gint nE = 0;
	gint nSF = 0;
	gboolean OK;
	gboolean newGeom;
	gboolean mp2;
        
	temp = get_name_file(fileName);
	set_status_label_info("File Name",temp);
	g_free(temp);
	set_status_label_info("File Type","MPQC output");

 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return FALSE;
	}
	t=g_malloc(BSIZE*sizeof(gchar));
	temp =  g_malloc(50*sizeof(char));	
        
	OK = TRUE;
	mp2 = FALSE;
	newGeom = FALSE;
	while(!feof(file))
	{
		if(!fgets(t,BSIZE,file)) break;
                 if(strstr(t,"changing atomic coordinates:"))
		 {
			newGeom = TRUE;
			if(strstr(t,"MBPT2")) mp2 = TRUE;
		 }
		 pdest = NULL;
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
   		if(pdest != NULL)
		{
			pdest++;
			geometryConvergence.numberOfGeometries++;
			nE++;
		  	if(geometryConvergence.numberOfGeometries == 1 )
		  	{
				geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_MPQC;
				geometryConvergence.fileName = g_strdup(fileName);
				geometryConvergence.numGeometry =  g_malloc(sizeof(gint));	
				geometryConvergence.numGeometry[0] =  1;
				geometryConvergence.energy =  g_malloc(sizeof(gfloat));	
				geometryConvergence.energy[0] = atof(pdest);
				geometryConvergence.maxStep =  g_malloc(sizeof(gfloat));	
		  	}
		  	else
		  	{
				geometryConvergence.numGeometry =  
				g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
				k = geometryConvergence.numberOfGeometries-1;
				geometryConvergence.numGeometry[k] =  k+1;
				geometryConvergence.energy =  
				g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
				geometryConvergence.energy[k] = atof(pdest);

				geometryConvergence.maxStep =  g_realloc(geometryConvergence.maxStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	
		  	}
		}
                pdest = NULL;
    		pdest = strstr( t,"Max Displacement");
                if( pdest != NULL && geometryConvergence.numberOfGeometries>0)
		{
    		 	pdest = strstr( t,":");
			if(pdest)
			{
				pdest++;
				nSF++;
				k = geometryConvergence.numberOfGeometries-1;
                 		sscanf(pdest,"%f",&geometryConvergence.maxStep[k]);
			}
		 }
	}
	if(!OK)
	{
		freeGeometryConvergence();
		sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
		Message(t," Error ",TRUE);
		OK = FALSE;
	 }
	if(nSF<nE)
	{
		if(nSF>0)
		{
			geometryConvergence.numberOfGeometries = nSF;
			geometryConvergence.numGeometry =  
			g_realloc(geometryConvergence.numGeometry,geometryConvergence.numberOfGeometries*sizeof(gint));	
			geometryConvergence.energy =  
			g_realloc(geometryConvergence.energy,geometryConvergence.numberOfGeometries*sizeof(gfloat));	
			geometryConvergence.maxStep =  g_realloc(geometryConvergence.maxStep, geometryConvergence.numberOfGeometries*sizeof(gfloat));	

		}
		else
		{
			freeGeometryConvergence();
			sprintf(t,"Sorry\nI can not read energy or convergence parameters from %s file ",fileName);
			Message(t," Error ",TRUE);
			OK = FALSE;
		}

	}

	fclose(file);
	g_free(t);
	g_free(temp);
	if(geometryConvergence.numberOfGeometries>0)
	{
		gint i;
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_mpqc_file_geomi(fileName,geometryConvergence.numGeometry[i], &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
  	rafreshList();
	return OK;
}
/********************************************************************************/
static gboolean read_xyz_multi(gchar* fileName)
{
	gint  i=0;
	gchar *t = NULL;
	FILE *file;
	gint nGeom = 0;
	gboolean OK;
	gchar *sdum = NULL;
	gfloat fdum1;
	gfloat fdum2;
	gfloat fdum3;
	gint ne;
	gint nAtoms;
	gchar** comments = NULL;
        
	t = get_name_file(fileName);
	set_status_label_info("File Name",t);
	if(t) g_free(t);
	set_status_label_info("File Type","XYZ");

 	file = FOpen(fileName, "r"); 
        if(!file)
	{
		t = g_strdup_printf(" Error : I can not open file %s\n",fileName);
		Message(t," Error ",TRUE);
		if(t) g_free(t);
		return FALSE;
	}
	t=g_malloc(BSIZE*sizeof(gchar));
	sdum =  g_malloc(50*sizeof(gchar));	
        
	OK = TRUE;
	while(!feof(file))
	{
		if(!fgets(t,BSIZE,file))break;
		ne = sscanf(t,"%d",&nAtoms);
		if(ne==1 && nAtoms>0)
		 {
		 	if(!fgets(t, BSIZE,file)) break; /* title */
			str_delete_n(t);
			delete_last_spaces(t);
			delete_first_spaces(t);
			if(comments==NULL) comments = g_malloc(sizeof(gchar*));
			else comments = g_realloc(comments, (nGeom+1)*sizeof(gchar*));
			comments[nGeom] = g_strdup(t);
			for(i=0;i<nAtoms;i++)
			{
				if(!fgets(t, BSIZE,file)) { OK = FALSE; break;};
				ne = sscanf(t,"%s %f %f %f",sdum,&fdum1, &fdum2, &fdum3);
				if(ne != 4) { OK = FALSE; break;};
			}
			if(!OK) break;
			nGeom++;
		 }
		else break;
	}
	if(OK && nGeom>0)
	{
		geometryConvergence.numberOfGeometries = nGeom;
		geometryConvergence.typeOfFile = GABEDIT_TYPEFILE_XYZ;
		geometryConvergence.fileName = g_strdup(fileName);
		geometryConvergence.numGeometry =  g_malloc(nGeom*sizeof(gint));
		geometryConvergence.comments =  comments;
		for(i=0;i<nGeom;i++) geometryConvergence.numGeometry[i] =  i+1;
	}
	else
	{
		sprintf(t,"Sorry\nI can not read geometries from %s file ",fileName);
		Message(t," Error ",TRUE);
		OK = FALSE;
		if(comments) g_free(comments);
	 }

	fclose(file);
	g_free(t);
	g_free(sdum);
	if(geometryConvergence.numberOfGeometries>0)
	{
		gint i;
		geometryConvergence.geometries = g_malloc(geometryConvergence.numberOfGeometries*sizeof(Geometry));
		for(i=0;i<geometryConvergence.numberOfGeometries;i++)
			if(!read_xyz_file_geomi(fileName,geometryConvergence.numGeometry[i], &geometryConvergence.geometries[i])) break;
		if(i!=geometryConvergence.numberOfGeometries)
		{
			freeGeometryConvergence();
			OK = FALSE;
		}
	}
  	rafreshList();
	return OK;
}
/********************************************************************************/
static void read_gabedit_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_gabedit_molden_geom_conv(FileName, GABEDIT_TYPEFILE_GABEDIT);
}
/********************************************************************************/
static void read_molden_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_gabedit_molden_geom_conv(FileName, GABEDIT_TYPEFILE_MOLDEN);
}
/********************************************************************************/
static void read_dalton_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_dalton_output(FileName);
}
/********************************************************************************/
static void read_gamess_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_gamess_output(FileName);
}
/********************************************************************************/
static void read_gaussian_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_gaussian_output(FileName);
}
/********************************************************************************/
static void read_molpro_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_molpro_log(FileName);
}
/********************************************************************************/
static void read_mpqc_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_mpqc_output(FileName);
}
/********************************************************************************/
static void read_xyz_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stopAnimation(NULL, NULL);

	freeGeometryConvergence();
  	rafreshList();
	read_xyz_multi(FileName);
}
/********************************************************************************/
static void read_gabedit_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_gabedit_file,
			"Read geometries from a Gabedit file",
			GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_molden_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_molden_file, "Read geometries from a Molden file", GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_dalton_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_dalton_file, "Read geometries from a Dalton output file", GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_gamess_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_gamess_file, "Read geometries from a Gamess output file", GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_gaussian_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_gaussian_file, "Read geometries from a Gaussian output file", GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_molpro_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_molpro_file, "Read geometries from a Molpro log file", GABEDIT_TYPEFILE_MOLPRO_LOG,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_mpqc_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_mpqc_file, "Read geometries from a MPQC output file", GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_xyz_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_xyz_file, "Read geometries from a XYZ file", GABEDIT_TYPEFILE_XYZ,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void save_gabedit_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	save_geometry_convergence_gabedit_format(FileName);
}
/********************************************************************************/
static gboolean set_geometry(gint k)
{
	Atom* listOfAtoms = NULL;
	gint nAtoms = 0;
	gint j;

	if(k<0 || k >= geometryConvergence.numberOfGeometries) return FALSE;

	if(GeomOrb)
	{
		free_atomic_orbitals();
		for(j=0;j<Ncenters;j++) if(GeomOrb[j].Symb) g_free(GeomOrb[j].Symb);
		g_free(GeomOrb);
		GeomOrb = NULL;
	}
	nAtoms = geometryConvergence.geometries[k].numberOfAtoms;
	listOfAtoms = geometryConvergence.geometries[k].listOfAtoms;

	GeomOrb=g_malloc(nAtoms*sizeof(TypeGeomOrb));
	for(j=0;j<nAtoms;j++)
	{
    		GeomOrb[j].Symb=g_strdup(listOfAtoms[j].symbol);
    		GeomOrb[j].C[0] = listOfAtoms[j].C[0];
    		GeomOrb[j].C[1] = listOfAtoms[j].C[1];
    		GeomOrb[j].C[2] = listOfAtoms[j].C[2];
  		GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
		GeomOrb[j].Prop.covalentRadii *=1.0;
	}
	Ncenters = nAtoms;
	init_atomic_orbitals();
	Dipole.def = FALSE;
	RebuildGeom = TRUE;
	glarea_rafresh(GLArea);

	return TRUE;
}
/********************************************************************************/
static void save_gabedit_file_dlg()
{
	GtkWidget* filesel;
	if(geometryConvergence.numberOfGeometries<1)
	{
		return;
	}
 	filesel = file_chooser_save(save_gabedit_file,
			"Save geometry convergences in gabedit file format",
			GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void playAnimation(GtkWidget *win, gpointer data)
{
	play = TRUE;
	gtk_widget_set_sensitive(PlayButton, FALSE); 
	gtk_widget_set_sensitive(StopButton, TRUE); 
	gtk_window_set_modal (GTK_WINDOW (WinDlg), TRUE);
	animate();

}
/********************************************************************************/
static void stopAnimation(GtkWidget *win, gpointer data)
{
	play = FALSE;
	if(GTK_IS_WIDGET(PlayButton)) gtk_widget_set_sensitive(PlayButton, TRUE); 
	if(GTK_IS_WIDGET(StopButton)) gtk_widget_set_sensitive(StopButton, FALSE); 
	if(GTK_IS_WIDGET(WinDlg)) gtk_window_set_modal (GTK_WINDOW (WinDlg), FALSE);
	while( gtk_events_pending() ) gtk_main_iteration();

	RebuildGeom = TRUE;
	Dipole.def = FALSE;
	init_atomic_orbitals();
	free_iso_all();
	if(this_is_an_object((GtkObject*)GLArea)) glarea_rafresh(GLArea);
}
/********************************************************************************/
static void destroyDlg(GtkWidget *win)
{
	createFilm = FALSE;
	numFileFilm = 0;

	delete_child(WinDlg);
	freeGeometryConvergence();
}
/********************************************************************************/
static void destroyAnimGeomConvDlg(GtkWidget *win)
{
	createFilm = FALSE;
	numFileFilm = 0;
	stopAnimation(NULL, NULL);
	gtk_widget_destroy(WinDlg);
	WinDlg = NULL;
	rowSelected = -1;
	freeGeometryConvergence();

}
/**********************************************************************************/
static void set_sensitive_option(GtkUIManager *manager, gchar* path)
{
	GtkWidget *wid = gtk_ui_manager_get_widget (manager, path);
	gboolean sensitive = TRUE;
  	if(geometryConvergence.numberOfGeometries<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(wid)) gtk_widget_set_sensitive(wid, sensitive);
}
/**********************************************************************************/
static gboolean show_menu_popup(GtkUIManager *manager, guint button, guint32 time)
{
	GtkWidget *menu = gtk_ui_manager_get_widget (manager, "/MenuGeomConv");
	if (GTK_IS_MENU (menu)) 
	{
		set_sensitive_option(manager,"/MenuGeomConv/SaveGabedit");
		set_sensitive_option(manager,"/MenuGeomConv/DeleteGeometry");
		gtk_menu_popup (GTK_MENU (menu), NULL, NULL, NULL, NULL, button, time);
		return TRUE;
	}
	else printf("Erreur menu n'est pas un menu\n");
	return FALSE;
}
/**********************************************************************************/
static void event_dispatcher(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{

	GtkTreePath *path;
	gint row = -1;
	if (event->window == gtk_tree_view_get_bin_window (GTK_TREE_VIEW (widget))
	    && !gtk_tree_view_get_path_at_pos (GTK_TREE_VIEW (widget),
					       event->x, event->y, NULL, NULL, NULL, NULL)) {
		gtk_tree_selection_unselect_all (gtk_tree_view_get_selection (GTK_TREE_VIEW (widget)));
	}
	if(gtk_tree_view_get_path_at_pos (GTK_TREE_VIEW (widget), event->x, event->y, &path, NULL, NULL, NULL))
	{
		if(path)
		{
			gtk_tree_selection_select_path  (gtk_tree_view_get_selection (GTK_TREE_VIEW (widget)), path);
			row = atoi(gtk_tree_path_to_string(path));
			gtk_tree_path_free(path);
		}
	}

	rowSelected = row;
	if(!play) stopAnimation(NULL, NULL);
	if(row>=0) set_geometry(rowSelected);

  	if (event->type == GDK_BUTTON_PRESS && ((GdkEventButton *) event)->button == 3)
	{
		GdkEventButton *bevent = (GdkEventButton *) event;
		GtkUIManager *manager = GTK_UI_MANAGER(user_data);
		show_menu_popup(manager, bevent->button, bevent->time);
	}
}
/**********************************************************************************/
static void rafreshList()
{
	gint i;
	gint k;
        GtkTreeIter iter;
	GtkTreeModel *model = NULL;
        GtkTreeStore *store = NULL;
	gchar *texts[7];
	gboolean visible[7] = { TRUE, TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
	gchar* titles[]={"Energy","MAX step","RMS step", "MAX Force","RMS Force","Number of Geometry","Comments"};
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;

	model = gtk_tree_view_get_model(treeView);
        store = GTK_TREE_STORE (model);
	gtk_tree_store_clear(store);
        model = GTK_TREE_MODEL (store);

	if(geometryConvergence.numberOfGeometries>0)
	{
		if(!geometryConvergence.energy)   { visible[0] = FALSE;}
		if(!geometryConvergence.maxStep)  { visible[1] = FALSE;}
		if(!geometryConvergence.rmsStep)  { visible[2] = FALSE;}
		if(!geometryConvergence.maxForce) { visible[3] = FALSE;}
		if(!geometryConvergence.rmsForce) { visible[4] = FALSE;}
		if(!geometryConvergence.numGeometry) { visible[5] = FALSE;}
		if(!geometryConvergence.comments) { visible[6] = FALSE;}
	}
	else
	{
		for(i=0;i<7;i++) visible[i] = FALSE;
	}


	if(!visible[0]) visible[5] = TRUE;
	else visible[5] = FALSE;

	do
	{
		column = gtk_tree_view_get_column(treeView, 0);
		if(column) gtk_tree_view_remove_column(treeView, column);
	}while(column != NULL);

	for(k=0;k<7;k++)
	{
		if(!visible[k]) continue;
		column = gtk_tree_view_column_new ();
		gtk_tree_view_column_set_title (column, titles[k]);
		gtk_tree_view_column_set_reorderable(column, TRUE);
		gtk_tree_view_column_set_resizable(column,TRUE);
		renderer = gtk_cell_renderer_text_new ();
		gtk_tree_view_column_pack_start (column, renderer, TRUE);
		gtk_tree_view_column_set_attributes (column, renderer, "text", k, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeView), column);
	}

  
	for(i=0;i<geometryConvergence.numberOfGeometries;i++)
	{
		if(visible[0]) texts[0] = g_strdup_printf("%f",geometryConvergence.energy[i]);
		if(visible[1]) texts[1] = g_strdup_printf("%f",geometryConvergence.maxStep[i]);
		if(visible[2]) texts[2] = g_strdup_printf("%f",geometryConvergence.rmsStep[i]);
		if(visible[3]) texts[3] = g_strdup_printf("%f",geometryConvergence.maxForce[i]);
		if(visible[4]) texts[4] = g_strdup_printf("%f",geometryConvergence.rmsForce[i]);
		if(visible[5]) texts[5] = g_strdup_printf("%d",geometryConvergence.numGeometry[i]);
		if(visible[6]) texts[6] = g_strdup_printf("%s",geometryConvergence.comments[i]);
        	gtk_tree_store_append (store, &iter, NULL);
		for(k=0;k<7;k++)
		{
			if(visible[k])
			{
				gtk_tree_store_set (store, &iter, k, texts[k], -1);
				g_free(texts[k]);
			}
		}
	}

	if(geometryConvergence.numberOfGeometries>0)
	{
		GtkTreePath *path;
		rowSelected = 0;
		path = gtk_tree_path_new_from_string  ("0");
		gtk_tree_selection_select_path  (gtk_tree_view_get_selection (GTK_TREE_VIEW (treeView)), path);
		gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW (treeView), path, NULL, FALSE,0.5,0.5);
		gtk_tree_path_free(path);
		set_geometry(rowSelected);
	}
	
	reset_parameters(NULL,NULL);
}
/*****************************************************************************/
static gchar* get_format_image_from_option()
{
	if(strcmp(formatFilm,"BMP")==0) return "bmp";
	if(strcmp(formatFilm,"PPM")==0) return "ppm";
	if(strcmp(formatFilm,"PNG")==0) return "png";
	if(strcmp(formatFilm,"JPEG")==0) return "jpg";
	if(strcmp(formatFilm,"PNG transparent")==0) return "png";
	if(strcmp(formatFilm,"Povray")==0) return "pov";
	return "UNK";
}
/********************************************************************************/
static void filmSelected(GtkWidget *widget)
{
	if(GTK_IS_WIDGET(buttonCheckFilm)&& GTK_TOGGLE_BUTTON (buttonCheckFilm)->active)
	{
		createFilm = TRUE;
		if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, TRUE);
		if(GTK_IS_WIDGET(comboListFilm))  gtk_widget_set_sensitive(comboListFilm, TRUE);
	}
	else
	{
		createFilm = FALSE;
		if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);
		if(GTK_IS_WIDGET(comboListFilm))  gtk_widget_set_sensitive(comboListFilm, FALSE);
	}
}
/********************************************************************************/
static void showMessageEnd()
{
	gchar* format =get_format_image_from_option();
	gchar* message = messageAnimatedImage(format);
	gchar* t = g_strdup_printf("\nA series of gab*.%s files was created in \"%s\" directeory.\n\n\n%s" , format, get_last_directory(),message);
	GtkWidget* winDlg = Message(t,"Info",TRUE);
	g_free(message);
	gtk_window_set_modal (GTK_WINDOW (winDlg), TRUE);
	g_free(t);
}
/********************************************************************************/
static void unActivateFilm()
{
	createFilm = FALSE;
	numFileFilm = 0;
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonCheckFilm), FALSE);
	if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);
	if(GTK_IS_WIDGET(comboListFilm))  gtk_widget_set_sensitive(comboListFilm, FALSE);
}
/********************************************************************************************************/
static void set_format_film(GtkComboBox *combobox, gpointer d)
{
	GtkTreeIter iter;
	gchar* data = NULL;
	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		gtk_tree_model_get (model, &iter, 0, &data, -1);
	}
	if(!data) return;
	sprintf(formatFilm ,"%s",(gchar*)data);
}
/********************************************************************************************************/
static GtkWidget *create_list_of_formats()
{
        GtkTreeIter iter;
        GtkListStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;
	gint i;
	gint k;
	gchar* options[] = {"BMP","PPM", "JPEG", "PNG", "PNG transparent", "Povray"};
	guint numberOfElements = G_N_ELEMENTS (options);


	k = 0;
	store = gtk_list_store_new (1,G_TYPE_STRING);
	for(i=0;i<numberOfElements; i++)
	{
        	gtk_list_store_append (store, &iter);
        	gtk_list_store_set (store, &iter, 0, options[i], -1);
		if(strcmp(options[i],formatFilm)==0) k = i;
	}

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	g_object_unref (model);
	g_signal_connect (G_OBJECT(combobox), "changed", G_CALLBACK(set_format_film), NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);
  	gtk_combo_box_set_active(GTK_COMBO_BOX (combobox), k);
	return combobox;
}
/********************************************************************************************************/
static void addEntrysButtons(GtkWidget* box)
{
	GtkWidget *Button;
	GtkWidget *frame;
	GtkWidget *vboxframe;
	GtkWidget *table;
	gchar t[BSIZE];
	gint i;
	GtkWidget *separator;
	GtkWidget* formatBox;

	frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 10);
	gtk_box_pack_start_defaults(GTK_BOX(box), frame);
	gtk_widget_show (frame);

	vboxframe = create_vbox(frame);

  	table = gtk_table_new(5,3,FALSE);
	gtk_box_pack_start_defaults(GTK_BOX(vboxframe), table);

	i = 0;
	add_label_table(table," Time step(s) ",(gushort)i,0);
	add_label_table(table," : ",(gushort)i,1); 
	EntryVelocity = gtk_entry_new();
	gtk_table_attach(GTK_TABLE(table),EntryVelocity,2,2+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	gtk_editable_set_editable((GtkEditable*) EntryVelocity,TRUE);
	sprintf(t,"%f",geometryConvergence.velocity);
	gtk_entry_set_text(GTK_ENTRY(EntryVelocity),t);

	i++;
	separator = gtk_hseparator_new();
	gtk_table_attach(GTK_TABLE(table),separator,0,3,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);

  	table = gtk_table_new(2,3,FALSE);
	gtk_box_pack_start_defaults(GTK_BOX(vboxframe), table);

	i=0;
	buttonCheckFilm = gtk_check_button_new_with_label ("Create a film");
	createFilm = FALSE;
	numFileFilm = 0;
	gtk_table_attach(GTK_TABLE(table),buttonCheckFilm,0,1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
  	g_signal_connect (G_OBJECT(buttonCheckFilm), "toggled", GTK_SIGNAL_FUNC (filmSelected), NULL);  

	formatBox = create_list_of_formats();
	gtk_table_attach(GTK_TABLE(table),formatBox,1,1+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);

	buttonDirFilm = create_button(WinDlg,"Folder");
	gtk_table_attach(GTK_TABLE(table),buttonDirFilm,2,2+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  1,1);
  	g_signal_connect(G_OBJECT(buttonDirFilm), "clicked",(GtkSignalFunc)set_directory,NULL);
	comboListFilm = formatBox;

	if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);
	if(GTK_IS_WIDGET(comboListFilm))  gtk_widget_set_sensitive(comboListFilm, FALSE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonCheckFilm), FALSE);


	i++;
	separator = gtk_hseparator_new();
	gtk_table_attach(GTK_TABLE(table),separator,0,2,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);



  	table = gtk_table_new(1,2,TRUE);
	gtk_box_pack_start (GTK_BOX (vboxframe), table, TRUE, TRUE, 0);
	i=0;
	Button = create_button(WinDlg,"Play");
	gtk_table_attach(GTK_TABLE(table),Button,0,0+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	PlayButton = Button;

	Button = create_button(WinDlg,"Stop");
	gtk_table_attach(GTK_TABLE(table),Button,1,1+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	StopButton = Button;

  	g_signal_connect(G_OBJECT(PlayButton), "clicked",(GtkSignalFunc)playAnimation,NULL);
  	g_signal_connect(G_OBJECT(StopButton), "clicked",(GtkSignalFunc)stopAnimation,NULL);
  	g_signal_connect_swapped(G_OBJECT (EntryVelocity), "activate", (GtkSignalFunc)reset_parameters, NULL);
}
/********************************************************************************/
static GtkTreeView* addList(GtkWidget *vbox, GtkUIManager *manager)
{
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkCellRenderer *renderer;
	GtkTreeView *treeView;
	GtkTreeViewColumn *column;
	GtkWidget *scr;
	gint i;
	gint widall=0;
	gint widths[]={10,10,10,10,10,10,10};
	gchar* titles[]={"Energy","MAX step","RMS step", "MAX Force","RMS Force","Number of Geometry","Comments"};
	gint Factor=7;
	gint len = 7;


	for(i=0;i<len;i++) widall+=widths[i];

	widall=widall*Factor+40;

	scr=gtk_scrolled_window_new(NULL,NULL);
	gtk_widget_set_size_request(scr,widall,(gint)(ScreenHeight*0.53));
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scr),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC); 
	gtk_box_pack_start(GTK_BOX (vbox), scr,TRUE, TRUE, 2);

	store = gtk_tree_store_new (7,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,  G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
        model = GTK_TREE_MODEL (store);

	treeView = (GtkTreeView*)gtk_tree_view_new_with_model (model);
	gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeView), TRUE);
	gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (treeView), TRUE);
  	gtk_container_add(GTK_CONTAINER(scr),GTK_WIDGET(treeView));


	for (i=0;i<len;i++)
	{
		column = gtk_tree_view_column_new ();
		gtk_tree_view_column_set_title (column, titles[i]);
		gtk_tree_view_column_set_min_width(column, widths[i]*Factor);
		gtk_tree_view_column_set_reorderable(column, TRUE);
		gtk_tree_view_column_set_sizing (column, GTK_TREE_VIEW_COLUMN_GROW_ONLY);
		gtk_tree_view_column_set_resizable(column,TRUE);
		renderer = gtk_cell_renderer_text_new ();
		gtk_tree_view_column_pack_start (column, renderer, TRUE);
		gtk_tree_view_column_set_attributes (column, renderer, "text", i, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeView), column);
	}

	gtk_tree_view_set_reorderable(treeView, TRUE);
	set_base_style(GTK_WIDGET(treeView), 55000,55000,55000);
	gtk_widget_show (GTK_WIDGET(treeView));
  	g_signal_connect(G_OBJECT (treeView), "button_press_event", GTK_SIGNAL_FUNC(event_dispatcher), manager);      
	return treeView;
}
/*****************************************************************************/
static gboolean createImagesFile()
{
	gchar* message = NULL;
	gchar* t;
	gchar* format;
	if(!createFilm)
	{
		setTextInProgress(" ");
		return FALSE;
	}
	format =get_format_image_from_option();
	t = g_strdup_printf("The %s%sgab%d.%s file was created", get_last_directory(),G_DIR_SEPARATOR_S,numFileFilm, format);

	if(!strcmp(formatFilm,"BMP")) message = new_bmp(get_last_directory(), ++numFileFilm);
	if(!strcmp(formatFilm,"PPM")) message = new_ppm(get_last_directory(), ++numFileFilm);
	if(!strcmp(formatFilm,"JPEG")) message = new_jpeg(get_last_directory(), ++numFileFilm);
	if(!strcmp(formatFilm,"PNG")) message = new_png(get_last_directory(), ++numFileFilm);
	if(!strcmp(formatFilm,"Povray")) message = new_pov(get_last_directory(), ++numFileFilm);
	if(!strcmp(formatFilm,"PNG transparent")) message = new_png_nobackground(get_last_directory(), ++numFileFilm);

	if(message == NULL) setTextInProgress(t);
	else
	{
    		GtkWidget* m;
		createFilm = FALSE;
		numFileFilm = 0;
    		m = Message(message,"Error",TRUE);
		gtk_window_set_modal (GTK_WINDOW (m), TRUE);
	}
	g_free(t);
	return TRUE;
}
/********************************************************************************/
static void animate()
{

	gint m = -1;
	gint step = +1;
	GtkTreePath *path;
	gchar* t;


	reset_parameters(NULL, NULL);

	numFileFilm = 0;

	if(GTK_IS_WIDGET(buttonCheckFilm)) gtk_widget_set_sensitive(buttonCheckFilm, FALSE);
	if(GTK_IS_WIDGET(comboListFilm)) gtk_widget_set_sensitive(comboListFilm, FALSE);
	if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);


  	if(GTK_IS_WIDGET(WinDlg))
	{
		GtkWidget* handelbox = g_object_get_data(G_OBJECT (WinDlg), "HandelBox");
		if(GTK_IS_WIDGET(handelbox))  gtk_widget_set_sensitive(handelbox, FALSE);
	}
	if(GTK_IS_WIDGET(treeView))gtk_widget_set_sensitive(GTK_WIDGET(treeView), FALSE);

	if(GeomOrb) free_atomic_orbitals();
	if(geometryConvergence.numberOfGeometries<1) play = FALSE;

	while(play)
	{
		while( gtk_events_pending() ) gtk_main_iteration();

		m += step;
		if(m>=geometryConvergence.numberOfGeometries)
		{
			m--;
			step = -1;
			continue;
		}
		if(m<0)
		{
			m++;
			step = +1;
			continue;
		}
		if(m==0 && step<0)
		{
			if(numFileFilm>0) showMessageEnd();
			unActivateFilm();
		}
		rowSelected = m;
		t = g_strdup_printf("%d",m);
		path = gtk_tree_path_new_from_string  (t);
		g_free(t);
		gtk_tree_selection_select_path  (gtk_tree_view_get_selection (GTK_TREE_VIEW (treeView)), path);
		gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW (treeView), path, NULL, FALSE,0.5,0.5);
		gtk_tree_path_free(path);
		set_geometry(rowSelected);

		createImagesFile();
		Waiting(geometryConvergence.velocity);
	}
	if(numFileFilm>0) showMessageEnd();
	unActivateFilm();

	if(GTK_IS_WIDGET(buttonCheckFilm)) gtk_widget_set_sensitive(buttonCheckFilm, TRUE);
	if(GTK_IS_WIDGET(comboListFilm)) gtk_widget_set_sensitive(comboListFilm, FALSE);
	if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);

	if(GTK_IS_WIDGET(treeView))gtk_widget_set_sensitive(GTK_WIDGET(treeView), TRUE);
  	if(GTK_IS_WIDGET(WinDlg))
	{
		GtkWidget* handelbox = g_object_get_data(G_OBJECT (WinDlg), "HandelBox");
		if(GTK_IS_WIDGET(handelbox))  gtk_widget_set_sensitive(handelbox, TRUE);
	}
	stopAnimation(NULL, NULL);
}
/********************************************************************************************/
static void help_supported_format()
{
	gchar temp[BSIZE];
	GtkWidget* win;
	sprintf(temp,
		" You can read more geometries from :\n"
	        "     * a Gabedit input file.\n"
	        "     * a Dalton output file.\n"
	        "     * a Gaussian output file.\n"
	        "     * a Molpro log file.\n"
	        "     * a MPQC output file.\n"
	        "     * a Molden input file.\n"
	        "     * a XYZ file.\n"
		 );
	win = Message(temp," Info ",FALSE);
	gtk_window_set_modal (GTK_WINDOW (win), TRUE);
}
/***************************************************************************/
static void help_animated_file()
{
	GtkWidget* win;
	gchar* temp = NULL;
	temp = g_strdup(
		" For create an animated file :\n"
		" ============================\n"
	        "   1) Read geometries from a Dalton, Gaussian, Molpro, Gabedit, Molden, MPQC or from XYZ file.\n"
	        "   2) Select \"create a series of BMP (or PPM or POV) images\" button.\n"
	        "      You can select your favorite directory by clicking to \"Directory\" button.\n"
	        "   3) Click to Play button.\n"
	        "   4) After on cycle Gabedit create a series of BMP(gab*.bmp) or PPM (gab*.ppm)  or POV(gab*.pov) files.\n"
	        "      From these files, you can create a gif or a png animated file using convert software.\n"
	        "              with \"convert -delay 10 -loop 1000 gab*.bmp imageAnim.gif\" command you can create a gif animated file.\n"
	        "              with \"convert -delay 10 -loop 1000 gab*.bmp imageAnim.mng\" command you can create a png animated file.\n\n"
	        "         For gab*.pov files :\n"
	        "            You must initially create files gab*.bmp using gab*.pov files.\n"
	        "            Then you can create the animated file using gab*.bmp file.\n\n"
	        "            You can use the xPovAnim script (from utils/povray directory) for create the gif animated file from gab*.pov files.\n\n"
	        "            convert is a free software. You can download this(for any system) from http://www.imagemagick.org\n"
	        "            povray is a free software. You can download this(for any system) from http://www.povray.org\n\n"
		 );
	win = Message(temp," Info ",FALSE);
	gtk_window_set_modal (GTK_WINDOW (win), TRUE);
	g_free(temp);
}
/*********************************************************************************************************************/
static void activate_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	/* const gchar *typename = G_OBJECT_TYPE_NAME (action);*/

	if(!strcmp(name, "File"))
	{
		GtkUIManager *manager = g_object_get_data(G_OBJECT(action), "Manager");
		if(GTK_IS_UI_MANAGER(manager)) set_sensitive_option(manager,"/MenuBar/File/SaveGabedit");
		if(GTK_IS_UI_MANAGER(manager)) set_sensitive_option(manager,"/MenuBar/File/DeleteGeometry");
	}
	else if(!strcmp(name, "ReadGabedit")) read_gabedit_file_dlg();
	else if(!strcmp(name, "ReadDalton")) read_dalton_file_dlg();
	else if(!strcmp(name, "ReadGamess")) read_gamess_file_dlg();
	else if(!strcmp(name, "ReadGaussian")) read_gaussian_file_dlg();
	else if(!strcmp(name, "ReadMolpro")) read_molpro_file_dlg();
	else if(!strcmp(name, "ReadMPQC")) read_mpqc_file_dlg();
	else if(!strcmp(name, "ReadMolden")) read_molden_file_dlg();
	else if(!strcmp(name, "ReadXYZ")) read_xyz_file_dlg();
	else if(!strcmp(name, "SaveGabedit")) save_gabedit_file_dlg();
	else if(!strcmp(name, "DeleteGeometry")) delete_one_geometry();
	else if(!strcmp(name, "Close")) destroyDlg(NULL);
	else if(!strcmp(name, "HelpSupportedFormat")) help_supported_format();
	else if(!strcmp(name, "HelpAnimation")) help_animated_file();
}
/*--------------------------------------------------------------------*/
static GtkActionEntry gtkActionEntries[] =
{
	{"File",     NULL, "_File", NULL, NULL, G_CALLBACK (activate_action)},
	{"Read",     NULL, "_Read"},
	{"ReadGabedit", GABEDIT_STOCK_GABEDIT, "Read a G_abedit file", NULL, "Read a Gabedit file", G_CALLBACK (activate_action) },
	{"ReadDalton", GABEDIT_STOCK_DALTON, "Read a _Dalton output file", NULL, "Read a Dalton output file", G_CALLBACK (activate_action) },
	{"ReadGamess", GABEDIT_STOCK_GAMESS, "Read a _Gamess output file", NULL, "Read a Gamess output file", G_CALLBACK (activate_action) },
	{"ReadGaussian", GABEDIT_STOCK_GAUSSIAN, "Read a _Gaussian output file", NULL, "Read a Gaussian output file", G_CALLBACK (activate_action) },
	{"ReadMolpro", GABEDIT_STOCK_MOLPRO, "Read a Mol_pro output file", NULL, "Read Molpro output file", G_CALLBACK (activate_action) },
	{"ReadMPQC", GABEDIT_STOCK_MPQC, "Read a MP_QC output file", NULL, "Read a MPQC output file", G_CALLBACK (activate_action) },
	{"ReadMolden", GABEDIT_STOCK_MOLDEN, "Read a Mol_den output file", NULL, "Read a Molden file", G_CALLBACK (activate_action) },
	{"ReadXYZ", NULL, "Read a _xyz file", NULL, "Read a xyz file", G_CALLBACK (activate_action) },
	{"SaveGabedit", GABEDIT_STOCK_SAVE, "_Save", NULL, "Save", G_CALLBACK (activate_action) },
	{"DeleteGeometry", GABEDIT_STOCK_CUT, "_Delete selected geometry", NULL, "Delete selected geometry", G_CALLBACK (activate_action) },
	{"Close", GABEDIT_STOCK_CLOSE, "_Close", NULL, "Close", G_CALLBACK (activate_action) },
	{"Help",     NULL, "_Help"},
	{"HelpSupportedFormat", NULL, "_Supported format...", NULL, "Supported format...", G_CALLBACK (activate_action) },
	{"HelpAnimation", NULL, "Creation of an _animated file...", NULL, "Creation of an animated file...", G_CALLBACK (activate_action) },
};
static guint numberOfGtkActionEntries = G_N_ELEMENTS (gtkActionEntries);
/********************************************************************************/
/* XML description of the menus for the test app.  The parser understands
 * a subset of the Bonobo UI XML format, and uses GMarkup for parsing */
static const gchar *uiMenuInfo =
"  <popup name=\"MenuGeomConv\">\n"
"    <separator name=\"sepMenuPopGabedit\" />\n"
"    <menuitem name=\"ReadGabedit\" action=\"ReadGabedit\" />\n"
"    <menuitem name=\"ReadDalton\" action=\"ReadDalton\" />\n"
"    <menuitem name=\"ReadGamess\" action=\"ReadGamess\" />\n"
"    <menuitem name=\"ReadGaussian\" action=\"ReadGaussian\" />\n"
"    <menuitem name=\"ReadMolpro\" action=\"ReadMolpro\" />\n"
"    <menuitem name=\"ReadMPQC\" action=\"ReadMPQC\" />\n"
"    <menuitem name=\"ReadMolden\" action=\"ReadMolden\" />\n"
"    <menuitem name=\"ReadXYZ\" action=\"ReadXYZ\" />\n"
"    <separator name=\"sepMenuPopSave\" />\n"
"    <menuitem name=\"SaveGabedit\" action=\"SaveGabedit\" />\n"
"    <separator name=\"sepMenuDelete\" />\n"
"    <menuitem name=\"DeleteGeometry\" action=\"DeleteGeometry\" />\n"
"    <separator name=\"sepMenuPopClose\" />\n"
"    <menuitem name=\"Close\" action=\"Close\" />\n"
"  </popup>\n"
"  <menubar name = \"MenuBar\">\n"
"    <menu name=\"File\" action=\"File\">\n"
"      <menu name=\"Read\" action=\"Read\">\n"
"        <menuitem name=\"ReadGabedit\" action=\"ReadGabedit\" />\n"
"        <menuitem name=\"ReadDalton\" action=\"ReadDalton\" />\n"
"        <menuitem name=\"ReadGamess\" action=\"ReadGamess\" />\n"
"        <menuitem name=\"ReadGaussian\" action=\"ReadGaussian\" />\n"
"        <menuitem name=\"ReadMolpro\" action=\"ReadMolpro\" />\n"
"        <menuitem name=\"ReadMPQC\" action=\"ReadMPQC\" />\n"
"        <menuitem name=\"ReadMolden\" action=\"ReadMolden\" />\n"
"        <menuitem name=\"ReadXYZ\" action=\"ReadXYZ\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuSave\" />\n"
"      <menuitem name=\"SaveGabedit\" action=\"SaveGabedit\" />\n"
"      <separator name=\"sepMenuDelete\" />\n"
"      <menuitem name=\"DeleteGeometry\" action=\"DeleteGeometry\" />\n"
"      <separator name=\"sepMenuClose\" />\n"
"      <menuitem name=\"Close\" action=\"Close\" />\n"
"    </menu>\n"
"      <menu name=\"Help\" action=\"Help\">\n"
"         <menuitem name=\"HelpSupportedFormat\" action=\"HelpSupportedFormat\" />\n"
"      <separator name=\"sepMenuHelpAnimation\" />\n"
"         <menuitem name=\"HelpAnimation\" action=\"HelpAnimation\" />\n"
"      </menu>\n"
"  </menubar>\n"
;
/*******************************************************************************************************************************/
static void add_widget (GtkUIManager *manager, GtkWidget   *widget, GtkContainer *container)
{
	GtkWidget *handlebox;

	handlebox =gtk_handle_box_new ();
	gtk_widget_ref (handlebox);
  	gtk_handle_box_set_handle_position  (GTK_HANDLE_BOX(handlebox),GTK_POS_LEFT);
	/*   GTK_SHADOW_NONE,  GTK_SHADOW_IN,  GTK_SHADOW_OUT, GTK_SHADOW_ETCHED_IN, GTK_SHADOW_ETCHED_OUT */
	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(handlebox),GTK_SHADOW_OUT);
	gtk_box_pack_start (GTK_BOX (container), handlebox, TRUE, TRUE, 0);

	gtk_widget_show (widget);
	gtk_container_add (GTK_CONTAINER (handlebox), widget);
	gtk_widget_show (handlebox);
}
/*******************************************************************************************************************************/
static GtkUIManager *create_menu(GtkWidget* box)
{
	GtkActionGroup *actionGroup = NULL;
	GtkUIManager *manager = NULL;
	GError *error = NULL;

  	manager = gtk_ui_manager_new ();
  	g_signal_connect_swapped (PrincipalWindow, "destroy", G_CALLBACK (g_object_unref), manager);

	actionGroup = gtk_action_group_new ("GabeditAnimationGeomConvActions");
	gtk_action_group_add_actions (actionGroup, gtkActionEntries, numberOfGtkActionEntries, NULL);

  	gtk_ui_manager_insert_action_group (manager, actionGroup, 0);

	g_signal_connect (manager, "add_widget", G_CALLBACK (add_widget), box);
  	gtk_window_add_accel_group (GTK_WINDOW (PrincipalWindow), gtk_ui_manager_get_accel_group (manager));
	if (!gtk_ui_manager_add_ui_from_string (manager, uiMenuInfo, -1, &error))
	{
		g_message ("building menus failed: %s", error->message);
		g_error_free (error);
	}
	if(GTK_IS_UI_MANAGER(manager))
	{
		GtkAction     *action = NULL;
		action = gtk_ui_manager_get_action(manager, "/MenuBar/File");
		if(G_IS_OBJECT(action)) g_object_set_data(G_OBJECT(action), "Manager", manager);
	}
	return manager;
}
/********************************************************************************/
void geometryConvergenceDlg()
{
	GtkWidget *Win;
	GtkWidget *vbox;
	GtkWidget *hbox;
	GtkWidget *parentWindow = PrincipalWindow;
	GtkUIManager *manager = NULL;

	if(WinDlg) return;

	initGeometryConvergence();

	Win= gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(parentWindow));
	gtk_window_set_default_size (GTK_WINDOW(Win),-1,(gint)(ScreenHeight*0.69));
	gtk_window_set_title(GTK_WINDOW(Win),"Geometry convergence");
	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	WinDlg = Win;

  	add_child(PrincipalWindow,Win,destroyAnimGeomConvDlg,"Geom. Conv.");
  	g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)delete_child,NULL);

	vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox);
	gtk_container_add (GTK_CONTAINER (Win), vbox);

	hbox = create_hbox_false(vbox);
	manager = create_menu(hbox);

	hbox = create_hbox_false(vbox);
	gtk_widget_realize(Win);

	treeView = addList(hbox, manager);
	addEntrysButtons(vbox);
	gtk_widget_show_all(vbox);

	gtk_widget_show_now(Win);

	fit_windows_position(PrincipalWindow, Win);

  	rafreshList();
	stopAnimation(NULL, NULL);
}
