/* GabeditXYPlot.c */
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
#include <stdio.h>
#include <string.h>
#include <gdk/gdk.h>
#include <gtk/gtk.h>

#include "GabeditXYPlot.h"

#define XYPLOT_DEFAULT_SIZE 300
#define BSIZE 1024

typedef enum
{
  JDX_TYPE_XYDATA,
  JDX_TYPE_XYPOINTS,
  JDX_TYPE_XYTABLE,
  JDX_TYPE_UNKNOWN
} JDXType;

/****************************************************************************************/
static void gabedit_xyplot_class_init (GabeditXYPlotClass    *klass);
static void gabedit_xyplot_init (GabeditXYPlot         *xyplot);
static void gabedit_xyplot_destroy (GtkObject        *object);
static void gabedit_xyplot_realize (GtkWidget        *widget);
static void gabedit_xyplot_size_request (GtkWidget      *widget, GtkRequisition *requisition);
static void gabedit_xyplot_size_allocate (GtkWidget     *widget, GtkAllocation *allocation);
static gint gabedit_xyplot_expose (GtkWidget        *widget, GdkEventExpose   *event);
static gint gabedit_xyplot_button_press (GtkWidget        *widget, GdkEventButton   *event);
static gint gabedit_xyplot_button_release (GtkWidget        *widget, GdkEventButton   *event);
static gint gabedit_xyplot_motion_notify (GtkWidget        *widget, GdkEventMotion   *event);
static gint gabedit_xyplot_scroll (GtkWidget        *widget, GdkEventScroll   *event);
static void gabedit_xyplot_style_set (GtkWidget      *widget, GtkStyle       *previous_style);
static void xyplot_enable_grids (GabeditXYPlot *xyplot, GabeditXYPlotGrid grid, gboolean enable);
static void xyplot_show_left_legends (GabeditXYPlot *xyplot, gboolean show);
static void xyplot_show_right_legends (GabeditXYPlot *xyplot, gboolean show);
static void xyplot_show_top_legends (GabeditXYPlot *xyplot, gboolean show);
static void xyplot_show_bottom_legends (GabeditXYPlot *xyplot, gboolean show);
static void xyplot_reflect_x (GabeditXYPlot *xyplot, gboolean enable);
static void xyplot_reflect_y (GabeditXYPlot *xyplot, gboolean enable);

/****************************************************************************************/
static GtkWidgetClass *parent_class = NULL; /* TO DELETE */
/****************************************************************************************/
static void xyplot_calculate_sizes (GabeditXYPlot *xyplot);
static void value2pixel(GabeditXYPlot *xyplot, gdouble xv, gdouble yv, guint *x, guint *y);
static void pixel2value(GabeditXYPlot *xyplot, guint xp, guint yp, gdouble *x, gdouble *y);
static void xyplot_calculate_legends_sizes(GabeditXYPlot *xyplot);
static void xyplot_build_legends(GabeditXYPlot *xyplot);
static void xyplot_free_legends(GabeditXYPlot *xyplot);
static void xyplot_build_points_data(GabeditXYPlot *xyplot, XYPlotData *data);

/****************************************************************************************/
/*
static void list_utf8()
{
	gchar tmp[10000];
	gchar t[10000];
	GtkWidget* dialog = NULL;
	gint i=32;
	sprintf(tmp,"%d(<span>&#%d;</span>)  ",i,i);
	
	for(i=9600;i<9700;i++)
	{

		sprintf(t,"%s",tmp);
		sprintf(tmp,"%s %d(<span>&#%d;</span>)  ",t,i,i);
	}
	dialog = gtk_message_dialog_new_with_markup (NULL,
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_INFO,
			GTK_BUTTONS_YES_NO,
			tmp
			);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
*/
/****************************************************************************************/
static GtkWidget* get_parent_window(GtkWidget* widget)
{
	GtkWidget* parent = NULL;
	GtkWidget* child = widget;
	do
	{
		parent = gtk_widget_get_parent(child);
		child = parent;
	}
	while( parent && !GTK_IS_WINDOW(parent));
	return parent;
}
/****************************************************************************************/
static void destroy_xyplot_window(GtkWidget* xyplot)
{
	GtkWidget* parentWindow;
	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow) gtk_object_destroy (GTK_OBJECT(parentWindow));
}
/****************************************************************************************/
static void destroy_data_dialog(GtkWidget* win, GdkEvent  *event, gpointer user_data)
{
  	gtk_object_destroy (GTK_OBJECT(win));
}
/********************************************************************************/
static gboolean remove_all_data(GtkWidget* xyplot, gint response_id)
{
	if(response_id != GTK_RESPONSE_YES) return FALSE;
	if(!xyplot) return FALSE; 
	if(GABEDIT_XYPLOT(xyplot)->data_list)
	{
		g_list_foreach(GABEDIT_XYPLOT(xyplot)->data_list, (GFunc)g_free, NULL);
		g_list_free(GABEDIT_XYPLOT(xyplot)->data_list);
		GABEDIT_XYPLOT(xyplot)->data_list = NULL;
	}
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	return TRUE;
}
/********************************************************************************/
static void remove_all_data_dlg(GtkWidget* xyplot)
{
	GtkWidget* parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
		       "Are you sure to remove all data ?"
			);
	gtk_dialog_set_default_response (GTK_DIALOG (dialog), GTK_RESPONSE_NO);
	g_signal_connect_swapped(dialog, "response", G_CALLBACK (remove_all_data), xyplot);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
