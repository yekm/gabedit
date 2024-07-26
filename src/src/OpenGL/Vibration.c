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
#include <stdlib.h>
#include "GlobalOrb.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "../Utils/UtilsInterface.h"
#include "../OpenGL/StatusOrb.h"
#include "../OpenGL/GLArea.h"
#include "../OpenGL/Vibration.h"
#include "../OpenGL/GeomOrbXYZ.h"
#include "../OpenGL/AtomicOrbitals.h"
#include "../Files/FileChooser.h"
#include "../Geometry/GeomGlobal.h"
#include "../Curve/VibSpectrum.h"
#include "../Files/FolderChooser.h"
#include "../Files/GabeditFolderChooser.h"
#include "../Common/Help.h"
#include "../Common/StockIcons.h"
#include "../OpenGL/Images.h"
#include "../OpenGL/PovrayGL.h"

static	GtkWidget *WinDlg = NULL;
static	GtkWidget *EntryScal = NULL;
static	GtkWidget *EntryVelocity = NULL;
static	GtkWidget *EntryRadius = NULL;
static	GtkWidget *EntryNSteps = NULL;
static	GtkWidget *LabelNSteps = NULL;
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


/********************************************************************************/
static void animate_vibration();
static void rafreshList();
static void stop_vibration(GtkWidget *win, gpointer data);
static void play_vibration(GtkWidget *win, gpointer data);
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
void init_vibration()
{
	vibration.numberOfAtoms = 0;
	vibration.geometry = NULL;
	vibration.numberOfFrequences = 0;
	vibration.modes = NULL;
	vibration.scal = 0.5;
	vibration.velocity = 0.1;
	vibration.radius = 0.1;
	vibration.nSteps = 4;
	rowSelected = -1;
	ShowVibration = FALSE;
}
/********************************************************************************/
void free_vibration()
{
	gint i;
	gint j;

	if(vibration.geometry)
	{
		for(i=0;i<vibration.numberOfAtoms;i++)
			if(vibration.geometry[i].symbol)
				g_free(vibration.geometry[i].symbol);

		g_free(vibration.geometry);
	}
	if(vibration.modes)
	{
		for(i=0;i<vibration.numberOfFrequences;i++)
		{
			if(vibration.modes[i].symmetry)
				g_free(vibration.modes[i].symmetry);

			for(j=0;j<3;j++)
			if(vibration.modes[i].vectors[j])
				g_free(vibration.modes[i].vectors[j]);
		}

		g_free(vibration.modes);
	}
	init_vibration();
}
/********************************************************************************/
void sort_vibration()
{
	gint i;
	gint j;
	gint k;
	VibrationMode mode;

	if(!vibration.geometry) return;
	if(!vibration.modes) return;
	for(i=0;i<vibration.numberOfFrequences-1;i++)
	{
		k = i;
		for(j=i+1;j<vibration.numberOfFrequences;j++)
			if(vibration.modes[j].frequence<vibration.modes[k].frequence) k = j;
		if(k!=i)
		{
			mode = vibration.modes[i];
			vibration.modes[i] = vibration.modes[k];
			vibration.modes[k] = mode;
		}
	}
}
/********************************************************************************/
static gboolean save_vibration_gabedit_format(gchar *FileName)
{
 	FILE *fd;
	gint j;
	gint i;

 	fd = FOpen(FileName, "w");
	if(fd == NULL)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I  can not create '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}
	fprintf(fd,"[Gabedit Format]\n");
	fprintf(fd,"[Atoms] Angs\n");
	for(j=0;j<Ncenters;j++)
	{
		fprintf(fd,"%s %d %d %f %f %f\n",GeomOrb[j].Symb,j+1,(gint)GeomOrb[j].Prop.atomicNumber,
				BOHR_TO_ANG*GeomOrb[j].C[0],BOHR_TO_ANG*GeomOrb[j].C[1],BOHR_TO_ANG*GeomOrb[j].C[2]);
	}

	fprintf(fd,"[FREQ]\n");
	for(j=0;j<vibration.numberOfFrequences;j++)
		fprintf(fd,"%f\n",vibration.modes[j].frequence);

	fprintf(fd,"[INT]\n");
	for(j=0;j<vibration.numberOfFrequences;j++)
		fprintf(fd,"%f %f\n",vibration.modes[j].IRIntensity,vibration.modes[j].RamanIntensity);

	fprintf(fd,"[FR-COORD]\n");
	for(j=0;j<Ncenters;j++)
		fprintf(fd,"%s %f %f %f\n",GeomOrb[j].Symb,GeomOrb[j].C[0],GeomOrb[j].C[1],GeomOrb[j].C[2]);
	fprintf(fd,"[FR-NORM-COORD]\n");
	for(j=0;j<vibration.numberOfFrequences;j++)
	{
		fprintf(fd,"vibration %d\n",j+1);
		for(i=0;i<vibration.numberOfAtoms;i++)
		fprintf(fd,"%f %f %f\n",vibration.modes[j].vectors[0][i],vibration.modes[j].vectors[1][i],vibration.modes[j].vectors[2][i]);
	}
	fclose(fd);
	return TRUE;
}
/********************************************************************************/
static void reset_parameters(GtkWidget *win, gpointer data)
{
	gdouble scal     = atof(gtk_entry_get_text(GTK_ENTRY(EntryScal)));
	gdouble velo     = atof(gtk_entry_get_text(GTK_ENTRY(EntryVelocity)));
	gdouble radius   = atof(gtk_entry_get_text(GTK_ENTRY(EntryRadius)));
	gint nSteps   = atof(gtk_entry_get_text(GTK_ENTRY(EntryNSteps)));
	gchar t[BSIZE];

	if(scal<0)
	{
		scal = -scal;
		sprintf(t,"%f",scal);
		gtk_entry_set_text(GTK_ENTRY(EntryScal),t);
	}
	if(velo<0)
	{
		velo = -velo;
		sprintf(t,"%f",velo);
		gtk_entry_set_text(GTK_ENTRY(EntryVelocity),t);
	}
	if(scal==0)
		scal = 0.1;

	if(radius<0)
	{
		radius = -radius;
		sprintf(t,"%f",radius);
		gtk_entry_set_text(GTK_ENTRY(EntryRadius),t);
	}
	if(nSteps<0)
	{
		nSteps = -nSteps;
		sprintf(t,"%d",nSteps);
		gtk_entry_set_text(GTK_ENTRY(EntryNSteps),t);
	}
	if(nSteps<2)
	{
		nSteps = 4;
		sprintf(t,"%d",nSteps);
		gtk_entry_set_text(GTK_ENTRY(EntryNSteps),t);
	}

	vibration.scal = scal;
	vibration.velocity = velo;
	vibration.radius = radius;
	vibration.nSteps = nSteps;
	if(!play)
		stop_vibration(NULL,NULL);

}
/********************************************************************************/
static void reset_geom_vibration()
{

	gint j = 0;

	if(GeomOrb)
		free_atomic_orbitals();


	if(GeomOrb)
	{
		for(j=0;j<Ncenters;j++)
			if(GeomOrb[j].Symb)
				g_free(GeomOrb[j].Symb);
		g_free(GeomOrb);
		GeomOrb = NULL;
	}

	Ncenters = vibration.numberOfAtoms;
	GeomOrb=g_malloc(Ncenters*sizeof(TypeGeomOrb));
	for(j=0;j<Ncenters;j++)
	{
    		GeomOrb[j].Symb=g_strdup(vibration.geometry[j].symbol);
    		GeomOrb[j].C[0] = vibration.geometry[j].coordinates[0];
    		GeomOrb[j].C[1] = vibration.geometry[j].coordinates[1];
    		GeomOrb[j].C[2] = vibration.geometry[j].coordinates[2];
  		GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
		GeomOrb[j].Prop.covalentRadii *=1.2;
	}
	init_atomic_orbitals();
}
/********************************************************************************/
static gboolean read_gabedit_molden_geom(gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar* tmp;
 	gchar sdum[BSIZE];
 	gboolean OK;
 	FILE *fd;
 	guint taille=BSIZE;
	gint j;
	gint ne;

	Dipole.def = FALSE;

	tmp = get_name_file(FileName);
	set_status_label_info("File Name",tmp);
	g_free(tmp);
	set_status_label_info("File Type","Gabedit/Molden");
	set_status_label_info("Geometry","Reading");

 	fd = FOpen(FileName, "r");
 	OK=FALSE;
 	while(fd && !feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,"[FR-COORD]") )
	  	{
			OK = TRUE;
			break;
	  	}
	}
	if(OK)
	{
		free_geometry();
		GeomOrb = g_malloc(sizeof(TypeGeomOrb));
	}
	else
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Geometry","Nothing");
		if(fd) fclose(fd);
		return FALSE;
	}
	j = 0;
  	while(!feof(fd) && OK )
  	{
    		fgets(t,taille,fd);
		if(strstr(t,"[")) break;
		if(this_is_a_backspace(t)) break;
		ne = sscanf(t,"%s %f %f %f",sdum,&GeomOrb[j].C[0],&GeomOrb[j].C[1],&GeomOrb[j].C[2]);
		if(ne != 4)
		{
			gchar buffer[BSIZE];
			Ncenters = j;
			free_geometry();
			sprintf(buffer,"Sorry, I can not read geometry from '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);
			fclose(fd);
			return FALSE;
		}
		GeomOrb[j].Symb = g_strdup(sdum);
		GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
		GeomOrb = g_realloc(GeomOrb,(j+2)*sizeof(TypeGeomOrb));
		j++;
	}
	fclose(fd);
	Ncenters = j;
	GeomOrb = g_realloc(GeomOrb,Ncenters*sizeof(TypeGeomOrb));

	RebuildGeom = TRUE;
	reset_grid_limits();
	init_atomic_orbitals();
	set_status_label_info("Geometry","Ok");
	glarea_rafresh(GLArea);

	return TRUE;
}
/********************************************************************************/
static gboolean read_gabedit_molden_frequencies(gchar *FileName)
{
 	gchar t[BSIZE];
 	gboolean OK;
 	FILE *fd;
 	guint taille=BSIZE;
	gint j;
	gint k;
	gint ne;

 	fd = FOpen(FileName, "r");
 	OK=FALSE;
 	while(fd && !feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,"[FREQ]") )
	  	{
			OK = TRUE;
			break;
	  	}
	}
	if(!OK)
	{
		if(fd) fclose(fd);
		return FALSE;
	}

  	vibration.numberOfFrequences = 0;
	vibration.modes = g_malloc(sizeof(VibrationMode));
	j = 0;
  	while(!feof(fd) && OK )
  	{
    		if(!fgets(t,taille,fd))
			break;
		if(strstr(t,"[")) break;
		if(this_is_a_backspace(t)) break;
		ne = sscanf(t,"%lf",&vibration.modes[j].frequence);
		if(ne != 1)
		{
			gchar buffer[BSIZE];
			sprintf(buffer,"Sorry, I can not read frequencies from '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);

			free_vibration();
			fclose(fd);
			return FALSE;
		}
		vibration.modes[j].symmetry = g_strdup("Unknown");

		for(k=0;k<3;k++)
		  vibration.modes[j].vectors[k]= g_malloc(vibration.numberOfAtoms*sizeof(gdouble));

		vibration.numberOfFrequences++;
		vibration.modes = g_realloc(
					vibration.modes,
					(vibration.numberOfFrequences+1)*sizeof(VibrationMode));
		j++;
	}

	for(j=0; j<vibration.numberOfFrequences;j++)
			vibration.modes[j].IRIntensity = vibration.modes[j].RamanIntensity = 0;

	if(strstr(t,"[INT"))
	{
		for(j=0; j<vibration.numberOfFrequences;j++)
		{
    			if(!fgets(t,taille,fd))break;
			sscanf(t,"%lf %lf",&vibration.modes[j].IRIntensity,&vibration.modes[j].RamanIntensity);
		}

	}

	fclose(fd);
	return TRUE;
}
/********************************************************************************/
static gboolean read_gabedit_molden_modes(gchar *FileName)
{
 	gchar t[BSIZE];
 	gboolean OK;
 	FILE *fd;
 	guint taille=BSIZE;
	gint j;
	gint i;
	gint ne;

	if(vibration.numberOfAtoms<1)
		return FALSE;
	if(vibration.numberOfFrequences<1)
		return FALSE;


 	fd = FOpen(FileName, "r");
 	OK=FALSE;
 	while(fd && !feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,"[FR-NORM-COORD]") )
	  	{
			OK = TRUE;
			break;
	  	}
	}
	if(!OK)
	{
		free_vibration();
		if(fd) fclose(fd);
		return FALSE;
	}

	j = 0;
  	while(!feof(fd) && j<vibration.numberOfFrequences)
  	{
    		if(!fgets(t,taille,fd))
			break;
		if(!strstr(t,"ibration"))
			break;
		for(i=0;i<vibration.numberOfAtoms;i++)
		{
    			if(!fgets(t,taille,fd))
				break;
			ne = sscanf(t,"%lf %lf %lf",
					&vibration.modes[j].vectors[0][i],
					&vibration.modes[j].vectors[1][i],
					&vibration.modes[j].vectors[2][i]);
			if(ne != 3)
			{
				gchar buffer[BSIZE];
				sprintf(buffer,"Sorry, I can not read Modes from '%s' file\n",FileName);
  				Message(buffer,"Error",TRUE);

				free_vibration();
				fclose(fd);
				return FALSE;
			}

		}
		j++;
	}
	if(vibration.numberOfFrequences!=j)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read Modes from '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		free_vibration();
		fclose(fd);
		return FALSE;
	}
	fclose(fd);
	return TRUE;
}
/********************************************************************************/
static void read_gabedit_molden_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	gint j;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	stop_vibration(NULL, NULL);

 	if(read_gabedit_molden_geom(FileName))
	{
		free_vibration();
		vibration.numberOfAtoms = Ncenters;
		vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
		for(j=0;j<Ncenters;j++)
		{
			vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    			vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    			vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    			vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
		}
		if(read_gabedit_molden_frequencies(FileName))
		{
			if(read_gabedit_molden_modes(FileName))
				rafreshList();
		}
	}
}
/********************************************************************************/
static void read_gabedit_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_gabedit_molden_file,
			"Read geometry and frequencies from a Gabedit file",
			GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_molden_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_gabedit_molden_file,
			"Read geometry and frequencies from a Molden file",
			GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static gboolean read_mpqc_modes(FILE* fd, gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar sdum1[BSIZE];
 	gboolean OK;
 	guint taille=BSIZE;
	gint i;
	gint c;
	gint nf;
	gfloat v[4];
	gint numberOfFrequencies = 3*vibration.numberOfAtoms;
	gint nj[4];
	gint jm = -1;
	gint j = -1;
	gint nsym = 0;
	gchar sym[BSIZE];
	gint nms = 0;
	gint nfs = 0;
	gint nfsOld = 0;

	if(vibration.numberOfAtoms<1) return FALSE;

 	OK=FALSE;
  	while(!feof(fd))
  	{
		if(!fgets(t,taille,fd)) break;
		if(strstr(t,"Frequencies") && strstr(t,"cm-1"))
		{
			OK = TRUE;
			break;
		}
	}
	if(!OK)
	{
		gchar buffer[BSIZE];
		free_vibration();
		rafreshList();
		sprintf(buffer,"Sorry, I can not read the frequencies from '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}

  	vibration.numberOfFrequences = numberOfFrequencies;
	vibration.modes = g_malloc((numberOfFrequencies)*sizeof(VibrationMode));
	for(i=0;i<numberOfFrequencies;i++)
	{
		vibration.modes[i].vectors[0] = NULL;
		vibration.modes[i].vectors[1] = NULL;
		vibration.modes[i].vectors[2] = NULL;
		vibration.modes[i].symmetry = NULL;
	}
	OK = FALSE;
	j = -1;
	jm = 0;
	nsym = -1;
  	while(!feof(fd))
  	{
		if(!fgets(t,taille,fd)) break;
		if(strstr(t,"THERMODYNAMIC ANALYSIS")) { OK = TRUE; break; }
		nf =-1;
		OK = FALSE;
  		while(!feof(fd) && !OK)
  		{
			if(!fgets(t,taille,fd)) break;
			if(strstr(t,"THERMODYNAMIC ANALYSIS")) { OK = TRUE; break; }
			if(strstr(t,"mass weighted dhessian"))
			{
  				while(!feof(fd))
  				{
					gint d;
					if(!fgets(t,taille,fd)) break;
					if(strstr(t,"THERMODYNAMIC ANALYSIS")) { OK = TRUE; break; }
					if(this_is_a_backspace(t)) continue;
					nf = sscanf(t,"%d",&d);
					/* t is a new symmetry */
					if(nf==0) 
					{
						OK = TRUE;
						break;
					}
				}
			}
		}
		if( !OK) break;
		if(strstr(t,"THERMODYNAMIC ANALYSIS")) { OK = TRUE; break; }
		nsym++;
		sscanf(t,"%s",sym);
		nfsOld = nfs;
		nfs = 0;
  		while(!feof(fd))
  		{
			gint d;
			gfloat f;

			if(!fgets(t,taille,fd)) break;
			if(this_is_a_backspace(t)) break;
			nf = sscanf(t,"%d %f",&d, &f);
			if(nf!=2) {OK = FALSE; break;}
			j++;
			if(j>=numberOfFrequencies) {OK = FALSE; break;}
			nfs++;
			vibration.modes[j].frequence = f;
			vibration.modes[j].IRIntensity = 0.0;
			vibration.modes[j].RamanIntensity = 0.0;
			vibration.modes[j].symmetry = g_strdup(sym);
			for(c=0;c<3;c++)
			{
				vibration.modes[j].vectors[c]= g_malloc(vibration.numberOfAtoms*sizeof(gdouble));
				for(i=0;i<vibration.numberOfAtoms;i++) vibration.modes[j].vectors[c][i] = 0;
			}
		}
		if(!OK) break;
		OK = FALSE;
  		while(!feof(fd))
  		{
			if(!fgets(t,taille,fd)) break;
			if(strstr(t,"THERMODYNAMIC ANALYSIS")) { OK = FALSE; break; }
			if(strstr(t,"ncbasis*eigvecs"))
			{
				OK = TRUE;
				break;
			}
		}
		if(!OK) break;
		nms = 0;
  		while(!feof(fd) && nms != nfs)
  		{
			gint k;
			gint kk;
			if(!fgets(t,taille,fd)) break;
			k = sscanf(t,"%d %d %d %d",&nj[0],&nj[1],&nj[2],&nj[3]);
			if(k<1) { OK = FALSE; break;}
			nms += k;
			jm+=k;
			for(kk=0;kk<k;kk++)
			{
				nj[kk]--;
				if(nj[kk]<0) { OK = FALSE; break;}
				nj[kk] += nfsOld;
			}
			if(!OK) break;

			for(i=0;i<vibration.numberOfAtoms;i++)
			for(c=0;c<3;c++)
			{
				if(!fgets(t,taille,fd)) { OK = FALSE;break;}
				nf = sscanf(t,"%s %f %f %f %f",sdum1,&v[0],&v[1],&v[2],&v[3]);
				nf--;
				if(nf<k) { OK = FALSE; break;}
				for(kk=0;kk<k;kk++)
				vibration.modes[nj[kk]].vectors[c][i] = v[kk];
			}
			if(!fgets(t,taille,fd)) break; /*  back space */
		}
		if(nms != nfs) break;
		if(!OK) break;
	}
	if(!OK || j <0 || jm != j+1)
	{
		gchar buffer[BSIZE];
		free_vibration();
		rafreshList();
		sprintf(buffer,
			"Sorry, I can not read the normal modes from '%s' file\n"
			"  Set debug = 1 in freq<MolecularFrequencies> object for obtain the normal modes from MPQC\n"
			,
			FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}
	vibration.numberOfFrequences = j+1;
	vibration.modes = g_realloc(vibration.modes,vibration.numberOfFrequences*sizeof(VibrationMode));
	return TRUE;
}
/********************************************************************************/
static void read_mpqc_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	gint j;
	FILE* file;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);

#ifdef G_OS_WIN32 
 	file = FOpen(FileName, "rb");
#else
	file = FOpen(FileName, "r");
#endif
	stop_vibration(NULL, NULL);
	if(!file)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return;
	}
 	if(gl_read_mpqc_file_geomi(FileName,-1))
	{
		free_vibration();
		vibration.numberOfAtoms = Ncenters;
		vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
		for(j=0;j<Ncenters;j++)
		{
			vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    			vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    			vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    			vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
		}
		if(read_mpqc_modes(file,FileName))
		{
				rafreshList();
		}
	}
	fclose(file);
}

