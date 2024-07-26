/* MolecularMechanicsDlg.c */
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


#include <stdlib.h>
#include <math.h>
#include "../../Config.h"
#include "../Common/Global.h"
#include "../Utils/UtilsInterface.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/Mesure.h"
#include "../Files/FolderChooser.h"
#include "../Files/GabeditFolderChooser.h"
#include "../MolecularMechanics/Atom.h"
#include "../MolecularMechanics/Molecule.h"
#include "../MolecularMechanics/ForceField.h"
#include "../MolecularMechanics/MolecularMechanics.h"
#include "../MolecularMechanics/ConjugateGradient.h"
#include "../MolecularMechanics/SteepestDescent.h"
#include "../MolecularMechanics/QuasiNewton.h"
#include "../MolecularMechanics/MolecularDynamics.h"

void dessine();

typedef enum
{
	MMBOND = 0,
	MMBEND = 1,
	MMTORSION = 2,
	MMIMPROPER = 3,
	MMNONBOND = 4,
	MMHBOND  =5 ,
	MMCOULOMB = 6,
	PWCOULOMB = 7,
	PWVANDERWALS = 8
} MMOptions;

typedef enum
{
	GRADQUASINEWTON  = 0,
	GRADSTEEPEST  = 1,
	GRADCONJUGATE = 2,
	GRADHESTENES  = 3,
	GRADFLETCHER  = 4,
	GRADPOLAK     = 5,
	GRADWOLF      = 6
} GradientOptions;

typedef enum
{
	GRADMAXITERATIONS  = 0,
	GRADEPSILON        = 1,
	GRADMAXLINES       = 2,
	GRADINITIALSTEP    = 3,
	GRADFREQUENCY      = 4
} GradientEntrys;

#define NGRADENTRYS 5
#define NGRADOPTIONS 7
#define NOPTIONS1 4
#define NOPTIONS2 3
#define NOPTIONS3 2
#define NINTEGOPTIONS 3
#define NTHERMOPTIONS 3

static	GtkWidget* buttonTypesOptions[3];
static	GtkWidget* buttonMMOptions[NOPTIONS1+NOPTIONS2+NOPTIONS3];
static	GtkWidget* buttonMinimizeOptions[NGRADOPTIONS];
static	GtkWidget* buttonMDOptions[NINTEGOPTIONS];
static	GtkWidget* buttonMDThermOptions[NTHERMOPTIONS];
static	GtkWidget* entryMinimizeOptions[NGRADENTRYS];
static	GtkWidget* frameAmber = NULL;
static	GtkWidget* framePairWise = NULL;
static 	GtkWidget* entryMDTimes[4];
static 	GtkWidget* entryMDTemperature[4];
static 	GtkWidget* entryMDStepSize;
static 	GtkWidget* entryMDRafresh;

static 	GtkWidget* entrySDFriction;
static 	GtkWidget* entrySDCollide;

static  GtkWidget* entryFileNameTraj = NULL;
static  GtkWidget* entryFileNameProp = NULL;
static  GtkWidget* buttonSaveTraj = NULL;
static  GtkWidget* buttonSaveProp = NULL;
static  GtkWidget* buttonDirSelector = NULL;