/*****************************************************************************************/
static void file_chooser_set_filters(GtkFileChooser *fileChooser,gchar **patterns)
{
	GtkFileFilter *filter;
	GtkFileFilter *filter0 = NULL;
	gint n = 0;

	g_return_if_fail (fileChooser != NULL);
	g_return_if_fail (GTK_IS_FILE_CHOOSER(fileChooser));
	g_return_if_fail (patterns != NULL);
	while(patterns[n])
	{
		filter = gtk_file_filter_new ();
		gtk_file_filter_set_name (filter, patterns[n]);
		gtk_file_filter_add_pattern (filter, patterns[n]);
		gtk_file_chooser_add_filter (GTK_FILE_CHOOSER (fileChooser), filter);
		if(n==0) filter0 = filter;
		n++;
	}
	if(filter0)gtk_file_chooser_set_filter (GTK_FILE_CHOOSER (fileChooser), filter0);
}
/********************************************************************************/
static GtkWidget* new_file_chooser_open(GtkWidget* parentWindow, GtkSignalFunc *func, gchar* title, gchar** patternsfiles)
{
	GtkWidget* filesel = NULL;
	filesel = g_object_new (GTK_TYPE_FILE_CHOOSER_DIALOG, "action", GTK_FILE_CHOOSER_ACTION_OPEN, "file-system-backend", "gtk+", "select-multiple", FALSE, NULL);
	gtk_window_set_title (GTK_WINDOW (filesel), title);
	gtk_dialog_add_buttons (GTK_DIALOG (filesel), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_OPEN, GTK_RESPONSE_OK, NULL);
	gtk_dialog_set_default_response (GTK_DIALOG (filesel), GTK_RESPONSE_OK);

	if(parentWindow) gtk_window_set_transient_for(GTK_WINDOW(filesel),GTK_WINDOW(parentWindow));

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_signal_connect (filesel, "response",  G_CALLBACK (func),GTK_OBJECT(filesel));
	g_signal_connect_after (filesel, "response", G_CALLBACK (gtk_widget_destroy),GTK_OBJECT(filesel));
	file_chooser_set_filters(GTK_FILE_CHOOSER(filesel),patternsfiles);
	gtk_widget_show(filesel);
	return filesel;
}
/********************************************************************************/
static GtkWidget* new_file_chooser_save(GtkWidget* parentWindow, GtkSignalFunc *func, gchar* title, gchar** patternsfiles)
{
	GtkWidget* filesel = NULL;
	filesel = g_object_new (GTK_TYPE_FILE_CHOOSER_DIALOG, "action", GTK_FILE_CHOOSER_ACTION_SAVE, "file-system-backend", "gtk+", "select-multiple", FALSE, NULL);
	gtk_window_set_title (GTK_WINDOW (filesel), title);
	gtk_dialog_add_buttons (GTK_DIALOG (filesel), GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL, GTK_STOCK_SAVE, GTK_RESPONSE_OK, NULL);
	gtk_dialog_set_default_response (GTK_DIALOG (filesel), GTK_RESPONSE_OK);

	if(parentWindow) gtk_window_set_transient_for(GTK_WINDOW(filesel),GTK_WINDOW(parentWindow));

	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_signal_connect (filesel, "response",  G_CALLBACK (func),GTK_OBJECT(filesel));
	g_signal_connect_after (filesel, "response", G_CALLBACK (gtk_widget_destroy),GTK_OBJECT(filesel));
	file_chooser_set_filters(GTK_FILE_CHOOSER(filesel),patternsfiles);
	gtk_widget_show(filesel);
	return filesel;
}
/********************************************************************************/
static void add_new_data(GtkWidget* xyplot, gint numberOfPoints, gdouble* X,  gdouble* Y)
{
	if(numberOfPoints>0)
	{
		gint loop;
		XYPlotData *data = g_malloc(sizeof(XYPlotData));
		guint red = rand()%60000;
		guint green = rand()%60000;
		guint blue = rand()%60000;
		data->size=numberOfPoints;
		data->x = g_malloc(numberOfPoints*sizeof(gdouble)); 
		data->y = g_malloc(numberOfPoints*sizeof(gdouble)); 
		for(loop = 0; loop<data->size;loop++)
		{
			data->x[loop] = X[loop];
			data->y[loop] = Y[loop];
		}

		sprintf(data->point_str,"+");
		data->point_pango = NULL;
		xyplot_build_points_data(GABEDIT_XYPLOT(xyplot), data);

		data->point_size=0;
		data->line_width=1;
		data->point_color.red=red; 
		data->point_color.green=green; 
		data->point_color.blue=blue; 

		data->line_color.red=green;
		data->line_color.green=red;
		data->line_color.blue=blue;
		data->line_style=GDK_LINE_SOLID;
		gabedit_xyplot_add_data (GABEDIT_XYPLOT(xyplot), data);
		gabedit_xyplot_set_autorange(GABEDIT_XYPLOT(xyplot), NULL);
	}
}
/********************************************************************************/
static gchar** my_strsplit(gchar *str)
{
	gchar** strsplit= g_malloc(sizeof(gchar*));
	gint n=0;
	gchar* t=str;
	gchar p[BSIZE];
	while(*t!='\n' && *t !='\0')
	{
		if(*t!=' ')
		{
			n++;
			strsplit= g_realloc(strsplit,(n+1)*sizeof(gchar*));
			sscanf(t,"%s",p);
			strsplit[n-1]= g_strdup(p);
			while(*t!=' ')
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}

		}
		else
		{
			while(*t ==' ' )
			{
				t++;
				if(*t =='\n' || *t =='\0')
					break;
			}
		}
	}
	strsplit[n]= NULL;
	return strsplit;
}
/********************************************************************************/
static gboolean read_data_xy1yncolumns(GtkFileChooser *filesel, gint response_id)
{
	gchar *fileName;
 	gchar t[BSIZE];
 	FILE *fd;
	GtkWidget* xyplot = NULL;
	gchar** strsplit;
	gchar* str = NULL;
	gint* numberOfPoints = NULL;
	gdouble** X = NULL;
	gdouble** Y = NULL;
	gint nmax = 0;
	gint i;
	gint k;
	gdouble x=0;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	fileName = gtk_file_chooser_get_filename(filesel);
	xyplot = g_object_get_data(G_OBJECT (filesel), "XYPLOT");

 	fd = fopen(fileName, "rb");

    	if(fgets(t,BSIZE,fd) && strcmp(t,"\n"))
	{
		for(i=0;i<strlen(t);i++)
		{
			if(t[i]==',')t[i]=' ';
			if(t[i]=='\t')t[i]=' ';
		}
		strsplit = my_strsplit(t);
		while(strsplit && strsplit[nmax]) nmax++;
		nmax--;
		if(nmax>0)
		{
			Y = g_malloc(nmax*sizeof(gdouble*));
			X = g_malloc(nmax*sizeof(gdouble*));
			numberOfPoints = g_malloc(nmax*sizeof(gint));
			for(k=0;k<nmax;k++)
			{
				numberOfPoints[k] = 1;
				X[k] = g_malloc(1*sizeof(gdouble));
				X[k][0] = atof(strsplit[0]);
				Y[k] = g_malloc(1*sizeof(gdouble));
				Y[k][0] = atof(strsplit[k+1]);
			}
		}
		if(strsplit) g_strfreev(strsplit);
	}
  	while(nmax>0 && !feof(fd))
  	{
    		if(!fgets(t,BSIZE,fd)) break;
		if(!strcmp(t,"\n")) break;
		for(i=0;i<strlen(t);i++)
		{
			if(t[i]==',')t[i]=' ';
			if(t[i]=='\t')t[i]=' ';
		}
		strsplit = my_strsplit(t);
		if(!strsplit) break;
		if(!strsplit[0]) break;
		if(!strsplit[1]) break;
		i = 0;
		do{
			str=strsplit[i];
			if(!str) break;
			i++;
			if(i==1) {
				x = atof(str);
				continue;
			}
			k = i-2;
			if(k>=nmax) break;
			numberOfPoints[k]++;
			X[k] = g_realloc(X[k], numberOfPoints[k]*sizeof(gdouble));
			Y[k] = g_realloc(Y[k], numberOfPoints[k]*sizeof(gdouble));
			X[k][numberOfPoints[k]-1] = x;
			Y[k][numberOfPoints[k]-1] = atof(str);
		}while(str!=NULL);

		g_strfreev(strsplit);
	}
	if(nmax>0)
	{
		for(k=0;k<nmax;k++)
		{
			if(numberOfPoints[k]>0 && X[k] && Y[k])
			{
				add_new_data(xyplot, numberOfPoints[k], X[k],  Y[k]);
			}
			if(X[k]) g_free(X[k]);
			if(Y[k]) g_free(Y[k]);
		}
	}
	else
	{
		GtkWidget* parentWidget = get_parent_window(GTK_WIDGET(xyplot));
		GtkWindow* parentWindow = NULL;
		if(parentWidget) parentWindow = GTK_WINDOW(parentWidget);
		GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE,
			       "Error reading file '%s'",
				fileName);
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	}

	if(numberOfPoints) g_free(numberOfPoints);
	if(X) g_free(X);
	if(Y) g_free(Y);
	fclose(fd);
	return TRUE;

}
/********************************************************************************/
static void read_data_xy1yncolumns_dlg(GtkWidget* xyplot)
{
	GtkWidget* parentWindow = NULL;
	gchar* patternsfiles[] = {"*.txt","*",NULL}; 
	GtkWidget* filesel= NULL;

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	filesel= new_file_chooser_open(parentWindow, 
			(GtkSignalFunc *)read_data_xy1yncolumns, 
			"Read data from an ASCII X.Y1..Yn file(x, y1, y2,...,yn)", 
			patternsfiles);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_object_set_data(G_OBJECT (filesel), "XYPLOT", xyplot);
}
/********************************************************************************/
static gboolean this_is_a_backspace(gchar *st)
{
        gint i;
        for(i=0;i<(gint)strlen(st);i++)
        	if(st[i] != ' ' && st[i] !='\n' && st[i] !='\r')
                	return FALSE;
        return TRUE;
}   
/********************************************************************************/
static gboolean read_data_2columns(GtkFileChooser *filesel, gint response_id)
{
	gchar *fileName;
 	gchar t[BSIZE];
 	gboolean OK;
 	FILE *fd;
	gint ne;
	gint numberOfPoints = 0;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gdouble a;
	gdouble b;
	GtkWidget* xyplot = NULL;
	gint nData= 0;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	fileName = gtk_file_chooser_get_filename(filesel);
	xyplot = g_object_get_data(G_OBJECT (filesel), "XYPLOT");

 	fd = fopen(fileName, "rb");
 	OK=FALSE;

  	while(!feof(fd))
  	{
    		if(!fgets(t,BSIZE,fd)) break;
		if(this_is_a_backspace(t))
		{
			if(numberOfPoints==0) continue;
			add_new_data(xyplot, numberOfPoints, X,  Y);
			numberOfPoints = 0;
			if(X) g_free(X);
			if(Y) g_free(Y);
			X = NULL;
			Y = NULL;
			nData ++;
		}
		ne = sscanf(t,"%lf %lf",&a, &b);
		if(ne==2)
		{
			numberOfPoints++;
			X = g_realloc(X, numberOfPoints*sizeof(gdouble));
			Y = g_realloc(Y, numberOfPoints*sizeof(gdouble));
			X[numberOfPoints-1] = a;
			Y[numberOfPoints-1] = b;
		}
	}
	if(numberOfPoints>0)
	{
		add_new_data(xyplot, numberOfPoints, X,  Y);
	}
	else if(nData == 0)
	{
		GtkWidget* parentWidget = get_parent_window(GTK_WIDGET(xyplot));
		GtkWindow* parentWindow = NULL;
		if(parentWidget) parentWindow = GTK_WINDOW(parentWidget);
		GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE,
			       "Error reading file '%s'",
				fileName);
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	}

	if(X) g_free(X);
	if(Y) g_free(Y);
	fclose(fd);
	return TRUE;

}
/********************************************************************************/
static void read_data_2columns_dlg(GtkWidget* xyplot)
{
	GtkWidget* parentWindow = NULL;
	gchar* patternsfiles[] = {"*.txt","*",NULL}; 
	GtkWidget* filesel= NULL;

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	filesel= new_file_chooser_open(parentWindow, 
			(GtkSignalFunc *)read_data_2columns, 
			"Read data from an ASCII XY file(2 columns)", 
			patternsfiles);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_object_set_data(G_OBJECT (filesel), "XYPLOT", xyplot);
}
/********************************************************************************/
static gboolean save_data_2columns(GtkFileChooser *filesel, gint response_id)
{
	gchar *fileName;
 	FILE *file;
	XYPlotData* data = NULL;
	gint loop;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	fileName = gtk_file_chooser_get_filename(filesel);
	data = g_object_get_data(G_OBJECT (filesel), "CurentData");
	if(!data) return FALSE;

 	file = fopen(fileName, "w");

	for(loop=0;loop<data->size; loop++)
	{
		fprintf(file, "%f %f\n",data->x[loop], data->y[loop]);
	}
	fclose(file);
	return TRUE;

}
/********************************************************************************/
static gboolean save_all_data_2columns(GtkFileChooser *filesel, gint response_id)
{
	gchar *fileName;
 	FILE *file;
	XYPlotData* data = NULL;
	gint loop;
	GList *current = NULL;
	GList *data_list = NULL;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	fileName = gtk_file_chooser_get_filename(filesel);

	data_list = g_object_get_data(G_OBJECT (filesel), "DataList");


 	file = fopen(fileName, "w");

	if(data_list)
	for(current=g_list_first(data_list); current!=NULL; current=current->next)
	{
		data=(XYPlotData*)current->data;
		if(!data) continue;
		for(loop=0;loop<data->size; loop++)
			fprintf(file, "%f %f\n",data->x[loop], data->y[loop]);
		fprintf(file, "\n");
  	}
	fclose(file);
	return TRUE;

}
/********************************************************************************/
static gint get_data_jdx_type(FILE* fd, gdouble* scaleX, gdouble* scaleY, gdouble* deltaX)
{
 	gchar t[BSIZE];
	*scaleX = 1;
	*scaleY = 1;
	*deltaX = 0;
  	while(!feof(fd))
  	{
    		if(!fgets(t,BSIZE,fd)) break;
		if(strstr(t,"##XFACTOR="))
		{
			gchar* e = strstr(t,"=")+1;
			if(e) *scaleX = atof(e);
		}
		if(strstr(t,"##YFACTOR="))
		{
			gchar* e = strstr(t,"=")+1;
			if(e) *scaleY = atof(e);
		}
		if(strstr(t,"##DELTAX="))
		{
			gchar* e = strstr(t,"=")+1;
			if(e) *deltaX = atof(e);
		}
		if(strstr(t,"##XYDATA="))
		{
			return JDX_TYPE_XYDATA;
		}
		if(strstr(t,"##XYPOINTS="))
		{
			return JDX_TYPE_XYPOINTS;
		}
		if(strstr(t,"##PEAK TABLE=") || strstr(t,"##PEAKTABLE="))
		{
			return JDX_TYPE_XYTABLE;
		}
	}
	return JDX_TYPE_UNKNOWN;

}
/********************************************************************************/
static gboolean read_data_jdx_xypoints(FILE* fd, GtkWidget*xyplot, gdouble scaleX, gdouble scaleY, gchar* fileName )
{
 	gchar t[BSIZE];
	gint numberOfPoints = 0;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gchar** strsplit;
	gchar* str1 = NULL;
	gchar* str2 = NULL;
	gint i;

  	while(!feof(fd))
  	{
    		if(!fgets(t,BSIZE,fd)) break;
		if(!strcmp(t,"\n")) break;
		if(strstr(t,"##END")) break;
		for(i=0;i<strlen(t);i++)
		{
			if(t[i]==',')t[i]=' ';
			if(t[i]=='\t')t[i]=' ';
		}
		strsplit = my_strsplit(t);
		if(!strsplit) break;
		if(!strsplit[0]) break;
		if(!strsplit[1]) break;
		i = 0;
		do{
			str1=strsplit[i];
			if(!str1) break;
			str2=strsplit[i+1];
			if(!str2) break;
			i++;
			numberOfPoints++;
			X = g_realloc(X, numberOfPoints*sizeof(gdouble));
			Y = g_realloc(Y, numberOfPoints*sizeof(gdouble));
			X[numberOfPoints-1] = atof(str1)*scaleX;
			Y[numberOfPoints-1] = atof(str2)*scaleY;
		}while(str2!=NULL);

		g_strfreev(strsplit);
	}
	if(numberOfPoints>0)
	{
		add_new_data(xyplot, numberOfPoints, X,  Y);
	}
	else
	{
		GtkWidget* parentWidget = get_parent_window(GTK_WIDGET(xyplot));
		GtkWindow* parentWindow = NULL;
		if(parentWidget) parentWindow = GTK_WINDOW(parentWidget);
		GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE,
			       "Error reading file '%s'",
				fileName);
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	}

	if(X) g_free(X);
	if(Y) g_free(Y);
	return TRUE;

}
/********************************************************************************/
static gboolean read_data_jdx_xydata(FILE* fd, GtkWidget*xyplot , gdouble scaleX, gdouble scaleY, gdouble deltaX , gchar* fileName)
{
 	gchar t[BSIZE];
	gint numberOfPoints = 0;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gchar** strsplit;
	gchar* str = NULL;
	gdouble x=0;
	gint i;

  	while(!feof(fd))
  	{
    		if(!fgets(t,BSIZE,fd)) break;
		if(!strcmp(t,"\n")) break;
		if(strstr(t,"##END")) break;
		for(i=0;i<strlen(t);i++)
		{
			if(t[i]==',')t[i]=' ';
			if(t[i]=='\t')t[i]=' ';
		}
		strsplit = my_strsplit(t);
		if(!strsplit) break;
		if(!strsplit[0]) break;
		if(!strsplit[1]) break;
		i = 0;
		do{
			str=strsplit[i];
			if(!str) break;
			i++;
			if(i==1) {
				x = atof(str);
				continue;
			}
			if(i>2) x += deltaX;
			numberOfPoints++;
			X = g_realloc(X, numberOfPoints*sizeof(gdouble));
			Y = g_realloc(Y, numberOfPoints*sizeof(gdouble));
			X[numberOfPoints-1] = x*scaleX;
			Y[numberOfPoints-1] = atof(str)*scaleY;
		}while(str!=NULL);

		g_strfreev(strsplit);
	}
	if(numberOfPoints>0)
	{
		add_new_data(xyplot, numberOfPoints, X,  Y);
	}
	else
	{
		GtkWidget* parentWidget = get_parent_window(GTK_WIDGET(xyplot));
		GtkWindow* parentWindow = NULL;
		if(parentWidget) parentWindow = GTK_WINDOW(parentWidget);
		GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE,
			       "Error reading file '%s'",
				fileName);
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	}

	if(X) g_free(X);
	if(Y) g_free(Y);
	return TRUE;

}
/********************************************************************************/
static gboolean read_data_jdx_xytable(FILE* fd, GtkWidget*xyplot , gdouble scaleX, gdouble scaleY, gchar* fileName)
{
 	gchar t[BSIZE];
	gint numberOfPoints = 0;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gchar** strsplit;
	gchar* str = NULL;
	gdouble x=0;
	gint i;

  	while(!feof(fd))
  	{
    		if(!fgets(t,BSIZE,fd)) break;
		if(!strcmp(t,"\n")) break;
		if(strstr(t,"##END")) break;
		for(i=0;i<strlen(t);i++)
		{
			if(t[i]==',')t[i]=' ';
			if(t[i]=='\t')t[i]=' ';
		}
		strsplit = my_strsplit(t);
		if(!strsplit) break;
		if(!strsplit[0]) break;
		if(!strsplit[1]) break;
		i = 0;
		do{
			str=strsplit[i];
			if(!str) break;
			i++;
			if(i%2==1) x = atof(str);
			else 
			{
				gint i0  = numberOfPoints;
				numberOfPoints += 3;
				X = g_realloc(X, numberOfPoints*sizeof(gdouble));
				Y = g_realloc(Y, numberOfPoints*sizeof(gdouble));
				X[i0] = x*scaleX;
				Y[i0] = 0;
				X[i0+1] = x*scaleX;
				Y[i0+1] = atof(str)*scaleY;
				X[i0+2] = x*scaleX;
				Y[i0+2] = 0;
			}
		}while(str!=NULL);

		g_strfreev(strsplit);
	}
	if(numberOfPoints>0)
	{
		add_new_data(xyplot, numberOfPoints, X,  Y);
	}
	else
	{
		GtkWidget* parentWidget = get_parent_window(GTK_WIDGET(xyplot));
		GtkWindow* parentWindow = NULL;
		if(parentWidget) parentWindow = GTK_WINDOW(parentWidget);
		GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE,
			       "Error reading file '%s'",
				fileName);
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	}

	if(X) g_free(X);
	if(Y) g_free(Y);
	return TRUE;

}
/********************************************************************************/
static gboolean read_data_jdx(GtkFileChooser *filesel, gint response_id)
{
	gchar *fileName;
 	FILE *fd;
	GtkWidget* xyplot = NULL;
	gint type = 0;
	gdouble scaleX;
	gdouble scaleY;
	gdouble deltaX;

	if(response_id != GTK_RESPONSE_OK) return FALSE;
 	fileName = gtk_file_chooser_get_filename(filesel);
	xyplot = g_object_get_data(G_OBJECT (filesel), "XYPLOT");

 	fd = fopen(fileName, "rb");
	type = get_data_jdx_type(fd, &scaleX, &scaleY, &deltaX);
	if(type==JDX_TYPE_XYPOINTS) read_data_jdx_xypoints(fd, xyplot, scaleX, scaleY, fileName);
	if(type==JDX_TYPE_XYDATA) read_data_jdx_xydata(fd,xyplot, scaleX, scaleY,deltaX, fileName);
	if(type==JDX_TYPE_XYTABLE) read_data_jdx_xytable(fd,xyplot, scaleX, scaleY, fileName);
	if(type==JDX_TYPE_UNKNOWN)
	{
		GtkWidget* parentWidget = get_parent_window(GTK_WIDGET(xyplot));
		GtkWindow* parentWindow = NULL;
		if(parentWidget) parentWindow = GTK_WINDOW(parentWidget);
		GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
				GTK_DIALOG_DESTROY_WITH_PARENT,
				GTK_MESSAGE_ERROR,
				GTK_BUTTONS_CLOSE,
			       "Error reading file '%s', The type of data in this file is unknown",
				fileName);
		gtk_dialog_run (GTK_DIALOG (dialog));
		gtk_widget_destroy (dialog);
	}
	fclose(fd);
	return TRUE;

}
/********************************************************************************/
static void read_data_jdx_dlg(GtkWidget* xyplot)
{
	GtkWidget* parentWindow = NULL;
	gchar* patternsfiles[] = {"*.jdx","*",NULL}; 
	GtkWidget* filesel= NULL;

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	filesel= new_file_chooser_open(parentWindow, 
			(GtkSignalFunc *)read_data_jdx, 
			"Read data from a jdx file", 
			patternsfiles);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_object_set_data(G_OBJECT (filesel), "XYPLOT", xyplot);
}
/********************************************************************************/
static void auto_range_activate(GtkWidget* buttonAutoRange, GtkWidget* xyplot)
{
	XYPlotData* data = NULL;
	data = g_object_get_data(G_OBJECT (buttonAutoRange), "CurentData");
	if(xyplot) gabedit_xyplot_set_autorange(GABEDIT_XYPLOT(xyplot), data);
}
/********************************************************************************/
static void save_data_2columns_dlg(GtkWidget* buttonSave, GtkWidget* xyplot)
{
	GtkWidget* parentWindow = NULL;
	gchar* patternsfiles[] = {"*.txt","*",NULL}; 
	GtkWidget* filesel= NULL;
	gchar* tmp = NULL;
	gpointer* data = NULL;

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	filesel= new_file_chooser_save(parentWindow, 
			(GtkSignalFunc *)save_data_2columns, 
			"Save data in an ASCII XY file(2 columns)", 
			patternsfiles);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	data = g_object_get_data(G_OBJECT (buttonSave), "CurentData");
	g_object_set_data(G_OBJECT (filesel), "CurentData", data);
	tmp = g_strdup_printf("%s%s%s",g_get_current_dir(),G_DIR_SEPARATOR_S,"xyplotData.txt");
	gtk_file_chooser_set_filename ((GtkFileChooser *)filesel, tmp);
	if(tmp) g_free(tmp);
	gtk_file_chooser_set_current_name ((GtkFileChooser *)filesel, "xyplotData.txt");
}
/********************************************************************************/
static void save_all_data_2columns_dlg(GtkWidget* xyplot)
{
	GtkWidget* parentWindow = NULL;
	gchar* patternsfiles[] = {"*.txt","*",NULL}; 
	GtkWidget* filesel= NULL;
	gchar* tmp = NULL;

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	filesel= new_file_chooser_save(parentWindow, 
			(GtkSignalFunc *)save_all_data_2columns, 
			"Save all data in an ASCII XY file(2 columns)", 
			patternsfiles);
	gtk_window_set_modal (GTK_WINDOW (filesel), TRUE);
	g_object_set_data(G_OBJECT (filesel), "DataList", GABEDIT_XYPLOT(xyplot)->data_list);
	tmp = g_strdup_printf("%s%s%s",g_get_current_dir(),G_DIR_SEPARATOR_S,"xyplotData.txt");
	gtk_file_chooser_set_filename ((GtkFileChooser *)filesel, tmp);
	if(tmp) g_free(tmp);
	gtk_file_chooser_set_current_name ((GtkFileChooser *)filesel, "xyplotData.txt");
}
/********************************************************************************/
static gboolean remove_data(GtkWidget* buttonRemove, gint response_id)
{
	XYPlotData* data = NULL;
	GtkWidget*window = NULL;
	GtkWidget*xyplot = NULL;

	if(response_id != GTK_RESPONSE_YES) return FALSE;
	data = g_object_get_data(G_OBJECT (buttonRemove), "CurentData");
	window = g_object_get_data(G_OBJECT (buttonRemove), "Window");
	xyplot = g_object_get_data(G_OBJECT (buttonRemove), "XYPLOT");
	if(xyplot && data) 
	{
		gabedit_xyplot_remove_data(GABEDIT_XYPLOT(xyplot), data);
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
	if(window) gtk_widget_destroy(window);
	return TRUE;
}
/********************************************************************************/
static void remove_data_dlg(GtkWidget* buttonRemove, GtkWidget* xyplot)
{
	GtkWidget* parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	GtkWidget* dialog = gtk_message_dialog_new (GTK_WINDOW(parentWindow),
			GTK_DIALOG_DESTROY_WITH_PARENT,
			GTK_MESSAGE_QUESTION,
			GTK_BUTTONS_YES_NO,
		       "Are you sure to delete this data ?"
			);
	gtk_dialog_set_default_response (GTK_DIALOG (dialog), GTK_RESPONSE_NO);
	g_signal_connect_swapped(dialog, "response", G_CALLBACK (remove_data), buttonRemove);
	gtk_dialog_run (GTK_DIALOG (dialog));
	gtk_widget_destroy (dialog);
}
/****************************************************************************************/
static void spin_font_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		gint fontSize = gtk_spin_button_get_value(spinbutton);
		gchar tmp[100];
		sprintf(tmp,"sans %d",fontSize);
		gabedit_xyplot_set_font (GABEDIT_XYPLOT(xyplot), tmp);
	}
}
/****************************************************************************************/
static void set_font_size_dialog(GtkWidget* xyplot)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* frame = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* hbox_frame = NULL;
	GtkWidget* label = NULL;
	GtkWidget* spin_font_size = NULL;
	GtkWidget* parentWindow = NULL;

	gtk_window_set_title (GTK_WINDOW (window), "Set font size");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_modal (GTK_WINDOW (window), TRUE);

	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_widget_destroy), (gpointer)xyplot);
	
	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_widget_show(hbox);

	frame=gtk_frame_new("Set font size");
	gtk_container_add(GTK_CONTAINER(hbox), frame);
	gtk_widget_show(frame);

	hbox_frame=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox_frame);
	gtk_widget_show(hbox_frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox_frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new(" ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin_font_size=gtk_spin_button_new_with_range(8, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), spin_font_size, TRUE, FALSE, 2);
	gtk_widget_show(spin_font_size);

	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_font_size), GABEDIT_XYPLOT(xyplot)->font_size);

	gtk_widget_show(window); 

	g_signal_connect(G_OBJECT(spin_font_size), "value-changed", G_CALLBACK(spin_font_changed_value), xyplot);

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow)
	{
		gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parentWindow));
	}
}
/****************************************************************************************/
static void spin_x_digits_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		gabedit_xyplot_set_x_legends_digits(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));
	}
}
/****************************************************************************************/
static void spin_y_digits_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		gabedit_xyplot_set_y_legends_digits(GABEDIT_XYPLOT(xyplot), gtk_spin_button_get_value(spinbutton));
	}
}
/****************************************************************************************/
static void set_digits_dialog(GtkWidget* xyplot)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* frame = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* hbox_frame = NULL;
	GtkWidget* label = NULL;
	GtkWidget* x_spin_digits = NULL;
	GtkWidget* y_spin_digits = NULL;
	GtkWidget* parentWindow = NULL;

	gtk_window_set_title (GTK_WINDOW (window), "Set digits");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_modal (GTK_WINDOW (window), TRUE);

	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_widget_destroy), (gpointer)xyplot);
	
	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_widget_show(hbox);

	frame=gtk_frame_new("Set digits");
	gtk_container_add(GTK_CONTAINER(hbox), frame);
	gtk_widget_show(frame);

	hbox_frame=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox_frame);
	gtk_widget_show(hbox_frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox_frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new(" X ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	x_spin_digits=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), x_spin_digits, TRUE, FALSE, 2);
	gtk_widget_show(x_spin_digits);

	label=gtk_label_new(" Y ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	y_spin_digits=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), y_spin_digits, TRUE, FALSE, 2);
	gtk_widget_show(y_spin_digits);


	gtk_spin_button_set_value(GTK_SPIN_BUTTON(x_spin_digits), GABEDIT_XYPLOT(xyplot)->x_legends_digits);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(y_spin_digits), GABEDIT_XYPLOT(xyplot)->y_legends_digits);

	gtk_widget_show(window); 

	g_signal_connect(G_OBJECT(x_spin_digits), "value-changed", G_CALLBACK(spin_x_digits_changed_value), xyplot);
	g_signal_connect(G_OBJECT(y_spin_digits), "value-changed", G_CALLBACK(spin_y_digits_changed_value), xyplot);

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow)
	{
		gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parentWindow));
	}
}
/********************************************************************************/
static void activate_entry_xlabel(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	GtkWidget* xyplot = NULL;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	gabedit_xyplot_set_x_label (GABEDIT_XYPLOT(xyplot), t);
}
/********************************************************************************/
static void activate_entry_ylabel(GtkWidget *entry, gpointer user_data)
{
	G_CONST_RETURN gchar* t;
	GtkWidget* xyplot = NULL;


	if(!user_data || !G_IS_OBJECT(user_data)) return;

	xyplot = GTK_WIDGET(user_data);
	t= gtk_entry_get_text(GTK_ENTRY(entry));
	gabedit_xyplot_set_y_label (GABEDIT_XYPLOT(xyplot), t);
}
/****************************************************************************************/
static void set_labels_dialog(GtkWidget* xyplot)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* parentWindow = NULL;
	GtkWidget* frame = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* hbox_frame = NULL;
	GtkWidget* label = NULL;
	GtkWidget* entry_x_label = NULL;
	GtkWidget* entry_y_label = NULL;

	gtk_window_set_title (GTK_WINDOW (window), "Set labels");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_modal (GTK_WINDOW (window), TRUE);

	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_widget_destroy), (gpointer)xyplot);
	
	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_widget_show(hbox);

	frame=gtk_frame_new("Set labels");
	gtk_container_add(GTK_CONTAINER(hbox), frame);
	gtk_widget_show(frame);

	hbox_frame=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox_frame);
	gtk_widget_show(hbox_frame);

	label=gtk_label_new("X : ");
	gtk_box_pack_start(GTK_BOX(hbox_frame), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 
	
	entry_x_label = gtk_entry_new();
	gtk_widget_set_size_request(entry_x_label,100,-1);
	if(GABEDIT_XYPLOT(xyplot)->h_label_str)
		gtk_entry_set_text(GTK_ENTRY(entry_x_label),GABEDIT_XYPLOT(xyplot)->h_label_str);
	else
		gtk_entry_set_text(GTK_ENTRY(entry_x_label),"");
	gtk_box_pack_start(GTK_BOX(hbox_frame), entry_x_label, FALSE, FALSE, 2);
	gtk_widget_show(entry_x_label);

	label=gtk_label_new("Y : ");
	gtk_box_pack_start(GTK_BOX(hbox_frame), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 
	
	entry_y_label = gtk_entry_new();
	gtk_widget_set_size_request(entry_y_label,100,-1);
	if(GABEDIT_XYPLOT(xyplot)->v_label_str)
		gtk_entry_set_text(GTK_ENTRY(entry_y_label),GABEDIT_XYPLOT(xyplot)->v_label_str);
	else
		gtk_entry_set_text(GTK_ENTRY(entry_y_label),"");
	gtk_box_pack_start(GTK_BOX(hbox_frame), entry_y_label, FALSE, FALSE, 2);
	gtk_widget_show(entry_y_label);

	gtk_widget_show(window); 

	g_signal_connect (G_OBJECT (entry_x_label), "activate", (GtkSignalFunc)activate_entry_xlabel, xyplot);
	g_signal_connect (G_OBJECT (entry_y_label), "activate", (GtkSignalFunc)activate_entry_ylabel, xyplot);

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow)
	{
		gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parentWindow));
	}
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
}
/****************************************************************************************/
static void set_ranges_dialog(GtkWidget* xyplot)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* parentWindow = NULL;
	GtkWidget* frame = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* hbox_frame = NULL;
	GtkWidget* label = NULL;
	GtkWidget* entry_x_min = NULL;
	GtkWidget* entry_x_max = NULL;
	GtkWidget* entry_y_min = NULL;
	GtkWidget* entry_y_max = NULL;
	gchar tmp[100];


	gtk_window_set_title (GTK_WINDOW (window), "Set ranges");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_modal (GTK_WINDOW (window), TRUE);

	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_widget_destroy), (gpointer)xyplot);
	
	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_widget_show(hbox);

	frame=gtk_frame_new("Set ranges");
	gtk_container_add(GTK_CONTAINER(hbox), frame);
	gtk_widget_show(frame);

	hbox_frame=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox_frame);
	gtk_widget_show(hbox_frame);

	label=gtk_label_new("X Min: ");
	gtk_box_pack_start(GTK_BOX(hbox_frame), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 

	entry_x_min = gtk_entry_new();
	gtk_widget_set_size_request(entry_x_min,50,-1);
	sprintf(tmp,"%0.3f",GABEDIT_XYPLOT(xyplot)->xmin);
	gtk_entry_set_text(GTK_ENTRY(entry_x_min),tmp);
	gtk_box_pack_start(GTK_BOX(hbox_frame), entry_x_min, TRUE, FALSE, 2);
	gtk_widget_show(entry_x_min);

	label=gtk_label_new("X Max: ");
	gtk_box_pack_start(GTK_BOX(hbox_frame), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 
	
	entry_x_max = gtk_entry_new();
	gtk_widget_set_size_request(entry_x_max,50,-1);
	sprintf(tmp,"%0.3f",GABEDIT_XYPLOT(xyplot)->xmax);
	gtk_entry_set_text(GTK_ENTRY(entry_x_max),tmp);
	gtk_box_pack_start(GTK_BOX(hbox_frame), entry_x_max, TRUE, FALSE, 2);
	gtk_widget_show(entry_x_max);

	label=gtk_label_new("Y Min: ");
	gtk_box_pack_start(GTK_BOX(hbox_frame), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 
	
	entry_y_min = gtk_entry_new();
	gtk_widget_set_size_request(entry_y_min,50,-1);
	sprintf(tmp,"%0.3f",GABEDIT_XYPLOT(xyplot)->ymin);
	gtk_entry_set_text(GTK_ENTRY(entry_y_min),tmp);
	gtk_box_pack_start(GTK_BOX(hbox_frame), entry_y_min, TRUE, FALSE, 2);
	gtk_widget_show(entry_y_min);

	label=gtk_label_new("Y Max: ");
	gtk_box_pack_start(GTK_BOX(hbox_frame), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 
	
	entry_y_max = gtk_entry_new();
	gtk_widget_set_size_request(entry_y_max,50,-1);
	sprintf(tmp,"%0.3f",GABEDIT_XYPLOT(xyplot)->ymax);
	gtk_entry_set_text(GTK_ENTRY(entry_y_max),tmp);
	gtk_box_pack_start(GTK_BOX(hbox_frame), entry_y_max, TRUE, FALSE, 2);
	gtk_widget_show(entry_y_max);

	gtk_widget_show(window); 

	g_signal_connect (G_OBJECT (entry_x_min), "activate", (GtkSignalFunc)activate_entry_xmin, xyplot);
	g_signal_connect (G_OBJECT (entry_x_max), "activate", (GtkSignalFunc)activate_entry_xmax, xyplot);
	g_signal_connect (G_OBJECT (entry_y_min), "activate", (GtkSignalFunc)activate_entry_ymin, xyplot);
	g_signal_connect (G_OBJECT (entry_y_max), "activate", (GtkSignalFunc)activate_entry_ymax, xyplot);


	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow)
	{
		gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parentWindow));
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
static void set_ticks_dialog(GtkWidget* xyplot)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* frame = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* hbox_frame = NULL;
	GtkWidget* label = NULL;
	GtkWidget* spin_hmajor = NULL;
	GtkWidget* spin_hminor = NULL;
	GtkWidget* spin_vmajor = NULL;
	GtkWidget* spin_vminor = NULL;
	GtkWidget* parentWindow = NULL;

	gtk_window_set_title (GTK_WINDOW (window), "Set ticks");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_modal (GTK_WINDOW (window), TRUE);

	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(gtk_widget_destroy), (gpointer)xyplot);
	
	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), hbox);
	gtk_widget_show(hbox);

	frame=gtk_frame_new("Set ticks");
	gtk_container_add(GTK_CONTAINER(hbox), frame);
	gtk_widget_show(frame);

	hbox_frame=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox_frame);
	gtk_widget_show(hbox_frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox_frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("X Major: ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin_hmajor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), spin_hmajor, TRUE, FALSE, 2);
	gtk_widget_show(spin_hmajor);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox_frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("Y Major: ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin_vmajor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), spin_vmajor, TRUE, FALSE, 2);
	gtk_widget_show(spin_vmajor);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox_frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("X Minor: ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin_hminor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), spin_hminor, TRUE, FALSE, 2);
	gtk_widget_show(spin_hminor);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(hbox_frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("Y Minor: ");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin_vminor=gtk_spin_button_new_with_range(0, 30, 1);
	gtk_box_pack_start(GTK_BOX(hbox), spin_vminor, TRUE, FALSE, 2);
	gtk_widget_show(spin_vminor);

	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_hmajor), GABEDIT_XYPLOT(xyplot)->hmajor_ticks);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_hminor), GABEDIT_XYPLOT(xyplot)->hminor_ticks);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_vmajor), GABEDIT_XYPLOT(xyplot)->vmajor_ticks);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_vminor), GABEDIT_XYPLOT(xyplot)->vminor_ticks);

	gtk_widget_show(window); 

	g_signal_connect(G_OBJECT(spin_hmajor), "value-changed", G_CALLBACK(spin_hmajor_changed_value), xyplot);
	g_signal_connect(G_OBJECT(spin_hminor), "value-changed", G_CALLBACK(spin_hminor_changed_value), xyplot);
	g_signal_connect(G_OBJECT(spin_vmajor), "value-changed", G_CALLBACK(spin_vmajor_changed_value), xyplot);
	g_signal_connect(G_OBJECT(spin_vminor), "value-changed", G_CALLBACK(spin_vminor_changed_value), xyplot);

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow)
	{
		gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parentWindow));
	}
}
/*********************************************************************************************************************/
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
static void saveImageDlg(GtkWidget* xyplot, gchar* type)
{
	GtkFileFilter *filter;
	GtkWidget *dialog;
	gchar* tmp = NULL;
	GtkWidget *parentWindow;

	dialog = g_object_new (GTK_TYPE_FILE_CHOOSER_DIALOG, "action", GTK_FILE_CHOOSER_ACTION_SAVE, "file-system-backend", "gtk+", "select-multiple", FALSE, NULL);
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
	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow) gtk_window_set_transient_for(GTK_WINDOW(dialog),GTK_WINDOW(parentWindow));
}
/****************************************************************************************/
static void spin_line_width_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (spinbutton), "CurentData");
		data->line_width = gtk_spin_button_get_value(spinbutton);
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void spin_line_color_changed_value(GtkColorButton  *colorbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (colorbutton), "CurentData");
		GdkColor c;
		gtk_color_button_get_color (colorbutton, &c);
		
		data->line_color = c; 
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/********************************************************************************************************/
static void combo_line_style_changed_value (GtkComboBox *combobox, gpointer user_data)
{
	GtkTreeIter iter;
	gchar* d = NULL;

	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (combobox), "CurentData");

		gtk_tree_model_get (model, &iter, 0, &d, -1);
		if(!d) return;
		if(!data) return;
		if (!strcmp(d,"Solid") ) {  data->line_style = GDK_LINE_SOLID; }
		else if (!strcmp(d,"On-Off dashed") ) {data->line_style = GDK_LINE_ON_OFF_DASH; }
		else if (!strcmp(d,"Double dashed") ) { data->line_style = GDK_LINE_DOUBLE_DASH;}
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void spin_point_size_changed_value(GtkSpinButton *spinbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (spinbutton), "CurentData");
		data->point_size = gtk_spin_button_get_value(spinbutton);
		xyplot_build_points_data(GABEDIT_XYPLOT(xyplot), data);
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/********************************************************************************************************/
static void combo_point_style_changed_value (GtkComboBox *combobox, gpointer user_data)
{
	GtkTreeIter iter;
	gchar* d = NULL;

	if (gtk_combo_box_get_active_iter (combobox, &iter))
	{
		GtkTreeModel* model = gtk_combo_box_get_model(combobox);
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (combobox), "CurentData");

		gtk_tree_model_get (model, &iter, 0, &d, -1);
		if(!d) return;
		if(!data) return;
		sprintf(data->point_str,d);
		xyplot_build_points_data(GABEDIT_XYPLOT(xyplot), data);
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void spin_point_color_changed_value(GtkColorButton  *colorbutton, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (colorbutton), "CurentData");
		GdkColor c;
		gtk_color_button_get_color (colorbutton, &c);
		
		data->point_color = c; 
		xyplot_build_points_data(GABEDIT_XYPLOT(xyplot), data);
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/********************************************************************************************************/
static GtkWidget *add_point_types_combo(GtkWidget *hbox, XYPlotData* data)
{
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;
	gint i = 0;
	gint k = 0;
	/* 0x2605=star, 25C6=BLACK DIAMOND,  0x25B2= black triangle, 0x25B3=white triangle */
	/* long int x =0x2605; printf("%d\n",x) in decimal*/
	gchar* list [] = {"<span >&#9733;</span>","+","x",
		"<span >&#9675;</span>", "<span >&#9679;</span>",
		"<span >&#9688;</span>", "<span >&#9689;</span>",
		"<span >&#9670;</span>", "<span >&#9674;</span>",
		"<span >&#8226;</span>",
		"<span ><b>&#9788;</b></span>",
		"<span >&#9651;</span>", "<span >&#9650;</span>"};
	guint n = G_N_ELEMENTS (list);

	store = gtk_tree_store_new (1,G_TYPE_STRING);

	for(i=0;i<n;i++)
	{
        	gtk_tree_store_append (store, &iter, NULL);
        	gtk_tree_store_set (store, &iter, 0, list[i], -1);
		if(!strcmp(list[i],data->point_str)) k = i;
	}
	

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	g_object_unref (model);
	gtk_box_pack_start (GTK_BOX (hbox), combobox, TRUE, TRUE, 1);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "markup", 0, NULL);

	gtk_widget_show(combobox); 
	gtk_combo_box_set_active (GTK_COMBO_BOX (combobox), k);

	return combobox;
}
/********************************************************************************************************/
static GtkWidget *add_line_types_combo(GtkWidget *hbox)
{
        GtkTreeIter iter;
        GtkTreeStore *store;
	GtkTreeModel *model;
	GtkWidget *combobox;
	GtkCellRenderer *renderer;

	store = gtk_tree_store_new (1,G_TYPE_STRING);

        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Solid", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "On-Off dashed", -1);
        gtk_tree_store_append (store, &iter, NULL);
        gtk_tree_store_set (store, &iter, 0, "Double dashed", -1);

        model = GTK_TREE_MODEL (store);
	combobox = gtk_combo_box_new_with_model (model);
	g_object_unref (model);
	gtk_box_pack_start (GTK_BOX (hbox), combobox, TRUE, TRUE, 1);
	renderer = gtk_cell_renderer_text_new ();
	gtk_cell_layout_pack_start (GTK_CELL_LAYOUT (combobox), renderer, TRUE);
	gtk_cell_layout_set_attributes (GTK_CELL_LAYOUT (combobox), renderer, "text", 0, NULL);

	return combobox;
}
/****************************************************************************************/
static void activate_entry_scale_x(GtkEntry *entry, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (entry), "CurentData");
		gint loop;
		gdouble a;
		G_CONST_RETURN gchar* t;
		t= gtk_entry_get_text(GTK_ENTRY(entry));
		if(!t) return;
		a = atof(t);
		for(loop=0;loop<data->size; loop++)
			data->x[loop] *= a;
		gtk_entry_set_text(GTK_ENTRY(entry),"1.0");
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void activate_entry_scale_y(GtkEntry *entry, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (entry), "CurentData");
		gint loop;
		gdouble a;
		G_CONST_RETURN gchar* t;
		t= gtk_entry_get_text(GTK_ENTRY(entry));
		if(!t) return;
		a = atof(t);
		for(loop=0;loop<data->size; loop++)
			data->y[loop] *= a;
		gtk_entry_set_text(GTK_ENTRY(entry),"1.0");
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void activate_entry_shift_x(GtkEntry *entry, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (entry), "CurentData");
		gint loop;
		gdouble a;
		G_CONST_RETURN gchar* t;
		t= gtk_entry_get_text(GTK_ENTRY(entry));
		if(!t) return;
		a = atof(t);
		for(loop=0;loop<data->size; loop++)
			data->x[loop] += a;
		gtk_entry_set_text(GTK_ENTRY(entry),"0.0");
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void activate_entry_shift_y(GtkEntry *entry, gpointer user_data)
{
	if(user_data && G_IS_OBJECT(user_data))
	{
		GtkWidget* xyplot = GTK_WIDGET(user_data);
		XYPlotData* data = g_object_get_data(G_OBJECT (entry), "CurentData");
		gint loop;
		gdouble a;
		G_CONST_RETURN gchar* t;
		t= gtk_entry_get_text(GTK_ENTRY(entry));
		if(!t) return;
		a = atof(t);
		for(loop=0;loop<data->size; loop++)
			data->y[loop] += a;
		gtk_entry_set_text(GTK_ENTRY(entry),"0.0");
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));
	}
}
/****************************************************************************************/
static void set_data_dialog(GabeditXYPlot* xyplot, XYPlotData* data)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* frame = NULL;
	GtkWidget* hbox = NULL;
	GtkWidget* hbox1 = NULL;
	GtkWidget* label = NULL;
	GtkWidget* combo = NULL;
	GtkWidget* combo_point = NULL;
	GtkWidget* spin = NULL;
	GtkWidget* button = NULL;
	GtkWidget* spin_point = NULL;
	GtkWidget* button_point = NULL;
	GtkWidget* buttonSave = NULL;
	GtkWidget* buttonRemove = NULL;
	GtkWidget* buttonAutoRanges = NULL;
	GtkWidget* buttonAutoRangesAll = NULL;
	GtkWidget* parentWindow = NULL;
	GtkWidget* vbox_window = NULL;
	GtkWidget* entry_scale_x = NULL;
	GtkWidget* entry_scale_y = NULL;
	GtkWidget* entry_shift_x = NULL;
	GtkWidget* entry_shift_y = NULL;

	gtk_window_set_title (GTK_WINDOW (window), "Set data options");
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_modal (GTK_WINDOW (window), TRUE);

	g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(destroy_data_dialog), (gpointer)xyplot);

	vbox_window=gtk_vbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(window), vbox_window);
	gtk_widget_show(vbox_window);

	hbox1=gtk_hbox_new(FALSE, 0);
	gtk_box_pack_start(GTK_BOX(vbox_window), hbox1, TRUE, FALSE, 2);
	gtk_widget_show(hbox1);

	frame = gtk_frame_new("Set line type");
	gtk_box_pack_start(GTK_BOX(hbox1), frame, TRUE, FALSE, 2);
	gtk_widget_show(frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("Line width :");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin = gtk_spin_button_new_with_range(0, 10, 1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin), data->line_width);
	gtk_box_pack_start(GTK_BOX(hbox), spin, TRUE, FALSE, 2);
	gtk_widget_show(spin);
	g_object_set_data(G_OBJECT (window), "SpinLineWidth", spin);

	label=gtk_label_new("Line type :");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 

	combo = add_line_types_combo(hbox);
	gtk_combo_box_set_active (GTK_COMBO_BOX (combo), 0);
	if(data->line_style == GDK_LINE_SOLID) gtk_combo_box_set_active (GTK_COMBO_BOX (combo), 0);
	else if(data->line_style == GDK_LINE_ON_OFF_DASH) gtk_combo_box_set_active (GTK_COMBO_BOX (combo), 1);
	else if(data->line_style == GDK_LINE_DOUBLE_DASH) gtk_combo_box_set_active (GTK_COMBO_BOX (combo), 2);
	gtk_widget_show(combo); 
	g_object_set_data(G_OBJECT (window), "ComboLineType", combo);

	label=gtk_label_new("Line color :");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 

	button = gtk_color_button_new_with_color (&data->line_color);
	gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, FALSE, 2);
	gtk_widget_show(button);
	g_object_set_data(G_OBJECT (window), "ColorButton", button);

	frame = gtk_frame_new("Set point type");
	gtk_box_pack_start(GTK_BOX(vbox_window), frame, TRUE, FALSE, 2);
	gtk_widget_show(frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox);
	gtk_widget_show(hbox);

	label=gtk_label_new("point size :");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 
	
	spin_point = gtk_spin_button_new_with_range(0, 30, 1);
	gtk_spin_button_set_value(GTK_SPIN_BUTTON(spin_point), data->point_size);
	gtk_box_pack_start(GTK_BOX(hbox), spin_point, TRUE, FALSE, 2);
	gtk_widget_show(spin_point);
	g_object_set_data(G_OBJECT (window), "SpinPointWidth", spin_point);

	label=gtk_label_new("Point type :");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 

	combo_point = add_point_types_combo(hbox, data);
	gtk_widget_show(combo_point); 
	g_object_set_data(G_OBJECT (window), "ComboPointType", combo_point);

	label=gtk_label_new("Point color :");
	gtk_box_pack_start(GTK_BOX(hbox), label, TRUE, FALSE, 2);
	gtk_widget_show(label); 

	button_point = gtk_color_button_new_with_color (&data->point_color);
	gtk_box_pack_start(GTK_BOX(hbox), button_point, TRUE, FALSE, 2);
	gtk_widget_show(button_point);
	g_object_set_data(G_OBJECT (window), "ColorButton", button_point);


	frame = gtk_frame_new(NULL);
	gtk_box_pack_start(GTK_BOX(vbox_window), frame, TRUE, FALSE, 2);
	gtk_widget_show(frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox);
	gtk_widget_show(hbox);


	label=gtk_label_new("Scale X : ");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 

	entry_scale_x = gtk_entry_new();
	gtk_widget_set_size_request(entry_scale_x,50,-1);
	gtk_entry_set_text(GTK_ENTRY(entry_scale_x),"1.0");
	gtk_box_pack_start(GTK_BOX(hbox), entry_scale_x, FALSE, FALSE, 2);
	gtk_widget_show(entry_scale_x);

	label=gtk_label_new("Scale Y : ");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 

	entry_scale_y = gtk_entry_new();
	gtk_widget_set_size_request(entry_scale_y,50,-1);
	gtk_entry_set_text(GTK_ENTRY(entry_scale_y),"1.0");
	gtk_box_pack_start(GTK_BOX(hbox), entry_scale_y, FALSE, FALSE, 2);
	gtk_widget_show(entry_scale_y);

	label=gtk_label_new("Shift X : ");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 

	entry_shift_x = gtk_entry_new();
	gtk_widget_set_size_request(entry_shift_x,50,-1);
	gtk_entry_set_text(GTK_ENTRY(entry_shift_x),"0.0");
	gtk_box_pack_start(GTK_BOX(hbox), entry_shift_x, FALSE, FALSE, 2);
	gtk_widget_show(entry_shift_x);

	label=gtk_label_new("Shift Y : ");
	gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 2);
	gtk_widget_show(label); 


	entry_shift_y = gtk_entry_new();
	gtk_widget_set_size_request(entry_shift_y,50,-1);
	gtk_entry_set_text(GTK_ENTRY(entry_shift_y),"0.0");
	gtk_box_pack_start(GTK_BOX(hbox), entry_shift_y, FALSE, FALSE, 2);
	gtk_widget_show(entry_shift_y);

	frame = gtk_frame_new(NULL);
	gtk_box_pack_start(GTK_BOX(vbox_window), frame, TRUE, FALSE, 2);
	gtk_widget_show(frame);

	hbox=gtk_hbox_new(FALSE, 0);
	gtk_container_add(GTK_CONTAINER(frame), hbox);
	gtk_widget_show(hbox);

	buttonAutoRanges = gtk_button_new_with_label ("Auto ranges");
	gtk_box_pack_start(GTK_BOX(hbox), buttonAutoRanges, TRUE, TRUE, 4);
	gtk_widget_show (buttonAutoRanges);

	buttonAutoRangesAll = gtk_button_new_with_label ("Auto ranges all");
	gtk_box_pack_start(GTK_BOX(hbox), buttonAutoRangesAll, TRUE, TRUE, 4);
	gtk_widget_show (buttonAutoRangesAll);


	buttonSave = gtk_button_new_with_label ("Save");
	gtk_box_pack_start(GTK_BOX(hbox), buttonSave, TRUE, TRUE, 4);
	gtk_widget_show (buttonSave);

	buttonRemove = gtk_button_new_with_label ("Remove");
	gtk_box_pack_start(GTK_BOX(hbox), buttonRemove, TRUE, TRUE, 4);
	gtk_widget_show (buttonRemove);


	gtk_widget_show(window); 

	g_object_set_data(G_OBJECT (spin), "CurentData", data);
	g_signal_connect(G_OBJECT(spin), "value-changed", G_CALLBACK(spin_line_width_changed_value), xyplot);
	g_object_set_data(G_OBJECT (button), "CurentData", data);
	g_signal_connect(G_OBJECT(button), "color-set", G_CALLBACK(spin_line_color_changed_value), xyplot);
	g_signal_connect(G_OBJECT(combo), "changed", G_CALLBACK(combo_line_style_changed_value), xyplot);
	g_object_set_data(G_OBJECT (combo), "CurentData", data);

	g_signal_connect(G_OBJECT(combo_point), "changed", G_CALLBACK(combo_point_style_changed_value), xyplot);
	g_object_set_data(G_OBJECT (combo_point), "CurentData", data);

	g_object_set_data(G_OBJECT (spin_point), "CurentData", data);
	g_signal_connect(G_OBJECT(spin_point), "value-changed", G_CALLBACK(spin_point_size_changed_value), xyplot);
	g_object_set_data(G_OBJECT (button_point), "CurentData", data);
	g_signal_connect(G_OBJECT(button_point), "color-set", G_CALLBACK(spin_point_color_changed_value), xyplot);


	g_object_set_data(G_OBJECT (buttonSave), "CurentData", data);
	g_signal_connect(G_OBJECT(buttonSave), "clicked", G_CALLBACK(save_data_2columns_dlg), xyplot);

	g_object_set_data(G_OBJECT (buttonRemove), "CurentData", data);
	g_object_set_data(G_OBJECT (buttonRemove), "Window", window);
	g_object_set_data(G_OBJECT (buttonRemove), "XYPLOT", xyplot);
	g_signal_connect(G_OBJECT(buttonRemove), "clicked", G_CALLBACK(remove_data_dlg), xyplot);

	g_object_set_data(G_OBJECT (buttonAutoRanges), "CurentData", data);
	g_signal_connect(G_OBJECT(buttonAutoRanges), "clicked", G_CALLBACK(auto_range_activate), xyplot);

	g_object_set_data(G_OBJECT (buttonAutoRangesAll), "CurentData", NULL);
	g_signal_connect(G_OBJECT(buttonAutoRangesAll), "clicked", G_CALLBACK(auto_range_activate), xyplot);

	g_object_set_data(G_OBJECT (entry_scale_x), "CurentData", data);
	g_object_set_data(G_OBJECT (entry_scale_y), "CurentData", data);
	g_object_set_data(G_OBJECT (entry_shift_x), "CurentData", data);
	g_object_set_data(G_OBJECT (entry_shift_y), "CurentData", data);
	g_signal_connect (G_OBJECT (entry_scale_x), "activate", (GtkSignalFunc)activate_entry_scale_x, xyplot);
	g_signal_connect (G_OBJECT (entry_scale_y), "activate", (GtkSignalFunc)activate_entry_scale_y, xyplot);
	g_signal_connect (G_OBJECT (entry_shift_x), "activate", (GtkSignalFunc)activate_entry_shift_x, xyplot);
	g_signal_connect (G_OBJECT (entry_shift_y), "activate", (GtkSignalFunc)activate_entry_shift_y, xyplot);

	parentWindow = get_parent_window(GTK_WIDGET(xyplot));
	if(parentWindow)
	{
		gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parentWindow));
	}
	/* list_utf8();*/
	

}
/*********************************************************************************************************************/
static void toggle_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	gboolean enable = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
	GtkWidget* xyplot = g_object_get_data(G_OBJECT (action), "XYPLOT");
	if(!xyplot) return;
	if(!strcmp(name,"HGridShowMajor")) 
		xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMAJOR_GRID, enable);
	else if(!strcmp(name,"HGridShowMinor")) 
		xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMINOR_GRID, enable);
	else if(!strcmp(name,"VGridShowMajor"))
		xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMAJOR_GRID, enable);
	else if(!strcmp(name,"VGridShowMinor"))
		xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMINOR_GRID, enable);
	else if(!strcmp(name,"LegendShowLeft"))
		xyplot_show_left_legends (GABEDIT_XYPLOT(xyplot), enable);
	else if(!strcmp(name,"LegendShowRight"))
		xyplot_show_right_legends (GABEDIT_XYPLOT(xyplot), enable);
	else if(!strcmp(name,"LegendShowTop"))
		xyplot_show_top_legends (GABEDIT_XYPLOT(xyplot), enable);
	else if(!strcmp(name,"LegendShowBottom"))
		xyplot_show_bottom_legends (GABEDIT_XYPLOT(xyplot), enable);
	else if(!strcmp(name,"DirectionReflectX"))
		xyplot_reflect_x (GABEDIT_XYPLOT(xyplot), enable);
	else if(!strcmp(name,"DirectionReflectY"))
		xyplot_reflect_y (GABEDIT_XYPLOT(xyplot), enable);
}
/*--------------------------------------------------------------------------------------------------------------------*/
static GtkToggleActionEntry gtkActionToggleEntries[] =
{
	{ "HGridShowMajor", NULL, "show _H major", NULL, "show H major", G_CALLBACK (toggle_action), TRUE },
	{ "HGridShowMinor", NULL, "show _H minor", NULL, "show H minor", G_CALLBACK (toggle_action), FALSE },
	{ "VGridShowMajor", NULL, "show _V major", NULL, "show V major", G_CALLBACK (toggle_action), TRUE },
	{ "VGridShowMinor", NULL, "show _V minor", NULL, "show V minor", G_CALLBACK (toggle_action), FALSE },
	{ "LegendShowLeft", NULL, "show _left", NULL, "show left", G_CALLBACK (toggle_action), TRUE },
	{ "LegendShowRight", NULL, "show _right", NULL, "show right", G_CALLBACK (toggle_action), TRUE },
	{ "LegendShowTop", NULL, "show _top", NULL, "show top", G_CALLBACK (toggle_action), TRUE },
	{ "LegendShowBottom", NULL, "show _bottom", NULL, "show bottom", G_CALLBACK (toggle_action), TRUE },
	{ "DirectionReflectX", NULL, "_X reflect", NULL, "X reflect", G_CALLBACK (toggle_action), FALSE },
	{ "DirectionReflectY", NULL, "_Y reflect", NULL, "Y reflect", G_CALLBACK (toggle_action), FALSE },
};
/*--------------------------------------------------------------------------------------------------------------------*/
static void init_toggle_entries (GtkWidget* xyplot)
{
	xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMAJOR_GRID, gtkActionToggleEntries[0].is_active);
	xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMINOR_GRID, gtkActionToggleEntries[1].is_active);
	xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMAJOR_GRID, gtkActionToggleEntries[2].is_active);
	xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMINOR_GRID, gtkActionToggleEntries[3].is_active);
	xyplot_show_left_legends (GABEDIT_XYPLOT(xyplot), gtkActionToggleEntries[4].is_active);
	xyplot_show_right_legends (GABEDIT_XYPLOT(xyplot), gtkActionToggleEntries[5].is_active);
	xyplot_show_top_legends (GABEDIT_XYPLOT(xyplot), gtkActionToggleEntries[6].is_active);
	xyplot_show_bottom_legends (GABEDIT_XYPLOT(xyplot), gtkActionToggleEntries[7].is_active);

	xyplot_reflect_x (GABEDIT_XYPLOT(xyplot), gtkActionToggleEntries[8].is_active);
	xyplot_reflect_y (GABEDIT_XYPLOT(xyplot), gtkActionToggleEntries[9].is_active);
}
static guint numberOfGtkActionToggleEntries = G_N_ELEMENTS (gtkActionToggleEntries);
/*********************************************************************************************************************/
static void activate_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	GtkWidget* xyplot = g_object_get_data(G_OBJECT (action), "XYPLOT");
	if(!strcmp(name,"SetTicks")) { set_ticks_dialog(xyplot); }
	if(!strcmp(name,"SetRanges")) { set_ranges_dialog(xyplot); }
	if(!strcmp(name,"SetLabels")) { set_labels_dialog(xyplot); }
	if(!strcmp(name,"SetDigits")) { set_digits_dialog(xyplot); }
	if(!strcmp(name,"SetFontSize")) { set_font_size_dialog(xyplot); }
	if(!strcmp(name,"SetAutoRanges")) { gabedit_xyplot_set_autorange(GABEDIT_XYPLOT(xyplot), NULL); }
	if(!strcmp(name,"DataRead2Columns")) { read_data_2columns_dlg(xyplot); }
	if(!strcmp(name,"DataReadXY1YnColumns")) { read_data_xy1yncolumns_dlg(xyplot); }
	if(!strcmp(name,"DataReadJDX")) { read_data_jdx_dlg(xyplot); }
	if(!strcmp(name,"DataSaveAll")) { save_all_data_2columns_dlg(xyplot); }
	if(!strcmp(name,"DataRemoveAll")) { remove_all_data_dlg(xyplot); }
	if(!strcmp(name,"ScreenCaptureBMP")) {  saveImageDlg(xyplot, "bmp");}
	if(!strcmp(name,"ScreenCaptureJPEG")) {  saveImageDlg(xyplot, "jpeg");}
	if(!strcmp(name,"ScreenCapturePNG")) {  saveImageDlg(xyplot, "png");}
	if(!strcmp(name,"ScreenCaptureTPNG")) {  saveImageDlg(xyplot, "tpng");}
	if(!strcmp(name,"Close")) {  destroy_xyplot_window(xyplot);}
}
/*--------------------------------------------------------------------*/
static GtkActionEntry gtkActionEntries[] =
{
	{"Set", NULL, "_Set"},
	{"SetTicks", NULL, "_Ticks", NULL, "Ticks", G_CALLBACK (activate_action) },
	{"SetRanges", NULL, "_Ranges", NULL, "Ranges", G_CALLBACK (activate_action) },
	{"SetLabels", NULL, "_Labels", NULL, "Labels", G_CALLBACK (activate_action) },
	{"SetDigits", NULL, "_Digits", NULL, "Digits", G_CALLBACK (activate_action) },
	{"SetFontSize", NULL, "_Font size", NULL, "Font size", G_CALLBACK (activate_action) },
	{"SetAutoRanges", NULL, "_Auto ranges", NULL, "Auto ranges", G_CALLBACK (activate_action) },
	{"Render", NULL, "_Render"},
	{"RenderGrid", NULL, "_Grid"},
	{"RenderLegends", NULL, "_Legends"},
	{"RenderDirections", NULL, "_Directions"},
	{"Data", NULL, "_Data"},
	{"DataAdd", NULL, "_Add Data"},
	{"DataRead2Columns", NULL, "_Read data from an ASCII XY file(2 columns)", NULL, "Read data from an ASCII XY file(2 columns)", G_CALLBACK (activate_action) },
	{"DataReadXY1YnColumns", NULL, "_Read data from an ASCII X.Y1..Yn file(x, y1, y2,...,yn)", NULL, "Read data from an ASCII XY file(2 columns)", G_CALLBACK (activate_action) },
	{"DataReadJDX", NULL, "_Read data from a JDX file", NULL, "Read data from a JDX file", G_CALLBACK (activate_action) },
	{"DataSaveAll", NULL, "_Save all data in an ascii XY file(2columns)", NULL, "Save all data in an ascii file(2columns)", G_CALLBACK (activate_action) },
	{"DataRemoveAll", NULL, "_Remove all data", NULL, "Remove all data", G_CALLBACK (activate_action) },
	{"ScreenCapture", NULL, "_Screen Capture"},
	{"ScreenCaptureBMP", NULL, "_BMP format", NULL, "BMP format", G_CALLBACK (activate_action) },
	{"ScreenCaptureJPEG", NULL, "_JPEG format", NULL, "JPEG format", G_CALLBACK (activate_action) },
	{"ScreenCapturePNG", NULL, "_PNG format", NULL, "PNG format", G_CALLBACK (activate_action) },
	{"ScreenCaptureTPNG", NULL, "_Transparent PNG format", NULL, "Transparent PNG format", G_CALLBACK (activate_action) },
	{"Close", GTK_STOCK_CLOSE, "_Close", NULL, "Close", G_CALLBACK (activate_action) },
};


