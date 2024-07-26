/* PreferencesOrb.c */
/**********************************************************************************************************
Copyright (c) 2002-2009 Abdul-Rahman Allouche. All rights reserved

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
#include "../OpenGL/GlobalOrb.h"
#include "../OpenGL/GLArea.h"
#include "../OpenGL/Orbitals.h"
#include "../OpenGL/UtilsOrb.h"
#include "../Utils/Vector3d.h"
#include "../OpenGL/TriangleDraw.h"
#include "../Utils/UtilsInterface.h"
#include "../Common/Windows.h"
#include "../OpenGL/MenuToolBarGL.h"
/********************************************************************************/
void destroy_selectors_window(GtkWidget* Win,gpointer data)
{
  GtkWidget**selectors =(GtkWidget**) g_object_get_data(G_OBJECT (Win), "Selectors");
  delete_child(Win);
  g_free(selectors);
}
/********************************************************************************/
void apply_colorselections(GtkWidget* Win,gpointer data)
{
	gdouble Col[4];
	GdkColor color;
  	GtkColorButton**selectors =(GtkColorButton**) g_object_get_data(G_OBJECT (Win), "Selectors");

	/* positive value */
	gtk_color_button_get_color (selectors[0], &color);
	Col[0] = color.red/65535.0;
	Col[1] = color.green/65535.0;
	Col[2] = color.blue/65535.0;
	set_color_surface(0,Col);

	/* negative value */
	gtk_color_button_get_color (selectors[1], &color);
	Col[0] = color.red/65535.0;
	Col[1] = color.green/65535.0;
	Col[2] = color.blue/65535.0;
	set_color_surface(1,Col);
	/* density surface */
	gtk_color_button_get_color (selectors[2], &color);
	Col[0] = color.red/65535.0;
	Col[1] = color.green/65535.0;
	Col[2] = color.blue/65535.0;
	set_color_surface(2,Col);
	RebuildSurf = TRUE;
	rafresh_window_orb();

	destroy_selectors_window(Win,data);
}
/********************************************************************************/
GtkWidget *create_colorsel_frame(GtkWidget *vboxall,gchar* title,GtkWidget** selectors)
{
	GtkWidget *frame;
	GtkWidget *Frame;
	GtkWidget *vboxframe;
	GtkWidget *selector;
	gushort i;
	gushort j;
	GtkWidget *Table;
	gint num = -1;
	gdouble v[3];
	GdkColor color;

	Frame = gtk_frame_new (title);
	gtk_container_set_border_width (GTK_CONTAINER (Frame), 5);
	gtk_container_add (GTK_CONTAINER (vboxall), Frame);
	gtk_widget_show (Frame);

	vboxframe = create_vbox(Frame);
	Table = gtk_table_new(2,2,FALSE);
	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			num++;
			if(num==3) break;

			get_color_surface(num,v);
			frame = NULL;
			switch(num)
			{
				case 0 : frame = gtk_frame_new ("Positive value");break;
				case 1 : frame = gtk_frame_new ("Negative value");break;
				case 2 : frame = gtk_frame_new ("Density");break;
				default : break;
			}
			add_widget_table(Table,frame,(gushort)i,(gushort)j);
			vboxframe = create_vbox(frame);

			color.red = (gushort)(v[0]*65535);
			color.green = (gushort)(v[1]*65535);
			color.blue = (gushort)(v[2]*65535);

			selector = gtk_color_button_new_with_color (&color);

			gtk_widget_show(selector);
			gtk_widget_show(frame);
			gtk_container_add(GTK_CONTAINER(vboxframe),selector);
			selectors[num] = selector;
		}
	}

	gtk_widget_show(Table);
	gtk_widget_show(Frame);
  
  	return Frame;
}
/********************************************************************************/
void set_colors_surfaces(gchar* title)
{
  GtkWidget *Win;
  GtkWidget *frame;
  GtkWidget *hbox;
  GtkWidget *vboxall;
  GtkWidget *vboxwin;
  GtkWidget *button;
  GtkWidget **selectors = g_malloc(3*sizeof(GtkWidget*));


  /* Principal Window */
  Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Win),title);
  gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
  gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
  gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(PrincipalWindow));
  gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

  add_glarea_child(Win,"Set Colors ");

  vboxall = create_vbox(Win);
  vboxwin = vboxall;
  frame = create_colorsel_frame(vboxall,NULL,selectors);
  g_object_set_data(G_OBJECT (Win), "Selectors",selectors);

  /* buttons box */
  hbox = create_hbox_false(vboxwin);
  gtk_widget_realize(Win);

  button = create_button(Win,"Cancel");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)destroy_selectors_window,GTK_OBJECT(Win));
  gtk_widget_show_all (button);

  button = create_button(Win,"OK");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  gtk_widget_show_all (button);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)apply_colorselections,GTK_OBJECT(Win));

  /* Show all */
  gtk_widget_show (Win);
}
/********************************************************************************/
void destroy_setlight_window(GtkWidget* Win,gpointer data)
{
  GtkWidget**entrys =(GtkWidget**) g_object_get_data(G_OBJECT (Win), "Entrys");
  delete_child(Win);
  g_free(entrys);
}
/********************************************************************************/
void apply_ligth_positions(GtkWidget *Win,gpointer data)
{
	GtkWidget** Entrys =(GtkWidget**)g_object_get_data(G_OBJECT (Win), "Entrys");
	G_CONST_RETURN gchar* temp;
	gint i;
	gint j;
	gfloat v[3];
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
        		temp	= gtk_entry_get_text(GTK_ENTRY(Entrys[j*3+i])); 
			v[j] = atof(temp);
		}
		set_light_position(i,v);
		
	}

	destroy_setlight_window(Win,data);
	glarea_rafresh(GLArea);
}
/********************************************************************************/
GtkWidget *create_light_positions_frame( GtkWidget *vboxall,gchar* title)
{
	GtkWidget *frame;
	GtkWidget *vboxframe;
	GtkWidget **Entrys = g_malloc(9*sizeof(GtkWidget*));
	gushort i;
	gushort j;
	GtkWidget *Table;
	gchar** temp[3];
#define NLIGNES   3
#define NCOLUMNS  3
	gchar      *strcolumns[NCOLUMNS] = {" X "," Y "," Z "};
	gchar      *strlignes[NLIGNES] = {" Light 1 : "," Light 2 : "," Light 3 : "};

	for(i=0;i<3;i++)
		temp[i] = get_light_position(i); 

	frame = gtk_frame_new (title);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
	gtk_container_add (GTK_CONTAINER (vboxall), frame);
	gtk_widget_show (frame);

	vboxframe = create_vbox(frame);
	Table = gtk_table_new(4,4,FALSE);
	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	for(j=1;j<NLIGNES+1;j++)
		add_label_at_table(Table,strlignes[j-1],(gushort)j,0,GTK_JUSTIFY_LEFT);

	for(i=1;i<NCOLUMNS+1;i++)
	{
		add_label_at_table(Table,strcolumns[i-1],0,(gushort)i,GTK_JUSTIFY_CENTER);
		for(j=1;j<NLIGNES+1;j++)
		{
			Entrys[(i-1)*NCOLUMNS+j-1] = gtk_entry_new ();
			add_widget_table(Table,Entrys[(i-1)*NCOLUMNS+j-1],(gushort)j,(gushort)i);
			gtk_entry_set_text(GTK_ENTRY( Entrys[(i-1)*NCOLUMNS+j-1]),temp[j-1][i-1]);
		}
	}

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
			g_free(temp[i][j]);
		g_free(temp[i]);
	}
	gtk_widget_show_all(frame);
	g_object_set_data(G_OBJECT (frame), "Entrys",Entrys);

	i = 0;
	g_object_set_data(G_OBJECT (Entrys[i]), "Entrys",Entrys);
	i = 2;
	g_object_set_data(G_OBJECT (Entrys[i]), "Entrys",Entrys);
	i = 3;
	g_object_set_data(G_OBJECT (Entrys[i]), "Entrys",Entrys);
	i = 6;
	g_object_set_data(G_OBJECT (Entrys[i]), "Entrys",Entrys);
  
  	return frame;
}
/********************************************************************************/
static void get_min_max_coord(gfloat* xmin, gfloat* xmax)
{
	gint i,j;
	gfloat min = 0;
	gfloat max = 0;
	if(!GeomOrb || Ncenters<1 )
	{
		*xmin = min;
		*xmax = max;
		return;
	}
 
	min = GeomOrb[0].C[0];
	max = GeomOrb[0].C[0];
	for(i=0;i<Ncenters;i++)
	{
		for(j=0;j<3;j++)
		{
			if(min>GeomOrb[i].C[j]) min = GeomOrb[i].C[j];
			if(max<GeomOrb[i].C[j]) max = GeomOrb[i].C[j];
		}
	}
	*xmin = min;
	*xmax = max;
}
/********************************************************************************/
static void set_camera_optimal(GtkWidget* Win,gpointer data)
{
	GtkWidget* EntryZNear = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "EntryZNear");
	GtkWidget* EntryZFar = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "EntryZFar");
	GtkWidget* EntryZoom = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "EntryZoom");
	gchar* temp;
	gfloat min = 0;
	gfloat max = 0;


	get_min_max_coord(&min, &max);
	if(min == 0 && max == 0)
		return;

	temp    = g_strdup("1");
	gtk_entry_set_text(GTK_ENTRY(EntryZNear),temp);
	temp    = g_strdup_printf("%f",fabs(max-min)*5);
	gtk_entry_set_text(GTK_ENTRY(EntryZFar), temp);
	temp    = g_strdup("1.0");
	gtk_entry_set_text(GTK_ENTRY(EntryZoom),temp);
}
/********************************************************************************/
static void apply_camera(GtkWidget* Win,gpointer data)
{
	GtkWidget* EntryZNear = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "EntryZNear");
	GtkWidget* EntryZFar = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "EntryZFar");
	GtkWidget* EntryZoom = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "EntryZoom");
	GtkWidget* buttonPerspective = (GtkWidget*)g_object_get_data(G_OBJECT (Win), "ButtonPerspective");
	G_CONST_RETURN gchar* temp;

	gfloat zNear = 1;
	gfloat zFar = 100;
	gfloat Zoom = 45;
	gfloat zn;
	gfloat zf;
	gfloat zo;
	gboolean perspective;

	get_camera_values(&zNear, &zFar, &Zoom, &perspective);

	temp    = gtk_entry_get_text(GTK_ENTRY(EntryZNear));
	zn = atof(temp);
	if(zn<=0)  zn = zNear;

	temp    = gtk_entry_get_text(GTK_ENTRY(EntryZFar));
	zf = atof(temp);
	if(zf<=0)  zn = zFar;

	temp    = gtk_entry_get_text(GTK_ENTRY(EntryZoom));
	zo = atof(temp);
	if(zo<=0)  zo = Zoom;
	else
		zo = 1/zo*45;
	if(GTK_IS_WIDGET(buttonPerspective))
	 perspective =GTK_TOGGLE_BUTTON (buttonPerspective)->active;
	set_camera_values(zn, zf, zo, perspective);
	rafresh_perspective_button();
}
/********************************************************************************/
static void set_sensitive_camera(GtkWidget* buttonPerspective, gpointer data)
{
	if(GTK_IS_WIDGET(buttonPerspective))
	{
		gboolean perspective = GTK_TOGGLE_BUTTON (buttonPerspective)->active;
		GtkWidget* EntryZNear = (GtkWidget*)g_object_get_data(G_OBJECT (buttonPerspective), "EntryZNear");
		GtkWidget* EntryZFar = g_object_get_data(G_OBJECT (buttonPerspective), "EntryZFar");
		GtkWidget* buttonOptimal = g_object_get_data(G_OBJECT (buttonPerspective), "ButtonOptimal");
		GtkWidget* labelZNear = g_object_get_data(G_OBJECT (buttonPerspective), "LabelZNear");
		GtkWidget* labelZFar = g_object_get_data(G_OBJECT (buttonPerspective), "LabelZFar");

		if(GTK_IS_WIDGET(EntryZNear))gtk_widget_set_sensitive(EntryZNear,perspective);
		if(GTK_IS_WIDGET(EntryZFar))gtk_widget_set_sensitive(EntryZFar,perspective);
		if(GTK_IS_WIDGET(buttonOptimal))gtk_widget_set_sensitive(buttonOptimal,perspective);
		if(GTK_IS_WIDGET(labelZNear))gtk_widget_set_sensitive(labelZNear,perspective);
		if(GTK_IS_WIDGET(labelZFar))gtk_widget_set_sensitive(labelZFar,perspective);
	}
}
/********************************************************************************/
static GtkWidget* create_camera_frame(GtkWidget* Win,GtkWidget *vbox)
{
	GtkWidget *frame;
	GtkWidget *vboxframe;
	GtkWidget* buttonOptimal;
	GtkWidget* EntryZNear;
	GtkWidget* EntryZFar;
	GtkWidget* EntryZoom;
	GtkWidget *table = gtk_table_new(8,3,FALSE);
	GtkWidget *hseparator;
	gushort i;
	gfloat zNear = 1;
	gfloat zFar = 100;
	gfloat Zoom = 45;
	gboolean perspective = TRUE;
  	GtkWidget* buttonPerspective;
  	GtkWidget* buttonNoPerspective;
	GtkWidget* labelZFar;
	GtkWidget* labelZNear;

	get_camera_values(&zNear, &zFar, &Zoom, &perspective);

	frame = gtk_frame_new (NULL);
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (vbox), frame, TRUE, TRUE, 0);
	gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

	vboxframe = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vboxframe);
	gtk_container_add (GTK_CONTAINER (frame), vboxframe);
	gtk_box_pack_start (GTK_BOX (vboxframe), table, TRUE, TRUE, 0);
