/* Orbitals.c */
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
#include "../Utils/AtomsProp.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "GeomDraw.h"
#include "GLArea.h"
#include "UtilsOrb.h"
#include "Basis.h"
#include "GeomOrbXYZ.h"
#include "AtomicOrbitals.h"
#include "StatusOrb.h"
/*
#include "OrbitalsDalton.h"
*/
#include "OrbitalsMolpro.h"

#define WIDTHSCR 0.608

static GtkWidget*  alphalist = NULL;
static GtkWidget*  betalist = NULL;
static gint TypeSelOrbtmp = 1;
static gint NumSelOrbtmp = -1;
void create_iso_orbitals();
static gboolean sphericalBasis = FALSE;
/********************************************************************************/
static void selectRow(GtkWidget* list, gint row)
{
	GtkTreePath *path;
	gchar* tmp = g_strdup_printf("%d",row);

	path = gtk_tree_path_new_from_string  (tmp);
	g_free(tmp);
	gtk_tree_selection_select_path  (gtk_tree_view_get_selection (GTK_TREE_VIEW (list)), path);
	gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW (list), path, NULL, FALSE,0.5,0.5);
	gtk_tree_path_free(path);
}
/********************************************************************************/
void free_orbitals()
{
	gint i;
	if(EnerAlphaOrbitals == EnerBetaOrbitals)
	{
		if(EnerAlphaOrbitals)
			g_free(EnerAlphaOrbitals);
		EnerAlphaOrbitals = NULL;
		EnerBetaOrbitals = NULL;
	}
	else
	{
		if(EnerAlphaOrbitals)
			g_free(EnerAlphaOrbitals);
		EnerAlphaOrbitals = NULL;
		if(EnerBetaOrbitals)
			g_free(EnerBetaOrbitals);
		EnerBetaOrbitals = NULL;
	}
	if(OccAlphaOrbitals == OccBetaOrbitals)
	{
		if(OccAlphaOrbitals)
			g_free(OccAlphaOrbitals);
		OccAlphaOrbitals = NULL;
		OccBetaOrbitals = NULL;
	}
	else
	{
		if(OccAlphaOrbitals)
			g_free(OccAlphaOrbitals);
		OccAlphaOrbitals = NULL;
		if(OccBetaOrbitals)
			g_free(OccBetaOrbitals);
		OccBetaOrbitals = NULL;

	}
	if(SymAlphaOrbitals == SymBetaOrbitals)
	{
		if(SymAlphaOrbitals)
		{
			for(i=0;i<NAlphaOrb;i++)
				if(SymAlphaOrbitals[i])
					g_free(SymAlphaOrbitals[i]);
			g_free(SymAlphaOrbitals);
		}
		SymAlphaOrbitals = NULL;
		SymBetaOrbitals = NULL;
	}
	else
	{
		if(SymAlphaOrbitals)
		{
			for(i=0;i<NAlphaOrb;i++)
				if(SymAlphaOrbitals[i])
					g_free(SymAlphaOrbitals[i]);
			g_free(SymAlphaOrbitals);
		}
		SymAlphaOrbitals = NULL;
		if(SymBetaOrbitals)
		{
			for(i=0;i<NBetaOrb;i++)
				if(SymBetaOrbitals[i])
					g_free(SymBetaOrbitals[i]);
			g_free(SymBetaOrbitals);
		}
		SymBetaOrbitals = NULL;
	}

	if(CoefAlphaOrbitals == CoefBetaOrbitals)
	{
		if(CoefAlphaOrbitals)
		{
			for(i=0;i<NOrb;i++)
				if(CoefAlphaOrbitals[i])
					g_free(CoefAlphaOrbitals[i]);
			g_free(CoefAlphaOrbitals);
		}
		CoefAlphaOrbitals  = NULL;
		CoefBetaOrbitals  = NULL;
	}
	else
	{
		if(CoefAlphaOrbitals)
		{
			for(i=0;i<NOrb;i++)
				if(CoefAlphaOrbitals[i])
					g_free(CoefAlphaOrbitals[i]);
			g_free(CoefAlphaOrbitals);
		}
		CoefAlphaOrbitals  = NULL;
		if(CoefBetaOrbitals)
		{
			for(i=0;i<NOrb;i++)
				if(CoefBetaOrbitals[i])
					g_free(CoefBetaOrbitals[i]);
			g_free(CoefBetaOrbitals);
		}
		CoefBetaOrbitals = NULL;
	}
	set_status_label_info("Mol. Orb.","Nothing");
	NOrb = 0;
	NAOrb = 0;
}
/********************************************************************************/
static void applyiso(GtkWidget *Win,gpointer data)
{
	GtkWidget* Entry =(GtkWidget*)g_object_get_data(G_OBJECT (Win), "Entry");
	gchar* temp;
	gfloat isovalue;
	
	temp = g_strdup(gtk_entry_get_text(GTK_ENTRY(Entry))); 
	delete_first_spaces(temp);
	delete_last_spaces(temp);
	if(this_is_a_real(temp)) isovalue = atof(temp);
	else
	{
		GtkWidget* message =Message("Error : one entry is not a float ","Error",TRUE);
  		gtk_window_set_modal (GTK_WINDOW (message), TRUE);
		return;
	}
	if(fabs(isovalue)>fabs(limits.MinMax[1][3]) && fabs(isovalue)>fabs(limits.MinMax[0][3]))
	{
		GtkWidget* message = Message("Error :  The maximal value should be smaller than the minimal value ","Error",TRUE);
  		gtk_window_set_modal (GTK_WINDOW (message), TRUE);
		return;
	}
	/*
	if(isovalue<limits.MinMax[0][3])
	{
		GtkWidget* message = Message("Error :  The minimal value should be smaller than the minimal value ","Error",TRUE);
  		gtk_window_set_modal (GTK_WINDOW (message), TRUE);
		return;
	}
	*/

	delete_child(Win);
	Define_Iso(fabs(isovalue));
	glarea_rafresh(GLArea);
}