/********************************************************************************/
static void read_mpqc_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_mpqc_file,
			"Read geometry and frequencies from a MPQC output file",
			GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/*****************************************************************/
static gchar* get_symbol(gchar* name)
{
	gchar Forbidden[]={'0','1','2','3','4','5','6','7','8','9'};
	gchar* symb;

	if(strlen(name)==1)
	{
		symb = g_strdup(name);
	}
	else
	{
		gint Ok = 1;
		gint i;
		for(i=0;i<10;i++)
			if(name[1]== Forbidden[i])
			{
				Ok =0;
				break;
			}
		if(Ok==1)
		{
			symb = g_strdup_printf("%c%c",toupper(name[0]),tolower(name[1]));
		}
		else
			symb = g_strdup_printf("%c",toupper(name[0]));
	}
	return symb;
}
/********************************************************************************/
static gboolean read_molpro_geom(FILE*fd, gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar* tmp;
 	gchar sdum1[BSIZE];
 	gchar sdum2[BSIZE];
 	gchar sdum3[BSIZE];
 	gboolean OK;
 	guint taille=BSIZE;
	gint j;
	gint ne;
 	long geomposok = 0;

	Dipole.def = FALSE;

	tmp = get_name_file(FileName);
	set_status_label_info("File Name",tmp);
	g_free(tmp);
	set_status_label_info("File Type","Molpro");
	set_status_label_info("Geometry","Reading");

 	OK=FALSE;
 	while(!feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,"FREQUENCIES * CALCULATION OF NORMAL MODES") )
	  	{
			OK = TRUE;
 			geomposok = ftell(fd);
		
			/*
			printf("%s",t);
			printf("geomposok = %ld\n",geomposok);
			*/
		
	  	}
	}
	if(OK)
	{
		/* printf("geomposok = %ld\n",geomposok);*/
		fseek(fd, geomposok, SEEK_SET);
		OK = FALSE;
 		while(!feof(fd))
		{
			fgets(t,taille,fd);
			
			/* printf("t=%s\n",t);*/
	 		if ( strstr( t,"Nr  Atom") )
	  		{
				fgets(t,taille,fd);
				OK = TRUE;
				break;
	  		}
		}
	}
	if(OK)
	{
		free_geometry();
		GeomOrb = g_malloc(sizeof(TypeGeomOrb));
	}
	else
	{
		gchar buffer[BSIZE];
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Geometry","Nothing");

		sprintf(buffer,"Sorry, I can not read Geometry from '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}
	j = 0;
  	while(!feof(fd) && OK )
  	{
    		fgets(t,taille,fd);
		if(this_is_a_backspace(t))
			break;
		ne = sscanf(t,"%s %s %s %f %f %f",
				sdum1,sdum2,sdum3,
				&GeomOrb[j].C[0],&GeomOrb[j].C[1],&GeomOrb[j].C[2]);
		if(ne != 6)
		{
			gchar buffer[BSIZE];

			Ncenters = j;
			free_geometry();

			sprintf(buffer,"Sorry, I can not read geometry from  '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);

			return FALSE;
		}
		GeomOrb[j].Symb = get_symbol(sdum2);
		GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
		GeomOrb = g_realloc(GeomOrb,(j+2)*sizeof(TypeGeomOrb));
		j++;
	}
	Ncenters = j;
	if(Ncenters>0)
		GeomOrb = g_realloc(GeomOrb,Ncenters*sizeof(TypeGeomOrb));
	else
		free_geometry();

	RebuildGeom = TRUE;
	reset_grid_limits();
	init_atomic_orbitals();
	set_status_label_info("Geometry","Ok");
	glarea_rafresh(GLArea);

	return TRUE;
}
/********************************************************************************/
static gint read_molpro_modes_str(FILE* fd, gchar *FileName, gchar* str)
{
 	gchar t[BSIZE];
 	gchar sdum1[BSIZE];
 	gchar sdum2[BSIZE];
 	gboolean OK;
 	guint taille=BSIZE;
	gint i;
	gint j;
	gint k;
	gint c;
	gint ne;
	gint nf;
	gfloat freq[5];
	gfloat IRIntensity[5];
	gint nfMax = 5;

	if(vibration.numberOfAtoms<1) return FALSE;

 	OK=FALSE;
 	while(!feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,str) )
	  	{
			OK = TRUE;
			break;
	  	}
	}

	if(!OK) return 1;

	j = vibration.numberOfFrequences;
  	while(!feof(fd))
  	{
		if(!fgets(t,taille,fd))
		{
			vibration.numberOfFrequences = j+nfMax;
			return 2;
		}
    		if(!fgets(t,taille,fd)) break;
		if(!strstr(t,"Wavenumbers")) break;
		nf = sscanf(t,"%s %s %f %f %f %f %f", sdum1,sdum2, &freq[0],&freq[1],&freq[2],&freq[3],&freq[4]);
		nf -= 2;
		if(strstr(str,"imaginary")) for(k=0;k<nf;k++) freq[k] = -freq[k];
    		if(!fgets(t,taille,fd)) break;
		sscanf(t,"%s %s %f %f %f %f %f",
				sdum1,sdum2,
				&IRIntensity[0],&IRIntensity[1],&IRIntensity[2],&IRIntensity[3],&IRIntensity[4]);

    		if(!fgets(t,taille,fd)) break;

		vibration.modes = g_realloc(vibration.modes,(j+nfMax)*sizeof(VibrationMode));

		for(k=0;k<nfMax;k++)
		{
			vibration.modes[j+k].frequence = freq[k];
			vibration.modes[j+k].IRIntensity = IRIntensity[k];
			vibration.modes[j+k].RamanIntensity = 0.0;
			vibration.modes[j+k].symmetry = g_strdup("Unknown");
			for(c=0;c<3;c++)
				vibration.modes[j+k].vectors[c]= 
					g_malloc(vibration.numberOfAtoms*sizeof(gdouble));

		}

		for(i=0;i<vibration.numberOfAtoms;i++)
		{
			for(c=0;c<3;c++)
			{
    				if(!fgets(t,taille,fd))
					break;
				ne = sscanf(t,"%s %lf %lf %lf %lf %lf",sdum1,
					&vibration.modes[j  ].vectors[c][i],
					&vibration.modes[j+1].vectors[c][i],
					&vibration.modes[j+2].vectors[c][i],
					&vibration.modes[j+3].vectors[c][i],
					&vibration.modes[j+4].vectors[c][i]);
				if(ne <2)
				{
					vibration.numberOfFrequences = j+nfMax;
					return 2;
				}
			}

		}
		j+=nf;

	}
	vibration.numberOfFrequences = j;
	vibration.modes = g_realloc(vibration.modes,vibration.numberOfFrequences*sizeof(VibrationMode));
	return 0;
}
/********************************************************************************/
static gboolean read_molpro_modes(FILE* fd, gchar *FileName)
{
	gint normalModes = 0;
	gint normalModesImag = 0;

	if(vibration.numberOfAtoms<1) return FALSE;

	vibration.modes = g_malloc(sizeof(VibrationMode));
  	vibration.numberOfFrequences = 0;
	normalModes = read_molpro_modes_str(fd, FileName, "Normal Modes");
	if(normalModes<=1)
		normalModesImag = read_molpro_modes_str(fd, FileName, "Normal Modes of imaginary frequencies");

	if(normalModes>1 || normalModesImag>1)
	{
			gchar buffer[BSIZE];
			free_vibration();
			sprintf(buffer,"Sorry, I can not read the frequencies from '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);
			return FALSE;
	}

	return TRUE;
}
/********************************************************************************/
static void read_molpro_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	gint j;
	FILE* file;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);