/* ------------------------------------------------------------------*/
	i = 4;
	labelZNear = add_label_table(table," Distance from the viewer to the near clipping plane ",i,0);
	add_label_table(table," : ",i,1);
	EntryZNear = gtk_entry_new();
	add_widget_table(table,EntryZNear,i,2);
	gtk_editable_set_editable((GtkEditable*)EntryZNear,TRUE);
	gtk_entry_set_text (GTK_ENTRY (EntryZNear),g_strdup_printf("%f",zNear));
/* ------------------------------------------------------------------*/
	i = 5;
	labelZFar = add_label_table(table," Distance from the viewer to the far clipping plane ",i,0);
	add_label_table(table," : ",i,1);
	EntryZFar = gtk_entry_new();
	add_widget_table(table,EntryZFar,i,2);
	gtk_editable_set_editable((GtkEditable*)EntryZFar,TRUE);
	gtk_entry_set_text (GTK_ENTRY (EntryZFar),g_strdup_printf("%f",zFar));
/* ------------------------------------------------------------------*/
	i = 6;
	add_label_table(table," Zoom factor ",i,0);
	add_label_table(table," : ",i,1);
	EntryZoom = gtk_entry_new();
	add_widget_table(table,EntryZoom,i,2);
	gtk_editable_set_editable((GtkEditable*)EntryZoom,TRUE);
	gtk_entry_set_text (GTK_ENTRY (EntryZoom),g_strdup_printf("%f",1/Zoom*45.0));
