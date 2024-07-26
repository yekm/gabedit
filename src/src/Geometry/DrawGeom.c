/* DrawGeom.c */
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
#include "../Geometry/Mesure.h"
#include "../Geometry/Postscript.h"
#include "../Geometry/Povray.h"
#include "../Common/Windows.h"
#include "../Utils/Transformation.h"
#include "../Geometry/GeomXYZ.h"
#include "../Geometry/GeomZmatrix.h"
#include "../Geometry/Symmetry.h"
#include "../Files/FileChooser.h"
#include "../Geometry/ImagesGeom.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/RotFragments.h"
#include "../Geometry/GeomConversion.h"
#include "../Geometry/ResultsAnalise.h"
#include "../Utils/HydrogenBond.h"
#include "../MolecularMechanics/PDBTemplate.h"
#include "../Symmetry/MoleculeSymmetryInterface.h"
#include "../Utils/Jacobi.h"
#include "../Geometry/MenuToolBarGeom.h"



static gfloat Quat[4] = {0.0,0.0,0.0,1.0};
static gfloat QuatFrag[4] = {0.0,0.0,0.0,1.0};
static gfloat QuatAtom[4] = {0.0,0.0,0.0,1.0};
static gfloat BeginX = 0;
static gfloat BeginY = 0;
static Camera camera = { 10,5};

static gfloat CSselectedAtom[3] = {0.0,0.0,0.0};
static gint NumSelectedAtom = -1;
static gint NumProcheAtom = -1;
static gboolean ButtonPressed = FALSE;
static gboolean ShiftKeyPressed = FALSE;

gchar* strToDraw = NULL;

static gboolean** Hconnections = NULL;
static gfloat minDistanceH = 1.50; /* in Agnstrom */
static gfloat maxDistanceH = 3.15; /* in Agnstrom */ 
static gfloat minAngleH = 145.0;
static gfloat maxAngleH = 215.0;

static gboolean** connections = NULL;

/********************************************************************************/
void set_statubar_pop_sel_atom();
void calcul_ndipole();
void redefine_dipole();
void dessine_dipole();
GtkWidget *AddNoteBookPage(GtkWidget *NoteBook,char *label);
void dessine();
void destroy_all_drawing(GtkWidget *win);
void ActivateButtonOperation (GtkWidget *widget, guint data);
void delete_selected_atoms();
gint unselected_atom(GdkEventButton *bevent);
static gint insert_atom(GtkWidget *widget,GdkEvent *event);
static gint insert_fragment(GtkWidget *widget,GdkEvent *event);
void define_good_factor();
void define_coefs_pers();
gboolean if_selected(gint Num);
gint index_selected(gint Num);
void sort_with_zaxis();
void define_geometry();
/********************************************************************************/
static  GdkGC* gc=NULL;
static	GdkColor* BackColor=NULL;
static GdkPixmap *pixmap = NULL;
static 	GtkWidget *NoteBookDraw;
static	GtkWidget *vboxmesure;
static gdouble TCOS[91],TSIN[91];
static gdouble CenterCoor[2];
static GtkWidget *vboxhandle;
static GtkWidget *StatusRotation = NULL;
static GtkWidget *StatusPopup = NULL;
static GtkWidget *StatusOperation = NULL;
static guint idStatusRotation = 0;
static guint idStatusPopup = 0;
static guint idStatusOperation = 0;
static GabEditGeomOperation OperationType = ROTATION;
static GabEditSelectType SelectType = RECTANGLE;
guint LabelOption = LABELNO;

static Fragment Frag = {0,NULL};

/*****************************************************************************/
GabEditGeomOperation getOperationType()
{
	return OperationType;
}
/*****************************************************************************/
gdouble get_real_distance2(GeomDef* g,gint i,gint j)
{
 	gdouble xx;
	gdouble d;

	xx = g[i].X-g[j].X;
	d = xx*xx;
	xx = g[i].Y-g[j].Y;
	d += xx*xx;
	xx = g[i].Z-g[j].Z;
	d += xx*xx;

	return d;
}
/*****************************************************************************/
static void free_connections()
{
	gint i;
	static gint oldNatoms = 0;
	if(!connections) return;
	for(i=0;i<oldNatoms;i++)
		if(connections[i]) g_free(connections[i]);
	g_free(connections);
	oldNatoms = Natoms;
}
/*****************************************************************************/
static void init_connections()
{
	gint i;
	gint j;
	if(Natoms<1) return;
	if(connections) free_connections();
	connections = g_malloc(Natoms*sizeof(gboolean*));
	for(i=0;i<(gint)Natoms;i++)
	{
		connections[i] = g_malloc(Natoms*sizeof(gboolean));
		for(j=0;j<(gint)Natoms;j++) connections[i][j] = FALSE;
	}
}
/*****************************************************************************/
static void set_connections()
{
	gint i;
	gint j;

	init_connections();
	for(i=0;i<(gint)Natoms;i++)
	{
		for(j=i+1;j<(gint)Natoms;j++)
		{
			connections[i][j] = draw_lines_yes_no(i,j);
			connections[j][i] = connections[i][j];
		}
	}
}
/*****************************************************************************/
static void free_Hconnections()
{
	gint i;
	static gint oldNatoms = 0;
	if(!Hconnections) return;
	for(i=0;i<oldNatoms;i++)
		if(Hconnections[i]) g_free(Hconnections[i]);
	g_free(Hconnections);
	oldNatoms = Natoms;
}
/*****************************************************************************/
static void init_Hconnections()
{
	gint i;
	gint j;
	if(Natoms<1) return;
	if(Hconnections) free_Hconnections();
	Hconnections = g_malloc(Natoms*sizeof(gboolean*));
	for(i=0;i<(gint)Natoms;i++)
	{
		Hconnections[i] = g_malloc(Natoms*sizeof(gboolean));
		for(j=0;j<(gint)Natoms;j++) Hconnections[i][j] = FALSE;
	}
}
/*****************************************************************************/
static void set_Hconnections()
{
	gint i;
	gint j;
	gint k;
	gboolean Ok;
	gdouble distance2;
	gdouble dx;
	gdouble dy;
	gdouble dz;
	gdouble angle;
	/* gchar* strDistance;*/
	gchar* strAngle;
	gdouble minDistanceH2;
	gdouble maxDistanceH2;
        Point A;
        Point B;

	minDistanceH = getMinDistanceHBonds();
	minDistanceH2 = minDistanceH*minDistanceH*ANG_TO_BOHR*ANG_TO_BOHR;

	maxDistanceH = getMaxDistanceHBonds();
	maxDistanceH2 = maxDistanceH*maxDistanceH*ANG_TO_BOHR*ANG_TO_BOHR;

	minAngleH = getMinAngleHBonds();
	maxAngleH = getMaxAngleHBonds();

	init_Hconnections();
	for(i=0;i<(gint)Natoms;i++)
	{
		Ok = FALSE;
		Ok = atomCanDoHydrogenBond(geometry[i].Prop.symbol);
		if(!Ok) continue;
		for(j=0;j<(gint)Natoms;j++)
		{
			if(connections[i][j]) continue;
			if(i==j) continue;
			if(strcmp(geometry[j].Prop.symbol, "H")!=0)continue;

			/*
			strDistance = get_distance(geometry[i].N,geometry[j].N);
			distance = atof(strDistance);
			if(strDistance) g_free(strDistance);
			if(distance<minDistanceH || distance>maxDistanceH) continue;
			*/
			dx = geometry[i].X-geometry[j].X;
			dy = geometry[i].Y-geometry[j].Y;
			dz = geometry[i].Z-geometry[j].Z;
			distance2 = (dx*dx+dy*dy+dz*dz);
			if(distance2<minDistanceH2 || distance2>maxDistanceH2) continue;


			Ok = FALSE;
			for(k=0;k<(gint)Natoms;k++)
			{
				if(k==j) continue;
				if(k==i) continue;
				if(!connections[j][k]) continue;
				/*
				strAngle = get_angle(geometry[i].N,geometry[j].N,geometry[k].N);
				angle = atof(strAngle);
				if(strAngle) g_free(strAngle);
				*/
				A.C[0]=geometry[i].X-geometry[j].X;
				A.C[1]=geometry[i].Y-geometry[j].Y;
				A.C[2]=geometry[i].Z-geometry[j].Z;
        
				B.C[0]=geometry[k].X-geometry[j].X;
				B.C[1]=geometry[k].Y-geometry[j].Y;
				B.C[2]=geometry[k].Z-geometry[j].Z;

        			strAngle = get_angle_vectors(A,B);
				angle = atof(strAngle);
				if(strAngle) g_free(strAngle);
				if(angle>=minAngleH &&angle<=maxAngleH)
				{
					Ok = TRUE;
					break;
				}
			}
			Hconnections[i][j] = Ok;
			Hconnections[j][i] = Ok;
		}
	}
}
/*****************************************************************************/
gboolean hbond_connections(gint i, gint j)
{

	if(ShowHBonds && Hconnections)
	{
		if(i<(gint)Natoms && j<(gint)Natoms && Hconnections[i]) return Hconnections[i][j];
		else return FALSE;
	}
	else return FALSE;
}
/*****************************************************************************/
void init_quat(gfloat quat[])
{
	gint i;
	for(i=0;i<3;i++) quat[i] = 0.0;
	quat[3] = 1.0;
}
/********************************************************************************/
static void set_origin_to_point(gdouble center[])
{
	gint n;
	for(n = 0;n<(gint)Natoms;n++)
	{
			geometry0[n].X -= center[0];
			geometry0[n].Y -= center[1];
			geometry0[n].Z -= center[2];

			geometry[n].X -= center[0];
			geometry[n].Y -= center[1];
			geometry[n].Z -= center[2];
	}
}
/********************************************************************************/
void set_origin_to_center_of_fragment()
{

	gdouble C[3] = {0,0,0};
	gint j = 0;
	gint i;
	for (i=0;i<(gint)Natoms;i++)
	{
		if(if_selected(i))
		{
			j++;
			C[0] += geometry[i].X;
			C[1] += geometry[i].Y;
			C[2] += geometry[i].Z;
		}
	}
	if(j==0) return;
	for (i=0;i<3;i++) C[i] /= j;
	set_origin_to_point(C);
	create_GeomXYZ_from_draw_grometry();
	TransX = 0;
	TransY = 0;
	dessine();
}
/********************************************************************************/
static void set_geom_to_axes(gdouble axis1[], gdouble axis2[], gdouble axis3[])
{
	gfloat **m0 = NULL;
	gfloat** minv;
	gint i,j;
	guint n;

	gdouble A[3];
	gdouble B[3];
	guint k;
	gdouble* X;
	gdouble* Y;
	gdouble* Z;

	if(Natoms<1) return;

	m0 = g_malloc(3*sizeof(gfloat*));
	X = g_malloc(Natoms*sizeof(gdouble));
	Y = g_malloc(Natoms*sizeof(gdouble));
	Z = g_malloc(Natoms*sizeof(gdouble));

	for(i=0;i<3;i++)
		m0[i] = g_malloc(3*sizeof(gfloat));


	m0[0][0] = axis1[0];
	m0[0][1] = axis1[1];
	m0[0][2] = axis1[2];

	m0[1][0] = axis2[0];
	m0[1][1] = axis2[1];
	m0[1][2] = axis2[2];

	m0[2][0] = axis3[0];
	m0[2][1] = axis3[1];
	m0[2][2] = axis3[2];

	minv = Inverse(m0,3,1e-7);

	for(n = 0;n<Natoms;n++)
	{
		A[0] = geometry[n].X;
		A[1] = geometry[n].Y;
		A[2] = geometry[n].Z;

		for(j=0;j<3;j++)
		{
			B[j] = 0.0;
			for(k=0;k<3;k++)
				B[j] += minv[k][j]*A[k];
		}

		X[n] = B[0];
		Y[n] = B[1];
		Z[n] = B[2];
	}
	for(n = 0;n<Natoms;n++)
	{
			geometry0[n].X = X[n];
			geometry0[n].Y = Y[n];
			geometry0[n].Z = Z[n];

			geometry[n].X = X[n];
			geometry[n].Y = Y[n];
			geometry[n].Z = Z[n];
	}
	
	for(i=0;i<3;i++) if(minv[i]) g_free(minv[i]);
	if(minv) g_free(minv);

	for(i=0;i<3;i++) if(m0[i]) g_free(m0[i]);
	if(m0) g_free(m0);

	if(X) g_free(X);
	if(Y) g_free(Y);
	if(Z) g_free(Z);
}
/********************************************************************************/
static int set_fragment_rotational_matrix(gdouble m[6], gdouble C[])
{
	gint i;
	gint ip;
	gint j;
	gint k;
	gdouble a;
	gdouble* XYZ[3];
	gdouble mt = 0;
	gint nFrag = 0;
	gint* numAtoms;

	for(i=0;i<3;i++)
	{
		XYZ[i] = g_malloc(Natoms*sizeof(gdouble));
		C[i] = 0.0;
	}
	numAtoms = g_malloc(Natoms*sizeof(gint));


	for(j=0;j<(gint)Natoms;j++)
	{
		if(if_selected(j))
		{
			numAtoms[nFrag] = j;
			mt += geometry[j].Prop.masse;
			XYZ[0][nFrag] = geometry[j].X;
			XYZ[1][nFrag] = geometry[j].Y;
			XYZ[2][nFrag] = geometry[j].Z;
			nFrag++;
		}
	}
	for(i=0;i<3;i++)
		for(j=0;j<nFrag;j++)
			C[i] += geometry[numAtoms[j]].Prop.masse*XYZ[i][j];
	if(mt != 0)
	for(i=0;i<3;i++) C[i] /= mt;

	for(j=0;j<nFrag;j++)
		for(i=0;i<3;i++)
			XYZ[i][j] -= C[i];
	
	k = 0;
	for(i=0;i<3;i++)
		for(ip=i;ip<3;ip++)
	{
		m[k] = 0.0;

		for(j=0;j<nFrag;j++)
		{
			if(i==ip)
			a = XYZ[(i+1)%3][j]*XYZ[(ip+1)%3][j]
			  + XYZ[(i+2)%3][j]*XYZ[(ip+2)%3][j];
			else
			{
				a =-XYZ[i][j]*XYZ[ip][j];
			}
			m[k] += geometry[numAtoms[j]].Prop.masse*a;
		}
		k++;
	}

	for(i=0;i<3;i++) g_free(XYZ[i]);
	g_free(numAtoms);
	return nFrag;
}
/********************************************************************************/
static int compute_fragment_principal_axes(gdouble axis1[], gdouble axis2[], gdouble axis3[], gdouble C[])
{
	gdouble m[6];
	gdouble I[3];
	gdouble** v = NULL;
	gint nrot;
	gint i;
	gint nFrag;


	if(Natoms<1) return 0;

	nFrag = set_fragment_rotational_matrix(m, C);
	if(nFrag == 0) return 0;

	v = g_malloc(3*sizeof(gdouble*));
	for(i=0;i<3;i++) v[i] = g_malloc(3*sizeof(gdouble));

	jacobi(m, 3,I,v,&nrot);

	for(i=0;i<3;i++) axis1[i] =  v[i][0];
	for(i=0;i<3;i++) axis2[i] =  v[i][1];
	for(i=0;i<3;i++) axis3[i] =  v[i][2];

	for(i=0;i<3;i++) g_free(v[i]);
	g_free(v);
	return nFrag;
}
/********************************************************************************/
void set_xyz_to_principal_axes_of_selected_atoms(gpointer data, guint Operation,GtkWidget* wid)
{
	gdouble axis1[3] = {1,0,0};
	gdouble axis2[3] = {0,1,0};
	gdouble axis3[3] = {0,0,1};
	gdouble C[3] = {0,0,0};
	int nFrag = compute_fragment_principal_axes(axis1,axis2,axis3,C);
	if(nFrag <2 ) return;
	set_origin_to_point(C);
	if(Operation == 0) set_geom_to_axes(axis1, axis2, axis3);
	else
	{
		gdouble a;
		gint i;
		for(i=0;i<3;i++)
		{
			a = axis1[i];
			axis1[i] = axis3[i];
			axis3[i] = a;
		}
		set_geom_to_axes(axis1, axis2, axis3);
	}
	create_GeomXYZ_from_draw_grometry();
	init_quat(Quat);
	dessine();
}
/********************************************************************************/
void create_tolerance_window(GtkWidget*w, gpointer data)
{
	createToleranceWindow(GeomDlg, NULL);
}
/********************************************************************************/
void get_abelian_orientation_with_reduction(GtkWidget*w, gpointer data)
{
	gchar** symbols = NULL;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gdouble* Z = NULL;
	gint i;
	gint numberOfAtoms = Natoms;
	gchar pointGroupSymbol[BSIZE];
	gchar abelianPointGroupSymbol[BSIZE];

	if(Natoms<1)
	{
		 Message("Sorry, the number of atoms is not positive","Error",TRUE);
		return;
	}
	symbols = (gchar**)g_malloc(sizeof(gchar*)*(Natoms));
	if(symbols == NULL) return;

	X = (gdouble*)g_malloc(sizeof(gdouble)*(Natoms));
	if(X == NULL) return;
	Y = (gdouble*)g_malloc(sizeof(gdouble)*(Natoms));
	if(Y == NULL) return;
	Z = (gdouble*)g_malloc(sizeof(gdouble)*(Natoms));
	if(Z == NULL) return;

	for (i=0;i<(gint)Natoms;i++)
	{
		symbols[i] = g_strdup(geometry0[i].Prop.symbol);
		X[i] = geometry0[i].X*BOHR_TO_ANG;
		Y[i] = geometry0[i].Y*BOHR_TO_ANG;
		Z[i] = geometry0[i].Z*BOHR_TO_ANG;
	}
	createGeometryAbelianGroupWindow(numberOfAtoms, symbols, X, Y, Z, pointGroupSymbol, abelianPointGroupSymbol);

	for (i=0;i<(gint)Natoms;i++)
		g_free( symbols[i]);
	g_free( symbols);
	g_free(X);
	g_free(Y);
	g_free(Z);
	return;
}
/********************************************************************************/
void get_standard_orientation_with_reduction(GtkWidget*w, gpointer data)
{
	gchar** symbols = NULL;
	gdouble* X = NULL;
	gdouble* Y = NULL;
	gdouble* Z = NULL;
	gint i;
	gint numberOfAtoms = Natoms;
	gchar groupeSymbol[BSIZE];

	if(Natoms<1)
	{
		 Message("Sorry, the number of atoms is not positive","Error",TRUE);
		return;
	}
	symbols = (gchar**)g_malloc(sizeof(gchar*)*(Natoms));
	if(symbols == NULL) return;

	X = (gdouble*)g_malloc(sizeof(gdouble)*(Natoms));
	if(X == NULL) return;
	Y = (gdouble*)g_malloc(sizeof(gdouble)*(Natoms));
	if(Y == NULL) return;
	Z = (gdouble*)g_malloc(sizeof(gdouble)*(Natoms));
	if(Z == NULL) return;

	for (i=0;i<(gint)Natoms;i++)
	{
		symbols[i] = g_strdup(geometry0[i].Prop.symbol);
		X[i] = geometry0[i].X*BOHR_TO_ANG;
		Y[i] = geometry0[i].Y*BOHR_TO_ANG;
		Z[i] = geometry0[i].Z*BOHR_TO_ANG;
	}
	createGeometrySymmetryWindow(numberOfAtoms,symbols,X, Y, Z, groupeSymbol);

	for (i=0;i<(gint)Natoms;i++)
		g_free( symbols[i]);
	g_free( symbols);
	g_free(X);
	g_free(Y);
	g_free(Z);
	return;
}
/********************************************************************************/
static gint set_key_press(GtkWidget* wid, GdkEventKey *event, gpointer data)
{
	if((event->keyval == GDK_Shift_L || event->keyval == GDK_Shift_R) )
		ShiftKeyPressed = TRUE;
	return TRUE;

}
/********************************************************************************/
static gint set_key_release(GtkWidget* wid, GdkEventKey *event, gpointer data)
{
	if((event->keyval == GDK_Shift_L || event->keyval == GDK_Shift_R) )
		ShiftKeyPressed = FALSE;
	return TRUE;
}
/********************************************************************************/
void setMMTypesCharges(gpointer data, guint Operation,GtkWidget* wid)
{
	gint i;
	gchar* mmType = NULL;
	gdouble charge = 0.0;
	for(i=0;i<(gint)Natoms;i++)
	{
		if(Operation!=3)
		{
			mmType = getMMTypeFromPDBTpl(geometry[i].Residue,geometry[i].Type,&charge);
			if(!strcmp(mmType,"UNK"))
			{
				g_free(mmType);
				continue;
			}
		}
		switch(Operation)
		{
			case 0: geometry[i].Charge = charge;
				geometry0[i].Charge = charge;
				break;
			case 1: g_free(geometry[i].Type);
				g_free(geometry0[i].Type);
				geometry[i].Type = g_strdup(mmType);
				geometry0[i].Type = g_strdup(mmType);
				break;
			case 2: g_free(geometry[i].Type);
				g_free(geometry0[i].Type);
				geometry[i].Type = g_strdup(mmType);
				geometry0[i].Type = g_strdup(mmType);
				geometry[i].Charge = charge;
				geometry0[i].Charge = charge;
				break;
			case 3:geometry[i].Charge = charge;
			       geometry0[i].Charge = charge;
			       break;
			default: break;
		}
		if(Operation!=3)
			g_free(mmType);
	}
	create_GeomXYZ_from_draw_grometry();
	dessine();
}
/*****************************************************************************/
GeomDef* Free_One_Geom(GeomDef* geom,gint N) 
{
  guint i;

 if(geom != NULL) 
 {
    for (i=0;i<(guint)N;i++)
    {
	g_free(geom[i].Prop.symbol);
	g_free(geom[i].Type);
	g_free(geom[i].Residue);
    }
		        
    g_free(geom);
 }
 return NULL;
}
/*****************************************************************************/
void free_text_to_draw()
{
	if(strToDraw)
		g_free(strToDraw);
	strToDraw = NULL;
}
/*****************************************************************************/
void set_text_to_draw(gchar* str)
{
	free_text_to_draw();

	strToDraw = g_strdup(str);
}
/********************************************************************************/
void set_statubar_operation_str(gchar* str)
{
	if(str)
	{
		gtk_statusbar_pop(GTK_STATUSBAR(StatusOperation),idStatusOperation);
		gtk_statusbar_push(GTK_STATUSBAR(StatusOperation),idStatusOperation,str);
	}
}
/*****************************************************************************/
void draw_text(gchar* str)
{
	GdkColormap *colormap;
	GdkColor color;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);

	gint x0  = ZoneDessin->allocation.width/20;
	gint y0  = ZoneDessin->allocation.height-ZoneDessin->allocation.height/10;

	color.red = FontsStyleLabel.TextColor.red;
	color.green = FontsStyleLabel.TextColor.green;
	color.blue = FontsStyleLabel.TextColor.blue;

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, x0, y0, str, FALSE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

}
/*****************************************************************************/
/*
void select_atoms_by_residues()
{
	gint i;
	gfloat x1=0;
	gfloat y1=0;
	gfloat xi;
	gfloat yi;
	gfloat d = 0;
	gint j;


	x1 = BeginX;
	y1 = BeginY;

	if(!ShiftKeyPressed)
	{
		if(!NumFatoms)
			g_free(NumFatoms);
		NumFatoms = NULL;

		NFatoms = 0;
	}
	for(i=0;i<(gint)Natoms;i++)
	{
		xi = geometry[i].Xi;
		yi = geometry[i].Yi;
		d = (xi-x1)*(xi-x1) + (yi-y1)*(yi-y1);
		d = sqrt(d);
		if(d<=geometry[i].Rayon)
		{
			for(j=0;j<(gint)Natoms;j++)
			{
				if(geometry[i].ResidueNumber == geometry[j].ResidueNumber)
				if(!if_selected(j))
				{
					if(NumFatoms == NULL)
						NumFatoms = g_malloc((NFatoms+1)*sizeof(gint));
					else
						NumFatoms = g_realloc(NumFatoms,(NFatoms+1)*sizeof(gint));
				NumFatoms[NFatoms] = geometry[j].N;
				NFatoms++;
				}
			}
			break;

		}
	}
	dessine();
}
*/