/********************************************************************************/
void applygrid(GtkWidget *Win,gpointer data)
{
	GtkWidget** entriestmp = NULL;
	G_CONST_RETURN gchar* temp;
	gchar* dump;
	gint i;
	gint j;
	GridLimits limitstmp;
	gint NumPointstmp[3];
	GtkWidget *entries[3][6];
	gfloat V[3][3];

	if(GTK_IS_WIDGET(Win))
	{
		entriestmp = (GtkWidget **)g_object_get_data(G_OBJECT (Win), "Entries");
	}
	else return;

	if(entriestmp==NULL) return;

	for(i=0;i<3;i++)
	for(j=0;j<6;j++)
		entries[i][j] = entriestmp[i*6+j];
	
	for(i=0;i<3;i++)
	{
		for(j=3;j<5;j++)
		{
        		temp	= gtk_entry_get_text(GTK_ENTRY(entries[i][j])); 
			dump = NULL;
			if(temp && strlen(temp)>0)
			{
				dump = g_strdup(temp);
				delete_first_spaces(dump);
				delete_last_spaces(dump);
			}

			if(dump && strlen(dump)>0 && this_is_a_real(dump))
			{
				limitstmp.MinMax[j-3][i] = atof(dump);
			}
			else
			{
				GtkWidget* message = Message("Error : one entry is not a float ","Error",TRUE);
  				gtk_window_set_modal (GTK_WINDOW (message), TRUE);
				return;
			}
			if(dump) g_free(dump);
		}
        	temp	= gtk_entry_get_text(GTK_ENTRY(entries[i][5])); 
		NumPointstmp[i] = atoi(temp);
		if(NumPointstmp[i] <=2)
		{
			GtkWidget* message = Message("Error : The number of points should be > 2. ","Error",TRUE);
  			gtk_window_set_modal (GTK_WINDOW (message), TRUE);
			return;
		}
		
	}

	for(i=0;i<3;i++)
	{
		if( limitstmp.MinMax[0][i]> limitstmp.MinMax[1][i])
		{
			GtkWidget* message = Message("Error :  The minimal value should be smaller than the maximal value ","Error",TRUE);
  			gtk_window_set_modal (GTK_WINDOW (message), TRUE);
			return;
		}
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			V[i][j] = 0;
        		temp	= gtk_entry_get_text(GTK_ENTRY(entries[i][j])); 
			dump = NULL;
			if(temp && strlen(temp)>0)
			{
				dump = g_strdup(temp);
				delete_first_spaces(dump);
				delete_last_spaces(dump);
			}

			if(dump && strlen(dump)>0 && this_is_a_real(dump))
			{
				V[i][j] = atof(dump);
			}
			else
			{
				GtkWidget* message = Message("Error : one entry is not a float ","Error",TRUE);
  				gtk_window_set_modal (GTK_WINDOW (message), TRUE);
				return;
			}
			if(dump) g_free(dump);
		}
	}
        
	for(i=0;i<3;i++)
	{
		gdouble norm = 0.0;
		for(j=0;j<3;j++)
			norm += V[i][j]*V[i][j];
		if(fabs(norm)<1e-8)
		{
			GtkWidget* message = Message("Error : the norm is equal to 0 ","Error",TRUE);
  			gtk_window_set_modal (GTK_WINDOW (message), TRUE);
			return;
		}
		for(j=0;j<3;j++)
			V[i][j] /= sqrt(norm);
	}
	for(j=0;j<3;j++) originOfCube[j] = 0;
	for(j=0;j<3;j++) firstDirection[j] = V[0][j];
	for(j=0;j<3;j++) secondDirection[j] = V[1][j];
	for(j=0;j<3;j++) thirdDirection[j] = V[2][j];

	for(i=0;i<3;i++)
	{
		NumPoints[i] =NumPointstmp[i] ; 
		for(j=0;j<2;j++)
			limits.MinMax[j][i] =limitstmp.MinMax[j][i]; 
	}


	delete_child(Win);
	TypeSelOrb = TypeSelOrbtmp;
 	NumSelOrb = NumSelOrbtmp;
	Define_Grid();
	create_iso_orbitals();
}
/*************************************************************************************************/
static void eventDispatcher(GtkWidget *widget, GdkEventButton *event, gpointer user_data)
{

	GtkTreePath *path;
	GtkTreeIter iter;
	GtkTreeModel *model;
	gint* type;

	if (!event) return;
        if (((GdkEventButton *) event)->button != 1) return; 

	type = (gint*)g_object_get_data(G_OBJECT (widget), "Type");
	TypeSelOrbtmp = *type;

	if(TypeSelOrbtmp == 1) 
		gtk_tree_selection_unselect_all (gtk_tree_view_get_selection (GTK_TREE_VIEW (betalist)));
	else 
		gtk_tree_selection_unselect_all (gtk_tree_view_get_selection (GTK_TREE_VIEW (alphalist)));

	if (event->window == gtk_tree_view_get_bin_window (GTK_TREE_VIEW (widget))
	    && !gtk_tree_view_get_path_at_pos (GTK_TREE_VIEW (widget), event->x, event->y, NULL, NULL, NULL, NULL)) {
		gtk_tree_selection_unselect_all (gtk_tree_view_get_selection (GTK_TREE_VIEW (widget)));
	}
	if(gtk_tree_view_get_path_at_pos (GTK_TREE_VIEW (widget), event->x, event->y, &path, NULL, NULL, NULL))
	{
		if(path)
		{
			model = gtk_tree_view_get_model(GTK_TREE_VIEW(widget));
			gtk_tree_selection_select_path  (gtk_tree_view_get_selection (GTK_TREE_VIEW (widget)), path);
 			NumSelOrbtmp = atoi(gtk_tree_path_to_string(path));
			gtk_tree_model_get_iter (model, &iter, path);
			gtk_tree_path_free(path);
 			if ((GdkEventButton *) event && ((GdkEventButton *) event)->type==GDK_2BUTTON_PRESS)
			{
				GtkWidget* button = g_object_get_data(G_OBJECT (widget), "ButtonOk");
				gtk_button_clicked (GTK_BUTTON (button));
			}
		}
		else NumSelOrbtmp = -1;
	}
	GTK_WIDGET_GET_CLASS(widget)->button_press_event(widget, event);
}
/********************************************************************************/
GtkWidget* create_gtk_list_orbitals(gint N,gfloat* Energies,gfloat* Occ,gchar** sym, gint* widall)
{
	gint i;
	gint j;
	GtkWidget* gtklist = NULL;
	gint *Width = NULL;
	gint NlistTitle = 4;
	gchar* Titles[] = {"Nr","Energy","Occ.","Sym."};
	gchar* List[4];
	GtkListStore *store;
	GtkTreeModel *model;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeSelection *select;
	GtkTreeIter iter;
	GType* types;
  
	Width = g_malloc(NlistTitle*sizeof(gint));

	for (j=0;j<NlistTitle;j++) Width[j] = strlen(Titles[j]);

	types = g_malloc(NlistTitle*sizeof(GType));
	for (i=0;i<NlistTitle;i++) types[i] = G_TYPE_STRING;
  	store = gtk_list_store_newv (NlistTitle, types);
	g_free(types);
	model = GTK_TREE_MODEL (store);


	Width[0] = (gint)(Width[0]*10);
	Width[1] = (gint)(Width[1]*12);
	Width[2] = (gint)(Width[2]*8);
	Width[3] = (gint)(Width[3]*14);

	*widall = 0;
	for (j=0;j<NlistTitle;j++) *widall += Width[j];
	*widall += 60;

	gtklist = gtk_tree_view_new_with_model (model);
	gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (gtklist), TRUE);
	gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (gtklist), TRUE);
	gtk_tree_view_set_reorderable(GTK_TREE_VIEW (gtklist), FALSE);

	for (i=0;i<NlistTitle;i++)
	{
		column = gtk_tree_view_column_new ();
		gtk_tree_view_column_set_title (column, Titles[i]);
		renderer = gtk_cell_renderer_text_new ();
		gtk_tree_view_column_pack_start (column, renderer, TRUE);
		gtk_tree_view_column_set_min_width(column, Width[i]);
		gtk_tree_view_column_set_attributes (column, renderer, "text", i, NULL);
		gtk_tree_view_append_column (GTK_TREE_VIEW (gtklist), column);
	}
  	g_free( Width);
  
	select = gtk_tree_view_get_selection (GTK_TREE_VIEW (gtklist));
	gtk_tree_selection_set_mode (select, GTK_SELECTION_SINGLE);

	for(i=0;i<N;i++)
	{
		List[0] = g_strdup_printf("%i",i+1);
		List[1] = g_strdup_printf("%f",Energies[i]);
		List[2] = g_strdup_printf("%f",Occ[i]);
		List[3] = g_strdup(sym[i]);

		gtk_list_store_append(store, &iter);
		for(j=0;j<4;j++) gtk_list_store_set (store, &iter, j, List[j], -1);

		for(j=0;j<4;j++) g_free(List[j]);
	}
	g_signal_connect(gtklist, "button_press_event", G_CALLBACK(eventDispatcher), NULL);

	return gtklist;
 
}
/********************************************************************************/
GtkWidget* create_alpha_list(GtkWidget *hboxall)
{
	GtkWidget *frame;
	GtkWidget *scr;
	GtkWidget *vbox;
	GtkWidget *gtklist;
	gint i;
	gint N;
	gfloat* Energies;
	gfloat* Occ;
	gchar** sym;
	static gint type = 1;
	gint widall = 0;

	N = NAlphaOrb;
	Energies = g_malloc(N*sizeof(gfloat));
	Occ = g_malloc(N*sizeof(gfloat));
	sym = g_malloc(N*sizeof(gchar*));

	for(i=0;i<N;i++)
	{
		Energies[i] = EnerAlphaOrbitals[i];
		Occ[i] = OccAlphaOrbitals[i];
		sym[i] = g_strdup(SymAlphaOrbitals[i]);
	}

	gtklist = create_gtk_list_orbitals(N,Energies,Occ,sym,&widall);
	alphalist = gtklist;
	g_object_set_data(G_OBJECT (gtklist), "Type",&type);
  	frame = gtk_frame_new ("Alpha Orbitals");
  	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  	gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
	gtk_box_pack_start (GTK_BOX (hboxall), frame, TRUE, TRUE, 1);     
  	gtk_widget_show (frame);
  	vbox = create_vbox(frame);
  	scr=gtk_scrolled_window_new(NULL,NULL);
	gtk_widget_set_size_request(scr,widall,(gint)(ScreenHeight*WIDTHSCR));
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scr),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  	gtk_box_pack_start(GTK_BOX (vbox), scr,TRUE, TRUE, 2);
  	gtk_container_add(GTK_CONTAINER(scr),gtklist);

	set_base_style(gtklist,55000,55000,55000);


	for(i=0;i<N;i++)
		g_free(sym[i]);
	g_free(Energies);
	g_free(Occ);
	g_free(sym);

	return frame;

}
/********************************************************************************/
GtkWidget* create_beta_list(GtkWidget *hboxall)
{
	GtkWidget *frame;
	GtkWidget *scr;
	GtkWidget *vbox;
	GtkWidget *gtklist;
	gint i;
	gint N;
	gfloat* Energies;
	gfloat* Occ;
	gchar** sym;
	static gint type = 2;
	gint widall = 0;

	N = NBetaOrb;
	Energies = g_malloc(N*sizeof(gfloat));
	Occ = g_malloc(N*sizeof(gfloat));
	sym = g_malloc(N*sizeof(gchar*));

	for(i=0;i<N;i++)
	{
		Energies[i] = EnerBetaOrbitals[i];
		Occ[i] = OccBetaOrbitals[i];
		sym[i] = g_strdup(SymBetaOrbitals[i]);
	}

	gtklist = create_gtk_list_orbitals(N,Energies,Occ,sym,&widall);
	betalist = gtklist;
	g_object_set_data(G_OBJECT (gtklist), "Type",&type);
  	frame = gtk_frame_new ("Beta Orbitals");
  	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  	gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
	gtk_box_pack_start (GTK_BOX (hboxall), frame, TRUE, TRUE, 1);     
  	gtk_widget_show (frame);
  	vbox = create_vbox(frame);
  	scr=gtk_scrolled_window_new(NULL,NULL);
	gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scr),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
	gtk_widget_set_size_request(scr,widall,(gint)(ScreenHeight*WIDTHSCR));
  	gtk_box_pack_start(GTK_BOX (vbox), scr,TRUE, TRUE, 2);
  	gtk_container_add(GTK_CONTAINER(scr),gtklist);
	set_base_style(gtklist,55000,55000,55000);
  	gtk_widget_show (scr);
  	gtk_widget_show (gtklist);

	for(i=0;i<N;i++)
		g_free(sym[i]);
	g_free(Energies);
	g_free(Occ);
	g_free(sym);
	return frame;
	
}
/********************************************************************************/
GtkWidget *add_label_at_table(GtkWidget *Table,gchar *label,gushort line,gushort colonne,GtkJustification just)
{
	GtkWidget *Label;
	GtkWidget *hbox = gtk_hbox_new(0,FALSE);
	
	Label = gtk_label_new (label);
   	gtk_label_set_justify(GTK_LABEL(Label),just);
	if(just ==GTK_JUSTIFY_CENTER) 
		gtk_box_pack_start (GTK_BOX (hbox), Label, TRUE, TRUE, 0);
	else
		gtk_box_pack_start (GTK_BOX (hbox), Label, FALSE, FALSE, 0);
	
	add_widget_table(Table,hbox,line,colonne);

	return Label;
}
/********************************************************************************/
GtkWidget *create_iso_frame( GtkWidget *vboxall,gchar* title)
{
	GtkWidget *frame;
	GtkWidget *vboxframe;
	GtkWidget *Entry;
	gushort i;
	gushort j;
	GtkWidget *Table;
	gfloat v;
#define NLIGNES   3
#define NCOLUMNS  3
	gchar      *strlabels[NLIGNES][NCOLUMNS];
	
	strlabels[0][0] = g_strdup(" Min ");
	strlabels[1][0] = g_strdup(" Max ");
	strlabels[2][0] = g_strdup(" Value ");
	strlabels[0][1] = g_strdup(" : ");
	strlabels[1][1] = g_strdup(" : ");
	strlabels[2][1] = g_strdup(" : ");
	strlabels[0][2] = g_strdup_printf(" %f ",limits.MinMax[0][3]);
	strlabels[1][2] = g_strdup_printf(" %f ",limits.MinMax[1][3]);
	v = limits.MinMax[1][3]/4;
		
	strlabels[2][2] = g_strdup_printf("%f",v);

	frame = gtk_frame_new (title);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	gtk_container_add (GTK_CONTAINER (vboxall), frame);
	gtk_widget_show (frame);

	vboxframe = create_vbox(frame);
	Table = gtk_table_new(3,3,FALSE);
	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			if(i+j != 4)
				add_label_at_table(Table,strlabels[i][j],i,(gushort)j,GTK_JUSTIFY_LEFT);
	Entry= gtk_entry_new ();
	add_widget_table(Table,Entry,(gushort)2,(gushort)2);
	gtk_entry_set_text(GTK_ENTRY( Entry),strlabels[2][2]);

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			g_free(strlabels[i][j]);
	}
	gtk_widget_show_all(frame);
	g_object_set_data(G_OBJECT (frame), "Entry",Entry);
  
  	return frame;
}
/********************************************************************************/
static void reset_new_surface()
{
	newSurface = FALSE;
}
/********************************************************************************/
void create_iso_orbitals()
{
  GtkWidget *Win;
  GtkWidget *frame;
  GtkWidget *hbox;
  GtkWidget *vboxall;
  GtkWidget *vboxwin;
  GtkWidget *button;
  GtkWidget* Entry;


  if(!grid )
  {
	  if( !CancelCalcul)
	  	Message("Grid not defined ","Error",TRUE);
	  return;
  }
  /* Principal Window */
  Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Win),"Calculations of isosurfaces for an orbital");
  gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
  gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
  gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(PrincipalWindow));
  gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

  add_glarea_child(Win,"Iso surface ");
  g_signal_connect(G_OBJECT(Win),"delete_event",(GtkSignalFunc)reset_new_surface,NULL);

  vboxall = create_vbox(Win);
  vboxwin = vboxall;
  frame = create_iso_frame(vboxall,"Iso-Value");
  Entry = (GtkWidget*) g_object_get_data(G_OBJECT (frame), "Entry");
  g_object_set_data(G_OBJECT (Win), "Entry",Entry);
   

  /* buttons box */
  hbox = create_hbox_false(vboxwin);
  gtk_widget_realize(Win);

  button = create_button(Win,"Cancel");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)delete_child, GTK_OBJECT(Win));
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)gtk_widget_destroy,GTK_OBJECT(Win));
  gtk_widget_show (button);

  button = create_button(Win,"OK");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  gtk_widget_show (button);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)applyiso,GTK_OBJECT(Win));
  g_signal_connect_swapped(G_OBJECT (Entry), "activate", (GtkSignalFunc) gtk_button_clicked, GTK_OBJECT (button));
  

  /* Show all */
  gtk_widget_show_all (Win);
}
/********************************************************************************/
void create_grid_orbitals()
{
  TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
  create_grid("Calculations of grid for an orbital");
}
/********************************************************************************/
void create_list_orbitals()
{
  GtkWidget *Win;
  GtkWidget *frame;
  GtkWidget *hbox;
  GtkWidget *vboxall;
  GtkWidget *vboxwin;
  GtkWidget *button;

  if(NAOrb<1)
  {
	  Message("Sorry, Please load a file before\n","Error",TRUE);
	  return;
  }

  /* Principal Window */
  Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Win),"Orbitals");
  gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
  gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
  gtk_window_set_default_size (GTK_WINDOW(Win),-1,(gint)(ScreenHeight*0.69));
  gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(PrincipalWindow));
  gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

  add_glarea_child(Win,"Orbitals List ");

  vboxall = create_vbox(Win);
  vboxwin = vboxall;

  frame = gtk_frame_new (NULL);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_container_add(GTK_CONTAINER(vboxall),frame);
  gtk_widget_show (frame);
  vboxall = create_vbox(frame);
   hbox = gtk_hbox_new (TRUE, 0);
   gtk_box_pack_start (GTK_BOX (vboxall), hbox, TRUE, TRUE, 0); 

  create_alpha_list(hbox);
  create_beta_list(hbox);
  TypeSelOrbtmp = TypeSelOrb;
  NumSelOrbtmp = NumSelOrb;

  gtk_widget_show_all(vboxall);

  /* buttons box */
  hbox = create_hbox_false(vboxwin);
  gtk_widget_realize(Win);

  button = create_button(Win,"Cancel");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)delete_child, GTK_OBJECT(Win));
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)gtk_widget_destroy,GTK_OBJECT(Win));
  gtk_widget_show (button);

  button = create_button(Win,"OK");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  gtk_widget_show (button);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)create_grid_orbitals,GTK_OBJECT(Win));
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)delete_child, GTK_OBJECT(Win));
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GtkSignalFunc)gtk_widget_destroy,GTK_OBJECT(Win));

  g_object_set_data(G_OBJECT (alphalist), "ButtonOk",button);
  g_object_set_data(G_OBJECT (betalist), "ButtonOk",button);
  


  gtk_widget_show (Win);
  fit_windows_position(PrincipalWindow, Win);
  /* Show all */

  gtk_widget_show_all (Win);

  if(TypeSelOrb == 1 && NumSelOrb > -1)
  {
  	gtk_tree_selection_unselect_all (gtk_tree_view_get_selection (GTK_TREE_VIEW (betalist)));
	selectRow(alphalist,NumSelOrb);
  }
  if(TypeSelOrb == 2 && NumSelOrb > -1)
  {
  	gtk_tree_selection_unselect_all (gtk_tree_view_get_selection (GTK_TREE_VIEW (alphalist)));
	selectRow(betalist,NumSelOrb);  
  }
}
/********************************************************************************/
gchar* get_sym_orb(gchar *allstr)
{
	gchar* begin = NULL;
	gchar* end = NULL;
	begin = strstr(allstr,"(");
	if(begin)
	{
		end = strstr(begin+1,")");
		if(end)
		{
			gint l = end-begin;
			gint i;
			gchar *sym;
			if(l<=0)
				return g_strdup("Unknown");
			sym = g_malloc(l*sizeof(gchar));
			for(i=0;i<l-1;i++)
				sym[i] = begin[i+1];
			sym[l-1] = '\0';
			return sym;
		}
		else
			return g_strdup("Unknown");
	}
	else 
		return g_strdup("Unknown");

}
/********************************************************************************/
static void save_geometry_gabedit_format(FILE* file)
{
	gint j;
	fprintf(file,"[Atoms] Angs\n");
	for(j=0;j<Ncenters;j++)
	{
		fprintf(file,"%s %d %d %f %f %f\n",GeomOrb[j].Symb,j+1,(gint)GeomOrb[j].Prop.atomicNumber,
				BOHR_TO_ANG*GeomOrb[j].C[0],BOHR_TO_ANG*GeomOrb[j].C[1],BOHR_TO_ANG*GeomOrb[j].C[2]);
	}
}
/********************************************************************************/
static void save_mo_orbitals_gabedit_format(FILE* file)
{
	gint i;
	gint j;
	fprintf(file,"[MO]\n");
	for(j=0;j<NAlphaOrb;j++)
	{

		fprintf(file," Ene= %f\n",EnerAlphaOrbitals[j]);
		fprintf(file," Spin= Alpha\n");
		fprintf(file," Occup= %f\n",OccAlphaOrbitals[j]);
		fprintf(file," Sym= %s\n",SymAlphaOrbitals[j]);
		for(i=0;i<NOrb;i++)
			fprintf(file,"     %d    %f\n",i+1, CoefAlphaOrbitals[j][i]);
	}
	for(j=0;j<NBetaOrb;j++)
	{

		fprintf(file," Ene= %f\n",EnerBetaOrbitals[j]);
		fprintf(file," Spin= Beta\n");
		fprintf(file," Occup= %f\n",OccBetaOrbitals[j]);
		fprintf(file," Sym= %s\n",SymBetaOrbitals[j]);
		for(i=0;i<NOrb;i++)
			fprintf(file,"     %d    %f\n",i+1, CoefBetaOrbitals[j][i]);
	}
	fprintf(file,"\n");
}
/********************************************************************************/
static void save_gabedit_orbitals(gchar* FileName)
{
 	FILE *file;
 	file = FOpen(FileName, "w");
	if(file == NULL)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not create '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return;
	}
	if(sphericalBasis)
		fprintf(file,"[Gabedit Format] Sphe\n");
	else
		fprintf(file,"[Gabedit Format]\n");
	save_geometry_gabedit_format(file);
	save_basis_gabedit_format(file);
	save_mo_orbitals_gabedit_format(file);
	save_ao_orbitals_gabedit_format(file);
	fclose(file);
}
/********************************************************************************/
gboolean read_last_orbitals_in_gaussian_file(gchar *NomFichier,gint itype)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *fd;
 	gint taille=BSIZE;
 	gint i;
 	gint numorb;
 	gchar *pdest = NULL;
	gint NumOrb[5];
	gchar SymOrb[5][10];
	gfloat EnerOrb[5];
	gchar *dump1= g_malloc(20);
	gchar *dump2= g_malloc(20);
	gint ncart;
	gint n;
	gint k;
	gfloat **CoefOrbitals;
	gfloat *EnerOrbitals;
	gchar **SymOrbitals;
	gchar* tmp = NULL;
	gint NOcc = 0;
	
 	if ((!NomFichier) || (strcmp(NomFichier,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return FALSE;
 	}

 	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r");
 	if(fd ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
  		return FALSE;
 	}
 	for(i=0;i<5;i++)
		AtomCoord[i]=g_malloc(taille*sizeof(char));
  
	/* Debug("Norb = %d\n",NOrb);*/
	CoefOrbitals = CreateTable2(NOrb);
	EnerOrbitals = g_malloc(NOrb*sizeof(gfloat));
	SymOrbitals = g_malloc(NOrb*sizeof(gchar*));

 	numorb =1;
 	do 
 	{
 		OK=FALSE;
 		while(!feof(fd))
		{
	  		fgets(t,taille,fd);
			switch(itype)
			{
			case 1 :
          			pdest = strstr( t, "Alpha Molecular Orbital Coefficients" );
					break;
			case 2 :
          			pdest = strstr( t, "Beta Molecular Orbital Coefficients" );
					break;
			case 3: 
          			pdest = strstr( t, "Molecular Orbital Coefficients" );
					break;
			}
	 		if ( pdest != NULL )
	  		{
                		numorb++;
                		OK = TRUE;
	  			break;
	  		}
        }
 		if(!OK && (numorb == 1) )
		{
			if(itype!=1)
			{
				gchar buffer[BSIZE];
				sprintf(buffer,"Sorry,  I can not read orbitals from '%s' file\n",NomFichier);
  				Message(buffer,"Error",TRUE);
			}
			FreeTable2(CoefOrbitals,NOrb);
			g_free(EnerOrbitals);
			g_free(SymOrbitals);
			return FALSE;
    	}
 		if(!OK)
		{
			/* Debug("End of read \n");*/
 			fclose(fd);
 			g_free(t);
 			for(i=0;i<5;i++)
				g_free(AtomCoord[i]);

			switch(itype)
			{
			case 1 : 
				CoefAlphaOrbitals = CoefOrbitals;
				EnerAlphaOrbitals = EnerOrbitals;
				
				SymAlphaOrbitals = SymOrbitals;

				OccAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
				for(i=0;i<NOcc;i++)
					OccAlphaOrbitals[i] = 1.0;
				for(i=NOcc;i<NOrb;i++)
					OccAlphaOrbitals[i] = 0.0;

				NAlphaOcc = NOcc;
				NAlphaOrb = NOrb;
				break;
			case 2 : 
				CoefBetaOrbitals = CoefOrbitals;
				EnerBetaOrbitals = EnerOrbitals;
				SymBetaOrbitals = SymOrbitals;

				OccBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
				for(i=0;i<NOcc;i++)
					OccBetaOrbitals[i] = 1.0;
				for(i=NOcc;i<NOrb;i++)
					OccBetaOrbitals[i] = 0.0;

				NBetaOcc = NOcc;
				NBetaOrb = NOrb;
				break;
			case 3 : 
				CoefAlphaOrbitals = CoefOrbitals;
				EnerAlphaOrbitals = EnerOrbitals;
				SymAlphaOrbitals = SymOrbitals;
				OccAlphaOrbitals = g_malloc(NOrb*sizeof(gfloat));
				for(i=0;i<NOcc;i++)
					OccAlphaOrbitals[i] = 1.0;
				for(i=NOcc;i<NOrb;i++)
					OccAlphaOrbitals[i] = 0.0;

				CoefBetaOrbitals = CoefOrbitals;
				EnerBetaOrbitals = EnerOrbitals;
				OccBetaOrbitals = OccAlphaOrbitals;
				SymBetaOrbitals = SymOrbitals;
				NAlphaOcc = NOcc;
				NBetaOcc = NOcc;
				NAlphaOrb = NOrb;
				NBetaOrb = NOrb;
				break;
			}
			return TRUE;
    		}

		NOcc = 0;
  		ncart=NOrb/5;
		for(n=0;n<ncart;n++)
		{
	  		fgets(t,taille,fd);
			sscanf(t,"%d %d %d %d %d",&NumOrb[0],&NumOrb[1],&NumOrb[2],&NumOrb[3],&NumOrb[4]);
			for(i=0;i<5;i++)
			   NumOrb[i]--;

	  		fgets(t,taille,fd);
			/* Debug("%d %d %d %d %d\n",NumOrb[0],NumOrb[1],NumOrb[2],NumOrb[3],NumOrb[4]);*/
			sscanf(t,"%s %s %s %s %s",SymOrb[0],SymOrb[1],SymOrb[2],SymOrb[3],SymOrb[4]);
			/* Debug("%s %s %s %s %s\n",SymOrb[0],SymOrb[1],SymOrb[2],SymOrb[3],SymOrb[4]);*/
			for(i=0;i<5;i++)
                	if(strstr(SymOrb[i],"O"))
					NOcc++;
			for(i=0;i<5;i++)
			   SymOrbitals[NumOrb[i]] = get_sym_orb(SymOrb[i]);
			
	  		fgets(t,taille,fd);
			sscanf(t,"%s %s %f %f %f %f %f",dump1,dump2,
				&EnerOrb[0], &EnerOrb[1], &EnerOrb[2], &EnerOrb[3], &EnerOrb[4]);
			for(i=0;i<5;i++)
                        	EnerOrbitals[NumOrb[i]] = EnerOrb[i];
			for(i=0;i<NOrb;i++)
			{
	  			fgets(t,taille,fd);
				tmp = t + 20;
				k = sscanf(tmp,"%f %f %f %f %f",&CoefOrbitals[NumOrb[0]][i],&CoefOrbitals[NumOrb[1]][i],
				&CoefOrbitals[NumOrb[2]][i],&CoefOrbitals[NumOrb[3]][i],&CoefOrbitals[NumOrb[4]][i]);
			}
		}
		/* Debug("End ncart\n"); */
		
		if(NOrb%5 !=0)
		{
		  switch(NOrb%5)
		  {
			case 1:
	  			fgets(t,taille,fd);
				sscanf(t,"%d",&NumOrb[0]);
				for(i=0;i<5;i++)
					NumOrb[i]--;
	  			fgets(t,taille,fd);
				sscanf(t,"%s",SymOrb[0]);
				if(strstr(SymOrb[0],"O"))
						NOcc++;
				SymOrbitals[NumOrb[0]] = get_sym_orb(SymOrb[0]);

	  			fgets(t,taille,fd);
				sscanf(t,"%s %s %f ",dump1,dump2,&EnerOrb[0]);
                        	EnerOrbitals[NumOrb[0]] = EnerOrb[0];
				for(i=0;i<NOrb;i++)
				{
	  				fgets(t,taille,fd);
					tmp = t + 20;
					k = sscanf(tmp,"%f ",&CoefOrbitals[NumOrb[0]][i]);
				}
				break;

			case 2:
	  			fgets(t,taille,fd);
				sscanf(t,"%d %d",&NumOrb[0],&NumOrb[1]);
				for(i=0;i<5;i++)
					NumOrb[i]--;
	  			fgets(t,taille,fd);
				sscanf(t,"%s %s",SymOrb[0],SymOrb[1]);
				for(i=0;i<2;i++)
					if(strstr(SymOrb[i],"O"))
						NOcc++;
				for(i=0;i<2;i++)
					SymOrbitals[NumOrb[i]] = get_sym_orb(SymOrb[i]);

	  			fgets(t,taille,fd);
				sscanf(t,"%s %s %f %f",dump1,dump2,&EnerOrb[0], &EnerOrb[1]);
				for(i=0;i<2;i++)
                        		EnerOrbitals[NumOrb[i]] = EnerOrb[i];
				for(i=0;i<NOrb;i++)
				{
	  				fgets(t,taille,fd);
					tmp = t + 20;
					k = sscanf(tmp,"%f %f ",&CoefOrbitals[NumOrb[0]][i],&CoefOrbitals[NumOrb[1]][i]);
				}
				break;
			case 3:
	  			fgets(t,taille,fd);
				sscanf(t,"%d %d %d",&NumOrb[0],&NumOrb[1],&NumOrb[2]);
				for(i=0;i<5;i++)
					NumOrb[i]--;
	  			fgets(t,taille,fd);
				sscanf(t,"%s %s %s",SymOrb[0],SymOrb[1],SymOrb[2]);
				for(i=0;i<3;i++)
					if(strstr(SymOrb[i],"O"))
						NOcc++;
				for(i=0;i<3;i++)
					SymOrbitals[NumOrb[i]] = get_sym_orb(SymOrb[i]);

	  			fgets(t,taille,fd);
				sscanf(t,"%s %s %f %f %f ",dump1,dump2,&EnerOrb[0], &EnerOrb[1], &EnerOrb[2]);
				for(i=0;i<3;i++)
                        		EnerOrbitals[NumOrb[i]] = EnerOrb[i];
				for(i=0;i<NOrb;i++)
				{
	  				fgets(t,taille,fd);
					tmp = t + 20;
					k = sscanf(tmp,"%f %f %f ",&CoefOrbitals[NumOrb[0]][i],&CoefOrbitals[NumOrb[1]][i],&CoefOrbitals[NumOrb[2]][i]);
				}
				break;
			case 4:
	  			fgets(t,taille,fd);
				sscanf(t,"%d %d %d %d",&NumOrb[0],&NumOrb[1],&NumOrb[2],&NumOrb[3]);
				for(i=0;i<5;i++)
					NumOrb[i]--;
	  			fgets(t,taille,fd);
				sscanf(t,"%s %s %s %s",SymOrb[0],SymOrb[1],SymOrb[2],SymOrb[3]);
				for(i=0;i<4;i++)
					if(strstr(SymOrb[i],"O"))
						NOcc++;
				for(i=0;i<4;i++)
					SymOrbitals[NumOrb[i]] = get_sym_orb(SymOrb[i]);

	  			fgets(t,taille,fd);
				sscanf(t,"%s %s %f %f %f %f",dump1,dump2,
					&EnerOrb[0], &EnerOrb[1], &EnerOrb[2], &EnerOrb[3]);
				for(i=0;i<4;i++)
                        		EnerOrbitals[NumOrb[i]] = EnerOrb[i];
				for(i=0;i<NOrb;i++)
				{
	  				fgets(t,taille,fd);
					tmp = t + 20;
					k = sscanf(tmp,"%f %f %f %f",
					&CoefOrbitals[NumOrb[0]][i],&CoefOrbitals[NumOrb[1]][i],&CoefOrbitals[NumOrb[2]][i],&CoefOrbitals[NumOrb[3]][i]);
					
				}
		  }
			
		}
 	}while(!feof(fd));

	/* Debug("End of read \n"); */
 	fclose(fd);
 	g_free(t);
 	for(i=0;i<5;i++)
		g_free(AtomCoord[i]);

	CoefAlphaOrbitals = CoefOrbitals;
	EnerAlphaOrbitals = EnerOrbitals;
	return TRUE;
}
/********************************************************************************/
gboolean read_orbitals_in_gabedit_or_molden_file(gchar *NomFichier,gint itype)
{
 	gchar *t;
 	gboolean OK;
 	gchar *AtomCoord[5];
 	FILE *fd;
 	gint taille=BSIZE;
 	gint i;
 	gint numorb;
 	gchar *pdest;
	gint n = 0;
	gfloat **CoefOrbitals;
	gfloat *EnerOrbitals;
	gfloat *OccOrbitals;
	gchar **SymOrbitals;
	gint NOcc = 0;
	gint idump;

	
 	if ((!NomFichier) || (strcmp(NomFichier,"") == 0))
 	{
		Message("Sorry No file slected\n","Error",TRUE);
    		return FALSE;
 	}

 	t=g_malloc(taille);
 	fd = FOpen(NomFichier, "r");
 	if(fd ==NULL)
 	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  		Message(buffer,"Error",TRUE);
  		return FALSE;
 	}

 	for(i=0;i<5;i++)
		AtomCoord[i]=g_malloc(taille*sizeof(char));
  
	CoefOrbitals = CreateTable2(NOrb);
	EnerOrbitals = g_malloc(NOrb*sizeof(gfloat));
	OccOrbitals = g_malloc(NOrb*sizeof(gfloat));
	SymOrbitals = g_malloc(NOrb*sizeof(gchar*));

 	numorb =1;
 	do 
 	{
 		OK=FALSE;
 		while(!feof(fd))
		{
	  		fgets(t,taille,fd);
          	pdest = strstr( t, "[MO]" );
	 		if ( pdest != NULL )
	  		{
                numorb++;
                OK = TRUE;
	  			break;
	  		}
        }
 		if(!OK && (numorb == 1) )
		{
			gchar buffer[BSIZE];
			sprintf(buffer,"Sorry, I can not open '%s' file\n",NomFichier);
  			Message(buffer,"Error",TRUE);
			FreeTable2(CoefOrbitals,NOrb);
			g_free(EnerOrbitals);
			g_free(SymOrbitals);
			return FALSE;
    	}
 		if(!OK)
		{
			goto end;
    	}

		n = -1;
		while(!feof(fd))
		{
			gdouble e = 0.0;
			gdouble o = 0.0;
			gchar* begin = NULL;
			gchar* spin = NULL;
			gchar sym[BSIZE];
			gboolean begincoef = FALSE;
			
			/* 
			 * Ene=      -2.5353 
			 * Spin= Alpha 
			 * Occup=   2.000000
			 */
			sym[0] = '\0';
			while(!feof(fd) && !begincoef)
			{
	  			fgets(t,taille,fd);
				if( this_is_a_backspace(t))
				{
					begincoef = FALSE;
					break;
				}
				if(atoi(t) != 0)
				{
					begincoef = TRUE;
					break;
				}
				begin = strstr(t,"=")+1;
				if(strstr(t,"Ene")!= 0)
					e = atof(begin);
			
				if( strstr(t,"Occ") != 0)
					o = atof(begin);

				if( strstr(t,"Spin") != 0)
					spin = g_strdup(begin);

				if( strstr(t,"Sym") != 0)
					sscanf(begin,"%s",sym);
			}
			if(!begincoef || feof(fd))
				break;
			if(!spin)
				continue;
			if(strstr(spin,"Alpha") && itype == 2)
				continue;
			if(strstr(spin,"Beta") && itype == 1)
				continue;

			n++;
			EnerOrbitals[n] = e;
			if(sym[0] != '\0')
				SymOrbitals[n] = g_strdup(sym);
			else
				SymOrbitals[n] = g_strdup("Unknown");

			OccOrbitals[n] = o;

			if(o>0)
				NOcc++;

			sscanf(t,"%d %f",&idump,&CoefOrbitals[n][0]);
			for(i=1;i<NAOrb;i++)
			{
	  			fgets(t,taille,fd);
				sscanf(t,"%d %f",&idump,&CoefOrbitals[n][i]);
			}
			if(n == NOrb-1)
				OK = FALSE;
		}
		
 	}while(!feof(fd));

end:
	/* Debug("End of read \n");*/
 	fclose(fd);
 	g_free(t);
	for(i=0;i<5;i++)
		g_free(AtomCoord[i]);

	switch(itype)
	{
		case 1 : 
			CoefAlphaOrbitals = CoefOrbitals;
			EnerAlphaOrbitals = EnerOrbitals;
			OccAlphaOrbitals = OccOrbitals;
			SymAlphaOrbitals = SymOrbitals;
			NAlphaOcc = NOcc;
			NAlphaOrb = n+1;
			break;
		case 2 : 
			CoefBetaOrbitals = CoefOrbitals;
			EnerBetaOrbitals = EnerOrbitals;
			OccBetaOrbitals = OccOrbitals;
			SymBetaOrbitals = SymOrbitals;
			NBetaOcc = NOcc;
			NBetaOrb = n+1;
			break;
		case 3 : 
			CoefAlphaOrbitals = CoefOrbitals;
			EnerAlphaOrbitals = EnerOrbitals;
			OccAlphaOrbitals = OccOrbitals;
			SymAlphaOrbitals = SymOrbitals;
			CoefBetaOrbitals = CoefOrbitals;
			EnerBetaOrbitals = EnerOrbitals;
			OccBetaOrbitals = OccOrbitals;
			SymBetaOrbitals = SymOrbitals;
			NAlphaOcc = NOcc;
			NBetaOcc = NOcc;
			NAlphaOrb = n+1;
			NBetaOrb = n+1;
			break;
		}
		if(n<0)
			return FALSE;
		else
			return TRUE;
}

