/* VibSpectrum.c */
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
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include "../../gtkplot/gtkplot.h"
#include "../../gtkplot/gtkplotcanvas.h"
#include "../../gtkplot/gtkplotdata.h"
#include "../../gtkplot/gtkplotprint.h"
#include "../Common/Global.h"
#include "../Utils/Constantes.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/Utils.h"
#include "../Files/FileChooser.h"
#include "../Common/Windows.h"
#include "../OpenGL/Vibration.h"

typedef struct _DataVibSpec
{
	GtkWidget **plots;
	gint nplots;

	GtkPlotData **dataset;
	gint ndataset;

	gdouble* outputSpectrumX;
	gdouble* outputSpectrumYIR;
	gdouble* outputSpectrumYRaman;
	gint numberOfFrequences;

	gdouble minFrequence;
	gdouble maxFrequence;

	gdouble minIntensity;
	gdouble maxIntensity;

	gdouble xMinorTick;
	gdouble xMajorTick;

	gdouble yMinorTick;
	gdouble yMajorTick;

	gdouble halfWidth;
	gdouble scaleFrequence;
	gboolean showIR;
	gboolean showRaman;
	gboolean lorentzian;
	Vibration vibration;
}DataVibSpec;

/** Internal functions ***********************************************************/
static DataVibSpec* newDataVibSpec(Vibration vibration);
static void computeMaxIntensity(DataVibSpec* dataVibSpec);
static gint activate_plot(GtkWidget *widget, gpointer data);
static void refreshPlot(GtkWidget *widget, gpointer data);
static void resetEntrys(GtkWidget *widget, gpointer data);
static void resetIR(GtkWidget *widget, gpointer data);
static void resetRaman(GtkWidget *widget, gpointer data);
static GtkWidget * newLayer(GtkWidget *canvas, DataVibSpec* dataVibSpec);
static gdouble lorentzianLineshape(gdouble rel_offset);
static gdouble gaussianLineshape(gdouble rel_offset);
static void calculSpectrum(DataVibSpec* dataVibSpec, gboolean computeMaxFreq);
static void buildPlot(GtkWidget *active_plot, DataVibSpec* dataVibSpec);
static void resetPlot(GtkWidget *active_plot, DataVibSpec* dataVibSpec);
static GtkWidget *createDialogFrame(GtkWidget *vboxall, GtkWidget *vibSpecDlg, DataVibSpec* dataVibSpec);
/********************************************************************************/
static DataVibSpec* newDataVibSpec(Vibration vibration)
{
	DataVibSpec* dataVibSpec = g_malloc(sizeof(DataVibSpec));
	gint j;

	dataVibSpec->plots = NULL;
	dataVibSpec->nplots = 0;

	dataVibSpec->dataset = NULL;
	dataVibSpec->ndataset = 0;

	dataVibSpec->outputSpectrumX = NULL;
	dataVibSpec->outputSpectrumYIR = NULL;
	dataVibSpec->outputSpectrumYRaman = NULL;
	dataVibSpec->numberOfFrequences = 0;
	dataVibSpec->minFrequence = 0;
	dataVibSpec->maxFrequence = 1000;
	dataVibSpec->minIntensity = 0.0;
	dataVibSpec->maxIntensity = 1.0;

	dataVibSpec->xMinorTick = 100.0;
	dataVibSpec->xMajorTick = 500.0;

	dataVibSpec->yMinorTick =  dataVibSpec->maxIntensity/10;
	dataVibSpec->yMajorTick = dataVibSpec->maxIntensity/5;

	dataVibSpec->showIR = TRUE;
	dataVibSpec->showRaman = FALSE;
	dataVibSpec->halfWidth = 20;
	dataVibSpec->scaleFrequence = 1.0;
	dataVibSpec->lorentzian = TRUE;

	dataVibSpec->vibration.numberOfFrequences = vibration.numberOfFrequences;
	dataVibSpec->vibration.modes = g_malloc(vibration.numberOfFrequences*sizeof(VibrationMode));
	for (j=0; j < vibration.numberOfFrequences; j++)
	{
		dataVibSpec->vibration.modes[j].frequence = vibration.modes[j].frequence;
		dataVibSpec->vibration.modes[j].IRIntensity = vibration.modes[j].IRIntensity;
		dataVibSpec->vibration.modes[j].RamanIntensity = vibration.modes[j].RamanIntensity;
	}


	return dataVibSpec;
}
/********************************************************************************/
static void  freeDataVibSpec(DataVibSpec* dataVibSpec)
{
	if(!dataVibSpec) return;
	if(dataVibSpec->vibration.modes) g_free(dataVibSpec->vibration.modes);
	if(dataVibSpec->outputSpectrumX) g_free(dataVibSpec->outputSpectrumX);
	if(dataVibSpec->outputSpectrumYIR) g_free(dataVibSpec->outputSpectrumYIR);
	if(dataVibSpec->outputSpectrumYRaman) g_free(dataVibSpec->outputSpectrumYRaman);
	g_free(dataVibSpec);
}
/********************************************************************************/
static void destroyAll(GtkWidget *vibSpecDlg)
{
	DataVibSpec* dataVibSpec = g_object_get_data (G_OBJECT (vibSpecDlg), "Data");
	freeDataVibSpec(dataVibSpec);
	gtk_widget_destroy (vibSpecDlg);
}
/********************************************************************************/
static void computeMaxIntensity(DataVibSpec* dataVibSpec)
{
	gint i;
	for (i=0; i < dataVibSpec->numberOfFrequences; i++)
	{
		if(i==0) 
		{
			if(dataVibSpec->showIR && dataVibSpec->showRaman)
			{
				dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYIR[i];
				if(dataVibSpec->outputSpectrumYIR[i]<dataVibSpec->outputSpectrumYRaman[i]) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYRaman[i];
			}
			else
			if(dataVibSpec->showIR) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYIR[i];
			else if(dataVibSpec->showRaman) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYRaman[i];
		}
		else
		{
			if(dataVibSpec->showIR && dataVibSpec->showRaman)
			{
				if(dataVibSpec->maxIntensity<dataVibSpec->outputSpectrumYIR[i]) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYIR[i];
				if(dataVibSpec->maxIntensity<dataVibSpec->outputSpectrumYRaman[i]) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYRaman[i];
			}
			else
			{
				if(dataVibSpec->showIR && dataVibSpec->maxIntensity<dataVibSpec->outputSpectrumYIR[i]) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYIR[i];
				if(dataVibSpec->showRaman && dataVibSpec->maxIntensity<dataVibSpec->outputSpectrumYRaman[i]) dataVibSpec->maxIntensity = dataVibSpec->outputSpectrumYRaman[i];
			}
		}
	}
	dataVibSpec->maxIntensity += dataVibSpec->maxIntensity*0.05;
	if(fabs(dataVibSpec->maxIntensity)<1e-10) dataVibSpec->maxIntensity = 1.0;
	dataVibSpec->yMinorTick =  dataVibSpec->maxIntensity/10;
	dataVibSpec->yMajorTick = dataVibSpec->maxIntensity/5;
}
/********************************************************************************/
static void resetEntrys(GtkWidget *vibSpecDlg, gpointer data)
{
	gchar t[BSIZE];
	GtkWidget* entryHalfWidth = NULL;
	GtkWidget* entryScaleFrequence = NULL;
	GtkWidget* entryMinFreq = NULL;
	GtkWidget* entryMaxFreq = NULL;
	GtkWidget* entryMinInt = NULL;
	GtkWidget* entryMaxInt = NULL;
	GtkWidget *entryXMinorTick;
	GtkWidget *entryXMajorTick;
	GtkWidget *entryYMinorTick;
	GtkWidget *entryYMajorTick;
	DataVibSpec* dataVibSpec = NULL;
	 
	if(!GTK_IS_WIDGET(vibSpecDlg)) return;

	dataVibSpec = g_object_get_data (G_OBJECT (vibSpecDlg), "Data");
	entryHalfWidth = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryHalfWidth");
	entryScaleFrequence = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryScaleFrequence");
	entryMinFreq = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryMinFreq");
	entryMaxFreq = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryMaxFreq");
	entryMinInt = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryMinInt");
	entryMaxInt = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryMaxInt");

	entryXMinorTick = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryXMinorTick");
	entryXMajorTick = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryXMajorTick");

	entryYMinorTick = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryYMinorTick");
	entryYMajorTick = g_object_get_data (G_OBJECT (vibSpecDlg), "EntryYMajorTick");

	sprintf(t,"%0.2f",dataVibSpec->halfWidth);
	gtk_entry_set_text(GTK_ENTRY(entryHalfWidth),t);
	sprintf(t,"%0.2f",dataVibSpec->scaleFrequence);
	gtk_entry_set_text(GTK_ENTRY(entryScaleFrequence),t);
	sprintf(t,"%0.4f",dataVibSpec->minFrequence);
	gtk_entry_set_text(GTK_ENTRY(entryMinFreq),t);
	sprintf(t,"%0.4f",dataVibSpec->maxFrequence);
	gtk_entry_set_text(GTK_ENTRY(entryMaxFreq),t);

	sprintf(t,"%0.4f",dataVibSpec->minIntensity);
	gtk_entry_set_text(GTK_ENTRY(entryMinInt),t);

	sprintf(t,"%0.4f",dataVibSpec->maxIntensity);
	gtk_entry_set_text(GTK_ENTRY(entryMaxInt),t);

	sprintf(t,"%0.4f",dataVibSpec->xMinorTick);
	gtk_entry_set_text(GTK_ENTRY(entryXMinorTick),t);
	sprintf(t,"%0.4f",dataVibSpec->xMajorTick);
	gtk_entry_set_text(GTK_ENTRY(entryXMajorTick),t);

	sprintf(t,"%0.4f",dataVibSpec->yMinorTick);
	gtk_entry_set_text(GTK_ENTRY(entryYMinorTick),t);
	sprintf(t,"%0.4f",dataVibSpec->yMajorTick);
	gtk_entry_set_text(GTK_ENTRY(entryYMajorTick),t);
}
/********************************************************************************/
static gint activate_plot(GtkWidget *widget, gpointer data)
{
	GtkWidget **widget_list = NULL;
	GtkWidget *active_widget = NULL;
	GtkWidget *canvas = NULL;
	gint n = 0;
	DataVibSpec* dataVibSpec = NULL;
	 
	dataVibSpec = g_object_get_data (G_OBJECT (widget), "Data");

	if(!dataVibSpec) return FALSE;

	if(GTK_IS_PLOT_CANVAS(widget)) 
	{
		canvas = GTK_WIDGET(widget);
		widget_list = dataVibSpec->plots;
		active_widget = GTK_WIDGET(gtk_plot_canvas_get_active_plot(GTK_PLOT_CANVAS(widget)));
	}

	while(n < dataVibSpec->nplots)
	{
		if(widget_list[n] == active_widget)
		{
			gtk_plot_canvas_set_active_plot(GTK_PLOT_CANVAS(canvas),GTK_PLOT(dataVibSpec->plots[n]));  
		}
		else
		{
		}
		n++;
	}
	if(GTK_IS_PLOT_CANVAS(widget))
	{
  		GtkPlotCanvas *canvas = NULL;
		GtkPlot *active_plot = NULL;
		GList *dataset = NULL;
		GtkPlotData *data = NULL;
		gint i = 0;
		gint x = 0, y = 0;
		gdouble xi = 0, yi = 0;
 
		canvas = GTK_PLOT_CANVAS(widget);
		if(!canvas) return FALSE;

		active_plot = canvas->active_plot;
		if(!active_plot) return FALSE;

  		dataset = active_plot->data_sets;
		if(!dataset) return FALSE;

		gtk_widget_get_pointer(widget, &x, &y);

		while(dataset)
		{
			data = (GtkPlotData *)dataset->data;
			for(i=0; i<data->num_points; i++)
			{
				gtk_plot_get_pixel(active_plot, data->x[i], data->y[i], &xi, &yi);
				if(abs(xi-x) <= 5 && abs(yi-y) <= 5)
				{
					/*
					canvas->active_x = data->x[i];
					canvas->active_y = data->y[i];
					*/
					gchar t[BSIZE];
					GtkWidget *statutX = g_object_get_data (G_OBJECT (widget), "StatutX");
					GtkWidget *statutY = g_object_get_data (G_OBJECT (widget), "StatutY");
					guint idStatus = 0;

					idStatus= gtk_statusbar_get_context_id(GTK_STATUSBAR(statutX),"Testing");
		                        gtk_statusbar_pop(GTK_STATUSBAR(statutX),idStatus);
					sprintf(t,"Frequency = %0.4f",data->x[i]);
		                        gtk_statusbar_push(GTK_STATUSBAR(statutX),idStatus, t);

					idStatus= gtk_statusbar_get_context_id(GTK_STATUSBAR(statutY),"Testing");
		                        gtk_statusbar_pop(GTK_STATUSBAR(statutY),idStatus);
					sprintf(t,"Intensity     = %0.4f",data->y[i]);
		                        gtk_statusbar_push(GTK_STATUSBAR(statutY),idStatus, t);
					break;
				}
			}
			dataset = dataset->next;
		}
	}
	return TRUE;
}
/********************************************************************************/
static void refreshPlot(GtkWidget *widget, gpointer data)
{
	GtkWidget *canvas;
	GtkWidget *plot;
	DataVibSpec* dataVibSpec;

	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(dataVibSpec && dataVibSpec->dataset)
	{
		gtk_widget_hide(GTK_WIDGET(dataVibSpec->dataset[0]));
		gtk_widget_hide(GTK_WIDGET(dataVibSpec->dataset[1]));
		if(dataVibSpec->showIR)  gtk_widget_show(GTK_WIDGET(dataVibSpec->dataset[0]));
		if(dataVibSpec->showRaman) gtk_widget_show(GTK_WIDGET(dataVibSpec->dataset[1]));
	}

	plot = g_object_get_data (G_OBJECT (data), "Plot");
	if(GTK_IS_WIDGET(plot))
	{
		if(dataVibSpec) 
		{
			resetPlot(GTK_WIDGET(plot), dataVibSpec);
		}
	}

	canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	if(GTK_IS_WIDGET(canvas))
	{
		gtk_plot_canvas_paint(GTK_PLOT_CANVAS(canvas));
		gtk_plot_canvas_refresh(GTK_PLOT_CANVAS(canvas));
	}
	if(GTK_IS_WIDGET(plot)) gtk_plot_refresh(GTK_PLOT(plot), NULL);

}
/********************************************************************************/
static void resetIR(GtkWidget *widget, gpointer data)
{
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;

	dataVibSpec->showIR = !dataVibSpec->showIR;
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(widget, data);
}
/********************************************************************************/
static void resetRaman(GtkWidget *widget, gpointer data)
{
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	dataVibSpec->showRaman = !dataVibSpec->showRaman;
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(widget, data);
}
/********************************************************************************/
static void resetLorentzian(GtkWidget *widget, gpointer data)
{
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	dataVibSpec->lorentzian = TRUE;
	calculSpectrum(dataVibSpec,FALSE);
	if(dataVibSpec->dataset)
	{
		gtk_plot_data_set_points(dataVibSpec->dataset[0], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYIR, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
		gtk_plot_data_set_points(dataVibSpec->dataset[1], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYRaman, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
	}
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(widget, data);
}
/********************************************************************************/
static void resetGauss(GtkWidget *widget, gpointer data)
{
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	dataVibSpec->lorentzian = FALSE;
	calculSpectrum(dataVibSpec,FALSE);
	if(dataVibSpec->dataset)
	{
		gtk_plot_data_set_points(dataVibSpec->dataset[0], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYIR, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
		gtk_plot_data_set_points(dataVibSpec->dataset[1], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYRaman, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
	}
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(widget, data);
}
/********************************************************************************/
static void activateEntryHalfWidth(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<=0)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->halfWidth);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->halfWidth = x;
	calculSpectrum(dataVibSpec,FALSE);
	if(dataVibSpec->dataset)
	{
		gtk_plot_data_set_points(dataVibSpec->dataset[0], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYIR, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
		gtk_plot_data_set_points(dataVibSpec->dataset[1], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYRaman, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
	}
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(entry, data);

}
/********************************************************************************/
static void activateEntryScaleFrequence(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<=0)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->scaleFrequence);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->scaleFrequence = x;
	calculSpectrum(dataVibSpec, TRUE);
	if(dataVibSpec->dataset)
	{
		gtk_plot_data_set_points(dataVibSpec->dataset[0], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYIR, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
		gtk_plot_data_set_points(dataVibSpec->dataset[1], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYRaman, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
	}
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryMinFrequence(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<=0)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->minFrequence);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->minFrequence = x;
	calculSpectrum(dataVibSpec, FALSE);
	if(dataVibSpec->dataset)
	{
		gtk_plot_data_set_points(dataVibSpec->dataset[0], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYIR, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
		gtk_plot_data_set_points(dataVibSpec->dataset[1], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYRaman, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
	}
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryMaxFrequence(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<=0 || x < dataVibSpec->minFrequence)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->maxFrequence);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->maxFrequence = x;
	calculSpectrum(dataVibSpec, FALSE);
	if(dataVibSpec->dataset)
	{
		gtk_plot_data_set_points(dataVibSpec->dataset[0], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYIR, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
		gtk_plot_data_set_points(dataVibSpec->dataset[1], 
				dataVibSpec->outputSpectrumX, 
				dataVibSpec->outputSpectrumYRaman, 
				NULL, 
				NULL,
			       	dataVibSpec->numberOfFrequences);
	}
	computeMaxIntensity(dataVibSpec);
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryMinIntensity(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x>= dataVibSpec->maxIntensity)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->minIntensity);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->minIntensity = x;
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryMaxIntensity(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<= dataVibSpec->minIntensity)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->maxIntensity);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->maxIntensity = x;
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryXMinorTick(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<0 || x>= dataVibSpec->xMajorTick)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->xMinorTick);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->xMinorTick = x;
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryXMajorTick(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<= dataVibSpec->xMinorTick)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->xMajorTick);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->xMajorTick = x;
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryYMinorTick(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<0 || x>= dataVibSpec->yMajorTick)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->yMinorTick);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->yMinorTick = x;
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void activateEntryYMajorTick(GtkWidget *entry, gpointer data)
{
	G_CONST_RETURN gchar* t;
	gdouble x;
	DataVibSpec* dataVibSpec;
	dataVibSpec = g_object_get_data (G_OBJECT (data), "Data");
	if(!dataVibSpec) return;
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	x = atof(t);
	if(x<= dataVibSpec->yMinorTick)
	{
		gchar* tmp = g_strdup_printf("%0.2f",dataVibSpec->yMajorTick);
		gtk_entry_set_text(GTK_ENTRY(entry),tmp);
		g_free(tmp);
		return;
	}
	dataVibSpec->yMajorTick = x;
	resetEntrys(data, NULL);
	refreshPlot(entry, data);
}
/********************************************************************************/
static void writePortrait(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");

 	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	if(GTK_IS_PLOT_CANVAS(canvas))
		gtk_plot_canvas_export_ps(GTK_PLOT_CANVAS(canvas), FileName, 0, 0, GTK_PLOT_LETTER);
	else
	{
		GtkWidget* mes = Message("Sorry , I can not create the ps file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
	}
}
/********************************************************************************/
static void writePortraitDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writePortrait, "Save spectrum", GABEDIT_TYPEFILE_PS,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void writeLandscape(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");

 	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
	if(GTK_IS_PLOT_CANVAS(canvas))
		gtk_plot_canvas_export_ps(GTK_PLOT_CANVAS(canvas), FileName, 1, 0, GTK_PLOT_LETTER);
	else
	{
		GtkWidget* mes = Message("Sorry , I can not create the ps file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
	}
}
/********************************************************************************/
static void writeLandscapeDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writeLandscape, "Save spectrum", GABEDIT_TYPEFILE_PS,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static guchar *get_rgb_image(GtkWidget* canvas)
{
	GtkWidget *drawable;
	GtkPlot* plot;
	gfloat fac=255.0/65535.0;
	GdkColormap *colormap;
  	guint height;
  	guint width;
	guint32 pixel;
  	GdkImage* image = NULL;
	GdkVisual *v;
	guint8 component;
	guint k=0;
	gint x;
	gint y;
	gint i;
	guchar* rgbbuf=NULL;

	
	plot = GTK_PLOT_CANVAS(canvas)->active_plot;
	drawable = GTK_WIDGET(plot);
  

	colormap = gdk_window_get_colormap(GTK_WIDGET(drawable)->window);
  	height = drawable->allocation.height;
  	width = drawable->allocation.width;
	rgbbuf=(guchar *) g_malloc(3*width*height*sizeof(guchar));

  	if(!colormap) return NULL;
	if(!rgbbuf)
	{
            GtkWidget* mess = Message("Sorry: couldn't allocate memory\n","Error",TRUE);
	    gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
	    return NULL;
	}
	
	image = gdk_image_get(drawable->window,0,0,width,height);

	v = gdk_colormap_get_visual(colormap);

	switch(v->type)
	{
		case GDK_VISUAL_STATIC_GRAY:
		case GDK_VISUAL_GRAYSCALE:
		case GDK_VISUAL_STATIC_COLOR:
		case GDK_VISUAL_PSEUDO_COLOR:
		for(y=height-1;y>=0;y--)
		for(x=0;x<(gint)width;x++)
		{
			pixel = gdk_image_get_pixel(image, x, y);
			rgbbuf[k] = (guchar)(colormap->colors[pixel].red*fac);
			rgbbuf[k+1] =(guchar) (colormap->colors[pixel].green*fac);
			rgbbuf[k+2] =(guchar) (colormap->colors[pixel].blue*fac);
			k+=3;
		}
		break;

	    case GDK_VISUAL_TRUE_COLOR:
		for(y=height-1;y>=0;y--)
		for(x=0;x<(gint)width;x++)
		{
			pixel = gdk_image_get_pixel(image, x, y);
	      		component = 0;
	      		for (i = 24; i < 32; i += v->red_prec)
				component |= ((pixel & v->red_mask) << (32 - v->red_shift - v->red_prec)) >> i;
	      		rgbbuf[k] = (guchar)(component);
	      		
			component = 0;
	      		for (i = 24; i < 32; i += v->green_prec)
				component |= ((pixel & v->green_mask) << (32 - v->green_shift - v->green_prec)) >> i;
	      		rgbbuf[k+1] = (guchar)(component);
	      		component = 0;
	      		for (i = 24; i < 32; i += v->blue_prec)
				component |= ((pixel & v->blue_mask) << (32 - v->blue_shift - v->blue_prec)) >> i;
	      		rgbbuf[k+2] = (guchar)(component);
	      		k += 3;
		}
	       break;
	    case GDK_VISUAL_DIRECT_COLOR:
		for(y=height-1;y>=0;y--)
		for(x=0;x<(gint)width;x++)
		{
			pixel = gdk_image_get_pixel(image, x, y);
	      		component = colormap->colors[((pixel & v->red_mask) << (32 - v->red_shift - v->red_prec)) >> 24].red;
	      		rgbbuf[k] = (guchar)(component*fac);

      			component = colormap->colors[((pixel & v->green_mask) << (32 - v->green_shift - v->green_prec)) >> 24].green;
      			rgbbuf[k+1] = (guchar)(component*fac);
      			component = colormap->colors[((pixel & v->blue_mask) << (32 - v->blue_shift - v->blue_prec)) >> 24].blue;
      			rgbbuf[k+2] = (guchar)(component*fac);
      			k += 3;
		}
	       break;
	       default :
	       {
	       		GtkWidget* mess = Message("Unknown visual\n","Error",TRUE);
	    		gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
		        g_free(rgbbuf);
		      	return NULL;
	       }
	}
	return rgbbuf;
}
/********************************************************************************/
static void writePPM(GabeditFileChooser *SelecFile, gint response_id)
{
	gchar *FileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");
	GtkWidget *drawable;
	GtkPlot* plot;

	FILE *file;
	int i;
	int j;
	int k;
	int width;
	int height;
	guchar *rgbbuf;

 	if(response_id != GTK_RESPONSE_OK) return;
 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
	       	GtkWidget* mess = Message("Sorry\n No selected file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
    		return ;
 	}

        file = FOpen(FileName,"wb");

        if (!file)
	{
	       	GtkWidget* mess = Message("Sorry: I can't open output file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
		return;
        }

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();
	Waiting(1.0);

	if(!GTK_IS_PLOT_CANVAS(canvas))
	{
		GtkWidget* mes = Message("Sorry , I can not create the ppm file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
		return;
	}

	activate_plot(canvas,NULL);
	while( gtk_events_pending() ) gtk_main_iteration();

	plot = GTK_PLOT_CANVAS(canvas)->active_plot;
	drawable = GTK_WIDGET(plot);

	rgbbuf = get_rgb_image(canvas);
	if (!rgbbuf) {
		fclose(file);
            return;
	}
	width =  drawable->allocation.width;
	height = drawable->allocation.height;

        fprintf(file,"P6\n");
        fprintf(file,"#Image rendered with gabedit\n");
        fprintf(file,"%d\n%d\n255\n", width,height);

	for(i=height-1; i>= 0; i--){
	   for(j=0; j< width; j++){
		k = 3*(j + i*width);
		fwrite( &rgbbuf[k] ,sizeof(*rgbbuf), 1, file);
		fwrite( &rgbbuf[k+1] ,sizeof(*rgbbuf), 1, file);
		fwrite( &rgbbuf[k+2] ,sizeof(*rgbbuf), 1, file);
	   }
	}

	fclose(file);
	g_free(rgbbuf);
} 
/********************************************************************************/
static void writePPMDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writePPM, "Save spectrum", GABEDIT_TYPEFILE_PPM,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static void WLSBL(int val,char* arr)
{
    arr[0] = (char) (val&0xff);
    arr[1] = (char) ((val>>8) &0xff);
    arr[2] = (char) ((val>>16)&0xff);
    arr[3] = (char) ((val>>24)&0xff);
}
/**************************************************************************/
static void writeBMP(GabeditFileChooser *SelecFile, gint response_id)
{       
  	guchar rgbtmp[3];
  	int pad;
	char bmp_header[]=
	{ 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0,
  	40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0, 0,0,0,0, 0,0,0,0,
  	0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };
	gchar *FileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");
	GtkWidget *drawable;
	GtkPlot* plot;

	FILE *file;
	int i;
	int j;
	int width;
	int height;
	guchar *rgbbuf;

 	if(response_id != GTK_RESPONSE_OK) return;

 	FileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!FileName) || (strcmp(FileName,"") == 0))
 	{
	       	GtkWidget* mess = Message("Sorry\n No selected file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
    		return ;
 	}

        file = FOpen(FileName,"wb");

        if (!file)
	{
	       	GtkWidget* mess = Message("Sorry: I can't open output file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
		return;
        }

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() )
		gtk_main_iteration();
	Waiting(1.0);

	if(!GTK_IS_PLOT_CANVAS(canvas))
	{
		GtkWidget* mes = Message("Sorry , I can not create the BMP file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
		return;
	}

	activate_plot(canvas,NULL);
	while( gtk_events_pending() ) gtk_main_iteration();

	plot = GTK_PLOT_CANVAS(canvas)->active_plot;
	drawable = GTK_WIDGET(plot);

	rgbbuf = get_rgb_image(canvas);
	if (!rgbbuf) {
	    	fclose(file);
            	return;
	}
	width =  drawable->allocation.width;
	height = drawable->allocation.height;


/* The number of bytes on a screenline should be wholly devisible by 4 */

  	pad = (width*3)%4;
  	if (pad) pad = 4 - pad;

  	WLSBL((int) (3*width+pad)*height+54,bmp_header+2);
  	WLSBL((int) width,bmp_header+18);
  	WLSBL((int) height,bmp_header+22);
  	WLSBL((int) 3*width*height,bmp_header+34);

  	fwrite(bmp_header,1,54,file);

  	for (i=0;i<height;i++)
	{
    		for (j=0;j<width;j++)
		{
			rgbtmp[0] = rgbbuf[(j+width*i)*3+2];
			rgbtmp[1] = rgbbuf[(j+width*i)*3+1];
			rgbtmp[2] = rgbbuf[(j+width*i)*3+0];
			fwrite(rgbtmp,3,1,file);
    		}
    	rgbtmp[0] = (char) 0;
    	for (j=0;j<pad;j++) 
		fwrite(rgbtmp,1,1,file);
  	}

  	fclose(file);
  	g_free(rgbbuf);
}
/********************************************************************************/
static void writeBMPDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writeBMP, "Save spectrum", GABEDIT_TYPEFILE_BMP,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/**************************************************************************/
static void writePNG(GabeditFileChooser *SelecFile, gint response_id)
{       
	gchar *fileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");
	GtkWidget *drawable;
	GtkPlot* plot;

 	if(response_id != GTK_RESPONSE_OK) return;

 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
	       	GtkWidget* mess = Message("Sorry\n No selected file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
    		return ;
 	}

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() ) gtk_main_iteration();
	Waiting(1.0);

	if(!GTK_IS_PLOT_CANVAS(canvas))
	{
		GtkWidget* mes = Message("Sorry , I can not create the PNG file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
		return;
	}

	activate_plot(canvas,NULL);
	while( gtk_events_pending() ) gtk_main_iteration();

	plot = GTK_PLOT_CANVAS(canvas)->active_plot;
	drawable = GTK_WIDGET(plot);
	gabedit_save_image(drawable, fileName, "png");
}
/********************************************************************************/
static void writePNGDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writePNG, "Save spectrum", GABEDIT_TYPEFILE_PNG,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/**************************************************************************/
static void writePNGNoBackGround(GabeditFileChooser *SelecFile, gint response_id)
{       
	gchar *fileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");
	GtkWidget *drawable;
	GtkPlot* plot;
	int width;
	int height;
	GError *error = NULL;
	GdkPixbuf  *pixbuf = NULL;

 	if(response_id != GTK_RESPONSE_OK) return;

 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
	       	GtkWidget* mess = Message("Sorry\n No selected file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
    		return ;
 	}

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() ) gtk_main_iteration();
	Waiting(1.0);

	if(!GTK_IS_PLOT_CANVAS(canvas))
	{
		GtkWidget* mes = Message("Sorry , I can not create the PNGNoBackGround file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
		return;
	}

	activate_plot(canvas,NULL);
	while( gtk_events_pending() ) gtk_main_iteration();

	plot = GTK_PLOT_CANVAS(canvas)->active_plot;
	drawable = GTK_WIDGET(plot);


	width =  drawable->allocation.width;
	height = drawable->allocation.height;
	pixbuf = gdk_pixbuf_get_from_drawable(NULL, drawable->window, NULL, 0, 0, 0, 0, width, height);
	if(pixbuf)
	{
		GdkPixbuf  *pixbufNew = NULL;
		guchar color[3] = {255, 255, 255};

		pixbufNew = gdk_pixbuf_add_alpha(pixbuf, TRUE, color[0], color[1], color[2]);
		if(pixbufNew) gdk_pixbuf_save(pixbufNew, fileName, "png", &error, NULL);
		else gdk_pixbuf_save(pixbuf, fileName, "png", &error, NULL);
	 	g_object_unref (pixbuf);
	 	g_object_unref (pixbufNew);
	}
}
/********************************************************************************/
static void writePNGNoBackGroundDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writePNGNoBackGround, "Save spectrum", GABEDIT_TYPEFILE_PNG,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/**************************************************************************/
static void writeJPEG(GabeditFileChooser *SelecFile, gint response_id)
{       
	gchar *fileName;
	GtkWidget* canvas = g_object_get_data (G_OBJECT (SelecFile), "Canvas");
	GtkWidget *drawable;
	GtkPlot* plot;

 	if(response_id != GTK_RESPONSE_OK) return;

 	fileName = gabedit_file_chooser_get_current_file(SelecFile);
 	if ((!fileName) || (strcmp(fileName,"") == 0))
 	{
	       	GtkWidget* mess = Message("Sorry\n No selected file","Error",TRUE);
	    	gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
    		return ;
 	}

	gtk_widget_hide(GTK_WIDGET(SelecFile));
	while( gtk_events_pending() ) gtk_main_iteration();
	Waiting(1.0);

	if(!GTK_IS_PLOT_CANVAS(canvas))
	{
		GtkWidget* mes = Message("Sorry , I can not create the JPEG file","Error", TRUE);
		gtk_window_set_modal (GTK_WINDOW (mes), TRUE);
		return;
	}

	activate_plot(canvas,NULL);
	while( gtk_events_pending() ) gtk_main_iteration();

	plot = GTK_PLOT_CANVAS(canvas)->active_plot;
	drawable = GTK_WIDGET(plot);
	gabedit_save_image(drawable, fileName, "jpeg");
}
/********************************************************************************/
static void writeJPEGDlg(GtkWidget* wid, gpointer data)
{
	GtkWidget* canvas = g_object_get_data (G_OBJECT (data), "Canvas");
	GtkWidget* filesel = file_chooser_save(writeJPEG, "Save spectrum", GABEDIT_TYPEFILE_JPEG,GABEDIT_TYPEWIN_ORB);
	g_object_set_data (G_OBJECT (filesel), "Canvas",canvas);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
}
/********************************************************************************/
static GtkWidget * newLayer(GtkWidget *canvas, DataVibSpec* dataVibSpec)
{
	dataVibSpec->nplots++;

	if(!dataVibSpec->plots )
	dataVibSpec->plots = (GtkWidget **)g_malloc( dataVibSpec->nplots * sizeof(GtkWidget *));
	else
	dataVibSpec->plots = (GtkWidget **)g_realloc(dataVibSpec->plots, dataVibSpec->nplots * sizeof(GtkWidget *));

	dataVibSpec->plots[dataVibSpec->nplots-1] = gtk_plot_new_with_size(NULL, .8, .8);
	gtk_widget_show(dataVibSpec->plots[dataVibSpec->nplots-1]);

	g_object_set_data (G_OBJECT (canvas), "Data",dataVibSpec);
	g_signal_connect_after(G_OBJECT(canvas), "select_item",(GtkSignalFunc) activate_plot, NULL);


	return dataVibSpec->plots[dataVibSpec->nplots-1];
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
/********************************************************************************/
static gdouble getMaxFrequency(DataVibSpec* dataVibSpec)
{
	gdouble maxFrequence = -5000.0;
	gint i;
	for(i=0;i<dataVibSpec->vibration.numberOfFrequences;i++)
	{
		gdouble tmp = dataVibSpec->vibration.modes[i].frequence*dataVibSpec->scaleFrequence;
		if(maxFrequence<tmp) maxFrequence = tmp;
	}
	if(maxFrequence<0) maxFrequence = 5000;
	return maxFrequence;
}
/********************************************************************************/
static void calculSpectrum(DataVibSpec* dataVibSpec, gboolean computeMaxFreq)
{
	gint i, j;
	gdouble intensityIR;
	gdouble intensityRaman;
	gdouble frq, center, rel_offset;
	gdouble (*lineshape)(gdouble);
	gdouble stepFrequence = 1.0;


	if(computeMaxFreq && dataVibSpec->vibration.numberOfFrequences>0)
	{
	           dataVibSpec->maxFrequence = (gint) getMaxFrequency(dataVibSpec);
		   i = dataVibSpec->maxFrequence / 500;
		   dataVibSpec->maxFrequence = (i+1)*500;
	}


	if (dataVibSpec->halfWidth < 0.5) dataVibSpec->halfWidth = 0.5;

	if (dataVibSpec->lorentzian)
		lineshape = lorentzianLineshape;
	else
		lineshape = gaussianLineshape;

	dataVibSpec->numberOfFrequences = 1 + (dataVibSpec->maxFrequence - dataVibSpec->minFrequence)/stepFrequence;

	if(dataVibSpec->outputSpectrumX) g_free(dataVibSpec->outputSpectrumX);
	if(dataVibSpec->outputSpectrumYIR) g_free(dataVibSpec->outputSpectrumYIR);
	if(dataVibSpec->outputSpectrumYRaman) g_free(dataVibSpec->outputSpectrumYRaman);

	dataVibSpec->outputSpectrumX = g_malloc(dataVibSpec->numberOfFrequences*sizeof(gdouble));
	dataVibSpec->outputSpectrumYIR = g_malloc(dataVibSpec->numberOfFrequences*sizeof(gdouble));
	dataVibSpec->outputSpectrumYRaman = g_malloc(dataVibSpec->numberOfFrequences*sizeof(gdouble));

	for (i=0; i < dataVibSpec->numberOfFrequences; i++)
	{
		intensityIR = 0.0;
		intensityRaman = 0.0;
		frq = dataVibSpec->minFrequence + i*stepFrequence;
		for (j=0; j < dataVibSpec->vibration.numberOfFrequences; j++)
		{
			if(dataVibSpec->vibration.modes[j].frequence<0) continue;
			center = (gdouble) dataVibSpec->vibration.modes[j].frequence*dataVibSpec->scaleFrequence;
			rel_offset = (frq - center) / dataVibSpec->halfWidth;
			intensityIR += dataVibSpec->vibration.modes[j].IRIntensity*lineshape(rel_offset);
			intensityRaman += dataVibSpec->vibration.modes[j].RamanIntensity*lineshape(rel_offset);
		}
		dataVibSpec->outputSpectrumYIR[i] = intensityIR;
		dataVibSpec->outputSpectrumYRaman[i] = intensityRaman;
		dataVibSpec->outputSpectrumX[i] = frq;
	}
	computeMaxIntensity(dataVibSpec);
}
/********************************************************************************/
static void buildPlot(GtkWidget *active_plot, DataVibSpec* dataVibSpec)
{
	GdkColor color;
	dataVibSpec->ndataset = 2;
	if(!dataVibSpec->dataset)
	dataVibSpec->dataset = (GtkPlotData **)g_malloc(dataVibSpec->ndataset * sizeof(GtkPlotData *));
	else
	dataVibSpec->dataset = (GtkPlotData **)g_realloc(dataVibSpec->dataset , dataVibSpec->ndataset * sizeof(GtkPlotData *));

	/*if(dataVibSpec->showIR)*/
	{
	/* dataVibSpec->dataset[0] = gtk_plot_data_new(GTK_PLOT(active_plot));*/
	dataVibSpec->dataset[0] = (GtkPlotData*)gtk_plot_data_new();
	gtk_plot_add_data(GTK_PLOT(active_plot), dataVibSpec->dataset[0]);
	gtk_plot_data_set_points(dataVibSpec->dataset[0], dataVibSpec->outputSpectrumX, dataVibSpec->outputSpectrumYIR, NULL, NULL, dataVibSpec->numberOfFrequences);

	gdk_color_parse("red", &color);
	gdk_color_alloc(gdk_colormap_get_system(), &color); 
	gtk_plot_data_set_line_attributes(dataVibSpec->dataset[0], GTK_PLOT_LINE_SOLID, GDK_CAP_BUTT, GDK_JOIN_MITER, 2.0, (const GdkColor*) &color);
	gtk_plot_data_set_legend(dataVibSpec->dataset[0], "Infra Red spectrum");
	}
	/* gtk_plot_hide_legends(GTK_PLOT(active_plot));*/

	
	/*if(dataVibSpec->showRaman)*/
	{
	dataVibSpec->dataset[1] = (GtkPlotData*)gtk_plot_data_new();
	gtk_plot_add_data(GTK_PLOT(active_plot), dataVibSpec->dataset[1]);
	gtk_plot_data_set_points(dataVibSpec->dataset[1], dataVibSpec->outputSpectrumX, dataVibSpec->outputSpectrumYRaman, NULL, NULL, dataVibSpec->numberOfFrequences);
	gdk_color_parse("blue", &color);
	gdk_color_alloc(gdk_colormap_get_system(), &color); 
	gtk_plot_data_set_line_attributes(dataVibSpec->dataset[1], GTK_PLOT_LINE_SOLID, GDK_CAP_BUTT, GDK_JOIN_MITER, 2.0, (const GdkColor*) &color);
	gtk_plot_data_set_legend(dataVibSpec->dataset[1], "Raman spectrum");
	}
	/* gtk_plot_hide_legends(GTK_PLOT(active_plot));*/


}
/********************************************************************************/
static void resetPlot(GtkWidget *active_plot, DataVibSpec* dataVibSpec)
{
	gint nminor = 0;
	gtk_plot_set_range(GTK_PLOT(active_plot), dataVibSpec->minFrequence , dataVibSpec->maxFrequence, dataVibSpec->minIntensity, dataVibSpec->maxIntensity);
	gtk_plot_legends_move(GTK_PLOT(active_plot), .500, .05);

	gtk_plot_axis_hide_title(GTK_PLOT(active_plot), GTK_PLOT_AXIS_TOP);
	gtk_plot_axis_set_title(GTK_PLOT(active_plot),GTK_PLOT_AXIS_BOTTOM,"Frequencies(cm^-1)");
	gtk_plot_axis_set_title(GTK_PLOT(active_plot),GTK_PLOT_AXIS_LEFT,"Intensity");
	gtk_plot_axis_move_title(GTK_PLOT(active_plot), GTK_PLOT_AXIS_LEFT,90, 0.02, 0.5);
	gtk_plot_axis_show_title(GTK_PLOT(active_plot),GTK_PLOT_AXIS_LEFT);
	 gtk_plot_axis_hide_title(GTK_PLOT(active_plot),GTK_PLOT_AXIS_RIGHT);

	nminor =  (gint)(dataVibSpec->xMajorTick/(dataVibSpec->xMinorTick+1+dataVibSpec->xMajorTick*1e-10));
	gtk_plot_axis_set_ticks(GTK_PLOT(active_plot), GTK_PLOT_AXIS_X, dataVibSpec->xMajorTick, nminor);
	nminor =  (gint)(dataVibSpec->yMajorTick/(dataVibSpec->yMinorTick+1+dataVibSpec->yMajorTick*1e-10));
	gtk_plot_axis_set_ticks(GTK_PLOT(active_plot), GTK_PLOT_AXIS_Y, dataVibSpec->yMajorTick, nminor);

	gtk_plot_axis_set_visible(GTK_PLOT(active_plot), GTK_PLOT_AXIS_TOP, TRUE);
	gtk_plot_axis_set_visible(GTK_PLOT(active_plot), GTK_PLOT_AXIS_RIGHT, TRUE);
	gtk_plot_x0_set_visible(GTK_PLOT(active_plot), FALSE);
	gtk_plot_y0_set_visible(GTK_PLOT(active_plot), FALSE);
}
/********************************************************************************/
static GtkWidget *createDialogFrame(GtkWidget *vboxall, GtkWidget *vibSpecDlg, DataVibSpec* dataVibSpec)
{
	GtkWidget *frame;
	gushort j;
	gushort i;
	GtkWidget *vboxframe;
	GtkWidget *Table;
	GtkWidget *buttonIR;
	GtkWidget *buttonRaman;

	GtkWidget *buttonLorentz;
	GtkWidget *buttonGauss;

	GtkWidget *entryHalfWidth;
	GtkWidget *entryScaleFrequence;

	GtkWidget *entryMinFreq;
	GtkWidget *entryMaxFreq;
	
	GtkWidget *buttonBMP;
	GtkWidget *buttonPPM;
	GtkWidget *buttonPNG;
	GtkWidget *buttonPNGNoBackGround;
	GtkWidget *buttonJPEG;

	GtkWidget *buttonPortrait;
	GtkWidget *buttonLandscape;

	GtkWidget *entryMinInt;
	GtkWidget *entryMaxInt;

	GtkWidget *entryYMinorTick;
	GtkWidget *entryYMajorTick;

	GtkWidget *entryXMinorTick;
	GtkWidget *entryXMajorTick;

	GtkWidget *statutX;
	GtkWidget *statutY;

  	frame = gtk_frame_new (NULL);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 5);
        gtk_box_pack_start (GTK_BOX (vboxall), frame, FALSE, FALSE, 0);

	vboxframe = create_vbox(frame);
	Table = gtk_table_new(4,13,FALSE);
	gtk_container_add(GTK_CONTAINER(vboxframe),Table);

	buttonIR = gtk_check_button_new_with_label("Infra Red spectrum" );
	buttonRaman = gtk_check_button_new_with_label("Raman spectrum ");
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonIR), dataVibSpec->showIR);
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonRaman), dataVibSpec->showRaman);

	g_signal_connect (G_OBJECT (buttonIR), "clicked", GTK_SIGNAL_FUNC(resetIR), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonRaman), "clicked", GTK_SIGNAL_FUNC(resetRaman), vibSpecDlg);

	buttonLorentz = gtk_radio_button_new_with_label( NULL,"Lorantzian lineshape" );
	buttonGauss = gtk_radio_button_new_with_label( gtk_radio_button_get_group (GTK_RADIO_BUTTON (buttonLorentz)), "Gaussian lineshape"); 
	gtk_toggle_button_set_active (GTK_TOGGLE_BUTTON (buttonLorentz), dataVibSpec->lorentzian);
	g_signal_connect (G_OBJECT (buttonLorentz), "clicked", GTK_SIGNAL_FUNC(resetLorentzian), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonGauss), "clicked", GTK_SIGNAL_FUNC(resetGauss), vibSpecDlg);

	entryHalfWidth = gtk_entry_new();
	gtk_widget_set_size_request(entryHalfWidth,50,-1);
	entryScaleFrequence = gtk_entry_new();
	gtk_widget_set_size_request(entryScaleFrequence,50,-1);
	entryMinFreq= gtk_entry_new();
	gtk_widget_set_size_request(entryMinFreq,100,-1);
	entryMaxFreq = gtk_entry_new();
	gtk_widget_set_size_request(entryMaxFreq,100,-1);

	entryYMinorTick= gtk_entry_new();
	gtk_widget_set_size_request(entryYMinorTick,100,-1);
	entryYMajorTick = gtk_entry_new();
	gtk_widget_set_size_request(entryYMajorTick,100,-1);

	entryXMinorTick= gtk_entry_new();
	gtk_widget_set_size_request(entryXMinorTick,100,-1);
	entryXMajorTick = gtk_entry_new();
	gtk_widget_set_size_request(entryXMajorTick,100,-1);

	entryMinInt= gtk_entry_new();
	gtk_widget_set_size_request(entryMinInt,100,-1);
	entryMaxInt = gtk_entry_new();
	gtk_widget_set_size_request(entryMaxInt,100,-1);

	statutX = gtk_statusbar_new();;
	statutY = gtk_statusbar_new();;

	buttonBMP = gtk_button_new_with_label ("BMP");
	buttonPPM = gtk_button_new_with_label ("PPM");
	buttonPNG = gtk_button_new_with_label ("PNG");
	buttonPNGNoBackGround = gtk_button_new_with_label ("PNG Transparent");
	buttonJPEG = gtk_button_new_with_label ("JPEG");

	buttonPortrait = gtk_button_new_with_label ("PS(Portrait)");
	buttonLandscape = gtk_button_new_with_label ("PS(Landscape)");

	i=0;
	{
		j=0;
		add_label_table(Table,"Min Frequency",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryMinFreq,i,j);
		j++;
		add_label_table(Table,"Min Intensity",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryMinInt,i,j);
		j++;
		add_label_table(Table,"Half-Width",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryHalfWidth,i,j);
		j++;
		add_widget_table(Table,buttonIR,i,j);
		j++;
		add_widget_table(Table,buttonPortrait,i,j);
		j++;
		add_widget_table(Table,buttonPNG,i,j);
	}
	i=1;
	{
		j=0;
		add_label_table(Table,"Max Frequency",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryMaxFreq,i,j);
		j++;
		add_label_table(Table,"Max Intensity",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryMaxInt,i,j);
		j++;
		add_label_table(Table,"Scale Frequence",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryScaleFrequence,i,j);
		j++;
		add_widget_table(Table,buttonRaman,i,j);
		j++;
		add_widget_table(Table,buttonLandscape,i,j);
		j++;
		add_widget_table(Table,buttonPNGNoBackGround,i,j);
	}
	i=2;
	{
		j=0;
		add_label_table(Table,"X Minor tick",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryXMinorTick,i,j);
		j++;
		add_label_table(Table,"Y Minor tick",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryYMinorTick,i,j);
		j++;
		gtk_table_attach(GTK_TABLE(Table),statutX,j,j+3,i,i+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
                  (GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
                  3,3);
		j+=3;
		add_widget_table(Table,buttonLorentz,i,j);
		j++;
		add_widget_table(Table,buttonBMP,i,j);
		j++;
		add_widget_table(Table,buttonJPEG,i,j);
	}
	i=3;
	{
		j=0;
		add_label_table(Table,"X Major tick",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryXMajorTick,i,j);
		j++;
		add_label_table(Table,"Y Major tick",i,j);
		j++;
		add_label_table(Table,":",i,j);
		j++;
		add_widget_table(Table,entryYMajorTick,i,j);
		j++;
		gtk_table_attach(GTK_TABLE(Table),statutY,j,j+3,i,i+1,
                  (GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
                  (GtkAttachOptions)(GTK_FILL | GTK_SHRINK),
                  3,3);
		j+=3;
		add_widget_table(Table,buttonGauss,i,j);
		j++;
		add_widget_table(Table,buttonPPM,i,j);
	}


	gtk_widget_show_all(frame);

	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryHalfWidth",entryHalfWidth);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryScaleFrequence",entryScaleFrequence);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryMinFreq",entryMinFreq);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryMaxFreq",entryMaxFreq);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryMinInt",entryMinInt);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryMaxInt",entryMaxInt);

	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryXMinorTick",entryXMinorTick);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryXMajorTick",entryXMajorTick);

	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryYMinorTick",entryYMinorTick);
	g_object_set_data (G_OBJECT (vibSpecDlg), "EntryYMajorTick",entryYMajorTick);

	g_object_set_data (G_OBJECT (vibSpecDlg), "StatutX",statutX);
	g_object_set_data (G_OBJECT (vibSpecDlg), "StatutY",statutY);

  	g_signal_connect (G_OBJECT (entryHalfWidth), "activate", (GtkSignalFunc)activateEntryHalfWidth, vibSpecDlg);
  	g_signal_connect (G_OBJECT (entryScaleFrequence), "activate", (GtkSignalFunc)activateEntryScaleFrequence, vibSpecDlg);
  	g_signal_connect (G_OBJECT (entryMinFreq), "activate", (GtkSignalFunc)activateEntryMinFrequence, vibSpecDlg);
  	g_signal_connect (G_OBJECT (entryMaxFreq), "activate", (GtkSignalFunc)activateEntryMaxFrequence, vibSpecDlg);

  	g_signal_connect (G_OBJECT (entryMinInt), "activate", (GtkSignalFunc)activateEntryMinIntensity, vibSpecDlg);
  	g_signal_connect (G_OBJECT (entryMaxInt), "activate", (GtkSignalFunc)activateEntryMaxIntensity, vibSpecDlg);

  	g_signal_connect (G_OBJECT (entryXMinorTick), "activate", (GtkSignalFunc)activateEntryXMinorTick, vibSpecDlg);
  	g_signal_connect (G_OBJECT (entryXMajorTick), "activate", (GtkSignalFunc)activateEntryXMajorTick, vibSpecDlg);

  	g_signal_connect (G_OBJECT (entryYMinorTick), "activate", (GtkSignalFunc)activateEntryYMinorTick, vibSpecDlg);
  	g_signal_connect (G_OBJECT (entryYMajorTick), "activate", (GtkSignalFunc)activateEntryYMajorTick, vibSpecDlg);

	g_signal_connect (G_OBJECT (buttonPortrait), "clicked", GTK_SIGNAL_FUNC(writePortraitDlg), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonLandscape), "clicked", GTK_SIGNAL_FUNC(writeLandscapeDlg), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonBMP), "clicked", GTK_SIGNAL_FUNC(writeBMPDlg), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonPPM), "clicked", GTK_SIGNAL_FUNC(writePPMDlg), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonPNG), "clicked", GTK_SIGNAL_FUNC(writePNGDlg), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonPNGNoBackGround), "clicked", GTK_SIGNAL_FUNC(writePNGNoBackGroundDlg), vibSpecDlg);
	g_signal_connect (G_OBJECT (buttonJPEG), "clicked", GTK_SIGNAL_FUNC(writeJPEGDlg), vibSpecDlg);

	return frame;
}
/********************************************************************************/
void createVibrationSpectrum(GtkWidget *parentWindow, Vibration vibration)
{
	GtkWidget *vibSpecDlg;
	GtkWidget *vbox1;
	GtkWidget *statut;
	GtkWidget *active_plot;
	GtkWidget *canvas;
	gint page_width, page_height;
	gfloat scale = 1.5;
	DataVibSpec* dataVibSpec=NULL;

	if(vibration.numberOfFrequences<1)
	{
		GtkWidget* mess=Message("For draw spectrum,Sorry, Please read a file before","Error",TRUE);
    		gtk_window_set_modal (GTK_WINDOW (mess), TRUE);
		return;
	}

	dataVibSpec=newDataVibSpec(vibration);

	calculSpectrum(dataVibSpec, TRUE);
 
	page_width = GTK_PLOT_LETTER_W * scale;
	page_height = GTK_PLOT_LETTER_H * scale;

	page_width = GTK_PLOT_LETTER_H * scale;
	page_height = GTK_PLOT_LETTER_W * scale;

	page_width = (gint)(ScreenWidth*0.6);
	page_height = (gint)(ScreenHeight*0.5);
 
	vibSpecDlg=gtk_window_new(GTK_WINDOW_TOPLEVEL);

	gtk_window_set_title(GTK_WINDOW(vibSpecDlg),"Virbration Spectrum");
	gtk_window_set_transient_for(GTK_WINDOW(vibSpecDlg),GTK_WINDOW(parentWindow));
    	gtk_window_set_modal (GTK_WINDOW (vibSpecDlg), TRUE);
	gtk_window_set_position(GTK_WINDOW(vibSpecDlg),GTK_WIN_POS_CENTER);

	gtk_widget_realize(vibSpecDlg);
	g_object_set_data (G_OBJECT (vibSpecDlg), "Data",dataVibSpec);
	init_child(vibSpecDlg, destroyAll," Vib. Spec. ");
	g_signal_connect(G_OBJECT(vibSpecDlg),"delete_event",(GtkSignalFunc)destroy_childs,NULL);

	gtk_container_set_border_width (GTK_CONTAINER (vibSpecDlg), 5);


	vbox1=gtk_vbox_new(FALSE,0);
	gtk_container_add(GTK_CONTAINER(vibSpecDlg),vbox1);
	gtk_widget_show(vbox1);

	canvas = gtk_plot_canvas_new(page_width, page_height,1.0);
	GTK_PLOT_CANVAS_SET_FLAGS(canvas, GTK_PLOT_CANVAS_DND_FLAGS);

	gtk_box_pack_start(GTK_BOX(vbox1),canvas, TRUE, TRUE,0);
	gtk_plot_canvas_set_size(GTK_PLOT_CANVAS(canvas), page_width, page_height);

	gtk_widget_show(canvas);

	active_plot = newLayer(canvas, dataVibSpec);
	resetPlot(active_plot, dataVibSpec);

	gtk_plot_canvas_add_plot(GTK_PLOT_CANVAS(canvas), GTK_PLOT(active_plot), .08, .08);
	gtk_plot_reflect_x(GTK_PLOT(active_plot), TRUE);
	gtk_plot_reflect_y(GTK_PLOT(active_plot), TRUE);

	gtk_widget_show(active_plot);

	buildPlot(active_plot, dataVibSpec);

	gtk_widget_show(vibSpecDlg);

	g_object_set_data (G_OBJECT (vibSpecDlg), "Canvas",canvas);
	g_object_set_data (G_OBJECT (vibSpecDlg), "Plot",active_plot);
	createDialogFrame(vbox1, vibSpecDlg, dataVibSpec);
	statut = g_object_get_data (G_OBJECT (vibSpecDlg), "StatutX");
	g_object_set_data (G_OBJECT (canvas), "StatutX",statut);
	statut = g_object_get_data (G_OBJECT (vibSpecDlg), "StatutY");
	g_object_set_data (G_OBJECT (canvas), "StatutY",statut);
	computeMaxIntensity(dataVibSpec);
	refreshPlot(vbox1, vibSpecDlg);
	resetEntrys(vibSpecDlg, NULL);

}