/*****************************************************************************/
static void amberMolecularDynamics(GtkWidget* Win, gpointer data)
{
	ForceField forceField; 
	ForceFieldOptions forceFieldOptions;
	MolecularDynamics molecularDynamics;
	gint updateFrequency = 1;
	gdouble heatTime;
	gdouble equiTime;
	gdouble runTime;
	gdouble coolTime; 
	gdouble heatTemp; 
	gdouble equiTemp; 
	gdouble runTemp; 
	gdouble coolTemp; 
	gdouble stepSize;
	MDIntegratorType integrator = VERLET;
	gchar* fileNameTraj = NULL;
	gchar* fileNameProp = NULL;
	gdouble friction=40;
	gdouble collide = 20;
	MDThermostatType thermostat = NONE;


	forceFieldOptions.type = AMBER;
	forceFieldOptions.bondStretch = GTK_TOGGLE_BUTTON (buttonMMOptions[MMBOND])->active;
	forceFieldOptions.angleBend = GTK_TOGGLE_BUTTON (buttonMMOptions[MMBEND])->active;
	forceFieldOptions.dihedralAngle = GTK_TOGGLE_BUTTON (buttonMMOptions[MMTORSION])->active;
	forceFieldOptions.improperTorsion = GTK_TOGGLE_BUTTON (buttonMMOptions[MMIMPROPER])->active;
	forceFieldOptions.nonBonded = GTK_TOGGLE_BUTTON (buttonMMOptions[MMNONBOND])->active;
	forceFieldOptions.hydrogenBonded = GTK_TOGGLE_BUTTON (buttonMMOptions[MMHBOND])->active;
	forceFieldOptions.coulomb = GTK_TOGGLE_BUTTON (buttonMMOptions[MMCOULOMB])->active;
	forceFieldOptions.vanderWals = GTK_TOGGLE_BUTTON (buttonMMOptions[PWVANDERWALS])->active;
	if(GTK_TOGGLE_BUTTON (buttonTypesOptions[AMBER])->active )
		forceFieldOptions.type = AMBER;
	else
	if(GTK_TOGGLE_BUTTON (buttonTypesOptions[PAIRWISE])->active )
	{
		forceFieldOptions.coulomb = GTK_TOGGLE_BUTTON (buttonMMOptions[PWCOULOMB])->active;
		forceFieldOptions.type = PAIRWISE;
	}

	updateFrequency = atoi(gtk_entry_get_text(GTK_ENTRY(entryMDRafresh)));
	if(updateFrequency<0) updateFrequency = 0;

	heatTime = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTimes[0])));
	equiTime = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTimes[1])));
	runTime = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTimes[2])));
	coolTime = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTimes[3])));

	heatTemp = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTemperature[0])));
	equiTemp = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTemperature[1])));
	runTemp = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTemperature[2])));
	coolTemp = atof(gtk_entry_get_text(GTK_ENTRY(entryMDTemperature[3])));

	stepSize = atof(gtk_entry_get_text(GTK_ENTRY(entryMDStepSize)));


	if(GTK_TOGGLE_BUTTON (buttonMDOptions[BEEMAN])->active) integrator = BEEMAN;
	if(GTK_TOGGLE_BUTTON (buttonMDOptions[STOCHASTIC])->active) integrator = STOCHASTIC;

	if(GTK_TOGGLE_BUTTON (buttonMDThermOptions[ANDERSEN])->active) thermostat = ANDERSEN;
	if(GTK_TOGGLE_BUTTON (buttonMDThermOptions[BERENDSEN])->active) thermostat = BERENDSEN;

	if( integrator == STOCHASTIC)
		friction = atof(gtk_entry_get_text(GTK_ENTRY(entrySDFriction)));

	collide = atof(gtk_entry_get_text(GTK_ENTRY(entrySDCollide)));

	if(heatTime<0) heatTime = 1;
	if(equiTime<0) equiTime = 1;
	if(runTime<0) runTime = 1;
	if(coolTime<0) coolTime = 4;

	if(heatTemp<0) heatTemp = 0;
	if(equiTemp<0) runTemp = 300;
	if(runTemp<0) runTemp = 300;
	if(coolTemp<0) coolTemp = 0;

	if(stepSize<0) stepSize = 1.0;
	if(stepSize>5) stepSize = 5.0;

	if(GTK_TOGGLE_BUTTON (buttonSaveTraj)->active)
	{
		gchar* dirName = gtk_file_chooser_get_current_folder (GTK_FILE_CHOOSER(buttonDirSelector));
		gchar* tmp = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryFileNameTraj)));
		if(dirName[strlen(dirName)-1] != G_DIR_SEPARATOR)
			fileNameTraj = g_strdup_printf("%s%s%s",dirName, G_DIR_SEPARATOR_S,tmp);
		else
			fileNameTraj = g_strdup_printf("%s%s",dirName, tmp);


		g_free(tmp);
		g_free(dirName);
	}
	if(GTK_TOGGLE_BUTTON (buttonSaveProp)->active)
	{
		gchar* dirName = gtk_file_chooser_get_current_folder (GTK_FILE_CHOOSER(buttonDirSelector));
		gchar* tmp = g_strdup(gtk_entry_get_text(GTK_ENTRY(entryFileNameProp)));
		if(dirName[strlen(dirName)-1] != G_DIR_SEPARATOR)
			fileNameProp = g_strdup_printf("%s%s%s",dirName, G_DIR_SEPARATOR_S,tmp);
		else
			fileNameProp = g_strdup_printf("%s%s",dirName, tmp);
		g_free(tmp);
		g_free(dirName);
		printf("fileNameProp = %s\n", fileNameProp);
	}



	gtk_widget_destroy(Win);
    	while( gtk_events_pending() ) gtk_main_iteration();

	gtk_widget_set_sensitive(StopButton, TRUE);
	StopCalcul = FALSE;

	if(forceFieldOptions.type==AMBER)
		forceField = createAmberModel(geometry0,Natoms,forceFieldOptions);
	else
	if(forceFieldOptions.type==PAIRWISE)
		forceField = createPairWiseModel(geometry0,Natoms,forceFieldOptions);

	if(StopCalcul)
	{
		set_text_to_draw(" ");
		set_statubar_operation_str("Calcul Canceled ");
		dessine();
		gtk_widget_set_sensitive(StopButton, FALSE);
		return;
	}


	gtk_widget_set_sensitive(StopButton, TRUE);
	{
		gint i;
		for(i=0;i<4;i++) NumSelAtoms[i] = -1;
		change_of_center(NULL,NULL);
	}

	runMolecularDynamics(&molecularDynamics, &forceField,
		updateFrequency, heatTime, equiTime, runTime, coolTime, heatTemp, equiTemp, runTemp, coolTemp, stepSize, 
		integrator, thermostat, friction, collide, fileNameTraj, fileNameProp);

	if(StopCalcul)
	{
		set_text_to_draw(" ");
		set_statubar_operation_str("Calcul canceled");
		dessine();
	}
	gtk_widget_set_sensitive(StopButton, FALSE);
	set_text_to_draw(" ");
	freeForceField(&forceField);
}
/********************************************************************************/
static void AddDynamicsOptionsDlg(GtkWidget *NoteBook, GtkWidget *win)
{

	gint i;
	gint j;
	GtkWidget *frame;
	GtkWidget *LabelOnglet;
	GtkWidget *LabelMenu;
	GtkWidget *vbox;
	GtkWidget *table;
	GtkWidget* label;
	GtkWidget *hseparator = NULL;

	frame = gtk_frame_new(NULL);
	gtk_container_set_border_width(GTK_CONTAINER(frame), 5);

	LabelOnglet = gtk_label_new("Molecular Dynamics Options");
	LabelMenu = gtk_label_new("Molecular Dynamics Options");
	gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook), frame,LabelOnglet, LabelMenu);
	g_object_set_data (G_OBJECT (frame), "frame", frame);

	vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox);
	gtk_container_add (GTK_CONTAINER (frame), vbox);

	table = gtk_table_new(16,6,FALSE);
	gtk_box_pack_start (GTK_BOX (vbox), table, TRUE, TRUE, 0);

