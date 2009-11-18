/* GabeditXYPlot.h */
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

#ifndef __GABEDIT_GABEDITXYPLOT_H__
#define __GABEDIT_GABEDITXYPLOT_H__



#include <gdk/gdk.h>
#include <gtk/gtkwidget.h>

G_BEGIN_DECLS

typedef enum
{
  GABEDIT_XYPLOT_HMAJOR_GRID,
  GABEDIT_XYPLOT_HMINOR_GRID,
  GABEDIT_XYPLOT_VMAJOR_GRID,
  GABEDIT_XYPLOT_VMINOR_GRID
} GabeditXYPlotGrid;

typedef enum
{
  GABEDIT_XYPLOT_CONV_NONE,
  GABEDIT_XYPLOT_CONV_LORENTZ,
  GABEDIT_XYPLOT_CONV_GAUSS
} GabeditXYPlotConvType;


#define GABEDIT_TYPE_XYPLOT                 (gabedit_xyplot_get_type ())
#define GABEDIT_XYPLOT(obj)                 (G_TYPE_CHECK_INSTANCE_CAST ((obj), GABEDIT_TYPE_XYPLOT, GabeditXYPlot))
#define GABEDIT_XYPLOT_CLASS(klass)         (G_TYPE_CHECK_CLASS_CAST ((klass), GABEDIT_TYPE_XYPLOT, GabeditXYPlotClass))
#define GABEDIT_IS_XYPLOT(obj)              (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GABEDIT_TYPE_XYPLOT))
#define GABEDIT_IS_XYPLOT_CLASS(klass)      (G_TYPE_CHECK_CLASS_TYPE ((klass), GABEDIT_TYPE_XYPLOT))
#define GABEDIT_XYPLOT_GET_CLASS(obj)       (G_TYPE_INSTANCE_GET_CLASS ((obj), GABEDIT_TYPE_XYPLOT, GabeditXYPlotClass))

typedef struct 
{
  gdouble *x, *y;
  guint size;
  gchar point_str[100];
  PangoLayout* point_pango;
  guint point_size;
  gint point_width, point_height;
  guint line_width;
  GdkColor point_color, line_color;
  GdkLineStyle line_style;
}XYPlotData;

typedef struct _GabeditXYPlot        GabeditXYPlot;
typedef struct _GabeditXYPlotClass   GabeditXYPlotClass;

struct _GabeditXYPlot
{
  GtkWidget widget;
  gdouble xmin, xmax, ymin, ymax; 
  
  GdkPixmap *plotting_area; 
  GdkPixmap *old_area; 
  cairo_t *cairo_widget; 
  cairo_t *cairo_area; 
  cairo_t *cairo_export; 
  GdkRectangle plotting_rect;
  guint x_legends_digits; 
  guint y_legends_digits; 

  guint hmajor_ticks, hminor_ticks; 
  guint vmajor_ticks, vminor_ticks; 
  gdouble d_hmajor, d_hminor; 
  gdouble d_vmajor, d_vminor; 
  
  gdouble d_hlegend, d_vlegend; 
  
  GdkGC *back_gc; 
  
  PangoLayout **h_legends;
  PangoLayout **v_legends;

  gchar** h_legends_str;
  gchar** v_legends_str;
  
  gint legends_width;
  gint legends_height;

  gchar *h_label_str;
  gchar *v_label_str;
  PangoLayout *h_label;
  PangoLayout *v_label;
  gint h_label_width;
  gint h_label_height;
  gint v_label_width;
  gint v_label_height;
  
  GdkGC *hmajor_grid_gc;
  GdkGC *hminor_grid_gc;
  GdkGC *vmajor_grid_gc;
  GdkGC *vminor_grid_gc;

  gboolean hmajor_grid;
  gboolean hminor_grid;
  gboolean vmajor_grid;
  gboolean vminor_grid; 

  gboolean show_left_legends;
  gboolean show_right_legends;
  gboolean show_top_legends;
  gboolean show_bottom_legends;

  gboolean reflect_x;
  gboolean reflect_y;

  GList *data_list;
  
  GdkGC *data_gc;

  guint mouse_button; 
  
  gboolean mouse_zoom_enabled;
  gboolean mouse_distance_enabled;
  
  guint mouse_zoom_button;
  guint mouse_distance_button;
  
  GdkPoint zoom_point;
  GdkPoint distance_point;
  
  GdkRectangle zoom_rect;
  GdkRectangle distance_rect;

  gboolean mouse_displace_enabled;
  guint mouse_displace_button;
  GdkPoint move_point;

  gboolean wheel_zoom_enabled;
  gdouble wheel_zoom_factor;

  gboolean mouse_autorange_enabled;
  guint mouse_autorange_button;
  gint font_size;
  gboolean double_click;

  gboolean shift_key_pressed;
  gboolean control_key_pressed;
};

struct _GabeditXYPlotClass
{
  GtkWidgetClass parent_class;
};