/*****************************************************************************/
void select_atoms_by_residues()
{
	gint i;
	gfloat x1=0;
	gfloat y1=0;
	gfloat xi;
	gfloat yi;
	gfloat d = 0;
	gint j;
	gint k;
	gboolean del = FALSE;
	gint selectedj;


	x1 = BeginX;
	y1 = BeginY;

	/*
	if(!ShiftKeyPressed)
	{
		if(!NumFatoms)
			g_free(NumFatoms);
		NumFatoms = NULL;

		NFatoms = 0;
	}
	*/
	for(i=0;i<(gint)Natoms;i++)
	{
		xi = geometry[i].Xi;
		yi = geometry[i].Yi;
		d = (xi-x1)*(xi-x1) + (yi-y1)*(yi-y1);
		d = sqrt(d);
		if(d<=geometry[i].Rayon)
		{
			del = if_selected(i);
			for(j=0;j<(gint)Natoms;j++)
			{
				if(geometry[i].ResidueNumber == geometry[j].ResidueNumber)
				{
					selectedj = index_selected(j);
					if(selectedj<0 && !del)
					{
						if(NumFatoms == NULL)
							NumFatoms = g_malloc((NFatoms+1)*sizeof(gint));
						else
							NumFatoms = g_realloc(NumFatoms,
									(NFatoms+1)*sizeof(gint));
						NumFatoms[NFatoms] = geometry[j].N;
						NFatoms++;
					}
					if(selectedj>=0 && del)
					{
						if((NFatoms-1)>0)
						{
							for(k=selectedj;k<(gint)(NFatoms-1);k++)
								NumFatoms[k] = NumFatoms[k+1];

							NumFatoms = g_realloc(NumFatoms,
									(NFatoms-1)*sizeof(gint));
							NFatoms--;
						}
						else
						{
							g_free(NumFatoms);
							NumFatoms = NULL;
							NFatoms = 0;
						}
					}

				}
			}
			break;

		}
	}
	dessine();
}
/*****************************************************************************/
void select_atoms_by_rectangle(gfloat x,gfloat y)
{
	gint i;
	gfloat x1=0;
	gfloat y1=0;
	gfloat x2=0;
	gfloat y2=0;
	gfloat xi;
	gfloat yi;

	if(x>BeginX)
	{
		x1 = BeginX;
		x2 = x;
	}
	else
	{
		x1 = x;
		x2 = BeginX;
	}
	if(y>BeginY)
	{
		y1 = BeginY;
		y2 = y;
	}
	else
	{
		y1 = y;
		y2 = BeginY;
	}
	if(!ShiftKeyPressed)
	{
		if(!NumFatoms)
			g_free(NumFatoms);
		NumFatoms = NULL;

		NFatoms = 0;
	}
	for(i=0;i<(gint)Natoms;i++)
	{
		xi = geometry[i].Xi;
		yi = geometry[i].Yi;
		if(xi>=x1 && xi<=x2 && yi>=y1 && yi<=y2 && !if_selected(i))
		{
			if(NumFatoms == NULL)
				NumFatoms = g_malloc((NFatoms+1)*sizeof(gint));
			else
				NumFatoms = g_realloc(NumFatoms,(NFatoms+1)*sizeof(gint));
			NumFatoms[NFatoms] = geometry[i].N;
			NFatoms++;

		}
	}
}
/********************************************************************************/
void draw_selection_rectangle(gfloat x,gfloat y)
{
	gfloat xi=0;
	gfloat yi=0;
	gfloat xf=0;
	gfloat yf=0;
        GdkColor color;
	GdkColormap *colormap;

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	color.red = 65535;
	color.green = 65535;
	color.blue = 65535;
	
	dessine();
        gdk_colormap_alloc_color(colormap,&color,FALSE,TRUE);
    	gdk_gc_set_foreground(gc,&color);
/*	GDK_LINE_ON_OFF_DASH, GDK_LINE_DOUBLE_DASH*/
	if(x>BeginX)
	{
		xi = BeginX;
		xf = x-BeginX;
	}
	else
	{
		xi = x;
		xf = BeginX-x;
	}
	if(y>BeginY)
	{
		yi = BeginY;
		yf = y-BeginY;
	}
	else
	{
		yi = y;
		yf = BeginY-y;
	}
	gdk_gc_set_line_attributes(gc,1,GDK_LINE_DOUBLE_DASH,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);
	/*gdk_gc_set_line_attributes(gc,1,GDK_LINE_ON_OFF_DASH,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);*/
  	gdk_draw_rectangle (ZoneDessin->window,gc,FALSE,xi, yi, xf, yf);
}
/********************************************************************************/
void draw_selection_circle(gfloat x,gfloat y)
{
	gfloat xi=0;
	gfloat yi=0;
	gfloat xf=0;
	gfloat yf=0;
        GdkColor color;
	GdkColormap *colormap;

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	color.red = 65535;
	color.green = 65535;
	color.blue = 65535;
	
	dessine();
        gdk_colormap_alloc_color(colormap,&color,FALSE,TRUE);
    	gdk_gc_set_foreground(gc,&color);
/*	GDK_LINE_ON_OFF_DASH, GDK_LINE_DOUBLE_DASH*/
	if(x>BeginX)
	{
		xi = BeginX;
		xf = x-BeginX;
	}
	else
	{
		xi = x;
		xf = BeginX-x;
	}
	if(y>BeginY)
	{
		yi = BeginY;
		yf = y-BeginY;
	}
	else
	{
		yi = y;
		yf = BeginY-y;
	}
	gdk_gc_set_line_attributes(gc,1,GDK_LINE_DOUBLE_DASH,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);
	gdk_draw_arc(ZoneDessin->window,gc,FALSE,xi,yi,xf,yf,0,380*64);
}
/********************************************************************************/
static void delete_molecule()
{
	if(Natoms<1)
		return;
	if(geometry0)
	       g_free(geometry0);
	if(geometry)
	       g_free(geometry);
	geometry0 = NULL;
	geometry = NULL;
	Natoms = 0;

	if(NumFatoms)
  		g_free(NumFatoms);
  	NumFatoms = NULL;
  	NFatoms = 0;

	create_GeomXYZ_from_draw_grometry();

	Ddef = FALSE;
	dessine();
	set_statubar_pop_sel_atom();
	free_text_to_draw();
	change_of_center(NULL,NULL);
}
/********************************************************************************/
void DeleteMolecule()
{
	gchar *t ="Do you want to really destroy this molecule?" ;
	if(Natoms>0)
		Continue_YesNo(delete_molecule, NULL,t);
	else
		Message("No molecule to delete\n"," Warning ",TRUE);
}
/********************************************************************************/
void SetOriginAtCenter(gpointer data, guint Operation,GtkWidget* wid)
{
	gdouble C[3];
	gint i;

	if(Natoms<1)
		return;

	for(i=0;i<3;i++)
		C[i] = 0.0; 

	for(i=0;i<(gint)Natoms;i++)
	{
		C[0] += geometry0[i].X;
		C[1] += geometry0[i].Y;
		C[2] += geometry0[i].Z;
	}
	for(i=0;i<3;i++)
		C[i] /= Natoms;

	for(i=0;i<(gint)Natoms;i++)
	{
		 geometry0[i].X -= C[0];
		 geometry0[i].Y -= C[1];
		 geometry0[i].Z -= C[2];
	}

	Ddef = FALSE;
	TransX = 0;
	TransY = 0;
	dessine();
	set_statubar_pop_sel_atom();
	return;
}
/********************************************************************************/
void TraitementGeom(gpointer data, guint Operation,GtkWidget* wid)
{
  switch((GabEditGeomOperation)Operation)
  {
	case SAVEJPEG:
 		file_chooser_save(save_geometry_jpeg_file,"Save image in jpeg file format",GABEDIT_TYPEFILE_JPEG,GABEDIT_TYPEWIN_GEOM);
		break;
	case SAVEPPM:
 		file_chooser_save(save_geometry_ppm_file,"Save image in ppm file format",GABEDIT_TYPEFILE_PPM,GABEDIT_TYPEWIN_GEOM);
		break;
	case SAVEBMP:
 		file_chooser_save(save_geometry_bmp_file,"Save image in bmp file format",GABEDIT_TYPEFILE_BMP,GABEDIT_TYPEWIN_GEOM);
		break;
	case SAVEPS:
 		file_chooser_save(save_geometry_ps_file,"Save image in ps file format",GABEDIT_TYPEFILE_PS,GABEDIT_TYPEWIN_GEOM);
		break;
	default:
		printf("Operation = %d\n",Operation);
  }
}
/********************************************************************************/  
GdkPixmap *get_drawing_pixmap()
{
  return pixmap;
}
/********************************************************************************/  
GdkColormap* get_drawing_colormap()
{
  GdkColormap *colormap = gdk_window_get_colormap(ZoneDessin->window);

  return colormap;
}
/********************************************************************************/  
void read_geometries_convergence(gpointer data, guint Operation,GtkWidget* wid)
{
	switch(Operation)
	{
		case FGEOMCONVDALTON:
 			  	  file_chooser_open(read_geometries_conv_dalton,"Load Geom. Conv. From Dalton Output file",
				  GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FGEOMCONVGAUSS:
 			  	  file_chooser_open(read_geometries_conv_gaussian,"Load Geom. Conv. From Gaussian Output file",
				  GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FGEOMCONVMOLPRO:
 			  	  file_chooser_open(read_geometries_conv_molpro,"Load Geom. Conv. From Molpro log file",
				  GABEDIT_TYPEFILE_MOLPRO_LOG,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FGEOMCONVMOLDEN:
 			  	  file_chooser_open(read_geometries_conv_molden,"Load Geom. Conv. From Molden file",
				  GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FGEOMCONVGABEDIT:
 			  	  file_chooser_open(read_geometries_conv_gabedit,"Load Geom. Conv. From Gabedit file",
				  GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FGEOMCONVMPQC:
 			  	  file_chooser_open(read_geometries_conv_mpqc,"Load Geom. Conv. From MPQC output file",
				  GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FGEOMCONVXYZ:
 			  	  file_chooser_open(read_geometries_conv_xyz,"Load Geom. Conv. From XYZ",
				  GABEDIT_TYPEFILE_XYZ,GABEDIT_TYPEWIN_GEOM);
				  break;
		default : break;
	}
}
/********************************************************************************/  
void save_geometry(gpointer data, guint Operation,GtkWidget* wid)
{
	if(Natoms<1)
	{
		Message("Sorry,No molecule to save\n"," Warning ",TRUE);
		return;
	}
	switch(Operation)
	{
		case FXYZ 	: create_GeomXYZ_from_draw_grometry();
 			  	  file_chooser_save(save_geometry_xyz_file,"Save geometry in xyz file",
				  GABEDIT_TYPEFILE_XYZ,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FMOL2 	: create_GeomXYZ_from_draw_grometry();
 			  	  file_chooser_save(save_geometry_mol2_file,"Save geometry in mol2 file",
				  GABEDIT_TYPEFILE_MOL2,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FTINKER 	: create_GeomXYZ_from_draw_grometry();
 			  	  file_chooser_save(save_geometry_tinker_file,"Save geometry in tinker file",
				  GABEDIT_TYPEFILE_TINKER,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FPDB 	: create_GeomXYZ_from_draw_grometry();
 			  	  file_chooser_save(save_geometry_pdb_file,"Save geometry in pdb file",
				  GABEDIT_TYPEFILE_PDB,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FHIN 	: create_GeomXYZ_from_draw_grometry();
 			  	  file_chooser_save(save_geometry_hin_file,"Save geometry in hyperchem file",
				  GABEDIT_TYPEFILE_HIN,GABEDIT_TYPEWIN_GEOM);
				  break;
		case FMZMAT 	: create_GeomXYZ_from_draw_grometry(); 
				  if(!xyz_to_zmat())
				  {
					Message("Sorry\nConversion is not possible from XYZ to Zmat","Errot",TRUE);
					return;
				  }
 			  	  file_chooser_save(save_geometry_mzmatrix_file,"Save geometry in mopac z-matrix file",
				  GABEDIT_TYPEFILE_MZMAT,GABEDIT_TYPEWIN_GEOM);
				  create_GeomXYZ_from_draw_grometry(); 
				  MethodeGeom = GEOM_IS_XYZ;
				  break;
		case FGZMAT 	: create_GeomXYZ_from_draw_grometry(); 
				  if(!xyz_to_zmat())
				  {
					Message("Sorry\nConversion is not possible from XYZ to Zmat","Errot",TRUE);
					return;
				  }
 			  	  file_chooser_save(save_geometry_gzmatrix_file,"Save geometry in gaussian z-matrix file",
				  GABEDIT_TYPEFILE_GZMAT,GABEDIT_TYPEWIN_GEOM);
				  create_GeomXYZ_from_draw_grometry(); 
				  MethodeGeom = GEOM_IS_XYZ;
				  break;
		default : break;
	}
}
/********************************************************************************/  
void read_geometry(gpointer data, guint Operation,GtkWidget* wid)
{
	switch(Operation)
	{
		case FXYZ 	:  MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_XYZ);break;
		case FGZMAT 	:  MethodeGeom = GEOM_IS_ZMAT;selc_ZMatrix_file();break;
		case FMZMAT 	:  MethodeGeom = GEOM_IS_ZMAT;selc_ZMatrix_mopac_file();break;
		case FMOL2 	:  MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOL2);break;
		case FTINKER 	: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_TINKER);break;
		case FPDB 	: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_PDB);break;
		case FHIN 	: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_HIN);break;

		case FDALTONIN : break;
		case FDALTONFIRST: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_DALTONFIRST);break;
		case FDALTONLAST : MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_DALTONLAST);break;

		case FGAUSSIN : selc_gauss_molcas_molpro_mpqc_input_file("Read Geometry from a Gaussian input file");break;
		case FGAUSSOUTFIRST: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAUSSOUTFIRST);break;
		case FGAUSSOUTLAST : MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAUSSOUTLAST);break;

		case FMOLCASIN : selc_gauss_molcas_molpro_mpqc_input_file("Read Geometry from a Molcas input file");break;
		case FMOLCASOUTFIRST: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLCASOUTFIRST);break;
		case FMOLCASOUTLAST : MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLCASOUTLAST);break;

		case FMOLPROIN : selc_gauss_molcas_molpro_mpqc_input_file("Read Geometry from a Molpro input file");break;
		case FMOLPROOUTFIRST: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLPROOUTFIRST);break;
		case FMOLPROOUTLAST : MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLPROOUTLAST);break;

		case FMPQCIN : selc_gauss_molcas_molpro_mpqc_input_file("Read Geometry from a MPQC input file");break;
		case FMPQCOUTFIRST: MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MPQCOUTFIRST);break;
		case FMPQCOUTLAST : MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MPQCOUTLAST);break;
	}
}
/********************************************************************************/  
guint label_option()
{
	return LabelOption;
}
/********************************************************************************/  
gboolean dipole_draw_mode()
{
	return DrawDipole;
}
/********************************************************************************/  
gboolean distances_draw_mode()
{
	return DrawDistance;
}
/********************************************************************************/  
gboolean dipole_mode()
{
	return ShowDipole;
}
/********************************************************************************/  
gboolean stick_mode()
{
	return StickMode;
}
/********************************************************************************/  
gboolean pers_mode()
{
	return PersMode;
}
/********************************************************************************/  
gboolean shad_mode()
{
	return ShadMode;
}
/********************************************************************************/  
gboolean light_mode()
{
	return LightMode;
}
/********************************************************************************/  
void to_postscript(GtkWidget *win, guint data)
{
	create_save_postscript(GeomDlg);
}
/********************************************************************************/  
void set_HBonds_dialog_geom(GtkWidget *win, guint data)
{
	set_HBonds_dialog (GeomDlg);
}
/********************************************************************************/  
void set_povray_options_geom(GtkWidget *win, guint data)
{
	 createPovrayOptionsWindow(GeomDlg);
}
/********************************************************************************/  
void to_povray(GtkWidget *win, guint data)
{
	create_save_povray(GeomDlg);
}
/********************************************************************************/
void HideShowMesure(gboolean hiding)
{
	if(hiding)
	{
  		gtk_widget_hide(vboxhandle);
  		gtk_widget_hide(ZoneDessin);
  		gtk_widget_show(ZoneDessin);
    		while( gtk_events_pending() ) gtk_main_iteration();
	}
	else gtk_widget_show(vboxhandle);

   	MesureIsHide=hiding;
}
/********************************************************************************/
static gint ScaleByMouse(gpointer data)
{
	GdkEventButton *bevent=(GdkEventButton *)data;

        switch(OperationType)
        {
	case SCALEGEOM :
			factor +=((bevent->y - BeginY) / ZoneDessin->allocation.height) * 5;
			if(factor<0.1) factor = 0.1;
			if(factor>10) factor = 10;
			dessine();
		break;
	case SCALESTICK :
			factorstick +=((bevent->y - BeginY) / ZoneDessin->allocation.height) * 5;
			if(factorstick <0.1) factorstick  = 0.1;
			if(factorstick >10) factorstick = 10;
			dessine();

		break;
	case SCALEBALL :
			factorball +=((bevent->y - BeginY) / ZoneDessin->allocation.height) * 5;
			if(factorball <0.1) factorball  = 0.1;
			if(factorball >10) factorball = 10;
			dessine();
		break;
	case SCALEDIPOLE :
			factordipole +=((bevent->y - BeginY) / ZoneDessin->allocation.height) * 5;
			if(factordipole <0.1) factordipole  = 0.1;
			if(factordipole >100) factordipole = 100;
			redefine_dipole();
			dessine();
		break;
	default : break;

        }
	BeginX = bevent->x;
	BeginY = bevent->y;
	

 	return TRUE;
}
/********************************************************************************/
static gint TranslationByMouse(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkRectangle area;
	GdkModifierType state;

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	area.x = 0;
	area.y = 0;
	area.width  = widget->allocation.width;
	area.height = widget->allocation.height;

    TransX =(gint)(TransX+(x - BeginX)); 
    TransY =(gint)(TransY+(y - BeginY)); 
	dessine();

	BeginX = x;
	BeginY = y;
 return TRUE;
}
/********************************************************************************/
static gint RotationByMouse(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkRectangle area;
	GdkModifierType state;
	gfloat spin_quat[4];

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	area.x = 0;
	area.y = 0;
	area.width  = widget->allocation.width;
	area.height = widget->allocation.height;

	
	trackball(spin_quat,
		(2.0*BeginX  - area.width) / area.width,
		(area.height - 2.0*BeginY) / area.height,
		(2.0*x       - area.width) / area.width,
		(area.height - 2.0*y     ) / area.height);
	add_quats(spin_quat, Quat, Quat);
	dessine();

	BeginX = x;
	BeginY = y;
 return TRUE;
}
/********************************************************************************/
static gint RotationZByMouse(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkModifierType state;
	gfloat spin_quat[4] = {0,0,0,0};
	gfloat phi = 1.0/180*PI;
	gfloat width;
	gfloat height;
	gint Xi;
	gint Yi;

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	width  = widget->allocation.width;
	height = widget->allocation.height;

	Xi = width/2 + TransX;
	Yi = height/2 + TransY;

	
	if(abs(BeginX-x)>abs(BeginY-y))
	 {
		  gdouble sign  = 1.0;
		  if(BeginY> Yi && BeginX<x) sign = -1;
		  if(BeginY< Yi && BeginX>x) sign = -1;
		  phi = sign* fabs(BeginX-x)/width*PI;
	  }
	  else
	  {
		  gdouble sign = 1.0;
		  if(BeginX> Xi && BeginY>y) sign = -1;
		  if(BeginX< Xi && BeginY<y) sign = -1;
		  phi = sign* fabs(BeginY-y)/height*PI;
	  }
	spin_quat[2] = 1.0;

	spin_quat[2]= sin(phi/2);
	spin_quat[3] = cos(phi/2);

	add_quats(spin_quat, Quat, Quat);
	dessine();

	BeginX = x;
	BeginY = y;
	return TRUE;
}
/********************************************************************************/
static void rotation_fragment_quat(gfloat m[4][4],gdouble C[])
{
	gdouble A[3];
	gdouble B[3];
	guint i,j,k;

	for (i=0;i<Natoms;i++)
	{
		A[0] = geometry[i].X-C[0];
		A[1] = geometry[i].Y-C[1];
		A[2] = geometry[i].Z-C[2];
		if(if_selected(i))
		{
			for(j=0;j<3;j++)
			{
				B[j] = 0.0;
				for(k=0;k<3;k++)
					B[j] += m[k][j]*A[k];
			}
		}
		else
			for(k=0;k<3;k++)
				B[k] = A[k];

		geometry[i].X=C[0]+B[0];
		geometry[i].Y=C[1]+B[1];
		geometry[i].Z=C[2]+B[2];
	}
	Ddef = FALSE;
	for (i=0;i<Natoms;i++)
	{
		geometry0[i].X=geometry[i].X;
		geometry0[i].Y=geometry[i].Y;
		geometry0[i].Z=geometry[i].Z;
	}
	init_quat(Quat);

	sort_with_zaxis();
	define_coefs_pers();
}
/********************************************************************************/
static gint local_zrotate_fragment(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkModifierType state;
	gfloat spin_quat[4] = {0,0,0,0};
	gfloat m[4][4];
	gdouble C[3]={0,0,0};/* Center of Fragment */
	gint i;
	gint j;
	gint k;
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;
	gdouble Cmax;
	gint Xi;
	gint Yi;
	gfloat width;
	gfloat height;
	gfloat phi = 1.0/180*PI;

	if(Natoms>0)
	{
		if(PersMode)
			Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
		else
			Cmax = coordmaxmin.Cmax;
	}
	else
		return FALSE;

	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;



	j=0;
	for (i=0;i<(gint)Natoms;i++)
	{
		if(if_selected(i))
		{
			j++;
			C[0] += geometry[i].X;
			C[1] += geometry[i].Y;
			C[2] += geometry[i].Z;
		}
	}
	if(j<1)
		return FALSE;
	for(k=0;k<3;k++)
		C[k] /= (gdouble)j;

	Xi = (gint)(C[0]/Cmax*factor*Rmax/2)+Xmax/2;
	Yi = (gint)(C[1]/Cmax*factor*Rmax/2)+Ymax/2;

	Xi = Xi + TransX;
	Yi = Yi + TransY;

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	width  = widget->allocation.width;
	height = widget->allocation.height;

	if(abs(BeginX-x)>abs(BeginY-y))
	 {
		  gdouble sign  = 1.0;
		  if(BeginY> Yi && BeginX<x) sign = -1;
		  if(BeginY< Yi && BeginX>x) sign = -1;
		  phi = sign* fabs(BeginX-x)/width*PI;
	  }
	  else
	  {
		  gdouble sign = 1.0;
		  if(BeginX> Xi && BeginY>y) sign = -1;
		  if(BeginX< Xi && BeginY<y) sign = -1;
		  phi = sign* fabs(BeginY-y)/height*PI;
	  }
	spin_quat[2] = 1.0;

	spin_quat[2]= sin(phi/2);
	spin_quat[3] = cos(phi/2);

	add_quats(spin_quat, QuatFrag, QuatFrag);
	build_rotmatrix(m,QuatFrag);
	rotation_fragment_quat(m,C);

	dessine();

	init_quat(QuatFrag);
	BeginX = x;
	BeginY = y;
 return TRUE;
}
/********************************************************************************/
static gint local_rotate_fragment(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkModifierType state;
	gfloat spin_quat[4];
	gfloat m[4][4];
	gdouble C[3]={0,0,0};/* Center of Fragment */
	gint i;
	gint j;
	gint k;
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;
	gdouble Cmax;
	gint Xi;
	gint Yi;
	gfloat width;
	gfloat height;

	if(Natoms>0)
	{
		if(PersMode)
			Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
		else
			Cmax = coordmaxmin.Cmax;
	}
	else
		return FALSE;

	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;



	j=0;
	for (i=0;i<(gint)Natoms;i++)
	{
		if(if_selected(i))
		{
			j++;
			C[0] += geometry[i].X;
			C[1] += geometry[i].Y;
			C[2] += geometry[i].Z;
		}
	}
	if(j<1)
		return FALSE;
	for(k=0;k<3;k++)
		C[k] /= (gdouble)j;

	Xi = (gint)(C[0]/Cmax*factor*Rmax/2)+Xmax/2;
	Yi = (gint)(C[1]/Cmax*factor*Rmax/2)+Ymax/2;

	Xi = Xi + TransX;
	Yi = Yi + TransY;

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	width  = widget->allocation.width;
	height = widget->allocation.height;

	
	trackball(spin_quat,
		(2.0*(width/2+BeginX-Xi)  - (width)) / (width),
		((height) - 2.0*(height/2+BeginY-Yi)) / (height),
		(2.0*(width/2+x-Xi)       - (width)) / (width),
		((height) - 2.0*(height/2+y-Yi)     ) / (height));

	add_quats(spin_quat, QuatFrag, QuatFrag);
	build_rotmatrix(m,QuatFrag);
	rotation_fragment_quat(m,C);

	dessine();

	init_quat(QuatFrag);
	BeginX = x;
	BeginY = y;
 return TRUE;
}
/********************************************************************************/
/*
static gint RotationAtomByMouse(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkRectangle area;
	GdkModifierType state;
	gfloat spin_quat[4];

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	area.x = 0;
	area.y = 0;
	area.width  = widget->allocation.width;
	area.height = widget->allocation.height;

	
	trackball(spin_quat,
		(2.0*BeginX  - area.width) / area.width,
		(area.height - 2.0*BeginY) / area.height,
		(2.0*x       - area.width) / area.width,
		(area.height - 2.0*y     ) / area.height);
	add_quats(spin_quat, QuatAtom, QuatAtom);
	dessine();
	
	BeginX = x;
	BeginY = y;

 return TRUE;
}
*/