/*----------------------------------------------------------------------------------*/
	i = 0;
	j = 2;
	label = gtk_label_new("Heating");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 0;
	j = 3;
	label = gtk_label_new("Equilibrium");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 0;
	j = 4;
	label = gtk_label_new("Production");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 0;
	j = 5;
	label = gtk_label_new("Cooling");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 0;
	label = gtk_label_new("Time (ps)");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 2;
	entryMDTimes[0] = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entryMDTimes[0]),"1.0");
	gtk_widget_set_size_request(entryMDTimes[0], 60, -1);
	gtk_table_attach(GTK_TABLE(table),entryMDTimes[0], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 3;
	entryMDTimes[1] = gtk_entry_new();
	gtk_widget_set_size_request(entryMDTimes[1], 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDTimes[1]),"1.0");
	gtk_table_attach(GTK_TABLE(table),entryMDTimes[1], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 4;
	entryMDTimes[2] = gtk_entry_new();
	gtk_widget_set_size_request(entryMDTimes[2], 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDTimes[2]),"4.0");
	gtk_table_attach(GTK_TABLE(table),entryMDTimes[2], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 5;
	entryMDTimes[3] = gtk_entry_new();
	gtk_widget_set_size_request(entryMDTimes[3], 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDTimes[3]),"4.0");
	gtk_table_attach(GTK_TABLE(table),entryMDTimes[3], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 0;
	label = gtk_label_new("Temperature (K)");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 2;
	entryMDTemperature[0] = gtk_entry_new();
	gtk_entry_set_text(GTK_ENTRY(entryMDTemperature[0]),"0.0");
	gtk_widget_set_size_request(entryMDTemperature[0], 60, -1);
	gtk_table_attach(GTK_TABLE(table),entryMDTemperature[0], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 3;
	entryMDTemperature[1] = gtk_entry_new();
	gtk_widget_set_size_request(entryMDTemperature[1], 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDTemperature[1]),"300.0");
	gtk_table_attach(GTK_TABLE(table),entryMDTemperature[1], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 4;
	entryMDTemperature[2] = gtk_entry_new();
	gtk_widget_set_size_request(entryMDTemperature[2], 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDTemperature[2]),"300.0");
	gtk_table_attach(GTK_TABLE(table),entryMDTemperature[2], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 5;
	entryMDTemperature[3] = gtk_entry_new();
	gtk_widget_set_size_request(entryMDTemperature[3], 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDTemperature[3]),"0.0");
	gtk_table_attach(GTK_TABLE(table),entryMDTemperature[3], j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 3;
	j = 0;
	label = gtk_label_new("Step size (fs)");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 3;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 3;
	j = 2;
	entryMDStepSize = gtk_entry_new();
	gtk_widget_set_size_request(entryMDStepSize, 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDStepSize),"1.0");
	gtk_table_attach(GTK_TABLE(table),entryMDStepSize, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 4;
	j = 0;
	label = gtk_label_new("Screen Rafresh after");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 4;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 4;
	j = 2;
	entryMDRafresh = gtk_entry_new();
	gtk_widget_set_size_request(entryMDRafresh, 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryMDRafresh),"5");
	gtk_table_attach(GTK_TABLE(table),entryMDRafresh, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 4;
	j = 3;
	label = gtk_label_new("steps");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 5;
	j = 0;
	label = gtk_label_new("Collide(ps^-1)");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 5;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 5;
	j = 2;
	entrySDCollide = gtk_entry_new();
	gtk_widget_set_size_request(entrySDCollide, 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entrySDCollide),"20.0");
	gtk_table_attach(GTK_TABLE(table),entrySDCollide, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 6;
	j = 0;
	label = gtk_label_new("Friction(ps^-1)");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 6;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 6;
	j = 2;
	entrySDFriction = gtk_entry_new();
	gtk_widget_set_size_request(entrySDFriction, 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entrySDFriction),"40.0");
	gtk_table_attach(GTK_TABLE(table),entrySDFriction, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	/* THERMOSTAT */
/*----------------------------------------------------------------------------------*/
	i = 3;
	j = 4;
	buttonMDThermOptions[NONE]= gtk_radio_button_new_with_label( NULL, "NVE"); 
	gtk_table_attach(GTK_TABLE(table),buttonMDThermOptions[NONE],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMDThermOptions[NONE]), TRUE);
/*----------------------------------------------------------------------------------*/
	i = 4;
	j = 4;
	buttonMDThermOptions[BERENDSEN]= gtk_radio_button_new_with_label(gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMDThermOptions[NONE])), "Berendsen"); 
	gtk_table_attach(GTK_TABLE(table),buttonMDThermOptions[BERENDSEN],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMDThermOptions[BERENDSEN]), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 5;
	j = 4;
	buttonMDThermOptions[ANDERSEN]= gtk_radio_button_new_with_label(gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMDThermOptions[NONE])), "Andersen"); 
	gtk_table_attach(GTK_TABLE(table),buttonMDThermOptions[ANDERSEN],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMDThermOptions[ANDERSEN]), FALSE);
/*----------------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------------*/
	i = 7;
	j = 0;
	hseparator = gtk_hseparator_new ();
	gtk_table_attach(GTK_TABLE(table),hseparator, j,j+6,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 8;
	j = 0;
	buttonMDOptions[VERLET]= gtk_radio_button_new_with_label( NULL, "MD Trajectory via Verlet velocity Algorithm"); 
	gtk_table_attach(GTK_TABLE(table),buttonMDOptions[VERLET],
			j,j+4,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMDOptions[VERLET]), TRUE);
