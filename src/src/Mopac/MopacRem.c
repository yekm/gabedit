/* MopacRem.c */
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
#include <ctype.h>
#include <math.h>
#include <string.h>

#include "../../Config.h"
#include "../Common/Global.h"
#include "../Mopac/MopacTypes.h"
#include "../Mopac/MopacGlobal.h"
#include "../Mopac/MopacMolecule.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Common/Windows.h"
#include "../Utils/Constantes.h"

static GtkWidget* comboethod = NULL;
/*************************************************************************************************************/
static gchar* listJobView[] = {
        "Single Point Energy", 
	"Equilibrium structure search", 
	"Frequencies",
	"Transition structure search", 
        "Theromochemical Calculations",
        "Molecular Orbitals",
        "Atomic charges from ElectroStatic Potential",
};
static gchar* listJobReal[] = {
        "1SCF ", 
	"XYZ ", 
        "FORCE ", 
	"TS ", 
	"THERMO ROT=1 ",
	"GRAPH VECTORS ",
	"1SCF ESP ",
};
static guint numberOfJobs = G_N_ELEMENTS (listJobView);
static gchar selectedJob[BSIZE]="1SCF";
/*************************************************************************************************************/
static gchar* listHamiltonianMethodsView[] = 
{ 
	"PM6", 
	"RM1", 
	"PM3", 
	"AM1", 
	"MNDO", 
};
static gchar* listHamiltonianMethodsReal[] = 
{ 
	"PM6", 
	"RM1", 
	"PM3", 
	"AM1", 
	"MNDO", 
};
static guint numberOfHamiltonianMethods = G_N_ELEMENTS (listHamiltonianMethodsView);
static gchar selectedHamiltonian[BSIZE]="PM6";
/*************************************************************************************************************/
static gchar* calculWord(gchar* view)
{
	gint i;
	for(i=0;i<numberOfJobs;i++)
	{
		if(strcmp(view,listJobView[i])==0)return listJobReal[i];
	}
	return NULL;
}
/*************************************************************************************************************/
static void putMopacJobTypeInfoInTextEditor()
{
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, selectedJob,-1);
        gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, " ",-1);
}
/*************************************************************************************************************/
static void putMopacHamiltonianInfoInTextEditor()
{
	if(strcmp(selectedHamiltonian,"NONE")==0)return;

       	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, selectedHamiltonian,-1);
       	gabedit_text_insert (GABEDIT_TEXT(text), NULL, NULL, NULL, " ",-1);
}
/*************************************************************************************************************/
void putMopacRemInfoInTextEditor()
{
	putMopacHamiltonianInfoInTextEditor();
	putMopacJobTypeInfoInTextEditor();

}
/************************************************************************************************************/
static void traitementJobType (GtkComboBox *combobox, gpointer d)
{
	GtkTreeIter iter;
	gchar* data = NULL;
	gchar* res = NULL;
	
	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		gtk_tree_model_get (model, &iter, 0, &data, -1);
	}
	else return;
	res = calculWord(data);
	if(res) sprintf(selectedJob,"%s",res);
	else  sprintf(selectedJob,"SP");

}
/********************************************************************************************************/
static GtkWidget *create_list_jobtype()
{
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;
	gint i;
        GtkTreeIter iter0;

	store = gtk_tree_store_new (1,G_TYPE_STRING);

	for(i=0;i<numberOfJobs;i++)
	{
        	gtk_tree_store_append (store, &iter, NULL);
		if(i==0) iter0 = iter;
        	gtk_tree_store_set (store, &iter, 0, listJobView[i], -1);
	}

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	/*
	gtk_combo_box_set_add_tearoffs (GTK_COMBO_BOX (combobox), TRUE);
	*/
	g_object_unref (model);
	g_signal_connect (G_OBJECT(combobox), "changed", G_CALLBACK(traitementJobType), NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);

	gtk_combo_box_set_active_iter(GTK_COMBO_BOX (combobox), &iter0);

	return combobox;
}
/************************************************************************************************************/
static void traitementHamiltonian (GtkComboBox *combobox, gpointer d)
{
	GtkTreeIter iter;
	gchar* data = NULL;
	gchar* res = NULL;
	gint i;
	/* gchar* s;*/
	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		gtk_tree_model_get (model, &iter, 0, &data, -1);
	}
	else return;
	for(i=0;i<numberOfHamiltonianMethods;i++)
	{
		if(strcmp((gchar*)data,listHamiltonianMethodsView[i])==0) res = listHamiltonianMethodsReal[i];
	}
	if(res) sprintf(selectedHamiltonian,"%s",res);

}
/********************************************************************************************************/
static GtkWidget *create_list_hamiltonian_methods()
{
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;
	gint i;
        GtkTreeIter iter0;

	store = gtk_tree_store_new (1,G_TYPE_STRING);

	for(i=0;i<numberOfHamiltonianMethods;i++)
	{
        	gtk_tree_store_append (store, &iter, NULL);
		if(i==0) iter0 = iter;
        	gtk_tree_store_set (store, &iter, 0, listHamiltonianMethodsView[i], -1);
	}

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	/*
	gtk_combo_box_set_add_tearoffs (GTK_COMBO_BOX (combobox), TRUE);
	*/
	g_object_unref (model);
	g_signal_connect (G_OBJECT(combobox), "changed", G_CALLBACK(traitementHamiltonian), NULL);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);

	gtk_combo_box_set_active_iter(GTK_COMBO_BOX (combobox), &iter0);

	return combobox;
}
/*************************************************************************************************************/
void createMopacRemFrame(GtkWidget *win, GtkWidget *box)
{
	GtkWidget* frame;
	GtkWidget* vboxFrame;
	GtkWidget* sep;
	GtkWidget* combo = NULL;
	gint l=0;
	gint c=0;
	gint ncases=1;
	GtkWidget *table = gtk_table_new(8,3,FALSE);

	comboethod = NULL;

	frame = gtk_frame_new ("Job Specification:");
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (box), frame, TRUE, TRUE, 3);
	gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

	vboxFrame = gtk_vbox_new (FALSE, 3);
	gtk_widget_show (vboxFrame);
	gtk_container_add (GTK_CONTAINER (frame), vboxFrame);
	gtk_box_pack_start (GTK_BOX (vboxFrame), table, TRUE, TRUE, 0);

	/*------------------ Job Type -----------------------------------------*/
	l=0; 
	c = 0; ncases=1;
	add_label_table(table,"Job Type",l,c);
	c = 1; ncases=1;
	add_label_table(table,":",l,c);
	combo = create_list_jobtype();
	c = 2; ncases=1;
	gtk_table_attach(GTK_TABLE(table),combo,c,c+ncases,l,l+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_SHRINK),
                  2,2);
	/*------------------ Hamiltonian Type -----------------------------------------*/
	l++;
	c = 0; ncases=1;
	add_label_table(table,"Hamiltonian",l,c);
	c = 1; ncases=1;
	add_label_table(table,":",l,c);
	combo = create_list_hamiltonian_methods();
	comboethod = combo;
	c = 2; ncases=1;
	gtk_table_attach(GTK_TABLE(table),combo,c,c+ncases,l,l+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_SHRINK),
                  2,2);
	/*------------------ separator -----------------------------------------*/
	l++;
	sep = gtk_hseparator_new ();;
	c = 0; ncases=3;
	gtk_table_attach(GTK_TABLE(table),sep,c,c+ncases,l,l+1,
		(GtkAttachOptions)	(GTK_FILL | GTK_EXPAND),
		(GtkAttachOptions)	(GTK_FILL | GTK_SHRINK),
                  2,2);
}