/********************************************************************************/
void set_statubar_pop_sel_atom()
{
	gchar* temp = NULL;
	gchar* t = NULL;
	if(NumSelectedAtom <0)
		return;
	temp = g_strdup_printf("%s[%d] ; Coord (Ang) : %f %f %f ",geometry0[NumSelectedAtom].Prop.symbol,NumSelectedAtom+1,
			geometry0[NumSelectedAtom].X*BOHR_TO_ANG,
			geometry0[NumSelectedAtom].Y*BOHR_TO_ANG,
			geometry0[NumSelectedAtom].Z*BOHR_TO_ANG);
	if(OperationType == DELETEFRAG)
	{
		t = temp;
		temp = g_strdup_printf("%s ; Move your mouse to cancel the operation",t); 
		g_free(t);
	}
	if(temp)
	{
		gtk_statusbar_pop(GTK_STATUSBAR(StatusOperation),idStatusOperation);
		gtk_statusbar_push(GTK_STATUSBAR(StatusOperation),idStatusOperation,temp);
		g_free(temp);
	}
}
/********************************************************************************/
static gint move_one_atom(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkModifierType state;
	gdouble X;
	gdouble Y;
	gdouble Z;
	gdouble Cmax;
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;

	if(NumSelectedAtom<0)
		return -1;
	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;
	

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  

	if(PersMode)
		Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
	else
		Cmax = coordmaxmin.Cmax;

	X = (gfloat)(x-Xmax/2-TransX)*2.0*Cmax/(factor*Rmax);
	Y = -(gfloat)(y-Ymax/2-TransY)*2.0*Cmax/(factor*Rmax);
	Z = geometry[NumSelectedAtom].Z;

	if(PersMode)
	{
		X = X/camera.f*(-Z+camera.position);
		Y = Y/camera.f*(-Z+camera.position);
	}
	{
		gfloat m[4][4];
		gfloat **m0 = g_malloc(3*sizeof(gfloat*));
		gfloat** minv;
		gint i,j;

		gdouble A[3];
		gdouble B[3];
		guint k;

		for(i=0;i<3;i++)
			m0[i] = g_malloc(3*sizeof(gfloat));

		build_rotmatrix(m,Quat);

		for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m0[i][j] = m[i][j];

		minv = Inverse(m0,3,1e-7);

		A[0] = X;
		A[1] = Y;
		A[2] = Z;
		for(j=0;j<3;j++)
		{
			B[j] = 0.0;
			for(k=0;k<3;k++)
				B[j] += minv[k][j]*A[k];
		}
		X=B[0];
		Y=B[1];
		Z=B[2];
		i = NumSelectedAtom;
		geometry0[i].X=B[0];
		geometry0[i].Y=B[1];
		geometry0[i].Z=B[2];

		for(i=0;i<3;i++)
			if(minv[i])
				g_free(minv[i]);
		if(minv)
			g_free(minv);

		for(i=0;i<3;i++)
			if(m0[i])
				g_free(m0[i]);
		if(m0)
			g_free(m0);
	}
	Ddef = FALSE;
	dessine();
	set_statubar_pop_sel_atom();
	return TRUE;
}