/*----------------------------------------------------------------------------------*/
	i = 9;
	j = 0;
	buttonMDOptions[BEEMAN]= gtk_radio_button_new_with_label(gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMDOptions[VERLET])), "MD Trajectory via Modified Beeman Algorithm"); 
	gtk_table_attach(GTK_TABLE(table),buttonMDOptions[BEEMAN],
			j,j+4,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMDOptions[BEEMAN]), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 10;
	j = 0;
	buttonMDOptions[STOCHASTIC]= gtk_radio_button_new_with_label(gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMDOptions[VERLET])), "Stochastic Dynamics via Verlet velocity Algorithm"); 
	gtk_table_attach(GTK_TABLE(table),buttonMDOptions[STOCHASTIC],
			j,j+4,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMDOptions[STOCHASTIC]), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 11;
	j = 0;
	hseparator = gtk_hseparator_new ();
	gtk_table_attach(GTK_TABLE(table),hseparator, j,j+6,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 12;
	j = 0;
	buttonSaveTraj = gtk_check_button_new_with_label("Save Trajectory in "); 
	gtk_table_attach(GTK_TABLE(table),buttonSaveTraj,
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonSaveTraj), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 12;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 12;
	j = 2;
	entryFileNameTraj = gtk_entry_new();
	gtk_widget_set_size_request(entryFileNameTraj, 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryFileNameTraj),"traj.gab");
	gtk_table_attach(GTK_TABLE(table),entryFileNameTraj, j,j+4,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 13;
	j = 0;
	buttonSaveProp = gtk_check_button_new_with_label("Save Properties in "); 
	gtk_table_attach(GTK_TABLE(table),buttonSaveProp,
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonSaveProp), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 13;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 13;
	j = 2;
	entryFileNameProp = gtk_entry_new();
	gtk_widget_set_size_request(entryFileNameProp, 60, -1);
	gtk_entry_set_text(GTK_ENTRY(entryFileNameProp),"prop.txt");
	gtk_table_attach(GTK_TABLE(table),entryFileNameProp, j,j+4,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 14;
	j = 0;
	label = gtk_label_new("Folder");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 14;
	j = 1;
	label = gtk_label_new(":");
	gtk_table_attach(GTK_TABLE(table),label, j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 14;
	j = 2;
	buttonDirSelector =  gtk_file_chooser_button_new("Select your folder", GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER);
	gtk_table_attach(GTK_TABLE(table),buttonDirSelector,
			j,j+4,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
}
/*****************************************************************************/
static void amberMinimize(GtkWidget* Win, gpointer data)
{
	ForceField forceField; 
	ForceFieldOptions forceFieldOptions;
	SteepestDescent steepestDescent;
	ConjugateGradient conjugateGradient;
	QuasiNewton quasiNewton;
	gboolean useConjugateGradient;
	gboolean useQuasiNewton;
	ConjugateGradientOptions conjugateGradientOptions;

	conjugateGradientOptions.gradientNorm = 1e-3;
	conjugateGradientOptions.maxIterations = 100;
	conjugateGradientOptions.updateFrequency = 1;
	conjugateGradientOptions.maxLines = 25;
	conjugateGradientOptions.initialStep = 0.001;
	conjugateGradientOptions.method = 1;

	forceFieldOptions.type = AMBER;
	forceFieldOptions.bondStretch = GTK_TOGGLE_BUTTON (buttonMMOptions[MMBOND])->active;
	forceFieldOptions.angleBend = GTK_TOGGLE_BUTTON (buttonMMOptions[MMBEND])->active;
	forceFieldOptions.dihedralAngle = GTK_TOGGLE_BUTTON (buttonMMOptions[MMTORSION])->active;
	forceFieldOptions.improperTorsion = GTK_TOGGLE_BUTTON (buttonMMOptions[MMIMPROPER])->active;
	forceFieldOptions.nonBonded = GTK_TOGGLE_BUTTON (buttonMMOptions[MMNONBOND])->active;
	forceFieldOptions.hydrogenBonded = GTK_TOGGLE_BUTTON (buttonMMOptions[MMHBOND])->active;
	forceFieldOptions.coulomb = GTK_TOGGLE_BUTTON (buttonMMOptions[MMCOULOMB])->active;
	forceFieldOptions.vanderWals = GTK_TOGGLE_BUTTON (buttonMMOptions[PWVANDERWALS])->active;

	useConjugateGradient = GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADCONJUGATE])->active;
	useQuasiNewton = GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADQUASINEWTON])->active;

	conjugateGradientOptions.gradientNorm  = 
		atof(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADEPSILON])));
	conjugateGradientOptions.maxIterations = 
		atoi(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXITERATIONS])));
	conjugateGradientOptions.updateFrequency = 
		atoi(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADFREQUENCY])));
	conjugateGradientOptions.initialStep = 
		atof(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADINITIALSTEP])));
	conjugateGradientOptions.maxLines = 
		atoi(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXLINES])));

	quasiNewton.maxIterations = 
		atoi(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXITERATIONS])));
	quasiNewton.updateFrequency = 
		atoi(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADFREQUENCY])));
	quasiNewton.epsilon  = 
		atof(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADEPSILON])));
	quasiNewton.tolerence = 1e-16;  
	quasiNewton.maxLines = 
		atoi(gtk_entry_get_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXLINES])));

	if(GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADHESTENES])->active)
		conjugateGradientOptions.method = 1;
	else
	if(GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADFLETCHER])->active)
		conjugateGradientOptions.method = 2;
	else
	if(GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADPOLAK])->active)
		conjugateGradientOptions.method = 3;
	else
	if(GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADWOLF])->active)
		conjugateGradientOptions.method = 4;

	if(GTK_TOGGLE_BUTTON (buttonTypesOptions[AMBER])->active )
		forceFieldOptions.type = AMBER;
	else
	if(GTK_TOGGLE_BUTTON (buttonTypesOptions[PAIRWISE])->active )
	{
		forceFieldOptions.coulomb = GTK_TOGGLE_BUTTON (buttonMMOptions[PWCOULOMB])->active;
		forceFieldOptions.type = PAIRWISE;
	}
	{
		gint i;
		for(i=0;i<4;i++) NumSelAtoms[i] = -1;
		change_of_center(NULL,NULL);
	}

	gtk_widget_destroy(Win);
    	while( gtk_events_pending() )
        	gtk_main_iteration();

	gtk_widget_set_sensitive(StopButton, TRUE);
	StopCalcul = FALSE;

	if(forceFieldOptions.type==AMBER)
		forceField = createAmberModel(geometry0,Natoms,forceFieldOptions);
	else
	if(forceFieldOptions.type==PAIRWISE)
		forceField = createPairWiseModel(geometry0,Natoms,forceFieldOptions);

	if(StopCalcul)
	{
		set_text_to_draw(" ");
		set_statubar_operation_str("Calcul Canceled ");
		dessine();
		gtk_widget_set_sensitive(StopButton, FALSE);
		return;
	}

	if(useConjugateGradient)
	{
		gtk_widget_set_sensitive(StopButton, TRUE);
		runConjugateGradient(&conjugateGradient, &forceField,
				conjugateGradientOptions); 
		if(StopCalcul)
		{
			set_text_to_draw(" ");
			set_statubar_operation_str("Calcul canceled");
			dessine();
		}
		gtk_widget_set_sensitive(StopButton, FALSE);
		freeConjugateGradient(&conjugateGradient);
	}
	else if(useQuasiNewton)
	{
		gtk_widget_set_sensitive(StopButton, TRUE);
		quasiNewton.forceField = &forceField; 
                runQuasiNewton(&quasiNewton);
		if(StopCalcul)
		{
			set_text_to_draw(" ");
			set_statubar_operation_str("Calcul canceled");
			dessine();
		}
		gtk_widget_set_sensitive(StopButton, FALSE);
		freeQuasiNewton(&quasiNewton);

	}
	else
	{
		gtk_widget_set_sensitive(StopButton, TRUE);
		runSteepestDescent(&steepestDescent, &forceField,
			       	conjugateGradientOptions.updateFrequency,
			       conjugateGradientOptions.maxIterations,
			       conjugateGradientOptions.gradientNorm,
			       conjugateGradientOptions.maxLines);
		if(StopCalcul)
		{
			set_text_to_draw(" ");
			set_statubar_operation_str("Calcul canceled");
			dessine();
		}
		gtk_widget_set_sensitive(StopButton, FALSE);
		freeSteepestDescent(&steepestDescent);
	}
	freeForceField(&forceField);
	set_text_to_draw(" ");
}
/*****************************************************************************/
void amberEnergyCalculation(GtkWidget* Win, gpointer data)
{
	gchar* str;
	ForceField forceField;
	ForceFieldOptions forceFieldOptions;
	gdouble gradientNorm = 0;
	gint i,j;

	forceFieldOptions.type = AMBER;
	forceFieldOptions.bondStretch = GTK_TOGGLE_BUTTON (buttonMMOptions[MMBOND])->active;
	forceFieldOptions.angleBend = GTK_TOGGLE_BUTTON (buttonMMOptions[MMBEND])->active;
	forceFieldOptions.dihedralAngle = GTK_TOGGLE_BUTTON (buttonMMOptions[MMTORSION])->active;
	forceFieldOptions.improperTorsion = GTK_TOGGLE_BUTTON (buttonMMOptions[MMIMPROPER])->active;
	forceFieldOptions.nonBonded = GTK_TOGGLE_BUTTON (buttonMMOptions[MMNONBOND])->active;
	forceFieldOptions.hydrogenBonded = GTK_TOGGLE_BUTTON (buttonMMOptions[MMHBOND])->active;
	forceFieldOptions.coulomb = GTK_TOGGLE_BUTTON (buttonMMOptions[MMCOULOMB])->active;
	forceFieldOptions.vanderWals = GTK_TOGGLE_BUTTON (buttonMMOptions[PWVANDERWALS])->active;

	if(GTK_TOGGLE_BUTTON (buttonTypesOptions[AMBER])->active )
		forceFieldOptions.type = AMBER;
	else
	if(GTK_TOGGLE_BUTTON (buttonTypesOptions[PAIRWISE])->active )
	{
		forceFieldOptions.coulomb = GTK_TOGGLE_BUTTON (buttonMMOptions[PWCOULOMB])->active;
		forceFieldOptions.type = PAIRWISE;
	}

	gtk_widget_destroy(Win);
    	while( gtk_events_pending() )
        	gtk_main_iteration();

	gtk_widget_set_sensitive(StopButton, TRUE);
	StopCalcul = FALSE;
	if(forceFieldOptions.type==AMBER)
		forceField = createAmberModel(geometry0,Natoms,forceFieldOptions);
	else
	if(forceFieldOptions.type==PAIRWISE)
		forceField = createPairWiseModel(geometry0,Natoms,forceFieldOptions);

	if(StopCalcul)
	{
		set_text_to_draw(" ");
		set_statubar_operation_str("Calcul canceled");
		dessine();
		gtk_widget_set_sensitive(StopButton, FALSE);
		return;
	}
	forceField.klass->calculateEnergy(&forceField);
	forceField.klass->calculateGradient(&forceField);

	gradientNorm = 0;
	for (  i = 0; i < forceField.molecule.nAtoms; i++ )
		for(j=0;j<3;j++)
			gradientNorm += 
			forceField.molecule.gradient[j][i]
			*forceField.molecule.gradient[j][i]; 

	str = g_strdup_printf("Gradient Norm  = %f energy = %f(KCal/mol)",
		sqrt(gradientNorm),forceField.molecule.energy); 

	set_text_to_draw(str);
	set_statubar_operation_str(str);
	dessine();
	gtk_widget_set_sensitive(StopButton, FALSE);
	freeForceField(&forceField);
	set_text_to_draw(" ");
	g_free(str);
}
/***********************************************************************/
void sensitive_conjugate_gradient_buttons(GtkWidget *button, gpointer data)
{
	gboolean useConjugateGradient;
	gboolean useQuasiNewton;
	gboolean Ok = FALSE;
	if(data != NULL)
		Ok = TRUE;

	useQuasiNewton = GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADQUASINEWTON])->active;
	useConjugateGradient = GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADCONJUGATE])->active;
	if(useConjugateGradient)
	{
		Ok = TRUE;
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADHESTENES], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADFLETCHER], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADPOLAK], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADWOLF], Ok);

		gtk_widget_set_sensitive(entryMinimizeOptions[GRADMAXLINES], Ok);
		gtk_widget_set_sensitive(entryMinimizeOptions[GRADINITIALSTEP], Ok);
		gtk_entry_set_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXLINES]),"25");
	}
	else
	if(useQuasiNewton)
	{
		Ok = FALSE;
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADHESTENES], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADFLETCHER], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADPOLAK], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADWOLF], Ok);

		gtk_widget_set_sensitive(entryMinimizeOptions[GRADMAXLINES], TRUE);
		gtk_widget_set_sensitive(entryMinimizeOptions[GRADINITIALSTEP], Ok);
		gtk_entry_set_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXLINES]),"25");
	}
	else
	{
		Ok = FALSE;
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADHESTENES], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADFLETCHER], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADPOLAK], Ok);
		gtk_widget_set_sensitive(buttonMinimizeOptions[GRADWOLF], Ok);

		gtk_widget_set_sensitive(entryMinimizeOptions[GRADMAXLINES], TRUE);
		gtk_widget_set_sensitive(entryMinimizeOptions[GRADINITIALSTEP], Ok);
		gtk_entry_set_text(GTK_ENTRY(entryMinimizeOptions[GRADMAXLINES]),"400");
	}
}
/***********************************************************************/
static void AddGradientOptionsDlg(GtkWidget *NoteBook)
{

	gint i;
	gint j;
	gint ifirst;
	GtkWidget *frame;
	GtkWidget *frame1;
	GtkWidget *LabelOnglet;
	GtkWidget *LabelMenu;
	GtkWidget *vbox;
	GtkWidget *vbox1;
	GtkWidget *hbox;
	GtkWidget *table;
	GtkWidget* label;
	GtkWidget *vseparator = gtk_vseparator_new ();
	gchar *options[NGRADOPTIONS]={
  		"Use Quasi Newton ",
  		"Use Steepest Descent ",
  		"Use Comgugate Gradient ",
  		"Hestenes-Stiefel Method",
  		"Fletcher-Reeves Method",
  		"Polak-Ribiere Method",
  		"Wolf-Powell Method"
  		};
	gchar *entrylabels[NGRADENTRYS]={
  		"Maximum Iterations",
  		"Epsilon",
  		"Maximum Line Searches",
  		"Step Size",
  		"Screen Rafresh after"
  		};
	gchar *entryvalues[NGRADENTRYS]={
  		"1000",
  		"0.0001",
  		"25",
  		"0.01",
  		"1"
  		};

	frame = gtk_frame_new(NULL);
	gtk_container_set_border_width(GTK_CONTAINER(frame), 5);

	LabelOnglet = gtk_label_new("Gradient Options");
	LabelMenu = gtk_label_new("Gradient Options");
	gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
			  frame,LabelOnglet, LabelMenu);
	g_object_set_data (G_OBJECT (frame), "frame", frame);

	vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox);
	gtk_container_add (GTK_CONTAINER (frame), vbox);

	frame1 = gtk_frame_new (NULL);
	gtk_widget_show (frame1);
	gtk_container_add (GTK_CONTAINER (vbox), frame1);
	gtk_frame_set_label_align (GTK_FRAME (frame1), 0.5, 0.5);

	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_container_add (GTK_CONTAINER (frame1), vbox1);

	table = gtk_table_new(8,8,FALSE);
	gtk_box_pack_start (GTK_BOX (vbox1), table, TRUE, TRUE, 0);