#ifdef G_OS_WIN32 
 	file = FOpen(FileName, "rb");
#else
	file = FOpen(FileName, "r");
#endif
	stop_vibration(NULL, NULL);
	if(!file)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return;
	}

 	if(read_molpro_geom(file,FileName))
	{
		free_vibration();
		vibration.numberOfAtoms = Ncenters;
		vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
		for(j=0;j<Ncenters;j++)
		{
			vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    			vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    			vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    			vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
		}
		if(read_molpro_modes(file,FileName))
		{
				rafreshList();
		}
	}
	fclose(file);
}

/********************************************************************************/
static void create_window_spectrum()
{
		createVibrationSpectrum(WinDlg, vibration);
}
/********************************************************************************/
static void read_molpro_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_molpro_file,
			"Read geometry and frequencies from a Molpro output file",
			GABEDIT_TYPEFILE_MOLPRO,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static gboolean read_dalton_geom(FILE* file, gchar *FileName)
{
 	gchar *t;
 	gchar *tmp = NULL;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	guint taille=BSIZE;
 	guint i;
 	gint j=0;
 	gint l;
 	guint numgeom;
	gchar dum[100];
	gint kk;

 	for(i=0;i<5;i++) AtomCoord[i]=g_malloc(taille*sizeof(gchar));
 	t=g_malloc(taille);

	free_geometry();
	tmp = get_name_file(FileName);
	set_status_label_info("File Name",tmp);
	g_free(tmp);
	set_status_label_info("File Type","Dalton");
 	numgeom =1;
 	do 
 	{
		set_status_label_info("Geometry","Reading");
 		OK=FALSE;
 		while(!feof(file))
		{
			if(!fgets(t,taille,file))break;
			if ( strstr(t,"Vibrational Frequencies") || strstr(t,"Vibrational frequencies")) break;
			if ( strstr(t,"geometry (au)"))
			{
	  			fgets(t,taille,file);
	  			fgets(t,taille,file);
 				numgeom++;
                		OK = TRUE;
	  			break;
	  		}
        	}
 		if(!OK && (numgeom == 1) )
		{
  			GtkWidget* w = Message("Sorry\nI can not read geometry from this file","Error",TRUE);
			gtk_window_set_modal (GTK_WINDOW (w), TRUE);
 			g_free(t);
 			for(i=0;i<5;i++) g_free(AtomCoord[i]);
			set_status_label_info("File Name","Nothing");
			set_status_label_info("File Type","Nothing");
			set_status_label_info("Geometry","Nothing");
			return FALSE;
    		}
 		if(!OK)break;

  		j=-1;
  		while(!feof(file) )
  		{
			fgets(t,taille,file);
			if ( !strcmp(t,"\n"))
			{
				/* get_dipole_from_dalton_output_file(file);*/
				break;
			}
    			j++;
    			if(GeomOrb==NULL) GeomOrb=g_malloc(sizeof(TypeGeomOrb));
    			else GeomOrb=g_realloc(GeomOrb,(j+1)*sizeof(TypeGeomOrb));

			kk = sscanf(t,"%s %s %s %s %s",AtomCoord[0],AtomCoord[1], AtomCoord[2],AtomCoord[3], dum);
			if(kk==5) sscanf(t,"%s %s %s %s %s",AtomCoord[0],dum, AtomCoord[1], AtomCoord[2],AtomCoord[3]);

			for(i=0;i<(gint)strlen(AtomCoord[0]);i++) if(isdigit(AtomCoord[0][i])) AtomCoord[0][i] = ' ';
			delete_all_spaces(AtomCoord[0]);
			AtomCoord[0][0]=toupper(AtomCoord[0][0]);
	 		l=strlen(AtomCoord[0]);
          		if (l==2) AtomCoord[0][1]=tolower(AtomCoord[0][1]);
			/*
			printf("j = %d symb = %s %s %s %s \n",j, AtomCoord[0], AtomCoord[1], AtomCoord[2],AtomCoord[3]);
			*/

    			GeomOrb[j].Symb=g_strdup(AtomCoord[0]);
    			for(i=0;i<3;i++) GeomOrb[j].C[i]=atof((AtomCoord[i+1]));

			GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
  		}
 	}while(!feof(file));

 	Ncenters = j+1;
 	g_free(t);
 	for(i=0;i<5;i++) g_free(AtomCoord[i]);
 	if(Ncenters == 0 ) g_free(GeomOrb);

	RebuildGeom = TRUE;
	reset_grid_limits();
	init_atomic_orbitals();
	set_status_label_info("Geometry","Ok");
	return TRUE;
}
/********************************************************************************/
static gint read_dalton_modes_NMDDRV(FILE* fd, gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar sdum1[BSIZE];
 	gchar sdum2[BSIZE];
 	gboolean OK;
 	guint taille=BSIZE;
	gint i;
	gint j;
	gint c;
	gint ne;
	gint nf;
	gfloat freq;
	gint nfMax = 6;

	if(vibration.numberOfAtoms<1) return 1;

 	OK=FALSE;
 	while(!feof(fd))
	{
		if(!fgets(t,taille,fd))break;
	 	if ( strstr( t,"Vibrational frequencies harmonic approximation:") )
	  	{
			OK = TRUE;
			break;
	  	}
	}

	if(!OK) return 1;

 	OK=FALSE;
 	while(!feof(fd))
	{
		if(!fgets(t,taille,fd))break;
	 	if ( strstr( t,"Mode") && strstr( t,"hartrees")  )
	  	{
			OK = TRUE;
			break;
	  	}
	}
	if(!OK) return 1;

	j = 0;
  	while(!feof(fd))
  	{
		if(!fgets(t,taille,fd))
		{
			vibration.numberOfFrequences = j;
			return 2;
		}
		if(this_is_a_backspace(t)) break;

		nf = sscanf(t,"%s %s", sdum1,sdum2);
		if(nf<2)
		{
			vibration.numberOfFrequences = j;
			return 2;
		}
		if(strstr(sdum2,"i"))
		{
			freq = -atof(sdum2);
		}
		else
			freq = atof(sdum2);

		vibration.modes = g_realloc(vibration.modes,(j+nfMax)*sizeof(VibrationMode));
		vibration.modes[j].frequence = freq;
		vibration.modes[j].IRIntensity = 0.0;
		vibration.modes[j].RamanIntensity = 0.0;
		vibration.modes[j].symmetry = g_strdup(sdum1);
		for(c=0;c<3;c++) vibration.modes[j].vectors[c]= g_malloc(vibration.numberOfAtoms*sizeof(gdouble));
		j++;
	}
	vibration.numberOfFrequences = j;

 	OK=FALSE;
 	while(!feof(fd))
	{
		if(!fgets(t,taille,fd))break;
	 	if ( strstr( t,"Normal coordinates"))
	  	{
			if(!fgets(t,taille,fd))break;
			OK = TRUE;
			break;
	  	}
	}
	if(!OK) return 1;

	j = 0;
  	while(!feof(fd))
  	{
		if(!fgets(t,taille,fd)) /* backspace */
		{
			return 2;
		}
		if(!fgets(t,taille,fd)) /* symmetry of each mode */
		{
			return 2;
		}

		nf = 0;
		for(i=0;i<vibration.numberOfAtoms;i++)
		{
			for(c=0;c<3;c++)
			{
    				if(!fgets(t,taille,fd)) break;
				ne = sscanf(t,"%lf %lf %lf %lf %lf %lf",
					&vibration.modes[j  ].vectors[c][i],
					&vibration.modes[j+1].vectors[c][i],
					&vibration.modes[j+2].vectors[c][i],
					&vibration.modes[j+3].vectors[c][i],
					&vibration.modes[j+4].vectors[c][i],
					&vibration.modes[j+5].vectors[c][i]);
				if(ne <1)
				{
					return 2;
				}
				nf = ne;
			}

		}
		if(nf<1) return 2;
		j+=nf;
		if(j>=vibration.numberOfFrequences) break;

	}
	vibration.modes = g_realloc(vibration.modes,vibration.numberOfFrequences*sizeof(VibrationMode));
	return 0;
}
/********************************************************************************/
static gint read_dalton_modes_MOLHES(FILE* fd, gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar sdum1[100];
 	gchar sdum2[100];
 	gboolean OK;
 	guint taille=BSIZE;
	gint i;
	gint j;
	gint c;
	gint ne;
	gint nf;
	/* gint nfMax = 5;*/
	gfloat freq;
	gint numModes[5];
	gint numMode;
	gchar sym[50];
	gfloat IR = 0;
	gint nModes = vibration.numberOfAtoms*3;
 	gchar sdum[8][50];

	if(vibration.numberOfAtoms<1) return 1;

 	OK=FALSE;
 	while(!feof(fd))
	{
		if(!fgets(t,taille,fd))break;
	 	if ( strstr( t,"Vibrational Frequencies and IR Intensities") )
	  	{
			OK = TRUE;
			break;
	  	}
	}

	if(!OK) return 1;

 	OK=FALSE;
 	while(!feof(fd))
	{
		if(!fgets(t,taille,fd))break;
	 	if ( strstr( t,"cm-1") && strstr( t,"hartrees")  )
	  	{
			if(!fgets(t,taille,fd))break;
			OK = TRUE;
			break;
	  	}
	}
	if(!OK) return 1;

	vibration.modes = g_realloc(vibration.modes,(nModes)*sizeof(VibrationMode));
	j = 0;
  	while(!feof(fd))
  	{
		if(!fgets(t,taille,fd))
		{
			vibration.numberOfFrequences = j;
			vibration.modes = g_realloc(vibration.modes,(j+1)*sizeof(VibrationMode));
			return 2;
		}
		if(this_is_a_backspace(t)) continue;
		if(strstr(t,"Normal Coordinates")) break;

		nf = sscanf(t,"%d %s %s %s %s", &numMode, sym, sdum1,sdum2, sdum2);
		if(nf<3)
		{
			vibration.numberOfFrequences = j;
			vibration.modes = g_realloc(vibration.modes,(j+1)*sizeof(VibrationMode));
			return 2;
		}
		if(strstr(sdum1,"i")) freq = -atof(sdum1);
		else freq = atof(sdum1);

		if(nf==5) IR = atof(sdum2);
		else IR = 0.0;
		if(numMode>nModes)
		{
			vibration.numberOfFrequences = j;
			vibration.modes = g_realloc(vibration.modes,(j+1)*sizeof(VibrationMode));
			return 2;
		}

		vibration.modes[numMode-1].frequence = freq;
		vibration.modes[numMode-1].IRIntensity = IR;
		vibration.modes[numMode-1].RamanIntensity = 0.0;
		vibration.modes[numMode-1].symmetry = g_strdup(sym);
		for(c=0;c<3;c++) vibration.modes[numMode-1].vectors[c]= g_malloc(vibration.numberOfAtoms*sizeof(gdouble));
		j++;
	}
	if(j<1)
	{
		if(vibration.modes) g_free(vibration.modes);
		vibration.modes = NULL;
		return 2;
	}
	vibration.numberOfFrequences = j;
	vibration.modes = g_realloc(vibration.modes,(j)*sizeof(VibrationMode));
	if(!strstr(t,"Normal Coordinates")) return 2;

	if(!fgets(t,taille,fd)) return 1; /* ---- */
	if(!fgets(t,taille,fd)) return 1; /* backspace */

	j = 0;
  	while(!feof(fd))
  	{
		gint nft = 0;
		if(!fgets(t,taille,fd)) /* backspace */
		{
			return 2;
		}
		if(!fgets(t,taille,fd)) /* num modes and frequencies */
		{
			return 2;
		}
		nft = sscanf(t,"%d %s %d %s %d %s %d %s %d %s",
					&numModes[0], sdum[0],
					&numModes[1], sdum[1],
					&numModes[2], sdum[2],
					&numModes[3], sdum[3],
					&numModes[4], sdum[4]);
		if(nft<2) return 1;
		if(!fgets(t,taille,fd)) return 2; /* --------- */
		if(!fgets(t,taille,fd)) return 2; /*backspace */
		nft /=2;

		ne = 0;
		for(i=0;i<vibration.numberOfAtoms;i++)
		{
			for(c=0;c<3;c++)
			{
    				if(!fgets(t,taille,fd)) break;
				ne = sscanf(t,"%s %s %s %s %s %s %s %s",
				sdum[0], sdum[1], sdum[2], sdum[3], sdum[4], sdum[5], sdum[6], sdum[7]);
				ne -=3;
				if(ne == nft)
				{
					gint k;
					for(k=0;k<ne;k++)
					vibration.modes[numModes[k]-1].vectors[c][i] = atof(sdum[k+3]);
				}
				else
				{
					ne++;
					if(ne==nft)
					{
						gint k;
						for(k=0;k<ne;k++)
							vibration.modes[numModes[k]-1].vectors[c][i] = atof(sdum[k+2]);
					}
					else return 2;

				}
			}
    			if(!fgets(t,taille,fd)) break; /* backspace */

		}
		j+=ne;
		if(j>=vibration.numberOfFrequences) break;

	}
	vibration.modes = g_realloc(vibration.modes,vibration.numberOfFrequences*sizeof(VibrationMode));
	return 0;
}
/********************************************************************************/
static gint read_dalton_modes(FILE* file, gchar *FileName)
{
	gint ret =0;
	gint j;
	free_vibration();
	vibration.numberOfAtoms = Ncenters;
	vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
	for(j=0;j<Ncenters;j++)
	{
		vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    		vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    		vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    		vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
	}
	vibration.modes = g_malloc(sizeof(VibrationMode));
  	vibration.numberOfFrequences = 0;
	fseek(file, 0, SEEK_SET);
	ret = read_dalton_modes_NMDDRV(file, FileName);
	if(ret==0) return ret;

	free_vibration();
	vibration.numberOfAtoms = Ncenters;
	vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
	for(j=0;j<Ncenters;j++)
	{
		vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    		vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    		vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    		vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
	}
	vibration.modes = g_malloc(sizeof(VibrationMode));
  	vibration.numberOfFrequences = 0;
	fseek(file, 0, SEEK_SET);
	ret = read_dalton_modes_MOLHES(file, FileName);
	return ret;
}
/********************************************************************************/
static gboolean read_gaussian_file_frequencies(gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar sdum1[BSIZE];
 	gchar sdum2[BSIZE];
 	gchar sdum3[BSIZE];
 	gboolean OK;
 	FILE *fd;
 	guint taille=BSIZE;
	gint idum;
	gint nf;
	gdouble freq[3] = {0,0,0};
	gdouble IRIntensity[3] = {0,0,0};
	gdouble RamanIntensity[3]={ 0,0,0};
	gdouble v[3][3];
	gchar sym[3][BSIZE];
	gint j;
	gint k;
	gint nfOld;


	Dipole.def = FALSE;
	free_vibration();
	vibration.numberOfAtoms = Ncenters;
	vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
	for(j=0;j<Ncenters;j++)
	{
		vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    		vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    		vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    		vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
	}
  	vibration.numberOfFrequences = 0;
	vibration.modes = g_malloc(sizeof(VibrationMode));

 	fd = FOpen(FileName, "r");
	if(!fd) return FALSE;

	for(j=0;j<3;j++)
	{
		sprintf(sym[j]," ");
		for(k=0;k<3;k++) v[j][k] = 0;
	}

 	do 
 	{
 		OK=FALSE;
 		while(!feof(fd))
		{
	  		fgets(t,taille,fd);
	 		/* if ( strstr( t,"reduced masses") )*/
	 		if ( strstr( t,"and normal coordinates:") )
	  		{
				OK = TRUE;
				break;
	  		}
		}
  		while(!feof(fd) )
  		{
    			fgets(t,taille,fd);
			if(this_is_a_backspace(t))
				break;
			nf = sscanf(t,"%d %d %d",&idum,&idum,&idum);
			if(nf<0 || nf>3)
			{
				break;
			}
			if(!fgets(t,taille,fd)) break;
			sscanf(t,"%s %s %s",sym[0],sym[1],sym[2]);

			if(!fgets(t,taille,fd)) break;
			sscanf(t,"%s %s %lf %lf %lf", sdum1,sdum2, &freq[0],&freq[1],&freq[2]);
			while(!feof(fd))
			{
    				fgets(t,taille,fd);
				if(strstr(t,"IR Inten"))
				{
					sscanf(t,"%s %s %s %lf %lf %lf", sdum1,sdum2, sdum3, &IRIntensity[0],&IRIntensity[1],&IRIntensity[2]);
					break;
				}
			}
			while(!feof(fd))
			{
    				fgets(t,taille,fd);
				if(strstr(t,"Raman"))
				{
					sscanf(t,"%s %s %s %lf %lf %lf", sdum1,sdum2, sdum3, &RamanIntensity[0],&RamanIntensity[1],&RamanIntensity[2]);
					break;
				}
				if(strstr(t,"Atom AN")) break;
			}

			if(!strstr(t,"Atom AN"))
			while(!feof(fd))
			{
    				fgets(t,taille,fd);
				if(strstr(t,"Atom AN")) break;
			}
			nfOld = vibration.numberOfFrequences;
  			vibration.numberOfFrequences += nf;
			vibration.modes = g_realloc(
					vibration.modes,
					vibration.numberOfFrequences*sizeof(VibrationMode));

			for(k=0;k<nf;k++)
			{
				vibration.modes[k+nfOld].frequence = freq[k];
				vibration.modes[k+nfOld].IRIntensity = IRIntensity[k];
				vibration.modes[k+nfOld].RamanIntensity = RamanIntensity[k];
				vibration.modes[k+nfOld].symmetry = g_strdup(sym[k]);
				vibration.modes[k+nfOld].vectors[0]= 
					g_malloc(vibration.numberOfAtoms*sizeof(gdouble));
				vibration.modes[k+nfOld].vectors[1]= 
					g_malloc(vibration.numberOfAtoms*sizeof(gdouble));
				vibration.modes[k+nfOld].vectors[2]= 
					g_malloc(vibration.numberOfAtoms*sizeof(gdouble));
			}

			for(j=0;j<Ncenters && !feof(fd);j++)
			{
				if(!fgets(t,taille,fd))
					break;
				sscanf(t,"%d %d %lf %lf %lf %lf %lf %lf %lf %lf %lf",
					&idum,&idum,
					&v[0][0],&v[0][1],&v[0][2],
					&v[1][0],&v[1][1],&v[1][2],
					&v[2][0],&v[2][1],&v[2][2]
					);
				for(k=0;k<nf;k++)
				{
					vibration.modes[k+nfOld].vectors[0][j]= v[k][0]; 
					vibration.modes[k+nfOld].vectors[1][j]= v[k][1]; 
					vibration.modes[k+nfOld].vectors[2][j]= v[k][2]; 
				}
			}
		}
 	}while(!feof(fd));
	rafreshList();
	if(vibration.numberOfFrequences<1)
	{
		GtkWidget* w = NULL;
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read frequencies from '%s' file\n",FileName);
  		w = Message(buffer,"Error",TRUE);
		gtk_window_set_modal (GTK_WINDOW (w), TRUE);
		return FALSE;
	}

	return TRUE;
}
/********************************************************************************/
static gboolean read_adf_geom(FILE*fd, gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar* tmp;
 	gchar sdum1[BSIZE];
 	gchar sdum2[BSIZE];
 	gchar sdum3[BSIZE];
 	gboolean OK;
 	guint taille=BSIZE;
	gint j;
	gint ne;
 	long geomposok = 0;

	Dipole.def = FALSE;

	tmp = get_name_file(FileName);
	set_status_label_info("File Name",tmp);
	g_free(tmp);
	set_status_label_info("File Type","ADF");
	set_status_label_info("Geometry","Reading");

 	OK=FALSE;
 	while(!feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,"*  F R E Q U E N C I E S  *") )
	  	{
			OK = TRUE;
 			geomposok = ftell(fd);
	  	}
	}
	if(OK)
	{
		fseek(fd, geomposok, SEEK_SET);
		OK = FALSE;
 		while(!feof(fd))
		{
			fgets(t,taille,fd);
	 		if ( strstr( t,"Atomic Masses") )
			{
				OK = FALSE;
				break;
			}
			
	 		if ( strstr( t,"Coordinates (Cartesian)") )
	  		{
				OK = TRUE;
				break;
	  		}
		}
	}
	if(OK)
	{
		OK = FALSE;
 		while(!feof(fd))
		{
			fgets(t,taille,fd);
	 		if ( strstr( t,"-----------------------") )
	  		{
				OK = TRUE;
				break;
	  		}
		}
	}

	if(OK)
	{
		free_geometry();
		GeomOrb = g_malloc(sizeof(TypeGeomOrb));
	}
	else
	{
		gchar buffer[BSIZE];
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Geometry","Nothing");

		sprintf(buffer,"Sorry, I can not read Geometry from '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}
	j = 0;
  	while(!feof(fd) && OK )
  	{
    		fgets(t,taille,fd);
		if(this_is_a_backspace(t)) break;
		if(strstr(t,"---------------------")) break;

		ne = sscanf(t,"%s %s %s %f %f %f",
				sdum1,sdum2,sdum3,
				&GeomOrb[j].C[0],&GeomOrb[j].C[1],&GeomOrb[j].C[2]);
		if(ne != 6)
		{
			gchar buffer[BSIZE];

			Ncenters = j;
			free_geometry();

			sprintf(buffer,"Sorry, I can not read geometry from  '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);

			return FALSE;
		}
		GeomOrb[j].Symb = get_symbol(sdum3);
		GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
		GeomOrb = g_realloc(GeomOrb,(j+2)*sizeof(TypeGeomOrb));
		j++;
	}
	Ncenters = j;
	if(Ncenters>0)
		GeomOrb = g_realloc(GeomOrb,Ncenters*sizeof(TypeGeomOrb));
	else
		free_geometry();

	RebuildGeom = TRUE;
	reset_grid_limits();
	init_atomic_orbitals();
	set_status_label_info("Geometry","Ok");
	glarea_rafresh(GLArea);

	return TRUE;
}
/********************************************************************************/
static gboolean read_adf_modes(FILE* fd, gchar *FileName)
{
 	gchar t[BSIZE];
 	gchar sdum1[BSIZE];
 	gchar sdum2[BSIZE];
 	gchar sdum3[BSIZE];
 	gboolean OK;
 	guint taille=BSIZE;
	gint i;
	gint j;
	gint k;
	gint c;
	gint ne;
	gint nf;
	gfloat freq[5];
	gint nfMax = 3;

	if(vibration.numberOfAtoms<1)
		return FALSE;

 	OK=FALSE;
 	while(!feof(fd))
	{
		fgets(t,taille,fd);
		/* printf("%s",t);*/
	 	if ( strstr( t,"Vibrations and Normal Modes") )
	  	{
			OK = TRUE;
			break;
	  	}
	}
	if(OK)
	{
 		OK=FALSE;
		if(fgets(t,taille,fd)) 
		if(fgets(t,taille,fd))
		if(fgets(t,taille,fd))
		if(fgets(t,taille,fd)) OK = TRUE;
	}
	if(!OK)
	{
		gchar buffer[BSIZE];
		free_vibration();
		sprintf(buffer,"Sorry, I can not read the frequencies from '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return FALSE;
	}

	j = 0;
	vibration.modes = g_malloc(sizeof(VibrationMode));
  	vibration.numberOfFrequences = 0;

  	while(!feof(fd))
  	{
		fgets(t,taille,fd);
		fgets(t,taille,fd);
		if(!fgets(t,taille,fd))
		{
			gchar buffer[BSIZE];
			vibration.numberOfFrequences = j+nfMax;
			free_vibration();
			sprintf(buffer,"Sorry, I can not read the frequencies from '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);
			return FALSE;
		}

		nf = sscanf(t,"%s %f %f %f", sdum1, &freq[0],&freq[1],&freq[2]);
		nf -= 1;
		if(nf<1) break;

    		if(!fgets(t,taille,fd)) break;

		vibration.modes = g_realloc(vibration.modes,(j+nfMax)*sizeof(VibrationMode));

		for(k=0;k<nfMax;k++)
		{
			vibration.modes[j+k].frequence = freq[k];
			vibration.modes[j+k].IRIntensity = 0;
			vibration.modes[j+k].RamanIntensity = 0.0;
			vibration.modes[j+k].symmetry = g_strdup("Unknown");
			for(c=0;c<3;c++)
				vibration.modes[j+k].vectors[c]= 
					g_malloc(vibration.numberOfAtoms*sizeof(gdouble));

		}

		for(i=0;i<vibration.numberOfAtoms;i++)
		{
    			if(!fgets(t,taille,fd)) break;
			ne = sscanf(t,"%s %s %lf %lf %lf %lf %lf %lf %lf %lf %lf",sdum1,sdum2,
					&vibration.modes[j  ].vectors[0][i],&vibration.modes[j  ].vectors[1][i],&vibration.modes[j  ].vectors[2][i],
					&vibration.modes[j+1  ].vectors[0][i],&vibration.modes[j+1  ].vectors[1][i],&vibration.modes[j+1  ].vectors[2][i],
					&vibration.modes[j+2  ].vectors[0][i],&vibration.modes[j+2  ].vectors[1][i],&vibration.modes[j+2  ].vectors[2][i]
					);
			if(ne <2)
			{
				gchar buffer[BSIZE];
				vibration.numberOfFrequences = j+nfMax;
				free_vibration();
				sprintf(buffer,"Sorry, I can not read Modes from '%s' file\n",FileName);
  				Message(buffer,"Error",TRUE);
				return FALSE;
			}
		}
		j+=nf;
	}
	vibration.numberOfFrequences = j;
	vibration.modes = g_realloc(vibration.modes,vibration.numberOfFrequences*sizeof(VibrationMode));
	OK = FALSE;
 	while(!feof(fd))
	{
		fgets(t,taille,fd);
	 	if ( strstr( t,"Frequency") && strstr( t,"Dipole Strength") )
	  	{
			OK = TRUE;
			break;
	  	}
	}
	if(OK)
	{
    		fgets(t,taille,fd);
    		fgets(t,taille,fd);
		for(i=0;i<vibration.numberOfFrequences;i++)
		{
    			if(!fgets(t,taille,fd)) break;
			ne = sscanf(t,"%s %s %s %lf",sdum1,sdum2, sdum3,&vibration.modes[i].IRIntensity);
			if(ne<3)break;
		}
	}

	return TRUE;
}
/********************************************************************************/
static void read_adf_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	gint j;
	FILE* file;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);

#ifdef G_OS_WIN32 
 	file = FOpen(FileName, "rb");
#else
	file = FOpen(FileName, "r");
#endif
	stop_vibration(NULL, NULL);
	if(!file)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return;
	}

 	if(read_adf_geom(file,FileName))
	{
		free_vibration();
		vibration.numberOfAtoms = Ncenters;
		vibration.geometry = g_malloc(Ncenters*sizeof(VibrationGeom));
		for(j=0;j<Ncenters;j++)
		{
			vibration.geometry[j].symbol = g_strdup(GeomOrb[j].Symb);
    			vibration.geometry[j].coordinates[0] = GeomOrb[j].C[0];
    			vibration.geometry[j].coordinates[1] = GeomOrb[j].C[1];
    			vibration.geometry[j].coordinates[2] = GeomOrb[j].C[2];
		}
		if(read_adf_modes(file,FileName))
		{
				rafreshList();
		}
	}
	fclose(file);
}
/********************************************************************************/
static void read_dalton_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	FILE* file;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);

 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
		Message("Sorry\n No file slected","Error",TRUE);
    		return ;
 	}

