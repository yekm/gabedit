/* EnergiesCurve.c */
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
#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#include "../Common/Global.h"
#include "ResultsAnalise.h"
#include "../Utils/UtilsInterface.h"
#include "../Geometry/GeomGlobal.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/Utils.h"
#include "../Geometry/EnergiesCurves.h"
#include "../Geometry/GeomXYZ.h"
#include "../Common/Windows.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"

#define Nmax 10

gboolean DrawEnergies(GtkWidget *dessin,GdkEventConfigure *ev);
gboolean grille(GtkWidget *dessin,GdkEventConfigure *ev);
void set_point(GtkWidget *widget, gint x,gint y, gint k);
gint get_coord(gint len,gdouble min, gdouble max,gdouble v,gboolean renv);
void get_coord_ecran(GtkWidget *widget,gint *tabx,gint *taby);
static void set_geom(GtkWidget *widget,gpointer data);
void set_point(GtkWidget *widget, gint x,gint y, gint k);


/********************************************************************************************/
static void draw_geom(GtkWidget *widget,gpointer data)
{
        if(ZoneDessin==NULL)
 	  create_window_drawing(); 
        else
	{
          	rafresh_drawing();
	}
}
/********************************************************************************************/
/*
static void movie_geom(GtkWidget *widget,gpointer data)
{
	gint *tabx;
	gint *taby;
	gint i;
	DataGeomConv *GeomConv;
	GTimer *timer;
	gdouble elaps;
	gulong m ;
	gboolean temp ;


	temp = MesureIsHide;
	if(ZoneDessin)
		HideShowMesure(TRUE);
	else
		MesureIsHide = TRUE;

	draw_geom(widget,data);
	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(widget),"Geometry"));	

	tabx = g_malloc(GeomConv->Npoint*sizeof(gint));
	taby = g_malloc(GeomConv->Npoint*sizeof(gint));

	get_coord_ecran(widget,tabx,taby);

	timer =g_timer_new( );
	g_timer_start( timer );
	
	for( i =0; i<GeomConv->Npoint;i++)
	{
		set_point(widget,tabx[i],taby[i],i);
		set_geom(widget,NULL);
		g_timer_reset( timer );
		do{
		elaps = g_timer_elapsed( timer,&m);
		}while(elaps<0.5);
	}
	g_free(tabx);
	g_free(taby);
	g_timer_destroy(timer);

	if(temp != MesureIsHide)
	{
		HideShowMesure(temp);
	}

}
*/
/********************************************************************************************/
static void set_geom(GtkWidget *widget,gpointer data)
{
	DataGeomConv *GeomConv  = (DataGeomConv*)(g_object_get_data(G_OBJECT(widget),"Geometry"));	
	gint *ki;
	gint k;

	ki = (gint*)(g_object_get_data(G_OBJECT(widget),"Point"));  
	k = *ki;
	if(GeomConv->fileType == GABEDIT_TYPEFILE_DALTON) read_geom_conv_from_dalton_output_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_GAMESS) read_geom_conv_from_gamess_output_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_GAUSSIAN) read_geom_from_gaussian_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_MOLPRO) read_geom_from_molpro_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_MOLDEN) read_geom_from_molden_geom_conv_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_GABEDIT) read_geom_from_molden_geom_conv_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_MPQC) read_geom_from_mpqc_output_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);
	if(GeomConv->fileType == GABEDIT_TYPEFILE_XYZ) read_geom_from_xyz_file(GeomConv->GeomFile,GeomConv->NumGeom[k]);

}
/********************************************************************************************/
static void set_default_point(GtkWidget *widget)
{
	DataGeomConv *GeomConv;

	gint *tabx;
	gint* taby;
	gint *k;

	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(widget),"Geometry"));	

	tabx = g_malloc(GeomConv->Npoint*sizeof(gint));
	taby = g_malloc(GeomConv->Npoint*sizeof(gint));

	k = (gint*)(g_object_get_data(G_OBJECT(widget),"Point"));  

	get_coord_ecran(widget,tabx,taby);
	set_point(widget,tabx[*k],taby[*k],*k);
	g_free(tabx);
	g_free(taby);
}