/********************************************************************************/
void read_gauss_orbitals(gchar* FileName)
{
	gint typefile;
	gint typebasis;
	gboolean Ok = FALSE;
	gchar *t = NULL;


	typefile =get_type_file(FileName);
	if(typefile==GABEDIT_TYPEFILE_UNKNOWN) return;
	if(typefile != GABEDIT_TYPEFILE_GAUSSIAN)
	{
		gchar buffer[BSIZE];
		sprintf(buffer,"Sorry, I can not read this format in '%s' file\n",FileName);
  		Message(buffer,"Error",TRUE);
		return ;
	}
	free_data_all();
	t = get_name_file(FileName);
	set_status_label_info("File Name",t);
	g_free(t);
	set_status_label_info("File Type","Gaussian");
	set_status_label_info("Mol. Orb.","Reading");
	
	free_orbitals();	
 	if(!gl_read_gaussn_file_geomi(FileName,-1))
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}

	set_status_label_info("Mol. Orb.","Reading");
 	InitializeAll();
 	if(!DefineBasisType(FileName))
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}

	typebasis =get_type_basis_in_gaussian_file(FileName);

	if(typebasis == 1)
	{
 		DefineSphericalBasis();
		sphericalBasis = TRUE;
	}
	else
	{
 		DefineCartBasis();
		sphericalBasis = FALSE;
	}
 	
 	/* PrintAllBasis();*/
 	NormaliseAllBasis();
 	/* PrintAllBasis();*/
 	DefineNOccs();


	Ok = read_last_orbitals_in_gaussian_file(FileName,1);
	if(Ok)
	{
		Ok = read_last_orbitals_in_gaussian_file(FileName,2);
	}
	else
	{
		Ok = read_last_orbitals_in_gaussian_file(FileName,3);
	}
	if(Ok)
	{
		/*PrintAllOrb(CoefAlphaOrbitals);*/
		set_status_label_info("Mol. Orb.","Ok");
		glarea_rafresh(GLArea); /* for geometry*/
		NumSelOrb = NAlphaOcc-1;
		create_list_orbitals();
	}
	else
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
	}

} 
/********************************************************************************/
void read_gabedit_orbitals(gchar* FileName)
{
	gint i;
	gint typefile;
	gint typebasis;
	gboolean OkAlpha = FALSE;
	gboolean OkBeta = FALSE;
	gchar* t = NULL;

	typefile =get_type_file(FileName);

	if(typefile==GABEDIT_TYPEFILE_UNKNOWN)
		return;

	if(typefile != GABEDIT_TYPEFILE_GABEDIT)
	{
		Message("Sorry, This file is not in Gabedit Format\n","Error",TRUE);
		return ;
	}
	free_data_all();
	t = get_name_file(FileName);
	set_status_label_info("File Name",t);
	g_free(t);
	set_status_label_info("File Type","Gabedit");
	set_status_label_info("Mol. Orb.","Reading");
	free_orbitals();	
 	if(!gl_read_gabedit_file_geom(FileName))
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}
 	InitializeAll();
 	if(!DefineGabeditBasisType(FileName))
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}
	
	typebasis =get_type_basis_in_gabedit_file(FileName);
	if(typebasis == 1)
	{
 		DefineSphericalBasis();
		sphericalBasis = TRUE;
	}
	else
	{
 		DefineCartBasis(); 	
		sphericalBasis = FALSE;
	}
 	NormaliseAllBasis();
 	/* PrintAllBasis();*/

 	DefineNOccs();

	OkBeta = read_orbitals_in_gabedit_or_molden_file(FileName,2);/* if beta orbital*/
	OkAlpha = read_orbitals_in_gabedit_or_molden_file(FileName,1);
	if(!OkBeta && OkAlpha)
	{
		CoefBetaOrbitals = CoefAlphaOrbitals;
		EnerBetaOrbitals = EnerAlphaOrbitals;		
		SymBetaOrbitals = SymAlphaOrbitals;
		NBetaOrb = NAlphaOrb;

		OccBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		NBetaOcc = 0;
		for(i=0;i<NBetaOrb;i++)
		{
			if(OccAlphaOrbitals[i]>1.0)
			{
				NBetaOcc++;
				OccBetaOrbitals[i] = OccAlphaOrbitals[i]/2;
				OccAlphaOrbitals[i] = OccBetaOrbitals[i];
			}
			else
				OccBetaOrbitals[i] = 0.0;
		}
		if(NBetaOrb>0)
			OkBeta = TRUE;
	}
	if(OkAlpha || OkBeta)
	{
		read_gabedit_atomic_orbitals(FileName);
		set_status_label_info("Mol. Orb.","Ok");
		glarea_rafresh(GLArea); /* for geometry*/
		NumSelOrb = NAlphaOcc-1;
		create_list_orbitals();
	}
	else
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
	}
}
/********************************************************************************/
void read_molden_orbitals(gchar* FileName)
{
	gint i;
	gint typefile;
	gint typebasis;
	gboolean OkAlpha = FALSE;
	gboolean OkBeta = FALSE;
 	gchar *t = NULL;

	typefile =get_type_file(FileName);

	if(typefile==GABEDIT_TYPEFILE_UNKNOWN)
		return;
	if(typefile != GABEDIT_TYPEFILE_MOLDEN)
	{
		Message("Sorry, This file is not in Molden Format\n","Error",TRUE);
		return ;
	}
	free_data_all();
	t = get_name_file(FileName);
	set_status_label_info("File Name",t);
	g_free(t);
	set_status_label_info("File Type","Molden");
	set_status_label_info("Mol. Orb.","Reading");

	free_orbitals();	
 	if(!gl_read_molden_file_geom(FileName))
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}

 	InitializeAll();
 	if(!DefineMoldenBasisType(FileName))
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
		return;
	}
 	/* Debug("End define Basis Type NAOrb = %d \n",NAOrb); */
 	/* PrintBasis();*/
 	/* Debug("End Print Basis\n"); */
	
	typebasis =get_type_basis_in_molden_file(FileName);
	/* printf("typebasis = %d\n",typebasis);*/
	if(typebasis == 1)
	{
 		DefineSphericalBasis();
		sphericalBasis = TRUE;
	}
	else
	{
 		DefineCartBasis();
		sphericalBasis = FALSE;
	}
 	
	/* Debug("End DefineBasis\n");*/
 	/* PrintAllBasis();*/
 	NormaliseAllBasis();
 	/* PrintAllBasis();*/
 	/* Debug("Spherical basis(Norb=%d)\n",NAOrb);*/
 	DefineNOccs();


	OkBeta = read_orbitals_in_gabedit_or_molden_file(FileName,2);/* if beta orbital*/
	/* Debug("Ok = %d\n",Ok);*/
	OkAlpha = read_orbitals_in_gabedit_or_molden_file(FileName,1);
	if(!OkBeta && OkAlpha)
	{
		CoefBetaOrbitals = CoefAlphaOrbitals;
		EnerBetaOrbitals = EnerAlphaOrbitals;		
		SymBetaOrbitals = SymAlphaOrbitals;
		NBetaOrb = NAlphaOrb;

		OccBetaOrbitals = g_malloc(NOrb*sizeof(gfloat));
		NBetaOcc = 0;
		for(i=0;i<NBetaOrb;i++)
		{
			if(OccAlphaOrbitals[i]>1.0)
			{
				NBetaOcc++;
				OccBetaOrbitals[i] = OccAlphaOrbitals[i]/2;
				OccAlphaOrbitals[i] = OccBetaOrbitals[i];
			}
			else
				OccBetaOrbitals[i] = 0.0;
		}
		if(NBetaOrb>0)
			OkBeta = TRUE;
	}
	/* Debug("NA = %d\n",NAlphaOcc); */
	/* Debug("NB = %d\n",NBetaOcc);*/
	if(OkBeta || OkAlpha)
	{
		/* PrintAllOrb(CoefAlphaOrbitals); */
		set_status_label_info("Mol. Orb.","Ok");
		glarea_rafresh(GLArea); /* for geometry */
		NumSelOrb = NAlphaOcc-1;
		create_list_orbitals();
	}
	else
	{
		set_status_label_info("File Name","Nothing");
		set_status_label_info("File Type","Nothing");
		set_status_label_info("Mol. Orb.","Nothing");
	}

}
/********************************************************************************/
void read_dalton_orbitals_sel(GabeditFileChooser *SelecFile, gint response_id)
{
 	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() ) gtk_main_iteration();

	add_objects_for_new_grid();
 	/* read_dalton_orbitals(FileName);*/
} 
/********************************************************************************/
void read_gauss_orbitals_sel(GabeditFileChooser *SelecFile, gint response_id)
{
 	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();

	add_objects_for_new_grid();
 	read_gauss_orbitals(FileName);
} 
/********************************************************************************/
void read_molpro_orbitals_sel(GabeditFileChooser *SelecFile, gint response_id)
{
 	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();

	add_objects_for_new_grid();
 	read_molpro_orbitals(FileName);
	sphericalBasis = TRUE;
} 
/********************************************************************************/
void read_gabedit_orbitals_sel(GabeditFileChooser *SelecFile, gint response_id)
{
 	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();

	add_objects_for_new_grid();
 	read_gabedit_orbitals(FileName);
} 
/********************************************************************************/
void save_gabedit_orbitals_sel(GabeditFileChooser *SelecFile, gint response_id)
{
 	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();

 	save_gabedit_orbitals(FileName);
} 
/********************************************************************************/
void read_molden_orbitals_sel(GabeditFileChooser *SelecFile, gint response_id)
{
 	gchar *FileName;

	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();

	add_objects_for_new_grid();
 	read_molden_orbitals(FileName);
} 