#ifdef G_OS_WIN32 
 	file = FOpen(FileName, "rb");
#else
	file = FOpen(FileName, "r");
#endif
	stop_vibration(NULL, NULL);
	if(!file)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return;
	}


	if(read_dalton_geom(file, FileName))
	{
		/* printf("OK read geom\n");*/
		if(read_dalton_modes(file,FileName)==0)
		{
				sort_vibration();
		}
		else
		{
			gchar buffer[BSIZE];
			free_vibration();
			sprintf(buffer,"Sorry, I can not read the frequencies from '%s' file\n",FileName);
  			Message(buffer,"Error",TRUE);
		}
		rafreshList();
	}
	fclose(file);
}
/********************************************************************************/
static void read_gaussian_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);

	stop_vibration(NULL, NULL);

 	gl_read_last_gauss_file(SelecFile, response_id);
	read_gaussian_file_frequencies(FileName);
}
/********************************************************************************/
static void read_dalton_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_dalton_file,
			"Read last geometry and frequencies from a Dalton output file",
			GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_gaussian_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_gaussian_file,
			"Read last geometry and frequencies from a Gaussian output file",
			GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void read_adf_file_dlg()
{
	GtkWidget* filesel = 
 	file_chooser_open(read_adf_file,
			"Read last geometry and frequencies from a ADF output file",
			GABEDIT_TYPEFILE_MOLPRO,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void save_gabedit_file(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	save_vibration_gabedit_format(FileName);
}
/********************************************************************************/
static void save_gabedit_file_dlg()
{
	GtkWidget* filesel;
	if(vibration.numberOfFrequences<1)
	{
		return;
	}

 	filesel = file_chooser_save(save_gabedit_file,
			"Save frequencies in gabedit file format",
			GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void play_vibration(GtkWidget *win, gpointer data)
{
	play = TRUE;
	gtk_widget_set_sensitive(PlayButton, FALSE); 
	gtk_widget_set_sensitive(StopButton, TRUE); 
	gtk_window_set_modal (GTK_WINDOW (WinDlg), TRUE);
	ShowVibration = FALSE;
	animate_vibration();

}
/********************************************************************************/
static void stop_vibration(GtkWidget *win, gpointer data)
{
	play = FALSE;
	if(GTK_IS_WIDGET(PlayButton))
		gtk_widget_set_sensitive(PlayButton, TRUE); 

	if(GTK_IS_WIDGET(StopButton))
		gtk_widget_set_sensitive(StopButton, FALSE); 

	if(GTK_IS_WIDGET(WinDlg))
		gtk_window_set_modal (GTK_WINDOW (WinDlg), FALSE);

	while( gtk_events_pending() )
		gtk_main_iteration();

	reset_geom_vibration();
	RebuildGeom = TRUE;
	ShowVibration = TRUE;
	Dipole.def = FALSE;
	init_atomic_orbitals();
	free_iso_all();
	if(this_is_an_object((GtkObject*)GLArea))
		glarea_rafresh(GLArea);
}
/********************************************************************************/
static void destroyDlg(GtkWidget *win, gpointer data)
{
	createBMPFiles = FALSE;
	numBMPFile = 0;
	createPPMFiles = FALSE;
	numPPMFile = 0;
	createPOVFiles = FALSE;
	numPOVFile = 0;

	delete_child(WinDlg);
}
/********************************************************************************/
static void destroyVibrationDlg(GtkWidget *win)
{
	createBMPFiles = FALSE;
	numBMPFile = 0;
	createPPMFiles = FALSE;
	numPPMFile = 0;

	createPOVFiles = FALSE;
	numPOVFile = 0;

	stop_vibration(NULL, NULL);
	gtk_widget_destroy(WinDlg);
	WinDlg = NULL;
	rowSelected = -1;
	ShowVibration = FALSE;

}
/**********************************************************************************/
static void set_sensitive_option(GtkUIManager *manager, gchar* path)
{
	GtkWidget *wid = gtk_ui_manager_get_widget (manager, path);
	gboolean sensitive = TRUE;
  	if(vibration.numberOfAtoms<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(wid)) gtk_widget_set_sensitive(wid, sensitive);
}
/**********************************************************************************/
static gboolean show_menu_popup(GtkUIManager *manager, guint button, guint32 time)
{
	GtkWidget *menu = gtk_ui_manager_get_widget (manager, "/MenuVibration");
	if (GTK_IS_MENU (menu)) 
	{
		set_sensitive_option(manager,"/MenuVibration/DrawSpectrum");
		set_sensitive_option(manager,"/MenuVibration/SaveGabedit");
		gtk_menu_popup (GTK_MENU (menu), NULL, NULL, NULL, NULL, button, time);
		return TRUE;
	}
	else printf("Erreur menu n'est pas un menu\n");
	return FALSE;
}
/********************************************************************************/
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
	if(!play) stop_vibration(NULL, NULL);

  	if (event->type == GDK_BUTTON_PRESS && ((GdkEventButton *) event)->button == 3)
	{
		GdkEventButton *bevent = (GdkEventButton *) event;
		GtkUIManager *manager = GTK_UI_MANAGER(user_data);
		show_menu_popup(manager, bevent->button, bevent->time);
	}
}
/********************************************************************************/
static void rafreshList()
{
	gint i;
  	gchar *texts[4];
	gint k;

        GtkTreeIter iter;
	GtkTreeModel *model = gtk_tree_view_get_model(treeView);
        GtkTreeStore *store = GTK_TREE_STORE (model);
  
	gtk_tree_store_clear(store);
        model = GTK_TREE_MODEL (store);

	for(i=0;i<vibration.numberOfFrequences;i++)
	{
		texts[0] = g_strdup_printf("%0.4f",vibration.modes[i].frequence);
		texts[1] = g_strdup(vibration.modes[i].symmetry);
		texts[2] = g_strdup_printf("%0.4f",vibration.modes[i].IRIntensity);
		texts[3] = g_strdup_printf("%0.4f",vibration.modes[i].RamanIntensity);
        	gtk_tree_store_append (store, &iter, NULL);
		/*
        	gtk_tree_store_set (store, &iter, 0, texts[0], 1, texts[1], 2, texts[2], 3, texts[3], -1);
		*/

		for(k=0;k<4;k++)
		{
        		gtk_tree_store_set (store, &iter, k, texts[k], -1);
			g_free(texts[k]);
		}
	}
	if(vibration.numberOfFrequences>0)
	{
		GtkTreePath *path;
		rowSelected = 0;
		path = gtk_tree_path_new_from_string  ("0");
		gtk_tree_selection_select_path  (gtk_tree_view_get_selection (GTK_TREE_VIEW (treeView)), path);
		gtk_tree_path_free(path);
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
/*****************************************************************/
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

	i=0;
	add_label_table(table," Scale factor ",(gushort)i,0);
	add_label_table(table," : ",(gushort)i,1); 
	EntryScal = gtk_entry_new();
	gtk_table_attach(GTK_TABLE(table),EntryScal,2,2+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	gtk_editable_set_editable((GtkEditable*) EntryScal,TRUE);
	sprintf(t,"%f",vibration.scal);
	gtk_entry_set_text(GTK_ENTRY(EntryScal),t);

	i++;
	add_label_table(table," Time step(s) ",(gushort)i,0);
	add_label_table(table," : ",(gushort)i,1); 
	EntryVelocity = gtk_entry_new();
	gtk_table_attach(GTK_TABLE(table),EntryVelocity,2,2+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	gtk_editable_set_editable((GtkEditable*) EntryVelocity,TRUE);
	sprintf(t,"%f",vibration.velocity);
	gtk_entry_set_text(GTK_ENTRY(EntryVelocity),t);

	i++;
	add_label_table(table," Arrow radius ",(gushort)i,0);
	add_label_table(table," : ",(gushort)i,1); 
	EntryRadius = gtk_entry_new();
	gtk_table_attach(GTK_TABLE(table),EntryRadius,2,2+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	gtk_editable_set_editable((GtkEditable*) EntryRadius,TRUE);
	sprintf(t,"%f",vibration.radius);
	gtk_entry_set_text(GTK_ENTRY(EntryRadius),t);

	i++;
	LabelNSteps = add_label_table(table," Steps by cycle ",(gushort)i,0);
	add_label_table(table," : ",(gushort)i,1); 
	EntryNSteps = gtk_entry_new();
	gtk_table_attach(GTK_TABLE(table),EntryNSteps,2,2+1,i,i+1,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
		  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
		  3,3);
	gtk_editable_set_editable((GtkEditable*) EntryNSteps,TRUE);
	sprintf(t,"%d",vibration.nSteps);
	gtk_entry_set_text(GTK_ENTRY(EntryNSteps),t);

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

  	g_signal_connect(G_OBJECT(PlayButton), "clicked",(GtkSignalFunc)play_vibration,NULL);
  	g_signal_connect(G_OBJECT(StopButton), "clicked",(GtkSignalFunc)stop_vibration,NULL);
  	g_signal_connect_swapped(G_OBJECT (EntryScal), "activate", (GtkSignalFunc)reset_parameters, NULL);
  	g_signal_connect_swapped(G_OBJECT (EntryVelocity), "activate", (GtkSignalFunc)reset_parameters, NULL);
  	g_signal_connect_swapped(G_OBJECT (EntryRadius), "activate", (GtkSignalFunc)reset_parameters, NULL);
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
	gint widths[]={10,10,10,10};
	gchar* titles[]={"Frequence","Symmetry","IR Int.","Raman Int"};
	gint Factor=7;
	gint len = 4;


	for(i=0;i<len;i++) widall+=widths[i];

	widall=widall*Factor+40;

	scr=gtk_scrolled_window_new(NULL,NULL);
	gtk_widget_set_size_request(scr,widall,(gint)(ScreenHeight*0.45));
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scr),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC); 
	gtk_box_pack_start(GTK_BOX (vbox), scr,TRUE, TRUE, 2);

	store = gtk_tree_store_new (4,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
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
		renderer = gtk_cell_renderer_text_new ();
		gtk_tree_view_column_pack_start (column, renderer, TRUE);
		gtk_tree_view_column_set_attributes (column, renderer, "text", i, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (treeView), column);
	}
  
	set_base_style(GTK_WIDGET(treeView), 55000,55000,55000);
	gtk_widget_show (GTK_WIDGET(treeView));
  	g_signal_connect(G_OBJECT (treeView), "button_press_event", GTK_SIGNAL_FUNC(event_dispatcher), manager);      
	return treeView;
}
/*****************************************************************************/
static gboolean createImageFile()
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
static void animate_vibration()
{

	gint m = rowSelected;
	gint j = 0;
	gdouble k = -1;
	gdouble step = 0.5;


	reset_parameters(NULL, NULL);
	step = 2.0/vibration.nSteps;

	numFileFilm = 0;

	if(GTK_IS_WIDGET(buttonCheckFilm)) gtk_widget_set_sensitive(buttonCheckFilm, FALSE);
	if(GTK_IS_WIDGET(comboListFilm)) gtk_widget_set_sensitive(comboListFilm, FALSE);
	if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);

	if(GTK_IS_WIDGET(EntryNSteps))  gtk_widget_set_sensitive(EntryNSteps, FALSE);
	if(GTK_IS_WIDGET(LabelNSteps))  gtk_widget_set_sensitive(LabelNSteps, FALSE);

	if(GeomOrb) free_atomic_orbitals();

	while(play)
	{
		while( gtk_events_pending() ) gtk_main_iteration();

		if(GeomOrb)
		{
			for(j=0;j<Ncenters;j++) if(GeomOrb[j].Symb) g_free(GeomOrb[j].Symb);
			g_free(GeomOrb);
			GeomOrb = NULL;
		}
		m = rowSelected;
		if(m<0)
		{
			stop_vibration(NULL, NULL);
			break;
		}

		Ncenters = vibration.numberOfAtoms;
		GeomOrb=g_malloc(Ncenters*sizeof(TypeGeomOrb));
		for(j=0;j<Ncenters;j++)
		{
    			GeomOrb[j].Symb=g_strdup(vibration.geometry[j].symbol);
    			GeomOrb[j].C[0] = vibration.geometry[j].coordinates[0]
				+k*vibration.scal*vibration.modes[m].vectors[0][j];

    			GeomOrb[j].C[1] = vibration.geometry[j].coordinates[1]
				+k*vibration.scal*vibration.modes[m].vectors[1][j];

    			GeomOrb[j].C[2] = vibration.geometry[j].coordinates[2]
				+k*vibration.scal*vibration.modes[m].vectors[2][j];

    			GeomOrb[j].Prop = prop_atom_get(GeomOrb[j].Symb);
			GeomOrb[j].Prop.covalentRadii *=1.2;
		}
		init_atomic_orbitals();

		RebuildGeom = TRUE;
		glarea_rafresh(GLArea);
		createImageFile();
		Waiting(vibration.velocity);
		k += step;
		if(k>1 || k<-1)
		{
			k -= step;
			step = - step;
			k += step;
		}
		if(fabs(k+1)<1e-8)
		{
			if(numFileFilm>0) showMessageEnd();
			unActivateFilm();
		}

	}

	if(numFileFilm>0) showMessageEnd();
	unActivateFilm();

	if(GTK_IS_WIDGET(buttonCheckFilm)) gtk_widget_set_sensitive(buttonCheckFilm, TRUE);
	if(GTK_IS_WIDGET(comboListFilm)) gtk_widget_set_sensitive(comboListFilm, FALSE);
	if(GTK_IS_WIDGET(buttonDirFilm))  gtk_widget_set_sensitive(buttonDirFilm, FALSE);

	if(GTK_IS_WIDGET(EntryNSteps))  gtk_widget_set_sensitive(EntryNSteps, TRUE);
	if(GTK_IS_WIDGET(LabelNSteps))  gtk_widget_set_sensitive(LabelNSteps, TRUE);
	stop_vibration(NULL, NULL);
}
/********************************************************************************************/
static void help_supported_format()
{
	gchar temp[BSIZE];
	GtkWidget* win;
	sprintf(temp,
		" You can read frequencies and normal modes from :\n"
	        "     * a Gabedit input file.\n"
	        "     * a Gaussian (g98 and g03) output file.\n"
	        "     * a Molpro output file.\n"
	        "     * a MPQC output file.\n"
	        "     * a ADF output file. Only the 2004 version of ADF is supported\n"
	        "     * a Molden input file.\n"
		 );
	win = Message(temp," Info ",FALSE);
	gtk_window_set_modal (GTK_WINDOW (win), TRUE);
}
/***************************************************************************/
static void help_animated_file()
{
	gchar* temp = NULL;
	GtkWidget* win;
	temp = g_strdup(
		" For create an animated file :\n"
		" ============================\n"
	        "   1) Read frequencies and normal modes from a Gaussian, Molpro, Gabedit, Molden, ADF or MPQC output file.\n"
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
	}
	else if(!strcmp(name, "Tools"))
	{
		GtkUIManager *manager = g_object_get_data(G_OBJECT(action), "Manager");
		if(GTK_IS_UI_MANAGER(manager)) set_sensitive_option(manager,"/MenuBar/Tools/DrawSpectrum");
	}
	else if(!strcmp(name, "ReadGabedit")) read_gabedit_file_dlg();
	else if(!strcmp(name, "ReadDalton")) read_dalton_file_dlg();
	else if(!strcmp(name, "ReadGaussian")) read_gaussian_file_dlg();
	else if(!strcmp(name, "ReadMolpro")) read_molpro_file_dlg();
	else if(!strcmp(name, "ReadMPQC")) read_mpqc_file_dlg();
	else if(!strcmp(name, "ReadADF")) read_adf_file_dlg();
	else if(!strcmp(name, "ReadMolden")) read_molden_file_dlg();
	else if(!strcmp(name, "SaveGabedit")) save_gabedit_file_dlg();
	else if(!strcmp(name, "Close")) destroyDlg(NULL,NULL);
	else if(!strcmp(name, "DrawSpectrum")) create_window_spectrum();
	else if(!strcmp(name, "HelpSupportedFormat")) help_supported_format();
	else if(!strcmp(name, "HelpAnimation")) help_animated_file();
}
/*********************************************************************************************************************/
static GtkActionEntry gtkActionEntries[] =
{
	{"File",     NULL, "_File", NULL, NULL, G_CALLBACK (activate_action)},
	{"Read",     NULL, "_Read"},
	{"ReadGabedit", GABEDIT_STOCK_GABEDIT, "Read a G_abedit file", NULL, "Read a Gabedit file", G_CALLBACK (activate_action) },
	{"ReadDalton", GABEDIT_STOCK_DALTON, "Read a _Dalton output file", NULL, "Read a Dalton output file", G_CALLBACK (activate_action) },
	{"ReadGaussian", GABEDIT_STOCK_GAUSSIAN, "Read a _Gaussian output file", NULL, "Read a Gaussian output file", G_CALLBACK (activate_action) },
	{"ReadMolpro", GABEDIT_STOCK_MOLPRO, "Read a Mol_pro output file", NULL, "Read Molpro output file", G_CALLBACK (activate_action) },
	{"ReadMPQC", GABEDIT_STOCK_MPQC, "Read a MP_QC output file", NULL, "Read a MPQC output file", G_CALLBACK (activate_action) },
	{"ReadADF", GABEDIT_STOCK_ADF, "Read a _ADF output file", NULL, "Read a ADF output file", G_CALLBACK (activate_action) },
	{"ReadMolden", GABEDIT_STOCK_MOLDEN, "Read a Mol_den output file", NULL, "Read a Molden file", G_CALLBACK (activate_action) },
	{"SaveGabedit", GABEDIT_STOCK_SAVE, "_Save", NULL, "Save", G_CALLBACK (activate_action) },
	{"Close", GABEDIT_STOCK_CLOSE, "_Close", NULL, "Close", G_CALLBACK (activate_action) },
	{"Tools",     NULL, "_Tools", NULL, NULL, G_CALLBACK (activate_action)},
	{"DrawSpectrum", GABEDIT_STOCK_DRAW, "Draw _Spectrum", NULL, "Draw Spectrum", G_CALLBACK (activate_action) },
	{"Help",     NULL, "_Help"},
	{"HelpSupportedFormat", NULL, "_Supported format...", NULL, "Supported format...", G_CALLBACK (activate_action) },
	{"HelpAnimation", NULL, "Creation of an _animated file...", NULL, "Creation of an animated file...", G_CALLBACK (activate_action) },
};
static guint numberOfGtkActionEntries = G_N_ELEMENTS (gtkActionEntries);
/********************************************************************************/
/* XML description of the menus for the test app.  The parser understands
 * a subset of the Bonobo UI XML format, and uses GMarkup for parsing */
static const gchar *uiMenuInfo =
"  <popup name=\"MenuVibration\">\n"
"    <separator name=\"sepMenuPopGabedit\" />\n"
"    <menuitem name=\"ReadGabedit\" action=\"ReadGabedit\" />\n"
"    <menuitem name=\"ReadDalton\" action=\"ReadDalton\" />\n"
"    <menuitem name=\"ReadGaussian\" action=\"ReadGaussian\" />\n"
"    <menuitem name=\"ReadMolpro\" action=\"ReadMolpro\" />\n"
"    <menuitem name=\"ReadMPQC\" action=\"ReadMPQC\" />\n"
"    <menuitem name=\"ReadADF\" action=\"ReadADF\" />\n"
"    <menuitem name=\"ReadMolden\" action=\"ReadMolden\" />\n"
"    <separator name=\"sepMenuPopSave\" />\n"
"    <menuitem name=\"SaveGabedit\" action=\"SaveGabedit\" />\n"
"    <separator name=\"sepMenuPopDraw\" />\n"
"    <menuitem name=\"DrawSpectrum\" action=\"DrawSpectrum\" />\n"
"    <separator name=\"sepMenuPopClose\" />\n"
"    <menuitem name=\"Close\" action=\"Close\" />\n"
"  </popup>\n"
"  <menubar name = \"MenuBar\">\n"
"    <menu name=\"File\" action=\"File\">\n"
"      <menu name=\"Read\" action=\"Read\">\n"
"        <menuitem name=\"ReadGabedit\" action=\"ReadGabedit\" />\n"
"        <menuitem name=\"ReadDalton\" action=\"ReadDalton\" />\n"
"        <menuitem name=\"ReadGaussian\" action=\"ReadGaussian\" />\n"
"        <menuitem name=\"ReadMolpro\" action=\"ReadMolpro\" />\n"
"        <menuitem name=\"ReadMPQC\" action=\"ReadMPQC\" />\n"
"        <menuitem name=\"ReadADF\" action=\"ReadADF\" />\n"
"        <menuitem name=\"ReadMolden\" action=\"ReadMolden\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuSave\" />\n"
"      <menuitem name=\"SaveGabedit\" action=\"SaveGabedit\" />\n"
"      <separator name=\"sepMenuClose\" />\n"
"      <menuitem name=\"Close\" action=\"Close\" />\n"
"    </menu>\n"
"      <menu name=\"Tools\" action=\"Tools\">\n"
"         <menuitem name=\"DrawSpectrum\" action=\"DrawSpectrum\" />\n"
"      </menu>\n"
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

	actionGroup = gtk_action_group_new ("GabeditVibrationActions");
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
		action = gtk_ui_manager_get_action(manager, "/MenuBar/Tools");
		if(G_IS_OBJECT(action)) g_object_set_data(G_OBJECT(action), "Manager", manager);
	}
	return manager;
}
/********************************************************************************/
void vibrationDlg()
{
	GtkWidget *Win;
	GtkWidget *vbox;
	GtkWidget *hbox;
	GtkUIManager *manager = NULL;
	/*
	GtkWidget *button;
	GtkWidget *menuButton;
	*/
	GtkWidget *parentWindow = PrincipalWindow;

	if(WinDlg)
		return;

	Win= gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(parentWindow));
	gtk_window_set_default_size (GTK_WINDOW(Win),-1,(gint)(ScreenHeight*0.69));
	gtk_window_set_title(GTK_WINDOW(Win),"Vibration");
	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	WinDlg = Win;

  	add_child(PrincipalWindow,Win,destroyVibrationDlg,"Vibration");
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
	stop_vibration(NULL, NULL);
}