/*----------------------------------------------------------------------------------*/
	i = 0;
	j = 0;
	buttonMinimizeOptions[GRADQUASINEWTON]= gtk_radio_button_new_with_label(
			NULL,
                       options[GRADQUASINEWTON]); 
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADQUASINEWTON],
			j,j+2,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADQUASINEWTON]), TRUE);
/*----------------------------------------------------------------------------------*/
	i = 1;
	j = 0;
	buttonMinimizeOptions[GRADSTEEPEST]= gtk_radio_button_new_with_label(
		gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMinimizeOptions[GRADQUASINEWTON])),
                options[GRADSTEEPEST]); 
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADSTEEPEST],
			j,j+2,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADSTEEPEST]), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 2;
	j = 0;
	buttonMinimizeOptions[GRADCONJUGATE] = gtk_radio_button_new_with_label(
                       gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMinimizeOptions[GRADSTEEPEST])),
			options[GRADCONJUGATE]);
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADCONJUGATE],
			j,j+2,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADCONJUGATE]), TRUE);
/*----------------------------------------------------------------------------------*/
	i = 3;
	j = 0;
	label = gtk_label_new("    ");
	gtk_table_attach(GTK_TABLE(table),label,
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
/*----------------------------------------------------------------------------------*/
	i = 3;
	j = 1;
	buttonMinimizeOptions[GRADHESTENES] = gtk_radio_button_new_with_label(NULL,options[GRADHESTENES]);
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADHESTENES],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL) ,
                  (GtkAttachOptions)(GTK_SHRINK),
                  1,1);

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADHESTENES]), TRUE);
/*----------------------------------------------------------------------------------*/
	i = 4;
	j = 1;
	buttonMinimizeOptions[GRADFLETCHER] = gtk_radio_button_new_with_label(
			gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMinimizeOptions[GRADHESTENES])),
			options[GRADFLETCHER]);
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADFLETCHER],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL) ,
                  (GtkAttachOptions)(GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADFLETCHER]), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 5;
	j = 1;
	buttonMinimizeOptions[GRADPOLAK] = gtk_radio_button_new_with_label(
			gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMinimizeOptions[GRADHESTENES])),
			options[GRADPOLAK]);
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADPOLAK],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADPOLAK]), FALSE);
/*----------------------------------------------------------------------------------*/
	i = 6;
	j = 1;
	buttonMinimizeOptions[GRADWOLF] = gtk_radio_button_new_with_label(
			gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonMinimizeOptions[GRADHESTENES])),
			options[GRADWOLF]);
	gtk_table_attach(GTK_TABLE(table),buttonMinimizeOptions[GRADWOLF],
			j,j+1,i,i+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADWOLF]), FALSE);