/* ------------------------------------------------------------------*/
	i=3;
	buttonOptimal = gtk_button_new_with_label("Get Optimal values" );
	add_widget_table(table,buttonOptimal,i,2);
	gtk_widget_show (buttonOptimal);
	g_object_set_data(G_OBJECT (frame), "EntryZNear",EntryZNear);
	g_object_set_data(G_OBJECT (frame), "EntryZFar",EntryZFar);
	g_object_set_data(G_OBJECT (frame), "EntryZoom",EntryZoom);
	g_signal_connect_swapped(G_OBJECT(buttonOptimal),"clicked",(GCallback)set_camera_optimal,GTK_OBJECT(Win));

/* ------------------------------------------------------------------*/
	i = 0;
  	buttonPerspective = gtk_radio_button_new_with_label(NULL,"Perspective"); 
	add_widget_table(table,buttonPerspective,i,0);
	g_object_set_data(G_OBJECT (buttonPerspective), "EntryZNear",EntryZNear);
	g_object_set_data(G_OBJECT (buttonPerspective), "EntryZFar",EntryZFar);
	g_object_set_data(G_OBJECT (buttonPerspective), "ButtonOptimal",buttonOptimal);
	g_object_set_data(G_OBJECT (buttonPerspective), "LabelZNear",labelZNear);
	g_object_set_data(G_OBJECT (buttonPerspective), "LabelZFar",labelZFar);

	i = 1;
  	buttonNoPerspective = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonPerspective)), "No perspective"); 
	add_widget_table(table,buttonNoPerspective,i,0);
	g_signal_connect(G_OBJECT(buttonPerspective),"clicked",(GCallback)set_sensitive_camera,NULL);
	if(perspective)
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonPerspective), TRUE);
	else
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonNoPerspective), TRUE);