/********************************************************************************************/
/* Création d'un nouveau pixmap d'arrière-plan de la taille voulue */
static gint configure_event (GtkWidget *widget, GdkEventConfigure *event)
{
	GdkColor couleur;
	GdkColormap *colormap;
	GdkGC *gc;
 	GdkPixmap *pixmap = NULL;

	colormap=gdk_window_get_colormap(widget->window);
	/*
	couleur.red=(gushort)(0.85*65535);
	couleur.green=(gushort)(0.85*65535);
	couleur.blue=(gushort)(0.85*65535);
	*/
	couleur.red=(gushort)(0);
	couleur.green=(gushort)(0);
	couleur.blue=(gushort)(0);
	
	gdk_color_alloc(colormap,&couleur);
/*
        pixmapold  = (GdkPixmap*)(g_object_get_data(G_OBJECT(widget),"Pixmap"));
        if (pixmapold)
        {
                gdk_pixmap_unref(pixmapold);
        }
*/
	gc = gdk_gc_new(widget->window);
	
	gdk_gc_set_foreground(gc,&couleur);
  
	pixmap = gdk_pixmap_new(widget->window,
                          widget->allocation.width,
                          widget->allocation.height,
                          -1);
        g_object_set_data_full(G_OBJECT (widget), "Pixmap", pixmap,
                                  (GtkDestroyNotify) gdk_pixmap_unref);  
  	gdk_draw_rectangle (	pixmap,
                      		gc,
                      		TRUE,
                      		0, 0,
                      		widget->allocation.width,
                      		widget->allocation.height);
  	gdk_gc_destroy(gc);

  	grille(widget,event);
  	DrawEnergies(widget,event);

  	return TRUE;
}
/********************************************************************************************/
static gint expose_event (GtkWidget *widget, GdkEventExpose *event)
{
	GdkPixmap *pixmap = (GdkPixmap*)(g_object_get_data(G_OBJECT(widget),"Pixmap")); 
  	gdk_draw_pixmap(widget->window,
                  	widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  	pixmap,
                  	event->area.x, event->area.y,
                  	event->area.x, event->area.y,
                  	event->area.width, event->area.height);

  	set_default_point(widget);
  return FALSE;
}
/********************************************************************************************/
void set_point(GtkWidget *widget, gint x,gint y, gint k)
{
	GdkPixmap *pixmap = (GdkPixmap*)(g_object_get_data(G_OBJECT(widget),"Pixmap")); 
	GtkWidget* Label;
	DataGeomConv *GeomConv;
	GdkColor couleur;
	GdkColormap *colormap;
	GdkGC *gc;
	gchar *t;
	gint *ki;
	gint rayon = 10;
        gint i;
	

	  gdk_draw_pixmap(widget->window,
                  widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,
                  0,0,
                  0,0,
                  widget->allocation.width,widget->allocation.height);

	colormap=gdk_window_get_colormap(widget->window);
	gc = gdk_gc_new(widget->window);
	couleur.red=0;
	couleur.green=65535;
	couleur.blue=0;
	gdk_color_alloc(colormap,&couleur);
	gdk_gc_set_foreground(gc,&couleur);
	gdk_gc_set_line_attributes(gc,1,GDK_LINE_SOLID,GDK_CAP_BUTT,GDK_JOIN_MITER);
	
	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(widget),"Geometry"));	

	t = g_strdup(GeomConv->Data[0][k]);
	Label = GTK_WIDGET(g_object_get_data(G_OBJECT(widget),GeomConv->TypeData[0]));
	gtk_label_set_text(GTK_LABEL(Label),t); 

        if(GeomConv->Npoint>1)
	{
                for(i=1;i<GeomConv->Ntype;i++)
		{
			t = g_strdup(GeomConv->Data[i][k]);
			Label = GTK_WIDGET(g_object_get_data(G_OBJECT(widget),GeomConv->TypeData[i]));
			gtk_label_set_text(GTK_LABEL(Label),t); 
		}

	}

	gdk_draw_arc(widget->window,gc,FALSE,x-rayon,y-rayon,2*rayon,2*rayon,0,380*64);
         ki = (gint*)(g_object_get_data(G_OBJECT(widget),"Point"));  
         *ki = k;
	gdk_gc_destroy(gc);

}
/********************************************************************************************/
gint get_coord(gint len,gdouble min, gdouble max,gdouble v,gboolean renv)			
{
	gint imin = len/20;
	gint pasi = (len-2*imin)/10;
	gint imax= imin+10*pasi;
	gint i;

        if(renv)
	 imax= imin+10*pasi-pasi/2;
	

       if(max-min>1e-8)
		i = (imax-imin)/(max-min)*(v-min)+imin;
         else
         {
		if(renv)
			i = imax;
		else
			i = imin;
         }
	if(renv)
		i = imax+imin-i;
	return i;
}
/********************************************************************************************/
void get_coord_ecran(GtkWidget *widget,gint *tabx,gint *taby)
{
	DataGeomConv *GeomConv;
	gdouble *tab;
	gdouble ymin,ymax;
	int i;

	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(widget),"Geometry"));
	
	tab = g_malloc(GeomConv->Npoint*sizeof(gdouble) );	
	
	for( i = 0;i<GeomConv->Npoint;i++)
		tab[i] = atof(GeomConv->Data[0][i]);
    ymin = tab[0];
	ymax = tab[0];

	for( i = 1;i<GeomConv->Npoint;i++)
	{
		if( tab[i]<ymin)
				ymin= tab[i];
		if( tab[i]>ymax)
				ymax= tab[i];
	}
    for( i = 0;i<GeomConv->Npoint;i++)
		tabx[i] = get_coord(widget->allocation.width,
					1.0,(gdouble)GeomConv->Npoint,(gdouble)(i+1),FALSE);
    
	for( i = 0;i<GeomConv->Npoint;i++)
		taby[i] = get_coord(widget->allocation.height,
					ymin,ymax,tab[i],TRUE);
