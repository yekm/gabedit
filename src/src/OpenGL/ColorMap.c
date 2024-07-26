/* ColorMap.c */
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
#include <gdk/gdkkeysyms.h>
#include "../Utils/Utils.h"
#include "../Utils/Constantes.h"
#include "ColorMap.h"
#include "GLArea.h"

/*
static ColorMap myColorMap =  {0,NULL};
static GtkWidget *handleboxShow;
static GdkGC *gc = NULL;
*/
/******************************************************************************************************************************/
/*
static void print_colorMap(ColorMap* colorMap)
{
	gint i;
	printf("Number of Color = %d\n",colorMap->numberOfColors);
	for(i=0; i<colorMap->numberOfColors; i++)
	{
		printf("%f %0.2f %0.2f %0.2f\n",colorMap->colorValue[i].value,colorMap->colorValue[i].color[0],colorMap->colorValue[i].color[1],colorMap->colorValue[i].color[2]);
	}
	printf("\n");
}
*/
/******************************************************************************************************************************/
void colormap_free(ColorMap* colorMap)
{
	if(!colorMap) return;
	if(colorMap->colorValue)
	{

		colorMap->numberOfColors = 0;
		return;
	}
	g_free(colorMap->colorValue);
	colorMap->numberOfColors = 0;
}
/******************************************************************************************************************************/
static void colormap_alloc(ColorMap* colorMap, gint numberOfColors)
{
	if(colorMap->colorValue)
		colormap_free(colorMap);

	if(numberOfColors<1) numberOfColors = 1;
	colorMap->numberOfColors = numberOfColors;
	colorMap->colorValue = g_malloc(numberOfColors*sizeof(OneColorValue));
}
/******************************************************************************************************************************/
static ColorMap new_colorMap(gfloat color[], gfloat value)
{
	gint c;
	ColorMap colorMap = {0,NULL};
	colormap_alloc(&colorMap, 1);
	for(c=0; c<3; c++)
		colorMap.colorValue[0].color[c] = color[c];
	colorMap.colorValue[0].value = value;
	return colorMap;
}
/******************************************************************************************************************************/
static void add_to_colorMap(ColorMap* colorMap, gfloat color[], gfloat value)
{
	gint i;
	gint c;
	OneColorValue* colorValue = NULL;
	colorValue = g_malloc((colorMap->numberOfColors+1)*sizeof(OneColorValue));
	for(i=0; i<colorMap->numberOfColors; i++)
		colorValue[i] = colorMap->colorValue[i];

	for(c=0;c<3;c++)
		colorValue[colorMap->numberOfColors].color[c] = color[c];
	colorValue[colorMap->numberOfColors].value = value;
	g_free( colorMap->colorValue);
	colorMap->colorValue = colorValue;
	colorMap->numberOfColors++;
}
/******************************************************************************************************************************/
static void sort_colorMap(ColorMap* colorMap)
{
	gint i;
	gint j;
	gint k;
	OneColorValue tmp;
	for(i=0;i<colorMap->numberOfColors-1;i++)
	{
		k = i;
		for(j=i+1;j<colorMap->numberOfColors;j++)
			if(colorMap->colorValue[k].value>colorMap->colorValue[j].value)
				k = j;
		if(k != i)
		{
			tmp = colorMap->colorValue[i];
			colorMap->colorValue[i] = colorMap->colorValue[k];
			colorMap->colorValue[k] = tmp;
		}
	}
}
/******************************************************************************************************************************/
ColorMap*  new_colorMap_min_max(gfloat minValue, gfloat maxValue)
{
	gint i;
	gint j;
	gint k;
	gfloat h = 0;
	gint ns = 4;
	gint nc = 20;
	gint n = nc *ns+1;
	gfloat color[3];
	ColorMap* colorMap;

	h = (maxValue-minValue)/(n-1) ;
	color[0] = 1.0; color[1] = 0.0; color[2] = 0.0; 

	colorMap = g_malloc(sizeof(ColorMap));
	*colorMap = new_colorMap(color, minValue);
	k = 1;
	for(j=0;j<ns;j++)
	for(i=0;i<nc;i++)
	{
		
		if(j==0) color[1] += 1.0/nc;
		if(j==1) color[0] -= 1.0/nc;
		if(j==2) color[2] += 1.0/nc;
		if(j==3) color[1] -= 1.0/nc;
		add_to_colorMap(colorMap, color, minValue +k*h);
		k++;
	}
	sort_colorMap(colorMap);
	return colorMap;
}
/******************************************************************************************************************************/
ColorMap*  new_colorMap_fromGrid(Grid* grid)
{
	gint i;
	gint j;
	gint k;
	gfloat maxValue = 0;
	gfloat minValue = 0;
	gboolean beg = TRUE;
	gfloat h = 0;
	gint ns = 4;
	gint nc = 20;
	gint n = nc *ns+1;
	gfloat color[3];
	gfloat v;
	ColorMap* colorMap;

	if(!grid)return NULL;

	for(i=0;i<grid->N[0];i++)
	{
		for(j=0;j<grid->N[1];j++)
		{
			for(k=0;k<grid->N[2];k++)
			{
				v = grid->point[i][j][k].C[4] ;
				if(beg)
				{
					beg = FALSE;
        				minValue =  v;
        				maxValue =  v;
				}
                		else
				{
        				if(minValue > v) minValue =  v;
        				if(maxValue < v) maxValue =  v;
				}
			}
		}
	}
	h = (maxValue-minValue)/(n-1) ;
	color[0] = 1.0; color[1] = 0.0; color[2] = 0.0; 

	colorMap = g_malloc(sizeof(ColorMap));
	*colorMap = new_colorMap(color, minValue);
	k = 1;
	for(j=0;j<ns;j++)
	for(i=0;i<nc;i++)
	{
		
		if(j==0) color[1] += 1.0/nc;
		if(j==1) color[0] -= 1.0/nc;
		if(j==2) color[2] += 1.0/nc;
		if(j==3) color[1] -= 1.0/nc;
		add_to_colorMap(colorMap, color, minValue +k*h);
		k++;
	}
	sort_colorMap(colorMap);
	//myColorMap = colorMap;
	return colorMap;
	/* print_colorMap(myColorMap);*/
}
/******************************************************************************************************************************/
void  set_Color_From_colorMap(ColorMap* colorMap, gfloat color[], gfloat value)
{
	gint i = 0;
	gint k = 0;
	gint c;
	if(colorMap->numberOfColors<1)
	{
		for(c=0;c<3;c++)
			color[c] = 0.5;
		return;
	}
	if(value<colorMap->colorValue[i].value)
	{
		for(c=0;c<3;c++)
			color[c] = colorMap->colorValue[i].color[c];
		return;
	}
	i = colorMap->numberOfColors-1;
	if(value>colorMap->colorValue[i].value)
	{
		for(c=0;c<3;c++)
			color[c] = colorMap->colorValue[i].color[c];
		return;
	}

	for(i=1;i<colorMap->numberOfColors-1;i++)
	{
		if(fabs(colorMap->colorValue[i].value-value)<fabs(colorMap->colorValue[k].value-value))
			k = i;
	}
	for(c=0;c<3;c++)
		color[c] = colorMap->colorValue[k].color[c];
}
/******************************************************************************************************************************/
void  reset_colorMap(GtkWidget* entry, gpointer data)
{
	gint i;
	gint j;
	gint k;
	gfloat maxValue = 0;
	gfloat minValue = 0;
	gfloat h = 0;
	gint ns = 4;
	gint nc = 20;
	gint n = nc *ns+1;
	gfloat color[3];
	G_CONST_RETURN gchar* tmp;
	ColorMap* colorMap = g_object_get_data(G_OBJECT(entry),"ColorMap");
	ColorMap* newColorMap = NULL;
	GtkWidget* handlebox = g_object_get_data(G_OBJECT(entry), "Handlebox");
	GtkWidget* darea = g_object_get_data(G_OBJECT(entry), "DrawingArea");
	GtkWidget* otherEntry = g_object_get_data(G_OBJECT(entry), "OtherEntry");

	if(!colorMap) return;

	if(colorMap->numberOfColors<1) return;


	if(data) /* this is right entry */
	{
		minValue = colorMap->colorValue[0].value;
		tmp  = gtk_entry_get_text(GTK_ENTRY(entry));
		maxValue = atof(tmp);
	}
	else
	{
		maxValue = colorMap->colorValue[colorMap->numberOfColors-1].value;
		tmp  = gtk_entry_get_text(GTK_ENTRY(entry));
		minValue = atof(tmp);
	}

	h = (maxValue-minValue)/(n-1) ;
	color[0] = 1.0; color[1] = 0.0; color[2] = 0.0; 

	newColorMap = g_malloc(sizeof(ColorMap));
	*newColorMap = new_colorMap(color, minValue);
	k = 1;
	for(j=0;j<ns;j++)
	for(i=0;i<nc;i++)
	{
		
		if(j==0) color[1] += 1.0/nc;
		if(j==1) color[0] -= 1.0/nc;
		if(j==2) color[2] += 1.0/nc;
		if(j==3) color[1] -= 1.0/nc;
		add_to_colorMap(newColorMap, color, minValue +k*h);
		k++;
	}
	sort_colorMap(newColorMap);
	colormap_free(colorMap);
	g_free(colorMap);

	colorMap = newColorMap;
	g_object_set_data(G_OBJECT(entry),"ColorMap", colorMap);
	g_object_set_data(G_OBJECT(handlebox),"ColorMap", colorMap);
	g_object_set_data(G_OBJECT(darea),"ColorMap", colorMap);
	g_object_set_data(G_OBJECT(otherEntry),"ColorMap", colorMap);

	/* print_colorMap(&myColorMap);*/
	RebuildSurf = TRUE;
	glarea_rafresh(GLArea);
	color_map_hide(handlebox);
	color_map_refresh(handlebox);
	color_map_show(handlebox);
}
/********************************************************************************/
static gint configure_event( GtkWidget *widget, GdkEventConfigure *event )
{
 
  	gint height = 0;
	GdkColor color;
	GdkColor tmpcolor;
	GdkColormap *colormap   = NULL;
  	GdkPixmap *pixmap = (GdkPixmap *)g_object_get_data(G_OBJECT(widget), "Pixmap");
  	GdkFont* font = (GdkFont *)g_object_get_data(G_OBJECT(widget), "Font");
	gboolean Ok = TRUE;
        GdkVisual* vis;
	gchar t[BSIZE];
	ColorMap* myColorMap = g_object_get_data(G_OBJECT(widget),"ColorMap");
	GdkGC *gc = g_object_get_data(G_OBJECT(widget),"Gdkgc");

	gint i;
	gint k;
	gint kOld;

	
	if (pixmap) gdk_pixmap_unref(pixmap);

	pixmap = gdk_pixmap_new(widget->window, widget->allocation.width, widget->allocation.height, -1);
	
	colormap  = gdk_window_get_colormap(widget->window);

  	height = widget->allocation.height;
        vis = gdk_colormap_get_visual(colormap);
        if(vis->depth >15) Ok = TRUE;
	else Ok = FALSE;

	 color.red = 40000; 
	 color.green = 40000; 
	 color.blue = 40000; 

	gdk_colormap_alloc_color(colormap, &color, FALSE, TRUE);

	if(Ok)
	{
		
  		for(i=0;i<widget->allocation.width;i++)
  		{
			k = i/(gdouble)(widget->allocation.width)*myColorMap->numberOfColors;

    			tmpcolor.red   = (gushort)(myColorMap->colorValue[k].color[0]*65535);
    			tmpcolor.green = (gushort)(myColorMap->colorValue[k].color[1]*65535);
    			tmpcolor.blue  = (gushort)(myColorMap->colorValue[k].color[2]*65535);

			gdk_colormap_alloc_color(colormap, &tmpcolor, FALSE, TRUE);
			gdk_gc_set_foreground(gc,&tmpcolor);
    			gdk_draw_line(pixmap,gc,i,0,i,height);
			
  		}
	
		kOld = -1;
  		for(i=0;i<widget->allocation.width;i++)
  		{
			k = i/(gdouble)(widget->allocation.width)*myColorMap->numberOfColors;
			if(k%(myColorMap->numberOfColors/4)==0 && k>0 && k<myColorMap->numberOfColors-1 && k!=kOld)
			{
				gint x = i;
				gint y = height-height/4;
				gint lentxt;
				
				sprintf(t,"%0.3f",myColorMap->colorValue[k].value);

				lentxt = gdk_string_width (font,t);
				x = i-lentxt/2;

	 			color.red = 0; 
	 			color.green = 0; 
	 			color.blue = 0; 
				gdk_color_alloc(colormap,&color);
				gdk_gc_set_foreground(gc,&color);

				gdk_gc_set_line_attributes(gc,0,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
				gdk_draw_string(pixmap,font,gc,x,y,t);
				kOld = k;
			}
		}
	}
	else
	{
		gdk_gc_set_foreground(gc,&color);
  		for(i=0;i<widget->allocation.width;i++)
    			gdk_draw_line(pixmap,gc,i,0,i,height);
  	}

  	g_object_set_data(G_OBJECT(widget), "Pixmap", pixmap);
  	return TRUE;
}
/********************************************************************************/   
static gint expose_event(GtkWidget  *widget,GdkEventExpose *event )
{
  	GdkPixmap *pixmap = NULL;

	if(event->count >0)
		return FALSE;

  	pixmap = (GdkPixmap *)g_object_get_data(G_OBJECT(widget), "Pixmap");
	if(pixmap)
		gdk_draw_pixmap(widget->window,
                  widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,
                  event->area.x, event->area.y,
                  event->area.x, event->area.y,
                  event->area.width, event->area.height);
  	return FALSE;
}
/********************************************************************************/
static GtkWidget *add_drawing_area(GtkWidget *table, gint i)
{
	GtkWidget *darea;
	GdkPixmap *pixmap = NULL;
	GdkFont* font  = gdk_fontset_load("-*-helvetica-bold-r-normal-*-*-140-*-*-*-*-*-*,*");

        font = gdk_font_load(get_font_label_name());
	/*
	if(!font)
  		font = PrincipalWindow->style->font;
		*/


	darea = gtk_drawing_area_new();
	 gtk_widget_set_size_request(GTK_WIDGET(darea), 300, -1);


	gtk_table_attach(GTK_TABLE(table),darea,i,i+1,0,1,
			(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
			(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
			0,0);
	gtk_widget_realize(darea);
	pixmap = gdk_pixmap_new(darea->window,darea->allocation.width,darea->allocation.height,-1);
	g_object_set_data(G_OBJECT(darea), "Pixmap", pixmap);
	g_object_set_data(G_OBJECT(darea), "Font", font);

	g_signal_connect(G_OBJECT(darea),"configure_event",(GtkSignalFunc)configure_event,NULL);
	g_signal_connect(G_OBJECT(darea),"expose_event",(GtkSignalFunc)expose_event,NULL);
	return darea;
}
/******************************************************************************************************************************/
GtkWidget* create_color_map_show(GtkWidget* box, ColorMap* colorMap, gchar* label)
{
  	GtkWidget *handlebox;
	GtkWidget* table; 
	GtkWidget* entry; 
	GtkWidget* entryLeft; 
	GtkWidget* entryRight; 
	GtkWidget *darea;
	GdkGC *gc = NULL;
	gint i;

  	handlebox = gtk_handle_box_new ();
  	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(handlebox),GTK_SHADOW_NONE);    
	gtk_handle_box_set_handle_position  (GTK_HANDLE_BOX(handlebox),GTK_POS_LEFT);
  	gtk_widget_show (handlebox);
  	gtk_box_pack_start (GTK_BOX (box), handlebox, FALSE, FALSE, 0);
	table = gtk_table_new(1,4,FALSE);

	gtk_container_add (GTK_CONTAINER (handlebox), table);
	
	i = 0;
	if(label)
	{
		GtkWidget* labelWid = gtk_label_new(label);
		gtk_widget_show(labelWid);
		gtk_table_attach(GTK_TABLE(table),labelWid,i,i+1,0,1,
			(GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
			(GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
			0,0);
	}
	i = 1;
	entry = gtk_entry_new();
	gtk_widget_set_size_request(entry,80,-1);
	gtk_widget_show(entry);
	gtk_table_attach(GTK_TABLE(table),entry,i,i+1,0,i,
			(GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
			(GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
			0,0);
	entryLeft = entry;

	i = 2;
	gc = gdk_gc_new(PrincipalWindow->window);
	darea = add_drawing_area(table, i);

	i = 3;
	entry = gtk_entry_new();
	gtk_widget_set_size_request(entry,80,-1);
	gtk_widget_show(entry);
	gtk_table_attach(GTK_TABLE(table),entry,i,i+1,0,1,
			(GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
			(GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
			0,0);
	entryRight = entry;

	gtk_widget_show(table);
	g_object_set_data(G_OBJECT(handlebox), "EntryLeft", entryLeft);
	g_object_set_data(G_OBJECT(handlebox), "EntryRight", entryRight);
	g_object_set_data(G_OBJECT(handlebox), "DrawingArea", darea);
	g_object_set_data(G_OBJECT(handlebox),"ColorMap", colorMap);
	g_object_set_data(G_OBJECT(handlebox),"Gdkgc", gc);

	g_object_set_data(G_OBJECT(darea),"ColorMap", colorMap);
	g_object_set_data(G_OBJECT(darea),"Gdkgc", gc);

	g_object_set_data(G_OBJECT(entryLeft), "DrawingArea", darea);
	g_object_set_data(G_OBJECT(entryRight), "DrawingArea", darea);

	g_object_set_data(G_OBJECT(entryLeft),"ColorMap", colorMap);
	g_object_set_data(G_OBJECT(entryRight),"ColorMap", colorMap);

	g_object_set_data(G_OBJECT(entryLeft),"Handlebox", handlebox);
	g_object_set_data(G_OBJECT(entryRight),"Handlebox", handlebox);

	g_object_set_data(G_OBJECT(entryLeft),"DrawingArea", darea);
	g_object_set_data(G_OBJECT(entryRight),"DrawingArea", darea);

	g_object_set_data(G_OBJECT(entryLeft),"OtherEntry", entryRight);
	g_object_set_data(G_OBJECT(entryRight),"OtherEntry", entryLeft);


	g_signal_connect(G_OBJECT (entryLeft), "activate",(GtkSignalFunc)reset_colorMap, NULL);
	g_signal_connect(G_OBJECT (entryRight), "activate",(GtkSignalFunc)reset_colorMap, GTK_OBJECT(entryLeft));

	return handlebox;
}
/******************************************************************************************************************************/
void color_map_show(GtkWidget* handlebox)
{
	GtkWidget* entryLeft = g_object_get_data(G_OBJECT(handlebox), "EntryLeft");
	GtkWidget* entryRight = g_object_get_data(G_OBJECT(handlebox), "EntryRight");
	ColorMap* myColorMap = g_object_get_data(G_OBJECT(handlebox), "ColorMap");
	gchar tmp[BSIZE];

	if(myColorMap->numberOfColors>0)
	{
		if(fabs(myColorMap->colorValue[0].value)>1e-3)
			sprintf(tmp,"%0.3f",myColorMap->colorValue[0].value);
		else
			if(fabs(myColorMap->colorValue[0].value)<1e-8)
				sprintf(tmp,"%0.1e",myColorMap->colorValue[0].value);
			else
				sprintf(tmp,"%f",myColorMap->colorValue[0].value);

		gtk_entry_set_text(GTK_ENTRY(entryLeft),tmp);
		if(fabs(myColorMap->colorValue[myColorMap->numberOfColors-1].value)>1e-3)
			sprintf(tmp,"%0.3f",myColorMap->colorValue[myColorMap->numberOfColors-1].value);
		else
			if(fabs(myColorMap->colorValue[myColorMap->numberOfColors-1].value)<1e-8)
				sprintf(tmp,"%0.1e",myColorMap->colorValue[myColorMap->numberOfColors-1].value);
			else
				sprintf(tmp,"%f",myColorMap->colorValue[myColorMap->numberOfColors-1].value);
		gtk_entry_set_text(GTK_ENTRY(entryRight),tmp);
	}

	gtk_widget_show_all(handlebox);
}
/******************************************************************************************************************************/
void color_map_refresh(GtkWidget* handlebox)
{
	GtkWidget* darea = g_object_get_data(G_OBJECT(handlebox), "DrawingArea");
	configure_event(darea, NULL);
}
/******************************************************************************************************************************/
void color_map_hide(GtkWidget* handlebox)
{
	gtk_widget_hide(handlebox);
}
