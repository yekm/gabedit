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
#include "../MolecularMechanics/Atom.h"
#include "../MolecularMechanics/Molecule.h"
#include "../MolecularMechanics/ForceField.h"
#include "../MolecularMechanics/MolecularMechanics.h"
#include "../MolecularMechanics/ConjugateGradient.h"
#include "../MolecularMechanics/SteepestDescent.h"
#include "../MolecularMechanics/QuasiNewton.h"

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

static	GtkWidget* buttonTypesOptions[3];
static	GtkWidget* buttonMMOptions[NOPTIONS1+NOPTIONS2+NOPTIONS3];
static	GtkWidget* buttonMinimizeOptions[NGRADOPTIONS];
static	GtkWidget* entryMinimizeOptions[NGRADENTRYS];
static	GtkWidget* frameAmber = NULL;
static	GtkWidget* framePairWise = NULL;

/*****************************************************************************/
void amberMinimize(GtkWidget* Win, gpointer data)
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
void AddGradientOptionsDlg(GtkWidget *NoteBook)
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
  		"200",
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
void AddMMOptionsDlg(GtkWidget *NoteBook)
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

	Win= gtk_dialog_new ();
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(parentWindow));
	gtk_window_set_title(&GTK_DIALOG(Win)->window,"Molecular Mechanics Minimize");
    	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

	g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)DestroyWinMMDlg,NULL);
 
	NoteBook = gtk_notebook_new();
	gtk_box_pack_start(GTK_BOX (GTK_DIALOG(Win)->vbox), NoteBook,TRUE, TRUE, 0);

	AddMMOptionsDlg(NoteBook);
	AddGradientOptionsDlg(NoteBook);
  

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
