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

#ifndef __GABEDIT_RESULTSANALISE_H__
#define __GABEDIT_RESULTSANALISE_H__

typedef struct _DataGeomConv
{
	gint Npoint;
	gint Ntype;
	gchar *TypeCalcul; 
	gchar **TypeData; 
	gchar ***Data; 
	gint *NumGeom; 
	gchar *GeomFile; 
	GabEditTypeFile fileType; 
}DataGeomConv;
void set_sensitive_remote_frame(gboolean sensitive);
void create_bar_result(GtkWidget* Vbox);
DataGeomConv free_geom_conv(DataGeomConv);
void find_energy_gauss_molcas_molpro_mpqc(GtkWidget *wid,gpointer data);
void read_geometries_conv_dalton(GabeditFileChooser *SelecFile, gint response_id);
void read_geometries_conv_gaussian(GabeditFileChooser *SelecFile, gint response_id);
void read_geometries_conv_molpro(GabeditFileChooser *SelecFile, gint response_id);
void read_geometries_conv_gabedit(GabeditFileChooser *SelecFile, gint response_id);
void read_geometries_conv_molden(GabeditFileChooser *SelecFile, gint response_id);
void read_geometries_conv_mpqc(GabeditFileChooser *SelecFile, gint response_id);
void read_geometries_conv_xyz(GabeditFileChooser *SelecFile, gint response_id);

#endif /* __GABEDIT_RESULTSANALISE_H__ */