static guint numberOfGtkActionEntries = G_N_ELEMENTS (gtkActionEntries);
/********************************************************************************/
static void add_data_to_actions(GtkUIManager *manager, GtkWidget   *xyplot)
{
	GtkAction* action = NULL;
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Set/SetTicks");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Set/SetRanges");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Set/SetLabels");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Set/SetDigits");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Set/SetFontSize");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Set/SetAutoRanges");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/HGridShowMajor");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/HGridShowMinor");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/VGridShowMajor");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/VGridShowMinor");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowLeft");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowRight");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowTop");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowBottom");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderDirections/DirectionReflectX");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderDirections/DirectionReflectY");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Data/DataAdd/DataRead2Columns");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Data/DataAdd/DataReadXY1YnColumns");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Data/DataAdd/DataReadJDX");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Data/DataSaveAll");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Data/DataRemoveAll");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/ScreenCapture/ScreenCaptureBMP");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/ScreenCapture/ScreenCaptureJPEG");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/ScreenCapture/ScreenCapturePNG");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);
	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/ScreenCapture/ScreenCaptureTPNG");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);


	action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Close");
	if(action) g_object_set_data(G_OBJECT (action), "XYPLOT", xyplot);

}
/********************************************************************************/
static const gchar *uiMenuInfo =
"  <popup name=\"MenuXYPlot\">\n"
"    <separator name=\"sepMenuPopSet\" />\n"
"    <menu name=\"Set\" action=\"Set\">\n"
"      <menuitem name=\"SetTicks\" action=\"SetTicks\" />\n"
"      <menuitem name=\"SetRanges\" action=\"SetRanges\" />\n"
"      <menuitem name=\"SetLabels\" action=\"SetLabels\" />\n"
"      <menuitem name=\"SetDigits\" action=\"SetDigits\" />\n"
"      <menuitem name=\"SetFontSize\" action=\"SetFontSize\" />\n"
"      <separator name=\"sepSetAutoRanges\" />\n"
"      <menuitem name=\"SetAutoRanges\" action=\"SetAutoRanges\" />\n"
"    </menu>\n"
"    <separator name=\"sepRender\" />\n"
"    <menu name=\"Render\" action=\"Render\">\n"
"      <menu name=\"RenderGrid\" action=\"RenderGrid\">\n"
"        <menuitem name=\"HGridShowMajor\" action=\"HGridShowMajor\" />\n"
"        <menuitem name=\"HGridShowMinor\" action=\"HGridShowMinor\" />\n"
"        <menuitem name=\"VGridShowMajor\" action=\"VGridShowMajor\" />\n"
"        <menuitem name=\"VGridShowMinor\" action=\"VGridShowMinor\" />\n"
"      </menu>\n"
"      <menu name=\"RenderLegends\" action=\"RenderLegends\">\n"
"        <menuitem name=\"LegendShowLeft\" action=\"LegendShowLeft\" />\n"
"        <menuitem name=\"LegendShowRight\" action=\"LegendShowRight\" />\n"
"        <menuitem name=\"LegendShowTop\" action=\"LegendShowTop\" />\n"
"        <menuitem name=\"LegendShowBottom\" action=\"LegendShowBottom\" />\n"
"      </menu>\n"
"      <menu name=\"RenderDirections\" action=\"RenderDirections\">\n"
"        <menuitem name=\"DirectionReflectX\" action=\"DirectionReflectX\" />\n"
"        <menuitem name=\"DirectionReflectY\" action=\"DirectionReflectY\" />\n"
"      </menu>\n"
"    </menu>\n"
"    <separator name=\"sepData\" />\n"
"    <menu name=\"Data\" action=\"Data\">\n"
"      <menu name=\"DataAdd\" action=\"DataAdd\">\n"
"        <menuitem name=\"DataRead2Columns\" action=\"DataRead2Columns\" />\n"
"        <menuitem name=\"DataReadXY1YnColumns\" action=\"DataReadXY1YnColumns\" />\n"
"        <menuitem name=\"DataReadJDX\" action=\"DataReadJDX\" />\n"
"      </menu>\n"
"        <separator name=\"sepDataSaveAll\" />\n"
"        <menuitem name=\"DataSaveAll\" action=\"DataSaveAll\" />\n"
"        <separator name=\"sepDataRemoveAll\" />\n"
"        <menuitem name=\"DataRemoveAll\" action=\"DataRemoveAll\" />\n"
"    </menu>\n"
"    <separator name=\"sepScreenCapture\" />\n"
"    <menu name=\"ScreenCapture\" action=\"ScreenCapture\">\n"
"      <menuitem name=\"ScreenCaptureBMP\" action=\"ScreenCaptureBMP\" />\n"
"      <menuitem name=\"ScreenCaptureJPEG\" action=\"ScreenCaptureJPEG\" />\n"
"      <menuitem name=\"ScreenCapturePNG\" action=\"ScreenCapturePNG\" />\n"
"      <menuitem name=\"ScreenCaptureTPNG\" action=\"ScreenCaptureTPNG\" />\n"
"    </menu>\n"
"    <separator name=\"sepClose\" />\n"
"      <menuitem name=\"Close\" action=\"Close\" />\n"
"  </popup>\n"
"  <toolbar action=\"ToolbarXYPlot\">\n"
"      <toolitem name=\"SetTicks\" action=\"SetTicks\" />\n"
"      <toolitem name=\"SetRanges\" action=\"SetRanges\" />\n"
"      <toolitem name=\"ScreenCaptureBMP\" action=\"ScreenCaptureBMP\" />\n"
"      <toolitem name=\"ScreenCaptureJPEG\" action=\"ScreenCaptureJPEG\" />\n"
"      <toolitem name=\"ScreenCapturePNG\" action=\"ScreenCapturePNG\" />\n"
"      <toolitem name=\"ScreenCaptureTPNG\" action=\"ScreenCaptureTPNG\" />\n"
"  </toolbar>\n"
;
/*****************************************************************************************/
static void add_widget (GtkUIManager *merge, GtkWidget   *widget, GtkContainer *container)
{
	GtkWidget *handlebox;

	if (!GTK_IS_TOOLBAR (widget))  return;

	handlebox =gtk_handle_box_new ();
	gtk_widget_ref (handlebox);
  	gtk_handle_box_set_handle_position  (GTK_HANDLE_BOX(handlebox),GTK_POS_TOP);
	/*   GTK_SHADOW_NONE,  GTK_SHADOW_IN,  GTK_SHADOW_OUT, GTK_SHADOW_ETCHED_IN, GTK_SHADOW_ETCHED_OUT */
	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(handlebox),GTK_SHADOW_OUT);
	gtk_box_pack_start (GTK_BOX (container), handlebox, FALSE, FALSE, 0);

	if (GTK_IS_TOOLBAR (widget)) 
	{
		GtkToolbar *toolbar;
		toolbar = GTK_TOOLBAR (widget);
		gtk_toolbar_set_show_arrow (toolbar, TRUE);
		gtk_toolbar_set_style(toolbar, GTK_TOOLBAR_ICONS);
		gtk_toolbar_set_orientation(toolbar,  GTK_ORIENTATION_VERTICAL);
	}
	gtk_widget_show (widget);
	gtk_container_add (GTK_CONTAINER (handlebox), widget);
	gtk_widget_show (handlebox);
}
/*************************************************************************************************/
static void add_toolbar_and_popup_menu(GtkWidget* parent, GtkWidget* box)
{
	GtkActionGroup *actionGroup = NULL;
	GtkUIManager *merge = NULL;
	GError *error = NULL;

  	merge = gtk_ui_manager_new ();
  	g_signal_connect_swapped (parent, "destroy", G_CALLBACK (g_object_unref), merge);

	actionGroup = gtk_action_group_new ("GabeditXYPlotActions");
	gtk_action_group_add_actions (actionGroup, gtkActionEntries, numberOfGtkActionEntries, NULL);
	gtk_action_group_add_toggle_actions (actionGroup, gtkActionToggleEntries, numberOfGtkActionToggleEntries, NULL);
  	gtk_ui_manager_insert_action_group (merge, actionGroup, 0);

	if(box) g_signal_connect (merge, "add_widget", G_CALLBACK (add_widget), box);
  	//gtk_window_add_accel_group (GTK_WINDOW (GeomDlg), gtk_ui_manager_get_accel_group (merge));
	if (!gtk_ui_manager_add_ui_from_string (merge, uiMenuInfo, -1, &error))
	{
		g_message ("building menus of xyplot failed: %s", error->message);
		g_error_free (error);
	}
	g_object_set_data(G_OBJECT (parent), "Manager", merge);
	add_data_to_actions(merge,parent);
	init_toggle_entries (parent);
}
/****************************************************************************************/
GType gabedit_xyplot_get_type ()
{

	static GType xyplot_type = 0;
	if (!xyplot_type)
       	{
             static const GTypeInfo xyplot_info =
            {
	           sizeof (GabeditXYPlotClass),
	           NULL,           /* base_init */
	           NULL,           /* base_finalize */
	           (GClassInitFunc) gabedit_xyplot_class_init,
	           NULL,           /* class_finalize */
	           NULL,           /* class_data */
	           sizeof (GabeditXYPlot),
	           0,             /* n_preallocs */
	           (GInstanceInitFunc) gabedit_xyplot_init,
           };
	   xyplot_type = g_type_register_static (GTK_TYPE_WIDGET, "GabeditXYPlot", &xyplot_info, 0);
	}
	return xyplot_type;
}
/****************************************************************************************/
static void gabedit_xyplot_class_init (GabeditXYPlotClass *class)
{
  GtkObjectClass *object_class;
  GtkWidgetClass *widget_class;

  object_class = (GtkObjectClass*) class;
  widget_class = (GtkWidgetClass*) class;

  //parent_class = gtk_type_class (gtk_widget_get_type ());
  parent_class = g_type_class_peek_parent (class);

  object_class->destroy = gabedit_xyplot_destroy;

  widget_class->realize = gabedit_xyplot_realize;
  widget_class->expose_event = gabedit_xyplot_expose;
  widget_class->size_request = gabedit_xyplot_size_request;
  widget_class->size_allocate = gabedit_xyplot_size_allocate;
  widget_class->button_press_event = gabedit_xyplot_button_press;
  widget_class->button_release_event = gabedit_xyplot_button_release;
  widget_class->motion_notify_event = gabedit_xyplot_motion_notify;
  widget_class->scroll_event = gabedit_xyplot_scroll;
  widget_class->style_set = gabedit_xyplot_style_set;
}
/****************************************************************************************/
static void gabedit_xyplot_init (GabeditXYPlot *xyplot)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
     
  xyplot->xmin=-1.0;
  xyplot->xmax=1.0;
  xyplot->ymin=-1.0;
  xyplot->ymax=1.0;
    
  xyplot->x_legends_digits=8;
  xyplot->y_legends_digits=8;

  xyplot->hmajor_ticks=11;
  xyplot->hminor_ticks=3;
  xyplot->vmajor_ticks=11;
  xyplot->vminor_ticks=3;
  
  xyplot->hmajor_grid=TRUE;
  xyplot->hminor_grid=TRUE;
  xyplot->vmajor_grid=TRUE;
  xyplot->vminor_grid=TRUE;  

  xyplot->show_left_legends = TRUE;
  xyplot->show_right_legends = FALSE;
  xyplot->show_top_legends = FALSE;
  xyplot->show_bottom_legends  = TRUE;

  xyplot->reflect_x  = FALSE;
  xyplot->reflect_y  = FALSE;

  xyplot->data_list=NULL;

  xyplot->mouse_zoom_enabled=TRUE;
  xyplot->mouse_zoom_button = 2;
  xyplot->mouse_displace_enabled=FALSE;
  xyplot->wheel_zoom_enabled=FALSE;
  xyplot->mouse_autorange_enabled=FALSE;
  xyplot->mouse_autorange_button = 1;

  xyplot->h_label_str = NULL;
  xyplot->v_label_str = NULL;
  xyplot->h_label = NULL;
  xyplot->v_label = NULL;
  xyplot->h_label_width = 0;
  xyplot->h_label_height = 0;
  xyplot->v_label_width = 0;
  xyplot->v_label_height = 0;
  xyplot->font_size = 12;
}
/****************************************************************************************/
GtkWidget* gabedit_xyplot_new ()
{
  GabeditXYPlot *xyplot;

  xyplot = g_object_new (GABEDIT_TYPE_XYPLOT, NULL);
  
  return GTK_WIDGET (xyplot);
}
/****************************************************************************************/
static void gabedit_xyplot_destroy (GtkObject *object)
{
  GabeditXYPlot *xyplot;

  g_return_if_fail (object != NULL);
  g_return_if_fail (G_IS_OBJECT (object));
  g_return_if_fail (GABEDIT_IS_XYPLOT (object));

  xyplot = GABEDIT_XYPLOT (object);

  if (xyplot->plotting_area && G_IS_OBJECT(xyplot->plotting_area))
  {
    g_object_unref(G_OBJECT(xyplot->plotting_area));
    xyplot->plotting_area = NULL;
  }

  if (xyplot->back_gc && G_IS_OBJECT(xyplot->back_gc))
  {
    g_object_unref(xyplot->back_gc);
    xyplot->back_gc = NULL;
  }

  if (xyplot->data_gc &&  G_IS_OBJECT(xyplot->data_gc))
  {
    g_object_unref(xyplot->data_gc);
    xyplot->data_gc = NULL;
  }

  if (xyplot->hmajor_grid_gc && G_IS_OBJECT(xyplot->hmajor_grid_gc))
  {
    g_object_unref(xyplot->hmajor_grid_gc);
    xyplot->hmajor_grid_gc = NULL;
  }

  if (xyplot->hminor_grid_gc && G_IS_OBJECT(xyplot->hminor_grid_gc))
  {
    g_object_unref(xyplot->hminor_grid_gc);
    xyplot->hminor_grid_gc = NULL;
  }

  if (xyplot->vmajor_grid_gc && G_IS_OBJECT(xyplot->vmajor_grid_gc))
  {
    g_object_unref(xyplot->vmajor_grid_gc);
    xyplot->vmajor_grid_gc = NULL;
  }

  if (xyplot->vminor_grid_gc && G_IS_OBJECT(xyplot->vminor_grid_gc))
  {
    g_object_unref(xyplot->vminor_grid_gc);
    xyplot->vminor_grid_gc = NULL;
  }

  if (GTK_OBJECT_CLASS (parent_class)->destroy)
    (* GTK_OBJECT_CLASS (parent_class)->destroy) (object);
  
  gtk_object_destroy (object);
}
/****************************************************************************************/
static gint xyplot_get_font_size (PangoFontDescription* font_desc)
{
	gint font_size = 8;
	if(!font_desc) return font_size;
	if (pango_font_description_get_size_is_absolute (font_desc))
	      font_size = pango_font_description_get_size (font_desc) / PANGO_SCALE;
	return font_size;
}
/****************************************************************************************/
static void gabedit_xyplot_realize (GtkWidget *widget)
{
  GabeditXYPlot *xyplot;
  GdkWindowAttr attributes;
  gint attributes_mask;
  GdkGCValues gc_values;
  GdkGCValuesMask gc_values_mask;
  GdkColor black;
  GdkColor white;
  GdkColormap *colormap;
     
  g_return_if_fail (widget != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (widget));

  GTK_WIDGET_SET_FLAGS (widget, GTK_REALIZED);
  xyplot = GABEDIT_XYPLOT (widget);

  attributes.x = widget->allocation.x;
  attributes.y = widget->allocation.y;
  attributes.width = widget->allocation.width;
  attributes.height = widget->allocation.height;
  attributes.wclass = GDK_INPUT_OUTPUT;
  attributes.window_type = GDK_WINDOW_CHILD;
  //attributes.event_mask = gtk_widget_get_events (widget) | 
  attributes.event_mask = GDK_EXPOSURE_MASK | GDK_LEAVE_NOTIFY_MASK |
	  GDK_POINTER_MOTION_MASK |
    GDK_POINTER_MOTION_HINT_MASK | 
    GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK;
  attributes.visual = gtk_widget_get_visual (widget);
  attributes.colormap = gtk_widget_get_colormap (widget);

  attributes_mask = GDK_WA_X | GDK_WA_Y | GDK_WA_VISUAL | GDK_WA_COLORMAP;
  widget->window = gdk_window_new (widget->parent->window, &attributes, attributes_mask);

  widget->style = gtk_style_attach (widget->style, widget->window);

  gdk_window_set_user_data (widget->window, widget);

  gtk_style_set_background (widget->style, widget->window, GTK_STATE_ACTIVE);
       
  colormap=gdk_drawable_get_colormap(widget->window); 

  gdk_color_white(colormap, &white);
  gdk_color_black(colormap, &black);

  gtk_widget_modify_bg (widget, GTK_STATE_NORMAL, &white);
    
  gc_values.foreground=white;
  gc_values.line_style=GDK_LINE_SOLID;
  gc_values.line_width=1;
  gc_values_mask=GDK_GC_FOREGROUND | GDK_GC_LINE_STYLE | GDK_GC_LINE_WIDTH;
  xyplot->back_gc=gdk_gc_new_with_values (widget->window, &gc_values, gc_values_mask);
  
  gc_values.foreground=black;
  xyplot->hmajor_grid_gc=gdk_gc_new_with_values (widget->window, &gc_values, gc_values_mask);
  xyplot->vmajor_grid_gc=gdk_gc_new_with_values (widget->window, &gc_values, gc_values_mask);
  
  gc_values.foreground=black;
  gc_values.line_style=GDK_LINE_ON_OFF_DASH;
  gc_values.line_width=1;
  gc_values_mask=GDK_GC_FOREGROUND | GDK_GC_LINE_STYLE | GDK_GC_LINE_WIDTH;
  xyplot->hminor_grid_gc=gdk_gc_new_with_values (widget->window, &gc_values, gc_values_mask);
  xyplot->vminor_grid_gc=gdk_gc_new_with_values (widget->window, &gc_values, gc_values_mask);

  xyplot->data_gc=gdk_gc_new (widget->window);

  xyplot->font_size =  xyplot_get_font_size (widget->style->font_desc);

  /* Create the initial legends*/
  xyplot_build_legends(xyplot);
  xyplot_calculate_legends_sizes(xyplot);
  xyplot_calculate_sizes(xyplot);
  add_toolbar_and_popup_menu(widget, NULL);
}
/****************************************************************************************/
static void gabedit_xyplot_size_request (GtkWidget *widget, GtkRequisition *requisition)
{
  g_return_if_fail (widget != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (widget));
  g_return_if_fail (requisition != NULL);

  requisition->width = XYPLOT_DEFAULT_SIZE;
  requisition->height = XYPLOT_DEFAULT_SIZE;
}
/****************************************************************************************/
static void gabedit_xyplot_size_allocate (GtkWidget *widget, GtkAllocation *allocation)
{
  GabeditXYPlot *xyplot;

  g_return_if_fail (widget != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (widget));
  g_return_if_fail (allocation != NULL);

  widget->allocation = *allocation;
  xyplot=GABEDIT_XYPLOT(widget);  

  if (GTK_WIDGET_REALIZED (widget))
    gdk_window_move_resize (widget->window,
			allocation->x, 
			allocation->y,
			allocation->width, 
			allocation->height);
    
  xyplot_calculate_sizes(xyplot);
}
/****************************************************************************************/
static void draw_points(GtkWidget *widget, GabeditXYPlot *xyplot, XYPlotData* data)
{
	gint i;
	guint x, y;
	GdkRectangle rect;

	if ( data->point_size<1 ) return;

	rect.x=0;
	rect.y=0;
	rect.width=widget->allocation.width;
	rect.height=widget->allocation.height;
	gdk_gc_set_rgb_fg_color (xyplot->data_gc, &data->point_color);

	for (i=0; i<data->size; i++)
        if ((data->x[i] < xyplot->xmax) && 
            (data->x[i] > xyplot->xmin) && 
            (data->y[i] < xyplot->ymax) && 
            (data->y[i] > xyplot->ymin))
	{
        	value2pixel(xyplot, data->x[i], data->y[i], &x, &y);
        	y=xyplot->plotting_rect.height-y;                   
		x -= data->point_width/2;
		y -= data->point_height/2;
		if(data->point_pango)
        	gtk_paint_layout (widget->style,
			xyplot->plotting_area,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
			x,
			y,
			data->point_pango);
	}
}
/****************************************************************************************/
static void draw_lines(GtkWidget *widget, GabeditXYPlot *xyplot, XYPlotData* data)
{
	GdkPoint* points;
	gint i;
	if (data->line_width<1) return;
	points=(GdkPoint*)g_malloc( (sizeof(GdkPoint) * data->size));
	gdk_gc_set_rgb_fg_color (xyplot->data_gc, &data->line_color);
	//gdk_gc_set_line_attributes (xyplot->data_gc, data->line_width, data->line_style, GDK_CAP_NOT_LAST, GDK_JOIN_MITER);
	gdk_gc_set_line_attributes (xyplot->data_gc, data->line_width, data->line_style, GDK_CAP_ROUND, GDK_JOIN_MITER);
                                             
	for (i=0; i<data->size; i++)
	{
		value2pixel(xyplot, data->x[i], data->y[i], (guint *)&points[i].x, (guint *)&points[i].y);
		points[i].y=xyplot->plotting_rect.height-points[i].y;                   
	}
	gdk_draw_lines (xyplot->plotting_area, xyplot->data_gc, points, data->size);  
	g_free(points);
}
/****************************************************************************************/
static void draw_zoom_rectangle(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	if (!xyplot->mouse_zoom_enabled || xyplot->mouse_button != xyplot->mouse_zoom_button) return;
	gdk_draw_rectangle (widget->window,
	                widget->style->fg_gc[widget->state],
			FALSE,
			xyplot->zoom_rect.x,
			xyplot->zoom_rect.y,
			xyplot->zoom_rect.width,
			xyplot->zoom_rect.height);
}
/****************************************************************************************/
static void draw_hminor_ticks(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	gint j;
	if (xyplot->hmajor_ticks<2 || xyplot->hminor_ticks == 0 ) return;
	for (i=0; i < xyplot->hmajor_ticks-1; i++)
	for (j=1; j <= xyplot->hminor_ticks; j++)
	{
		if (xyplot->show_bottom_legends)
        	gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x+i*xyplot->d_hminor*(xyplot->hminor_ticks+1)+j*xyplot->d_hminor, 
			xyplot->plotting_rect.y+xyplot->plotting_rect.height,
			xyplot->plotting_rect.x+i*xyplot->d_hminor*(xyplot->hminor_ticks+1)+j*xyplot->d_hminor,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height+3);
      		if (xyplot->show_top_legends)
        	gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x+i*xyplot->d_hminor*(xyplot->hminor_ticks+1)+j*xyplot->d_hminor, 
			xyplot->plotting_rect.y,
			xyplot->plotting_rect.x+i*xyplot->d_hminor*(xyplot->hminor_ticks+1)+j*xyplot->d_hminor,
			xyplot->plotting_rect.y-3);
      }
}
/****************************************************************************************/
static void draw_hmajor_ticks_and_xlegends(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	GdkRectangle rect;

	rect.x=0;
	rect.y=0;
	rect.width=widget->allocation.width;
	rect.height=widget->allocation.height;
  
	if (xyplot->hmajor_ticks>1)
	for (i=0; i < xyplot->hmajor_ticks; i++)
	{
		gint l1 = i;
		if(xyplot->reflect_x) l1 = xyplot->hmajor_ticks-i-1;
		if (xyplot->show_bottom_legends)
		gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x+i*xyplot->d_hmajor, 
			xyplot->plotting_rect.y+xyplot->plotting_rect.height,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height+5);
		if (xyplot->show_top_legends)
		gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x+i*xyplot->d_hmajor, 
			xyplot->plotting_rect.y,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor,
			xyplot->plotting_rect.y-5);

		if (xyplot->x_legends_digits!=0 && xyplot->show_bottom_legends)
		gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor-0.5*xyplot->legends_width,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height+0.375*xyplot->legends_height,
			xyplot->h_legends[l1]);
		if (xyplot->x_legends_digits!=0 && xyplot->show_top_legends)
		gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        xyplot->plotting_rect.x+i*xyplot->d_hmajor-0.5*xyplot->legends_width,
			xyplot->plotting_rect.y-1.25*xyplot->legends_height,
			xyplot->h_legends[l1]);
	}
	if ( xyplot->h_label && xyplot->x_legends_digits!=0 && xyplot->show_bottom_legends)
	{
        	gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        xyplot->plotting_rect.x+0.5*xyplot->plotting_rect.width,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height+xyplot->legends_height+0.375*xyplot->h_label_height,
			xyplot->h_label);
	}
	if (xyplot->h_label  && xyplot->x_legends_digits!=0 && xyplot->show_top_legends && !xyplot->show_bottom_legends)
	{
        	gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        xyplot->plotting_rect.x+0.5*xyplot->plotting_rect.width,
			xyplot->plotting_rect.y-xyplot->legends_height-1.375*xyplot->h_label_height,
			xyplot->h_label);
	}
}