/* Entrys */
	j = 3;
	i = 2;
	gtk_table_attach(GTK_TABLE(table),vseparator,
		j,j+1,i,i+5,
                (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                1,1);

	ifirst = 2;

	for(i=0;i<NGRADENTRYS;i++)
	{
		j = 4;
		label = gtk_label_new(entrylabels[i]);
		gtk_label_set_justify(GTK_LABEL(label),GTK_JUSTIFY_LEFT);
		hbox = gtk_hbox_new (FALSE, 5);
		gtk_table_attach(GTK_TABLE(table),hbox,
			j,j+1,i+ifirst,i+ifirst+1,
                  (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                  (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                  1,1);
		gtk_widget_show (hbox);
  		gtk_box_pack_start (GTK_BOX(hbox), label, FALSE, FALSE, 5);

		j = 5;
		label = gtk_label_new(" : ");
		gtk_table_attach(GTK_TABLE(table),label,
			j,j+1,i+ifirst,i+ifirst+1,
                  (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                  (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                  1,1);

		j = 6;
		entryMinimizeOptions[i] = gtk_entry_new();
  		gtk_widget_set_size_request(entryMinimizeOptions[i], 60, -1);
		gtk_table_attach(GTK_TABLE(table),entryMinimizeOptions[i],
			j,j+1,i+ifirst,i+ifirst+1,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK) ,
                  (GtkAttachOptions)(GTK_FILL|GTK_SHRINK),
                  1,1);
		gtk_entry_set_text(GTK_ENTRY(entryMinimizeOptions[i]),entryvalues[i]);
	}
	j = 8;
	label = gtk_label_new(" steps ");
	gtk_table_attach(GTK_TABLE(table),label,
		j,j+1,GRADFREQUENCY+1,GRADFREQUENCY+2,
                (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                (GtkAttachOptions)(GTK_EXPAND | GTK_FILL),
                1,1);


	g_signal_connect(G_OBJECT(buttonMinimizeOptions[GRADCONJUGATE]),
			"clicked",
			(GtkSignalFunc)sensitive_conjugate_gradient_buttons,
			(gpointer)(buttonMinimizeOptions[GRADCONJUGATE]));
	g_signal_connect(G_OBJECT(buttonMinimizeOptions[GRADSTEEPEST]),
			"clicked",
			(GtkSignalFunc)sensitive_conjugate_gradient_buttons,
			NULL);
	g_signal_connect(G_OBJECT(buttonMinimizeOptions[GRADQUASINEWTON]),
			"clicked",
			(GtkSignalFunc)sensitive_conjugate_gradient_buttons,
			NULL);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMinimizeOptions[GRADQUASINEWTON]), TRUE);
}
/***********************************************************************/
static void sensitiveFrames(GtkWidget *button, gpointer data)
{
	if(button == buttonTypesOptions[AMBER])
	{
		gtk_widget_set_sensitive(frameAmber, TRUE);
		gtk_widget_set_sensitive(framePairWise, FALSE);
	}
	else
	{
		gtk_widget_set_sensitive(frameAmber, FALSE);
		gtk_widget_set_sensitive(framePairWise, TRUE);
	}
}
/***********************************************************************/
static void AddMMOptionsDlg(GtkWidget *NoteBook)
{

	gint i;
	GtkWidget *frame;
	GtkWidget *frame1;
	GtkWidget *frame2;
	GtkWidget *LabelOnglet;
	GtkWidget *LabelMenu;
	GtkWidget *vbox;
	GtkWidget *vbox1;
	GtkWidget *vbox2;
	GtkWidget *hbox;
	gchar *firstColonn[NOPTIONS1]={
  		"Use bond stretch terms ",
  		"Use angle bend terms ",
  		"Use torsion terms ",
  		"Use improper torsion terms "
  		};
	gchar *secondColonn[NOPTIONS2]={
  		"Use Non bonded terms ",
		"Use H-Bonded terms ",
		"Use electrostatic charge-charge terms "
  		};
	gchar *pairWise[NOPTIONS3]={
		"Use Vander Wals attactive terms ",
		"Use electrostatic charge-charge terms "
  		};

	frame = gtk_frame_new(NULL);
	gtk_container_set_border_width(GTK_CONTAINER(frame), 5);

	LabelOnglet = gtk_label_new("MM Options");
	LabelMenu = gtk_label_new("MM Options");
	gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
			  frame,LabelOnglet, LabelMenu);
	g_object_set_data (G_OBJECT (frame), "frame", frame);

	vbox = gtk_vbox_new (FALSE, 2);
	gtk_widget_show (vbox);
	gtk_container_add (GTK_CONTAINER (frame), vbox);

	buttonTypesOptions[AMBER] =gtk_radio_button_new_with_label( NULL,"Amber model"); 
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonTypesOptions[AMBER]), TRUE);
	gtk_box_pack_start (GTK_BOX (vbox), buttonTypesOptions[AMBER], TRUE, TRUE, 0);
	gtk_widget_show (buttonTypesOptions[AMBER]);

	frame1 = gtk_frame_new (NULL);
	gtk_widget_show (frame1);
	gtk_container_add (GTK_CONTAINER (vbox), frame1);
	gtk_frame_set_label_align (GTK_FRAME (frame1), 0.5, 0.5);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_widget_show (hbox);
	gtk_container_add (GTK_CONTAINER (frame1), hbox);

	vbox1 = gtk_vbox_new (FALSE, 0);
	gtk_widget_ref (vbox1);
	gtk_box_pack_start (GTK_BOX (hbox), vbox1, TRUE, TRUE, 0);

	for(i=0;i<NOPTIONS1;i++)
	{
		buttonMMOptions[i] = create_checkbutton(frame1,vbox1,firstColonn[i]);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMMOptions[i]), TRUE);
	}

	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMMOptions[MMIMPROPER]), FALSE);

	vbox2 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox2);
	gtk_box_pack_start (GTK_BOX (hbox), vbox2, TRUE, TRUE, 0);

	for(i=0;i<NOPTIONS2;i++)
	{
  		buttonMMOptions[NOPTIONS1+i] = create_checkbutton(frame1,vbox2,secondColonn[i]);
		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMMOptions[NOPTIONS1+i]), FALSE);
	}
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMMOptions[MMNONBOND]), TRUE);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonMMOptions[MMCOULOMB]), TRUE);

	buttonTypesOptions[PAIRWISE] = gtk_radio_button_new_with_label(
			gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonTypesOptions[AMBER])),
			"Pair Wise approximation of energy");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonTypesOptions[PAIRWISE]), FALSE);
	gtk_box_pack_start (GTK_BOX (vbox), buttonTypesOptions[PAIRWISE], TRUE, TRUE, 0);
	gtk_widget_show (buttonTypesOptions[PAIRWISE]);

	frame2 = gtk_frame_new (NULL);
	gtk_widget_show (frame2);
	gtk_container_add (GTK_CONTAINER (vbox), frame2);
	gtk_frame_set_label_align (GTK_FRAME (frame2), 0.5, 0.5);

	vbox2 = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vbox2);
	gtk_container_add (GTK_CONTAINER (frame2), vbox2);

	for(i=0;i<NOPTIONS3;i++)
	{
  		buttonMMOptions[NOPTIONS1+NOPTIONS2+i] = 
			create_checkbutton(frame2,vbox2,pairWise[i]);
		gtk_toggle_button_set_active (
				GTK_TOGGLE_BUTTON (buttonMMOptions[NOPTIONS1+NOPTIONS2+i]), TRUE);
	}
	frameAmber = frame1;
	framePairWise = frame2;
	sensitiveFrames(buttonTypesOptions[AMBER],NULL);

	g_signal_connect(G_OBJECT(buttonTypesOptions[AMBER]),
			"clicked", (GtkSignalFunc)sensitiveFrames,NULL);
	g_signal_connect(G_OBJECT(buttonTypesOptions[PAIRWISE]),
			"clicked", (GtkSignalFunc)sensitiveFrames,NULL);


}
/***********************************************************************/
void DestroyWinMMDlg(GtkWidget* Win, gpointer data)
{
	gtk_widget_destroy(GTK_WIDGET(Win));
}
/***********************************************************************/
void MolecularMechanicsEnergyDlg()
{
	GtkWidget *button;
	GtkWidget *Win;
	GtkWidget *NoteBook;
	GtkWidget *parentWindow = GeomDlg;

	StopCalcul = TRUE;

	Win= gtk_dialog_new ();
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(parentWindow));
	gtk_window_set_title(&GTK_DIALOG(Win)->window,"Molecular Mechanics Energy");
    	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)DestroyWinMMDlg,NULL);
 
	NoteBook = gtk_notebook_new();
	gtk_box_pack_start(GTK_BOX (GTK_DIALOG(Win)->vbox), NoteBook,TRUE, TRUE, 0);

	AddMMOptionsDlg(NoteBook);
  

	gtk_widget_realize(Win);

	button = create_button(Win,"Cancel");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Win)->action_area), button, TRUE, TRUE, 0);
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(DestroyWinMMDlg),GTK_OBJECT(Win));
	gtk_widget_show (button);

	button = create_button(Win,"Ok");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Win)->action_area), button, TRUE, TRUE, 0);
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked", (GtkSignalFunc)amberEnergyCalculation,GTK_OBJECT(Win));
	gtk_widget_show (button);


	gtk_widget_show_all(Win);
  
}
/***********************************************************************/
void MolecularMechanicsMinimizeDlg()
{
	GtkWidget *button;
	GtkWidget *Win;
	GtkWidget *NoteBook;
	GtkWidget *parentWindow = GeomDlg;

	StopCalcul = TRUE;

	Win= gtk_dialog_new ();
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(parentWindow));
	gtk_window_set_title(&GTK_DIALOG(Win)->window,"Molecular Mechanics Minimize");
    	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)DestroyWinMMDlg,NULL);
 
	NoteBook = gtk_notebook_new();
	gtk_box_pack_start(GTK_BOX (GTK_DIALOG(Win)->vbox), NoteBook,TRUE, TRUE, 0);

	AddGradientOptionsDlg(NoteBook);
	AddMMOptionsDlg(NoteBook);
  

	gtk_widget_realize(Win);

	button = create_button(Win,"Cancel");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Win)->action_area), button, TRUE, TRUE, 0);
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(DestroyWinMMDlg),GTK_OBJECT(Win));
	gtk_widget_show (button);

	button = create_button(Win,"Ok");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Win)->action_area), button, TRUE, TRUE, 0);
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked", (GtkSignalFunc)amberMinimize,GTK_OBJECT(Win));
	gtk_widget_show (button);

  


	gtk_widget_show_all(Win);
  
}
/***********************************************************************/
void MolecularMechanicsDynamicsDlg()
{
	GtkWidget *button;
	GtkWidget *Win;
	GtkWidget *NoteBook;
	GtkWidget *parentWindow = GeomDlg;

	StopCalcul = TRUE;

	Win= gtk_dialog_new ();
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(parentWindow));
	gtk_window_set_title(&GTK_DIALOG(Win)->window,"Molecular Dynamics");
    	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)gtk_widget_destroy,NULL);
 
	NoteBook = gtk_notebook_new();
	gtk_box_pack_start(GTK_BOX (GTK_DIALOG(Win)->vbox), NoteBook,TRUE, TRUE, 0);

	AddDynamicsOptionsDlg(NoteBook, Win);
	AddMMOptionsDlg(NoteBook);
  

	gtk_widget_realize(Win);

	button = create_button(Win,"Cancel");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Win)->action_area), button, TRUE, TRUE, 0);
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked", GTK_SIGNAL_FUNC(gtk_widget_destroy),GTK_OBJECT(Win));
	gtk_widget_show (button);

	button = create_button(Win,"Ok");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( GTK_DIALOG(Win)->action_area), button, TRUE, TRUE, 0);
	g_signal_connect_swapped(GTK_OBJECT(button), "clicked", (GtkSignalFunc)amberMolecularDynamics,GTK_OBJECT(Win));
	gtk_widget_show (button);

	gtk_widget_show_all(Win);
  
}
/***********************************************************************/
