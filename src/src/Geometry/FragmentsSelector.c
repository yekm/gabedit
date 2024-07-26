/* FragmentsSelector.c */
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
#include <math.h>

#include "../Common/Global.h"
#include "../Utils/Constantes.h"
#include "../Utils/UtilsInterface.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Utils/Utils.h"
#include "../Utils/PovrayUtils.h"
#include "../Utils/AtomsProp.h"
#include "../Geometry/GeomGlobal.h"
#include "../Common/Windows.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/PreviewGeom.h"
#include "../Geometry/FragmentsTree.h"

/********************************************************************************/
void hide_fragments_selector()
{
  	GtkWidget* FragmentsSelectorDlg = NULL;
	FragmentsSelectorDlg = g_object_get_data(G_OBJECT(GeomDlg), "FragmentsSelectorDlg");
	if( FragmentsSelectorDlg) gtk_widget_hide(FragmentsSelectorDlg);
}
/********************************************************************************/
void show_fragments_selector()
{
  	GtkWidget* FragmentsSelectorDlg = NULL;
	FragmentsSelectorDlg = g_object_get_data(G_OBJECT(GeomDlg), "FragmentsSelectorDlg");
	if( FragmentsSelectorDlg) gtk_widget_hide(FragmentsSelectorDlg);
}
/********************************************************************************/
void rafresh_fragments_selector()
{
  	GtkWidget* FragmentsSelectorDlg = NULL;
	GtkWidget* treeView = NULL;
	FragmentsSelectorDlg = g_object_get_data(G_OBJECT(GeomDlg), "FragmentsSelectorDlg");
	if( FragmentsSelectorDlg) treeView = g_object_get_data(G_OBJECT(FragmentsSelectorDlg), "TreeView");
	if( treeView) rafreshTreeView(treeView);
}
/********************************************************************************/
void create_window_fragments_selector()
{
	GtkWidget *vboxframe;
	GtkWidget *frame;
	GtkWidget *hboxframe;
	GtkWidget *VboxWin;
  	GtkWidget* FragmentsSelectorDlg = NULL;
  	GtkWidget* drawingArea = NULL;
	GtkWidget* treeView = NULL;

	FragmentsSelectorDlg = g_object_get_data(G_OBJECT(GeomDlg), "FragmentsSelectorDlg");
	if(!FragmentsSelectorDlg || !GTK_IS_OBJECT(FragmentsSelectorDlg))
	{
		FragmentsSelectorDlg = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		g_object_set_data(G_OBJECT(GeomDlg), "FragmentsSelectorDlg", FragmentsSelectorDlg);
	}
	else
	{
		gtk_widget_show(FragmentsSelectorDlg);
		return;
	}

	VboxWin = gtk_vbox_new (TRUE, 0);
	gtk_container_add(GTK_CONTAINER(FragmentsSelectorDlg),VboxWin);
	gtk_widget_show(VboxWin);

	gtk_window_set_title(GTK_WINDOW(FragmentsSelectorDlg),"Gabedit : Fragment Selector ");
	gtk_window_set_transient_for(GTK_WINDOW(FragmentsSelectorDlg),GTK_WINDOW(GeomDlg));
	gtk_widget_add_events(GeomDlg,GDK_KEY_RELEASE_MASK);
   

	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);
	add_child(GeomDlg,FragmentsSelectorDlg, gtk_widget_destroy," Frag. Sel. ");
	g_signal_connect (GTK_OBJECT (FragmentsSelectorDlg), "delete_event", GTK_SIGNAL_FUNC (gtk_widget_hide), NULL);

	frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 1);
	gtk_box_pack_start(GTK_BOX(VboxWin), frame,TRUE,TRUE,1);
	gtk_widget_show (frame);

	vboxframe = create_vbox(frame);
	gtk_widget_show (vboxframe);


	hboxframe = gtk_hbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vboxframe), hboxframe, TRUE, TRUE, 0);
	treeView = addFragmentsTreeView(hboxframe);
	gtk_widget_show_all (hboxframe);

	hboxframe = gtk_hbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vboxframe), hboxframe, TRUE, TRUE, 0);
	gtk_widget_show (hboxframe);

  	drawingArea = add_preview_geom(hboxframe);
	g_object_set_data(G_OBJECT(FragmentsSelectorDlg), "DrawingArea", drawingArea);
	g_object_set_data(G_OBJECT(FragmentsSelectorDlg), "TreeView", treeView);
	g_object_set_data(G_OBJECT(treeView), "DrawingArea", drawingArea);

    	gtk_widget_set_size_request(GTK_WIDGET(FragmentsSelectorDlg),(gint)(ScreenHeight*0.35),(gint)(ScreenHeight*0.7));
	

	gtk_widget_show (FragmentsSelectorDlg);
	fit_windows_position(GeomDlg,FragmentsSelectorDlg);
	add_a_fragment(FragmentsSelectorDlg,"Amine");

}
