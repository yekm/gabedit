/* GabeditXYPlotWin.c */
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

#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "GabeditXYPlot.h"
#include "GabeditXYPlotWin.h"

/****************************************************************************************/
static void build_data_xyplot_curve_noconv(XYPlotWinData* winData, XYPlotData* dataCurve)
{
	gint loop;
	
	dataCurve->size=winData->size;
	if(dataCurve->size>0)
	{
		if(!dataCurve->x) g_free(dataCurve->x);
		if(!dataCurve->y) g_free(dataCurve->y);
		dataCurve->x = (gdouble*)g_malloc(sizeof(gdouble)*dataCurve->size);
		dataCurve->y = (gdouble*)g_malloc(sizeof(gdouble)*dataCurve->size);
	}
	
	for (loop=0; loop<dataCurve->size; loop++){
		dataCurve->x[loop]=winData->x[loop]*winData->scaleX;
		dataCurve->y[loop]=winData->y[loop];
	}
	dataCurve->style=winData->style;
	dataCurve->point_width=winData->point_width;
	dataCurve->line_width=winData->line_width;
	dataCurve->point_color.red=winData->point_color.red; 
	dataCurve->point_color.green=winData->point_color.green; 
	dataCurve->point_color.blue=winData->point_color.blue; 

	dataCurve->line_color.red=winData->line_color.red; 
	dataCurve->line_color.green=winData->line_color.green; 
	dataCurve->line_color.blue=winData->line_color.blue; 

	dataCurve->line_style=winData->line_style; 

}
/********************************************************************************/
static gdouble lorentzianLineshape(gdouble rel_offset)
{
	return 1.0 / (1.0 + rel_offset * rel_offset);
}
/********************************************************************************/
static gdouble gaussianLineshape(gdouble rel_offset)
{
  gdouble nln2 = -log(2.0);
  return exp(nln2 * rel_offset * rel_offset);
}
/****************************************************************************************/
static void build_data_xyplot_curve_withconv(XYPlotWinData* winData, XYPlotData* dataCurve)
{
	gdouble stepX = 1;
	gint i;
	gint j;
	gdouble (*lineshape)(gdouble);

	if(winData->convType==GABEDIT_CONV_TYPE_LORENTZ)
	       lineshape = lorentzianLineshape;
	else
	       lineshape = gaussianLineshape;


	
	dataCurve->size=20*winData->size+2;
	if(dataCurve->size<8000) dataCurve->size = 8000;
	if(dataCurve->size>0 && winData->size)
	{
		if(!dataCurve->x) g_free(dataCurve->x);
		if(!dataCurve->y) g_free(dataCurve->y);
		dataCurve->x = (gdouble*)g_malloc(sizeof(gdouble)*dataCurve->size);
		dataCurve->y = (gdouble*)g_malloc(sizeof(gdouble)*dataCurve->size);
	}
	stepX = (winData->xmax - winData->xmin)/(dataCurve->size-1);

	if(winData->size>0)
	for (i=0; i < dataCurve->size; i++)
	{
		gdouble yy = 0.0;
		gdouble xx =  winData->xmin + i*stepX;
		for (j=0; j < winData->size; j++)
		{
			gdouble center = (gdouble) winData->x[j]*winData->scaleX ;
			gdouble rel_offset = (xx - center) / winData->halfWidth;
			yy += winData->y[j]*lineshape(rel_offset);
		}
		dataCurve->x[i] = xx;
		dataCurve->y[i] = yy;
	}



	dataCurve->style=winData->style;
	dataCurve->point_width=winData->point_width;
	dataCurve->line_width=winData->line_width;
	dataCurve->point_color.red=winData->point_color.red; 
	dataCurve->point_color.green=winData->point_color.green; 
	dataCurve->point_color.blue=winData->point_color.blue; 

	dataCurve->line_color.red=winData->line_color.red; 
	dataCurve->line_color.green=winData->line_color.green; 
	dataCurve->line_color.blue=winData->line_color.blue; 

	dataCurve->line_style=winData->line_style; 

}
/****************************************************************************************/
static void build_data_xyplot_curve(XYPlotWinData* winData, XYPlotData* dataCurve)
{
	switch(winData->convType)
	{
		case GABEDIT_CONV_TYPE_NONE :
			build_data_xyplot_curve_noconv(winData, dataCurve);
			break;
		case GABEDIT_CONV_TYPE_LORENTZ :
		case GABEDIT_CONV_TYPE_GAUSS :
			build_data_xyplot_curve_withconv(winData, dataCurve);
	}
}
/****************************************************************************************/
static void build_data_xyplot_peaks(XYPlotWinData* winData, XYPlotData* dataPeaks)
{
	gint loop;
	dataPeaks->size=3*winData->size+2;
	if(dataPeaks->size>0)
	{
		if(!dataPeaks->x) g_free(dataPeaks->x);
		if(!dataPeaks->y) g_free(dataPeaks->y);
		dataPeaks->x = (gdouble*)g_malloc(sizeof(gdouble)*dataPeaks->size);
		dataPeaks->y = (gdouble*)g_malloc(sizeof(gdouble)*dataPeaks->size);
	}
	
     
	dataPeaks->x[0]=winData->xmin;
	dataPeaks->y[0]=winData->ymin;
	dataPeaks->x[dataPeaks->size-1]=winData->xmax;
	dataPeaks->y[dataPeaks->size-1]=winData->ymin;
	for (loop=0; loop<winData->size; loop++){
		gint iold = loop*3+1;
		gdouble xx = winData->x[loop]*winData->scaleX;
		dataPeaks->x[iold]=xx;
		dataPeaks->y[iold]=winData->ymin;

		dataPeaks->x[iold+1]=xx;
		dataPeaks->y[iold+1]=winData->y[loop];

		dataPeaks->x[iold+2]=xx;
		dataPeaks->y[iold+2]=winData->ymin;
	}

	dataPeaks->style=winData->style;
	dataPeaks->point_width=winData->point_width;
	dataPeaks->line_width=winData->line_width;
	dataPeaks->point_color.red=winData->point_color.red*0.9; 
	dataPeaks->point_color.green=winData->point_color.green*0.9; 
	dataPeaks->point_color.blue=winData->point_color.blue*0.9; 

	dataPeaks->line_color.red=winData->line_color.red*0.9; 
	dataPeaks->line_color.green=winData->line_color.green*0.9; 
	dataPeaks->line_color.blue=winData->line_color.blue*0.9; 

	dataPeaks->line_style=winData->line_style; 
}
/****************************************************************************************/
static void build_data_xyplot(XYPlotWinData* winData)
{
	XYPlotData* dataPeaks = NULL;
	XYPlotData* dataCurve = NULL;
	if(!winData->showDataPeaks && !winData->showDataCurve) return;
	if(!winData->dataPeaks)
	{
		winData->dataPeaks = (XYPlotData*)g_malloc(sizeof(XYPlotData));
		winData->dataPeaks->size = 0;
		winData->dataPeaks->x = NULL;
		winData->dataPeaks->y = NULL;
	}
	if(!winData->dataCurve) 
	{
		winData->dataCurve = (XYPlotData*)g_malloc(sizeof(XYPlotData));
		winData->dataCurve->size = 0;
		winData->dataCurve->x = NULL;
		winData->dataCurve->y = NULL;
	}

	dataPeaks = winData->dataPeaks;
	dataCurve = winData->dataCurve;

	build_data_xyplot_curve(winData, dataCurve);
	build_data_xyplot_peaks(winData, dataPeaks);
}
/****************************************************************************************/
static XYPlotWinData* get_win_data(GabeditXYPlot *xyplot, gint size, gdouble* x, gdouble* y)
{
	XYPlotWinData* winData = (XYPlotWinData*)g_malloc(sizeof(XYPlotWinData));
	gint loop;
	winData->showDataPeaks = FALSE;
	winData->showDataCurve = TRUE;
	winData->dataPeaks = NULL;
	winData->dataCurve = NULL;
	

	winData->size=size;
	winData->x = NULL;
	winData->y = NULL;
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &(winData->xmin), &(winData->xmax), &(winData->ymin), &(winData->ymax));
	if(size>0)
	{
		winData->x = (gdouble*) g_malloc(sizeof(gdouble)*size);
		winData->y = (gdouble*) g_malloc(sizeof(gdouble)*size);
		for(loop=0;loop<size;loop++)
		{
			winData->x[loop] = x[loop];
			winData->y[loop] = y[loop];
		}
	}
	winData->style=GABEDIT_XYPLOT_DATA_LINES;

	winData->point_width=0;
	winData->line_width=2;

	winData->point_color.red=0;
	winData->point_color.green=0;
	winData->point_color.blue=0;

	winData->line_color.red=65000;
	winData->line_color.green=0;
	winData->line_color.blue=0;

 	winData->line_style=GDK_LINE_SOLID;

 	winData->halfWidth = fabs(winData->xmax-winData->xmin)/30;
 	winData->convType = GABEDIT_CONV_TYPE_LORENTZ;
 	winData->scaleX = 1;


	build_data_xyplot(winData);

	return winData;

}
/****************************************************************************************/
static void gabedit_xyplot_add_windata(GabeditXYPlot *xyplot, XYPlotWinData* data)
{
	GList* data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");
  	if (!data_list || g_list_find (data_list, (gpointer)data)==NULL)
	{
		data_list=g_list_append(data_list, (gpointer) data);
		g_object_set_data(G_OBJECT (xyplot), "DataList", data_list);
	}
}
/****************************************************************************************/
static void gabedit_xyplot_show_curve_peaks(GabeditXYPlot *xyplot)
{
	GList* data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");
	GList* current = NULL;
	XYPlotWinData* data;
	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		if(data->showDataPeaks) gabedit_xyplot_add_data(xyplot, data->dataPeaks);
		if(data->showDataCurve) gabedit_xyplot_add_data(xyplot, data->dataCurve);
	}
}
/****************************************************************************************/
static void gabedit_xyplot_refresh_dat(GabeditXYPlot *xyplot)
{
	GList* data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");
	GList* current = NULL;
	XYPlotWinData* data;
	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		if(data->convType!=GABEDIT_CONV_TYPE_NONE)
		{
			gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &(data->xmin), &(data->xmax), &(data->ymin), &(data->ymax));
			build_data_xyplot(data);
		}
	}
}
/****************************************************************************************/
static void spin_hminor_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_set_ticks_hminor(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));	
	}
}
/****************************************************************************************/
static void spin_hmajor_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_set_ticks_hmajor(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));
	}
}
/****************************************************************************************/
static void spin_vminor_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_set_ticks_vminor(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));
	}
}
/****************************************************************************************/
static void spin_vmajor_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_set_ticks_vmajor(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));	
	}
}
/****************************************************************************************/
static void toggle_h_major_grids_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMAJOR_GRID, gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_h_minor_grids_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMINOR_GRID, gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_v_major_grids_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMAJOR_GRID, gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_v_minor_grids_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMINOR_GRID, gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_show_left_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_show_left_legends (GABEDIT_XYPLOT(xyplot), gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_show_right_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_show_right_legends (GABEDIT_XYPLOT(xyplot), gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_show_top_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_show_top_legends (GABEDIT_XYPLOT(xyplot), gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_show_bottom_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_show_bottom_legends (GABEDIT_XYPLOT(xyplot), gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_reflect_x_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_reflect_x (GABEDIT_XYPLOT(xyplot), gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void toggle_reflect_y_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gabedit_xyplot_reflect_y (GABEDIT_XYPLOT(xyplot), gtk_toggle_button_get_active(togglebutton));
	}
}
/****************************************************************************************/
static void spin_l_digits_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		gabedit_xyplot_set_legends_digits(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));
	}
}
/********************************************************************************/
static void toggle_no_convolution_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	GtkWidget* xyplot = NULL;
	GList* data_list = NULL;
	GList* current = NULL;
	XYPlotWinData* data;


	if(!user_data || !G_IS_OBJECT(user_data)) return;
	if(!gtk_toggle_button_get_active(togglebutton)) return;

	xyplot = GTK_WIDGET(user_data);
	data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");

	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		if(data->convType!=GABEDIT_CONV_TYPE_NONE)
		{
			data->convType=GABEDIT_CONV_TYPE_NONE;
			build_data_xyplot(data);
		}
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/********************************************************************************/
static void toggle_lorentzian_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	GtkWidget* xyplot = NULL;
	GList* data_list = NULL;
	GList* current = NULL;
	XYPlotWinData* data;


	if(!user_data || !G_IS_OBJECT(user_data)) return;
	if(!gtk_toggle_button_get_active(togglebutton)) return;

	xyplot = GTK_WIDGET(user_data);
	data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");

	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		if(data->convType!=GABEDIT_CONV_TYPE_LORENTZ)
		{
			data->convType=GABEDIT_CONV_TYPE_LORENTZ;
			build_data_xyplot(data);
		}
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/********************************************************************************/
static void toggle_gaussian_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	GtkWidget* xyplot = NULL;
	GList* data_list = NULL;
	GList* current = NULL;
	XYPlotWinData* data;


	if(!user_data || !G_IS_OBJECT(user_data)) return;
	if(!gtk_toggle_button_get_active(togglebutton)) return;

	xyplot = GTK_WIDGET(user_data);
	data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");

	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		if(data->convType!=GABEDIT_CONV_TYPE_GAUSS)
		{
			data->convType=GABEDIT_CONV_TYPE_GAUSS;
			build_data_xyplot(data);
		}
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/********************************************************************************/
static void toggle_show_peaks_toggled(GtkToggleButton *togglebutton, gpointer user_data)
{
	GtkWidget* xyplot = NULL;
	GList* data_list = NULL;
	GList* current = NULL;
	XYPlotWinData* data;
	gboolean showPeaks = FALSE;

	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");

	if(!data_list) return;

	showPeaks = gtk_toggle_button_get_active(togglebutton);
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		gabedit_xyplot_remove_data(GABEDIT_XYPLOT(xyplot), (gpointer)data->dataPeaks);
		if(data->showDataPeaks!=showPeaks)
		{
			data->showDataPeaks=showPeaks;
			build_data_xyplot(data);
			if(data->showDataPeaks)
				gabedit_xyplot_add_data(GABEDIT_XYPLOT(xyplot), (gpointer)data->dataPeaks);
		}
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));

}
/****************************************************************************************/
static gboolean xyplot_motion_notify_event(GtkWidget *xyplot, GdkEventMotion *event, gpointer user_data)
{
	double xv, yv;
	int x, y;
	char str[50];
	int context_id;
	GtkWidget* statusbar = g_object_get_data(G_OBJECT (xyplot), "StatusBar");

	x=event->x;
	y=event->y;

	if (event->is_hint || (event->window != xyplot->window))
		gdk_window_get_pointer (xyplot->window, &x, &y, NULL);

	if(gabedit_xyplot_get_point(GABEDIT_XYPLOT(xyplot), x, y, &xv, &yv))
	snprintf(str, 50, "Mouse position: %f, %f", xv, yv);
	else
	snprintf(str, " ");
	context_id=gtk_statusbar_get_context_id (GTK_STATUSBAR(statusbar), "mouse position");
	gtk_statusbar_push (GTK_STATUSBAR(statusbar), context_id, str);
    
	return TRUE;
}
/********************************************************************************/
static void activate_entry_xmin(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	gdouble a;
	GtkWidget* xyplot = NULL;
	gdouble xmin;
	gdouble ymin;
	gdouble xmax;
	gdouble ymax;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	a = atof(t);
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &xmin, &xmax, &ymin, &ymax);

	if(a>= xmax)
	{
		gchar* tmp = g_strdup_printf("%0.3f",xmin);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	gabedit_xyplot_set_range_xmin (GABEDIT_XYPLOT(xyplot), a);
	gabedit_xyplot_refresh_dat(GABEDIT_XYPLOT(xyplot));
}
/********************************************************************************/
static void activate_entry_xmax(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	gdouble a;
	GtkWidget* xyplot = NULL;
	gdouble xmin;
	gdouble ymin;
	gdouble xmax;
	gdouble ymax;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	a = atof(t);
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &xmin, &xmax, &ymin, &ymax);

	if(a<=xmin)
	{
		gchar* tmp = g_strdup_printf("%0.3f",xmax);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	gabedit_xyplot_set_range_xmax (GABEDIT_XYPLOT(xyplot), a);
	gabedit_xyplot_refresh_dat(GABEDIT_XYPLOT(xyplot));
}
/********************************************************************************/
static void activate_entry_ymin(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	gdouble a;
	GtkWidget* xyplot = NULL;
	gdouble xmin;
	gdouble ymin;
	gdouble xmax;
	gdouble ymax;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	a = atof(t);
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &xmin, &xmax, &ymin, &ymax);

	if(a>= ymax)
	{
		gchar* tmp = g_strdup_printf("%0.3f",ymin);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	gabedit_xyplot_set_range_ymin (GABEDIT_XYPLOT(xyplot), a);
	gabedit_xyplot_refresh_dat(GABEDIT_XYPLOT(xyplot));
}
/********************************************************************************/
static void activate_entry_ymax(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	gdouble a;
	GtkWidget* xyplot = NULL;
	gdouble xmin;
	gdouble ymin;
	gdouble xmax;
	gdouble ymax;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	a = atof(t);
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &xmin, &xmax, &ymin, &ymax);

	if(a<= ymin)
	{
		gchar* tmp = g_strdup_printf("%0.3f",ymax);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	gabedit_xyplot_set_range_ymax (GABEDIT_XYPLOT(xyplot), a);
	gabedit_xyplot_refresh_dat(GABEDIT_XYPLOT(xyplot));
}
/********************************************************************************/
static void activate_entry_half_width(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	gdouble a;
	GtkWidget* xyplot = NULL;
	gdouble xmin;
	gdouble ymin;
	gdouble xmax;
	gdouble ymax;
	GList* data_list = NULL;
	GList* current = NULL;
	XYPlotWinData* data;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	a = atof(t);
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &xmin, &xmax, &ymin, &ymax);

	if(a<= 0)
	{
		gchar* tmp = g_strdup_printf("%0.3f",fabs(xmax-xmin)/30);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");
	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		data->halfWidth = a;
		if(data->convType!=GABEDIT_CONV_TYPE_NONE)
		{
			build_data_xyplot(data);
		}
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/********************************************************************************/
static void activate_entry_scale_x(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	gdouble a;
	GtkWidget* xyplot = NULL;
	gdouble xmin;
	gdouble ymin;
	gdouble xmax;
	gdouble ymax;
	GList* data_list = NULL;
	GList* current = NULL;
	XYPlotWinData* data;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	a = atof(t);
	gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &xmin, &xmax, &ymin, &ymax);

	if(a<= 0)
	{
		gchar* tmp = g_strdup_printf("%0.3f",1.0);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");
	if(!data_list) return;
	current=g_list_first(data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotWinData*)current->data;
		data->scaleX = a;
		build_data_xyplot(data);
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/*************************************************************************************/
static void Waiting(gdouble tsecond)
{
        GTimer *timer;
        gdouble elaps;
        gulong m ;
	
        timer =g_timer_new( );
	g_timer_start( timer );
	g_timer_reset( timer );
        do{
		elaps = g_timer_elapsed( timer,&m);
        }while(elaps<tsecond);
 	g_timer_destroy(timer);
}
/**************************************************************************/
static void saveImage(GtkFileChooser *SelecFile, gint response_id)
{       
	gchar *fileName;
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (SelecFile), "XYPLOT");
	gchar* type = g_object_get_data (G_OBJECT (SelecFile), "ImageType");

 	if(response_id != GTK_RESPONSE_OK) return;

 	fileName = gtk_file_chooser_get_filename(SelecFile);
	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() ) gtk_main_iteration();
	Waiting(1.0);

	if(!GABEDIT_IS_XYPLOT(xyplot)) return;
	gtk_widget_hide(xyplot);
	gtk_widget_show(xyplot);
	while( gtk_events_pending() ) gtk_main_iteration();

	gabedit_xyplot_save(GABEDIT_XYPLOT(xyplot), fileName, type);
}
/********************************************************************************/
static void saveImageDlg(GtkWidget* wid, gpointer user_data)
{
	GtkFileFilter *filter;
	GtkWidget* xyplot = GTK_WIDGET(user_data);
	gboolean multiple = FALSE;
	GtkWidget *dialog;
	gchar* type = g_object_get_data (G_OBJECT (wid), "ImageType");
	gchar* tmp = NULL;

	dialog = g_object_new (GTK_TYPE_FILE_CHOOSER_DIALOG, "action", GTK_FILE_CHOOSER_ACTION_SAVE, "file-system-backend", "gtk+", "select-multiple", multiple, NULL);
	gtk_window_set_title (GTK_WINDOW (dialog), "Save XY plot");
	gtk_dialog_add_buttons (GTK_DIALOG (dialog), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_OK, NULL);
	filter = gtk_file_filter_new ();
	
	tmp = g_strdup_printf("*.%s",type);
	gtk_file_filter_set_name (filter, tmp);
	gtk_file_filter_add_pattern (filter, tmp);
	gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (dialog), filter);
	g_free(tmp);


	gtk_dialog_set_default_response (GTK_DIALOG (dialog), GTK_RESPONSE_OK);
	g_signal_connect (dialog, "response",  G_CALLBACK (saveImage),GTK_OBJECT(dialog));
	g_signal_connect (dialog, "response", G_CALLBACK (gtk_widget_destroy),GTK_OBJECT(dialog));
	g_object_set_data(G_OBJECT (dialog), "ImageType", type);
	gtk_widget_show(dialog);
	if(!strcmp(type,"tpng"))
		tmp = g_strdup_printf("xyplot.png");
	else
		tmp = g_strdup_printf("xyplot.%s",type);
	gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER (dialog),tmp);
	g_free(tmp);

	g_object_set_data (G_OBJECT (dialog), "XYPLOT",xyplot);
	gtk_window_set_modal (GTK_WINDOW (dialog), TRUE);
}
/****************************************************************************************/
static void gabedit_xyplot_autorange(GabeditXYPlot *xyplot)
{
	GList* data_list = g_object_get_data(G_OBJECT (xyplot), "DataList");
	GList* current = NULL;
	XYPlotWinData* data;
	GtkWidget *entry_half_width = g_object_get_data(G_OBJECT (xyplot), "EntryHalfWidth");
	GtkWidget *entry_scale_x = g_object_get_data(G_OBJECT (xyplot), "EntryScaleX");
	GtkWidget*entry_x_min = g_object_get_data(G_OBJECT (xyplot), "EntryXMin");
	GtkWidget*entry_x_max = g_object_get_data(G_OBJECT (xyplot), "EntryXMax");
	GtkWidget*entry_y_min = g_object_get_data(G_OBJECT (xyplot), "EntryYMin");
	GtkWidget*entry_y_max = g_object_get_data(G_OBJECT (xyplot), "EntryYMax");

	if(!data_list) return;
	current=g_list_first(data_list);
	if(!current) return;
	data = (XYPlotWinData*)current->data;
	if(data->dataCurve) gabedit_xyplot_set_autorange (xyplot, data->dataCurve);
	if(data->dataPeaks) gabedit_xyplot_set_autorange (xyplot, data->dataPeaks);
	if(data->convType!=GABEDIT_CONV_TYPE_NONE && (data->dataCurve ||data->dataPeaks ))
	{
		gchar tmp[100];
		gabedit_xyplot_get_range (GABEDIT_XYPLOT(xyplot), &(data->xmin), &(data->xmax), &(data->ymin), &(data->ymax));

		sprintf(tmp,"%0.3f",data->xmin);
		gtk_entry_set_text(GTK_ENTRY(entry_x_min),tmp);
		sprintf(tmp,"%0.3f",data->xmax);
		gtk_entry_set_text(GTK_ENTRY(entry_x_max),tmp);
		sprintf(tmp,"%0.3f",data->ymin);
		gtk_entry_set_text(GTK_ENTRY(entry_y_min),tmp);
		sprintf(tmp,"%0.3f",data->ymax);
		gtk_entry_set_text(GTK_ENTRY(entry_y_max),tmp);

		data->halfWidth = fabs(data->xmax-data->xmin)/30;

		build_data_xyplot(data);

		sprintf(tmp,"%0.3f",data->halfWidth);
		gtk_entry_set_text(GTK_ENTRY(entry_half_width),tmp);

		sprintf(tmp,"%0.3f",data->scaleX);
		gtk_entry_set_text(GTK_ENTRY(entry_scale_x),tmp);

	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
}
/****************************************************************************************/
void gabedit_xyplotwin_add_data(GtkWidget *winXYPlot, gint size, gdouble* x, gdouble* y)
{
	GabeditXYPlot *xyplot = g_object_get_data(G_OBJECT (winXYPlot), "XYPLOT");
	XYPlotWinData* winData = NULL;
	if(!xyplot || !G_IS_OBJECT(xyplot)) return;
	winData = get_win_data(xyplot, size, x, y);
	gabedit_xyplot_add_windata(xyplot, winData);
	gabedit_xyplot_refresh_dat(GABEDIT_XYPLOT(xyplot));
	gabedit_xyplot_show_curve_peaks(GABEDIT_XYPLOT(xyplot));
}
/****************************************************************************************/
void gabedit_xyplotwin_autorange(GtkWidget *winXYPlot)
{
	GabeditXYPlot *xyplot = g_object_get_data(G_OBJECT (winXYPlot), "XYPLOT");
	if(!xyplot || !G_IS_OBJECT(xyplot)) return;
	gabedit_xyplot_autorange(xyplot);
}
/****************************************************************************************/
GtkWidget* gabedit_xyplotwin_new(gchar* title)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* table1 = NULL;
	GtkWidget* table2 = NULL;
	GtkWidget* frame_xyplot = NULL;
	GtkWidget* xyplot = NULL;
	GtkWidget* tmp_hbox = NULL;
	GtkWidget* tmp_label = NULL;
	GtkWidget* vbox = NULL;
	GtkWidget* hbox = NULL;

	GtkWidget *frame_set_ticks = NULL;
	GtkWidget *vbox_set_ticks = NULL;
	GtkWidget *label_hminor = NULL;
	GtkWidget *spin_hminor = NULL;
	GtkWidget *label_hmajor = NULL;
	GtkWidget *spin_hmajor = NULL;
	GtkWidget *label_vminor = NULL;
	GtkWidget *spin_vminor = NULL;
	GtkWidget *label_vmajor = NULL;
	GtkWidget *spin_vmajor = NULL;

	GtkWidget *frame_set_grids = NULL;
	GtkWidget *vbox_set_grids = NULL;
	GtkWidget *toggle_h_major_grids = NULL;
	GtkWidget *toggle_h_minor_grids = NULL;
	GtkWidget *toggle_v_major_grids = NULL;
	GtkWidget *toggle_v_minor_grids = NULL;

	GtkWidget *frame_set_range = NULL;
	GtkWidget *vbox_set_range = NULL;
	GtkWidget* entry_x_min = NULL;
	GtkWidget* entry_x_max = NULL;
	GtkWidget* entry_y_min = NULL;
	GtkWidget* entry_y_max = NULL;

	GtkWidget *frame_set_directions = NULL;
	GtkWidget *vbox_set_directions = NULL;
	GtkWidget *toggle_reflect_x = NULL;
	GtkWidget *toggle_reflect_y = NULL;
	GtkWidget *frame_screen_capture = NULL;
	GtkWidget *vbox_screen_capture = NULL;

	GtkWidget *frame_set_legends = NULL;
	GtkWidget *vbox_set_legends = NULL;
	GtkWidget *spin_l_digits = NULL;
	GtkWidget *toggle_show_left = NULL;
	GtkWidget *toggle_show_right = NULL;
	GtkWidget *toggle_show_top = NULL;
	GtkWidget *toggle_show_bottom = NULL;

	GtkWidget *buttonPNG = NULL;
	GtkWidget *buttonTPNG = NULL;
	GtkWidget *buttonBMP = NULL;
	GtkWidget *buttonJPEG = NULL;

	GtkWidget *statusbar = NULL;
	static gchar* imageTypes[] = {"bmp","png","tpng","jpeg"};

	GtkWidget *frame_set_data = NULL;
	GtkWidget *vbox_set_data = NULL;
	GtkWidget *toggle_no_convolution = NULL;
	GtkWidget *toggle_lorentzian = NULL;
	GtkWidget *toggle_gaussian = NULL;
	GtkWidget *toggle_show_peaks = NULL;
	GtkWidget *entry_half_width = NULL;
	GtkWidget *entry_scale_x = NULL;
	GtkWidget* expander = NULL;
	GtkWidget* hbox_data = NULL;

	GList* data_list = NULL;

	gdouble xmin = 0;
	gdouble xmax = 10;
	gdouble ymin = 0;
	gdouble ymax = 20;

	gint hmajor = 11;
	gint hminor = 3;
	gint vmajor = 11;
	gint vminor = 3;
	gchar tmp[100];
	
	gtk_window_set_title (GTK_WINDOW (window), title);
	/*
	gtk_signal_connect (GTK_OBJECT (window), "delete_event", G_CALLBACK (gtk_widget_destroy), NULL);
	*/
	gtk_container_set_border_width(GTK_CONTAINER (window), 10);
	
	table1=gtk_table_new(5, 3, FALSE);
	gtk_container_add(GTK_CONTAINER(window), table1);
	gtk_widget_show(table1);
  
	frame_xyplot=gtk_frame_new("GabeditPlot");
	gtk_table_attach(GTK_TABLE(table1), frame_xyplot, 0, 1, 0, 1, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
	gtk_widget_show(frame_xyplot);
  
	xyplot = gabedit_xyplot_new();
	gtk_container_add(GTK_CONTAINER(frame_xyplot), xyplot);
	gtk_widget_show (xyplot);

	g_object_set_data (G_OBJECT (window), "XYPLOT",xyplot);

	gabedit_xyplot_reflect_x (GABEDIT_XYPLOT(xyplot), FALSE);
	gabedit_xyplot_reflect_y (GABEDIT_XYPLOT(xyplot), FALSE);

	gabedit_xyplot_show_left_legends (GABEDIT_XYPLOT(xyplot), TRUE);
	gabedit_xyplot_show_right_legends (GABEDIT_XYPLOT(xyplot), FALSE);
	gabedit_xyplot_show_top_legends (GABEDIT_XYPLOT(xyplot), FALSE);
	gabedit_xyplot_show_bottom_legends (GABEDIT_XYPLOT(xyplot), TRUE);

	expander = gtk_expander_new("More options");
	gtk_table_attach(GTK_TABLE(table1), expander, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
	gtk_widget_show (expander);
	table2=gtk_table_new(3, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(expander), table2);
	gtk_widget_show (table2);
	/*
	table2=gtk_table_new(3, 2, FALSE);
	gtk_table_attach(GTK_TABLE(table1), table2, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 0);
	gtk_widget_show (table2);
	*/

	frame_set_ticks=gtk_frame_new("Set ticks");
	gtk_table_attach(GTK_TABLE(table2), frame_set_ticks, 0, 1, 0, 1, GTK_FILL, GTK_FILL, 0, 1);
	gtk_widget_show(frame_set_ticks);

	vbox_set_ticks=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_set_ticks), vbox_set_ticks);
	gtk_widget_show(vbox_set_ticks);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_ticks), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	label_hmajor=gtk_label_new("X Major: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), label_hmajor, TRUE, FALSE, 2);
	gtk_widget_show(label_hmajor); 
	
	spin_hmajor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), spin_hmajor, TRUE, FALSE, 2);
	gtk_widget_show(spin_hmajor);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_ticks), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	label_vmajor=gtk_label_new("Y Major: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), label_vmajor, TRUE, FALSE, 2);
	gtk_widget_show(label_vmajor); 
	
	spin_vmajor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), spin_vmajor, TRUE, FALSE, 2);
	gtk_widget_show(spin_vmajor);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_ticks), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	label_hminor=gtk_label_new("X Minor: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), label_hminor, TRUE, FALSE, 2);
	gtk_widget_show(label_hminor); 
	
	spin_hminor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), spin_hminor, TRUE, FALSE, 2);
	gtk_widget_show(spin_hminor);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_ticks), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	label_vminor=gtk_label_new("Y Minor: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), label_vminor, TRUE, FALSE, 2);
	gtk_widget_show(label_vminor); 
	
	spin_vminor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), spin_vminor, TRUE, FALSE, 2);
	gtk_widget_show(spin_vminor);


	frame_set_grids=gtk_frame_new("Set grids");
	gtk_table_attach(GTK_TABLE(table2), frame_set_grids, 1, 2, 0, 1, GTK_FILL, GTK_FILL, 5, 1);
	gtk_widget_show(frame_set_grids);

	vbox_set_grids=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_set_grids), vbox_set_grids);
	gtk_widget_show(vbox_set_grids);

	toggle_h_major_grids=gtk_check_button_new_with_label("X Major");
	gtk_box_pack_start(GTK_BOX(vbox_set_grids), toggle_h_major_grids, TRUE, FALSE, 2);
	gtk_widget_show(toggle_h_major_grids);

	toggle_v_major_grids=gtk_check_button_new_with_label("Y Major");
	gtk_box_pack_start(GTK_BOX(vbox_set_grids), toggle_v_major_grids, TRUE, FALSE, 2);
	gtk_widget_show(toggle_v_major_grids);

	toggle_h_minor_grids=gtk_check_button_new_with_label("X Minor");
	gtk_box_pack_start(GTK_BOX(vbox_set_grids), toggle_h_minor_grids, TRUE, FALSE, 2);
	gtk_widget_show(toggle_h_minor_grids);

	toggle_v_minor_grids=gtk_check_button_new_with_label("Y Minor");
	gtk_box_pack_start(GTK_BOX(vbox_set_grids), toggle_v_minor_grids, TRUE, FALSE, 2);
	gtk_widget_show(toggle_v_minor_grids);

	frame_set_range=gtk_frame_new("Set range");
	gtk_table_attach(GTK_TABLE(table2), frame_set_range, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0, 1);
	gtk_widget_show(frame_set_range);

	vbox_set_range=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_set_range), vbox_set_range);
	gtk_widget_show(vbox_set_range);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_range), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	tmp_label=gtk_label_new("X Min: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 2);
	gtk_widget_show(tmp_label); 
	
	entry_x_min = gtk_entry_new();
	gtk_widget_set_size_request(entry_x_min,50,-1);
	sprintf(tmp,"%0.3f",xmin);
	gtk_entry_set_text(GTK_ENTRY(entry_x_min),tmp);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), entry_x_min, TRUE, FALSE, 2);
	gtk_widget_show(entry_x_min);

	tmp_label=gtk_label_new("X Max: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 2);
	gtk_widget_show(tmp_label); 
	
	entry_x_max = gtk_entry_new();
	gtk_widget_set_size_request(entry_x_max,50,-1);
	sprintf(tmp,"%0.3f",xmax);
	gtk_entry_set_text(GTK_ENTRY(entry_x_max),tmp);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), entry_x_max, TRUE, FALSE, 2);
	gtk_widget_show(entry_x_max);

	tmp_label=gtk_label_new("Y Min: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 2);
	gtk_widget_show(tmp_label); 
	
	entry_y_min = gtk_entry_new();
	gtk_widget_set_size_request(entry_y_min,50,-1);
	sprintf(tmp,"%0.3f",ymin);
	gtk_entry_set_text(GTK_ENTRY(entry_y_min),tmp);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), entry_y_min, TRUE, FALSE, 2);
	gtk_widget_show(entry_y_min);

	tmp_label=gtk_label_new("Y Max: ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 2);
	gtk_widget_show(tmp_label); 
	
	entry_y_max = gtk_entry_new();
	gtk_widget_set_size_request(entry_y_max,50,-1);
	sprintf(tmp,"%0.3f",ymax);
	gtk_entry_set_text(GTK_ENTRY(entry_y_max),tmp);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), entry_y_max, TRUE, FALSE, 2);
	gtk_widget_show(entry_y_max);

	frame_set_legends = gtk_frame_new("Set legends");
	gtk_table_attach(GTK_TABLE(table2), frame_set_legends, 1, 2, 1, 2, GTK_FILL | GTK_FILL, GTK_FILL | GTK_FILL, 5, 1);
	gtk_widget_show(frame_set_legends);

	vbox_set_legends=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_set_legends), vbox_set_legends);
	gtk_widget_show(vbox_set_legends);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_legends), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	tmp_label=gtk_label_new("digits : ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 2);
	gtk_widget_show(tmp_label); 

	spin_l_digits = gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(tmp_hbox), spin_l_digits, FALSE, FALSE, 2);
	gtk_widget_show (spin_l_digits);

	toggle_show_left = gtk_check_button_new_with_label("Left");
	gtk_box_pack_start(GTK_BOX(vbox_set_legends), toggle_show_left, TRUE, FALSE, 2);
	gtk_widget_show(toggle_show_left);

	toggle_show_right = gtk_check_button_new_with_label("Right");
	gtk_box_pack_start(GTK_BOX(vbox_set_legends), toggle_show_right, TRUE, FALSE, 2);
	gtk_widget_show(toggle_show_right);

	toggle_show_top = gtk_check_button_new_with_label("Top");
	gtk_box_pack_start(GTK_BOX(vbox_set_legends), toggle_show_top, TRUE, FALSE, 2);
	gtk_widget_show(toggle_show_top);

	toggle_show_bottom = gtk_check_button_new_with_label("Bottom");
	gtk_box_pack_start(GTK_BOX(vbox_set_legends), toggle_show_bottom, TRUE, FALSE, 2);
	gtk_widget_show(toggle_show_bottom);

	vbox = gtk_hbox_new(TRUE, 0);
	gtk_table_attach(GTK_TABLE(table2), vbox, 0, 1, 2, 3, GTK_FILL | GTK_FILL, GTK_FILL | GTK_FILL, 0, 1);
	gtk_widget_show(vbox);

	frame_set_directions=gtk_frame_new("Set directions");
	gtk_box_pack_start(GTK_BOX(vbox), frame_set_directions, TRUE, TRUE, 0);
	gtk_widget_show(frame_set_directions);

	vbox_set_directions=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_set_directions), vbox_set_directions);
	gtk_widget_show(vbox_set_directions);

	toggle_reflect_x=gtk_check_button_new_with_label("Reflect X");
	gtk_box_pack_start(GTK_BOX(vbox_set_directions), toggle_reflect_x, TRUE, FALSE, 2);
	gtk_widget_show(toggle_reflect_x);

	toggle_reflect_y=gtk_check_button_new_with_label("Reflect Y");
	gtk_box_pack_start(GTK_BOX(vbox_set_directions), toggle_reflect_y, TRUE, FALSE, 2);
	gtk_widget_show(toggle_reflect_y);

	frame_screen_capture=gtk_frame_new("Screen capture");
	gtk_box_pack_start(GTK_BOX(vbox), frame_screen_capture, TRUE, TRUE, 0);
	gtk_widget_show(frame_screen_capture);

	vbox_screen_capture=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_screen_capture), vbox_screen_capture);
	gtk_widget_show(vbox_screen_capture);

	buttonPNG = gtk_button_new_with_label ("PNG");
	gtk_widget_set_size_request(buttonPNG,50,-1);
	gtk_box_pack_start(GTK_BOX(vbox_screen_capture), buttonPNG, TRUE, FALSE, 1);
	gtk_widget_show (buttonPNG);

	buttonTPNG = gtk_button_new_with_label ("Tr. PNG");
	gtk_widget_set_size_request(buttonTPNG,50,-1);
	gtk_box_pack_start(GTK_BOX(vbox_screen_capture), buttonTPNG, TRUE, FALSE, 1);
	gtk_widget_show (buttonTPNG);

	buttonBMP = gtk_button_new_with_label ("BMP");
	gtk_widget_set_size_request(buttonBMP,50,-1);
	gtk_box_pack_start(GTK_BOX(vbox_screen_capture), buttonBMP, TRUE, FALSE, 1);
	gtk_widget_show (buttonBMP);

	buttonJPEG = gtk_button_new_with_label ("JPEG");
	gtk_widget_set_size_request(buttonJPEG,50,-1);
	gtk_box_pack_start(GTK_BOX(vbox_screen_capture), buttonJPEG, TRUE, FALSE, 1);
	gtk_widget_show (buttonJPEG);


	/*
	statusbar=gtk_statusbar_new();
	gtk_table_attach(GTK_TABLE(table2), statusbar, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 5, 5);
	gtk_widget_show (statusbar);
	g_object_set_data(G_OBJECT (xyplot), "StatusBar", statusbar);
	*/
	g_object_set_data(G_OBJECT (xyplot), "DataList", data_list);

	frame_set_data=gtk_frame_new("Set data");
	gtk_table_attach(GTK_TABLE(table1), frame_set_data, 0, 1, 2, 3, GTK_FILL, GTK_FILL, 0, 5);
	gtk_widget_show(frame_set_data);

	vbox_set_data=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame_set_data), vbox_set_data);
	gtk_widget_show(vbox_set_data);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_data), hbox);
	gtk_widget_show(hbox);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox), tmp_hbox);
	gtk_widget_show(tmp_hbox);

	toggle_no_convolution = gtk_radio_button_new_with_label( NULL,"No convolution" );
	gtk_box_pack_start(GTK_BOX(tmp_hbox), toggle_no_convolution, FALSE, FALSE, 2);
	gtk_widget_show(toggle_no_convolution); 

	toggle_lorentzian = gtk_radio_button_new_with_label(gtk_radio_button_get_group (GTK_RADIO_BUTTON (toggle_no_convolution)),"Lorentzian lineshape" );
	gtk_box_pack_start(GTK_BOX(tmp_hbox), toggle_lorentzian, FALSE, FALSE, 2);
	gtk_widget_show(toggle_lorentzian); 

	toggle_gaussian = gtk_radio_button_new_with_label(gtk_radio_button_get_group (GTK_RADIO_BUTTON (toggle_no_convolution)),"Gaussian lineshape" );
	gtk_box_pack_start(GTK_BOX(tmp_hbox), toggle_gaussian, FALSE, FALSE, 2);
	gtk_widget_show(toggle_gaussian); 

	toggle_show_peaks = gtk_check_button_new_with_label("Show peaks");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), toggle_show_peaks, FALSE, FALSE, 4);
	gtk_widget_show(toggle_show_peaks);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(vbox_set_data), hbox);
	gtk_widget_show(hbox);

	tmp_hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox), tmp_hbox);
	gtk_widget_show(tmp_hbox);


	tmp_label=gtk_label_new("Half-Width : ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 4);
	gtk_widget_show(tmp_label); 

	entry_half_width = gtk_entry_new();
	gtk_widget_set_size_request(entry_half_width,50,-1);
	gtk_entry_set_text(GTK_ENTRY(entry_half_width),"0.25");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), entry_half_width, FALSE, FALSE, 4);
	gtk_widget_show(entry_half_width);

	tmp_label=gtk_label_new("Scale X : ");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), tmp_label, FALSE, FALSE, 2);
	gtk_widget_show(tmp_label); 

	entry_scale_x = gtk_entry_new();
	gtk_widget_set_size_request(entry_scale_x,50,-1);
	gtk_entry_set_text(GTK_ENTRY(entry_scale_x),"1.0");
	gtk_box_pack_start(GTK_BOX(tmp_hbox), entry_scale_x, FALSE, FALSE, 2);
	gtk_widget_show(entry_scale_x);
	hbox_data = tmp_hbox;

	statusbar=gtk_statusbar_new();
	gtk_table_attach(GTK_TABLE(table1), statusbar, 0, 1, 3, 4, GTK_FILL, GTK_FILL, 5, 5);
	gtk_widget_show (statusbar);
	g_object_set_data(G_OBJECT (xyplot), "StatusBar", statusbar);


	gabedit_xyplot_set_ticks(GABEDIT_XYPLOT(xyplot), hmajor, hminor, vmajor, vminor);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_hminor), hminor);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_hmajor), hmajor);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_vminor), vminor);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_vmajor), vmajor);

        gabedit_xyplot_set_range(GABEDIT_XYPLOT(xyplot),  0.0,  10,  0,  20);

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_h_major_grids), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_h_minor_grids), FALSE);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMINOR_GRID, FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_v_major_grids), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_v_minor_grids), FALSE);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMINOR_GRID, FALSE);

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_left), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_right), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_top), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_bottom), TRUE);

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_reflect_x), FALSE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_reflect_y), FALSE);

	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_l_digits), 5);
	gabedit_xyplot_set_legends_digits(GABEDIT_XYPLOT(xyplot), 5);

	g_signal_connect(G_OBJECT(spin_hminor), "value-changed", G_CALLBACK(spin_hminor_changed_value), xyplot);
	g_signal_connect(G_OBJECT(spin_hmajor), "value-changed", G_CALLBACK(spin_hmajor_changed_value), xyplot);
	g_signal_connect(G_OBJECT(spin_vminor), "value-changed", G_CALLBACK(spin_vminor_changed_value), xyplot);
	g_signal_connect(G_OBJECT(spin_vmajor), "value-changed", G_CALLBACK(spin_vmajor_changed_value), xyplot);

	g_signal_connect(G_OBJECT(toggle_h_major_grids), "toggled", G_CALLBACK(toggle_h_major_grids_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_h_minor_grids), "toggled", G_CALLBACK(toggle_h_minor_grids_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_v_major_grids), "toggled", G_CALLBACK(toggle_v_major_grids_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_v_minor_grids), "toggled", G_CALLBACK(toggle_v_minor_grids_toggled), xyplot);

	g_signal_connect (G_OBJECT (entry_x_min), "activate", (GCallback)activate_entry_xmin, xyplot);
	g_signal_connect (G_OBJECT (entry_x_max), "activate", (GCallback)activate_entry_xmax, xyplot);
	g_signal_connect (G_OBJECT (entry_y_min), "activate", (GCallback)activate_entry_ymin, xyplot);
	g_signal_connect (G_OBJECT (entry_y_max), "activate", (GCallback)activate_entry_ymax, xyplot);

	g_signal_connect(G_OBJECT(toggle_show_left), "toggled", G_CALLBACK(toggle_show_left_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_show_right), "toggled", G_CALLBACK(toggle_show_right_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_show_top), "toggled", G_CALLBACK(toggle_show_top_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_show_bottom), "toggled", G_CALLBACK(toggle_show_bottom_toggled), xyplot);

	g_signal_connect(G_OBJECT(toggle_reflect_x), "toggled", G_CALLBACK(toggle_reflect_x_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_reflect_y), "toggled", G_CALLBACK(toggle_reflect_y_toggled), xyplot);

	g_signal_connect(G_OBJECT(spin_l_digits), "value-changed", G_CALLBACK(spin_l_digits_changed_value), xyplot);

	g_object_set_data(G_OBJECT (buttonBMP), "ImageType", imageTypes[0]);
	g_signal_connect (G_OBJECT (buttonBMP), "clicked", G_CALLBACK(saveImageDlg), xyplot);

	g_object_set_data(G_OBJECT (buttonPNG), "ImageType", imageTypes[1]);
	g_signal_connect (G_OBJECT (buttonPNG), "clicked", G_CALLBACK(saveImageDlg), xyplot);

	g_object_set_data(G_OBJECT (buttonTPNG), "ImageType", imageTypes[2]);
	g_signal_connect (G_OBJECT (buttonTPNG), "clicked", G_CALLBACK(saveImageDlg), xyplot);

	g_object_set_data(G_OBJECT (buttonJPEG), "ImageType", imageTypes[3]);
	g_signal_connect (G_OBJECT (buttonJPEG), "clicked", G_CALLBACK(saveImageDlg), xyplot);

	g_signal_connect(G_OBJECT(toggle_no_convolution), "toggled", G_CALLBACK(toggle_no_convolution_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_lorentzian), "toggled", G_CALLBACK(toggle_lorentzian_toggled), xyplot);
	g_signal_connect(G_OBJECT(toggle_gaussian), "toggled", G_CALLBACK(toggle_gaussian_toggled), xyplot);
	g_signal_connect (G_OBJECT (entry_half_width), "activate", (GCallback)activate_entry_half_width, xyplot);
	g_signal_connect (G_OBJECT (entry_scale_x), "activate", (GCallback)activate_entry_scale_x, xyplot);
	g_signal_connect(G_OBJECT(toggle_show_peaks), "toggled", G_CALLBACK(toggle_show_peaks_toggled), xyplot);


	g_signal_connect_after(G_OBJECT(xyplot), "motion-notify-event", G_CALLBACK(xyplot_motion_notify_event), NULL);

	gtk_widget_show (window);


	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_peaks), FALSE);
	toggle_show_peaks_toggled(GTK_TOGGLE_BUTTON(toggle_show_peaks), xyplot);
	g_object_set_data(G_OBJECT (xyplot), "EntryHalfWidth", entry_half_width);
	g_object_set_data(G_OBJECT (xyplot), "EntryScaleX", entry_scale_x);
	g_object_set_data(G_OBJECT (xyplot), "EntryXMin", entry_x_min);
	g_object_set_data(G_OBJECT (xyplot), "EntryXMax", entry_x_max);
	g_object_set_data(G_OBJECT (xyplot), "EntryYMin", entry_y_min);
	g_object_set_data(G_OBJECT (xyplot), "EntryYMax", entry_y_max);
	g_object_set_data(G_OBJECT (xyplot), "ReflectX", toggle_reflect_x);
	g_object_set_data(G_OBJECT (xyplot), "ReflectY", toggle_reflect_y);
	g_object_set_data(G_OBJECT (xyplot), "HBoxData", hbox_data);
	g_object_set_data(G_OBJECT (xyplot), "Window", window);

	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_lorentzian), TRUE);
	toggle_lorentzian_toggled((GtkToggleButton*)toggle_lorentzian,xyplot);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_top), TRUE);
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_show_right), TRUE);

	g_object_set_data(G_OBJECT (window), "HBoxData", hbox_data);



  
	return window;
}
/****************************************************************************************/
void gabedit_xyplotwin_relect_x(GtkWidget* window, gboolean active)
{
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget* toggle_reflect_x = g_object_get_data (G_OBJECT (xyplot), "ReflectX");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_reflect_x), active);
}
/****************************************************************************************/
void gabedit_xyplotwin_relect_y(GtkWidget* window, gboolean active)
{
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget* toggle_reflect_y = g_object_get_data (G_OBJECT (xyplot), "ReflectY");
	gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(toggle_reflect_y), active);
}
/****************************************************************************************/
void gabedit_xyplotwin_set_half_width(GtkWidget* window, gdouble value)
{
	gchar tmp[100];
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget *entry_half_width = g_object_get_data(G_OBJECT (xyplot), "EntryHalfWidth");
	sprintf(tmp,"%0.3f",value);
	gtk_entry_set_text(GTK_ENTRY(entry_half_width),tmp);
	activate_entry_half_width(entry_half_width, xyplot);
}
/****************************************************************************************/
void gabedit_xyplotwin_set_xmin(GtkWidget* window, gdouble value)
{
	gchar tmp[100];
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget *entry_x_min = g_object_get_data(G_OBJECT (xyplot), "EntryXMin");
	sprintf(tmp,"%0.3f",value);
	gtk_entry_set_text(GTK_ENTRY(entry_x_min),tmp);
	activate_entry_xmin(entry_x_min, xyplot);
}
/****************************************************************************************/
void gabedit_xyplotwin_set_xmax(GtkWidget* window, gdouble value)
{
	gchar tmp[100];
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget *entry_x_max = g_object_get_data(G_OBJECT (xyplot), "EntryXMax");
	sprintf(tmp,"%0.3f",value);
	gtk_entry_set_text(GTK_ENTRY(entry_x_max),tmp);
	activate_entry_xmax(entry_x_max, xyplot);
}
/****************************************************************************************/
void gabedit_xyplotwin_set_ymin(GtkWidget* window, gdouble value)
{
	gchar tmp[100];
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget *entry_y_min = g_object_get_data(G_OBJECT (xyplot), "EntryYMin");
	sprintf(tmp,"%0.3f",value);
	gtk_entry_set_text(GTK_ENTRY(entry_y_min),tmp);
	activate_entry_ymin(entry_y_min, xyplot);
}
/****************************************************************************************/
void gabedit_xyplotwin_set_ymax(GtkWidget* window, gdouble value)
{
	gchar tmp[100];
	GtkWidget* xyplot = g_object_get_data (G_OBJECT (window), "XYPLOT");
	GtkWidget *entry_y_max = g_object_get_data(G_OBJECT (xyplot), "EntryYMax");
	sprintf(tmp,"%0.3f",value);
	gtk_entry_set_text(GTK_ENTRY(entry_y_max),tmp);
	activate_entry_ymax(entry_y_max, xyplot);
}
/****************************************************************************************/
GtkWidget* gabedit_xyplotwin_new_testing(gchar* title)
{
	GtkWidget* window = gabedit_xyplotwin_new(title);
	gint size = 20;
	gint i;
	gdouble x[20];
	gdouble y[20];
	for(i=0;i<size;i++)
	{
		x[i] = i;
		y[i] = rand()/(gdouble)RAND_MAX*size;
	}
	gabedit_xyplotwin_add_data(window, size, x, y);
	gabedit_xyplotwin_autorange(window);
	return window;
}
/****************************************************************************************/
GtkWidget* gabedit_xyplotwin_new_with_xy(gchar* title,  gint size, gdouble* x, gdouble* y)
{
	GtkWidget* window = gabedit_xyplotwin_new(title);
	gabedit_xyplotwin_add_data(window, size, x, y);
	gabedit_xyplotwin_autorange(window);
	return window;
}