/*
	printf("Npoint = %d\n",GeomConv->Npoint);
	for( i = 0;i<GeomConv->Npoint;i++)
		printf("(%d,%d) ; %f\n",tabx[i],taby[i],tab[i]);
*/	
	g_free(tab) ;
}
/********************************************************************************************/
gboolean grille(GtkWidget *dessin,GdkEventConfigure *ev)
{
	GdkPixmap *pixmap = (GdkPixmap*)(g_object_get_data(G_OBJECT(dessin),"Pixmap")); 
	GdkColor couleur;
	GdkColormap *colormap;
	GdkGC *gc;
 	PangoFontDescription *font_desc = NULL;

	gint xmin = dessin->allocation.width/20;
	gint ymin = dessin->allocation.height/20;
	gint pasx = (dessin->allocation.width-2*xmin)/10;
	gint pasy = (dessin->allocation.height-2*ymin)/10;
	
	gint xmax= xmin+10*pasx;
	gint ymax= ymin+10*pasy;
	
	gint i;
	gchar *st;

	DataGeomConv *GeomConv;
	
	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(dessin),"Geometry"));
	
	colormap=gdk_window_get_colormap(dessin->window);
	couleur.red=65535;
	couleur.green=0;
	couleur.blue=0;
	gdk_color_alloc(colormap,&couleur);
	gc = gdk_gc_new(dessin->window);
	gdk_gc_set_foreground(gc,&couleur);
	
	gdk_gc_set_line_attributes(gc,1,GDK_LINE_SOLID,GDK_CAP_PROJECTING,GDK_JOIN_MITER);
	
	for( i = xmin; i<=xmax;i+=pasx)
		gdk_draw_line(pixmap,gc,i,ymin,i,ymax);

	for( i = ymin; i<=ymax;i+=pasy)
		gdk_draw_line(pixmap,gc,xmin,i,xmax,i);
	/*
	couleur.red=0;
	couleur.green=0;
	couleur.blue=0;
	*/
	couleur.red=(gushort)(0.85*65535);
	couleur.green=(gushort)(0.85*65535);
	couleur.blue=(gushort)(0.85*65535);

	gdk_color_alloc(colormap,&couleur);
	gdk_gc_set_foreground(gc,&couleur);
	
 	font_desc = pango_font_description_from_string ("times 12");

	for( i = xmin; i<=xmax;i+=pasx)
	{
		st = g_strdup_printf("%4.1f", 1+((GeomConv->Npoint-1)/10.0)* ((i-xmin)/pasx) );
		gabedit_draw_string(dessin, pixmap, font_desc, gc, i, ymax, st, TRUE, FALSE);
                g_free(st);
	}

	if(font_desc) pango_font_description_free (font_desc);

        if(GeomConv->Npoint==1)
        {
 		font_desc = pango_font_description_from_string ("times 16");
		st = g_strdup("Single point");
		gabedit_draw_string(dessin, pixmap, font_desc, gc, dessin->allocation.width/2, dessin->allocation.height/2, st, TRUE, TRUE);
                g_free(st);
		if(font_desc) pango_font_description_free (font_desc);
        }
        if(GeomConv->TypeCalcul && !this_is_a_backspace(GeomConv->TypeCalcul))
        {
 		font_desc = pango_font_description_from_string ("times 14");
		st = g_strdup_printf("%s Calculation", GeomConv->TypeCalcul);
		gabedit_draw_string(dessin, pixmap, font_desc, gc, dessin->allocation.width/2, ymin/2, st, TRUE, TRUE);

                g_free(st);
		if(font_desc) pango_font_description_free (font_desc);
        }

	gdk_gc_destroy(gc);
	return TRUE;
	
}
/********************************************************************************************/
gboolean DrawEnergies(GtkWidget *dessin,GdkEventConfigure *ev)
{
	GdkPixmap *pixmap = (GdkPixmap*)(g_object_get_data(G_OBJECT(dessin),"Pixmap")); 
	GdkColor couleur;
	GdkColormap *colormap;
	GdkGC *gc;
	DataGeomConv *GeomConv;
	gint *tabx;
	gint *taby;
	gint rayon = 6;
	int i;

	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(dessin),"Geometry"));
	tabx = g_malloc(GeomConv->Npoint*sizeof(gint));
	taby = g_malloc(GeomConv->Npoint*sizeof(gint));

	get_coord_ecran(dessin,tabx,taby);

	colormap=gdk_window_get_colormap(dessin->window);
	gc = gdk_gc_new(dessin->window);
	couleur.red=0;
	couleur.green=0;
	couleur.blue=65535;
	gdk_color_alloc(colormap,&couleur);
	gdk_gc_set_foreground(gc,&couleur);
	gdk_gc_set_line_attributes(gc,2,GDK_LINE_SOLID,GDK_CAP_PROJECTING,GDK_JOIN_MITER);
	
	for( i = 0;i<GeomConv->Npoint-1;i++)
	gdk_draw_line(pixmap,gc,tabx[i],taby[i],
		tabx[i+1],taby[i+1]);

	gdk_gc_set_fill(gc,GDK_SOLID);
    gdk_gc_set_line_attributes(gc,1,GDK_LINE_SOLID,GDK_CAP_PROJECTING,GDK_JOIN_MITER);
	couleur.red=(gushort)(0.9*65535);
	couleur.green=(gushort)(0.9*65535);
	couleur.blue=(gushort)(0.9*65535);
	gdk_color_alloc(colormap,&couleur);
	gdk_gc_set_foreground(gc,&couleur);

	for( i = 0;i<GeomConv->Npoint;i++)
		gdk_draw_arc(pixmap,gc,TRUE,tabx[i]-rayon,taby[i]-rayon,2*rayon,2*rayon,0,380*64);
	gdk_gc_destroy(gc);
	
        g_free(tabx);
        g_free(taby);

	return TRUE;
	
}
/********************************************************************************************/
static gint button_press_event (GtkWidget *widget, GdkEventButton *event)
{
	GdkPixmap *pixmap = (GdkPixmap*)(g_object_get_data(G_OBJECT(widget),"Pixmap")); 
	gint *tabx;
	gint *taby;
	gint i,k;
	DataGeomConv *GeomConv;
	
	
	GeomConv = (DataGeomConv*)(g_object_get_data(G_OBJECT(widget),"Geometry"));	
	
	tabx = g_malloc(GeomConv->Npoint*sizeof(gint));
	taby = g_malloc(GeomConv->Npoint*sizeof(gint));

	get_coord_ecran(widget,tabx,taby);

	k=0;
	for( i =0; i<GeomConv->Npoint;i++)
		if( (event->x - tabx[i])*(event->x - tabx[i]) +
			(event->y - taby[i])*(event->y - taby[i]) 
			<
			(event->x - tabx[k])*(event->x - tabx[k]) +
			(event->y - taby[k])*(event->y - taby[k]) 
		   )
  	k =i;
	if (event->button == 1 && pixmap != NULL)
	{
			set_point(widget,tabx[k],taby[k],k);
 			set_geom(widget,NULL);
	}
        g_free(tabx);
        g_free(taby);
	return TRUE;
}
/********************************************************************************************/
static GtkWidget*add_label(gchar *tlabel,GtkWidget *vbox)
{
  GtkWidget *Label;
  GtkWidget *Frame;
 
        Frame = gtk_frame_new (tlabel);
        gtk_frame_set_shadow_type( GTK_FRAME(Frame),GTK_SHADOW_ETCHED_OUT);
        gtk_widget_ref (Frame);
        gtk_box_pack_start(GTK_BOX(vbox), Frame,FALSE,FALSE,2);
        gtk_widget_show (Frame);
 
        Label = gtk_label_new(" ");
        gtk_label_set_justify(GTK_LABEL(Label),GTK_JUSTIFY_LEFT);
        gtk_widget_ref (Label);
        gtk_container_add (GTK_CONTAINER (Frame), Label);
 
  return Label;
}     
/********************************************************************************************/
static void destroy_widget_null(GtkWidget *wid)
{
 GtkWidget **pwid;
 DataGeomConv *GeomConv = (DataGeomConv *)g_object_get_data(G_OBJECT(wid),"GeometryPointer");
 gint *k = (gint *)g_object_get_data(G_OBJECT(wid),"GeometryDim");
 gint i;


 destroy_button_windows(wid);
 pwid = (GtkWidget**)(g_object_get_data(G_OBJECT(wid),"PointerWidget"));	
/*
 if(wid) 
 	gtk_widget_destroy(wid);
*/
 *pwid =  NULL;
 for(i=0;i<*k;i++)
  GeomConv[i] = free_geom_conv( GeomConv[i]);

  g_free(GeomConv);
 g_free(k);
 GeomConvIsOpen = FALSE;
}
/********************************************************************************************/
GtkWidget *add_energies_curve( GtkWidget *WindowEnergies, DataGeomConv* GeomConv,gboolean init)
{
 	GdkPixmap *pixmap = NULL;
	GtkWidget *dessin;
	GtkWidget *hbox;
	GtkWidget *vbox;
	GtkWidget *Label;
	GtkWidget *Frame;
	GtkWidget *button;
	static GtkWidget *Hbox = NULL;
 	GtkWidget *Vbox = (GtkWidget *)(g_object_get_data(G_OBJECT(WindowEnergies),"Vbox")); 
 	gint *N = (gint *)g_object_get_data(G_OBJECT(WindowEnergies),"GeometryDim");
	gint *k;
        gint i;
        static gint j = 0;
        gchar *t;

        if(init)
	{
		Hbox = NULL;
		j = 0;
	}
        if(!GeomConv || GeomConv->Npoint < 1)
        {
		switch(GeomConv->fileType)
		{
			case GABEDIT_TYPEFILE_GAUSSIAN :
				Message("Sorry\n I can not read energies from your gaussian output file\n"," Error ",TRUE); 
				break;
			case GABEDIT_TYPEFILE_MOLPRO :
          			Message("Sorry\n I can not read energies from your molpro log file\n"," Error ",TRUE);
				break;
			case GABEDIT_TYPEFILE_MOLDEN :
        	  		Message("Sorry\n I can not read energies from your molden file\n"," Error ",TRUE);
				break;
			case GABEDIT_TYPEFILE_GABEDIT :
        	  		Message("Sorry\n I can not read energies from your gabedit file\n"," Error ",TRUE);
				break;
			case GABEDIT_TYPEFILE_MPQC :
        	  		Message("Sorry\n I can not read energies from your MPQC output file\n"," Error ",TRUE);
				break;
			case GABEDIT_TYPEFILE_XYZ :
        	  		Message("Sorry\n I can not read your XYZ file\n"," Error ",TRUE);
				break;
			default :
        	  		Message("Sorry\n I can not read energies\n"," Error ",TRUE);
		}
        }

        if(j%2 == 0)
        {
                Hbox = gtk_hbox_new (FALSE, 0);
                gtk_widget_ref (Hbox);
		t = g_strdup_printf("Hbox%d",j);
		g_object_set_data_full(G_OBJECT (Vbox), t,
					  Hbox,(GtkDestroyNotify) gtk_widget_unref);
		g_free(t);
                gtk_widget_show (Hbox);
                gtk_box_pack_start(GTK_BOX(Vbox), Hbox,TRUE,TRUE,5);
 
        }
        j++; 

	k = g_malloc(sizeof(gint));
	*k = 0;

	Frame = gtk_frame_new (GeomConv->TypeCalcul);
        gtk_frame_set_shadow_type( GTK_FRAME(Frame),GTK_SHADOW_ETCHED_OUT);
        gtk_widget_ref (Frame);
        gtk_box_pack_start(GTK_BOX(Hbox), Frame,TRUE,TRUE,10);
        gtk_widget_show (Frame);

	hbox = gtk_hbox_new (FALSE, 0);
	gtk_widget_ref (hbox);
	gtk_widget_show (hbox);
	gtk_container_add(GTK_CONTAINER(Frame),hbox);
	
	dessin=gtk_drawing_area_new();
	gtk_widget_set_events (dessin, GDK_EXPOSURE_MASK
                         | GDK_LEAVE_NOTIFY_MASK
                         | GDK_BUTTON_PRESS_MASK
                         | GDK_POINTER_MOTION_MASK
                         | GDK_POINTER_MOTION_HINT_MASK);
	gtk_box_pack_start (GTK_BOX (hbox), dessin, TRUE, TRUE, 0);	
	gtk_widget_set_size_request(GTK_WIDGET(dessin),ScreenWidth/6,ScreenHeight/(*N)/6);
	gtk_widget_realize (dessin);
	pixmap = gdk_pixmap_new(dessin->window,
                          dessin->allocation.width,
                          dessin->allocation.height,
                          -1);
        g_object_set_data_full(G_OBJECT (dessin), "Pixmap", pixmap,
                                  (GtkDestroyNotify) gdk_pixmap_unref);  


	Frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type( GTK_FRAME(Frame),GTK_SHADOW_ETCHED_OUT);
	gtk_widget_ref (Frame);
	g_object_set_data_full(G_OBJECT (WindowEnergies), "Frame",
							   Frame,(GtkDestroyNotify) gtk_widget_unref);
	gtk_box_pack_start(GTK_BOX(hbox), Frame,FALSE,FALSE,2);
	gtk_widget_show (Frame);
 
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_ref (vbox);
	g_object_set_data_full(G_OBJECT (Frame), "vbox", vbox,
                            (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show (vbox);
	gtk_container_add(GTK_CONTAINER (Frame), vbox);

        

         Label = add_label(GeomConv->TypeData[0],vbox);
         g_object_set_data_full(G_OBJECT (dessin),GeomConv->TypeData[0], Label,
                            (GtkDestroyNotify) gtk_widget_unref);      
        if(GeomConv->Npoint > 1)
        {
		for(i=1;i<GeomConv->Ntype ;i++)
		{
			Label = add_label(GeomConv->TypeData[i],vbox);
			g_object_set_data_full(G_OBJECT (dessin), GeomConv->TypeData[i], Label,
                            (GtkDestroyNotify) gtk_widget_unref);
                }
        }


	button = create_button(WindowEnergies,"Close");
	g_signal_connect_swapped(G_OBJECT(button),"clicked", (GtkSignalFunc)gtk_widget_destroy,GTK_OBJECT(WindowEnergies));
	gtk_box_pack_end(GTK_BOX(vbox), button,FALSE,FALSE,1);
  	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
  	gtk_widget_grab_default(button);

	/*
	button = create_button(WindowEnergies,"Movie");
	g_signal_connect_swapped(G_OBJECT(button),"clicked", (GtkSignalFunc)movie_geom,GTK_OBJECT(dessin));
	gtk_box_pack_end(GTK_BOX(vbox), button,FALSE,FALSE,1);
  	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);
	*/

	button = create_button(WindowEnergies,"Draw");
	g_signal_connect_swapped(G_OBJECT(button),"clicked", (GtkSignalFunc)draw_geom,GTK_OBJECT(WindowEnergies));
	gtk_box_pack_end(GTK_BOX(vbox), button,FALSE,FALSE,1);
  	GTK_WIDGET_SET_FLAGS(button, GTK_CAN_DEFAULT);

	g_object_set_data(G_OBJECT (dessin), "Geometry", GeomConv);
	
	g_object_set_data_full(G_OBJECT (dessin), "Point", k, (GtkDestroyNotify) g_free);
	
	g_signal_connect(G_OBJECT (dessin),"button_press_event", (GtkSignalFunc) button_press_event, NULL);

	g_signal_connect(G_OBJECT(dessin),"expose_event", (GtkSignalFunc)expose_event,NULL);
	g_signal_connect(G_OBJECT(dessin),"configure_event", (GtkSignalFunc)configure_event,NULL);
	set_geom(dessin,NULL);
					   
	return dessin;

}
/********************************************************************************************/
void create_energies_curves(DataGeomConv* GeomConv,gint N)
{
	static GtkWidget *WindowEnergies=NULL;
	GtkWidget *dessin;
	GtkWidget *Vbox;
	gchar *t;
        gint i;
        gint* k;
       
	 if(!GeomConv)
	 {
		Message("Sorry\n No geometry available in this file\n"," Error ",TRUE); 
		return;
	 }

        if(N < 1)
        {
	  switch(GeomConv->fileType)
	  {
		case GABEDIT_TYPEFILE_GAUSSIAN :
			Message("Sorry\n I can not read energies from your gaussian output file\n"," Error ",TRUE); 
			break;
		case GABEDIT_TYPEFILE_MOLPRO :
          		Message("Sorry\n I can not read energies from your molpro log file\n"," Error ",TRUE);
			break;
		case GABEDIT_TYPEFILE_MOLDEN :
          		Message("Sorry\n I can not read energies from your molden file\n"," Error ",TRUE);
			break;
		case GABEDIT_TYPEFILE_GABEDIT :
          		Message("Sorry\n I can not read energies from your gabedit file\n"," Error ",TRUE);
			break;
		case GABEDIT_TYPEFILE_MPQC :
          		Message("Sorry\n I can not read energies from your MPQC output file\n"," Error ",TRUE);
			break;
		case GABEDIT_TYPEFILE_XYZ :
          		Message("Sorry\n I can not read your xyz file\n"," Error ",TRUE);
			break;
		default :
          		Message("Sorry\n I can not read energies\n"," Error ",TRUE);
	  }
	  return;
        }
        k = g_malloc(sizeof(gint));
        *k = N;

        if(WindowEnergies)
	{
		gtk_widget_destroy(WindowEnergies);
	}
        GeomConvIsOpen = TRUE;
	WindowEnergies = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	g_object_set_data(G_OBJECT (WindowEnergies), "PointerWidget",&WindowEnergies);
	gtk_container_set_border_width(GTK_CONTAINER(WindowEnergies),8);
        t = g_strdup_printf("Geometry convergence from file : %s",GeomConv->GeomFile);
    	gtk_window_set_title(GTK_WINDOW(WindowEnergies),t);
        g_free(t);
	g_signal_connect(G_OBJECT(WindowEnergies),"delete_event",
					   (GtkSignalFunc)gtk_widget_destroy,NULL);
	g_signal_connect(G_OBJECT(WindowEnergies),"destroy",
					   (GtkSignalFunc)destroy_widget_null,NULL);
		
	Vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_ref (Vbox);
	gtk_widget_show (Vbox);
	gtk_container_add(GTK_CONTAINER(WindowEnergies),Vbox);

         g_object_set_data_full(G_OBJECT (WindowEnergies), "Vbox",
                                   Vbox,(GtkDestroyNotify) gtk_widget_unref);
	
	gtk_widget_realize (WindowEnergies);

	g_object_set_data(G_OBJECT (WindowEnergies), "GeometryPointer",GeomConv);
	g_object_set_data(G_OBJECT (WindowEnergies), "GeometryDim",k);

	dessin=add_energies_curve(WindowEnergies,&GeomConv[0],TRUE);
        for(i=1;i<N;i++)
	{
		dessin=add_energies_curve(WindowEnergies,&GeomConv[i],FALSE);
	}

        add_button_windows("Geom. Conv.",WindowEnergies);
	gtk_widget_show_all(WindowEnergies);
        set_icone(WindowEnergies);

}
/********************************************************************************************/