GtkWidget*     gabedit_xyplot_new ();
GType          gabedit_xyplot_get_type ();
void gabedit_xyplot_set_range (GabeditXYPlot *xyplot, gdouble xmin, gdouble xmax, gdouble ymin, gdouble ymax);    
void gabedit_xyplot_set_range_xmin (GabeditXYPlot *xyplot, gdouble xmin);
void gabedit_xyplot_set_range_xmax (GabeditXYPlot *xyplot, gdouble xmax);
void gabedit_xyplot_set_range_ymin (GabeditXYPlot *xyplot, gdouble ymin);
void gabedit_xyplot_set_range_ymax (GabeditXYPlot *xyplot, gdouble ymax);
void gabedit_xyplot_set_autorange (GabeditXYPlot *xyplot, XYPlotData *data);    
void gabedit_xyplot_get_range (GabeditXYPlot *xyplot, gdouble *xmin, gdouble *xmax, gdouble *ymin, gdouble *ymax);
gboolean gabedit_xyplot_get_point (GabeditXYPlot *xyplot, guint x, guint y, gdouble *xv, gdouble *yv);
void gabedit_xyplot_set_ticks (GabeditXYPlot *xyplot, guint hmajor, guint hminor, guint vmajor, guint vminor);
void gabedit_xyplot_set_ticks_hmajor (GabeditXYPlot *xyplot, guint hmajor);
void gabedit_xyplot_set_ticks_hminor (GabeditXYPlot *xyplot, guint hminor);
void gabedit_xyplot_set_ticks_vmajor (GabeditXYPlot *xyplot, guint vmajor);
void gabedit_xyplot_set_ticks_vminor (GabeditXYPlot *xyplot, guint vminor);
void gabedit_xyplot_get_ticks (GabeditXYPlot *xyplot, guint *hmajor, guint *hminor, guint *vmajor, guint *vminor);
void gabedit_xyplot_set_x_legends_digits (GabeditXYPlot *xyplot, guint digits);
void gabedit_xyplot_set_y_legends_digits (GabeditXYPlot *xyplot, guint digits);
guint gabedit_xyplot_get_x_legends_digits (GabeditXYPlot *xyplot);
guint gabedit_xyplot_get_y_legends_digits (GabeditXYPlot *xyplot);
void gabedit_xyplot_set_background_color (GabeditXYPlot *xyplot, GdkColor color); 
void gabedit_xyplot_set_grids_attributes (GabeditXYPlot *xyplot, GabeditXYPlotGrid grid, GdkColor color, gint line_width, GdkLineStyle line_style);
void gabedit_xyplot_get_grids_attributes (GabeditXYPlot *xyplot, GabeditXYPlotGrid grid, GdkColor *color, gint *line_width, GdkLineStyle *line_style);
void gabedit_xyplot_enable_grids (GabeditXYPlot *xyplot, GabeditXYPlotGrid grid, gboolean enable);
void gabedit_xyplot_add_data (GabeditXYPlot *xyplot, XYPlotData *data);
void gabedit_xyplot_remove_data (GabeditXYPlot *xyplot, XYPlotData *data);
void gabedit_xyplot_add_data_peaks(GabeditXYPlot *xyplot, gint numberOfPoints, gdouble* X,  gdouble* Y, GdkColor color);
void gabedit_xyplot_add_data_conv(GabeditXYPlot *xyplot, gint numberOfPoints, gdouble* X,  gdouble* Y, gdouble halfWidth,GabeditXYPlotConvType convType, GdkColor color);
void gabedit_xyplot_configure_mouse_zoom (GabeditXYPlot *xyplot, gboolean enabled, guint button);
void gabedit_xyplot_configure_mouse_distance (GabeditXYPlot *xyplot, gboolean enabled, guint button);
void gabedit_xyplot_configure_wheel_zoom (GabeditXYPlot *xyplot, gboolean enabled, gdouble factor);
void gabedit_xyplot_configure_mouse_displace (GabeditXYPlot *xyplot, gboolean enabled, guint button);
void gabedit_xyplot_configure_mouse_autorange (GabeditXYPlot *xyplot, gboolean enabled, guint button);
void gabedit_xyplot_save(GabeditXYPlot *xyplot, gchar *fileName, gchar* type);
void gabedit_xyplot_reflect_x (GabeditXYPlot *xyplot, gboolean reflection);
void gabedit_xyplot_reflect_y (GabeditXYPlot *xyplot, gboolean reflection);
void gabedit_xyplot_show_left_legends (GabeditXYPlot *xyplot, gboolean show);
void gabedit_xyplot_show_right_legends (GabeditXYPlot *xyplot, gboolean show);
void gabedit_xyplot_show_top_legends (GabeditXYPlot *xyplot, gboolean show);
void gabedit_xyplot_show_bottom_legends (GabeditXYPlot *xyplot, gboolean show);
void gabedit_xyplot_set_font (GabeditXYPlot *xyplot, gchar* fontName);
void gabedit_xyplot_set_x_label (GabeditXYPlot *xyplot, G_CONST_RETURN gchar* str);
void gabedit_xyplot_set_y_label (GabeditXYPlot *xyplot, G_CONST_RETURN gchar* str);
GtkWidget* gabedit_xyplot_new_window(gchar* title, GtkWidget*parent);
void gabedit_xyplot_help();

G_END_DECLS

#endif /* __GABEDIT_GABEDITXYPLOT_H__ */
