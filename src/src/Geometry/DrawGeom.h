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

#ifndef __GABEDIT_DRAWGEOM_H__
#define __GABEDIT_DRAWGEOM_H__

typedef enum
{
ROTATION,ROTATIONZ,TRANSMOVIE,CENTER,
SCALEGEOM,SCALESTICK,SCALEBALL,SCALEDIPOLE,
SELECTFRAG,SELECTRESIDUE,DELETEFRAG,MOVEFRAG,ROTLOCFRAG,ROTZLOCFRAG,INSERTATOM,
ADDFRAGMENT,
MESURE,SHOWMESURE,
RENDERSTICK,RENDERBALL,
LABELNO,LABELSYMB,LABELNUMB,LABELTYP,LABELLAYER,LABELSYMBNUMB,
LABELCHARGE,LABELSYMBCHARGE,LABELNUMBCHARGE,LABELCOORDINATES,
FXYZ,FMOL2,FTINKER,FPDB,FHIN,FGZMAT,FMZMAT,
FDALTONIN,FDALTONFIRST,FDALTONLAST,
FGAMESSIN,FGAMESSFIRST,FGAMESSLAST,
FGAUSSIN,FGAUSSOUTFIRST,FGAUSSOUTLAST,
FMOLCASIN,FMOLCASOUTFIRST, FMOLCASOUTLAST,
FMOLPROIN,FMOLPROOUTFIRST, FMOLPROOUTLAST,
FMPQCIN,FMPQCOUTFIRST, FMPQCOUTLAST,
FGEOMCONVDALTON,FGEOMCONVGAMESS,FGEOMCONVGAUSS,FGEOMCONVMOLPRO, FGEOMCONVMOLDEN,FGEOMCONVGABEDIT,FGEOMCONVMPQC, FGEOMCONVXYZ,
SAVEJPEG, SAVEPPM, SAVEBMP, SAVEPS
}GabEditGeomOperation;

typedef enum
{
 RECTANGLE,CIRCLE,ATOMS
}GabEditSelectType;

typedef enum
{
 LOW_LAYER=0, MEDIUM_LAYER, HIGH_LAYER
}GabEditLayerType;

typedef struct _Camera
{
 gdouble position;
 gdouble f;
}Camera;

typedef struct _GeomDef
{
 gdouble X;
 gdouble Y;
 gdouble Z;
 gdouble Charge;
 SAtomsProp Prop;
 gchar* Type;
 gchar* Residue;
 gint ResidueNumber;
 gint Xi;
 gint Yi;
 gushort Rayon;
 gdouble Coefpers;
 guint N;
 gboolean ColorAlloc;
 GabEditLayerType Layer;
 gboolean Variable;
}GeomDef;

typedef struct _CoordMaxMin
{
 gdouble Xmax;
 gdouble Xmin;
 gdouble Ymax;
 gdouble Ymin;
 gdouble Zmax;
 gdouble Zmin;
 gdouble Cmax;
}CoordMaxMin;

typedef struct _FragmentsItems
{
  gchar* Name;
  gchar* Menu;
  gint Num;
}FragmentsItems;

FragmentsItems *FragItems;
gint NFrags;

CoordMaxMin coordmaxmin;

GeomDef *geometry;
GeomDef *geometry0;
guint Natoms;

gint *NumFatoms;
guint NFatoms;

gdouble factor;
gdouble factorstick;
gdouble factorball;
gdouble factordipole;
gint TransX;
gint TransY;
GtkWidget *GeomDlg;
GtkWidget *StopButton;
gboolean StopCalcul;

gboolean StickMode;
gboolean ShadMode;
gboolean PersMode;
gboolean LightMode;
gboolean DrawDistance;
gboolean DrawDipole;
gboolean ShowDipole;
gboolean ShowHBonds;

#define NDIVDIPOLE 20
gdouble dipole[NDIVDIPOLE][3];
gdouble dipole0[NDIVDIPOLE][3];
gdouble dipole00[NDIVDIPOLE][3];
gint DXi[NDIVDIPOLE];
gint DYi[NDIVDIPOLE];
gint Ndipole[NDIVDIPOLE];
gchar* AtomToInsert;
gint NumSelAtoms[4];
gboolean Ddef;