static gint move_all_selected_atoms(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkModifierType state;
	gdouble X;
	gdouble Y;
	gdouble Z;
	gdouble Cmax;
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;

	if(NumSelectedAtom<0)
		return -1;
	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;
	

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		x = event->x;
		y = event->y;
		state = event->state;
#endif
	}
	else
	{
		x = event->x;
		y = event->y;
		state = event->state;
	}
  
	if(PersMode)
		Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
	else
		Cmax = coordmaxmin.Cmax;

	X = (gfloat)(x-Xmax/2-TransX)*2.0*Cmax/(factor*Rmax);
	Y = -(gfloat)(y-Ymax/2-TransY)*2.0*Cmax/(factor*Rmax);
	Z = geometry[NumSelectedAtom].Z;

	if(PersMode)
	{
		X = X/camera.f*(-Z+camera.position);
		Y = Y/camera.f*(-Z+camera.position);
	}
	{
		gfloat m[4][4];
		gfloat **m0 = g_malloc(3*sizeof(gfloat*));
		gfloat** minv;
		gint i,j;

		gdouble A[3];
		gdouble B[3];
		guint k;

		for(i=0;i<3;i++)
			m0[i] = g_malloc(3*sizeof(gfloat));

		build_rotmatrix(m,Quat);

		for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m0[i][j] = m[i][j];

		minv = Inverse(m0,3,1e-7);

		A[0] = X;
		A[1] = Y;
		A[2] = Z;
		for(j=0;j<3;j++)
		{
			B[j] = 0.0;
			for(k=0;k<3;k++)
				B[j] += minv[k][j]*A[k];
		}
		X=B[0];
		Y=B[1];
		Z=B[2];
		i = NumSelectedAtom;
		B[0] -=geometry0[i].X;
		B[1] -=geometry0[i].Y;
		B[2] -=geometry0[i].Z;

		for(i=0;i<(gint)Natoms;i++)
		for(j=0;j<(gint)NFatoms;j++)
			if(NumFatoms[j]==(gint)geometry0[i].N)
			{
				geometry0[i].X += B[0];
				geometry0[i].Y += B[1];
				geometry0[i].Z += B[2];
			}


		for(i=0;i<3;i++)
			if(minv[i])
				g_free(minv[i]);
		if(minv)
			g_free(minv);

		for(i=0;i<3;i++)
			if(m0[i])
				g_free(m0[i]);
		if(m0)
			g_free(m0);
	}
	Ddef = FALSE;
	dessine();
	set_statubar_pop_sel_atom();
	return TRUE;
}
/********************************************************************************/
static gint MoveAtomByMouse(GtkWidget *widget, GdkEventMotion *event)
{
	gboolean MoveAll = FALSE;
	gint i;
	gint j;

	for(i=0;i<(gint)Natoms;i++)
		if((gint)i==NumSelectedAtom)
		{
			for(j = 0;j<(gint)NFatoms;j++)
				if(NumFatoms[j] == (gint)geometry[i].N)
					MoveAll = TRUE;
			break;
		}
	if(!MoveAll)
	{
		move_one_atom(widget,event);
		return TRUE;
	}
	move_all_selected_atoms(widget, event);
	return TRUE;
}
/*****************************************************************************/
gint set_proche_atom(GdkEventButton *bevent)
{
	gdouble xi,yi,xii,yii;
	gint i;
	gdouble mindist = -1;
	gdouble d1 ;

	xi = bevent->x;
	yi = bevent->y;

	NumProcheAtom = -1;
	for(i=0;i<(gint)Natoms;i++)
	{
		xii = xi-geometry[i].Xi;
		yii = yi-geometry[i].Yi;
		d1 = xii*xii+yii*yii;
		/*d2 = xii*xii+yii*yii-(gdouble)geometry[i].Rayon*(gdouble)geometry[i].Rayon;*/
			if(mindist<0)
			{
				mindist = fabs(d1);
				NumProcheAtom = i;
			}
			if(mindist>fabs(d1))
			{
				mindist = fabs(d1);
				NumProcheAtom = i;
			}
	}
	/*set_statubar_pop_sel_atom();*/
	return NumProcheAtom;
}
/*****************************************************************************/
gint set_selected_atoms(GdkEventButton *bevent)
{
	gdouble xi,yi,xii,yii;
	gint i;
	gdouble mindist = -1;
	gdouble d2 ;
	gdouble d1 ;
	gint ns = -1;

	xi = bevent->x;
	yi = bevent->y;

	for(i=0;i<(gint)Natoms;i++)
	{
		xii = xi-geometry[i].Xi;
		yii = yi-geometry[i].Yi;
		d1 = xii*xii+yii*yii;
		d2 = d1-(gdouble)geometry[i].Rayon*(gdouble)geometry[i].Rayon;
		if(d2<0)
		{
			if(mindist<0)
			{
				mindist = fabs(d1);
				ns = i;
			}
			if(mindist>fabs(d1))
			{
				mindist = fabs(d1);
				ns = i;
			}
		}
	}
	if(ns != -1)
	{
		gboolean Ok = FALSE;
		for(i=0;i<4;i++)
			if(NumSelAtoms[i] ==(gint) geometry[ns].N)
			{
				NumSelAtoms[i] = -1;
				Ok = TRUE;
				break;
			}
		if(!Ok)
		for(i=0;i<4;i++)
			if(NumSelAtoms[i] == -1 || NumSelAtoms[i] >(gint)Natoms)
			{
				NumSelAtoms[i] = geometry[ns].N;
				Ok = TRUE;
				break;
			}

		if(!Ok)
		{
			for(i=0;i<3;i++)
				NumSelAtoms[i] = NumSelAtoms[i+1]; 
			NumSelAtoms[3] = geometry[ns].N; 
		}
	}
	for(i=0;i<3;i++)
		if(NumSelAtoms[i] == -1)
		{
			NumSelAtoms[i] = NumSelAtoms[i+1];
			NumSelAtoms[i+1] = -1;
		}
/*
	Debug("ns = ");
	for(i=0;i<4;i++)
			Debug(" %d ",NumSelAtoms[i]);
	Debug("\n");
*/
	dessine();
	change_of_center(NULL,NULL);
	set_statubar_pop_sel_atom();
	return ns;
}
/*****************************************************************************/
gint unselected_atom(GdkEventButton *bevent)
{
	gdouble xi,yi,xii,yii;

	xi = bevent->x;
	yi = bevent->y;

	xii = xi-BeginX;
	yii = yi-BeginY;
	if(xii*xii+yii*yii > 8)
	{
		NumSelectedAtom = -1;
		dessine();
		SetOperation (NULL,DELETEFRAG);
	}
	return NumSelectedAtom;
}
/*****************************************************************************/
gint set_selected_atom(GdkEventButton *bevent)
{
	gdouble xi,yi,xii,yii;
	gint i;
	gdouble mindist = -1;
	gdouble d2 ;
	gdouble d1 ;

	xi = bevent->x;
	yi = bevent->y;

	NumSelectedAtom = -1;
	for(i=0;i<(gint)Natoms;i++)
	{
		xii = xi-geometry[i].Xi;
		yii = yi-geometry[i].Yi;
		d1 = xii*xii+yii*yii;
		d2 = d1-(gdouble)geometry[i].Rayon*(gdouble)geometry[i].Rayon;
		if(d2<0)
		{
			if(mindist<0)
			{
				mindist = fabs(d1);
				NumSelectedAtom = i;
			}
			if(mindist>fabs(d1))
			{
				mindist = fabs(d1);
				NumSelectedAtom = i;
			}
		}
	}
	for(i=0;i<3;i++)
		QuatAtom[i] = 0;
	QuatAtom[3] = 1;
	if(NumSelectedAtom>=0)
	{
	CSselectedAtom[0] = geometry0[NumSelectedAtom].X;
	CSselectedAtom[1] = geometry0[NumSelectedAtom].Y;
	CSselectedAtom[2] = geometry0[NumSelectedAtom].Z;
	}
	dessine();
	set_statubar_pop_sel_atom();
	return NumSelectedAtom;
}
/*****************************************************************************
*  event_dispatcher
******************************************************************************/
gint button_press(GtkWidget *DrawingArea, GdkEvent *event, gpointer Menu)
{
	GdkEventButton *bevent;

	switch (event->type)
	{
		case GDK_BUTTON_PRESS:
		{
			bevent = (GdkEventButton *) event;
			if (bevent->button == 3) /* Right Button ==> Popup Menu */
			{
				popuo_menu_geom( bevent->button, bevent->time);
			}
			else
			if (bevent->button == 1)
			{
				/* beginning of drag, reset mouse position */
				BeginX= bevent->x;
				BeginY = bevent->y;
        			switch(OperationType)
        			{
					case SELECTRESIDUE : select_atoms_by_residues(); break;
					case MOVEFRAG : set_selected_atom(bevent); break;
					case DELETEFRAG : set_selected_atom(bevent);break;
					case MESURE     : set_selected_atoms(bevent);break;
					case INSERTATOM : set_selected_atom(bevent); 
							  set_proche_atom(bevent);break;
					case ADDFRAGMENT : set_proche_atom(bevent);break;
					case ROTLOCFRAG : init_quat(QuatFrag);
							  ButtonPressed = TRUE;
							  dessine();
							  break;
					case ROTZLOCFRAG : init_quat(QuatFrag);
							  ButtonPressed = TRUE;
							  dessine();
							  break;
					default:break;
				}
			return TRUE;
			}
			else
			if (bevent->button == 2)
			{
				BeginX= bevent->x;
				BeginY = bevent->y;
				return TRUE;
			}
		}
		default: break;
	}
	return FALSE;
}
/*************************/
void unselect_all_atoms()
{
	NFatoms = 0;
	if(NumFatoms)
	       g_free(NumFatoms);
	NumFatoms = NULL;
}
/*****************************************************************************
*  event_release
******************************************************************************/
gint button_release(GtkWidget *DrawingArea, GdkEvent *event, gpointer Menu)
{
	if(NumSelectedAtom !=-1)
	{
		switch(OperationType)
		{
		case MOVEFRAG :
			create_GeomXYZ_from_draw_grometry();
			NumSelectedAtom = -1;
			if(GeomIsOpen)
				unselect_all_atoms();

			free_text_to_draw();
			dessine();
			SetOperation (NULL,MOVEFRAG);
			change_of_center(NULL,NULL);
			break;
		case DELETEFRAG :
			delete_selected_atoms();
			create_GeomXYZ_from_draw_grometry();
			NumSelectedAtom = -1;
			free_text_to_draw();
			dessine();
			SetOperation (NULL,DELETEFRAG);
			change_of_center(NULL,NULL);
			break;
		default:break;

		}
	}
	switch(OperationType)
	{
	case INSERTATOM :
		insert_atom(DrawingArea,event);
		create_GeomXYZ_from_draw_grometry();
		NumProcheAtom = -1;
		NumSelectedAtom = -1;
		free_text_to_draw();
		dessine();
		SetOperation (NULL,INSERTATOM);
		change_of_center(NULL,NULL);
		break;
	case ADDFRAGMENT :
		insert_fragment(DrawingArea,event);
		create_GeomXYZ_from_draw_grometry();
		NumProcheAtom = -1;
		free_text_to_draw();
		dessine();
		activate_rotation();
		SetOperation (NULL,ROTATION);
		change_of_center(NULL,NULL);
		break;
	case ROTLOCFRAG :
		ButtonPressed = FALSE;
		create_GeomXYZ_from_draw_grometry();
		dessine();
		change_of_center(NULL,NULL);
		break;
	case ROTZLOCFRAG :
		ButtonPressed = FALSE;
		create_GeomXYZ_from_draw_grometry();
		dessine();
		change_of_center(NULL,NULL);
		break;

	default:
		dessine();
	}

	return TRUE;

}
/*****************************************************************************
*  event_dispatcher
******************************************************************************/
gint event_dispatcher(GtkWidget *DrawingArea, GdkEvent *event, gpointer Menu)
{
	return button_press(DrawingArea,event,Menu);

}
/********************************************************************************/
/* Moption Notify */
/********************************************************************************/
gint motion_notify(GtkWidget *widget, GdkEventMotion *event)
{
	int x, y;
	GdkModifierType state;

	if (event->is_hint)
	{
#if !defined(G_OS_WIN32)
		gdk_window_get_pointer(event->window, &x, &y, &state);
#else
		state = event->state;
#endif

	}
	else
		state = event->state;
  

	if (state & GDK_BUTTON1_MASK)
	{
		switch(OperationType)
		{
			case ROTATION 	: RotationByMouse(widget,event);break;
			case ROTATIONZ 	: RotationZByMouse(widget,event);break;
			case TRANSMOVIE : TranslationByMouse(widget,event);break;
			case SCALEGEOM 	: 
			case SCALESTICK	:
			case SCALEBALL 	: 
			case SCALEDIPOLE: ScaleByMouse((gpointer)event);break;
			case SELECTFRAG : 
					  switch(SelectType)
					  {
						case CIRCLE :
							draw_selection_circle(event->x,event->y);
							break;
						case RECTANGLE:
							draw_selection_rectangle(event->x,event->y);
							select_atoms_by_rectangle(event->x,event->y);
							break;
						default:break;
					  }
					  break;
			case MOVEFRAG   : 
					  MoveAtomByMouse(widget,event);
					  free_text_to_draw();
					  change_of_center(NULL,NULL);
					  break;
			case ROTLOCFRAG :
					local_rotate_fragment(widget,event);
					free_text_to_draw();
					change_of_center(NULL,NULL);
					break;
			case ROTZLOCFRAG :
					local_zrotate_fragment(widget,event);
					free_text_to_draw();
					change_of_center(NULL,NULL);
					break;
			case DELETEFRAG : unselected_atom((GdkEventButton *)event);
					  free_text_to_draw();
					  change_of_center(NULL,NULL);
					  break;
            default : return FALSE;
		}
	}

	if (state & GDK_BUTTON2_MASK)
	{
		RotationByMouse(widget,event);
	}
	return TRUE;
}
/********************************************************************************/
static void redraw()
{
/*        gtk_signal_emit_by_name(GTK_OBJECT (ZoneDessin),"hide");*/
/*        gtk_signal_emit_by_name(GTK_OBJECT (ZoneDessin),"show");*/
  gdk_draw_pixmap(ZoneDessin->window,
                  ZoneDessin->style->fg_gc[GTK_WIDGET_STATE (ZoneDessin)],
                  pixmap,
                  0,0,
                  0,0,
                  ZoneDessin->allocation.width,
                  ZoneDessin->allocation.height);    
}
/********************************************************************************/
static void pixmap_init(GtkWidget *widget)
{
  GdkColormap *colormap;

  if(!BackColor)
  gdk_draw_rectangle (pixmap,
                      widget->style->black_gc,
                      TRUE,
                      0, 0,
                      widget->allocation.width,
                      widget->allocation.height);    
  else
  {
   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
        gdk_colormap_alloc_color(colormap,BackColor,FALSE,TRUE);
	gdk_gc_set_foreground(gc,BackColor);

        gdk_draw_rectangle (pixmap,
                      gc,
                      TRUE,
                      0, 0,
                      widget->allocation.width,
                      widget->allocation.height);    
  }
}
/*****************************************************************************/
static gint configure_event( GtkWidget *widget, GdkEventConfigure *event )
{
	if(gc) gdk_gc_destroy(gc);
	gc = gdk_gc_new(ZoneDessin->window);
	if (pixmap) gdk_pixmap_unref(pixmap);
	pixmap = gdk_pixmap_new(widget->window, widget->allocation.width, widget->allocation.height, -1);
	dessine();

	return TRUE;
}
/********************************************************************************/   
static gint expose_event( GtkWidget *widget, GdkEventExpose *event )
{
	if(event->count >0) return FALSE;
	gdk_draw_pixmap(widget->window,
                  widget->style->fg_gc[GTK_WIDGET_STATE (widget)],
                  pixmap,
                  event->area.x, event->area.y,
                  event->area.x, event->area.y,
                  event->area.width, event->area.height);
 
	return FALSE;
}                                                                               
/*****************************************************************************/
void SetCosSin()
{
  int i;
 
  for ( i=0; i < 91; i++ ) {
        TSIN[i] = sin((PI*i)/180.0);
        TCOS[i] = cos((PI*i)/180.0);
  }
}
/*****************************************************************************/ 
void RenderStick()
{
	StickMode = TRUE;
	dessine();
}
/*****************************************************************************/
void RenderBallStick()
{
	StickMode = FALSE;
	dessine();
}
/*****************************************************************************/
void ActivateButtonOperation (GtkWidget *widget, guint data)
{
	SetOperation (widget,data);
}
/*****************************************************************************/
void SetOperation (GtkWidget *widget, guint data)
{
	gchar* temp = NULL;
	if(data == CENTER)
	{
			TransX = 0;
			TransY = 0;
			dessine();
		return;
	}
	OperationType = data ;
	switch(data)
	{
		case ROTATION	: temp = g_strdup(" Press the Left mouse button and move your mouse for a \"Rotate molecule\". ");break;
		case ROTATIONZ	: temp = g_strdup(" Press the Left mouse button and move your mouse for a \"Rotate molecule about z axis\". ");break;
		case TRANSMOVIE : temp = g_strdup(" Press the Left mouse button and move your mouse for a \"Translation\". ");break;
		case SCALEGEOM	: temp = g_strdup(" Press the Left mouse button and move your mouse for a \"Zoom\". ");break;
		case SCALESTICK : temp = g_strdup(" Press the Left mouse button and move your mouse for \"Scale Stick\". ");break;
		case SCALEBALL  :  temp = g_strdup(" Press the Left mouse button and move your mouse for \"Scale Ball\". ");break;
		case SCALEDIPOLE:  temp = g_strdup(" Press the Left mouse button and move your mouse for \"Scale Dipole\". ");break;
		case SELECTFRAG :  temp = g_strdup(" Press the Left mouse button and move your mouse for \"select a fragments\".Use shift key for more selections. ");break;
		case SELECTRESIDUE :  temp = g_strdup("  Press the Left mouse button for pick an atom, all atoms for residue of this atom are selected(or unselected).");break;
		case DELETEFRAG :  temp = g_strdup(" Press the Left mouse button(for pick an atom or all selected atoms) and release for \"Delete selected atom(s)\". ");break;
		case ROTLOCFRAG :  temp = g_strdup(" Press the Left mouse button and move your mouse for \"Rotatation of selected atom(s)[Local Rotation]\". ");break;
		case ROTZLOCFRAG :  temp = g_strdup(" Press the Left mouse button and move your mouse for \"Rotation, about z axis, of selected atom(s)[Local Rotation]\". ");break;
		case MOVEFRAG   :  temp = g_strdup(" Press the Left mouse button(for pick an atom or all slected atoms) and move your mouse for \"Move selected atom(s)\". ");break;
		case INSERTATOM :  temp = g_strdup(" Press and release the Left mouse button for \"Insert an atom\".\"Pick an atom for replace it.\"");break;
		case MESURE		:  temp = g_strdup(" Press and release the Left mouse button for \"Select your atoms\". ");
							HideShowMesure(FALSE);
							change_of_center(NULL,NULL);
							dessine();
							break;
		case ADDFRAGMENT :  temp = g_strdup(" Press and release the Left mouse button for \"Insert a Fragment\". ");break;
	}
	if(temp)
	{
		gtk_statusbar_pop(GTK_STATUSBAR(StatusOperation),idStatusOperation);
		gtk_statusbar_push(GTK_STATUSBAR(StatusOperation),idStatusOperation,temp);
		g_free(temp);
	}
	dessine();
}
/*****************************************************************************/
void setPersonalFragment(Fragment F)
{
	gint i;
	Frag.NAtoms = F.NAtoms;
	Frag.Atoms = g_malloc(Frag.NAtoms*sizeof(Atom));
	for(i=0;i<F.NAtoms;i++)
	{
		Frag.Atoms[i].Residue = g_strdup(F.Atoms[i].Residue);
		Frag.Atoms[i].Symb = g_strdup(F.Atoms[i].Symb);
		Frag.Atoms[i].Type = g_strdup(F.Atoms[i].Type);
		Frag.Atoms[i].Coord[0] = F.Atoms[i].Coord[0];
		Frag.Atoms[i].Coord[1] = F.Atoms[i].Coord[1];
		Frag.Atoms[i].Coord[2] = F.Atoms[i].Coord[2];
		Frag.Atoms[i].Charge = F.Atoms[i].Charge;
	}
	Frag.atomToDelete = F.atomToDelete; 
	Frag.atomToBondTo = F.atomToBondTo;
	Frag.angleAtom    = F.angleAtom;

	SetOperation (NULL,ADDFRAGMENT);
}
/*****************************************************************************/
void AddFragment(GtkWidget *widget, guint data)
{
	/*
	switch(data)
	{
		case WATER : Frag = GetFragment("Water");break;
		case AMMONIA : Frag = GetFragment("Ammonia");break;
		case FORMALDEHYDE : Frag = GetFragment("Formaldehyde");break;
		case FORMAMIDE : Frag = GetFragment("Formamide");break;
		case GLYCEROL : Frag = GetFragment("Glycerol");break;
		case GLYCOL : Frag = GetFragment("Glycol");break;
		case HYDRAZONE : Frag = GetFragment("Hydrazone");break;
		case IMINE : Frag = GetFragment("Imine");break;
		case UREA : Frag = GetFragment("Urea");break;
	}
	*/
	Frag = GetFragment(FragItems[data].Name);
	SetOperation (NULL,ADDFRAGMENT);
}
/*****************************************************************************/
void addAFragment(gchar* fragName)
{
	if(fragName) Frag = GetFragment(fragName);
	else return;
	SetOperation (NULL,ADDFRAGMENT);
}
/*****************************************************************************/
void SetLabelOptions (GtkWidget *widget, guint data)
{
	if(LabelOption != data)
	{
		LabelOption = data ;
		dessine();
	}
}
/*****************************************************************************/
void SetLabelDistances(GtkWidget *win,gboolean YesNo)
{
	DrawDistance = !DrawDistance;
	dessine();
}
/*****************************************************************************/
void SetLabelDipole(GtkWidget *win,gboolean YesNo)
{
	DrawDipole = !DrawDipole;
	dessine();
}
/*****************************************************************************/
void RenderShad(GtkWidget *win,gboolean YesNo)
{
	ShadMode = !ShadMode;
	dessine();
}
/*****************************************************************************/
void RenderPers(GtkWidget *win,gboolean YesNo)
{
	PersMode = !PersMode;
	if(PersMode)
		define_coefs_pers();
	dessine();
}
/*****************************************************************************/
void RenderLight(GtkWidget *win,gboolean YesNo)
{
	LightMode = !LightMode;
	dessine();
}
/*****************************************************************************/
void RenderHBonds(GtkWidget *win,gboolean YesNo)
{
	ShowHBonds = !ShowHBonds;
	dessine();
}
/*****************************************************************************/
void RenderDipole(GtkWidget *win,gboolean YesNo)
{
	ShowDipole = !ShowDipole;
	dessine();
}
/*****************************************************************************/
void set_dipole_from_charges()
{
	gint i;
	gint j;

	create_GeomXYZ_from_draw_grometry();
	NumSelectedAtom = -1;
	unselect_all_atoms();
	Dipole.def = TRUE;
	for(i=0;i<3;i++)
		Dipole.Value[i] = 0.0;
	for(j=0;j<(gint)Natoms;j++)
	{
		Dipole.Value[0] += geometry0[j].X*geometry0[j].Charge;
		Dipole.Value[1] += geometry0[j].Y*geometry0[j].Charge;
		Dipole.Value[2] += geometry0[j].Z*geometry0[j].Charge;

	}	
	define_geometry();
	dessine();
}
/*****************************************************************************/
gchar *get_distance(gint i,gint j)
{
        Point A;
        Point B;
        guint k;
        guint Ni=-1;
        guint Nj=-1;
        gchar *serr;

       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)i)
		Ni = k;
       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)j)
		Nj = k;
        
        if(Ni==-1 || Nj == -1)
        {
           serr=g_strdup("ERROR");
           return serr; 
        }

	A.C[0]=geometry[Ni].X;
	A.C[1]=geometry[Ni].Y;
	A.C[2]=geometry[Ni].Z;
        
	B.C[0]=geometry[Nj].X;
	B.C[1]=geometry[Nj].Y;
	B.C[2]=geometry[Nj].Z;

        return get_distance_points(A,B,FALSE);
}
/*****************************************************************************/
gchar *get_angle(gint i,gint j,gint l)
{
        Point A;
        Point B;
        guint k;
        guint Ni=0;
        guint Nj=0;
        guint Nl=0;

       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)i)
		Ni = k;
       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)j)
		Nj = k;
       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)l)
		Nl = k;
        

	A.C[0]=geometry[Ni].X-geometry[Nj].X;
	A.C[1]=geometry[Ni].Y-geometry[Nj].Y;
	A.C[2]=geometry[Ni].Z-geometry[Nj].Z;
        
	B.C[0]=geometry[Nl].X-geometry[Nj].X;
	B.C[1]=geometry[Nl].Y-geometry[Nj].Y;
	B.C[2]=geometry[Nl].Z-geometry[Nj].Z;

        return get_angle_vectors(A,B);
}
/*****************************************************************************/
gchar *get_dihedral(gint i,gint j,gint l,gint m)
{
        Point A;
        Point B;
        Point V1;
        Point V2;
        Point W1;
        guint k;
        guint Ni=0;
        guint Nj=0;
        guint Nl=0;
        guint Nm=0;
	gdouble angle;
	gdouble dihsgn;

       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)i)
		Ni = k;
       for (k=0;k<Natoms;k++)
	  if(geometry[k].N==(guint)j)
		Nj = k;
       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)l)
		Nl = k;
       for (k=0;k<Natoms;k++)
	  if(geometry[k].N== (guint)m)
		Nm = k;
        

	V1.C[0]=geometry[Ni].X-geometry[Nj].X;
	V1.C[1]=geometry[Ni].Y-geometry[Nj].Y;
	V1.C[2]=geometry[Ni].Z-geometry[Nj].Z;

	V2.C[0]=geometry[Nl].X-geometry[Nj].X;
	V2.C[1]=geometry[Nl].Y-geometry[Nj].Y;
	V2.C[2]=geometry[Nl].Z-geometry[Nj].Z;

        A = get_produit_vectoriel(V1,V2);

	V1.C[0]=geometry[Nm].X-geometry[Nl].X;
	V1.C[1]=geometry[Nm].Y-geometry[Nl].Y;
	V1.C[2]=geometry[Nm].Z-geometry[Nl].Z;

	V2.C[0]=geometry[Nj].X-geometry[Nl].X;
	V2.C[1]=geometry[Nj].Y-geometry[Nl].Y;
	V2.C[2]=geometry[Nj].Z-geometry[Nl].Z;

        B = get_produit_vectoriel(V2,V1);

        angle = atof(get_angle_vectors(A,B));

        W1 = get_produit_vectoriel(A,B);
        if (get_module(W1)<1e-5 )
              dihsgn = 1.0e0;
        else
	{
        dihsgn = get_scalaire(W1,V2);
        if (dihsgn>0)
            dihsgn = -1.0e0;
        else
           dihsgn = 1.0e0;
	}
          angle *=dihsgn;
	return g_strdup_printf("%f",angle);
}
/*****************************************************************************/
void define_coord_maxmin()
{
	guint i;
        gdouble XmaxMmin;
        gdouble YmaxMmin;
        if(Natoms==0) 
        	return;
	coordmaxmin.Xmax =geometry[0].X;
	coordmaxmin.Ymax =geometry[0].Y;
	coordmaxmin.Zmax =geometry[0].Z;

	coordmaxmin.Xmin =geometry[0].X;
	coordmaxmin.Ymin =geometry[0].Y;
	coordmaxmin.Zmin =geometry[0].Z;

	for (i = 1;i<Natoms;i++)
	{
	if (geometry[i].X>coordmaxmin.Xmax)
			   coordmaxmin.Xmax =geometry[i].X;
	if (geometry[i].X<coordmaxmin.Xmin)
			   coordmaxmin.Xmin =geometry[i].X;

	if (geometry[i].Y>coordmaxmin.Ymax)
			   coordmaxmin.Ymax =geometry[i].Y;
	if (geometry[i].Y<coordmaxmin.Ymin)
			   coordmaxmin.Ymin =geometry[i].Y;

    if (geometry[i].Z>coordmaxmin.Zmax)
			   coordmaxmin.Zmax =geometry[i].Z;	
	if (geometry[i].Z<coordmaxmin.Zmin)
			   coordmaxmin.Zmin =geometry[i].Z;

	}
	XmaxMmin = coordmaxmin.Xmax-coordmaxmin.Xmin;
        if(fabs(XmaxMmin)<1.e-4 ) XmaxMmin = 1.0;
	YmaxMmin = coordmaxmin.Ymax-coordmaxmin.Ymin;
        if(fabs(YmaxMmin)<1.e-4 ) YmaxMmin = 1.0;
        coordmaxmin.Cmax = XmaxMmin;
	if(coordmaxmin.Cmax<YmaxMmin)
        	coordmaxmin.Cmax = YmaxMmin;

}
/*****************************************************************************/
void geometry_in_au()
{
        guint i;
        for(i=0;i<Natoms;i++)
	{
           geometry[i].X *=ANG_TO_BOHR ;
           geometry[i].Y *=ANG_TO_BOHR ;
           geometry[i].Z *=ANG_TO_BOHR ;
        }
}
/*****************************************************************************/
void define_geometry_from_xyz()
{
        guint i;

        for(i=0;i<Natoms;i++)
	{
         if(!test(GeomXYZ[i].X))
                 geometry[i].X = get_value_variableXYZ(GeomXYZ[i].X);
          else
		geometry[i].X = atof(GeomXYZ[i].X);
         if(!test(GeomXYZ[i].Y))
                 geometry[i].Y = get_value_variableXYZ(GeomXYZ[i].Y);
          else
		geometry[i].Y = atof(GeomXYZ[i].Y);
         if(!test(GeomXYZ[i].Z))
                 geometry[i].Z = get_value_variableXYZ(GeomXYZ[i].Z);
          else
		geometry[i].Z = atof(GeomXYZ[i].Z);
	geometry[i].Prop = prop_atom_get(GeomXYZ[i].Symb);
	geometry[i].Type = g_strdup(GeomXYZ[i].Type);
	geometry[i].Residue = g_strdup(GeomXYZ[i].Residue);
	geometry[i].ResidueNumber = GeomXYZ[i].ResidueNumber;
	geometry[i].Charge = atof(GeomXYZ[i].Charge);
	geometry[i].N = i+1;
	}
}
/*****************************************************************************/
gboolean define_geometry_from_zmat()
{
  gdouble cosph,sinph,costh,sinth,coskh,sinkh;
  gdouble cosa,sina,cosd,sind;
  gdouble dist,angle,dihed;
  gdouble xpd,ypd,zpd,xqd,yqd,zqd;
  gdouble xa,ya,za,xb,yb,zb;
  gdouble rbc,xyb,yza,temp;
  gdouble xpa,ypa,zqa;
  gdouble xd,yd,zd;
  gboolean flag;
  gint i, na, nb, nc;

  if (Natoms == 0)
    return( FALSE );
  /* Atom #1 */
  geometry[0].X = 0.0;
  geometry[0].Y = 0.0;
  geometry[0].Z = 0.0;
  geometry[0].N = 1;
  
  if (Natoms == 1)
  {
    geometry[0].Prop = prop_atom_get(Geom[0].Symb);
    geometry[0].Type   = g_strdup(Geom[0].Type);
    geometry[0].Residue   = g_strdup(Geom[0].Residue);
    geometry[0].ResidueNumber   = Geom[0].ResidueNumber;
    geometry[0].Charge = atof(Geom[0].Charge);
    return( TRUE );
  }
  
  /* Atom #2 */
  if(!test(Geom[1].R))
    geometry[1].X = get_value_variableZmat(Geom[1].R);
  else
    geometry[1].X = atof(Geom[1].R);
  geometry[1].Y = 0.0;
  geometry[1].Z = 0.0;
  geometry[1].N = 2;
  
  if( Natoms == 2 )
  {
    geometry[0].Prop = prop_atom_get(Geom[0].Symb);
    geometry[1].Prop = prop_atom_get(Geom[1].Symb);
    geometry[0].Type = g_strdup(Geom[0].Type);
    geometry[1].Type = g_strdup(Geom[1].Type);
    geometry[0].Residue = g_strdup(Geom[0].Residue);
    geometry[1].Residue = g_strdup(Geom[1].Residue);
    geometry[0].ResidueNumber   = Geom[0].ResidueNumber;
    geometry[1].ResidueNumber   = Geom[1].ResidueNumber;
    geometry[0].Charge = atof(Geom[0].Charge);
    geometry[1].Charge = atof(Geom[1].Charge);
    return( TRUE );
  }
  
  /* Atom #3 */
  if(!test(Geom[2].R))
    dist = get_value_variableZmat(Geom[2].R);
  else
    dist = atof(Geom[2].R);

  if(!test(Geom[2].Angle))
    angle = get_value_variableZmat(Geom[2].Angle);
  else
    angle = atof(Geom[2].Angle);

    angle *=  DEG_TO_RAD;

  cosa = cos(angle);
  sina = sin(angle);
  
  if( atoi (Geom[2].NAngle) == 2 )
  	geometry[2].X =  geometry[0].X + cosa*dist;
  else 
  	geometry[2].X =  geometry[1].X - cosa*dist;

  geometry[2].Y =  sina*dist;
  geometry[2].Z = 0.0;
  geometry[2].N = 3;
  
  for (i = 3; i <(gint)Natoms; i++)
  {   
  if(!test(Geom[i].R))
    dist = get_value_variableZmat(Geom[i].R);
  else
    dist = atof(Geom[i].R);

  if(!test(Geom[i].Angle))
    angle = get_value_variableZmat(Geom[i].Angle);
  else
    angle = atof(Geom[i].Angle) ;

  if(!test(Geom[i].Dihedral))
    dihed = get_value_variableZmat(Geom[i].Dihedral);
  else
    dihed = atof(Geom[i].Dihedral) ;

    angle *= DEG_TO_RAD;
    dihed *= DEG_TO_RAD;

    na = atoi(Geom[i].NR)-1;
    nb = atoi(Geom[i].NAngle)-1;
    nc = atoi(Geom[i].NDihedral)-1;
    
    xb = geometry[nb].X - geometry[na].X;
    yb = geometry[nb].Y - geometry[na].Y;
    zb = geometry[nb].Z - geometry[na].Z;
    
    rbc = xb*xb + yb*yb + zb*zb;
    if( rbc < 0.0001 )
      return( FALSE );
    rbc = 1.0/sqrt(rbc);
    
    cosa = cos(angle);
    sina = sin(angle);
    
    
    if( fabs(cosa) >= 0.999999 )
    { 
      /* Colinear */
      temp = dist*rbc*cosa;
      geometry[i].X  = geometry[na].X + temp*xb;
      geometry[i].Y  = geometry[na].Y + temp*yb;
      geometry[i].Z  = geometry[na].Z + temp*zb;
      geometry[i].N = i+1;
    } 
    else
    {
      xa = geometry[nc].X - geometry[na].X;
      ya = geometry[nc].Y - geometry[na].Y;
      za = geometry[nc].Z - geometry[na].Z;
      
      sind = -sin(dihed);
      cosd = cos(dihed);
      
      xd = dist*cosa;
      yd = dist*sina*cosd;
      zd = dist*sina*sind;
      
      xyb = sqrt(xb*xb + yb*yb);
      if( xyb < 0.1 )
      {  
	/* Rotate about y-axis! */
	temp = za; za = -xa; xa = temp;
	temp = zb; zb = -xb; xb = temp;
	xyb = sqrt(xb*xb + yb*yb);
	flag = TRUE;
      }
      else 
	flag = FALSE;
      
      costh = xb/xyb;
      sinth = yb/xyb;
      xpa = costh*xa + sinth*ya;
      ypa = costh*ya - sinth*xa;
      
      sinph = zb*rbc;
      cosph = sqrt(1.0 - sinph*sinph);
      zqa = cosph*za  - sinph*xpa;
      
      yza = sqrt(ypa*ypa + zqa*zqa);
      
      if( yza > 1.0E-10 )
      {   
	coskh = ypa/yza;
	sinkh = zqa/yza;
	
	ypd = coskh*yd - sinkh*zd;
	zpd = coskh*zd + sinkh*yd;
      } 
      else
      { 
	/* coskh = 1.0; */
	/* sinkh = 0.0; */
	ypd = yd;
	zpd = zd;
      }
      
      xpd = cosph*xd  - sinph*zpd;
      zqd = cosph*zpd + sinph*xd;
      xqd = costh*xpd - sinth*ypd;
      yqd = costh*ypd + sinth*xpd;
      
      if( flag )
      { 
	/* Rotate about y-axis! */
	geometry[i].X = geometry[na].X - zqd;
	geometry[i].Y = geometry[na].Y + yqd;
	geometry[i].Z = geometry[na].Z + xqd;
        geometry[i].N = i+1;
      } 
      else
      {  
	geometry[i].X = geometry[na].X + xqd;
	geometry[i].Y = geometry[na].Y + yqd;
	geometry[i].Z = geometry[na].Z + zqd;
        geometry[i].N = i+1;
      }
    }
  }
  for(i=0;i<(gint)Natoms;i++)
  {
	geometry[i].Prop = prop_atom_get(Geom[i].Symb);
    	geometry[i].Type = g_strdup(Geom[i].Type);
    	geometry[i].Residue = g_strdup(Geom[i].Residue);
    	geometry[i].ResidueNumber = Geom[i].ResidueNumber;
    	geometry[i].Charge = atof(Geom[i].Charge);
  }
  return( TRUE );
}
/*****************************************************************************/
void define_good_factor()
{
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;
	gint Xi;
	gint Yi;
	guint i;
	gdouble X;
	gdouble Y;
	gdouble Cmax;
	gint X1,X2;
	gint Y1,Y2;

	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	X1 = Xmax;
	X2 = Xmax;
	Y1 = Ymax;
	Y2 = Ymax;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;

	sort_with_zaxis();
	define_coefs_pers();
	define_coord_maxmin();
	
	for (i = 0;i<Natoms;i++)
	{
		if(PersMode)
		{
			X = geometry[i].X*camera.f/(-geometry[i].Z+camera.position);
			Y = geometry[i].Y*camera.f/(-geometry[i].Z+camera.position);
			Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
		}
		else
		{
			X = geometry[i].X;
			Y = geometry[i].Y;
			Cmax = coordmaxmin.Cmax;
		}
		Xi = (gint)(X/Cmax*factor*Rmax/2)+Xmax/2+TransX;
		Yi = (gint)(-Y/Cmax*factor*Rmax/2)+Ymax/2+TransY;
		if(i==0)
		{
			X1 = Xi; X2 =Xi; Y1 = Yi; Y2 = Yi;
		}
		else
		{
			if(X1>Xi) X1 = Xi;
			if(X2<Xi) X2 = Xi;
			if(Y1>Yi) Y1 = Yi;
			if(Y2<Yi) Y2 = Yi;
		}
	}
	if((X2-X1)>(gint)Xmax)
		factor *= fabs((gdouble)(Xmax-20)/(X2-X1));

	if((Y2-Y1)>(gint)Ymax)
		factor *= fabs((gdouble)(Ymax-20)/(Y2-Y1));
}
/*****************************************************************************/
void define_coord_ecran()
{
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;
	gint Xi;
	gint Yi;
	guint i;
	gdouble X;
	gdouble Y;
	gdouble Cmax;

	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;
	
	for (i = 0;i<Natoms;i++)
	{
	if(PersMode)
	{
	X = geometry[i].X*camera.f/(-geometry[i].Z+camera.position);
	Y = geometry[i].Y*camera.f/(-geometry[i].Z+camera.position);
	Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
	}
	else
	{
	X = geometry[i].X;
	Y = geometry[i].Y;
	Cmax = coordmaxmin.Cmax;
	}
	/*
	Xi = (gint)(geometry[i].X/coordmaxmin.Cmax*factor*Rmax/2)+Xmax/2;
	Yi = (gint)(-geometry[i].Y/coordmaxmin.Cmax*factor*Rmax/2)+Ymax/2;
	*/
	Xi = (gint)(X/Cmax*factor*Rmax/2)+Xmax/2;
	Yi = (gint)(-Y/Cmax*factor*Rmax/2)+Ymax/2;

	geometry[i].Xi = Xi + TransX;
	geometry[i].Yi = Yi + TransY;
	geometry[i].Rayon = (gushort)(geometry[i].Prop.radii/coordmaxmin.Cmax*factor*Rmax/2);
	}
	CenterCoor[0]=0.0;
	CenterCoor[1]=0.0;
	for (i = 0;i<Natoms;i++)
	{
	CenterCoor[0] +=geometry[i].Xi;
	CenterCoor[1] +=geometry[i].Yi;
	}

	CenterCoor[0] /=Natoms;
	CenterCoor[1] /=Natoms;
	if(Ddef)
	{
		for(i=0;i<NDIVDIPOLE;i++)
		{
			if(PersMode)
			{
			X = dipole[i][0]*camera.f/(-dipole[i][2]+camera.position);
			Y = dipole[i][1]*camera.f/(-dipole[i][2]+camera.position);
			Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
			}
			else
			{
			X = dipole[i][0];
			Y = dipole[i][1];
			Cmax = coordmaxmin.Cmax;
			}
			DXi[i] = (gint)(X/Cmax*factor*Rmax/2)+Xmax/2 + TransX;
			DYi[i] = (gint)(-Y/Cmax*factor*Rmax/2)+Ymax/2 + TransY;
		}
	}
}
/*****************************************************************************/
void sort_with_zaxis()
{
	guint i;
	guint j;
	guint k;
	GeomDef tmpgeom;
	for (i = 0;i<Natoms-1;i++)
	{
        	tmpgeom = geometry[i];
		k=i;
		for (j = i+1;j<Natoms;j++)
			if(tmpgeom.Z>geometry[j].Z) 
			{
				k=j;
        			tmpgeom = geometry[k];
			}
		if(k!=i)
		{
        		tmpgeom = geometry[i];
        		geometry[i] = geometry[k];
        		geometry[k] = tmpgeom;


			tmpgeom = geometry0[i];
        		geometry0[i] = geometry0[k];
        		geometry0[k] = tmpgeom;

			if(NumSelectedAtom == (gint)i)
				NumSelectedAtom = (gint)k;
			else
			if(NumSelectedAtom == (gint)k)
				NumSelectedAtom = (gint)i;
		
		}
	}
	calcul_ndipole();
}
/*****************************************************************************/
void define_coefs_pers()
{
	guint i;
        if(fabs(coordmaxmin.Zmax-coordmaxmin.Zmin)<1.e-6)
	{
		camera.position = 10;
		camera.f = 5;
        	for(i=0;i<Natoms;i++)
			geometry[i].Coefpers = 1.0;
	}
        else
	{
		gdouble posx = 4*fabs(coordmaxmin.Xmax-coordmaxmin.Xmin);
		gdouble posy = 4*fabs(coordmaxmin.Ymax-coordmaxmin.Ymin);
		gdouble posz = 4*fabs(coordmaxmin.Zmax-coordmaxmin.Zmin);
		gdouble pos = posx;

		if(pos<posy) pos = posy;
		if(pos<posz) pos = posz;

		camera.position = pos;

		camera.f = camera.position/2;
        	for(i=0;i<Natoms;i++)
			geometry[i].Coefpers = 1.5*camera.f/(-geometry[i].Z+camera.position); 
	}
}
/*****************************************************************************/
void set_color_shad(GdkColor *color,guint i)
{
 gdouble Coef=1.0;
 if(fabs(coordmaxmin.Zmax-coordmaxmin.Zmin)>1.e-6)
 {
 	Coef = fabs(0.99-0.2*(coordmaxmin.Zmax-geometry[i].Z)/(coordmaxmin.Zmax-coordmaxmin.Zmin));
        if(Coef<1.0)
	{
	color->red =  (gushort)(color->red*Coef) ;
 	color->green =  (gushort)(color->green*Coef) ;
 	color->blue =  (gushort)(color->blue*Coef) ;
	}
 }
}
/*****************************************************************************/
void rotationGen(gdouble alpha,gdouble Axe[],gdouble A[],gdouble B[])
{
/* Axe est un tableau de 2 elements qui definit l'axe de rotation qui se trouve dans le paln xOy*/
/* theta angle entre l'axe de rotation et l'axe x. l'axe de rotation se trouve dans le plan xoy */
/* alpha angle rotation autour de l'axe de rotation defini par theta */
	gdouble cosa = cos(alpha/180*PI);
	gdouble sina = sin(alpha/180*PI);
        gdouble cost=Axe[0]/sqrt(Axe[0]*Axe[0] + Axe[1]*Axe[1] );
        gdouble sint=Axe[1]/sqrt(Axe[0]*Axe[0] + Axe[1]*Axe[1] );
	
	B[0] = A[0]*cost*cost + A[1]*sint*cost + A[0]*sint*sint*cosa - A[1]*cost*cosa*sint+A[2]*sint*sina;
	B[1] = A[0]*cost*sint + A[1]*sint*sint - A[0]*sint*cost*cosa + A[1]*cost*cosa*cost-A[2]*cost*sina;
	B[2] = -A[0]*sint*sina + A[1]*cost*sina + A[2]*cosa;
}
/*****************************************************************************/
static gint replace_atom()
{
	g_free(geometry[NumSelectedAtom].Prop.symbol);
	geometry[NumSelectedAtom].Prop = prop_atom_get(AtomToInsert);
	g_free(geometry0[NumSelectedAtom].Prop.symbol);
	geometry0[NumSelectedAtom].Prop = prop_atom_get(AtomToInsert);
	g_free(geometry[NumSelectedAtom].Type);
	geometry[NumSelectedAtom].Type = g_strdup(AtomToInsert);
	return 1;
}
/*****************************************************************************/
static gint insert_atom(GtkWidget *widget,GdkEvent *event)
{
	int x, y;
	GdkEventButton *bevent=(GdkEventButton *)event;
	gdouble X;
	gdouble Y;
	gdouble Z;
	gdouble Cmax;
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;
	
	if(Natoms>0 && NumProcheAtom<0)
		return -1;
	if(NumSelectedAtom>-1)
	{
		return replace_atom();
	}

	if(Natoms>0)
	{
		geometry0 = g_realloc(geometry0,(Natoms+1)*sizeof(GeomDef));
		geometry = g_realloc(geometry,(Natoms+1)*sizeof(GeomDef)); 
	}
	else
	{
		geometry0 = g_malloc(sizeof(GeomDef));
		geometry = g_malloc(sizeof(GeomDef)); 
	}

	Ddef = FALSE;

	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;
	

	x = bevent->x;
	y = bevent->y;
  
	if(Natoms>0)
	{
		if(PersMode)
			Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
		else
			Cmax = coordmaxmin.Cmax;
	}
	else
	{
		geometry[Natoms].Prop = prop_atom_get(AtomToInsert);
		Cmax = 4*geometry[Natoms].Prop.covalentRadii;
		coordmaxmin.Cmax = Cmax;
	}

	X = (gfloat)(x-Xmax/2-TransX)*2.0*Cmax/(factor*Rmax);
	Y = -(gfloat)(y-Ymax/2-TransY)*2.0*Cmax/(factor*Rmax);
	if(Natoms>0)
		Z = geometry[NumProcheAtom].Z;
	else
		Z = 0.0;

	if(PersMode)
	{
		X = X/camera.f*(-Z+camera.position);
		Y = Y/camera.f*(-Z+camera.position);
	}
	{
		gfloat m[4][4];
		gfloat **m0 = g_malloc(3*sizeof(gfloat*));
		gfloat** minv;
		gint i,j;

		gdouble A[3];
		gdouble B[3];
		guint k;

		for(i=0;i<3;i++)
			m0[i] = g_malloc(3*sizeof(gfloat));

		build_rotmatrix(m,Quat);

		for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m0[i][j] = m[i][j];

		minv = Inverse(m0,3,1e-7);
		if(minv)
		{
			A[0] = X;
			A[1] = Y;
			A[2] = Z;
			for(j=0;j<3;j++)
			{
				B[j] = 0.0;
				for(k=0;k<3;k++)
				B[j] += minv[k][j]*A[k];
			}
			geometry[Natoms].X=B[0];
			geometry[Natoms].Y=B[1];
			geometry[Natoms].Z=B[2];
			geometry[Natoms].Prop = prop_atom_get(AtomToInsert);
			geometry[Natoms].Type = g_strdup(AtomToInsert);
			geometry[Natoms].N = Natoms+1;
			if(Natoms==0)
			{
				geometry[Natoms].Residue = g_strdup(AtomToInsert);
				geometry[Natoms].ResidueNumber = 0;
			}
			else
			{
				gint k;
				gint proche = 0;
				gdouble d;
				gdouble d1;
				d = get_real_distance2(geometry,0,Natoms);
				for(k=1;k<(gint)Natoms;k++)
				{
					
					d1 = get_real_distance2(geometry,k,Natoms);
					if(d1<d)
					{
						proche = k;
						d = d1;
					}
				}
				geometry[Natoms].Residue = g_strdup(geometry[proche].Residue);
				geometry[Natoms].ResidueNumber = geometry[proche].ResidueNumber;
			}

			geometry[Natoms].Charge = 0.0;

			geometry0[Natoms].Prop = prop_atom_get(AtomToInsert);
			geometry0[Natoms].Type = g_strdup(AtomToInsert);
			geometry0[Natoms].Residue = g_strdup(geometry[Natoms].Residue);
			geometry0[Natoms].ResidueNumber = geometry[Natoms].ResidueNumber;
			geometry0[Natoms].X = geometry[Natoms].X;
			geometry0[Natoms].Y = geometry[Natoms].Y;
			geometry0[Natoms].Z = geometry[Natoms].Z;
			geometry0[Natoms].Charge = 0.0;
			geometry0[Natoms].N = Natoms+1;

			for(i=0;i<3;i++)
				if(minv[i])
				g_free(minv[i]);
			g_free(minv);
			Natoms++;
		}
		if(m0)
		{
			for(i=0;i<3;i++)
				if(m0[i])
					g_free(m0[i]);
				g_free(m0);
		}
	}
	Ddef = FALSE;
	dessine();
	set_statubar_pop_sel_atom();
	return TRUE;
}
/*****************************************************************************/
static void select_fragment(gint NDelAtom)
{
	gint i;

	if(!NumFatoms)
		g_free(NumFatoms);
	NumFatoms = NULL;

	NFatoms = Frag.NAtoms-NDelAtom;
	if(NFatoms<1)
		return;
	NumFatoms = g_malloc(NFatoms*sizeof(gint));
	for(i=0;i<(gint)NFatoms;i++)
	{
			NumFatoms[i] = geometry[i+Natoms-NFatoms].N;
	}
}
/*****************************************************************************/
static gint get_number_new_residue()
{
	gint numMax =-1;
	gint i;
	if(Natoms<1 || !geometry0)
		return numMax + 1;
	for(i=0;i<(gint)Natoms;i++)
		if(numMax<geometry0[i].ResidueNumber)
			numMax = geometry0[i].ResidueNumber;
	return numMax +1;
}
/*****************************************************************************/
static gint insert_fragment(GtkWidget *widget,GdkEvent *event)
{
	int x, y;
	GdkEventButton *bevent=(GdkEventButton *)event;
	gdouble X;
	gdouble Y;
	gdouble Z;
	gdouble Cmax;
	gushort Xmax;
	gushort Ymax;
	gushort Rmax;
	gint i;
	gint ns;
	gdouble xii;
	gdouble yii;
	gdouble d1;
	gdouble d2;
	gint ToBond=-1;
	gint ToAngle=-1;
	gint* atomlist = NULL;
	gint NDelAtom = 0;

	
	if(Natoms>0 && NumProcheAtom<0)
	{
		FreeFragment(Frag);
		return 0;
	}
	if(Frag.NAtoms<=0)
	{
		FreeFragment(Frag);
		return 0;
	}

	if(Natoms>0)
	{
		geometry0 = g_realloc(geometry0,(Natoms+Frag.NAtoms)*sizeof(GeomDef));
		geometry  = g_realloc(geometry,(Natoms+Frag.NAtoms)*sizeof(GeomDef)); 
	}
	else
	{
		geometry0 = g_malloc(Frag.NAtoms*sizeof(GeomDef));
		geometry  = g_malloc(Frag.NAtoms*sizeof(GeomDef)); 
	}

	Ddef = FALSE;

	Xmax=ZoneDessin->allocation.width;
	Ymax=ZoneDessin->allocation.height;
	Rmax = Xmax;
	if(Rmax<Ymax)
		Rmax = Ymax;
	

	x = bevent->x;
	y = bevent->y;
  
	ns = -1;
	if(Natoms>0)
	{
		if(PersMode)
			Cmax  = coordmaxmin.Cmax*camera.f/(camera.position);
		else
			Cmax = coordmaxmin.Cmax;
		for(i=0;i<(gint)Natoms;i++)
		{
			xii = x-geometry[i].Xi;
			yii = y-geometry[i].Yi;
			d1 = xii*xii+yii*yii;
			d2 = d1-(gdouble)geometry[i].Rayon*(gdouble)geometry[i].Rayon;
			if(d2<0)
				ns = i;
		}
	}
	else
	{
		Natoms = 0;
		for(i=0;i<Frag.NAtoms;i++)
			geometry[Natoms+i].Prop = prop_atom_get(Frag.Atoms[i].Symb);
		Cmax = 4*geometry[Natoms].Prop.covalentRadii;
		for(i=1;i<Frag.NAtoms;i++)
			if(Cmax<geometry[Natoms+i].Prop.covalentRadii)
			       Cmax	= geometry[Natoms+i].Prop.covalentRadii; 
		coordmaxmin.Cmax = Cmax;
	}

	X = (gfloat)(x-Xmax/2-TransX)*2.0*Cmax/(factor*Rmax);
	Y = -(gfloat)(y-Ymax/2-TransY)*2.0*Cmax/(factor*Rmax);
	if(Natoms>0)
		Z = geometry[NumProcheAtom].Z;
	else
		Z = 0.0;

	if(PersMode)
	{
		X = X/camera.f*(-Z+camera.position);
		Y = Y/camera.f*(-Z+camera.position);
	}
	{
		gfloat m[4][4];
		gfloat **m0 = g_malloc(3*sizeof(gfloat*));
		gfloat** minv;
		gint i,j;

		gdouble A[3];
		gdouble B[3];
		guint k;

		for(i=0;i<3;i++)
			m0[i] = g_malloc(3*sizeof(gfloat));

		build_rotmatrix(m,Quat);

		for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m0[i][j] = m[i][j];

		minv = Inverse(m0,3,1e-7);
		if(minv)
		{
			A[0] = X;
			A[1] = Y;
			A[2] = Z;
			for(j=0;j<3;j++)
			{
				B[j] = 0.0;
				for(k=0;k<3;k++)
				B[j] += minv[k][j]*A[k];
			}
			if(ns!=-1)
			{
				atomlist = g_malloc((Frag.NAtoms-1)*sizeof(gint));
					B[0] = geometry0[ns].X;
					B[1] = geometry0[ns].Y;
					B[2] = geometry0[ns].Z;

				if(Frag.atomToDelete>-1)
				{
					B[0] = geometry0[ns].X - Frag.Atoms[Frag.atomToDelete].Coord[0];
					B[1] = geometry0[ns].Y - Frag.Atoms[Frag.atomToDelete].Coord[1];
					B[2] = geometry0[ns].Z - Frag.Atoms[Frag.atomToDelete].Coord[2];
				}
			}
			j = -1;
			ToBond = -1;
			ToAngle = -1;

			for(i=0;i<Frag.NAtoms;i++)
			{
				if(ns!=-1 && i== Frag.atomToDelete)
				{
					NDelAtom = 1;
					continue;
				}
				j++;
				geometry0[Natoms+j].X=B[0]+Frag.Atoms[i].Coord[0];
				geometry0[Natoms+j].Y=B[1]+Frag.Atoms[i].Coord[1];
				geometry0[Natoms+j].Z=B[2]+Frag.Atoms[i].Coord[2];
				if(ns!=-1)
				{
					if(i==Frag.atomToBondTo)
						ToBond = Natoms+j;

					if(i==Frag.angleAtom)
						ToAngle = Natoms+j;

					atomlist[j] = Natoms+j;

				}
				geometry0[Natoms+j].Prop = prop_atom_get(Frag.Atoms[i].Symb);
				geometry0[Natoms+j].Type =g_strdup(Frag.Atoms[i].Type);
				geometry0[Natoms+j].Residue =g_strdup(Frag.Atoms[i].Residue);
				geometry0[Natoms+j].ResidueNumber= get_number_new_residue();
				geometry0[Natoms+j].Charge = Frag.Atoms[i].Charge;
				geometry0[Natoms+j].N = Natoms+j+1;

				geometry[Natoms+j].Prop = prop_atom_get(Frag.Atoms[i].Symb);
				geometry[Natoms+j].Type =g_strdup(Frag.Atoms[i].Type);
				geometry[Natoms+j].Residue =g_strdup(Frag.Atoms[i].Residue);
				geometry[Natoms+j].ResidueNumber=geometry0[Natoms+j].ResidueNumber;
				geometry[Natoms+j].Charge = Frag.Atoms[i].Charge;
				geometry[Natoms+j].N = Natoms+j+1;
			}

			/*
			printf("Atom to delete : %d\n ",Frag.atomToDelete);
			if(ns !=-1)
				printf("Atom %d connect to %d\n ",Frag.atomToBondTo,ns);
			*/
			for(i=0;i<3;i++)
				if(minv[i])
					g_free(minv[i]);
			
			g_free(minv);
			
			Natoms+=Frag.NAtoms;
			
			if(ns!=-1)
			{
				gint nsBond = -1;
				gint Ok = 1;
				for(i=0;i<(gint)Natoms;i++)
				{
					Ok = 1;
					for(j=0;j<(gint)Frag.NAtoms-1;j++)
					{
						if((i)==atomlist[j])
						{
							Ok = 0;
							break;
						}
					}
					if(Ok==0) continue;
					if( i!= ns && draw_lines_yes_no(ns,i) )
					{
						nsBond = i;
						break;
					}
				}

				/*setAngle(ns,ToBond,Natoms-1,geometry0,Frag.NAtoms-1,atomlist,109.0);*/
				if(nsBond >-1 && ToBond > -1)
					SetAngle(Natoms-1,geometry0,nsBond, ns, ToBond,109.0,atomlist, Frag.NAtoms-1);
				if(nsBond >-1 && ToBond > -1 && ToAngle>-1)
					SetTorsion(Natoms,geometry0, nsBond,ns, ToBond, ToAngle, 180.0,atomlist, Frag.NAtoms-1);
				
				if(!atomlist)
					g_free(atomlist);
				
				Natoms--;
				geometry0 = g_realloc(geometry0,(Natoms)*sizeof(GeomDef));
				geometry  = g_realloc(geometry,(Natoms)*sizeof(GeomDef)); 
			}
		}
		if(m0)
		{
			for(i=0;i<3;i++)
				if(m0[i])
					g_free(m0[i]);
				g_free(m0);
		}
	}
	Ddef = FALSE;

	if(Natoms-Frag.NAtoms+NDelAtom>0)
		select_fragment(NDelAtom);
	SetOriginAtCenter(NULL,0,NULL);
	define_good_factor();

	dessine();
	set_statubar_pop_sel_atom();
	FreeFragment(Frag);
	return 1;
}
/*****************************************************************************/
/*****************************************************************************/
void delete_one_atom(gint NumDel)
{

	gint i;
	gint j;

	for (i=NumDel;i<(gint)Natoms-1;i++)
	{
		geometry0[i]=geometry0[i+1];
		geometry[i]=geometry[i+1];
	}
	Natoms--;
	for (i=0;i<(gint)Natoms;i++)
	{
		for(j=0;j<(gint)NFatoms;j++)
		{
			if(NumFatoms[j] ==(gint) geometry[i].N)
				NumFatoms[j] = i+1;
		}
		geometry0[i].N = i+1;
		geometry[i].N = i+1;
	}

	if(Natoms>0)
	{
		geometry0 = g_realloc(geometry0,Natoms*sizeof(GeomDef));
		geometry = g_realloc(geometry,Natoms*sizeof(GeomDef)); 
	}
	else
	{
		if(geometry0)
			g_free(geometry0);
		geometry0 = NULL;
		if(geometry)
			g_free(geometry);
		geometry = NULL;
		Natoms = 0;
	}
	Ddef = FALSE;
}
/*****************************************************************************/
gint index_selected(gint Num)
{
	gint j;
	if(NFatoms<1 || !NumFatoms )
		return -1;

	for(j=0;j<(gint)NFatoms;j++)
		if(NumFatoms[j] == (gint)geometry[Num].N)
			return j;
	return -1;
}
/*****************************************************************************/
gboolean if_selected(gint Num)
{
	gint j;
	if(NFatoms<1 || !NumFatoms )
		return FALSE;

	for(j=0;j<(gint)NFatoms;j++)
		if(NumFatoms[j] == (gint)geometry[Num].N)
			return TRUE;
	return FALSE;
}
/*****************************************************************************/
void delete_all_selected_atoms()
{

	gint i;
	gint j;
	GeomDef tmp;

	for (i=0;i<(gint)Natoms-1;i++)
	{
		if(!if_selected(i))
			continue;

		for(j=i+1;j<(gint)Natoms;j++)
			if(!if_selected(j))
			{
				tmp = geometry0[i];
				geometry0[i] = geometry0[j];
				geometry0[j] = tmp ;
				tmp = geometry[i];
				geometry[i] = geometry[j];
				geometry[j] = tmp ;
				break;
			}
	}

	if(NFatoms>Natoms)
	{
		printf("internal error\n");
		Natoms = 0;
	}
	else
		Natoms-=NFatoms;

	for (i=0;i<(gint)Natoms;i++)
	{
		geometry0[i].N = i+1;
		geometry[i].N = i+1;
	}

	if(Natoms>0)
	{
		geometry0 = g_realloc(geometry0,Natoms*sizeof(GeomDef));
		geometry = g_realloc(geometry,Natoms*sizeof(GeomDef)); 
	}
	else
	{
		if(geometry0)
			g_free(geometry0);
		geometry0 = NULL;
		if(geometry)
			g_free(geometry);
		geometry = NULL;
		Natoms = 0;
	}
	NFatoms = 0;
	if(NumFatoms)
		g_free(NumFatoms);
	NumFatoms = NULL;
	Ddef = FALSE;
}
/*****************************************************************************/
void delete_selected_atoms()
{

	gint i;
	gint j;
	gboolean DelAll = FALSE;

	if(NumSelectedAtom<0)
		return;

	for(i=0;i<(gint)Natoms;i++)
		if((gint)i==NumSelectedAtom)
		{
			for(j = 0;j<(gint)NFatoms;j++)
				if(NumFatoms[j] == (gint)geometry[i].N)
					DelAll = TRUE;
			break;
		}
	if(DelAll==FALSE)
	{
		delete_one_atom(NumSelectedAtom);
		return;
	}
	delete_all_selected_atoms();
}
/*****************************************************************************/
void rotation_geometry_quat(gfloat m[4][4])
{
	gdouble A[3];
	gdouble B[3];
	guint i,j,k;

	/*
		Debug("Rotate matrix : \n");
		for(j=0;j<3;j++)
		{
			for(k=0;k<3;k++)
				Debug("%12.6f ",m[k][j]);
			Debug("\n");
		}
		Debug("\n");
	*/
	for (i=0;i<Natoms;i++)
	{
		A[0] = geometry0[i].X;
		A[1] = geometry0[i].Y;
		A[2] = geometry0[i].Z;
		for(j=0;j<3;j++)
		{
			B[j] = 0.0;
			for(k=0;k<3;k++)
				B[j] += m[k][j]*A[k];
		}
		geometry[i].X=B[0];
		geometry[i].Y=B[1];
		geometry[i].Z=B[2];
	}
	if(Ddef)
	{
		
	for (i=0;i<NDIVDIPOLE;i++)
	{
	A[0] = dipole0[i][0];
	A[1] = dipole0[i][1];
	A[2] = dipole0[i][2];
	for(j=0;j<3;j++)
	{
		B[j] = 0.0;
		for(k=0;k<3;k++)
			B[j] += m[k][j]*A[k];
	}
	dipole[i][0]=B[0];
	dipole[i][1]=B[1];
	dipole[i][2]=B[2];
	}
	}

	sort_with_zaxis();
	define_coefs_pers();
}
/*****************************************************************************/
void rotation_atom_quat(gint i,gfloat m[4][4])
{
	gdouble A[3];
	gdouble B[3];
	guint j,k;

	A[0] = CSselectedAtom[0] ;
	A[1] = CSselectedAtom[1] ;
	A[2] = CSselectedAtom[2] ;
	for(j=0;j<3;j++)
	{
		B[j] = 0.0;
		for(k=0;k<3;k++)
			B[j] += m[k][j]*A[k];
	}
	geometry0[i].X=B[0];
	geometry0[i].Y=B[1];
	geometry0[i].Z=B[2];
}
/*****************************************************************************/
void rotation(double a,double b,double angle,double *ap,double *bp)
{
	double cosangle = cos(angle/180*PI);
	double sinangle = sin(angle/180*PI);
	
	*ap = a*cosangle - b *sinangle;
	*bp = b*cosangle + a *sinangle;
}
/*****************************************************************************/
void set_to_yaxis()
{
	double A;
	double B;
	double angle=90;
	double Xmax,Xmin;
	double Ymax,Ymin;
	double Zmax,Zmin;
	guint i;
	guint axe;


        if(Natoms<1)
          return;

	Xmax =geometry[0].X;
	Ymax =geometry[0].Y;
	Zmax =geometry[0].Z;

	Xmin =geometry[0].X;
	Ymin =geometry[0].Y;
	Zmin =geometry[0].Z;

	for (i = 1;i<Natoms;i++)
	{
	if (geometry[i].X>Xmax)
			  Xmax =geometry[i].X;
	if (geometry[i].X<Xmin)
			  Xmin =geometry[i].X;

	if (geometry[i].Y>Ymax)
			   Ymax =geometry[i].Y;
	if (geometry[i].Y<Ymin)
			  Ymin =geometry[i].Y;

    	if (geometry[i].Z>Zmax)
			Zmax =geometry[i].Z;	
	if (geometry[i].Z<Zmin)
			Zmin =geometry[i].Z;

	}
        axe=0;
        if(fabs(Ymax-Ymin)<=fabs(Xmax-Xmin))
        {
        	if(fabs(Zmax-Zmin)<fabs(Ymax-Ymin))
                    axe=2;
                 else
		    axe=1;
         }
         else
        {
        	if(fabs(Zmax-Zmin)<fabs(Xmax-Xmin))
                    axe=2;
         }
         
        
	if(axe==0)
	{
		for (i=0;i<Natoms;i++)
		{
			A = geometry[i].Z;
			B = geometry[i].X;
			rotation(A,B,angle,&geometry[i].Z,&geometry[i].X);
		}
		for (i=0;i<NDIVDIPOLE;i++)
		{
			A = dipole[i][2];
			B = dipole[i][0];
			rotation(A,B,angle,&dipole[i][2],&dipole[i][0]);
		}
	}
        else if(axe==1)
	{
		for (i=0;i<Natoms;i++)
		{
			A = geometry[i].Y;
			B = geometry[i].Z;
			rotation(A,B,angle,&geometry[i].Y,&geometry[i].Z);
		}
		for (i=0;i<NDIVDIPOLE;i++)
		{
			A = dipole[i][1];
			B = dipole[i][2];
			rotation(A,B,angle,&dipole[i][1],&dipole[i][2]);
		}
	}
}
/*****************************************************************************/
void define_geometry()
{
        guint i;
        guint j;
        gdouble X0[3];

	if(geometry != NULL) 
		{
                for (i=0;i<Natoms;i++)
			g_free(geometry[i].Prop.symbol);
		        
		g_free(geometry);
		geometry = NULL;
		}
        if(MethodeGeom == GEOM_IS_XYZ)
		Natoms = NcentersXYZ;
        else
		Natoms = NcentersZmat;

	geometry =g_malloc(Natoms*sizeof(GeomDef));

        if((MethodeGeom == GEOM_IS_XYZ) && (GeomXYZ  != NULL) ) 
		define_geometry_from_xyz();
        if((MethodeGeom == GEOM_IS_ZMAT) && (Geom  != NULL) ) 
		if(!define_geometry_from_zmat())
		Message("Error in  conversion\n Zmatix to xyz "," Warning ",TRUE);

         if(Units == 1 ) 
		geometry_in_au();
/* Center of molecule */
        if(Natoms<1) return;
        for(i=0;i<3;i++)
		X0[i] = 0.0;
        for(i=0;i<Natoms;i++)
	{
	X0[0] +=geometry[i].X;
	X0[1] +=geometry[i].Y;
	X0[2] +=geometry[i].Z;
	}
        for(i=0;i<3;i++)
		X0[i] /= Natoms;
        for(i=0;i<Natoms;i++)
	{
	geometry[i].X -= X0[0];
	geometry[i].Y -= X0[1];
	geometry[i].Z -= X0[2]; 
	} 

	Ddef = Dipole.def;
	if(Ddef)
	{
		gfloat step[3] ={Dipole.Value[0]/(NDIVDIPOLE-1),Dipole.Value[1]/(NDIVDIPOLE-1),Dipole.Value[2]/(NDIVDIPOLE-1)};
		dipole[0][0] = -X0[0];
		dipole[0][1] = -X0[1];
		dipole[0][2] = -X0[2];
		for(i=1;i<NDIVDIPOLE;i++)
			for(j=0;j<3;j++)
				dipole[i][j] = dipole[0][j]+step[j]*i;
	}

	set_to_yaxis();

	if(geometry0)
		g_free(geometry0);
	geometry0 = NULL;

	geometry0 =g_malloc(Natoms*sizeof(GeomDef));
	for(i=0;i<Natoms;i++)
	{
	geometry0[i].X = geometry[i].X;
	geometry0[i].Y = geometry[i].Y;
	geometry0[i].Z = geometry[i].Z; 
	geometry0[i].N = geometry[i].N; 
	geometry0[i].Prop = prop_atom_get(geometry[i].Prop.symbol);
	geometry0[i].Type = g_strdup(geometry[i].Type);
	geometry0[i].Residue = g_strdup(geometry[i].Residue);
	geometry0[i].ResidueNumber = geometry[i].ResidueNumber;
	geometry0[i].Charge = geometry[i].Charge;
	} 
	if(Ddef)
	{
	for(i=0;i<NDIVDIPOLE;i++)
		for(j=0;j<3;j++)
		{
			dipole0[i][j] = dipole[0][j] + (dipole[i][j]-dipole[0][j])*factordipole;
			dipole00[i][j] = dipole0[i][j];
		}
	}


	sort_with_zaxis();
	define_coord_maxmin();
	define_coefs_pers();
	free_text_to_draw();

}
/*****************************************************************************/
guint get_num_min_rayonIJ(guint i,guint j)
{	
	gint rmin;
	guint kmin;

	rmin = geometry[i].Rayon;
        kmin = i;
	if(rmin > geometry[j].Rayon)
		{
			rmin = geometry[j].Rayon;
			kmin =j;
		}
	return kmin;

}
/*****************************************************************************/
void draw_triangle(gint x1,gint y1,gint x2,gint y2,gint x3,gint y3, GdkColor colori)
{
	GdkColormap *colormap;
        GdkColor color[91];
        gint i;
        GdkVisual* vis;
        gushort temp;
	gint istep;
	GdkPoint points[3] = {{x1,y1},{x2,y2},{x3,y3}};
	gint epaisseur = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	gfloat vx,vy,v2;

	vx = (x2-x1);
	vy = (y2-y1);
	v2 = sqrt(vx*vx + vy*vy);

/*	Debug("ep = %d\n",epaisseur);*/
        color[90]=colori;
   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
 

         vis = gdk_colormap_get_visual(colormap);
    	if (!LightMode) 
        {
            gdk_colormap_alloc_color(colormap,&color[90],FALSE,TRUE);
	    gdk_gc_set_foreground(gc,&color[90]);
	    gdk_gc_set_line_attributes(gc,1,GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);
	    gdk_draw_polygon(pixmap,gc,1,points,3);

            return;
        }

	if(epaisseur>0)
	istep = (gint)(90/epaisseur+1);
	else
	istep = 1;
        if(vis->depth >15)
        for(i=90;i>0;i-=istep)
        {
            color[i].red = (gushort)(colori.red*TCOS[i]); 
            color[i].green =(gushort) (colori.green*TCOS[i]); 
            color[i].blue = (gushort)(colori.blue*TCOS[i]); 
            gdk_colormap_alloc_color(colormap,&color[i],FALSE,TRUE);
        }
        else
        {
                temp = (gushort)(((gdouble)colori.red+(gdouble)colori.green+(gdouble)colori.blue)/3.0);
                if(temp<30000)
                    temp *=2;
                colori.red=temp;
                colori.green=temp;
                colori.blue=temp;
        	for(i=90;i>0;i-=istep)
        	{
            		color[i].red = (gushort)(colori.red*TCOS[i]); 
            		color[i].green =(gushort) (colori.green*TCOS[i]); 
            		color[i].blue = (gushort)(colori.blue*TCOS[i]); 
            		gdk_color_alloc(colormap,&color[i]);
        	}
        }

        color[90]=colori;
        gdk_color_alloc(colormap,&color[90]);
        for(i=90;i>0;i-=istep)
        {
	    epaisseur =(gint) (epaisseur*(TSIN[i])+0.5);
	    /*
	    points[0].x = x1 - vx*epaisseur;
	    points[0].y = y1 - vy*epaisseur;
	    points[1].x = x2 - vx*epaisseur;
	    points[1].y = y2 - vy*epaisseur;
	    points[0].x = x1;
	    points[0].y = y1;
	    points[1].x = x2;
	    points[1].y = y2;
	    */
	/*    gdk_gc_set_foreground(gc,&color[i]);*/
	    gdk_gc_set_foreground(gc,&color[90]);
	    /*gdk_gc_set_line_attributes(gc,1,GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);*/
	    gdk_gc_set_line_attributes(gc,1,GDK_LINE_SOLID,GDK_CAP_BUTT,GDK_JOIN_BEVEL);
	    gdk_draw_polygon(pixmap,gc,1,points,3);
        }

}
/*****************************************************************************/
void draw_line(gint x1,gint y1,gint x2,gint y2,GdkColor colori,gint epaisseuri,
		gfloat *vxp,gfloat *vyp,gint* epaisseurip,gboolean newbond)
{
	GdkColormap *colormap;
        GdkColor color[91];
        gint epaisseur=epaisseuri;
        gint i;
        GdkVisual* vis;
        gushort temp;
	gint istep;

        color[90]=colori;
   	colormap  = gdk_window_get_colormap(ZoneDessin->window);

         vis = gdk_colormap_get_visual(colormap);
    	if (!LightMode) 
        {
	    	gfloat vx = (y2 - y1);
	    	gfloat vy = (x1 - x2);
	    	gfloat v2 = sqrt(vx*vx + vy*vy);
        	GdkColor colorgray;

        	if(vis->depth >15)
		{
          	colorgray.red = (gushort)(colori.red*0.6); 
          	colorgray.green = (gushort)(colori.green*0.6); 
          	colorgray.blue = (gushort)(colori.blue*0.6); 
		}
		else
		{
          	colorgray.red = (gushort)(35000); 
          	colorgray.green = (gushort)(35000); 
          	colorgray.blue = (gushort)(35000); 
		}

            gdk_colormap_alloc_color(colormap,&color[90],FALSE,TRUE);
	    gdk_gc_set_foreground(gc,&color[90]);
	    gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);
	    /*if(v2>2)*/
	    if(v2>=0)
	    gdk_draw_line(pixmap,gc,x1,y1,x2,y2);

            if ( !StickMode )
	    {
	    	if(newbond)
		{
			*vxp = vx;
			*vyp = vy;
			*epaisseurip = epaisseur/4;
		}
	    	if(newbond && v2>2)
	    	{
		   if(vx<0)
		   {
		   	vx = -vx;
		   	vy = -vy;
		   }
		   vx *= 3*epaisseur/v2/8;
		   vy *= 3*epaisseur/v2/8;
		   x1 = (gint)(x1-vx+0.5);
		   x2 = (gint)(x2-vx+0.5);
		   y1 = (gint)(y1-vy+0.5);
		   y2 = (gint)(y2-vy+0.5);
            	gdk_colormap_alloc_color(colormap,&colorgray,FALSE,TRUE);
	    	gdk_gc_set_foreground(gc,&colorgray);
	        gdk_gc_set_line_attributes(gc,epaisseur/4+2,GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);
	        gdk_draw_line(pixmap,gc,x1,y1,x2,y2);
		*vxp = vx;
		*vyp = vy;
		*epaisseurip = epaisseur/4;
	    	}
	    	else
	    	{
		   if(v2<=2)
			   return;
		   if(*vxp *vx<0)
		   {
		   vx = -vx;
		   vy = -vy;
		   }
		   vx *= 3*(*epaisseurip)/v2/2;
		   vy *= 3*(*epaisseurip)/v2/2;

		   x1 = (gint)(x1-vx+0.5);
		   x2 = (gint)(x2-vx+0.5);
		   y1 = (gint)(y1-vy+0.5);
		   y2 = (gint)(y2-vy+0.5);
		   
            	gdk_colormap_alloc_color(colormap,&colorgray,FALSE,TRUE);
	    	gdk_gc_set_foreground(gc,&colorgray);
	        gdk_gc_set_line_attributes(gc,*epaisseurip+2,GDK_LINE_SOLID,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);
	        gdk_draw_line(pixmap,gc,x1,y1,x2,y2);
		
	    	}
	    }
            return;
        }

	if(epaisseur>0)
	istep = (gint)(90/epaisseur+1);
	else
	istep = 1;
        if(vis->depth >15)
        for(i=90;i>0;i-=istep)
        {
            color[i].red = (gushort)(colori.red*TCOS[i]); 
            color[i].green =(gushort) (colori.green*TCOS[i]); 
            color[i].blue = (gushort)(colori.blue*TCOS[i]); 
            gdk_colormap_alloc_color(colormap,&color[i],FALSE,TRUE);
        }
        else
        {
                temp = (gushort)(((gdouble)colori.red+(gdouble)colori.green+(gdouble)colori.blue)/3.0);
                if(temp<30000)
                    temp *=2;
                colori.red=temp;
                colori.green=temp;
                colori.blue=temp;
        	for(i=90;i>0;i-=istep)
        	{
            		color[i].red = (gushort)(colori.red*TCOS[i]); 
            		color[i].green =(gushort) (colori.green*TCOS[i]); 
            		color[i].blue = (gushort)(colori.blue*TCOS[i]); 
            		gdk_color_alloc(colormap,&color[i]);
        	}
        }

        for(i=90;i>0;i-=istep)
        {
	    epaisseur =(gint) (epaisseur*(TSIN[i])+0.5);
	    gdk_gc_set_foreground(gc,&color[i]);
	    gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_BUTT,GDK_JOIN_BEVEL);
	    gdk_draw_line(pixmap,gc,x1,y1,x2,y2);
        }

}
/*****************************************************************************/
GdkColor get_color_string(guint i)
{
 GdkColor color;
 if (ShadMode) 
 {
  color.red   =(gushort)(65535-geometry[i].Prop.color.red*geometry[i].Coefpers);
  color.green =(gushort)(65535-geometry[i].Prop.color.green*geometry[i].Coefpers);
  color.blue  =(gushort)(65535-geometry[i].Prop.color.blue*geometry[i].Coefpers);
 }
 else
 {
  color.red   =FontsStyleLabel.TextColor.red;
  color.green =FontsStyleLabel.TextColor.green;
  color.blue  =FontsStyleLabel.TextColor.blue;
 }
 return color;
}
/*****************************************************************************/
void draw_distance(gint i,gint j,gint x0,gint y0)
{
	GdkColormap *colormap;
        GdkColor color;
 	GdkFont *font = NULL; 
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
  	if(font_desc) font = gdk_font_from_description (font_desc);

        Point A;
        Point B;

	A.C[0]=geometry[i].X;
	A.C[1]=geometry[i].Y;
	A.C[2]=geometry[i].Z;
        
	B.C[0]=geometry[j].X;
	B.C[1]=geometry[j].Y;
	B.C[2]=geometry[j].Z;

        color = get_color_string(i);
	
   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);

	gdk_gc_set_foreground(gc,&color);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, x0,y0,get_distance_points(A,B,TRUE),TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

}
/*****************************************************************************/
void draw_line2(gint epaisseur,guint i,guint j,gint x1,gint y1,gint x2,gint y2,
				GdkColor color1,GdkColor color2)
{
	gint x0;
	gint y0;

        gdouble poid1;
        gdouble poid2;
        gdouble poid;
        gushort rayon;
        gint xp;
        gint yp;
        gdouble k;
	gfloat vx,vy;
	gint ep;

        if ( !StickMode )
        { 
                rayon =(gushort)(geometry[i].Rayon*factorball);
    		if (PersMode) 
                	rayon =(gushort)(geometry[i].Coefpers*geometry[i].Rayon*factorball);

                 k= ((gdouble)rayon*(gdouble)rayon-(gdouble)epaisseur*(gdouble)epaisseur/4.0);
		if(k>0 &&(( (gdouble)(x2-x1)*(gdouble)(x2-x1)+(gdouble)(y2-y1)*(gdouble)(y2-y1) )>2))
                k = (sqrt(k))/(gdouble)(sqrt( (gdouble)(x2-x1)*(gdouble)(x2-x1)+(gdouble)(y2-y1)*(gdouble)(y2-y1) ) );     
                else
                 k=0.0;

                xp = x1 + (gint)(k *(x2-x1)+0.5);
                yp = y1 + (gint)(k *(y2-y1)+0.5);   
        }
        else
        {
	      xp = x1;
              yp = y1;
        }
        poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
        poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
        poid = poid1 + poid2 ;
	x0=(gint)((x1*poid2+x2*poid1)/poid+0.5);
	y0=(gint)((y1*poid2+y2*poid1)/poid+0.5);

	draw_line(xp,yp,x0,y0,color1,epaisseur,&vx,&vy,&ep,TRUE);

	
        k=  (gdouble)(x2-x0)*(gdouble)(x2-x0)+(gdouble)(y2-y0)*(gdouble)(y2-y0);

        if(k>1e-10)
        {
        	x0 = (gint)(x0 -1.0*(gdouble)(x2-x0)/sqrt(k)+0.5),
        	y0 = (gint)(y0 -1.0*(gdouble)(y2-y0)/sqrt(k)+0.5);
        }

	draw_line(x0,y0,x2,y2,color2,epaisseur,&vx,&vy,&ep,FALSE); 
	if(DrawDistance)
                 draw_distance(i,j,x0,y0); 
}
/*****************************************************************************/
static void draw_line_hbond(gint x1,gint y1,gint x2,gint y2,GdkColor color,gint epaisseur)
{
	GdkColormap *colormap;

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
        gdk_colormap_alloc_color(colormap,&color,FALSE,TRUE);
	gdk_gc_set_foreground(gc,&color);
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_ON_OFF_DASH,GDK_CAP_NOT_LAST,GDK_JOIN_MITER);

	gdk_draw_line(pixmap,gc,x1,y1,x2,y2);
}
/*****************************************************************************/
static void draw_line2_hbond(gint x1,gint y1,gint x2,gint y2, gint i, gint j, GdkColor color1,GdkColor color2, gint epaisseur)
{
	gint x0;
	gint y0;

        gdouble poid1;
        gdouble poid2;
        gdouble poid;
        gushort rayon;
        gint xp;
        gint yp;
        gdouble k;

        if ( !StickMode )
        { 
                rayon =(gushort)(geometry[i].Rayon*factorball);
    		if (PersMode) rayon =(gushort)(geometry[i].Coefpers*geometry[i].Rayon*factorball);

                 k= ((gdouble)rayon*(gdouble)rayon-(gdouble)epaisseur*(gdouble)epaisseur/4.0);
		if(k>0 &&(( (gdouble)(x2-x1)*(gdouble)(x2-x1)+(gdouble)(y2-y1)*(gdouble)(y2-y1) )>2))
                k = (sqrt(k))/(gdouble)(sqrt( (gdouble)(x2-x1)*(gdouble)(x2-x1)+(gdouble)(y2-y1)*(gdouble)(y2-y1) ) );     
                else k=0.0;

                xp = x1 + (gint)(k *(x2-x1)+0.5);
                yp = y1 + (gint)(k *(y2-y1)+0.5);   
        }
        else
        {
	      xp = x1;
              yp = y1;
        }
        poid1 = geometry[i].Prop.covalentRadii+geometry[i].Prop.radii;
        poid2 = geometry[j].Prop.covalentRadii+geometry[j].Prop.radii;
        poid = poid1 + poid2 ;
	x0=(gint)((x1*poid2+x2*poid1)/poid+0.5);
	y0=(gint)((y1*poid2+y2*poid1)/poid+0.5);

	draw_line_hbond(xp,yp,x0,y0,color1,epaisseur);

        k=  (gdouble)(x2-x0)*(gdouble)(x2-x0)+(gdouble)(y2-y0)*(gdouble)(y2-y0);

        if(k>1e-10)
        {
        	x0 = (gint)(x0 -1.0*(gdouble)(x2-x0)/sqrt(k)+0.5),
        	y0 = (gint)(y0 -1.0*(gdouble)(y2-y0)/sqrt(k)+0.5);
        }

	draw_line_hbond(x0,y0,x2,y2,color2,epaisseur); 
	if(DrawDistance) draw_distance(i,j,x0,y0); 
}
/*****************************************************************************/
void draw_anneau(gint xi,gint yi,gint rayoni,GdkColor colori)
{
	GdkColormap *colormap;
        gint x=xi,y=yi,rayon=rayoni;

        colormap  = gdk_window_get_colormap(ZoneDessin->window);
        gdk_colormap_alloc_color(colormap,&colori,FALSE,TRUE);
	gdk_gc_set_foreground(gc,&colori);
	gdk_gc_set_line_attributes(gc,2,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	/*gdk_gc_set_fill(gc,GDK_SOLID);*/
	gdk_draw_arc(pixmap,gc,FALSE,x-rayon,y-rayon,2*rayon,2*rayon,0,380*64);
}
/*****************************************************************************/
void draw_cercle(gint xi,gint yi,gint rayoni,GdkColor colori)
{
	GdkColormap *colormap;
        gint x=xi,y=yi,rayon=rayoni;
        GdkColor color[91];
        int i;
        GdkVisual* vis;
        gushort temp;
        GdkColor colorgray;

          colorgray.red = (gushort)(colori.red*0.6); 
          colorgray.green = (gushort)(colori.green*0.6); 
          colorgray.blue = (gushort)(colori.blue*0.6); 

        colormap  = gdk_window_get_colormap(ZoneDessin->window);
        vis = gdk_colormap_get_visual(colormap);
        	if(vis->depth >15)
		{
          	colorgray.red = (gushort)(colori.red*0.6); 
          	colorgray.green = (gushort)(colori.green*0.6); 
          	colorgray.blue = (gushort)(colori.blue*0.6); 
		}
		else
		{
          	colorgray.red = (gushort)(35000); 
          	colorgray.green = (gushort)(35000); 
          	colorgray.blue = (gushort)(35000); 
		}

        gdk_colormap_alloc_color(colormap,&colori,FALSE,TRUE);
	gdk_gc_set_foreground(gc,&colori);
	gdk_gc_set_line_attributes(gc,2,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gdk_gc_set_fill(gc,GDK_SOLID);
	gdk_draw_arc(pixmap,gc,TRUE,x-rayon,y-rayon,2*rayon,2*rayon,0,380*64);
        gdk_colormap_alloc_color(colormap,&colorgray,FALSE,TRUE);
	gdk_gc_set_foreground(gc,&colorgray);
	gdk_draw_arc(pixmap,gc,TRUE,x-rayon,y-rayon,2*rayon,2*rayon,90*64,180*64);
	gdk_gc_set_foreground(gc,&colori);
	gdk_draw_arc(pixmap,gc,TRUE,x-rayon/2,y-rayon,rayon,2*rayon,0,380*64);

    	if (!LightMode) 
                return;

        for(i=90;i>0;i--)
        {
            color[i].red = (gushort)(colori.red*TCOS[i]); 
            color[i].green =(gushort) (colori.green*TCOS[i]); 
            color[i].blue = (gushort)(colori.blue*TCOS[i]); 
        }
        if(vis->depth <16)
        {

                temp = (gushort)(((gdouble)colori.red+(gdouble)colori.green+(gdouble)colori.blue)/3.0);
                if(temp<30000)
                    temp *=2;
                colori.red=temp;
                colori.green=temp;
                colori.blue=temp;
        	for(i=90;i>0;i--)
        	{
            		color[i].red = (gushort)(colori.red*TCOS[i]); 
            		color[i].green =(gushort) (colori.green*TCOS[i]); 
            		color[i].blue = (gushort)(colori.blue*TCOS[i]); 
        	}
        }
        for(i=90;i>0;i--)
        {
	    rayon =(gint) rayoni*TSIN[i];
            gdk_colormap_alloc_color(colormap,&color[i],FALSE,TRUE);
	    gdk_gc_set_foreground(gc,&color[i]);
	   gdk_draw_arc(pixmap,gc,TRUE,x-rayon,y-rayon,2*rayon,2*rayon,0,380*64);
        }

}
/*****************************************************************************/
gboolean draw_lines_yes_no(guint i,guint j)
{
  gdouble distance;
  gdouble dif[3];
  guint k;
  dif[0] = geometry[i].X-geometry[j].X;
  dif[1] = geometry[i].Y-geometry[j].Y;
  dif[2] = geometry[i].Z-geometry[j].Z;
  distance = 0;
  for (k=0;k<3;k++)
	distance +=dif[k]*dif[k];
  distance = sqrt(distance);
  if(distance<(geometry[i].Prop.covalentRadii+geometry[j].Prop.covalentRadii))
	return TRUE;
  else 
	return FALSE;
}
/*****************************************************************************/
void draw_symb(guint epaisseur,guint i)
{
	GdkColormap *colormap;
	GdkColor color;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
	gchar* t= g_strdup_printf("%s", geometry[i].Prop.symbol);
        

	color = get_color_string(i);
   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);

	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,t,TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);
	g_free(t);

}
/*****************************************************************************/
void draw_numb(guint epaisseur,guint i)
{
	GdkColormap *colormap;
        GdkColor color;
        gchar *temp;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
        temp = g_strdup_printf("%d",geometry[i].N);

        color = get_color_string(i);

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,temp, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

        g_free(temp);
}
/*****************************************************************************/
void draw_numb_symb(guint epaisseur,guint i)
{
	GdkColormap *colormap;
        GdkColor color;
        gchar *temp;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
        temp = g_strdup_printf("%s[%d]",geometry[i].Prop.symbol,geometry[i].N);

        color = get_color_string(i);

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,temp, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);
        g_free(temp);
}
/*****************************************************************************/
void draw_charge(guint epaisseur,guint i)
{
	GdkColormap *colormap;
        GdkColor color;
        gchar *temp;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
        temp = g_strdup_printf("%0.3f",geometry[i].Charge);

        color = get_color_string(i);
   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,temp, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

        g_free(temp);
}
/*****************************************************************************/
void draw_symb_charge(guint epaisseur,guint i)
{
	GdkColormap *colormap;
        GdkColor color;
        gchar *temp;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
        temp = g_strdup_printf("%s[%0.3f]",geometry[i].Prop.symbol,geometry[i].Charge);

        color = get_color_string(i);

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,temp, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

        g_free(temp);
}
/*****************************************************************************/
void draw_numb_charge(guint epaisseur,guint i)
{
	GdkColormap *colormap;
        GdkColor color;
        gchar *temp;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
        temp = g_strdup_printf("%d[%0.3f]",geometry[i].N,geometry[i].Charge);

        color = get_color_string(i);

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,temp, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

        g_free(temp);
}
/*****************************************************************************/
void draw_coordinates(guint epaisseur,guint i)
{
	GdkColormap *colormap;
        GdkColor color;
        gchar *temp;
 	GdkFont *font = NULL; 
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);
  	if(font_desc) font = gdk_font_from_description (font_desc);
        temp = g_strdup_printf("%s[%0.3f,%0.3f,%0.3f] Ang",
			geometry0[i].Prop.symbol,
			geometry0[i].X*BOHR_TO_ANG,
			geometry0[i].Y*BOHR_TO_ANG,
			geometry0[i].Z*BOHR_TO_ANG);

        color = get_color_string(i);

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);
	gdk_gc_set_foreground(gc,&color);
        if(epaisseur == 0)epaisseur =1;
	gdk_gc_set_line_attributes(gc,epaisseur,GDK_LINE_SOLID,GDK_CAP_ROUND,GDK_JOIN_ROUND);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, geometry[i].Xi,geometry[i].Yi,temp, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

        g_free(temp);
}
/*****************************************************************************/
void draw_label(guint epaisseur,guint i)
{
   switch(LabelOption)
   {
   case LABELSYMB: draw_symb(epaisseur,i);break;
   case LABELNUMB: draw_numb(epaisseur,i);break;
   case LABELSYMBNUMB: draw_numb_symb(epaisseur,i);break;
   case LABELCHARGE: draw_charge(epaisseur,i);break;
   case LABELSYMBCHARGE: draw_symb_charge(epaisseur,i);break;
   case LABELNUMBCHARGE: draw_numb_charge(epaisseur,i);break;
   case LABELCOORDINATES: draw_coordinates(epaisseur,i);break;
   }
}
/*****************************************************************************/
void dessine_ball()
{	
	guint i;
	guint j;
	guint k;
	gint epaisseur;
        gushort rayon;
	GdkColor color1;
	GdkColor color2;
	GdkColor colorRed;
	GdkColor colorGreen;
	GdkColor colorBlue;
	GdkColor colorFrag;

	colorRed.red   = 65535;
	colorRed.green = 0;
	colorRed.blue  = 0;

	colorGreen.red   = 0;
	colorGreen.green = 65535;
	colorGreen.blue  = 0;

	colorBlue.red   = 0;
	colorBlue.green = 0;
	colorBlue.blue  = 65535;

	colorFrag = colorGreen;

	set_connections();
	if(ShowHBonds) set_Hconnections();

	for(i=0;i<Natoms;i++)
	if((gint)i==NumSelectedAtom)
	{
		for(j = 0;j<NFatoms;j++)
			if(NumFatoms[j] == (gint)geometry[i].N) colorFrag = colorRed;
		break;
	}
        if(ButtonPressed && OperationType==ROTLOCFRAG) colorFrag = colorRed;
        if(ButtonPressed && OperationType==ROTZLOCFRAG) colorFrag = colorRed;

	define_coord_ecran();
	for(i=0;i<Natoms-1;i++)
	{
                rayon =(gushort)(geometry[i].Rayon*factorball);
    		if (PersMode) rayon =(gushort)(geometry[i].Coefpers*geometry[i].Rayon*factorball);
		color1 = geometry[i].Prop.color;  
    		if (ShadMode) set_color_shad(&color1,i);
    		draw_cercle(geometry[i].Xi,geometry[i].Yi,rayon,color1);
		if((gint)i==NumSelectedAtom) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorRed);
		else
		if(NSA>-1 && (gint)geometry[i].N == NSA) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorBlue);
		if(OperationType == MESURE)
		for(j = 0;j<4;j++)
		if(NumSelAtoms[j] == (gint)geometry[i].N) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorGreen);
        	switch(OperationType)
		{
			case SELECTFRAG :
			case SELECTRESIDUE :
			case DELETEFRAG :
			case ROTLOCFRAG :
			case ROTZLOCFRAG :
			case MOVEFRAG :
			for(j = 0;j<NFatoms;j++)
				if(NumFatoms[j] == (gint)geometry[i].N)
	 				draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorFrag);
			break;
			default :break;
		}

		for(j=i+1;j<Natoms;j++)
                if(connections[i][j])
		{
			k =get_num_min_rayonIJ(i,j);
			epaisseur = (gint) (geometry[k].Rayon*factorstick);
    			if (PersMode) epaisseur =(gint)(geometry[k].Coefpers*epaisseur);
			color2 = geometry[j].Prop.color;  
    			if (ShadMode) set_color_shad(&color2,j);
			draw_line2(epaisseur,i,j,geometry[i].Xi,geometry[i].Yi,
						geometry[j].Xi,geometry[j].Yi,
						color1,color2);
		}
		else
		{
			if(ShowHBonds && Hconnections[i][j])
			{
				epaisseur = 8;
                		epaisseur*=factorstick;
				color1 = geometry[i].Prop.color;  
				color2 = geometry[j].Prop.color;  
				draw_line2_hbond(geometry[i].Xi,geometry[i].Yi, geometry[j].Xi,geometry[j].Yi, i,  j,  color1, color2,  epaisseur);
			}
		}
    		if (LabelOption != 0) draw_label(5,i);
		if(ShowDipole) for(j = 0;j<NDIVDIPOLE;j++) if(Ndipole[j]==(gint)i) dessine_dipole(j);
	}
        i=Natoms-1;
        rayon =(gushort)(geometry[i].Rayon*factorball);
    	if (PersMode) rayon =(gushort)(geometry[i].Coefpers*geometry[i].Rayon*factorball);
	color1 = geometry[i].Prop.color;  
    	if (ShadMode) set_color_shad(&color1,i);
	draw_cercle(geometry[i].Xi,geometry[i].Yi,rayon,color1);
	if((gint)i==NumSelectedAtom) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorRed);
	else
	if(NSA>-1 && (gint)geometry[i].N == NSA) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorBlue);
	if(OperationType == MESURE)
	for(j = 0;j<4;j++)
		if(NumSelAtoms[j] == (gint)geometry[i].N)
 			draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorGreen);
        switch(OperationType)
	{
		case SELECTFRAG :
		case SELECTRESIDUE :
		case DELETEFRAG :
		case ROTLOCFRAG :
		case ROTZLOCFRAG :
		case MOVEFRAG :
		for(j = 0;j<NFatoms;j++)
		if(NumFatoms[j] == (gint)geometry[i].N)
 			draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorFrag);
		break;
		default :break;
	}

	if(ShowDipole) for(j = 0;j<NDIVDIPOLE;j++) if(Ndipole[j]==(gint)i) dessine_dipole(j);
    	if (LabelOption != 0) draw_label(5,i);

	
}
/*****************************************************************************/
void dessine_stick()
{	
	guint i;
	guint j;
	guint k;
	gint epaisseur;
	GdkColor color1;
	GdkColor color2;
	GdkColor colorRed;
	GdkColor colorGreen;
	GdkColor colorBlue;
	GdkColor colorFrag;
    	gushort rayon;
	gboolean* FreeAtoms = g_malloc(Natoms*sizeof(gboolean));

	colorRed.red = 65535;
	colorRed.green = 0;
	colorRed.blue = 0;

	colorGreen.red   = 0;
	colorGreen.green = 65535;
	colorGreen.blue  = 0;

	colorBlue.red   = 0;
	colorBlue.green = 0;
	colorBlue.blue  = 65535;

	colorFrag = colorGreen;

	set_connections();
	if(ShowHBonds) set_Hconnections();

	for(i=0;i<Natoms;i++)
	if((gint)i==NumSelectedAtom)
	{
		for(j = 0;j<NFatoms;j++)
		if(NumFatoms[j] == (gint)geometry[i].N) colorFrag = colorRed;
		break;
	}
        if(ButtonPressed && OperationType==ROTLOCFRAG) colorFrag = colorRed;
        if(ButtonPressed && OperationType==ROTZLOCFRAG) colorFrag = colorRed;

	for(i=0;i<Natoms;i++) FreeAtoms[i] = TRUE;

	define_coord_ecran();

	for(i=0;i<Natoms;i++)
        {
		k = -1;
		for(j=i+1;j<Natoms;j++)
                if(connections[i][j])
		{
			FreeAtoms[j] = FALSE;
			FreeAtoms[i] = FALSE;
			k =get_num_min_rayonIJ(i,j);
			epaisseur = (gint) (geometry[k].Rayon/4*factorstick);
    			if (PersMode) 
               		 	epaisseur =(gint)(geometry[k].Coefpers*epaisseur);
			color1 = geometry[i].Prop.color;  
			color2 = geometry[j].Prop.color;  
    			if (ShadMode) 
			{
				set_color_shad(&color1,i);
				set_color_shad(&color2,j);
			}
			draw_line2(epaisseur,i,j,geometry[i].Xi,geometry[i].Yi, geometry[j].Xi,geometry[j].Yi, color1,color2);
		}
		else
		{
			if(ShowHBonds && Hconnections[i][j])
			{
				epaisseur = 4;
                		epaisseur*=factorstick;
				color1 = geometry[i].Prop.color;  
				color2 = geometry[j].Prop.color;  
				draw_line2_hbond(geometry[i].Xi,geometry[i].Yi, geometry[j].Xi,geometry[j].Yi, i,  j,  color1, color2,  epaisseur);
			}
		}
		if(FreeAtoms[i])
		{
        		rayon =(gushort)(geometry[i].Rayon*factorball)/2;
    			if (PersMode) rayon =(gushort)(geometry[i].Coefpers*geometry[i].Rayon*factorball)/2;
			color1 = geometry[i].Prop.color;  
    			if (ShadMode) set_color_shad(&color1,i);
			draw_cercle(geometry[i].Xi,geometry[i].Yi,rayon,color1);
		}
		else
		{
        		rayon =(gushort)(geometry[i].Rayon*factorstick)/3;
    			if (PersMode) rayon =(gushort)(geometry[i].Coefpers*geometry[i].Rayon*factorstick)/3;
		}
		if((gint)i==NumSelectedAtom) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorRed);
		else
		if(NSA>-1 && (gint)geometry[i].N == NSA) draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorBlue);
		if(OperationType == MESURE)
		for(j = 0;j<4;j++)
		if(NumSelAtoms[j] == (gint)geometry[i].N)
	 		draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorGreen);

        	switch(OperationType)
		{
			case SELECTFRAG :
			case SELECTRESIDUE :
			case DELETEFRAG :
			case ROTLOCFRAG :
			case ROTZLOCFRAG :
			case MOVEFRAG :
			for(j = 0;j<NFatoms;j++)
			if(NumFatoms[j] == (gint)geometry[i].N)
	 			draw_anneau(geometry[i].Xi,geometry[i].Yi,rayon,colorFrag);
			break;
			default : break;
		}



		if(ShowDipole) for(j = 0;j<NDIVDIPOLE;j++) if(Ndipole[j]==(gint)i) dessine_dipole(j);
    		if (LabelOption != 0) draw_label(5,i);
        }
    	if (LabelOption != 0) draw_label(5,Natoms-1);
	g_free(FreeAtoms);
	
}
/*****************************************************************************/
void redefine_dipole()
{
        guint i;
        guint j;

	if(!Ddef)
		return;
	{
		for(i=0;i<NDIVDIPOLE;i++)
			for(j=0;j<3;j++)
				dipole0[i][j] = dipole00[0][j] + (dipole00[i][j]-dipole00[0][j])*factordipole;
	}
}
/*****************************************************************************/
void draw_dipole(gint x0,gint y0)
{
	GdkColormap *colormap;
        GdkColor color;
	gchar* t;
	gdouble d = 0.0;
	gint i;
 	PangoFontDescription *font_desc = pango_font_description_from_string (FontsStyleLabel.fontname);

	for(i=0;i<3;i++)
		d += Dipole.Value[i]*Dipole.Value[i];

	t = g_strdup_printf("%0.3f D",sqrt(d)*AUTODEB);

        color = get_color_string(0);

   	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	gdk_color_alloc(colormap,&color);

	gdk_gc_set_foreground(gc,&color);
	gabedit_draw_string(ZoneDessin, pixmap, font_desc, gc, x0, y0, t, TRUE,TRUE);

	if(font_desc) pango_font_description_free (font_desc);

}
/*****************************************************************************/
void calcul_ndipole()
{
	gint i;
	gint j;

	for (j = 0;j<NDIVDIPOLE;j++)
		Ndipole[j] = 0; 

	for (i = 1;i<(gint)Natoms;i++)
	{
		for (j = 0;j<NDIVDIPOLE;j++)
			if(dipole[j][2]>geometry[i].Z)
				Ndipole[j] = i;
	}

}
/*****************************************************************************/
void dessine_dipole(gint i)
{	
	gint epaisseur;
	GdkColor color;
	gfloat vx,vy;
	gint ep;

    	if(!Ddef)
		return;

	epaisseur = (gint) (10*factorstick);
	/*
        epaisseur =(gint)(geometry[0].Coefpers*epaisseur);
	*/
        epaisseur = (gint) (epaisseur/2.0); 
        epaisseur =(gint)(epaisseur*Dipole.radius/0.25);
	if(i<NDIVDIPOLE-1)
	{
	color.red = Dipole.color[0];
	color.green = Dipole.color[1];
	color.blue = Dipole.color[2];
	draw_line(DXi[i],DYi[i],DXi[i+1],DYi[i+1],color,epaisseur,&vx,&vy,&ep,TRUE);
	if(DrawDipole && i==NDIVDIPOLE/2)
	 	draw_dipole(DXi[i],DYi[i]);
	}
	else
	{
	color.red = Dipole.color[0]/1.1;
	color.green = Dipole.color[1]/1.1;
	color.blue = Dipole.color[2]/1.1;
 	draw_cercle(DXi[i],DYi[i],epaisseur,color);
	}
}
/*****************************************************************************/
void dessine()
{
	gfloat m[4][4];
     	pixmap_init(ZoneDessin);


     	if(Natoms<1)
	{
		redraw();
		return;
	}

	if(strToDraw)
		draw_text(strToDraw);
	
	build_rotmatrix(m,Quat);
	rotation_geometry_quat(m);


	if (StickMode) 
   		dessine_stick();
	else 
		dessine_ball();

	redraw();
}
/*****************************************************************************/
void rafresh_drawing()
{
  
	guint i;
	HideShowMesure(MesureIsHide);
	i= gtk_notebook_get_current_page(GTK_NOTEBOOK(NoteBookDraw));
	define_geometry();
	gtk_notebook_remove_page((GtkNotebook *)NoteBookDraw,0);
	vboxmesure =AddNoteBookPage(NoteBookDraw,"Mesure");
	AddMesure(GeomDlg,vboxmesure);

	gtk_widget_hide_all(NoteBookDraw);
	gtk_widget_show_all(NoteBookDraw);
	gtk_notebook_set_current_page((GtkNotebook*)NoteBookDraw,i);
	dessine();
}
/*****************************************************************************/
void multi_geometry_by_factor(gdouble fa0)
{
        guint i;

        for(i=0;i<Natoms;i++)
	{
          geometry[i].X *= fa0;
          geometry[i].Y *= fa0;
          geometry[i].Z *= fa0;
	}
	define_coord_maxmin();
}
/*****************************************************************************/
void multi_geometry_by_a0(GtkWidget *win, gpointer d)
{
	multi_geometry_by_factor(BOHR_TO_ANG);
	dessine();
}
/*****************************************************************************/
void divide_geometry_by_a0(GtkWidget *win, gpointer d)
{
 multi_geometry_by_factor(1.0/BOHR_TO_ANG);
 dessine();
}
/*****************************************************************************/
void factor_default(GtkWidget *win,gpointer d)
{
	factor =1.0;
	dessine();
}
/*****************************************************************************/
void factor_stick_default(GtkWidget *win,gpointer d)
{
	factorstick =1.0;
	dessine();
}
/*****************************************************************************/
void factor_ball_default(GtkWidget *win,gpointer d)
{
	factorball =1.0;
	dessine();
}
/*****************************************************************************/
void factor_dipole_default(GtkWidget *win,gpointer d)
{
	factordipole =1.0;
	redefine_dipole();
	dessine();
}
/*****************************************************************************/
void factor_all_default(GtkWidget *win,gpointer d)
{
	factorball =1.0;
	factorstick =1.0;
	factor =1.0;
	factordipole =1.0;
	redefine_dipole();
	SetOperation(NULL,     	CENTER);
}
/*****************************************************************************/
void set_back_color_black()
{

	if(BackColor)
        {
		gdk_color_free(BackColor);
		BackColor=NULL;
        }
        gdk_draw_rectangle (pixmap,
                      ZoneDessin->style->black_gc,
                      TRUE,
                      0, 0,
                      ZoneDessin->allocation.width,
                      ZoneDessin->allocation.height);    
        dessine();
}
/*****************************************************************************/
void set_back_color(GtkColorSelection *Sel,gpointer *d)
{
	GdkColor color;
	GdkColormap *colormap;

	gtk_color_selection_get_current_color(Sel, &color);
	colormap  = gdk_window_get_colormap(ZoneDessin->window);
	
        BackColor = gdk_color_copy(&color);
        gdk_colormap_alloc_color(colormap,&color,FALSE,TRUE);

	gdk_gc_set_foreground(gc,&color);

        gdk_draw_rectangle (pixmap,
                      gc,
                      TRUE,
                      0, 0,
                      ZoneDessin->allocation.width,
                      ZoneDessin->allocation.height);    
        dessine();

}
/*****************************************************************************/
void open_color_dlg(GtkWidget *win,gpointer *DrawingArea)
{

	GtkColorSelectionDialog *ColorDlg;
	ColorDlg = 
		(GtkColorSelectionDialog *)gtk_color_selection_dialog_new(
		"Set Background Color");
	gtk_window_set_modal (GTK_WINDOW (ColorDlg), TRUE);
	gtk_window_set_transient_for(GTK_WINDOW(ColorDlg),GTK_WINDOW(Fenetre));
        
	gtk_widget_hide(ColorDlg->help_button);
	
	g_signal_connect_swapped(G_OBJECT(ColorDlg->ok_button),"clicked",
		(GtkSignalFunc)set_back_color,GTK_OBJECT(ColorDlg->colorsel));

	g_signal_connect_swapped(G_OBJECT(ColorDlg->ok_button),"clicked",
		(GtkSignalFunc)gtk_widget_destroy,GTK_OBJECT(ColorDlg));

	g_signal_connect_swapped(G_OBJECT(ColorDlg->cancel_button),"clicked",
		(GtkSignalFunc)gtk_widget_destroy,GTK_OBJECT(ColorDlg));

	gtk_widget_show(GTK_WIDGET(ColorDlg));

}
/*****************************************************************************/
GtkWidget *create_drawing_in_box(GtkWidget *box)
{
    GtkWidget *DrawingArea;

    DrawingArea = gtk_drawing_area_new();
    gtk_box_pack_start(GTK_BOX(box), DrawingArea,TRUE,TRUE,0);
    gtk_widget_set_size_request(GTK_WIDGET(DrawingArea),400,-1);
    gtk_widget_show(DrawingArea);
    return DrawingArea;
  
}
/*****************************************************************************/
GtkWidget *create_drawing_in_table(GtkWidget *Table,gint i,gint j,gint k,gint l)
{
    GtkWidget *DrawingArea;

    DrawingArea = gtk_drawing_area_new();

    gtk_table_attach(GTK_TABLE(Table), DrawingArea, i,j, k,l,
                   GTK_FILL | GTK_EXPAND, GTK_EXPAND | GTK_FILL, 0, 0);
    gtk_widget_set_size_request(GTK_WIDGET(DrawingArea),400,-1);
    gtk_widget_show(DrawingArea);
    return DrawingArea;
  
}
/*****************************************************************************/
GtkWidget *create_frame_in_vbox(gchar *title,GtkWidget *win,GtkWidget *vbox,gboolean type)
{
  GtkWidget *frame;
  frame = gtk_frame_new (title);
  gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
  gtk_widget_ref (frame);
  g_object_set_data_full(G_OBJECT (win), "frame",
	  frame,(GtkDestroyNotify) gtk_widget_unref);
  gtk_container_set_border_width (GTK_CONTAINER (frame), 1);
  gtk_box_pack_start(GTK_BOX(vbox), frame,type,type,1);
  gtk_widget_show (frame);
  return frame;

}
/*****************************************************************************/
GtkWidget *create_vbox_in_hbox(GtkWidget *win,GtkWidget *hbox,gboolean type)
{
	GtkWidget *vbox;
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_widget_ref (vbox);
	g_object_set_data_full(G_OBJECT (win), "vbox", vbox,
                            (GtkDestroyNotify) gtk_widget_unref);
	gtk_widget_show (vbox);
	gtk_box_pack_start (GTK_BOX (hbox), vbox, type, type, 1);

	return vbox;
}
/*****************************************************************************/
GtkWidget *create_hbox_in_vbox(GtkWidget *vbox)
{
	GtkWidget *hbox;
	hbox = gtk_hbox_new (FALSE, 0);
	gtk_widget_ref (hbox);
	gtk_widget_show (hbox);
	gtk_box_pack_start (GTK_BOX (vbox), hbox, FALSE, FALSE, 0);	
	return hbox;
}
/*****************************************************************************/
void destroy_drawing_and_childs(GtkWidget *win,gpointer data)
{
  destroy_childs(GeomDlg);
}
/*****************************************************************************/
void destroy_all_drawing(GtkWidget *win)
{

  geometry  = Free_One_Geom(geometry ,Natoms);
  geometry0 = Free_One_Geom(geometry0,Natoms);

  g_free(NumFatoms);
  NumFatoms = NULL;
  NFatoms = 0;
  Natoms = 0;

 gtk_widget_destroy(ZoneDessin);
 ZoneDessin = NULL;
 gtk_widget_destroy(GeomDlg);

 if (pixmap)
    gdk_pixmap_unref(pixmap);
 pixmap = NULL;
 if (gc)
      gdk_gc_destroy(gc);
 gc = NULL;
}
/*****************************************************************************/
GtkWidget *AddNoteBookPage(GtkWidget *NoteBook,char *label)
{
  GtkWidget *vboxpage;
  GtkWidget *Frame;
  

  Frame = gtk_frame_new(NULL);
  gtk_container_set_border_width(GTK_CONTAINER(Frame), 2);

  /*
  LabelOnglet = gtk_label_new(label);
  LabelMenu = gtk_label_new(label);
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                LabelOnglet, LabelMenu);
*/
  gtk_notebook_append_page_menu(GTK_NOTEBOOK(NoteBook),
                                Frame,
                                NULL, NULL);

  g_object_set_data(G_OBJECT (Frame), "Frame", Frame);

  gtk_widget_show(Frame);
  vboxpage = create_vbox(Frame);

  return vboxpage; 
}
/********************************************************************************************/
static void stop_calcul(GtkWidget *wi, gpointer data)
{
	StopCalcul = TRUE;
}
/********************************************************************************/
void add_stop_button(GtkWidget *Win, GtkWidget *box)
{
  StopButton = gtk_button_new_with_label("Cancel");
  gtk_box_pack_start (GTK_BOX (box), StopButton, FALSE, TRUE, 0);	
  gtk_widget_set_sensitive(StopButton, FALSE);
  
  g_signal_connect(G_OBJECT(StopButton), "clicked", GTK_SIGNAL_FUNC (stop_calcul), NULL);  
}
/********************************************************************************/
void create_window_drawing()
{
	GtkWidget *vboxframe;
	GtkWidget *frame;
	GtkWidget *hboxframe;
	GtkWidget *vbox;
	GtkWidget *hbox;
	GtkWidget *hboxoperation;
	GtkWidget *DrawingArea;
	GtkWidget *vboxleft;
	GtkWidget *vboxright;
	GtkWidget *NoteBook;
	GtkWidget *Table;
	GtkWidget *handelbox;
	GtkWidget *Status;
	GtkWidget *VboxWin;
	GtkWidget *hboxtoolbar;
  	GtkWidget* handlebox;
  	GtkWidget* table;

	{
		gint i;
		factor=1.0;
		factorstick=1.0;
		factorball=1.0;
		factordipole=1.0;
		TransX=0;
		TransY=0;
		SetCosSin();
		Ddef = FALSE;
		AtomToInsert = g_strdup("H");
		for(i=0;i<4;i++) NumSelAtoms[i] = -1;
		StickMode = TRUE;
		ShadMode = FALSE;
		PersMode = FALSE;
		LightMode = FALSE;
		DrawDistance=FALSE;
		DrawDipole = FALSE;
		StopCalcul = FALSE;
		ShowHBonds = FALSE;
		Frag.NAtoms = 0;
		Frag.Atoms = NULL;
		FragItems = NULL;
		NFrags = 0;
		OperationType = ROTATION ;
	}
	

	geometry = NULL;
	geometry0 = NULL;
	Natoms = 0;

	NumFatoms = NULL;
	NFatoms = 0;

	define_geometry();

	if(Natoms == 0) OperationType = INSERTATOM;

	GeomDlg = NULL ;
	GeomDlg = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	VboxWin = gtk_vbox_new (TRUE, 0);
	gtk_container_add(GTK_CONTAINER(GeomDlg),VboxWin);
	gtk_widget_show(VboxWin);
	gtk_window_set_title(GTK_WINDOW(GeomDlg),"Gabedit : Draw Geometry ");
	gtk_window_set_transient_for(GTK_WINDOW(GeomDlg),GTK_WINDOW(Fenetre));
	gtk_widget_add_events(GeomDlg,GDK_KEY_RELEASE_MASK);
   

	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);
	init_child(GeomDlg,destroy_all_drawing," Draw Geom. ");
	g_signal_connect(G_OBJECT(GeomDlg),"delete_event",(GtkSignalFunc)destroy_childs,NULL);

	frame = create_frame_in_vbox(NULL,GeomDlg,VboxWin,TRUE);
	gtk_widget_show (frame);
	vboxframe = create_vbox(frame);
	gtk_widget_show (vboxframe);

	hboxframe = gtk_hbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vboxframe), hboxframe, TRUE, TRUE, 0);
	gtk_widget_show (hboxframe);

	
	/* DrawingArea */
	vbox = create_vbox_in_hbox(frame,hboxframe,TRUE);
	frame = create_frame_in_vbox(NULL,GeomDlg,vbox,TRUE);
	hbox = create_hbox_in_vbox(vbox);
	vbox = create_vbox(frame);
	vboxleft= vbox;

	vbox = create_vbox_in_hbox(frame,hboxframe,FALSE);  
	vboxhandle = vbox;
	handelbox =gtk_handle_box_new ();
	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(handelbox),GTK_SHADOW_NONE);
	gtk_handle_box_set_handle_position  (GTK_HANDLE_BOX(handelbox),GTK_POS_TOP);   
	gtk_container_add( GTK_CONTAINER (vbox), handelbox);
	gtk_widget_show (handelbox);
	vbox = gtk_vbox_new (FALSE, 0);
	gtk_container_add( GTK_CONTAINER(handelbox), vbox);
	gtk_widget_show (vbox);
	vboxright= vbox;

	vbox = vboxleft;

	/* The Table */
	Table = gtk_table_new(1, 2, FALSE);
	gtk_container_add(GTK_CONTAINER(vbox), Table);
	gtk_widget_show(Table); 

	DrawingArea = create_drawing_in_table(Table,1,2,0,1);
	gtk_widget_set_size_request(GTK_WIDGET(DrawingArea ),(gint)(ScreenHeight*0.5),(gint)(ScreenHeight*0.5));

	ZoneDessin = DrawingArea;
	g_signal_connect(G_OBJECT(ZoneDessin),"configure_event", (GtkSignalFunc)configure_event,NULL);

	hboxtoolbar = gtk_hbox_new (FALSE, 0);
	gtk_table_attach(GTK_TABLE(Table), hboxtoolbar, 0,1, 0,1, GTK_FILL , GTK_SHRINK |GTK_FILL, 0, 0);
	gtk_widget_show(hboxtoolbar);

	gtk_widget_set_events (ZoneDessin, GDK_EXPOSURE_MASK
					| GDK_LEAVE_NOTIFY_MASK
					| GDK_BUTTON_PRESS_MASK
					| GDK_BUTTON_RELEASE_MASK
					| GDK_POINTER_MOTION_MASK
					| GDK_POINTER_MOTION_HINT_MASK);


	gtk_widget_realize(GeomDlg);

	NoteBook = gtk_notebook_new();
	gtk_notebook_set_show_tabs(GTK_NOTEBOOK(NoteBook), FALSE);
	gtk_notebook_set_show_border(GTK_NOTEBOOK(NoteBook), FALSE);

	NoteBookDraw = NoteBook;
	gtk_box_pack_start(GTK_BOX (vboxright), NoteBook,TRUE, TRUE, 0);

	vboxmesure =AddNoteBookPage(NoteBook,"Mesure");
	AddMesure(GeomDlg,vboxmesure);
	gtk_widget_show(NoteBook);
	gtk_widget_show_all(vboxmesure);
	gtk_widget_show(vboxright);


  	handlebox = gtk_handle_box_new ();
  	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(handlebox),GTK_SHADOW_NONE);    
	gtk_handle_box_set_handle_position  (GTK_HANDLE_BOX(handlebox),GTK_POS_LEFT);
  	gtk_widget_show (handlebox);
	gtk_box_pack_start(GTK_BOX (hbox), handlebox,TRUE, TRUE, 0);

	table = gtk_table_new(2,2,FALSE);
	gtk_container_add (GTK_CONTAINER (handlebox), table);
	gtk_widget_show(table);
	/* Rotation Status */
	Status = gtk_statusbar_new();
	gtk_table_attach(GTK_TABLE(table),Status,0,1,0,1,
					(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
					(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
					1,1);
	idStatusRotation = gtk_statusbar_get_context_id(GTK_STATUSBAR(Status),"Rotation");
	StatusRotation = Status;
	gtk_statusbar_pop(GTK_STATUSBAR(StatusRotation),idStatusRotation);
	gtk_statusbar_push(GTK_STATUSBAR(StatusRotation),idStatusRotation,
		" Press the Midle mouse button and move your mouse for a \"Rotation\". ");


	/* Mode Status */
	Status = gtk_statusbar_new();
	gtk_table_attach(GTK_TABLE(table),Status,1,2,0,1,
					(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
					(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
					1,1);
	idStatusPopup= gtk_statusbar_get_context_id(GTK_STATUSBAR(Status),"Ball&Stick");
	StatusPopup = Status;
	gtk_statusbar_pop(GTK_STATUSBAR(StatusPopup),idStatusPopup);
	gtk_statusbar_push(GTK_STATUSBAR(StatusPopup),idStatusPopup,
		" Press the Right mouse button for display the popup menu. ");

	/* Operation Status */
	Status = gtk_statusbar_new();
	hboxoperation = gtk_hbox_new (FALSE, 0);
	gtk_table_attach(GTK_TABLE(table), hboxoperation,0,2,1,2,
					(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
					(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
					1,1);
	gtk_box_pack_start (GTK_BOX(hboxoperation),Status, TRUE, TRUE, 1);

	idStatusOperation = gtk_statusbar_get_context_id(GTK_STATUSBAR(Status),"Rotation");
	StatusOperation = Status;
	gtk_statusbar_pop(GTK_STATUSBAR(StatusOperation),idStatusOperation);
	gtk_statusbar_push(GTK_STATUSBAR(StatusOperation),idStatusOperation,
		" Press the Left mouse button and move your mouse for a \"Rotation\". ");

	add_stop_button(GeomDlg, hboxoperation);
	gtk_widget_show_all(hbox);
	gtk_widget_show_all(hboxoperation);
	gtk_widget_show_all(vbox);


	gtk_widget_show(frame);

	if(MesureIsHide)
	{
  		gtk_widget_hide(vboxhandle);
	}
	else
		gtk_widget_show(vboxhandle);

	gtk_window_set_default_size (GTK_WINDOW(GeomDlg), (gint)(ScreenHeight*0.7), (gint)(ScreenHeight*0.7));


	g_object_set_data(G_OBJECT(GeomDlg), "StatusBox",handlebox);
	create_toolbar_and_popup_menu_geom(hboxtoolbar);


	/* Evenments */
	g_signal_connect(G_OBJECT(ZoneDessin),"expose_event",(GtkSignalFunc)expose_event,NULL);
	g_signal_connect(G_OBJECT(ZoneDessin), "button_press_event",GTK_SIGNAL_FUNC(event_dispatcher), NULL);
	g_signal_connect(G_OBJECT(ZoneDessin), "motion_notify_event",GTK_SIGNAL_FUNC(motion_notify), NULL);
	g_signal_connect(G_OBJECT(ZoneDessin), "button_release_event",GTK_SIGNAL_FUNC(button_release), NULL);
	g_signal_connect(G_OBJECT (GeomDlg), "key_press_event", (GtkSignalFunc) set_key_press, GeomDlg);
	g_signal_connect(G_OBJECT (GeomDlg), "key_release_event", (GtkSignalFunc) set_key_release, NULL);
	gtk_widget_show(GeomDlg);

	gtk_window_move(GTK_WINDOW(GeomDlg),0,0);


	set_back_color_black();
	set_icone(GeomDlg);
}
/*****************************************************************************/
void draw_geometry(GtkWidget *w,gpointer d)
{
 if(ZoneDessin == NULL)
          create_window_drawing();
 else
 {
	gtk_widget_hide(GeomDlg);
	gtk_widget_show(GeomDlg);
  	rafresh_drawing();
 }
}
/*****************************************************************************/