/* ------------------------------------------------------------------*/
	i = 2;
	hseparator = gtk_hseparator_new ();
  	gtk_table_attach(GTK_TABLE(table),hseparator,0,3,i,i+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  (GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
                  1,1);


	g_object_set_data(G_OBJECT (frame), "ButtonPerspective",buttonPerspective);
	g_object_set_data(G_OBJECT (frame), "ButtonNoPerspective",buttonNoPerspective);
	gtk_widget_show_all(frame);
	return frame;
}
/********************************************************************************/
void set_camera()
{
	GtkWidget *Win;
	GtkWidget *frame;
	GtkWidget *hbox;
	GtkWidget *vboxall;
	GtkWidget *vboxwin;
	GtkWidget *button;
	GtkWidget* EntryZNear;
	GtkWidget* EntryZFar;
	GtkWidget* EntryZoom;
	GtkWidget* buttonPerspective;
	GtkWidget* buttonNoPerspective;


	Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(Win),"Camera");
	gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
	gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
	gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(PrincipalWindow));
	gtk_window_set_modal (GTK_WINDOW (Win), TRUE);
	add_child(PrincipalWindow,Win,gtk_widget_destroy,"Camera");
	g_signal_connect(G_OBJECT(Win),"delete_event",(GCallback)delete_child,NULL);

	vboxall = create_vbox(Win);
	vboxwin = vboxall;
	frame = create_camera_frame(Win,vboxall);
	EntryZNear = (GtkWidget*) g_object_get_data(G_OBJECT (frame), "EntryZNear");
	EntryZFar = (GtkWidget*) g_object_get_data(G_OBJECT (frame), "EntryZFar");
	EntryZoom = (GtkWidget*) g_object_get_data(G_OBJECT (frame), "EntryZoom");
	buttonPerspective = (GtkWidget*) g_object_get_data(G_OBJECT (frame), "ButtonPerspective");
	buttonNoPerspective = (GtkWidget*) g_object_get_data(G_OBJECT (frame), "ButtonNoPerspective");

	g_object_set_data(G_OBJECT (Win), "EntryZNear",EntryZNear);
	g_object_set_data(G_OBJECT (Win), "EntryZFar",EntryZFar);
	g_object_set_data(G_OBJECT (Win), "EntryZoom",EntryZoom);
	g_object_set_data(G_OBJECT (Win), "ButtonPerspective",buttonPerspective);
	g_object_set_data(G_OBJECT (Win), "ButtonNoPerspective",buttonNoPerspective);
   

	hbox = create_hbox_false(vboxwin);
	gtk_widget_realize(Win);

	button = create_button(Win,"Close");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)delete_child, GTK_OBJECT(Win));
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)gtk_widget_destroy, GTK_OBJECT(Win));
	gtk_widget_show (button);

	button = create_button(Win,"Apply");
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)apply_camera, GTK_OBJECT(Win));

	button = create_button(Win,"OK");
	gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	gtk_widget_grab_default(button);
	gtk_widget_show (button);

	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)apply_camera, GTK_OBJECT(Win));
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)delete_child, GTK_OBJECT(Win));
	g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)gtk_widget_destroy,GTK_OBJECT(Win));

	gtk_widget_show_all (Win);
}
/********************************************************************************/
void set_light_positions(gchar* title)
{
  GtkWidget *Win;
  GtkWidget *frame;
  GtkWidget *hbox;
  GtkWidget *vboxall;
  GtkWidget *vboxwin;
  GtkWidget *button;
  GtkWidget** Entrys;

  /* Principal Window */
  Win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(Win),title);
  gtk_window_set_position(GTK_WINDOW(Win),GTK_WIN_POS_CENTER);
  gtk_container_set_border_width (GTK_CONTAINER (Win), 5);
  gtk_window_set_transient_for(GTK_WINDOW(Win),GTK_WINDOW(PrincipalWindow));
  gtk_window_set_modal (GTK_WINDOW (Win), TRUE);

  add_glarea_child(Win,"Grid ");

  vboxall = create_vbox(Win);
  vboxwin = vboxall;
  frame = create_light_positions_frame(vboxall,"Ligth positions");
  Entrys = (GtkWidget**) g_object_get_data(G_OBJECT (frame), "Entrys");
  g_object_set_data(G_OBJECT (Win), "Entrys",Entrys);
   

  /* buttons box */
  hbox = create_hbox_false(vboxwin);
  gtk_widget_realize(Win);

  button = create_button(Win,"Cancel");
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)destroy_setlight_window, GTK_OBJECT(Win));
  gtk_widget_show (button);

  button = create_button(Win,"OK");
  gtk_box_pack_start (GTK_BOX( hbox), button, TRUE, TRUE, 3);
  GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  gtk_widget_grab_default(button);
  gtk_widget_show (button);
  g_signal_connect_swapped(G_OBJECT(button), "clicked",(GCallback)apply_ligth_positions,GTK_OBJECT(Win));
  

  /* Show all */
  gtk_widget_show_all (Win);
}
/********************************************************************************/
static void  setNumberOfSubdivisions(GtkWidget *Entry, gpointer data)
{
	static gchar* typeEntry[] = {"CYLINDER","SPHERE"};
	G_CONST_RETURN gchar* textEntry = gtk_entry_get_text(GTK_ENTRY(Entry)); 
	gint value = 0;
	if(textEntry && strlen(textEntry)>0) value = atof(textEntry);
	if(value<1)return;
	if(strcmp((gchar*)data,typeEntry[0])==0)
	{
		openGLOptions.numberOfSubdivisionsCylindre = value;
	}
	else
	{
		openGLOptions.numberOfSubdivisionsSphere = value;
	}
}
/********************************************************************************/
static void  set_opengl(GtkWidget *Button, gpointer data)
{
	gchar* typeButton[] = {"RGBA","DOUBLEBUFFER" ,"ALPHASIZE","DEPTHSIZE"};
	gint i;
	for(i=0;i<4;i++)
		if(strcmp((gchar*)data,typeButton[i])==0)
		{
			switch(i)
			{
				case 0: 
					if(openGLOptions.rgba==0) 
						openGLOptions.rgba=1;
					else 
						openGLOptions.rgba=0;
					break;
				case 1: 
					if(openGLOptions.doubleBuffer==0)
						openGLOptions.doubleBuffer = 1;
					else
						openGLOptions.doubleBuffer = 0;
					break;
				case 2: 
					if(openGLOptions.alphaSize==0)
						openGLOptions.alphaSize = 1;
					else
						openGLOptions.alphaSize = 0;
					break;
				case 3: 
					if(openGLOptions.depthSize==0)
						openGLOptions.depthSize = 1;
					else
						openGLOptions.depthSize = 0;
					break;
			}
			break;
		}
}
/********************************************************************************/
void  create_opengl_frame(GtkWidget* Win,GtkWidget *vbox)
{
	GtkWidget *frame;
	GtkWidget *vboxframe;
	GtkWidget* buttonRGBA;
	GtkWidget* buttonALPHASIZE;
	GtkWidget* buttonDEPTHSIZE;
	GtkWidget* buttonDOUBLEBUFFER;
	GtkWidget* EntryCylinder;
	GtkWidget* EntrySphere;
	GtkWidget* combo;
	GtkWidget *table = gtk_table_new(2,5,FALSE);
	static gchar* typeButton[] = {"RGBA","DOUBLEBUFFER" ,"ALPHASIZE","DEPTHSIZE"};
	static gchar* values[] = {"5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20","21","22","23","24","25","26","27","28","29","30"};
	static gchar* typeEntry[] = {"CYLINDER","SPHERE"};
	gushort i;


	frame = gtk_frame_new ("OpenGL Options");
	gtk_widget_show (frame);
	gtk_box_pack_start (GTK_BOX (vbox), frame, TRUE, TRUE, 0);
	gtk_frame_set_label_align (GTK_FRAME (frame), 0.5, 0.5);

	vboxframe = gtk_vbox_new (FALSE, 0);
	gtk_widget_show (vboxframe);
	gtk_container_add (GTK_CONTAINER (frame), vboxframe);

	gtk_box_pack_start (GTK_BOX (vboxframe), table, TRUE, TRUE, 0);

/* ------------------------------------------------------------------*/
	i = 0;
	add_label_table(table," number Of Subdivisions for a Cylinder ",i,0);
	add_label_table(table," : ",i,1);
	combo = create_combo_box_entry(values,26,TRUE,-1,-1);
	EntryCylinder = GTK_BIN(combo)->child;
	add_widget_table(table,combo,i,2);
	gtk_editable_set_editable((GtkEditable*)EntryCylinder,FALSE);
	gtk_entry_set_text (GTK_ENTRY (EntryCylinder),g_strdup_printf("%d",openGLOptions.numberOfSubdivisionsCylindre));
	g_signal_connect (G_OBJECT (EntryCylinder), "changed",(GCallback)setNumberOfSubdivisions,typeEntry[0]);
/* ------------------------------------------------------------------*/
	i = 1;
	add_label_table(table," number Of Subdivisions for a Sphere ",i,0);
	add_label_table(table," : ",i,1);
	combo = create_combo_box_entry(values,26,TRUE,-1,-1);
	EntrySphere = GTK_BIN(combo)->child;
	add_widget_table(table,combo,i,2);
	gtk_editable_set_editable((GtkEditable*)EntrySphere,FALSE);
	gtk_entry_set_text (GTK_ENTRY (EntrySphere),g_strdup_printf("%d",openGLOptions.numberOfSubdivisionsSphere));
	g_signal_connect (G_OBJECT (EntrySphere), "changed",(GCallback)setNumberOfSubdivisions,typeEntry[1]);
/* ------------------------------------------------------------------*/

	buttonRGBA = gtk_check_button_new_with_label("RGBA" );
	add_widget_table(table,buttonRGBA,0,3);
	gtk_widget_show (buttonRGBA);
	if(openGLOptions.rgba!=0)
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonRGBA), TRUE);
	else
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonRGBA), FALSE);

	buttonDOUBLEBUFFER = gtk_check_button_new_with_label("DOUBLEBUFFER" );
	add_widget_table(table,buttonDOUBLEBUFFER,1,3);
	gtk_widget_show (buttonDOUBLEBUFFER);
	if(openGLOptions.doubleBuffer!=0)
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonDOUBLEBUFFER), TRUE);
	else
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonDOUBLEBUFFER), FALSE);

	buttonALPHASIZE = gtk_check_button_new_with_label("ALPHASIZE=1(0 if not)" );
	add_widget_table(table,buttonALPHASIZE,0,4);
	gtk_widget_show (buttonALPHASIZE);
	if(openGLOptions.alphaSize!=0)
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonALPHASIZE), TRUE);
	else
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonALPHASIZE), FALSE);

	buttonDEPTHSIZE = gtk_check_button_new_with_label("DEPTHSIZE=1(0 if not)" );
	add_widget_table(table,buttonDEPTHSIZE,1,4);
	gtk_widget_show (buttonDEPTHSIZE);
	if(openGLOptions.depthSize!=0)
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonDEPTHSIZE), TRUE);
	else
  		gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonDEPTHSIZE), FALSE);

	g_signal_connect (G_OBJECT (buttonRGBA), "clicked", G_CALLBACK(set_opengl), typeButton[0]);
	g_signal_connect (G_OBJECT (buttonDOUBLEBUFFER), "clicked", G_CALLBACK(set_opengl), typeButton[1]);
	g_signal_connect (G_OBJECT (buttonALPHASIZE), "clicked", G_CALLBACK(set_opengl), typeButton[2]);
	g_signal_connect (G_OBJECT (buttonDEPTHSIZE), "clicked", G_CALLBACK(set_opengl), typeButton[3]);
	gtk_widget_show_all(frame);
}