gint get_connection_type(gint i, gint j);
void SelectFixedVariableAtoms(gboolean variable);
void set_fix_selected_atoms();
void set_variable_selected_atoms();
void messageAmberTypesDefine();
gboolean getShowMultipleBonds();
void RenderMultipleBonds(GtkWidget *win,gboolean show);
GabEditGeomOperation getOperationType();
void set_origin_to_center_of_fragment();
void set_xyz_to_principal_axes_of_selected_atoms(gpointer data, guint Operation,GtkWidget* wid);
void create_tolerance_window(GtkWidget*w, gpointer data);
void get_abelian_orientation_with_reduction(GtkWidget*w, gpointer data);
void get_standard_orientation_with_reduction(GtkWidget*w, gpointer data);
void setMMTypesCharges(gpointer data, guint Operation,GtkWidget* wid);
GeomDef* Free_One_Geom(GeomDef* geom,gint N);
void set_text_to_draw(gchar* str);
void set_statubar_operation_str(gchar* str);
GdkPixmap* get_drawing_pixmap();
GdkColormap* get_drawing_colormap();
guint label_option();
gboolean distances_draw_mode();
gboolean stick_mode();
gboolean pers_mode();
gboolean shad_mode();
gboolean light_mode();
gboolean hbond_connections(gint i, gint j);
gchar *get_distance(gint i,gint j);
gchar *get_angle(gint i,gint j,gint l);
gchar *get_dihedral(gint i,gint j,gint l,gint m);
void create_window_drawing();
void rafresh_drawing();
void draw_geometry(GtkWidget *,gpointer);
gboolean draw_lines_yes_no(guint i,guint j);
guint get_num_min_rayonIJ(guint i,guint j);
void SetRadioPopupMenu(gchar* button);
void HideShowMesure(gboolean hiding);
void ActivateButtonOperation (GtkWidget *widget, guint data);
void RenderStick();
void RenderBallStick();
gboolean dipole_draw_mode();
gboolean dipole_mode();
void CreateDrawMenu();
void TraitementGeom(gpointer data, guint Operation,GtkWidget* wid);
void SelectAllAtoms();
void InvertSelectionOfAtoms();
void unSelectAllAtoms();
void SelectLayerAtoms(GabEditLayerType layer);
void copySelectedAtoms();
void DeleteMolecule();
void SetOriginAtCenter(gpointer data, guint Operation,GtkWidget* wid);
void read_geometries_convergence(gpointer data, guint Operation,GtkWidget* wid);
void save_geometry(gpointer data, guint Operation,GtkWidget* wid);
void read_geometry(gpointer data, guint Operation,GtkWidget* wid);
void factor_default(GtkWidget *win,gpointer d);
void factor_stick_default(GtkWidget *win,gpointer d);
void factor_ball_default(GtkWidget *win,gpointer d);
void factor_dipole_default(GtkWidget *win,gpointer d);
void factor_all_default(GtkWidget *win,gpointer d);
void RenderShad(GtkWidget *,gboolean);
void RenderPers(GtkWidget *,gboolean);
void RenderLight(GtkWidget *,gboolean);
void RenderDipole(GtkWidget *,gboolean);
void RenderHBonds(GtkWidget *,gboolean);
void set_layer_of_selected_atoms(GabEditLayerType l);
void SetLabelDistances(GtkWidget *,gboolean);
void SetLabelDipole(GtkWidget *win,gboolean YesNo);
void initLabelOptions(guint data);
void SetLabelOptions(GtkWidget *widget, guint data);
void AddFragment(GtkWidget *widget, guint data);
void addAFragment(gchar* fragName);
void set_back_color_black();
void open_color_dlg(GtkWidget *win,gpointer *DrawingArea);
void to_postscript(GtkWidget *win, guint data);
void set_HBonds_dialog_geom(GtkWidget *win, guint data);
void set_povray_options_geom(GtkWidget *win, guint data);
void to_povray(GtkWidget *win, guint data);
void destroy_drawing_and_childs(GtkWidget *win,gpointer data);
void SetOperation(GtkWidget *,guint);
void set_dipole_from_charges();
void setPersonalFragment(Fragment F);
void unselect_all_atoms();

#endif /* __GABEDIT_DRAWGEOM_H__ */