/****************************************************************************************/
static void draw_hminor_grid(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	gint j;
	if (xyplot->hminor_grid && (xyplot->vmajor_ticks > 1) && (xyplot->vminor_ticks != 0))
	for (i=0; i < xyplot->vmajor_ticks-1; i++)
	for (j=1; j <= xyplot->vminor_ticks; j++)
	{
        	gdk_draw_line(widget->window, 
			xyplot->hminor_grid_gc,
			xyplot->plotting_rect.x, 
			xyplot->plotting_rect.y+i*xyplot->d_vmajor+j*xyplot->d_vminor,
			xyplot->plotting_rect.x+xyplot->plotting_rect.width,
			xyplot->plotting_rect.y+i*xyplot->d_vmajor+j*xyplot->d_vminor);
      }
}
/****************************************************************************************/
static void draw_hmajor_grid(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
 
	if (xyplot->hmajor_grid && (xyplot->vmajor_ticks > 1) )
	for (i=1; i < (xyplot->vmajor_ticks-1); i++)
		gdk_draw_line(widget->window, 
			xyplot->hmajor_grid_gc,
			xyplot->plotting_rect.x, 
			xyplot->plotting_rect.y+i*xyplot->d_vmajor,
			xyplot->plotting_rect.x+xyplot->plotting_rect.width,
			xyplot->plotting_rect.y+i*xyplot->d_vmajor);
}
/****************************************************************************************/
static void draw_vminor_ticks(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	gint j;

	if ( (xyplot->vmajor_ticks > 1) && (xyplot->vminor_ticks != 0) )
	for (i=0; i < xyplot->vmajor_ticks-1; i++)
	for (j=1; j <= xyplot->vminor_ticks; j++)
	{
		if (xyplot->show_left_legends)
        	gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x, 
			xyplot->plotting_rect.y+i*xyplot->d_vminor*(xyplot->vminor_ticks+1)+j*xyplot->d_vminor,
			xyplot->plotting_rect.x-3,
			xyplot->plotting_rect.y+i*xyplot->d_vminor*(xyplot->vminor_ticks+1)+j*xyplot->d_vminor);       
      		if (xyplot->show_right_legends)
        	gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x+xyplot->plotting_rect.width, 
			xyplot->plotting_rect.y+i*xyplot->d_vminor*(xyplot->vminor_ticks+1)+j*xyplot->d_vminor,
			xyplot->plotting_rect.x+xyplot->plotting_rect.width+3,
			xyplot->plotting_rect.y+i*xyplot->d_vminor*(xyplot->vminor_ticks+1)+j*xyplot->d_vminor);       
	}
}
/****************************************************************************************/
static void draw_vmajor_ticks_and_ylegends(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	GdkRectangle rect;

	rect.x=0;
	rect.y=0;
	rect.width=widget->allocation.width;
	rect.height=widget->allocation.height;

	if (xyplot->vmajor_ticks>1)
	for (i=0; i < xyplot->vmajor_ticks; i++)
	{
		gint l1 = i;
		if(xyplot->reflect_y) l1 = xyplot->vmajor_ticks-i-1;
		if (xyplot->show_left_legends)
		gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x, 
			xyplot->plotting_rect.y+i*xyplot->d_vmajor,
			xyplot->plotting_rect.x-5,
			xyplot->plotting_rect.y+i*xyplot->d_vmajor);
		if (xyplot->show_right_legends)
		gdk_draw_line(widget->window, 
			widget->style->fg_gc[widget->state],
			xyplot->plotting_rect.x+xyplot->plotting_rect.width, 
			xyplot->plotting_rect.y+i*xyplot->d_vmajor,
			xyplot->plotting_rect.x+xyplot->plotting_rect.width+5,
			xyplot->plotting_rect.y+i*xyplot->d_vmajor);
    
		if (xyplot->y_legends_digits!=0 && xyplot->show_left_legends)
        	gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        xyplot->plotting_rect.x-10-1.0*xyplot->legends_width,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height-i*xyplot->d_vmajor-0.5*xyplot->legends_height,
			xyplot->v_legends[l1]);
		if (xyplot->y_legends_digits!=0 && xyplot->show_right_legends)
		gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        xyplot->plotting_rect.x+xyplot->plotting_rect.width+10,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height-i*xyplot->d_vmajor-0.5*xyplot->legends_height,
			xyplot->v_legends[l1]);
	}
	if (xyplot->v_label && xyplot->y_legends_digits!=0 && xyplot->show_left_legends)
	{
		PangoMatrix matrix = PANGO_MATRIX_INIT;
		PangoContext *context = gtk_widget_get_pango_context(widget);
  		pango_matrix_rotate (&matrix, 90);
		pango_context_set_matrix (context, &matrix);
		pango_layout_context_changed (xyplot->v_label);
        	gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        2,
			xyplot->plotting_rect.y+0.5*xyplot->plotting_rect.height-xyplot->v_label_width/2,
			xyplot->v_label);
  		pango_matrix_rotate (&matrix, -90);
		pango_context_set_matrix (context, &matrix);
		pango_layout_context_changed (xyplot->v_label);
	}
	if (xyplot->v_label && xyplot->y_legends_digits!=0 && xyplot->show_right_legends && !xyplot->show_left_legends)
	{
		PangoMatrix matrix = PANGO_MATRIX_INIT;
		PangoContext *context = gtk_widget_get_pango_context(widget);
  		pango_matrix_rotate (&matrix, 90);
		pango_context_set_matrix (context, &matrix);
		pango_layout_context_changed (xyplot->v_label);
        	gtk_paint_layout (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			FALSE,
			&rect,
			widget,
			NULL,
                        xyplot->plotting_rect.x+xyplot->plotting_rect.width+1.25*xyplot->legends_width+2,
			xyplot->plotting_rect.y+0.5*xyplot->plotting_rect.height-xyplot->v_label_width/2,
			xyplot->v_label);
  		pango_matrix_rotate (&matrix, -90);
		pango_context_set_matrix (context, &matrix);
		pango_layout_context_changed (xyplot->v_label);
	}
}
/****************************************************************************************/
static void draw_vminor_grid(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	gint j;
	if (xyplot->vminor_grid && (xyplot->hmajor_ticks > 1) && (xyplot->hminor_ticks != 0) )
	for (i=0; i < xyplot->hmajor_ticks-1; i++)
	for (j=1; j <= xyplot->hminor_ticks; j++)
       	gdk_draw_line(widget->window, 
			xyplot->vminor_grid_gc,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor+j*xyplot->d_hminor, 
			xyplot->plotting_rect.y,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor+j*xyplot->d_hminor,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height);
}
/****************************************************************************************/
static void draw_vmajor_grid(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gint i;
	if (xyplot->vmajor_grid && (xyplot->hmajor_ticks > 1))
	for (i=1; i < (xyplot->hmajor_ticks-1); i++)  
	gdk_draw_line(widget->window, 
			xyplot->vmajor_grid_gc,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor, 
			xyplot->plotting_rect.y,
			xyplot->plotting_rect.x+i*xyplot->d_hmajor,
			xyplot->plotting_rect.y+xyplot->plotting_rect.height);
}
/****************************************************************************************/
static void draw_borders(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gdk_draw_rectangle (widget->window,
	                widget->style->fg_gc[widget->state],
			FALSE,
			xyplot->plotting_rect.x,
			xyplot->plotting_rect.y,
			xyplot->plotting_rect.width,
			xyplot->plotting_rect.height);
}
/****************************************************************************************/
static void draw_background(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	GdkRectangle rect;

	rect.x=0;
	rect.y=0;
	rect.width=widget->allocation.width;
	rect.height=widget->allocation.height;

	gtk_paint_flat_box (widget->style,
			widget->window,
			GTK_STATE_NORMAL,
			GTK_SHADOW_NONE,
			&rect,
			widget,
			NULL, 
			0, 
			0, 
			-1,
			-1);
  
	/* Filling the plotting area*/
	gdk_draw_rectangle (xyplot->plotting_area,
	                xyplot->back_gc,
			TRUE,
			0,
			0,
			xyplot->plotting_rect.width,
			xyplot->plotting_rect.height);
  
}
/****************************************************************************************/
static void draw_data(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	XYPlotData *data = NULL;
	GList *current = NULL;

	if(xyplot->data_list)
	for(current=g_list_first(xyplot->data_list); current!=NULL; current=current->next)
	{
		data=(XYPlotData*)current->data;
		draw_lines(widget, xyplot, data);
		draw_points(widget, xyplot, data);
  	}
  
}
/****************************************************************************************/
static void draw_plotting_area(GtkWidget *widget, GabeditXYPlot *xyplot)
{
	gdk_draw_drawable (widget->window, 
			xyplot->back_gc, 
			xyplot->plotting_area, 
			0, 
			0, 
			xyplot->plotting_rect.x, 
			xyplot->plotting_rect.y, 
			xyplot->plotting_rect.width, 
			xyplot->plotting_rect.height);

}
/****************************************************************************************/
static gint gabedit_xyplot_expose (GtkWidget *widget, GdkEventExpose *event)
{
	GabeditXYPlot *xyplot;

	g_return_val_if_fail (widget != NULL, FALSE);
	g_return_val_if_fail (GABEDIT_IS_XYPLOT (widget), FALSE);
	g_return_val_if_fail (event != NULL, FALSE);

	if (event->count > 0) return FALSE;
    
	xyplot=GABEDIT_XYPLOT(widget);

	draw_background(widget, xyplot);
	draw_data(widget, xyplot);
	draw_plotting_area(widget, xyplot);
 
	draw_zoom_rectangle(widget, xyplot);
        
	draw_borders(widget, xyplot);
	
	draw_hminor_ticks(widget, xyplot);
	draw_hmajor_ticks_and_xlegends(widget, xyplot);
	draw_hminor_grid(widget, xyplot);
	draw_hmajor_grid(widget, xyplot);

	draw_vminor_ticks(widget, xyplot);
	draw_vmajor_ticks_and_ylegends(widget, xyplot);
	draw_vminor_grid(widget, xyplot);
	draw_vmajor_grid(widget, xyplot);

	return 0;
}
/****************************************************************************************/
static gint get_distance_M_AB(GabeditXYPlot *xyplot,gint xM, gint yM, gint ixA, gint iyA, gint ixB, gint iyB)
{
	gdouble xA = ixA;
	gdouble yA = iyA;
	gdouble xB = ixB;
	gdouble yB = iyB;
	gdouble xAB = xB -xA;
	gdouble yAB = yB -yA;
	gdouble AB2 = xAB*xAB + yAB*yAB;
	gdouble xMA;
	gdouble yMA;
	gdouble MA2;
	gdouble xMB;
	gdouble yMB;
	gdouble MB2;
	gdouble xC;
	gdouble yC;
	gdouble xMC;
	gdouble yMC;
	gdouble MC2;

	do{
		xMA = xA -xM;
		yMA = yA -yM;
		MA2 = xMA*xMA + yMA*yMA;
		xMB = xB -xM;
		yMB = yB -yM;
		MB2 = xMB*xMB + yMB*yMB;
		xC = (xA + xB)/2.0;
		yC = (yA + yB)/2.0;
		xMC = xC - xM;
		yMC = yC - yM;
		MC2 = xMC*xMC + yMC*yMC;
		if(MA2>MB2)
		{
			if(MC2<MA2)
			{
				xA = xC;
				yA = yC;
			}
			else
			{
				xB = xC;
				yB = yC;
			}
		}
		else
		{
			if(MC2<MB2)
			{
				xB = xC;
				yB = yC;
			}
			else
			{
				xA = xC;
				yA = yC;
			}
		}
		xAB = xB -xA;
		yAB = yB -yA;
		AB2 = xAB*xAB + yAB*yAB;
	}while(AB2>1);
	return (gint)sqrt(MC2);
}
/****************************************************************************************/
static gint gabedit_xyplot_double_click (GtkWidget *widget, GdkEventButton *event)
{
  	XYPlotData *data; 
	GList* current = NULL;
	guint x;
	guint y;
	gboolean OK = FALSE;
	GabeditXYPlot *xyplot = NULL;
	gint loop;
	guint xOld;
	guint yOld;

  	xyplot=GABEDIT_XYPLOT(widget);

	if(!(xyplot->data_list)) return TRUE;
	current=g_list_first(xyplot->data_list);
	for(; current != NULL; current = current->next)
	{
		data = (XYPlotData*)current->data;
		xOld = 0;
		yOld = 0;
		for(loop=0;loop<data->size;loop++)
		{
    			value2pixel(xyplot, data->x[loop], data->y[loop], &x, &y);
			y=xyplot->plotting_rect.height-y;
			x += xyplot->plotting_rect.x;
			y += xyplot->plotting_rect.y;
			if(loop ==0 && abs(x-event->x)<5 && abs(y-event->y)<5)
			{
				OK = TRUE;
				break;
			}
			if(loop >0 && get_distance_M_AB(xyplot,(gint)event->x, (gint)event->y,  (gint)xOld, (gint)yOld, (gint)x, (gint)y)<5)
			{
				OK = TRUE;
				break;
			}
			xOld = x;
			yOld = y;
		}
		if(OK) break;
	}
	if(OK)
	{
		set_data_dialog(xyplot,data);
	}
	return OK;
}
/*********************************************************************************************************************/
static gboolean popuo_menu(GtkWidget* widget, guint button, guint32 time)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (widget), "Manager");
	GtkWidget *menu = gtk_ui_manager_get_widget (manager, "/MenuXYPlot");
	if (GTK_IS_MENU (menu)) 
	{
		gtk_menu_popup (GTK_MENU (menu), NULL, NULL, NULL, NULL, button, time);
		return TRUE;
	}
	else 
	{
		g_message ("popup menu of xyplot failed");
	}
	return FALSE;
}
/****************************************************************************************/
static gint gabedit_xyplot_button_press (GtkWidget *widget, GdkEventButton *event)
{
  GabeditXYPlot *xyplot;
  
  g_return_val_if_fail (widget != NULL, FALSE);
  g_return_val_if_fail (GABEDIT_IS_XYPLOT (widget), FALSE);
  g_return_val_if_fail (event != NULL, FALSE);

  xyplot = GABEDIT_XYPLOT (widget);
  if(event->type == GDK_2BUTTON_PRESS)
  {
	  xyplot->double_click = TRUE;
	  return gabedit_xyplot_double_click(widget,event);
  }
  if(event->button == 3)
  {
	  return popuo_menu(widget, event->button, event->time);
  }

  if (xyplot->mouse_zoom_enabled && (event->button == xyplot->mouse_zoom_button) )
    if ( (event->x > xyplot->plotting_rect.x) && 
         (event->x < (xyplot->plotting_rect.x + xyplot->plotting_rect.width)) && 
         (event->y > xyplot->plotting_rect.y) && 
         (event->y < (xyplot->plotting_rect.y + xyplot->plotting_rect.height)) ){
      xyplot->mouse_button=event->button;
    
      xyplot->zoom_point.x=event->x;
      xyplot->zoom_point.y=event->y;
  }

  if (xyplot->mouse_displace_enabled && (event->button == xyplot->mouse_displace_button))
    if ( (event->x > xyplot->plotting_rect.x) && 
         (event->x < (xyplot->plotting_rect.x + xyplot->plotting_rect.width)) && 
         (event->y > xyplot->plotting_rect.y) && 
         (event->y < (xyplot->plotting_rect.y + xyplot->plotting_rect.height)) ){
      xyplot->mouse_button=event->button;
    
      xyplot->move_point.x=event->x;
      xyplot->move_point.y=event->y;
  } 

  if ( xyplot->mouse_autorange_enabled && 
      (event->button == xyplot->mouse_autorange_button) )
    gabedit_xyplot_set_autorange(xyplot, NULL);

   xyplot->double_click = FALSE;
  
  return FALSE;
}
/****************************************************************************************/
static gint gabedit_xyplot_button_release (GtkWidget *widget, GdkEventButton *event)
{
  GabeditXYPlot *xyplot;
  gdouble xmin, xmax, ymin, ymax;
  gint xleft, ytop, xright, ybottom; 
  
  g_return_val_if_fail (widget != NULL, FALSE);
  g_return_val_if_fail (GABEDIT_IS_XYPLOT (widget), FALSE);
  g_return_val_if_fail (event != NULL, FALSE);

  xyplot = GABEDIT_XYPLOT (widget);

   if ( !xyplot->double_click && xyplot->mouse_zoom_enabled && 
       (event->button == xyplot->mouse_zoom_button) && 
       (xyplot->mouse_button == xyplot->mouse_zoom_button)){

    xleft=xyplot->zoom_rect.x-xyplot->plotting_rect.x;
    xright=xyplot->zoom_rect.x+xyplot->zoom_rect.width-xyplot->plotting_rect.x;
    ybottom=xyplot->plotting_rect.y+xyplot->plotting_rect.height-xyplot->zoom_rect.y-xyplot->zoom_rect.height;
    ytop=xyplot->plotting_rect.y+xyplot->plotting_rect.height-xyplot->zoom_rect.y;
        
    pixel2value(xyplot, xleft, ybottom, &xmin, &ymin);
    pixel2value(xyplot, xright, ytop, &xmax, &ymax);

    if(xyplot->reflect_x)
    {
	    gdouble a = xmin;
	    xmin = xmax;
	    xmax = a;
    }
    if(xyplot->reflect_y)
    {
	    gdouble a = ymin;
	    ymin = ymax;
	    ymax = a;
    }
  
    gabedit_xyplot_set_range(xyplot, xmin, xmax, ymin, ymax);
    
    xyplot->mouse_button=0;
  }

  if (xyplot->mouse_displace_enabled && 
      (event->button == xyplot->mouse_displace_button) && 
      (xyplot->mouse_button == xyplot->mouse_displace_button) ){
    xyplot->mouse_button=0;
  }
    
  return FALSE;
}
/****************************************************************************************/
static gint gabedit_xyplot_motion_notify (GtkWidget *widget, GdkEventMotion *event)
{
  GabeditXYPlot *xyplot;
  guint x, y;
  gdouble px, py, mx, my;
  
  g_return_val_if_fail (widget != NULL, FALSE);
  g_return_val_if_fail (GABEDIT_IS_XYPLOT (widget), FALSE);
  g_return_val_if_fail (event != NULL, FALSE);

  xyplot = GABEDIT_XYPLOT (widget);

  x = event->x;
  y = event->y;
  
  if (event->is_hint || (event->window != widget->window))
      gdk_window_get_pointer (widget->window, (gint *)&x, (gint *)&y, NULL);

  if (xyplot->mouse_zoom_enabled && 
      (xyplot->mouse_button == xyplot->mouse_zoom_button) ){
    if (x < xyplot->plotting_rect.x)
      x=xyplot->plotting_rect.x;
       
    if(x > (xyplot->plotting_rect.x + xyplot->plotting_rect.width)) 
      x=(xyplot->plotting_rect.x + xyplot->plotting_rect.width);

    if (y < xyplot->plotting_rect.y)
      y=xyplot->plotting_rect.y;

    if (y > (xyplot->plotting_rect.y + xyplot->plotting_rect.height))
      y=(xyplot->plotting_rect.y + xyplot->plotting_rect.height);

    if (xyplot->zoom_point.x < x){
      xyplot->zoom_rect.x=xyplot->zoom_point.x;
      xyplot->zoom_rect.width=x-xyplot->zoom_point.x;
    }else{
      xyplot->zoom_rect.x=x;
      xyplot->zoom_rect.width=xyplot->zoom_point.x-x;
    }

    if (xyplot->zoom_point.y < y){
      xyplot->zoom_rect.y=xyplot->zoom_point.y;
      xyplot->zoom_rect.height=y-xyplot->zoom_point.y;
    }else{
      xyplot->zoom_rect.y=y;
      xyplot->zoom_rect.height=xyplot->zoom_point.y-y;
    }
    
    gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
  }

  if (xyplot->mouse_displace_enabled && (xyplot->mouse_button==xyplot->mouse_displace_button))
    if ( (x > xyplot->plotting_rect.x) && 
         (x < (xyplot->plotting_rect.width + xyplot->plotting_rect.x)) &&
         (y > xyplot->plotting_rect.y) && 
         (y < (xyplot->plotting_rect.height + xyplot->plotting_rect.y)) ){
      pixel2value(xyplot, xyplot->move_point.x, xyplot->move_point.y, &px, &py);
      pixel2value(xyplot, x, y, &mx, &my);
    
      gabedit_xyplot_set_range(xyplot, xyplot->xmin+(px-mx), xyplot->xmax+(px-mx), xyplot->ymin-(py-my), xyplot->ymax-(py-my)); 
      xyplot->move_point.x=x;
      xyplot->move_point.y=y;
  }

  return FALSE;
}
/****************************************************************************************/
static gint gabedit_xyplot_scroll (GtkWidget *widget, GdkEventScroll   *event)
{
  GabeditXYPlot *xyplot;
  gdouble x_range = 0.0, y_range = 0.0, 
          xmin = 0.0, xmax = 0.0, 
          ymin = 0.0, ymax = 0.0;

  g_return_val_if_fail (widget != NULL, FALSE);
  g_return_val_if_fail (GABEDIT_IS_XYPLOT (widget), FALSE);
  g_return_val_if_fail (event != NULL, FALSE);

  xyplot=GABEDIT_XYPLOT(widget);

  if (xyplot->wheel_zoom_enabled){
    if (event->direction==GDK_SCROLL_UP){
      x_range=xyplot->wheel_zoom_factor*(xyplot->xmax-xyplot->xmin);
      y_range=xyplot->wheel_zoom_factor*(xyplot->ymax-xyplot->ymin);
    }

    if (event->direction==GDK_SCROLL_DOWN){
      x_range=(xyplot->xmax-xyplot->xmin)/xyplot->wheel_zoom_factor;
      y_range=(xyplot->ymax-xyplot->ymin)/xyplot->wheel_zoom_factor;
    }
 
    xmin=xyplot->xmin+((xyplot->xmax-xyplot->xmin)/2.0)-(x_range/2.0);
    xmax=xyplot->xmin+((xyplot->xmax-xyplot->xmin)/2.0)+(x_range/2.0);
     
    ymin=xyplot->ymin+((xyplot->ymax-xyplot->ymin)/2.0)-(y_range/2.0);
    ymax=xyplot->ymin+((xyplot->ymax-xyplot->ymin)/2.0)+(y_range/2.0);

    gabedit_xyplot_set_range(xyplot, xmin, xmax, ymin, ymax);
  }  
  return TRUE;
}
/****************************************************************************************/
static void gabedit_xyplot_style_set (GtkWidget *widget, GtkStyle *previous_style)
{
  GabeditXYPlot *xyplot;
  
  g_return_if_fail (widget != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (widget));
  
  xyplot = GABEDIT_XYPLOT (widget);
  
  xyplot_calculate_legends_sizes(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_range (GabeditXYPlot *xyplot, gdouble xmin, gdouble xmax, gdouble ymin, gdouble ymax)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if (xmin < xmax){
    xyplot->xmin=xmin;
    xyplot->xmax=xmax;
  }
  
  if (ymin < ymax){
    xyplot->ymin=ymin;
    xyplot->ymax=ymax;
  }
   
  xyplot_free_legends(xyplot);
  xyplot_build_legends(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_range_xmin (GabeditXYPlot *xyplot, gdouble xmin)
{
	gabedit_xyplot_set_range(xyplot, xmin,  xyplot->xmax, xyplot->ymin , xyplot->ymax);
}
/****************************************************************************************/
void gabedit_xyplot_set_range_xmax (GabeditXYPlot *xyplot, gdouble xmax)
{
	gabedit_xyplot_set_range(xyplot, xyplot->xmin,  xmax, xyplot->ymin , xyplot->ymax);
}
/****************************************************************************************/
void gabedit_xyplot_set_range_ymin (GabeditXYPlot *xyplot, gdouble ymin)
{
	gabedit_xyplot_set_range(xyplot, xyplot->xmin,  xyplot->xmax, ymin , xyplot->ymax);
}
/****************************************************************************************/
void gabedit_xyplot_set_range_ymax (GabeditXYPlot *xyplot, gdouble ymax)
{
	gabedit_xyplot_set_range(xyplot, xyplot->xmin,  xyplot->xmax, xyplot->ymin , ymax);
}
/****************************************************************************************/
void gabedit_xyplot_set_autorange (GabeditXYPlot *xyplot, XYPlotData *data)
{
  guint loop, loop2;
  gdouble xmax, xmin, ymax, ymin;
  gdouble dx, dy; 
  XYPlotData *current_data; 
  GList *current_node; 
 
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
   
  xmax=1.0;
  xmin=-1.0;
  ymax=1.0;
  ymin=-1.0;

  if (data!=NULL){ 
    xmax=data->x[0];
    xmin=data->x[0];
    ymax=data->y[0];
    ymin=data->y[0];
    for (loop=1; loop<data->size; loop++){
      if (data->x[loop] > xmax)
        xmax=data->x[loop];
      if (data->x[loop] < xmin)
        xmin=data->x[loop];
      if (data->y[loop] > ymax)
        ymax=data->y[loop];
      if (data->y[loop] < ymin)
        ymin=data->y[loop];
    }
  }

  if ( (data == NULL) && xyplot->data_list ){
    current_node=g_list_first(xyplot->data_list);
    current_data=(XYPlotData*)current_node->data;  
    xmin=current_data->x[0];
    xmax=current_data->x[0]; 
    ymin=current_data->y[0];
    ymax=current_data->y[0];
    for (; current_node!=NULL; current_node=current_node->next)
    {
        current_data=(XYPlotData*)current_node->data;  
      for (loop2=0; loop2<current_data->size; loop2++){
        if (xmin > current_data->x[loop2])
          xmin=current_data->x[loop2];
        if (xmax < current_data->x[loop2])
          xmax=current_data->x[loop2];
        if (ymin > current_data->y[loop2])
          ymin=current_data->y[loop2];
        if (ymax < current_data->y[loop2])
          ymax=current_data->y[loop2];
      }
    }
  }

  dx=fabs(xmax-xmin);
  dy=fabs(ymax-ymin);
  xmin=xmin-dx*0.1;
  xmax=xmax+dx*0.1;
  ymin=ymin-dy*0.1;
  ymax=ymax+dy*0.1;
  
  xyplot->xmin=xmin;
  xyplot->xmax=xmax;
  xyplot->ymin=ymin;
  xyplot->ymax=ymax;

  xyplot_free_legends(xyplot);
  xyplot_build_legends(xyplot);  
  xyplot_calculate_sizes(xyplot);

  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_get_range (GabeditXYPlot *xyplot, gdouble *xmin, gdouble *xmax, gdouble *ymin, gdouble *ymax)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if (xmin!=NULL)
    *xmin=xyplot->xmin;
  if (xmax!=NULL)
    *xmax=xyplot->xmax;
  if (ymax!=NULL)
    *ymax=xyplot->ymax;
  if (ymin!=NULL)
    *ymin=xyplot->ymin;
}
/****************************************************************************************/
void gabedit_xyplot_get_point (GabeditXYPlot *xyplot, guint x, guint y, gdouble *xv, gdouble *yv)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if ((x < xyplot->plotting_rect.x) || 
      (x > (xyplot->plotting_rect.x + xyplot->plotting_rect.width)) || 
      (y < xyplot->plotting_rect.y) || 
      (y > (xyplot->plotting_rect.y + xyplot->plotting_rect.height))) {
    xv=yv=NULL;
    return;
  }
  
  x=x-xyplot->plotting_rect.x;
  y=xyplot->plotting_rect.y+xyplot->plotting_rect.height-y; 
  
  pixel2value(xyplot, x, y, xv, yv);
}
/****************************************************************************************/
void gabedit_xyplot_set_ticks (GabeditXYPlot *xyplot, guint hmajor, guint hminor, guint vmajor, guint vminor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  xyplot_free_legends(xyplot);

  xyplot->hmajor_ticks=hmajor;
  xyplot->hminor_ticks=hminor;
  xyplot->vmajor_ticks=vmajor;
  xyplot->vminor_ticks=vminor;
    
  xyplot_build_legends(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_ticks_hmajor (GabeditXYPlot *xyplot, guint hmajor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  xyplot_free_legends(xyplot);

  xyplot->hmajor_ticks=hmajor;
    
  xyplot_build_legends(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_ticks_hminor (GabeditXYPlot *xyplot, guint hminor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  xyplot_free_legends(xyplot);

  xyplot->hminor_ticks=hminor;
    
  xyplot_build_legends(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_ticks_vmajor (GabeditXYPlot *xyplot, guint vmajor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  xyplot_free_legends(xyplot);

  xyplot->vmajor_ticks=vmajor;
    
  xyplot_build_legends(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_ticks_vminor (GabeditXYPlot *xyplot, guint vminor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  xyplot_free_legends(xyplot);

  xyplot->vminor_ticks=vminor;
    
  xyplot_build_legends(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_get_ticks (GabeditXYPlot *xyplot, guint *hmajor, guint *hminor, guint *vmajor, guint *vminor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if (hmajor!=NULL)
    *hmajor=xyplot->hmajor_ticks;
  if (hminor!=NULL)
    *hminor=xyplot->hminor_ticks;
  if (vmajor!=NULL)
    *vmajor=xyplot->vmajor_ticks;
  if (vminor!=NULL)
    *vminor=xyplot->vminor_ticks;
}
/****************************************************************************************/
void gabedit_xyplot_set_x_legends_digits (GabeditXYPlot *xyplot, guint digits)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if (digits != xyplot->x_legends_digits){
    xyplot_free_legends(xyplot);
  
    xyplot->x_legends_digits=digits;
  
    xyplot_build_legends(xyplot);
    xyplot_calculate_legends_sizes(xyplot);
    xyplot_calculate_sizes(xyplot);
    gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
  }
}
/****************************************************************************************/
void gabedit_xyplot_set_y_legends_digits (GabeditXYPlot *xyplot, guint digits)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if (digits != xyplot->y_legends_digits){
    xyplot_free_legends(xyplot);
  
    xyplot->y_legends_digits=digits;
  
    xyplot_build_legends(xyplot);
    xyplot_calculate_legends_sizes(xyplot);
    xyplot_calculate_sizes(xyplot);
    gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
  }
}
/****************************************************************************************/
guint gabedit_xyplot_get_x_legends_digits (GabeditXYPlot *xyplot)
{
  g_return_val_if_fail (xyplot != NULL, 0);
  g_return_val_if_fail (GABEDIT_IS_XYPLOT (xyplot), 0);
  
  return(xyplot->x_legends_digits);
}
/****************************************************************************************/
guint gabedit_xyplot_get_y_legends_digits (GabeditXYPlot *xyplot)
{
  g_return_val_if_fail (xyplot != NULL, 0);
  g_return_val_if_fail (GABEDIT_IS_XYPLOT (xyplot), 0);
  
  return(xyplot->y_legends_digits);
}
/****************************************************************************************/
void gabedit_xyplot_set_background_color (GabeditXYPlot *xyplot, GdkColor color)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));

  gdk_gc_set_rgb_fg_color(xyplot->back_gc, &color);

  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_grids_attributes (GabeditXYPlot *xyplot, 
			GabeditXYPlotGrid grid, 
			GdkColor color, 
			gint line_width, 
			GdkLineStyle line_style)
{
  GdkGC *gc;

  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  switch (grid){
    case GABEDIT_XYPLOT_HMAJOR_GRID:
      gc=xyplot->hmajor_grid_gc;  
    break;
    case GABEDIT_XYPLOT_HMINOR_GRID:
      gc=xyplot->hminor_grid_gc;
    break;
    case GABEDIT_XYPLOT_VMAJOR_GRID:
      gc=xyplot->vmajor_grid_gc;
    break;
    case GABEDIT_XYPLOT_VMINOR_GRID:
      gc=xyplot->vminor_grid_gc;
    break;
    default:
      return;
  }
  
  gdk_gc_set_rgb_fg_color(gc, &color);
  gdk_gc_set_line_attributes(gc, line_width, line_style, 0 ,0);
  
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_get_grids_attributes (GabeditXYPlot *xyplot, 
			GabeditXYPlotGrid grid, 
			GdkColor *color, 
			gint *line_width, 
			GdkLineStyle *line_style)
{
  GdkGC *gc;
  GdkGCValues gc_values;

  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  g_return_if_fail (color != NULL);
  g_return_if_fail (line_width != NULL);
  g_return_if_fail (line_style != NULL);
  
  switch (grid){
    case GABEDIT_XYPLOT_HMAJOR_GRID:
      gc=xyplot->hmajor_grid_gc;  
    break;
    case GABEDIT_XYPLOT_HMINOR_GRID:
      gc=xyplot->hminor_grid_gc;
    break;
    case GABEDIT_XYPLOT_VMAJOR_GRID:
      gc=xyplot->vmajor_grid_gc;
    break;
    case GABEDIT_XYPLOT_VMINOR_GRID:
      gc=xyplot->vminor_grid_gc;
    break;
    default:
      return;
  }
  
  gdk_gc_get_values(gc, &gc_values);
  
  *color=gc_values.foreground;
  *line_width=gc_values.line_width;
  *line_style=gc_values.line_style;
}
/****************************************************************************************/
static void xyplot_enable_grids (GabeditXYPlot *xyplot, GabeditXYPlotGrid grid, gboolean enable)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  switch (grid){
    case GABEDIT_XYPLOT_HMAJOR_GRID:
      xyplot->hmajor_grid=enable;  
    break;
    case GABEDIT_XYPLOT_HMINOR_GRID:
      xyplot->hminor_grid=enable;  
    break;
    case GABEDIT_XYPLOT_VMAJOR_GRID:
      xyplot->vmajor_grid=enable;  
    break;
    case GABEDIT_XYPLOT_VMINOR_GRID:
      xyplot->vminor_grid=enable;  
    break;
    default:
      return;
  }
  
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_enable_grids (GabeditXYPlot *xyplot, GabeditXYPlotGrid grid, gboolean enable)
{

	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = NULL;
	if(grid==GABEDIT_XYPLOT_HMAJOR_GRID)
		action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/HGridShowMajor");
	if(grid==GABEDIT_XYPLOT_HMINOR_GRID)
		action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/HGridShowMinor");
	if(grid==GABEDIT_XYPLOT_VMAJOR_GRID)
		action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/VGridShowMajor");
	if(grid==GABEDIT_XYPLOT_VMINOR_GRID)
		action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderGrid/VGridShowMinor");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
void gabedit_xyplot_add_data(GabeditXYPlot *xyplot, XYPlotData *data)
{
	g_return_if_fail (xyplot != NULL);
	g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
	g_return_if_fail (data != NULL);
  
	if (g_list_find (xyplot->data_list, (gpointer)data)==NULL)
	{
		xyplot->data_list=g_list_append(xyplot->data_list, (gpointer) data);
		data->point_pango = NULL;
		xyplot_build_points_data(GABEDIT_XYPLOT(xyplot), data);
	}
}
/****************************************************************************************/
void gabedit_xyplot_remove_data(GabeditXYPlot *xyplot, XYPlotData *data)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  g_return_if_fail (data != NULL);

  if (g_list_find (xyplot->data_list, (gpointer)data)!=NULL){
    xyplot->data_list=g_list_remove_all (xyplot->data_list, (gpointer) data);
  }
}

/****************************************************************************************/
void gabedit_xyplot_configure_mouse_zoom(GabeditXYPlot *xyplot, gboolean enabled, guint button)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));

  xyplot->mouse_zoom_enabled=enabled;
  xyplot->mouse_zoom_button=button;
}
/****************************************************************************************/
void gabedit_xyplot_configure_wheel_zoom(GabeditXYPlot *xyplot, gboolean enabled, gdouble factor)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));

  xyplot->wheel_zoom_enabled=enabled;
  xyplot->wheel_zoom_factor=factor;
}
/****************************************************************************************/
void gabedit_xyplot_configure_mouse_displace(GabeditXYPlot *xyplot, gboolean enabled, guint button)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));

  xyplot->mouse_displace_enabled=enabled;
  xyplot->mouse_displace_button=button;
}
/****************************************************************************************/
void gabedit_xyplot_configure_mouse_autorange(GabeditXYPlot *xyplot, gboolean enabled, guint button)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));

  xyplot->mouse_autorange_enabled=enabled;
  xyplot->mouse_autorange_button=button;
}
/********************************************************************************/
static guchar *get_rgb_image(GtkWidget* drawable)
{
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

	
	colormap = gdk_window_get_colormap(GTK_WIDGET(drawable)->window);
  	height = drawable->allocation.height;
  	width = drawable->allocation.width;
	rgbbuf=(guchar *) g_malloc(3*width*height*sizeof(guchar));

  	if(!colormap) return NULL;
	if(!rgbbuf) return NULL;
	
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
		        g_free(rgbbuf);
		      	return NULL;
	       }
	}
	return rgbbuf;
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
static void writeBMP(GabeditXYPlot *xyplot, gchar *fileName)
{       
  	guchar rgbtmp[3];
  	int pad;
	char bmp_header[]=
	{ 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0,
  	40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0, 0,0,0,0, 0,0,0,0,
  	0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0 };
	GtkWidget *drawable;

	FILE *file;
	int i;
	int j;
	int width;
	int height;
	guchar *rgbbuf;

        file = fopen(fileName,"wb");

        if (!file) return;

	drawable = GTK_WIDGET(xyplot);

	rgbbuf = get_rgb_image(drawable);
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
/****************************************************************************************/
static void writeTransparentPNG(GabeditXYPlot *xyplot, gchar *fileName)
{       
	GtkWidget* widget = GTK_WIDGET(xyplot);
	int width;
	int height;
	GError *error = NULL;
	GdkPixbuf  *pixbuf = NULL;
	width =  widget->allocation.width;
	height = widget->allocation.height;
	pixbuf = gdk_pixbuf_get_from_drawable(NULL, widget->window, NULL, 0, 0, 0, 0, width, height);
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
/****************************************************************************************/
void gabedit_xyplot_save(GabeditXYPlot *xyplot, gchar *fileName, gchar* type)
{       
	GtkWidget* widget = GTK_WIDGET(xyplot);
	int width;
	int height;
	GError *error = NULL;
	GdkPixbuf  *pixbuf = NULL;

	if(!strcmp(type,"bmp"))
	{
		writeBMP(xyplot, fileName);
		return;
	}
	if(!strcmp(type,"tpng"))
	{
		writeTransparentPNG(xyplot, fileName);
		return;
	}


	width =  widget->allocation.width;
	height = widget->allocation.height;
	pixbuf = gdk_pixbuf_get_from_drawable(NULL, widget->window, NULL, 0, 0, 0, 0, width, height);
	if(pixbuf)
	{
		gdk_pixbuf_save(pixbuf, fileName, type, &error, NULL);
	 	g_object_unref (pixbuf);
	}
}
/****************************************************************************************/
static void xyplot_calculate_sizes (GabeditXYPlot *xyplot)
{
  GtkWidget *widget;
  gint left = 10;
  gint right = 10;
  gint top = 5;
  gint bottom = 5;
  
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  widget = GTK_WIDGET(xyplot);
  left += 0.75*((gdouble)xyplot->legends_width);
  right += 0.75*((gdouble)xyplot->legends_width);
  top += 0.5*((gdouble)xyplot->legends_height);
  bottom += 0.5*((gdouble)xyplot->legends_height);
  if(xyplot->show_left_legends) left = 10+1.5*((gdouble)xyplot->legends_width)+1.0*((gdouble)xyplot->v_label_height);
  if(xyplot->show_right_legends) right = 10+1.5*((gdouble)xyplot->legends_width)+1.0*((gdouble)xyplot->v_label_height);
  if(xyplot->show_top_legends) top = 5+1.5*((gdouble)xyplot->legends_height)+1.0*((gdouble)xyplot->h_label_height);
  if(xyplot->show_bottom_legends) bottom = 5+1.5*((gdouble)xyplot->legends_height)+1.0*((gdouble)xyplot->h_label_height);

  xyplot->plotting_rect.x = left;
  xyplot->plotting_rect.y = top;
  
 
  xyplot->plotting_rect.width=widget->allocation.width  -left - right;

  xyplot->plotting_rect.height=widget->allocation.height  - top - bottom ;
  
  if (xyplot->hmajor_ticks>1){
    xyplot->d_hmajor=((gdouble)xyplot->plotting_rect.width)/((gdouble)xyplot->hmajor_ticks-1.0);
    xyplot->d_hminor=((gdouble)xyplot->d_hmajor)/((gdouble)xyplot->hminor_ticks+1.0);
  }
  
  if (xyplot->vmajor_ticks>1){
    xyplot->d_vmajor=((gdouble)xyplot->plotting_rect.height)/((gdouble)xyplot->vmajor_ticks-1.0);
    xyplot->d_vminor=((gdouble)xyplot->d_vmajor)/((gdouble)xyplot->vminor_ticks+1.0);
  }

  /* Creating the plotting area (everytime the plotting area's size is changed, the size of the pismap
     must be changed too, so, a new one, with the right size is created*/
  if (xyplot->plotting_area!=NULL) 
    g_object_unref(G_OBJECT(xyplot->plotting_area));
  if (GTK_WIDGET_REALIZED(widget)) 
    xyplot->plotting_area=gdk_pixmap_new(widget->window, xyplot->plotting_rect.width, xyplot->plotting_rect.height, -1);
}
/****************************************************************************************/
static void value2pixel(GabeditXYPlot *xyplot, gdouble xv, gdouble yv, guint *x, guint *y)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  *x=(xv-xyplot->xmin)*((gdouble)xyplot->plotting_rect.width)/(xyplot->xmax-xyplot->xmin);
  if(xyplot->reflect_x) *x = xyplot->plotting_rect.width - *x;

  *y=(yv-xyplot->ymin)*((gdouble)xyplot->plotting_rect.height)/(xyplot->ymax-xyplot->ymin);
  if(xyplot->reflect_y) *y = xyplot->plotting_rect.height - *y;
}
/****************************************************************************************/
static void pixel2value(GabeditXYPlot *xyplot, guint xp, guint yp, gdouble *x, gdouble *y)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  gdouble xxp = (gdouble)xp;
  gdouble yyp = (gdouble)yp;
  if(xyplot->reflect_x)  xxp = xyplot->plotting_rect.width-xxp;
  if(xyplot->reflect_y)  yyp = xyplot->plotting_rect.height-yyp;

    
  *x=xyplot->xmin+((gdouble)xxp)*(xyplot->xmax-xyplot->xmin)/((gdouble)xyplot->plotting_rect.width);
  *y=xyplot->ymin+((gdouble)yyp)*(xyplot->ymax-xyplot->ymin)/((gdouble)xyplot->plotting_rect.height);
}
/****************************************************************************************/
static void xyplot_calculate_legends_sizes(GabeditXYPlot *xyplot)
{
  GtkWidget *widget;
    
  g_return_if_fail (xyplot != NULL);
  
  widget=GTK_WIDGET(xyplot);

  if (xyplot->x_legends_digits==0 && xyplot->y_legends_digits==0){
    xyplot->legends_width=0;
    xyplot->legends_height=0;
    return;
  }

  if (xyplot->h_legends)
  {
    pango_layout_set_font_description (xyplot->h_legends[0], widget->style->font_desc);  
    pango_layout_get_size(xyplot->h_legends[0], &(xyplot->legends_width), &(xyplot->legends_height));
  }
  if (xyplot->v_legends)
  {
    pango_layout_set_font_description (xyplot->v_legends[0], widget->style->font_desc);  
    pango_layout_get_size(xyplot->v_legends[0], &(xyplot->legends_width), &(xyplot->legends_height));
  }

  xyplot->legends_width/=PANGO_SCALE;
  xyplot->legends_height/=PANGO_SCALE;

  xyplot->h_label_width = 0;
  xyplot->h_label_height =0;
  if (xyplot->h_label)
  {
    	pango_layout_set_font_description (xyplot->h_label, widget->style->font_desc);  
    	pango_layout_get_size(xyplot->h_label, &(xyplot->h_label_width), &(xyplot->h_label_height));
	xyplot->h_label_width /=PANGO_SCALE;
	xyplot->h_label_height /=PANGO_SCALE;
  }
  xyplot->v_label_width = 0;
  xyplot->v_label_height =0;
  if (xyplot->v_label)
  {
    	pango_layout_set_font_description (xyplot->v_label, widget->style->font_desc);  
    	pango_layout_get_size(xyplot->v_label, &(xyplot->v_label_width), &(xyplot->v_label_height));
	xyplot->v_label_width /=PANGO_SCALE;
	xyplot->v_label_height /=PANGO_SCALE;
  }
} 
/****************************************************************************************/
static void xyplot_build_legends(GabeditXYPlot *xyplot)
{
  GtkWidget *widget;
  gint loop;
  gchar *str;

  g_return_if_fail (xyplot != NULL);
  
  widget=GTK_WIDGET(xyplot);

  if ( (xyplot->hmajor_ticks > 1) && (xyplot->x_legends_digits != 0)){
    xyplot->d_hlegend=fabs(xyplot->xmax-xyplot->xmin)/((gdouble)xyplot->hmajor_ticks-1.0);

    xyplot->h_legends=g_new(PangoLayout*, xyplot->hmajor_ticks);
    str=g_malloc( (sizeof(gchar) * (xyplot->x_legends_digits+1)) );
    for (loop=0; loop<xyplot->hmajor_ticks; loop++){
      snprintf(str, xyplot->x_legends_digits+1, "%f", xyplot->xmin + (gdouble)loop*xyplot->d_hlegend);
      str[xyplot->x_legends_digits]='\0';
      xyplot->h_legends[loop]=gtk_widget_create_pango_layout (widget, str); 
    }
    g_free(str);
  }

  if ((xyplot->vmajor_ticks > 1) && (xyplot->y_legends_digits != 0) ){  
    xyplot->d_vlegend=fabs(xyplot->ymax-xyplot->ymin)/((gdouble)xyplot->vmajor_ticks-1.0);
 
    xyplot->v_legends=g_new(PangoLayout*, xyplot->vmajor_ticks);
    str=g_malloc( (sizeof(gchar) * (xyplot->y_legends_digits+1))); 
    for (loop=0; loop<xyplot->vmajor_ticks; loop++){
      snprintf(str, xyplot->y_legends_digits+1, "%f", xyplot->ymin + (gdouble)loop*xyplot->d_vlegend);
      str[xyplot->y_legends_digits]='\0';
      xyplot->v_legends[loop]=gtk_widget_create_pango_layout (widget, str); 
    }
    g_free(str);
  }
  if (xyplot->h_label_str)
  {
	  gchar *name = g_strconcat("<span>", xyplot->h_label_str, "</span>", NULL);
	  xyplot->h_label = gtk_widget_create_pango_layout (widget, xyplot->h_label_str);
	  pango_layout_set_markup(xyplot->h_label, name, -1);
	  g_free(name);
  }
  else
	  xyplot->h_label = NULL;
  if (xyplot->v_label_str)
  {
	  gchar *name = g_strconcat("<span>", xyplot->v_label_str, "</span>", NULL);
	  xyplot->v_label = gtk_widget_create_pango_layout (widget, xyplot->v_label_str);
	  pango_layout_set_markup(xyplot->v_label, name, -1);
	  g_free(name);
  }
  else 
	  xyplot->v_label = NULL;

  xyplot_calculate_legends_sizes(xyplot);
} 
/****************************************************************************************/
static void xyplot_free_legends(GabeditXYPlot *xyplot)
{
  gint loop;

  g_return_if_fail (xyplot != NULL);
    
  if (xyplot->h_legends!=NULL){
    for (loop=0; loop<xyplot->hmajor_ticks; loop++)
      if (xyplot->h_legends[loop]!=NULL)
        g_object_unref(G_OBJECT(xyplot->h_legends[loop]));
    g_free(xyplot->h_legends);
    xyplot->h_legends=NULL;    
  }

  if (xyplot->v_legends!=NULL){
    for (loop=0; loop<xyplot->vmajor_ticks; loop++)
      if (xyplot->v_legends[loop]!=NULL)
        g_object_unref(G_OBJECT(xyplot->v_legends[loop]));
    g_free(xyplot->v_legends);
    xyplot->v_legends=NULL;    
  }  
}
/****************************************************************************************/
static void xyplot_build_points_data(GabeditXYPlot *xyplot, XYPlotData *data)
{
	GtkWidget *widget;
	if (xyplot == NULL) return;
	if(xyplot->data_list == NULL) return;
  
	widget=GTK_WIDGET(xyplot);
	if(data->point_pango != NULL) g_object_unref(G_OBJECT(data->point_pango));
	data->point_pango = gtk_widget_create_pango_layout (widget, data->point_str);
	if(data->point_pango)
	{
		PangoRectangle logical_rect;
		pango_layout_set_justify(data->point_pango,TRUE);
		pango_layout_set_alignment(data->point_pango,PANGO_ALIGN_CENTER);
		pango_layout_set_alignment(data->point_pango,PANGO_ALIGN_LEFT);
		pango_layout_set_markup(data->point_pango, data->point_str, -1);
		gchar fontName[100];
		PangoAttrList *attr_list;
		PangoFontDescription *font_desc = NULL;
		sprintf(fontName,"sans %d",2+data->point_size*2);
		font_desc = pango_font_description_from_string (fontName);
    		pango_layout_set_font_description (data->point_pango, font_desc);  
		pango_layout_context_changed(data->point_pango);
		pango_layout_get_pixel_extents(data->point_pango, NULL, &logical_rect);
    		pango_layout_get_size(data->point_pango, &(data->point_width), &(data->point_height));
		data->point_width/=PANGO_SCALE;
		data->point_height/=PANGO_SCALE;
		/* printf("%d %d\n",logical_rect.x,logical_rect.y);*/
		data->point_width =logical_rect.width;
		data->point_height =logical_rect.height;
		pango_font_description_free (font_desc);
		/* set color */
		attr_list = pango_layout_get_attributes (data->point_pango);
		if (attr_list == NULL) attr_list = pango_attr_list_new ();
		else pango_attr_list_ref (attr_list);
		pango_attr_list_insert(attr_list,
				pango_attr_foreground_new(
					data->point_color.red, 
					data->point_color.green, 
					data->point_color.blue)
				);
		pango_layout_set_attributes (data->point_pango, attr_list);
		pango_attr_list_unref (attr_list);

	}
}
/****************************************************************************************/
static void xyplot_reflect_x (GabeditXYPlot *xyplot, gboolean reflection)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if(xyplot->reflect_x == reflection) return; 

  xyplot->reflect_x = reflection;
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_reflect_x (GabeditXYPlot *xyplot, gboolean enable)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderDirections/DirectionReflectX");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
static void xyplot_reflect_y (GabeditXYPlot *xyplot, gboolean reflection)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if(xyplot->reflect_y == reflection) return; 

  xyplot->reflect_y = reflection;
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_reflect_y (GabeditXYPlot *xyplot, gboolean enable)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderDirections/DirectionReflectY");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
static void xyplot_show_left_legends (GabeditXYPlot *xyplot, gboolean show)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if(xyplot->show_left_legends == show) return; 

  xyplot->show_left_legends = show; 
  xyplot_build_legends(xyplot);
  xyplot_calculate_legends_sizes(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_show_left_legends (GabeditXYPlot *xyplot, gboolean enable)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowLeft");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
static void xyplot_show_right_legends (GabeditXYPlot *xyplot, gboolean show)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if(xyplot->show_right_legends == show) return; 

  xyplot->show_right_legends = show; 
  xyplot_build_legends(xyplot);
  xyplot_calculate_legends_sizes(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_show_right_legends (GabeditXYPlot *xyplot, gboolean enable)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowRight");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
static void xyplot_show_top_legends (GabeditXYPlot *xyplot, gboolean show)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if(xyplot->show_top_legends == show) return; 

  xyplot->show_top_legends = show; 
  xyplot_build_legends(xyplot);
  xyplot_calculate_legends_sizes(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_show_top_legends (GabeditXYPlot *xyplot, gboolean enable)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowTop");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
static void xyplot_show_bottom_legends (GabeditXYPlot *xyplot, gboolean show)
{
  g_return_if_fail (xyplot != NULL);
  g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
  
  if(xyplot->show_bottom_legends == show) return; 

  xyplot->show_bottom_legends = show; 
  xyplot_build_legends(xyplot);
  xyplot_calculate_legends_sizes(xyplot);
  xyplot_calculate_sizes(xyplot);
  gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_show_bottom_legends (GabeditXYPlot *xyplot, gboolean enable)
{
	GtkUIManager *manager = g_object_get_data(G_OBJECT (xyplot), "Manager");
	GtkAction* action = gtk_ui_manager_get_action (manager, "/MenuXYPlot/Render/RenderLegends/LegendShowBottom");
	if(action) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action),enable);
}
/****************************************************************************************/
void gabedit_xyplot_set_font (GabeditXYPlot *xyplot, gchar* fontName)
{
	GtkWidget* widget = NULL;
	g_return_if_fail (xyplot != NULL);
	g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
	PangoFontDescription *font_desc = pango_font_description_from_string (fontName);

	widget=GTK_WIDGET(xyplot);

	if(font_desc)
	{
		xyplot->font_size =  xyplot_get_font_size (font_desc)/PANGO_SCALE;
		gtk_widget_modify_font (widget, font_desc);  
  		xyplot_build_legends(xyplot);
  		xyplot_calculate_legends_sizes(xyplot);
  		xyplot_calculate_sizes(xyplot);
		gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
	}
}
/****************************************************************************************/
void gabedit_xyplot_set_x_label (GabeditXYPlot *xyplot, G_CONST_RETURN gchar* str)
{
	GtkWidget* widget = NULL;
	g_return_if_fail (xyplot != NULL);
	g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
	widget=GTK_WIDGET(xyplot);

  	if(xyplot->h_label_str) g_free(xyplot->h_label_str);
	if(str && strlen(str)>0)
	{
		xyplot->h_label_str = g_strdup(str);
	}
	else
	{
		xyplot->h_label_str = NULL;
	}

  	xyplot_build_legends(xyplot);
  	xyplot_calculate_legends_sizes(xyplot);
  	xyplot_calculate_sizes(xyplot);
	gtk_widget_queue_draw(GTK_WIDGET(xyplot));  
}
/****************************************************************************************/
void gabedit_xyplot_set_y_label (GabeditXYPlot *xyplot, G_CONST_RETURN gchar* str)
{
	GtkWidget* widget = NULL;
	g_return_if_fail (xyplot != NULL);
	g_return_if_fail (GABEDIT_IS_XYPLOT (xyplot));
	widget=GTK_WIDGET(xyplot);

  	if(xyplot->v_label_str) g_free(xyplot->v_label_str);
	if(str && strlen(str)>0)
	{
		xyplot->v_label_str = g_strdup(str);
	}
	else
		xyplot->v_label_str = NULL;

  	xyplot_build_legends(xyplot);
  	xyplot_calculate_legends_sizes(xyplot);
  	xyplot_calculate_sizes(xyplot);
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

	gabedit_xyplot_get_point(GABEDIT_XYPLOT(xyplot), x, y, &xv, &yv);
	snprintf(str, 50, "Mouse position: %f, %f", xv, yv);
	context_id=gtk_statusbar_get_context_id (GTK_STATUSBAR(statusbar), "mouse position");
	gtk_statusbar_push (GTK_STATUSBAR(statusbar), context_id, str);
    
	return TRUE;
}
/****************************************************************************************/
GtkWidget* gabedit_xyplot_new_window(gchar* title, GtkWidget*parent)
{
	GtkWidget* window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
	GtkWidget* table = NULL;
	GtkWidget* box = NULL;
	GtkWidget* frame_xyplot = NULL;
	GtkWidget* xyplot = NULL;

	GtkWidget *statusbar = NULL;

	gtk_window_set_title (GTK_WINDOW (window), title);
	gtk_signal_connect (GTK_OBJECT (window), "delete_event", GTK_SIGNAL_FUNC (gtk_widget_destroy), NULL);
	gtk_container_set_border_width (GTK_CONTAINER (window), 10);
	gtk_window_set_default_size (GTK_WINDOW(window),2*gdk_screen_width()/3,2*gdk_screen_height()/3);
	
	table=gtk_table_new(3, 1, FALSE);
	gtk_container_add(GTK_CONTAINER(window), table);
	gtk_widget_show(table);
  
	frame_xyplot=gtk_frame_new("XY GabeditPlot");
	gtk_table_attach(GTK_TABLE(table), frame_xyplot, 0, 1, 0, 1, GTK_EXPAND | GTK_FILL, GTK_EXPAND | GTK_FILL, 0, 0);
	gtk_widget_show(frame_xyplot);
  
	xyplot = gabedit_xyplot_new();
	gtk_container_add(GTK_CONTAINER(frame_xyplot), xyplot);
	gtk_widget_show (xyplot);

	g_object_set_data (G_OBJECT (window), "XYPLOT",xyplot);

	box=gtk_hbox_new(FALSE,0);
	gtk_table_attach(GTK_TABLE(table), box, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 5, 5);
	gtk_widget_show (box);
	g_object_set_data(G_OBJECT (xyplot), "Box", box);

	statusbar=gtk_statusbar_new();
	gtk_table_attach(GTK_TABLE(table), statusbar, 0, 1, 2, 3, GTK_FILL, GTK_FILL, 5, 5);
	gtk_widget_show (statusbar);
	g_object_set_data(G_OBJECT (xyplot), "StatusBar", statusbar);

        gabedit_xyplot_set_range(GABEDIT_XYPLOT(xyplot),  0.0,  10,  0,  20);
	gabedit_xyplot_set_x_legends_digits(GABEDIT_XYPLOT(xyplot), 5);
	gabedit_xyplot_set_y_legends_digits(GABEDIT_XYPLOT(xyplot), 5);


	gtk_widget_show (window);

	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_HMAJOR_GRID, FALSE);
	gabedit_xyplot_enable_grids (GABEDIT_XYPLOT(xyplot), GABEDIT_XYPLOT_VMAJOR_GRID, FALSE);
	gabedit_xyplot_show_top_legends (GABEDIT_XYPLOT(xyplot),FALSE);
	gabedit_xyplot_show_right_legends (GABEDIT_XYPLOT(xyplot),FALSE);

	g_signal_connect_after(G_OBJECT(xyplot), "motion-notify-event", G_CALLBACK(xyplot_motion_notify_event), NULL);

	g_object_set_data(G_OBJECT (xyplot), "Window", window);
	g_object_set_data(G_OBJECT (window), "Box", box);

	gabedit_xyplot_set_font (GABEDIT_XYPLOT(xyplot), "sans 10");
	if(parent) gtk_window_set_transient_for(GTK_WINDOW(window),GTK_WINDOW(parent));

	return window;
}
