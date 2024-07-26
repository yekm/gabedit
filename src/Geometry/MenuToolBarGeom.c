/* MenuToolBarGeom.c */
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
#include <stdlib.h>
#include <math.h>

#include "../Common/Global.h"
#include "../Utils/UtilsInterface.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Utils/Utils.h"
#include "../Utils/AtomsProp.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/Mesure.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/Povray.h"
#include "../Common/Windows.h"
#include "../Utils/Transformation.h"
#include "../MolecularMechanics/MolecularMechanicsDlg.h"
#include "../MolecularMechanics/SetMMParameters.h"
#include "../MolecularMechanics/SetPDBTemplate.h"
#include "../SemiEmpirical/SemiEmpiricalDlg.h"
#include "../Geometry/GeomXYZ.h"
#include "../Geometry/GeomZmatrix.h"
#include "../Geometry/Symmetry.h"
#include "../Files/FileChooser.h"
#include "../Geometry/ImagesGeom.h"
#include "../Geometry/RotFragments.h"
#include "../Geometry/BuildLinear.h"
#include "../Geometry/BuildRing.h"
#include "../Geometry/BuildRoZPhi.h"
#include "../Geometry/BuildPolyPeptide.h"
#include "../Geometry/BuildPolySaccharide.h"
#include "../Geometry/BuildPolyNucleicAcid.h"
#include "../Geometry/BuildNanoTube.h"
#include "../Geometry/PersonalFragments.h"
#include "../Geometry/ResultsAnalise.h"
#include "../Geometry/GeomConversion.h"
#include "../Geometry/MenuToolBarGeom.h"
#include "../Geometry/OpenBabel.h"
#include "../Geometry/FragmentsSelector.h"
#include "../Geometry/ExportGeom.h"
#include "../Utils/HydrogenBond.h"
#include "../Symmetry/MoleculeSymmetryInterface.h"
#include "../Common/StockIcons.h"


/* #define EXPERIMENTAL 1*/
/*********************************************************************************************************************/
static	GtkUIManager *manager = NULL;
static GtkWidget* handleBoxToolBar = NULL;
static gboolean ViewToolBar = TRUE;
static	GtkToolbar* toolBar = NULL;
/*********************************************************************************************************************/
static void view_toolbar ()
{
	if(!handleBoxToolBar) return;
	if(ViewToolBar)
 		gtk_widget_hide (GTK_WIDGET(handleBoxToolBar));
	else
 		gtk_widget_show (GTK_WIDGET(handleBoxToolBar));
	ViewToolBar = !ViewToolBar;
}
/********************************************************************************/
static void set_atom(GtkWidget *button,gpointer data)
{
	GtkWidget* WinTable = g_object_get_data(G_OBJECT(button), "WinTable");
	/*
	GtkStyle *button_style = gtk_widget_get_style(WinTable); 
	gchar* told;
	gtk_button_set_label(GTK_BUTTON(AtomButton), (gchar*)data);
	told = GTK_BUTTON(AtomButton)->label_text; 
	GTK_BUTTON(AtomButton)->label_text = g_strdup(data);
	if(told) g_free(told);
	set_button_style(button_style,AtomButton,(gchar*)data);
	*/
	if(AtomToInsert) g_free(AtomToInsert);
	AtomToInsert = g_strdup((gchar*)data);
	if(GTK_IS_WIDGET(WinTable)) gtk_widget_destroy(WinTable);
}
/********************************************************************************/
static void select_atom()
{
	GtkWidget* Table;
	GtkWidget* button;
	GtkWidget* frame;
	GtkWidget* WinTable;
	guint i;
	guint j;
        GtkStyle *button_style;
        GtkStyle *style;

	gchar*** Symb = get_periodic_table();

	WinTable = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_modal(GTK_WINDOW(WinTable),TRUE);
	gtk_window_set_title(GTK_WINDOW(WinTable),"Select your atom");
	gtk_window_set_default_size (GTK_WINDOW(WinTable),(gint)(ScreenWidth*0.5),(gint)(ScreenHeight*0.4));

	frame = gtk_frame_new (NULL);
	gtk_frame_set_shadow_type( GTK_FRAME(frame),GTK_SHADOW_ETCHED_OUT);
	gtk_container_set_border_width (GTK_CONTAINER (frame), 10);

	gtk_container_add(GTK_CONTAINER(WinTable),frame);  
	gtk_widget_show (frame);

	Table = gtk_table_new(PERIODIC_TABLE_N_ROWS-1,PERIODIC_TABLE_N_COLUMNS,TRUE);
	gtk_container_add(GTK_CONTAINER(frame),Table);
	button_style = gtk_widget_get_style(WinTable); 
  
	for ( i = 0;i<PERIODIC_TABLE_N_ROWS-1;i++)
		for ( j = 0;j<PERIODIC_TABLE_N_COLUMNS;j++)
	{
		if(strcmp(Symb[j][i],"00"))
		{
			button = gtk_button_new_with_label(Symb[j][i]);
			style=set_button_style(button_style,button,Symb[j][i]);
			g_object_set_data(G_OBJECT(button), "WinTable", WinTable);
			g_signal_connect(G_OBJECT(button), "clicked", (GCallback)set_atom,(gpointer )Symb[j][i]);
			gtk_table_attach(GTK_TABLE(Table),button,j,j+1,i,i+1,
				(GtkAttachOptions)(GTK_FILL | GTK_EXPAND) ,
				(GtkAttachOptions)(GTK_FILL | GTK_EXPAND),
			1,1);
		}
	}
 	
	gtk_widget_show_all(WinTable);
}
/*********************************************************************************************************************/
enum 
{
	OPERATION_TRANSLATE,
	OPERATION_ROTATION,
	OPERATION_ROTATION_Z,
	OPERATION_ZOOM,
	OPERATION_SCALE_STICK,
	OPERATION_SCALE_BALL,
	OPERATION_SCALE_DIPOLE,
	OPERATION_SELECTION_ATOMS,
	OPERATION_DELETE_OBJECTS,
	OPERATION_MOVE_ATOMS,
	OPERATION_ROTATION_ATOMS,
	OPERATION_ROTATION_Z_ATOMS,
	OPERATION_EDIT_OBJECTS,
	OPERATION_INSERT_FRAG,
	OPERATION_MESURE,
};
static void render_operation_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	GtkWidget *atomToInsert = gtk_ui_manager_get_widget (manager, "/ToolbarGL/SetAtomToInsert");

	if(GTK_IS_WIDGET(atomToInsert)) gtk_widget_set_sensitive(atomToInsert, FALSE);

	switch(value)
	{
		case OPERATION_TRANSLATE : SetOperation(NULL, TRANSMOVIE); break;
		case  OPERATION_ROTATION : SetOperation(NULL, ROTATION); break;
		case OPERATION_ROTATION_Z : SetOperation(NULL,ROTATIONZ ); break;
		case  OPERATION_ZOOM : SetOperation(NULL, SCALEGEOM ); break;
		case  OPERATION_SCALE_STICK : SetOperation(NULL, SCALESTICK); break;
		case  OPERATION_SCALE_BALL : SetOperation(NULL, SCALEBALL); break;
		case  OPERATION_SCALE_DIPOLE : SetOperation(NULL, SCALEDIPOLE); break;
		case  OPERATION_SELECTION_ATOMS : SetOperation(NULL, SELECTOBJECTS); break;
		case OPERATION_DELETE_OBJECTS : SetOperation(NULL,DELETEOBJECTS ); break;
		case  OPERATION_MOVE_ATOMS : SetOperation(NULL, MOVEFRAG); break;
		case  OPERATION_ROTATION_ATOMS : SetOperation(NULL, ROTLOCFRAG ); break;
		case   OPERATION_ROTATION_Z_ATOMS : SetOperation(NULL, ROTZLOCFRAG); break;
		case   OPERATION_EDIT_OBJECTS : 
			    SetOperation(NULL, EDITOBJECTS );
			    if(GTK_IS_WIDGET(atomToInsert)) gtk_widget_set_sensitive(atomToInsert, TRUE);
			    break;
		case   OPERATION_INSERT_FRAG : 
				    		SetOperation(NULL, ADDFRAGMENT ); 
						create_window_fragments_selector();
						break;
		case   OPERATION_MESURE :
				    SetOperation(NULL, MESURE );
				    {
					GtkAction * action = gtk_ui_manager_get_action(manager, "/ToolbarGL/ShowMesureNoteBook");
					GtkWidget *notebook = gtk_ui_manager_get_widget (manager, "/ToolbarGL/ShowMesureNoteBook");
					gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action), TRUE);
					gtk_widget_set_sensitive(notebook, FALSE);
				    }
				    break;
	}
	if(value != OPERATION_MESURE) 
	{
		GtkWidget *notebook = gtk_ui_manager_get_widget (manager, "/ToolbarGL/ShowMesureNoteBook");
		gtk_widget_set_sensitive(notebook, TRUE);
	}
}
static GtkRadioActionEntry operationsEntries[] = {
  { "OperationsTranslate", GABEDIT_STOCK_TRANSLATE, "_Translate", NULL, "Translation", OPERATION_TRANSLATE },
  { "OperationsRotation", GABEDIT_STOCK_ROTATION, "_Rotation", NULL, "Rotation", OPERATION_ROTATION },
  { "OperationsRotationZ", GABEDIT_STOCK_ROTATION_Z, "Rotation about _z axis", NULL, "Rotation about z axis", OPERATION_ROTATION_Z },
  { "OperationsZoom", GABEDIT_STOCK_ZOOM, "Zo_om", NULL, "Zoom", OPERATION_ZOOM },
  { "OperationsScaleStick", GABEDIT_STOCK_SCALE_STICK, "Scale _stick", NULL, "Scale stick", OPERATION_SCALE_STICK },
  { "OperationsScaleBall", GABEDIT_STOCK_SCALE_BALL, "Scale _ball", NULL, "Scale ball", OPERATION_SCALE_BALL },
  { "OperationsScaleDipole", GABEDIT_STOCK_SCALE_DIPOLE, "Scale _dipole", NULL, "Scale dipole", OPERATION_SCALE_DIPOLE },
  { "OperationsSelectionOfAtoms", GABEDIT_STOCK_SELECT_RESIDUE, "_Selection of atoms", NULL, "Selection of atoms", OPERATION_SELECTION_ATOMS },
  { "OperationsDeleteObjects", GABEDIT_STOCK_DELETE_CUT, "_Delete selected atoms/bond", NULL, "Delete selected atoms/bond", OPERATION_DELETE_OBJECTS },
  { "OperationsMoveAtoms", GABEDIT_STOCK_MOVE_ATOM, "_Move selected atoms", NULL, "Move selected atoms", OPERATION_MOVE_ATOMS },
  { "OperationsRotationAtoms", GABEDIT_STOCK_ROTATION_LOCAL, "R_otation of selected atoms", NULL, "Rotation of selected atoms", OPERATION_ROTATION_ATOMS },
  { "OperationsRotationZAtoms", GABEDIT_STOCK_ROTATION_Z_LOCAL, "Rotation, about _z axis, of selected atoms", NULL, "Rotation, about z axis, of selected atoms", OPERATION_ROTATION_Z_ATOMS },

  { "OperationsEditObjects", GABEDIT_STOCK_DRAW, "_Insert/Change atoms or bond", NULL, "Insert/Change atoms or bond", OPERATION_EDIT_OBJECTS },
  { "OperationsInsertFrag", GABEDIT_STOCK_IFRAG, "_Insert a fragment", NULL, "Insert a fragment", OPERATION_INSERT_FRAG},
  { "OperationsMesure", GABEDIT_STOCK_MESURE, "_Mesure", NULL, "Mesure", OPERATION_MESURE },
};
static guint numberOfOperationsEntries = G_N_ELEMENTS (operationsEntries);
/*********************************************************************************************************************/
enum 
{
	LABEL_NO,
	LABEL_SYMBOLS,
	LABEL_NUMBERS,
	LABEL_SYMBOLS_NUMBERS,
	LABEL_CHARGES,
	LABEL_SYMBOLS_CHARGES,
	LABEL_NUMBERS_CHARGES,
	LABEL_REDIDUES,
	LABEL_COORDINATES,
	LABEL_MMTYPES,
	LABEL_PDBTYPES,
	LABEL_LAYERS,
};
static void render_label_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));

	switch(value)
	{
		case LABEL_NO : SetLabelOptions (NULL,  LABELNO); break;
		case  LABEL_SYMBOLS : SetLabelOptions (NULL, LABELSYMB ); break;
		case  LABEL_NUMBERS : SetLabelOptions (NULL,  LABELNUMB); break;
		case  LABEL_MMTYPES : SetLabelOptions (NULL,  LABELMMTYP); break;
		case  LABEL_PDBTYPES : SetLabelOptions (NULL,  LABELPDBTYP); break;
		case  LABEL_LAYERS : SetLabelOptions (NULL,  LABELLAYER); break;
		case  LABEL_SYMBOLS_NUMBERS : SetLabelOptions (NULL,  LABELSYMBNUMB); break;
		case  LABEL_CHARGES : SetLabelOptions (NULL,  LABELCHARGE); break;
		case  LABEL_SYMBOLS_CHARGES: SetLabelOptions (NULL,  LABELSYMBCHARGE); break;
		case  LABEL_NUMBERS_CHARGES: SetLabelOptions (NULL,  LABELNUMBCHARGE); break;
		case  LABEL_REDIDUES: SetLabelOptions (NULL,  LABELRESIDUES); break;
		case  LABEL_COORDINATES: SetLabelOptions (NULL,  LABELCOORDINATES); break;
	}
}
static GtkRadioActionEntry labelEntries[] = {
  { "LabelsNothing", NULL, "_Nothing", NULL, "no labels", LABEL_NO },
  { "LabelsSymbols", NULL, "_Symbols", NULL, "show symbols", LABEL_SYMBOLS},
  { "LabelsNumbers", NULL, "_Numbers", NULL, "show numbers of atoms", LABEL_NUMBERS},
  { "LabelsMMTypes", NULL, "_MM Types", NULL, "show MM types of atoms", LABEL_MMTYPES},
  { "LabelsPDBTypes", NULL, "_PDB Types", NULL, "show PDB types of atoms", LABEL_PDBTYPES},
  { "LabelsLayers", NULL, "_Layer", NULL, "show layer of atoms", LABEL_LAYERS},
  { "LabelsSymbolsAndNumbers", NULL, "Symbols_&Numbers", NULL, "show symbols and numbers of atoms", LABEL_SYMBOLS_NUMBERS},
  { "LabelsCharges", NULL, "_Charges", NULL, "show charges of atoms", LABEL_CHARGES},
  { "LabelsSymbolsAndCharges", NULL, "Symbols_&Charges", NULL, "show symbols and charges of atoms", LABEL_SYMBOLS_CHARGES},
  { "LabelsNumbersAndCharges", NULL, "Numbers_&Charges", NULL, "show numbers and charges of atoms", LABEL_NUMBERS_CHARGES},
  { "LabelsRedidues", NULL, "Residues", NULL, "show redidues", LABEL_REDIDUES},
  { "LabelsCoordinates", NULL, "C_oordinates", NULL, "show coordinates of atoms", LABEL_COORDINATES},
};
static guint numberOfLabelEntries = G_N_ELEMENTS (labelEntries);
/*********************************************************************************************************************/
typedef enum 
{
	GEOMETRY_STICK,
	GEOMETRY_BALLSTICK,
}TypeRenderGeom;
static void render_geometry_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));

	switch(value)
	{
		case GEOMETRY_STICK :  RenderStick(); break;
		case GEOMETRY_BALLSTICK : RenderBallStick(); break;
	}
}
static GtkRadioActionEntry rendereGeometryEntries[] = {
  { "RenderGeometryStick", GABEDIT_STOCK_RENDER_STICK, "_Stick", NULL, "render stick", GEOMETRY_STICK },
  { "RenderGeometryBallAndStick", GABEDIT_STOCK_RENDER_BALL_STICK, "_Ball&Stick", NULL, "render Ball&Stick", GEOMETRY_BALLSTICK },
};
static guint numberOfRenderGeometryEntries = G_N_ELEMENTS (rendereGeometryEntries);
/*********************************************************************************************************************/
static void toggle_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	if(!strcmp(name,"LabelsDistances")) SetLabelDistances(NULL, TRUE);
	else if(!strcmp(name,"LabelsDipole")) SetLabelDipole(NULL, TRUE);
	else if(!strcmp(name,"RenderPerspective")) RenderPers(NULL, TRUE);
	else if(!strcmp(name,"RenderLighting")) RenderLight(NULL, TRUE);
	else if(!strcmp(name,"RenderCartoon")) RenderCartoon(NULL, TRUE);
	else if(!strcmp(name,"RenderShad")) RenderShad(NULL, TRUE);
	else if(!strcmp(name,"RenderShowDipole")) RenderDipole(NULL, TRUE);
	else if(!strcmp(name,"RenderShowHydrogenBonds")) RenderHBonds(NULL, TRUE);
	else if(!strcmp(name,"RenderShowDoubleTripleBonds"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		RenderMultipleBonds(NULL,show);
	}
	else if(!strcmp(name,"ShowToolBar")) view_toolbar();
	else if(!strcmp(name,"ShowStatusBox"))
	{
		GtkWidget* box = g_object_get_data(G_OBJECT(GeomDlg), "StatusBox");
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		gtk_widget_hide(box);
		if(show) gtk_widget_show(box);
	}
	else if(!strcmp(name,"ShowMesureNoteBook"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		HideShowMesure(!show);
	}
	else if(!strcmp(name,"AdjustHydrogens"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		AdjustHydrogensYesNo(show);
	}
	else if(!strcmp(name,"RebuildConnectionsDuringEdition"))
	{
		gboolean rebuild = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		RebuildConnectionsDuringEditionYesNo(rebuild);
	}
}
/*--------------------------------------------------------------------------------------------------------------------*/
static GtkToggleActionEntry gtkActionToggleEntries[] =
{
	{ "LabelsDistances", NULL, "_Distances", NULL, "show distances", G_CALLBACK (toggle_action), FALSE },
	{ "LabelsDipole", NULL, "_Dipole", NULL, "show dipole", G_CALLBACK (toggle_action), FALSE },

	{ "RenderPerspective", NULL, "_Perspective", NULL, "render perspective", G_CALLBACK (toggle_action), FALSE },
	{ "RenderLighting", NULL, "_Lighting", NULL, "render lighting", G_CALLBACK (toggle_action), FALSE },
	{ "RenderCartoon", NULL, "_Cartoon", NULL, "render cartoon", G_CALLBACK (toggle_action), FALSE },
	{ "RenderShad", NULL, "_Shad", NULL, "render shad", G_CALLBACK (toggle_action), FALSE },
	{ "RenderShowDipole", NULL, "Show _Dipole", NULL, "Show dipole", G_CALLBACK (toggle_action), FALSE },
	{ "RenderShowHydrogenBonds", NULL, "Show _Hydrogen bonds", NULL, "Show hydrogen bonds", G_CALLBACK (toggle_action), FALSE },
	{ "RenderShowDoubleTripleBonds", NULL, "Show _double & triple bonds", NULL, "Show double&triple bonds", G_CALLBACK (toggle_action), TRUE },

	{ "ShowToolBar", NULL, "_Show toolbar", NULL, "show toolbar", G_CALLBACK (toggle_action), TRUE },
	{ "ShowStatusBox", NULL, "_show status handlebox", NULL, "show status handlebox", G_CALLBACK (toggle_action), TRUE},

	{ "ShowMesureNoteBook", GABEDIT_STOCK_HIDE, "show the mesure notebook", NULL, "show the mesure notebook", G_CALLBACK (toggle_action), FALSE},
	{ "AdjustHydrogens", GABEDIT_STOCK_ADJUST_H, "Adjust _hydrogens", NULL, "Adjus hydrogens", G_CALLBACK (toggle_action), FALSE},
	{ "RebuildConnectionsDuringEdition", GTK_STOCK_DISCONNECT, "Rebuild _connections during a move", NULL, "Rebuild connections during a mov", G_CALLBACK (toggle_action), FALSE},

};

static guint numberOfGtkActionToggleEntries = G_N_ELEMENTS (gtkActionToggleEntries);
/*********************************************************************************************************************/
static void activate_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	if(!strcmp(name,"ReadXYZ")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_XYZ); }
	else if(!strcmp(name,"ReadMol2")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOL2); }
	else if(!strcmp(name,"ReadTinker")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_TINKER); }
	else if(!strcmp(name,"ReadPDB")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_PDB); }
	else if(!strcmp(name,"ReadHyperchem")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_HIN);}
	else if(!strcmp(name,"ReadMol")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOL);}
	else if(!strcmp(name,"ReadGabedit")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GABEDIT);}
	else if(!strcmp(name,"ReadGaussianZMat")) { MethodeGeom = GEOM_IS_ZMAT;selc_ZMatrix_file(); }
	else if(!strcmp(name,"ReadMopacZMat")) { MethodeGeom = GEOM_IS_ZMAT;selc_ZMatrix_mopac_file(); }
	else if(!strcmp(name,"ReadDaltonFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_DALTONFIRST); }
	else if(!strcmp(name,"ReadDaltonLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_DALTONLAST); }
	else if(!strcmp(name,"ReadGamessFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAMESSFIRST); }
	else if(!strcmp(name,"ReadGamessLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAMESSLAST); }
	else if(!strcmp(name,"ReadGaussianInput")) { selc_all_input_file("Read Geometry from a Gaussian input file"); }
	else if(!strcmp(name,"ReadGaussianFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAUSSOUTFIRST); }
	else if(!strcmp(name,"ReadGaussianLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAUSSOUTLAST);}
	else if(!strcmp(name,"ReadMolcasInput")) { selc_all_input_file("Read Geometry from a Molcas input file");}
	else if(!strcmp(name,"ReadMolcasFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLCASOUTFIRST);}
	else if(!strcmp(name,"ReadMolcasLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLCASOUTLAST);}
	else if(!strcmp(name,"ReadMolproInput")) { selc_all_input_file("Read Geometry from a Molpro input file");}
	else if(!strcmp(name,"ReadMolproFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLPROOUTFIRST);}
	else if(!strcmp(name,"ReadMolproLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOLPROOUTLAST);}
	else if(!strcmp(name,"ReadMopacInput")) { selc_all_input_file("Read Geometry from a Mopac input file");}
	else if(!strcmp(name,"ReadMopacFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOPACOUTFIRST);}
	else if(!strcmp(name,"ReadMopacLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOPACOUTLAST);}
	else if(!strcmp(name,"ReadMopacAux")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MOPACAUX);}
	else if(!strcmp(name,"ReadMopacScan")) 
	{ 
 	  	file_chooser_open(read_geometries_conv_mopac_scan,"Read Geomtries From Mopac Scan Output file", GABEDIT_TYPEFILE_MOPAC,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"ReadMPQCInput")) { selc_all_input_file("Read Geometry from a MPQC input file");}
	else if(!strcmp(name,"ReadMPQCFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MPQCOUTFIRST);}
	else if(!strcmp(name,"ReadMPQCLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_MPQCOUTLAST);}
	else if(!strcmp(name,"ReadPCGamessFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAMESSFIRST); }
	else if(!strcmp(name,"ReadPCGamessLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_GAMESSLAST); }
	else if(!strcmp(name,"ReadOrcaFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_ORCAOUTFIRST);}
	else if(!strcmp(name,"ReadOrcaLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_ORCAOUTLAST);}
	else if(!strcmp(name,"ReadQChemFirst")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_QCHEMOUTFIRST);}
	else if(!strcmp(name,"ReadQChemLast")) { MethodeGeom = GEOM_IS_XYZ;selc_XYZ_file(GABEDIT_TYPEFILEGEOM_QCHEMOUTLAST);}
	else if(!strcmp(name,"ReadUsingOpenBabel")) { create_babel_read_dialogue(); }
	else if(!strcmp(name,"ReadGeomConvDalton"))
 	  file_chooser_open(read_geometries_conv_dalton,"Load Geom. Conv. From Dalton Output file", GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvGamess"))
 	  file_chooser_open(read_geometries_conv_gamess,"Load Geom. Conv. From Gamess Output file", GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvGaussian"))
 	  file_chooser_open(read_geometries_conv_gaussian,"Load Geom. Conv. From Gaussian Output file", GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvMolpro"))
   	  file_chooser_open(read_geometries_conv_molpro,"Load Geom. Conv. From Molpro log file", GABEDIT_TYPEFILE_MOLPRO_LOG,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvMopac"))
   	  file_chooser_open(read_geometries_conv_mopac,"Load Geom. Conv. From Molpac aux file", GABEDIT_TYPEFILE_MOPAC_AUX,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvMPQC"))
   	  file_chooser_open(read_geometries_conv_mpqc,"Load Geom. Conv. From MPQC output file", GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvOrca"))
   	  file_chooser_open(read_geometries_conv_orca,"Load Geom. Conv. From ORCA output file", GABEDIT_TYPEFILE_ORCA,GABEDIT_TYPEWIN_GEOM);

	else if(!strcmp(name,"ReadGeomConvQChem"))
   	  file_chooser_open(read_geometries_conv_qchem,"Load Geom. Conv. From Q-Chem output file", GABEDIT_TYPEFILE_QCHEM,GABEDIT_TYPEWIN_GEOM);

	else if(!strcmp(name,"ReadGeomConvGabedit"))
   	  file_chooser_open(read_geometries_conv_gabedit,"Load Geom. Conv. From Gabedit file", GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_GEOM);

	else if(!strcmp(name,"ReadGeomConvMolden"))
   	  file_chooser_open(read_geometries_conv_molden,"Load Geom. Conv. From Molden file", GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"ReadGeomConvXYZ"))
  	  file_chooser_open(read_geometries_conv_xyz,"Load Geom. Conv. From XYZ", GABEDIT_TYPEFILE_XYZ,GABEDIT_TYPEWIN_GEOM);
	else if(!strcmp(name,"EditDeleteMolecule")) DeleteMolecule();
	else if(!strcmp(name,"EditDeleteHydrogenAtoms")) deleteHydrogenAtoms();
	else if(!strcmp(name,"EditDeleteSelectedAtoms")) deleteSelectedAtoms();
	else if(!strcmp(name,"EditMoveCenterOfSelectedAtomsToOrigin")) moveCenterOfSelectedAtomsToOrigin();
	else if(!strcmp(name,"EditAlignPrincipalAxesOfSelectedAtomsToXYZ")) alignPrincipalAxesOfSelectedAtomsToXYZ();
	else if(!strcmp(name,"EditAlignSelectedAndNotSelectedAtoms")) alignSelectedAndNotSelectedAtoms();
	else if(!strcmp(name,"EditCopySelectedAtoms")) copySelectedAtoms();
	else if(!strcmp(name,"EditResetAllConnections")) resetConnections();
	else if(!strcmp(name,"EditResetConnectionsBetweenSelectedAndNotSelectedAtoms")) resetConnectionsBetweenSelectedAndNotSelectedAtoms();
	else if(!strcmp(name,"EditResetConnectionsBetweenSelectedAtoms")) resetConnectionsBetweenSelectedAtoms();

	else if(!strcmp(name,"EditResetMultipleConnections")) resetMultipleConnections();
	else if(!strcmp(name,"EditSelectAll"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectAllAtoms();
	}
	else if(!strcmp(name,"EditInvertSelection"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		InvertSelectionOfAtoms();
	}
	else if(!strcmp(name,"EditUnSelectAll"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		unSelectAllAtoms();
	}
	else if(!strcmp(name,"EditSelectHighAtoms"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectLayerAtoms(HIGH_LAYER);
	}
	else if(!strcmp(name,"EditSelectMediumAtoms"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectLayerAtoms(MEDIUM_LAYER);
	}
	else if(!strcmp(name,"EditSelectLowAtoms"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectLayerAtoms(LOW_LAYER);
	}
	else if(!strcmp(name,"EditSelectFixedAtoms"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectFixedVariableAtoms(FALSE);
	}
	else if(!strcmp(name,"EditSelectVariableAtoms"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectFixedVariableAtoms(TRUE);
	}
	else if(!strcmp(name,"EditSelectFirstResidue"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectFirstResidue();
	}
	else if(!strcmp(name,"EditSelectLastResidue"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		SelectLastResidue();
	}
	else if(!strcmp(name,"EditSelectResidueByName"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		selectResidueByNameDlg();
	}
	else if(!strcmp(name,"EditSelectAtomsByMMType"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		selectAtomsByMMTypeDlg();
	}
	else if(!strcmp(name,"EditSelectAtomsByPDBType"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		selectAtomsByPDBTypeDlg();
	}
	else if(!strcmp(name,"EditSelectAtomsBySymbol"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		selectAtomsBySymbolDlg();
	}
	else if(!strcmp(name,"EditSelectAtomsByPositiveCharges"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		selectAtomsByChargeValues(TRUE);
	}
	else if(!strcmp(name,"EditSelectAtomsByNegativeCharges"))
	{
		GtkAction *selectionAtoms = gtk_ui_manager_get_action (manager, "/MenuGeom/Operations/OperationsSelectionOfAtoms");
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(selectionAtoms), TRUE);
		selectAtomsByChargeValues(FALSE);
	}
	else if(!strcmp(name,"EditOpenGeometryEditor")) 
	{
		if(MethodeGeom == GEOM_IS_XYZ) create_GeomXYZ_from_draw_grometry();
		edit_geometry();
		unSelectAllAtoms();
	}
	else if(!strcmp(name,"SaveAsXYZ"))
	{
		create_GeomXYZ_from_draw_grometry();
 	  	file_chooser_save(save_geometry_xyz_file,"Save geometry in xyz file", GABEDIT_TYPEFILE_XYZ,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"SaveAsGabedit"))
	{
		create_GeomXYZ_from_draw_grometry();
 	  	file_chooser_save(save_geometry_gabedit_file,"Save geometry in Gabedit file", GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"SaveAsMol2"))
	{
		create_GeomXYZ_from_draw_grometry();
 		file_chooser_save(save_geometry_mol2_file,"Save geometry in mol2 file", GABEDIT_TYPEFILE_MOL2,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"SaveAsTinker"))
	{
		create_GeomXYZ_from_draw_grometry();
 		file_chooser_save(save_geometry_tinker_file,"Save geometry in tinker file", GABEDIT_TYPEFILE_TINKER,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"SaveAsPDB"))
	{
		create_GeomXYZ_from_draw_grometry();
 		file_chooser_save(save_geometry_pdb_file,"Save geometry in pdb file", GABEDIT_TYPEFILE_PDB,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"SaveAsHyperchem"))
	{
		create_GeomXYZ_from_draw_grometry();
 		file_chooser_save(save_geometry_hin_file,"Save geometry in hyperchem file", GABEDIT_TYPEFILE_HIN,GABEDIT_TYPEWIN_GEOM);
	}
	else if(!strcmp(name,"SaveAsMopacZMat"))
	{
		create_GeomXYZ_from_draw_grometry(); 
		MethodeGeom = GEOM_IS_XYZ;
		if(!xyz_to_zmat())
		{
			Message("Sorry\nConversion is not possible from XYZ to Zmat","Error",TRUE);
			return;
		}
 		file_chooser_save(save_geometry_mzmatrix_file,"Save geometry in mopac z-matrix file", GABEDIT_TYPEFILE_MZMAT,GABEDIT_TYPEWIN_GEOM);
		create_GeomXYZ_from_draw_grometry(); 
		MethodeGeom = GEOM_IS_XYZ;
	}
	else if(!strcmp(name,"SaveAsGaussianZMat"))
	{
		create_GeomXYZ_from_draw_grometry(); 
		MethodeGeom = GEOM_IS_XYZ;
		if(!xyz_to_zmat())
		{
			Message("Sorry\nConversion is not possible from XYZ to Zmat","Error",TRUE);
			return;
		}
 		file_chooser_save(save_geometry_gzmatrix_file,"Save geometry in gaussian z-matrix file", GABEDIT_TYPEFILE_GZMAT,GABEDIT_TYPEWIN_GEOM);
		create_GeomXYZ_from_draw_grometry(); 
		MethodeGeom = GEOM_IS_XYZ;
	}
	else if(!strcmp(name,"SaveUsingOpenBabel")) { create_babel_save_dialogue(); }
	else if(!strcmp(name,"BuildLinearMolecule")) build_linear_molecule_dlg();
	else if(!strcmp(name,"BuildNanoTube")) build_nanotube_dlg();
	else if(!strcmp(name,"BuildRingMolecule")) build_ring_molecule_dlg();
	else if(!strcmp(name,"BuildMoleculeWithSymmetry")) build_rozphi_molecule_dlg();
	else if(!strcmp(name,"BuildPolyPeptide")) build_polypeptide_dlg();
	else if(!strcmp(name,"BuildPolyNucleicAcid")) build_polynucleicacid_dlg();
	else if(!strcmp(name,"BuildPolySaccharide")) build_polysaccharide_dlg();
	else if(!strcmp(name,"PersonalFragmentsNewGroup")) newGroupeDlg(NULL, 0, NULL);
	else if(!strcmp(name,"PersonalFragmentsDeleteGroup")) deleteGroupeDlg(NULL, 0, NULL);
	else if(!strcmp(name,"PersonalFragmentsAddMolecule"))  addFragmentDlg(NULL, 0, NULL);
	else if(!strcmp(name,"PersonalFragmentsRemoveFragment")) deleteFragmentDlg(NULL, 0, NULL);
	else if(!strcmp(name, "RenderDefaultStick")) factor_stick_default(NULL, NULL);
	else if(!strcmp(name, "RenderDefaultBall"))factor_ball_default(NULL, NULL);
	else if(!strcmp(name, "RenderDefaultZoom")) factor_default(NULL, NULL);
	else if(!strcmp(name, "RenderDefaultDipole")) factor_dipole_default(NULL, NULL);
	else if(!strcmp(name, "RenderDefaultCenter")) SetOperation(NULL, CENTER);
	else if(!strcmp(name, "RenderDefaultAll")) factor_all_default(NULL, NULL);
	else if(!strcmp(name, "RenderBackgroundColorBlack")) set_back_color_black();
	else if(!strcmp(name, "RenderBackgroundColorOther")) open_color_dlg( NULL, NULL);
	else if(!strcmp(name,"RenderHideHydrogenAtoms")) RenderHAtoms(NULL, FALSE);
	else if(!strcmp(name, "RenderHideSelectedAtoms")) hide_selected_atoms();
	else if(!strcmp(name, "RenderHideNotSelectedAtoms")) hide_not_selected_atoms();
	else if(!strcmp(name, "RenderShowAllAtoms")) show_all_atoms();
	else if(!strcmp(name, "RenderShowHydrogenAtoms")) show_hydrogen_atoms();

	else if(!strcmp(name, "SymmetryRotationalConstantes")) create_symmetry_window( NULL, 0);
	else if(!strcmp(name, "SymmetryGroupSymmetry")) get_standard_orientation_with_reduction(NULL, 0);
	else if(!strcmp(name, "SymmetryAbelianGroup")) get_abelian_orientation_with_reduction(NULL, 0);
	else if(!strcmp(name, "SymmetrySetTolerance")) create_tolerance_window (NULL, 0);
	else if(!strcmp(name, "SetOriginToCenterOfMolecule")) SetOriginAtCenter(NULL, 0, NULL);
	else if(!strcmp(name, "SetOriginToCenterOfSelectedAtoms")) set_origin_to_center_of_fragment();
	else if(!strcmp(name, "SetXYZToPAX")) set_xyz_to_principal_axes_of_selected_atoms(NULL,0, NULL);
	else if(!strcmp(name, "SetXYZToPAZ")) set_xyz_to_principal_axes_of_selected_atoms(NULL,1, NULL);
	else if(!strcmp(name, "SetSelectedAtomsToHighLayer")) set_layer_of_selected_atoms(HIGH_LAYER);
	else if(!strcmp(name, "SetSelectedAtomsToMediumLayer")) set_layer_of_selected_atoms(MEDIUM_LAYER);
	else if(!strcmp(name, "SetSelectedAtomsToLowLayer")) set_layer_of_selected_atoms(LOW_LAYER);
	else if(!strcmp(name, "SetSelectedAtomsToFixed")) set_fix_selected_atoms();
	else if(!strcmp(name, "SetSelectedAtomsToVariable")) set_variable_selected_atoms();
	else if(!strcmp(name, "SetMMTypeOfselectedAtoms")) setMMTypeOfselectedAtomsDlg();
	else if(!strcmp(name, "SetPDBTypeOfselectedAtoms")) setPDBTypeOfselectedAtomsDlg();
	else if(!strcmp(name, "SetChargeOfselectedAtoms")) setChargeOfselectedAtomsDlg();
	else if(!strcmp(name, "scaleChargesOfSelectedAtoms")) scaleChargesOfSelectedAtomsDlg();
	else if(!strcmp(name, "InsertAFragment")) activate_insert_fragment();
	else if(!strcmp(name, "AddMaxHydrogens")) addMaxHydrogens();
	else if(!strcmp(name, "AddHydrogens")) addHydrogens();
	else if(!strcmp(name, "AddHydrogensTpl")) addHydrogensTpl();
	else if(!strcmp(name, "AddOneHydrogen")) addOneHydrogen();
	else if(!strcmp(name, "SetDipole")) set_dipole_dialog();
	else if(!strcmp(name, "SetDipoleFormCharges")) set_dipole_from_charges();
	else if(!strcmp(name, "ComputeDipoleFormCharges")) compute_dipole_from_charges();
	else if(!strcmp(name, "ComputeTotalCharge")) compute_total_charge();
	else if(!strcmp(name, "ComputeChargeForResidues")) compute_charge_by_residue();
	else if(!strcmp(name, "ComputeChargeOfSelectedsAtoms")) compute_charge_of_selected_atoms();
	else if(!strcmp(name, "SetHydrogenBonds"))set_HBonds_dialog_geom(NULL, 0);
	else if(!strcmp(name, "SetPropertiesOfAtoms")) create_table_prop();
	else if(!strcmp(name, "SetMolecularMechanicsParameters")) setMMParamatersDlg();
	else if(!strcmp(name, "SetPDBTemplate")) setPDBTemplateDlg();
	else if(!strcmp(name, "SetChargesUsingPDBTemplate")) setMMTypesCharges(NULL, 0, NULL);
	else if(!strcmp(name, "SetAtomTypesUsingPDBTemplate")) setMMTypesCharges(NULL, 1, NULL);
	else if(!strcmp(name, "SetAtomTypeAndChargeUsingPDBTemplate")) setMMTypesCharges(NULL, 2, NULL);
	else if(!strcmp(name, "SetAtomTypeCalcul")) setMMTypesCharges(NULL, 4, NULL);
	else if(!strcmp(name, "SetChargesToZero")) setMMTypesCharges(NULL, 3, NULL);
	else if(!strcmp(name, "SetPovrayBackground")) set_povray_options_geom(NULL,0);
	else if(!strcmp(name, "SetAtomToInsert")) select_atom();
	else if(!strcmp(name, "ExportPostscript")) export_geometry_dlg("ps");
	else if(!strcmp(name, "ExportEPS")) export_geometry_dlg("eps");
	else if(!strcmp(name, "ExportPovray")) exportPOVGeomDlg(GeomDlg);
	else if(!strcmp(name, "ExportPDF")) export_geometry_dlg("pdf");
	else if(!strcmp(name, "ExportSVG")) export_geometry_dlg("svg");
	else if(!strcmp(name, "ScreenCaptureJPG")) 
	{
 		GtkWidget* chooser = file_chooser_save(save_geometry_jpeg_file,"Save image in jpeg file format",GABEDIT_TYPEFILE_JPEG,GABEDIT_TYPEWIN_GEOM);
		fit_windows_position(GeomDlg, chooser);
	}
	else if(!strcmp(name, "ScreenCapturePPM"))
	{
 		GtkWidget* chooser = file_chooser_save(save_geometry_ppm_file,"Save image in ppm file format",GABEDIT_TYPEFILE_PPM,GABEDIT_TYPEWIN_GEOM);
		fit_windows_position(GeomDlg, chooser);
	}
	else if(!strcmp(name, "ScreenCaptureBMP"))
	{
 		GtkWidget* chooser = file_chooser_save(save_geometry_bmp_file,"Save image in bmp file format",GABEDIT_TYPEFILE_BMP,GABEDIT_TYPEWIN_GEOM);
		fit_windows_position(GeomDlg, chooser);
	}
	else if(!strcmp(name, "ScreenCapturePNG"))
	{
 		GtkWidget* chooser = file_chooser_save(save_geometry_png_file,"Save image in png file format",GABEDIT_TYPEFILE_PNG,GABEDIT_TYPEWIN_GEOM);
		fit_windows_position(GeomDlg, chooser);
	}
	else if(!strcmp(name, "ScreenCapturePS"))
	{
 		GtkWidget* chooser = file_chooser_save(save_geometry_ps_file,"Save image in ps file format",GABEDIT_TYPEFILE_PS,GABEDIT_TYPEWIN_GEOM);
		fit_windows_position(GeomDlg, chooser);
	}
	else if(!strcmp(name, "ScreenCaptureCilpBoard")) 
	{
		copy_screen_geom_clipboard();
	}

	else if(!strcmp(name, "MolecularMechanicsEnergy")) 
	{
		MolecularMechanicsEnergyDlg();
		messageAmberTypesDefine();
	}
	else if(!strcmp(name, "MolecularMechanicsOptimization"))
	{
		MolecularMechanicsMinimizeDlg();
		messageAmberTypesDefine();
	}
	else if(!strcmp(name, "MolecularMechanicsDynamics"))
	{
		MolecularMechanicsDynamicsDlg();
		messageAmberTypesDefine();
	}
	else if(!strcmp(name, "MolecularMechanicsDynamicsConfo"))
	{
		MolecularMechanicsDynamicsConfoDlg();
		messageAmberTypesDefine();
	}
	else if(!strcmp(name, "SemiEmpiricalMD"))
	{
		semiEmpiricalMolecularDynamicsDlg();
	}
	else if(!strcmp(name, "SemiEmpiricalMDConfo"))
	{
		semiEmpiricalMolecularDynamicsConfoDlg();
	}
	else if(!strcmp(name, "SemiEmpiricalEnergyPCGamessAM1"))
	{
		semiEmpiricalDlg("AM1PCGamessEnergy");
	}
	else if(!strcmp(name, "SemiEmpiricalEnergyMopacPM6"))
	{
		semiEmpiricalDlg("PM6MopacEnergy");
	}
	else if(!strcmp(name, "SemiEmpiricalEnergyMopacAM1"))
	{
		semiEmpiricalDlg("AM1MopacEnergy");
	}
	else if(!strcmp(name, "SemiEmpiricalOptimisationPCGamessAM1"))
	{
		semiEmpiricalDlg("AM1PCGamessOptimize");
	}
	else if(!strcmp(name, "SemiEmpiricalOptimisationMopacPM6"))
	{
		semiEmpiricalDlg("PM6MopacOptimize");
	}
	else if(!strcmp(name, "SemiEmpiricalESPMopacPM6"))
	{
		semiEmpiricalDlg("PM6MopacESP");
	}
	else if(!strcmp(name, "SemiEmpiricalOptimisationMopac"))
	{
		semiEmpiricalDlg("MopacOptimize");
	}
	else if(!strcmp(name, "SemiEmpiricalESPMopac"))
	{
		semiEmpiricalDlg("MopacESP");
	}
	else if(!strcmp(name, "SemiEmpiricalScanMopacPM6"))
	{
		semiEmpiricalDlg("MopacScanPM6");
	}
	else if(!strcmp(name, "SemiEmpiricalScanMopacAM1"))
	{
		semiEmpiricalDlg("MopacScanAM1");
	}
	else if(!strcmp(name, "SemiEmpiricalScanMopac"))
	{
		semiEmpiricalDlg("MopacScan");
	}
	else if(!strcmp(name, "SemiEmpiricalEnergyMopac"))
	{
		semiEmpiricalDlg("MopacEnergy");
	}
	else if(!strcmp(name, "SemiEmpiricalOptimisationMopacAM1"))
	{
		semiEmpiricalDlg("AM1MopacOptimize");
	}
	else if(!strcmp(name, "SemiEmpiricalESPMopacAM1"))
	{
		semiEmpiricalDlg("AM1MopacESP");
	}
	else if(!strcmp(name, "SemiEmpiricalEnergyOrca"))
	{
		semiEmpiricalDlg("OrcaEnergy");
	}
	else if(!strcmp(name, "SemiEmpiricalOptimisationOrca"))
	{
		semiEmpiricalDlg("OrcaOptimize");
	}

	else if(!strcmp(name, "Close")) destroy_drawing_and_childs(NULL, 0);
}
/*--------------------------------------------------------------------*/
static GtkActionEntry gtkActionEntries[] =
{
	{"Read", NULL, "_Read"},
	{"ReadXYZ", NULL, "_XYZ file", NULL, "Read a XYZ file", G_CALLBACK (activate_action) },
	{"ReadMol2", NULL, "_Mol2 file", NULL, "Read a Mol2 file", G_CALLBACK (activate_action) },
	{"ReadTinker", NULL, "_Tinker file", NULL, "Read a Tinker file", G_CALLBACK (activate_action) },
	{"ReadPDB", GABEDIT_STOCK_PDB, "_PDB file", NULL, "Read a PDB file", G_CALLBACK (activate_action) },
	{"ReadHyperchem", NULL, "_Hyperchem file", NULL, "Read a Hyperchem file", G_CALLBACK (activate_action) },
	{"ReadMol", NULL, "_Mol file", NULL, "Read a Mol file", G_CALLBACK (activate_action) },
	{"ReadGabedit", GABEDIT_STOCK_GABEDIT, "_Gabedit file", NULL, "Read a Gabedit file", G_CALLBACK (activate_action) },
	{"ReadGaussianZMat", GABEDIT_STOCK_GAUSSIAN, "_Gaussian Z-Matrix file", NULL, "Read a Gaussian Z-Matrix file", G_CALLBACK (activate_action) },
	{"ReadMopacZMat", GABEDIT_STOCK_MOPAC, "_Mopac Z-Matrix file", NULL, "Read a Mopac Z-Matrix file", G_CALLBACK (activate_action) },

	{"Dalton", GABEDIT_STOCK_DALTON, "_Dalton"},
	{"ReadDaltonFirst", GABEDIT_STOCK_DALTON, "F_irst geometry from a Dalton output file", NULL, "Read the first geometry from a Dalton output file", G_CALLBACK (activate_action) },
	{"ReadDaltonLast", GABEDIT_STOCK_DALTON, "L_ast geometry from a Dalton output file", NULL, "Read the last geometry from a Dalton output file", G_CALLBACK (activate_action) },

	{"Gamess", GABEDIT_STOCK_GAMESS, "Ga_mess"},
	{"ReadGamessFirst", GABEDIT_STOCK_GAMESS, "F_irst geometry from a Gamess output file", NULL, "Read the first geometry from a Gamess output file", G_CALLBACK (activate_action) },
	{"ReadGamessLast", GABEDIT_STOCK_GAMESS, "L_ast geometry from a Gamess output file", NULL, "Read the last geometry from a Gamess output file", G_CALLBACK (activate_action) },

	{"Gaussian", GABEDIT_STOCK_GAUSSIAN, "_Gaussian"},
	{"ReadGaussianInput", GABEDIT_STOCK_GAUSSIAN, "_Gaussian Input file", NULL, "Read a Gaussian Input file", G_CALLBACK (activate_action) },
	{"ReadGaussianFirst", GABEDIT_STOCK_GAUSSIAN, "F_irst geometry from a Gaussian output file", NULL, "Read the first geometry from a Gaussian output file", G_CALLBACK (activate_action) },
	{"ReadGaussianLast", GABEDIT_STOCK_GAUSSIAN, "L_ast geometry from a Gaussian output file", NULL, "Read the last geometry from a Gaussian output file", G_CALLBACK (activate_action) },

	{"Molcas", GABEDIT_STOCK_MOLCAS, "Mol_cas"},
	{"ReadMolcasInput", GABEDIT_STOCK_MOLCAS, "Mol_cas Input file", NULL, "Read a Molcas Input file", G_CALLBACK (activate_action) },
	{"ReadMolcasFirst", GABEDIT_STOCK_MOLCAS, "F_irst geometry from a Molcas output file", NULL, "Read the first geometry from a Molcas output file", G_CALLBACK (activate_action) },
	{"ReadMolcasLast", GABEDIT_STOCK_MOLCAS, "L_ast geometry from a Molcas output file", NULL, "Read the last geometry from a Molcas output file", G_CALLBACK (activate_action) },

	{"Molpro", GABEDIT_STOCK_MOLPRO, "Mol_pro"},
	{"ReadMolproInput", GABEDIT_STOCK_MOLPRO, "Mol_pro Input file", NULL, "Read a Molpro Input file", G_CALLBACK (activate_action) },
	{"ReadMolproFirst", GABEDIT_STOCK_MOLPRO, "F_irst geometry from a Molpro output file", NULL, "Read the first geometry from a Molpro output file", G_CALLBACK (activate_action) },
	{"ReadMolproLast", GABEDIT_STOCK_MOLPRO, "L_ast geometry from a Molpro output file", NULL, "Read the last geometry from a Molpro output file", G_CALLBACK (activate_action) },

	{"Mopac", GABEDIT_STOCK_MOPAC, "_Mopac"},
	{"ReadMopacInput", GABEDIT_STOCK_MOPAC, "_Mopac Input file", NULL, "Read a Mopac Input file", G_CALLBACK (activate_action) },
	{"ReadMopacFirst", GABEDIT_STOCK_MOPAC, "F_irst geometry from a Mopac output file", NULL, "Read the first geometry from a Mopac output file", G_CALLBACK (activate_action) },
	{"ReadMopacLast", GABEDIT_STOCK_MOPAC, "L_ast geometry from a Mopac output file", NULL, "Read the last geometry from a Mopac output file", G_CALLBACK (activate_action) },
	{"ReadMopacAux", GABEDIT_STOCK_MOPAC, "L_ast geometry from a Mopac aux file", NULL, "Read the last geometry from a Mopac aux file", G_CALLBACK (activate_action) },
	{"ReadMopacScan", GABEDIT_STOCK_MOPAC, "Geometries from a Mopac _scan output file", NULL, "Geometries from a Mopac scan output file", G_CALLBACK (activate_action) },

	{"MPQC", GABEDIT_STOCK_MPQC, "MP_QC"},
	{"ReadMPQCInput", GABEDIT_STOCK_MPQC, "MP_QC Input file", NULL, "Read a MPQC Input file", G_CALLBACK (activate_action) },
	{"ReadMPQCFirst", GABEDIT_STOCK_MPQC, "F_irst geometry from a MPQC output file", NULL, "Read the first geometry from a MPQC output file", G_CALLBACK (activate_action) },
	{"ReadMPQCLast", GABEDIT_STOCK_MPQC, "L_ast geometry from a MPQC output file", NULL, "Read the last geometry from a MPQC output file", G_CALLBACK (activate_action) },

	{"Orca", GABEDIT_STOCK_ORCA, "_Orca"},
	{"ReadOrcaFirst", GABEDIT_STOCK_ORCA, "F_irst geometry from a Orca output file", NULL, "Read the first geometry from a Orca output file", G_CALLBACK (activate_action) },
	{"ReadOrcaLast", GABEDIT_STOCK_ORCA, "L_ast geometry from a Orca output file", NULL, "Read the last geometry from a Orca output file", G_CALLBACK (activate_action) },


	{"PCGamess", GABEDIT_STOCK_PCGAMESS, "_PCGamess"},
	{"ReadPCGamessFirst", GABEDIT_STOCK_PCGAMESS, "F_irst geometry from a PCGamess output file", NULL, "Read the first geometry from a PCGamess output file", G_CALLBACK (activate_action) },
	{"ReadPCGamessLast", GABEDIT_STOCK_PCGAMESS, "L_ast geometry from a PCGamess output file", NULL, "Read the last geometry from a PCGamess output file", G_CALLBACK (activate_action) },

	{"QChem", GABEDIT_STOCK_QCHEM, "Q-_Chem"},
	{"ReadQChemFirst", GABEDIT_STOCK_QCHEM, "F_irst geometry from a Q-Chem output file", NULL, "Read the first geometry from a Q-Chem output file", G_CALLBACK (activate_action) },
	{"ReadQChemLast", GABEDIT_STOCK_QCHEM, "L_ast geometry from a Q-Chem output file", NULL, "Read the last geometry from a Q-Chem output file", G_CALLBACK (activate_action) },

	{"ReadUsingOpenBabel", GABEDIT_STOCK_OPEN_BABEL, "_Other format (using open babel)", NULL, "Other format (using open babel)", G_CALLBACK (activate_action) },

	{"ReadGeomConv", NULL, "Geometries _Convergence"},
	{"ReadGeomConvDalton", GABEDIT_STOCK_DALTON, "from a _Dalton output file", NULL, "Read Geometries Convergence from a Dalton output file", G_CALLBACK (activate_action) },
	{"ReadGeomConvGamess", GABEDIT_STOCK_GAMESS, "from a _Gamess output file", NULL, "Read Geometries Convergence from a Gamess output file", G_CALLBACK (activate_action) },
	{"ReadGeomConvGaussian", GABEDIT_STOCK_GAUSSIAN, "from a _Gaussian output file", NULL, "Read Geometries Convergence from a Gaussian output file", G_CALLBACK (activate_action) },
	{"ReadGeomConvMolpro", GABEDIT_STOCK_MOLPRO, "from a Mol_pro log file", NULL, "Read Geometries Convergence from a Molpro log file", G_CALLBACK (activate_action) },
	{"ReadGeomConvMopac", GABEDIT_STOCK_MOPAC, "from a _Mopac aux file", NULL, "Read Geometries Convergence from a Mopac aux file", G_CALLBACK (activate_action) },
	{"ReadGeomConvMPQC", GABEDIT_STOCK_MPQC, "from a MP_QC output file", NULL, "Read Geometries Convergence from a MPQC output file", G_CALLBACK (activate_action) },
	{"ReadGeomConvOrca", GABEDIT_STOCK_ORCA, "from a _Orca output file", NULL, "Read Geometries Convergence from a Orca output file", G_CALLBACK (activate_action) },
	{"ReadGeomConvQChem", GABEDIT_STOCK_QCHEM, "from a Q-_Chem output file", NULL, "Read Geometries Convergence from a Q-Chem output file", G_CALLBACK (activate_action) },
	{"ReadGeomConvGabedit", GABEDIT_STOCK_GABEDIT, "from a G_abedit file", NULL, "Read Geometries Convergence from a Gabedit file", G_CALLBACK (activate_action) },
	{"ReadGeomConvMolden", GABEDIT_STOCK_MOLDEN, "from a Mol_den file", NULL, "Read Geometries Convergence from a Molden file", G_CALLBACK (activate_action) },
	{"ReadGeomConvXYZ", NULL, "from a _XYZ file", NULL, "Read several Geometries from a XYZ file", G_CALLBACK (activate_action) },

	{"Edit", NULL, "_Edit"},
	{"EditResetAllConnections", GABEDIT_STOCK_ADD_BOND, "_Reset all connections", NULL, "Reset all connections", G_CALLBACK (activate_action) },
	{"EditResetMultipleConnections", GABEDIT_STOCK_COPY, "_Reset multiple connections", NULL, "Reset multiple connections", G_CALLBACK (activate_action) },

	{"EditResetConnectionsBetweenSelectedAndNotSelectedAtoms", GABEDIT_STOCK_ADD_BOND, "_Reset connections between selected and not selected atoms", NULL, "Reset connections between selected and not selected atoms", G_CALLBACK (activate_action) },
	{"EditResetConnectionsBetweenSelectedAtoms", GABEDIT_STOCK_ADD_BOND, "_Reset connections between selected atoms", NULL, "Reset connections between selected atoms", G_CALLBACK (activate_action) },

	{"EditCopySelectedAtoms", GABEDIT_STOCK_COPY, "_Copy&Past selected atoms", NULL, "Copy&Past selected atoms", G_CALLBACK (activate_action) },
	{"EditDeleteHydrogenAtoms", GABEDIT_STOCK_CUT, "_Remove hydrogen atoms", NULL, "Remove hydrogen atoms", G_CALLBACK (activate_action) },
	{"EditDeleteSelectedAtoms", GABEDIT_STOCK_CUT, "Remove selected atoms", NULL, "Remove selected atoms", G_CALLBACK (activate_action) },
	{"EditMoveCenterOfSelectedAtomsToOrigin", GABEDIT_STOCK_MOVE_ATOM, "Move the center of selected atoms to origin", NULL, "Move selected atoms to origin", G_CALLBACK (activate_action) },
	{"EditAlignPrincipalAxesOfSelectedAtomsToXYZ", NULL, "_Align the principal axes selected atoms to XYZ", NULL, "Align the principal axes of selected atoms to XYZ", G_CALLBACK (activate_action) },
	{"EditAlignSelectedAndNotSelectedAtoms", NULL, "_Align selected and not selected atoms", NULL, "Align selected and not slected atoms to XYZ", G_CALLBACK (activate_action) },
	{"EditDeleteMolecule", GABEDIT_STOCK_CUT, "_Delete molecule", NULL, "Delete molecule", G_CALLBACK (activate_action) },
	{"EditOpenGeometryEditor", NULL, "_Open XYZ or GZMAT editor", NULL, "Open XYZ or GZMAT editor", G_CALLBACK (activate_action) },
	{"Selection", NULL, "_Selection"},
	{"EditSelectAll", NULL, "Select _all atoms", NULL, "Select all atoms", G_CALLBACK (activate_action) },
	{"EditInvertSelection", NULL, "_Invert selection", NULL, "Invert selection", G_CALLBACK (activate_action) },
	{"EditUnSelectAll", NULL, "_Unselect all", NULL, "Unselect all", G_CALLBACK (activate_action) },
	{"EditSelectHighAtoms", NULL, "Select atoms with _high layer", NULL, "Select atoms with high layer", G_CALLBACK (activate_action) },
	{"EditSelectMediumAtoms", NULL, "Select atoms with _medium layer", NULL, "Select atoms with medium layer", G_CALLBACK (activate_action) },
	{"EditSelectLowAtoms", NULL, "Select atoms with _low layer", NULL, "Select atoms with low layer", G_CALLBACK (activate_action) },
	{"EditSelectFixedAtoms", NULL, "Select _freezing atoms during optimizations", NULL, "Select freezing atoms during optimizations", G_CALLBACK (activate_action) },
	{"EditSelectVariableAtoms", NULL, "Select _not freezing atoms during optimizations", NULL, "Select not freezing atoms during optimizations", G_CALLBACK (activate_action) },
	{"EditSelectFirstResidue", NULL, "Select the _first residue", NULL, "Select the first residue", G_CALLBACK (activate_action) },
	{"EditSelectLastResidue", NULL, "Select the _last residue", NULL, "Select the last residue", G_CALLBACK (activate_action) },
	{"EditSelectResidueByName", NULL, "Select residues by name", NULL, "Select residues by name", G_CALLBACK (activate_action) },
	{"EditSelectAtomsByMMType", NULL, "Select atoms by MM type", NULL, "Select atoms by MM type", G_CALLBACK (activate_action) },
	{"EditSelectAtomsByPDBType", NULL, "Select atoms by PDB type", NULL, "Select atoms by PDB type", G_CALLBACK (activate_action) },
	{"EditSelectAtomsBySymbol", NULL, "Select atoms by symbol", NULL, "Select atoms by symbol", G_CALLBACK (activate_action) },
	{"EditSelectAtomsByPositiveCharges", NULL, "Select atoms with positive charges", NULL, "Select atoms with positive charges", G_CALLBACK (activate_action) },
	{"EditSelectAtomsByNegativeCharges", NULL, "Select atoms with negative charges", NULL, "Select atoms with negative charges", G_CALLBACK (activate_action) },

	{"SaveAs", NULL, "_Save as"},
	{"SaveAsGabedit", GABEDIT_STOCK_GABEDIT, "_Gabedit file", NULL, "Save geometry in a Gabedit file", G_CALLBACK (activate_action) },
	{"SaveAsXYZ", NULL, "_XYZ file", NULL, "Save geometry in a XYZ file", G_CALLBACK (activate_action) },
	{"SaveAsMol2", NULL, "_Mol2 file", NULL, "Save geometry in a Mol2 file", G_CALLBACK (activate_action) },
	{"SaveAsTinker", NULL, "_Tinker file", NULL, "Save geometry in a Tinker file", G_CALLBACK (activate_action) },
	{"SaveAsPDB", GABEDIT_STOCK_PDB, "_pdb file", NULL, "Save geometry in a pdb file", G_CALLBACK (activate_action) },
	{"SaveAsHyperchem", NULL, "_Hyperchem file", NULL, "Save geometry in a Hyperchem file", G_CALLBACK (activate_action) },
	{"SaveAsMopacZMat", NULL, "_Mopac Zmatrix file", NULL, "Save geometry in a Mopac Zmatrix file", G_CALLBACK (activate_action) },
	{"SaveAsGaussianZMat", GABEDIT_STOCK_GAUSSIAN, "_Gaussian Zmatrix file", NULL, "Save geometry in a Gaussian Zmatrix file", G_CALLBACK (activate_action) },
	{"SaveUsingOpenBabel", GABEDIT_STOCK_OPEN_BABEL, "_Other format (using open babel)", NULL, "Other format (using open babel)", G_CALLBACK (activate_action) },

	{"Add", NULL, "_Add"},
/*
	{"AddAttachFunctionalGroup", NULL, "Attach Functional _Group"},
	{"AddHydrocarbon", NULL, "_Hydrocarbon"},
	{"AddRing", NULL, "_Ring"},
	{"AddDrugs", NULL, "_Drugs"},
	{"AddFullerene", NULL, "_Fullerene"},
	{"AddMiscellaneous", NULL, "_Miscellaneous"},
*/
	{"PersonalFragments", NULL, "Personal _fragment"},
	{"PersonalFragmentsNewGroup", NULL, "_New Group", NULL, "New Group", G_CALLBACK (activate_action) },
	{"PersonalFragmentsDeleteGroup", NULL, "_Delete a Group", NULL, "Delete a Group", G_CALLBACK (activate_action) },
	{"PersonalFragmentsAddMolecule", NULL, "_Add this molecule to personnal Fragments", NULL, "Add this molecule to personnal Fragments", G_CALLBACK (activate_action) },
	{"PersonalFragmentsRemoveFragment", NULL, "_Remove a Fragment", NULL, "Remove a Fragment", G_CALLBACK (activate_action) },
	{"InsertAFragment", NULL, "Add a _fragment", NULL, "Add a fragment", G_CALLBACK (activate_action) },
	{"AddMaxHydrogens", NULL, "Add _Max Hydrogens", NULL, "Add Max Hydrogens", G_CALLBACK (activate_action) },
	{"AddHydrogens", NULL, "Add _Hydrogens", NULL, "Add Hydrogens", G_CALLBACK (activate_action) },
	{"AddOneHydrogen", NULL, "Add _one Hydrogen", NULL, "Add one Hydrogen", G_CALLBACK (activate_action) },
	{"AddHydrogensTpl", NULL, "Add _Hydrogens using PDB template", NULL, "Add Hydrogens using PDB template", G_CALLBACK (activate_action) },

	{"Build", NULL, "_Build"},
	{"BuildLinearMolecule", NULL, "_Linear Molecule", NULL, "build a linear molecule", G_CALLBACK (activate_action) },
	{"BuildRingMolecule", NULL, "_Ring Molecule", NULL, "build a ring molecule", G_CALLBACK (activate_action) },
	{"BuildMoleculeWithSymmetry", NULL, "_Molecule with a symmetry axis of rotation", NULL, "build a molecule with a symmetry axis of rotation", G_CALLBACK (activate_action) },
	{"BuildPolyPeptide", NULL, "Poly_Peptide", NULL, "build a polypeptide", G_CALLBACK (activate_action) },
	{"BuildPolySaccharide", NULL, "Poly_Saccharide", NULL, "build a Polysaccharide", G_CALLBACK (activate_action) },
	{"BuildPolyNucleicAcid", NULL, "Poly_Nucleic Acid", NULL, "build a polynucleic acid", G_CALLBACK (activate_action) },
	{"BuildNanoTube", NULL, "Nano_tube", NULL, "nanotube", G_CALLBACK (activate_action) },

	{"Operations", NULL, "_Operations"},
	{"Labels", NULL, "_Labels"},
	{"Render", NULL, "_Render"},
	{"RenderDefault", NULL, "_Default"},
	{"RenderDefaultStick", GABEDIT_STOCK_RENDER_STICK, "_Stick", NULL, "default stick scale", G_CALLBACK (activate_action) },
	{"RenderDefaultBall", GABEDIT_STOCK_RENDER_BALL_STICK, "_Ball", NULL, "default ball scale", G_CALLBACK (activate_action) },
	{"RenderDefaultZoom", GABEDIT_STOCK_ZOOM, "_Zoom", NULL, "default zoom scale", G_CALLBACK (activate_action) },
	{"RenderDefaultDipole", NULL, "_Dipole", NULL, "default dipole scale", G_CALLBACK (activate_action) },
	{"RenderDefaultCenter", NULL, "_Center", NULL, "center of molecule on centre of screen", G_CALLBACK (activate_action) },
	{"RenderDefaultAll", NULL, "_All", NULL, "reset default parameters", G_CALLBACK (activate_action) },
	{"RenderBackgroundColor", NULL, "_Background Color"},
	{"RenderBackgroundColorBlack", NULL, "_Black", NULL, "black background", G_CALLBACK (activate_action) },
	{"RenderBackgroundColorOther", NULL, "_Other", NULL, "reset the background color", G_CALLBACK (activate_action) },
	{"RenderHideHydrogenAtoms", NULL, "Hide _hydrogen atoms", NULL, "Hide hydrogen atoms", G_CALLBACK (activate_action) },
	{"RenderHideNotSelectedAtoms", NULL, "Hide _not selected atoms", NULL, "Hide not selected atoms", G_CALLBACK (activate_action) },
	{"RenderHideSelectedAtoms", NULL, "Hide _selected atoms", NULL, "Hide selected atoms", G_CALLBACK (activate_action) },
	{"RenderShowHydrogenAtoms", NULL, "_Show hydrogen atoms", NULL, "Show hydrogen atoms", G_CALLBACK (activate_action) },
	{"RenderShowAllAtoms", NULL, "_Show all atoms", NULL, "Show all atoms", G_CALLBACK (activate_action) },

	{"Symmetry", NULL, "_Symmetry"},
	{"SymmetryRotationalConstantes", NULL, "Rotational Constantes & Dipole at there principal axis", NULL, "compute the rotational constantes &  the dipole at there principal axis", G_CALLBACK (activate_action) },
	{"SymmetryGroupSymmetry", NULL, "_Group of symmetry & Geometry with reduce molecule to its basis set of atoms", NULL, "compute the _Groupe symmetry and geometry with  reduce molecule to its basis set of atoms", G_CALLBACK (activate_action) },
	{"SymmetryAbelianGroup", NULL, "_Abelian group & Geometry with  reduce molecule to its basis set of atoms", NULL, "compute the _Abelian group and Geometry with reduce molecule to its basis set of atoms", G_CALLBACK (activate_action) },
	{"SymmetrySetTolerance", NULL, "_Set tolerance parameters", NULL, "Set tolerance parameters", G_CALLBACK (activate_action) },

	{"Set", NULL, "_Set"},
	{"SetOriginToCenterOfMolecule", NULL, "Set origin at _Center of molecule", NULL, "Set origin at center of molecule", G_CALLBACK (activate_action) },
	{"SetOriginToCenterOfSelectedAtoms", NULL, "Set origin at Center of _selected atoms", NULL, "Set origin at center of selected atoms", G_CALLBACK (activate_action) },
	{"SetXYZToPAX", NULL, "Set XYZ axes to the principal axes of selected atoms (_X = min inertia)", NULL, "Set XYZ axes to the principal axes of selected atoms (X = min inertia)", G_CALLBACK (activate_action) },
	{"SetXYZToPAZ", NULL, "Set XYZ axes to the principal axes of selected atoms (_Z = min inertia)", NULL, "Set XYZ axes to the principal axes of selected atoms (Z axis = min inertia)", G_CALLBACK (activate_action) },
	{"SetSelectedAtomsToHighLayer", NULL, "Set selected atoms to _Hight layer", NULL, "Set selected atoms to Hight layer", G_CALLBACK (activate_action) },
	{"SetSelectedAtomsToMediumLayer", NULL, "Set selected atoms to _Medium layer", NULL, "Set selected atoms to Medium layer", G_CALLBACK (activate_action) },
	{"SetSelectedAtomsToLowLayer", NULL, "Set selected atoms to _Low layer", NULL, "Set selected atoms to Low layer", G_CALLBACK (activate_action) },
	{"SetSelectedAtomsToFixed", NULL, "Set selected atoms to _freezing during optimizations", NULL, "Set selected atoms to freezing during optimizations", G_CALLBACK (activate_action) },
	{"SetSelectedAtomsToVariable", NULL, "Set selected atoms to _not freezing during optimizations", NULL, "Set selected atoms to not freezing during optimizations", G_CALLBACK (activate_action) },
	{"SetMMTypeOfselectedAtoms", NULL, "Set the _MM type of selected atoms", NULL, "Set the MM type of selected atoms", G_CALLBACK (activate_action) },
	{"SetPDBTypeOfselectedAtoms", NULL, "Set the _PDB type of selected atoms", NULL, "Set the PDB type of selected atoms", G_CALLBACK (activate_action) },
	{"SetChargeOfselectedAtoms", NULL, "Set the _Charge of selected atoms", NULL, "Set the charge of selected atoms", G_CALLBACK (activate_action) },
	{"scaleChargesOfSelectedAtoms", NULL, "scale the _Charge of selected atoms", NULL, "scale the charge of selected atoms", G_CALLBACK (activate_action) },
	{"SetDipole", NULL, "_Dipole", NULL, "Set dipole", G_CALLBACK (activate_action) },
	{"SetDipoleFormCharges", NULL, "_Compute Dipole from charges", NULL, "Compute dipole using charges", G_CALLBACK (activate_action) },
	{"SetHydrogenBonds", NULL, "_Hydrogen bonds parameters", NULL, "Set the hydrogen bonds parameters", G_CALLBACK (activate_action) },
	{"SetPropertiesOfAtoms", NULL, "P_roperties of atoms", NULL, "Set properties of atoms", G_CALLBACK (activate_action) },
	{"SetMolecularMechanicsParameters", NULL, "_Molecular Mechanics Parameters", NULL, "Set molecular mechanics parameters", G_CALLBACK (activate_action) },
	{"SetPDBTemplate", NULL, "_PDB Template", NULL, "Set PDB Template", G_CALLBACK (activate_action) },
	{"SetChargesUsingPDBTemplate", NULL, "_Charges using PDB Template", NULL, "Set charges using PDB Template", G_CALLBACK (activate_action) },
	{"SetAtomTypesUsingPDBTemplate", NULL, "Atom _Types using PDB Template", NULL, "Set atom types using PDB Template", G_CALLBACK (activate_action) },
	{"SetAtomTypeAndChargeUsingPDBTemplate", NULL, "Atom Type&Charge using PDB Template", NULL, "Set atom type and charge using PDB Template", G_CALLBACK (activate_action) },
	{"SetAtomTypeCalcul", NULL, "Atom Types using connections types", NULL, "Compute atom types using the types of connections", G_CALLBACK (activate_action) },
	{"SetChargesToZero", NULL, "Charges to _zero", NULL, "Set charges to zero", G_CALLBACK (activate_action) },
	{"SetPovrayBackground", NULL, "_Povray background", NULL, "Set povray background", G_CALLBACK (activate_action) },

	{"SetAtomToInsert", GABEDIT_STOCK_ATOMTOINSERT, "Set _atom to insert", NULL, "Set atom to insert", G_CALLBACK (activate_action) },

	{"Export", NULL, "Ex_port"},
	{"ExportPostscript", NULL, "P_ostscript", NULL, "create a postscript file", G_CALLBACK (activate_action) },
	{"ExportEPS", NULL, "_Encapsuled Postscript", NULL, "create a Encapsuled Postscript file", G_CALLBACK (activate_action) },
	{"ExportPovray", NULL, "Po_vray", NULL, "create a povray file", G_CALLBACK (activate_action) },
	{"ExportPDF", NULL, "_PDF", NULL, "create a pdf file", G_CALLBACK (activate_action) },
	{"ExportSVG", NULL, "_SVG", NULL, "create a svg file", G_CALLBACK (activate_action) },
	{"Tools", NULL, "_Tools"},
	{"ComputeTotalCharge", NULL, "_Compute total charge", NULL, "Compute total charge", G_CALLBACK (activate_action) },
	{"ComputeChargeForResidues", NULL, "Compute charge for _residues", NULL, "Compute charge for residues", G_CALLBACK (activate_action) },
	{"ComputeChargeOfSelectedsAtoms", NULL, "Compute charge of _selected atoms", NULL, "Compute charge of selected atoms", G_CALLBACK (activate_action) },
	{"ComputeDipoleFormCharges", NULL, "_Compute dipole from charges", NULL, "Compute dipole from charges", G_CALLBACK (activate_action) },

	{"ScreenCapture", NULL, "Screen Ca_pture"},
	{"ScreenCaptureJPG", NULL, "_JPG format", NULL, "create a JPEG file", G_CALLBACK (activate_action) },
	{"ScreenCapturePPM", NULL, "_PPM format", NULL, "create a PPM file", G_CALLBACK (activate_action) },
	{"ScreenCaptureBMP", NULL, "_BMP format", NULL, "create a BMP file", G_CALLBACK (activate_action) },
	{"ScreenCapturePNG", NULL, "_PNG format", NULL, "create a PNG file", G_CALLBACK (activate_action) },
	{"ScreenCapturePS", NULL, "_PS format", NULL, "create a PS file", G_CALLBACK (activate_action) },
	{"ScreenCaptureCilpBoard", NULL, "_Copy to clipboard", NULL, "copy to clipboard", G_CALLBACK (activate_action) },

	{"MolecularMechanics", NULL, "_Molecular Mechanics"},
	{"MolecularMechanicsEnergy", NULL, "_Energy", NULL, "compute the energy using the MM method", G_CALLBACK (activate_action) },
	{"MolecularMechanicsOptimization", NULL, "_Optimization", NULL, "optimize the geometry using the MM method", G_CALLBACK (activate_action) },
	{"MolecularMechanicsDynamics", NULL, "Molcecular _Dynamics", NULL, "Molcecular dynamics using the MM method", G_CALLBACK (activate_action) },
	{"MolecularMechanicsDynamicsConfo", NULL, "Molcecular _Dynamics Conformational search", NULL, "Molcecular dynamics conformational search using the MM method", G_CALLBACK (activate_action) },

	{"SemiEmpirical", NULL, "_Semi-empirical"},
	{"SemiEmpiricalEnergyPCGamessAM1", NULL, "PCGamess AM1 _Energy", NULL, "compute the energy using the AM1 method from PCGamess", G_CALLBACK (activate_action) },
	{"SemiEmpiricalOptimisationPCGamessAM1", NULL, "PCGamess AM1 _Optimization", NULL, "optimize the geometry using the AM1 method from PCGamess", G_CALLBACK (activate_action) },

	{"SemiEmpiricalEnergyMopac", NULL, "Mopac _Energy", NULL, "compute the energy using Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalOptimisationMopac", NULL, "Mopac _Optimisation", NULL, "optimize the geometry using Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalESPMopac", NULL, "Mopac _ESP charges", NULL, "ESP Charge using Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalScanMopac", NULL, "Mopac _Reaction path", NULL, "Mopac Scan calculation", G_CALLBACK (activate_action) },

	{"SemiEmpiricalEnergyMopacPM6", NULL, "Mopac PM6 _Energy", NULL, "compute the energy using the PM6 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalOptimisationMopacPM6", NULL, "Mopac PM6 _Optimisation", NULL, "optimize the geometry using the PM6 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalESPMopacPM6", NULL, "Mopac PM6 _ESP charges", NULL, "ESP Charge using the PM6 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalScanMopacPM6", NULL, "Mopac PM6 _Reaction path", NULL, "Reaction path using the PM6 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalEnergyMopacAM1", NULL, "Mopac AM1 _Energy", NULL, "compute the energy using the AM1 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalOptimisationMopacAM1", NULL, "Mopac AM1 _Optimisation", NULL, "optimize the geometry using the AM1 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalESPMopacAM1", NULL, "Mopac AM1 _ESP charges", NULL, "ESP Charge using the AM1 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalScanMopacAM1", NULL, "Mopac AM1 _Reaction path", NULL, "Reaction path using the AM1 method from Mopac", G_CALLBACK (activate_action) },
	{"SemiEmpiricalEnergyOrca", NULL, "Orca _Energy", NULL, "compute the energy using Orca", G_CALLBACK (activate_action) },
	{"SemiEmpiricalOptimisationOrca", NULL, "Orca _Optimisation", NULL, "optimize the geometry using Orca", G_CALLBACK (activate_action) },
	{"SemiEmpiricalMD", NULL, "Molcecular _Dynamics", NULL, "Molcecular dynamics using a semi-empirical method", G_CALLBACK (activate_action) },
	{"SemiEmpiricalMDConfo", NULL, "Molcecular _Dynamics Conformational search", NULL, "Molcecular dynamics conformational search using a semi-empirical  method", G_CALLBACK (activate_action) },


	{"View", NULL, "_View"},

	{"Close", GABEDIT_STOCK_CLOSE, "_Close", NULL, "Close", G_CALLBACK (activate_action) },
};
static guint numberOfGtkActionEntries = G_N_ELEMENTS (gtkActionEntries);
/********************************************************************************/
/* XML description of the menus for the test app.  The parser understands
 * a subset of the Bonobo UI XML format, and uses GMarkup for parsing */
static const gchar *uiMenuInfo =
"  <popup name=\"MenuGeom\">\n"
"    <separator name=\"sepMenuPopRead\" />\n"
"    <menu name=\"Read\" action=\"Read\">\n"
"      <menuitem name=\"ReadGabedit\" action=\"ReadGabedit\" />\n"
"      <menuitem name=\"ReadXYZ\" action=\"ReadXYZ\" />\n"
"      <menuitem name=\"ReadMol2\" action=\"ReadMol2\" />\n"
"      <menuitem name=\"ReadTinker\" action=\"ReadTinker\" />\n"
"      <menuitem name=\"ReadPDB\" action=\"ReadPDB\" />\n"
"      <menuitem name=\"ReadHyperchem\" action=\"ReadHyperchem\" />\n"
"      <menuitem name=\"ReadMol\" action=\"ReadMol\" />\n"
"      <separator name=\"sepMenuReadDalton\" />\n"
"      <menu name=\"Dalton\" action=\"Dalton\">\n"
"        <menuitem name=\"ReadDaltonFirst\" action=\"ReadDaltonFirst\" />\n"
"        <menuitem name=\"ReadDaltonLast\" action=\"ReadDaltonLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadGamess\" />\n"
"      <menu name=\"Gamess\" action=\"Gamess\">\n"
"        <menuitem name=\"ReadGamessFirst\" action=\"ReadGamessFirst\" />\n"
"        <menuitem name=\"ReadGamessLast\" action=\"ReadGamessLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadGaussian\" />\n"
"      <menu name=\"Gaussian\" action=\"Gaussian\">\n"
"        <menuitem name=\"ReadGaussianInput\" action=\"ReadGaussianInput\" />\n"
"        <menuitem name=\"ReadGaussianFirst\" action=\"ReadGaussianFirst\" />\n"
"        <menuitem name=\"ReadGaussianLast\" action=\"ReadGaussianLast\" />\n"
"        <menuitem name=\"ReadGaussianZMat\" action=\"ReadGaussianZMat\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadMolcas\" />\n"
"      <menu name=\"Molcas\" action=\"Molcas\">\n"
"        <menuitem name=\"ReadMolcasInput\" action=\"ReadMolcasInput\" />\n"
"        <menuitem name=\"ReadMolcasFirst\" action=\"ReadMolcasFirst\" />\n"
"        <menuitem name=\"ReadMolcasLast\" action=\"ReadMolcasLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadMolpro\" />\n"
"      <menu name=\"Molpro\" action=\"Molpro\">\n"
"        <menuitem name=\"ReadMolproInput\" action=\"ReadMolproInput\" />\n"
"        <menuitem name=\"ReadMolproFirst\" action=\"ReadMolproFirst\" />\n"
"        <menuitem name=\"ReadMolproLast\" action=\"ReadMolproLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadMopac\" />\n"
"      <menu name=\"Mopac\" action=\"Mopac\">\n"
"        <menuitem name=\"ReadMopacInput\" action=\"ReadMopacInput\" />\n"
"        <menuitem name=\"ReadMopacFirst\" action=\"ReadMopacFirst\" />\n"
"        <menuitem name=\"ReadMopacLast\" action=\"ReadMopacLast\" />\n"
"        <menuitem name=\"ReadMopacAux\" action=\"ReadMopacAux\" />\n"
"        <menuitem name=\"ReadMopacScan\" action=\"ReadMopacScan\" />\n"
"        <menuitem name=\"ReadMopacZMat\" action=\"ReadMopacZMat\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadMPQC\" />\n"
"      <menu name=\"MPQC\" action=\"MPQC\">\n"
"        <menuitem name=\"ReadMPQCInput\" action=\"ReadMPQCInput\" />\n"
"        <menuitem name=\"ReadMPQCFirst\" action=\"ReadMPQCFirst\" />\n"
"        <menuitem name=\"ReadMPQCLast\" action=\"ReadMPQCLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadOrca\" />\n"
"      <menu name=\"Orca\" action=\"Orca\">\n"
"        <menuitem name=\"ReadOrcaFirst\" action=\"ReadOrcaFirst\" />\n"
"        <menuitem name=\"ReadOrcaLast\" action=\"ReadOrcaLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadPCGamess\" />\n"
"      <menu name=\"PCGamess\" action=\"PCGamess\">\n"
"        <menuitem name=\"ReadPCGamessFirst\" action=\"ReadPCGamessFirst\" />\n"
"        <menuitem name=\"ReadPCGamessLast\" action=\"ReadPCGamessLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadQChem\" />\n"
"      <menu name=\"QChem\" action=\"QChem\">\n"
"        <menuitem name=\"ReadQChemFirst\" action=\"ReadQChemFirst\" />\n"
"        <menuitem name=\"ReadQChemLast\" action=\"ReadQChemLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuReadOpenBabel\" />\n"
"      <menuitem name=\"ReadUsingOpenBabel\" action=\"ReadUsingOpenBabel\" />\n"
"      <separator name=\"sepMenuReadGeomConv\" />\n"
"      <menu name=\"ReadGeomConv\" action=\"ReadGeomConv\">\n"
"        <menuitem name=\"ReadGeomConvDalton\" action=\"ReadGeomConvDalton\" />\n"
"        <menuitem name=\"ReadGeomConvGamess\" action=\"ReadGeomConvGamess\" />\n"
"        <menuitem name=\"ReadGeomConvGaussian\" action=\"ReadGeomConvGaussian\" />\n"
"        <menuitem name=\"ReadGeomConvMolpro\" action=\"ReadGeomConvMolpro\" />\n"
"        <menuitem name=\"ReadGeomConvMopac\" action=\"ReadGeomConvMopac\" />\n"
"        <menuitem name=\"ReadGeomConvMPQC\" action=\"ReadGeomConvMPQC\" />\n"
"        <menuitem name=\"ReadGeomConvOrca\" action=\"ReadGeomConvOrca\" />\n"
"        <menuitem name=\"ReadGeomConvQChem\" action=\"ReadGeomConvQChem\" />\n"
"        <menuitem name=\"ReadGeomConvGabedit\" action=\"ReadGeomConvGabedit\" />\n"
"        <menuitem name=\"ReadGeomConvMolden\" action=\"ReadGeomConvMolden\" />\n"
"        <menuitem name=\"ReadGeomConvXYZ\" action=\"ReadGeomConvXYZ\" />\n"
"      </menu>\n"
"    </menu>\n"
"      <menu name=\"Edit\" action=\"Edit\">\n"
"        <menuitem name=\"EditResetAllConnections\" action=\"EditResetAllConnections\" />\n"
"        <menuitem name=\"EditResetMultipleConnections\" action=\"EditResetMultipleConnections\" />\n"
"        <menuitem name=\"EditResetConnectionsBetweenSelectedAndNotSelectedAtoms\" action=\"EditResetConnectionsBetweenSelectedAndNotSelectedAtoms\" />\n"
"        <menuitem name=\"EditResetConnectionsBetweenSelectedAtoms\" action=\"EditResetConnectionsBetweenSelectedAtoms\" />\n"
"        <separator name=\"sepMenuEditCopySelectedAtoms\" />\n"
"        <menuitem name=\"EditCopySelectedAtoms\" action=\"EditCopySelectedAtoms\" />\n"
"        <separator name=\"sepMenuEditDeleteMolecule\" />\n"
"        <menuitem name=\"EditDeleteHydrogenAtoms\" action=\"EditDeleteHydrogenAtoms\" />\n"
"        <menuitem name=\"EditDeleteSelectedAtoms\" action=\"EditDeleteSelectedAtoms\" />\n"
"        <menuitem name=\"EditDeleteMolecule\" action=\"EditDeleteMolecule\" />\n"
"        <separator name=\"sepMenuEditMove\" />\n"
"        <menuitem name=\"EditMoveCenterOfSelectedAtomsToOrigin\" action=\"EditMoveCenterOfSelectedAtomsToOrigin\" />\n"
#ifdef EXPERIMENTAL
"        <menuitem name=\"EditAlignPrincipalAxesOfSelectedAtomsToXYZ\" action=\"EditAlignPrincipalAxesOfSelectedAtomsToXYZ\" />\n"
"        <menuitem name=\"EditAlignSelectedAndNotSelectedAtoms\" action=\"EditAlignSelectedAndNotSelectedAtoms\" />\n"
#endif
"        <separator name=\"sepMenuEditOpenGeometryEditor\" />\n"
"        <menuitem name=\"EditOpenGeometryEditor\" action=\"EditOpenGeometryEditor\" />\n"
"        <separator name=\"sepMenuPersonalFragments\" />\n"
"        <menu name=\"PersonalFragments\" action=\"PersonalFragments\">\n"
"          <menuitem name=\"PersonalFragmentsNewGroup\" action=\"PersonalFragmentsNewGroup\" />\n"
"          <menuitem name=\"PersonalFragmentsDeleteGroup\" action=\"PersonalFragmentsDeleteGroup\" />\n"
"          <separator name=\"sepMenuPersonalFragmentsAddMolecule\" />\n"
"          <menuitem name=\"PersonalFragmentsAddMolecule\" action=\"PersonalFragmentsAddMolecule\" />\n"
"          <menuitem name=\"PersonalFragmentsRemoveFragment\" action=\"PersonalFragmentsRemoveFragment\" />\n"
"        </menu>\n"
"      </menu>\n"
"      <menu name=\"Selection\" action=\"Selection\">\n"
"        <menuitem name=\"EditSelectAll\" action=\"EditSelectAll\" />\n"
"        <menuitem name=\"EditInvertSelection\" action=\"EditInvertSelection\" />\n"
"        <menuitem name=\"EditUnSelectAll\" action=\"EditUnSelectAll\" />\n"
"        <separator name=\"sepMenuSelectHighAtoms\" />\n"
"        <menuitem name=\"EditSelectHighAtoms\" action=\"EditSelectHighAtoms\" />\n"
"        <menuitem name=\"EditSelectMediumAtoms\" action=\"EditSelectMediumAtoms\" />\n"
"        <menuitem name=\"EditSelectLowAtoms\" action=\"EditSelectLowAtoms\" />\n"
"        <separator name=\"sepMenuSelectFixedAtoms\" />\n"
"        <menuitem name=\"EditSelectFixedAtoms\" action=\"EditSelectFixedAtoms\" />\n"
"        <menuitem name=\"EditSelectVariableAtoms\" action=\"EditSelectVariableAtoms\" />\n"
"        <menuitem name=\"EditSelectFirstResidue\" action=\"EditSelectFirstResidue\" />\n"
"        <menuitem name=\"EditSelectLastResidue\" action=\"EditSelectLastResidue\" />\n"
"        <menuitem name=\"EditSelectResidueByName\" action=\"EditSelectResidueByName\" />\n"
"        <menuitem name=\"EditSelectAtomsByMMType\" action=\"EditSelectAtomsByMMType\" />\n"
"        <menuitem name=\"EditSelectAtomsByPDBType\" action=\"EditSelectAtomsByPDBType\" />\n"
"        <menuitem name=\"EditSelectAtomsBySymbol\" action=\"EditSelectAtomsBySymbol\" />\n"
"        <menuitem name=\"EditSelectAtomsByPositiveCharges\" action=\"EditSelectAtomsByPositiveCharges\" />\n"
"        <menuitem name=\"EditSelectAtomsByNegativeCharges\" action=\"EditSelectAtomsByNegativeCharges\" />\n"
"      </menu>\n"
"      <menu name=\"SaveAs\" action=\"SaveAs\">\n"
"        <menuitem name=\"SaveAsGabedit\" action=\"SaveAsGabedit\" />\n"
"        <menuitem name=\"SaveAsXYZ\" action=\"SaveAsXYZ\" />\n"
"        <menuitem name=\"SaveAsMol2\" action=\"SaveAsMol2\" />\n"
"        <menuitem name=\"SaveAsTinker\" action=\"SaveAsTinker\" />\n"
"        <menuitem name=\"SaveAsPDB\" action=\"SaveAsPDB\" />\n"
"        <menuitem name=\"SaveAsHyperchem\" action=\"SaveAsHyperchem\" />\n"
"        <separator name=\"sepMenuSaveAsZmat\" />\n"
"        <menuitem name=\"SaveAsMopacZMat\" action=\"SaveAsMopacZMat\" />\n"
"        <menuitem name=\"SaveAsGaussianZMat\" action=\"SaveAsGaussianZMat\" />\n"
"        <separator name=\"sepMenuSaveOpenBabel\" />\n"
"        <menuitem name=\"SaveUsingOpenBabel\" action=\"SaveUsingOpenBabel\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuAdd\" />\n"
"      <menu name=\"Add\" action=\"Add\">\n"
"        <menuitem name=\"InsertAFragment\" action=\"InsertAFragment\" />\n"
"          <separator name=\"sepMenuAddEnd\" />\n"
"          <menuitem name=\"AddHydrogens\" action=\"AddHydrogens\" />\n"
"          <menuitem name=\"AddMaxHydrogens\" action=\"AddMaxHydrogens\" />\n"
"          <menuitem name=\"AddOneHydrogen\" action=\"AddOneHydrogen\" />\n"
"          <separator name=\"sepMenuAddTpl\" />\n"
"          <menuitem name=\"AddHydrogensTpl\" action=\"AddHydrogensTpl\" />\n"
"      </menu>\n"
"      <menu name=\"Build\" action=\"Build\">\n"
"        <menuitem name=\"BuildLinearMolecule\" action=\"BuildLinearMolecule\" />\n"
"        <separator name=\"sepBuildRingMolecule\" />\n"
"        <menuitem name=\"BuildRingMolecule\" action=\"BuildRingMolecule\" />\n"
"        <separator name=\"sepBuildBuildMoleculeWithSymmetry\" />\n"
"        <menuitem name=\"BuildMoleculeWithSymmetry\" action=\"BuildMoleculeWithSymmetry\" />\n"
"        <separator name=\"sepBuildBuildPolyPeptide\" />\n"
"        <menuitem name=\"BuildPolyPeptide\" action=\"BuildPolyPeptide\" />\n"
"        <separator name=\"sepBuildBuildPolyNucleicAcid\" />\n"
"        <menuitem name=\"BuildPolyNucleicAcid\" action=\"BuildPolyNucleicAcid\" />\n"
"        <separator name=\"sepBuildBuildPolySaccharide\" />\n"
"        <menuitem name=\"BuildPolySaccharide\" action=\"BuildPolySaccharide\" />\n"
"        <separator name=\"sepBuildBuildNanoTube\" />\n"
"        <menuitem name=\"BuildNanoTube\" action=\"BuildNanoTube\" />\n"
"      </menu>\n"
"    <separator name=\"sepMenuOperations\" />\n"
"    <menu name=\"Operations\" action=\"Operations\">\n"
"      <menuitem name=\"OperationsTranslate\" action=\"OperationsTranslate\" />\n"
"      <menuitem name=\"OperationsRotation\" action=\"OperationsRotation\" />\n"
"      <menuitem name=\"OperationsRotationZ\" action=\"OperationsRotationZ\" />\n"
"      <menuitem name=\"OperationsZoom\" action=\"OperationsZoom\" />\n"
"      <menuitem name=\"OperationsScaleStick\" action=\"OperationsScaleStick\" />\n"
"      <menuitem name=\"OperationsScaleBall\" action=\"OperationsScaleBall\" />\n"
"      <menuitem name=\"OperationsScaleDipole\" action=\"OperationsScaleDipole\" />\n"
"      <separator name=\"sepMenuSelectionOfAtoms\" />\n"
"      <menuitem name=\"OperationsSelectionOfAtoms\" action=\"OperationsSelectionOfAtoms\" />\n"
"      <menuitem name=\"OperationsDeleteObjects\" action=\"OperationsDeleteObjects\" />\n"
"      <menuitem name=\"OperationsMoveAtoms\" action=\"OperationsMoveAtoms\" />\n"
"      <menuitem name=\"OperationsRotationAtoms\" action=\"OperationsRotationAtoms\" />\n"
"      <menuitem name=\"OperationsRotationZAtoms\" action=\"OperationsRotationZAtoms\" />\n"
"      <menuitem name=\"OperationsEditObjects\" action=\"OperationsEditObjects\" />\n"
"      <menuitem name=\"OperationsInsertFrag\" action=\"OperationsInsertFrag\" />\n"
"      <separator name=\"sepMenuMesure\" />\n"
"      <menuitem name=\"OperationsMesure\" action=\"OperationsMesure\" />\n"
"    </menu>\n"
"    <menu name=\"Labels\" action=\"Labels\">\n"
"      <menuitem name=\"LabelsNothing\" action=\"LabelsNothing\" />\n"
"      <menuitem name=\"LabelsSymbols\" action=\"LabelsSymbols\" />\n"
"      <menuitem name=\"LabelsNumbers\" action=\"LabelsNumbers\" />\n"
"      <menuitem name=\"LabelsMMTypes\" action=\"LabelsMMTypes\" />\n"
"      <menuitem name=\"LabelsPDBTypes\" action=\"LabelsPDBTypes\" />\n"
"      <menuitem name=\"LabelsLayers\" action=\"LabelsLayers\" />\n"
"      <menuitem name=\"LabelsSymbolsAndNumbers\" action=\"LabelsSymbolsAndNumbers\" />\n"
"      <menuitem name=\"LabelsCharges\" action=\"LabelsCharges\" />\n"
"      <menuitem name=\"LabelsSymbolsAndCharges\" action=\"LabelsSymbolsAndCharges\" />\n"
"      <menuitem name=\"LabelsNumbersAndCharges\" action=\"LabelsNumbersAndCharges\" />\n"
"      <menuitem name=\"LabelsRedidues\" action=\"LabelsRedidues\" />\n"
"      <menuitem name=\"LabelsCoordinates\" action=\"LabelsCoordinates\" />\n"
"      <separator name=\"sepMenuLabelsDistances\" />\n"
"      <menuitem name=\"LabelsDistances\" action=\"LabelsDistances\" />\n"
"      <menuitem name=\"LabelsDipole\" action=\"LabelsDipole\" />\n"
"    </menu>\n"
"    <menu name=\"Render\" action=\"Render\">\n"
"      <menuitem name=\"RenderGeometryStick\" action=\"RenderGeometryStick\" />\n"
"      <menuitem name=\"RenderGeometryBallAndStick\" action=\"RenderGeometryBallAndStick\" />\n"
"      <separator name=\"sepMenuPerspective\" />\n"
"      <menuitem name=\"RenderPerspective\" action=\"RenderPerspective\" />\n"
"      <menuitem name=\"RenderLighting\" action=\"RenderLighting\" />\n"
"      <menuitem name=\"RenderCartoon\" action=\"RenderCartoon\" />\n"
"      <menuitem name=\"RenderShad\" action=\"RenderShad\" />\n"
"      <separator name=\"sepMenuShowDipole\" />\n"
"      <menuitem name=\"RenderShowDipole\" action=\"RenderShowDipole\" />\n"
"      <menuitem name=\"RenderShowHydrogenBonds\" action=\"RenderShowHydrogenBonds\" />\n"
"      <menuitem name=\"RenderShowDoubleTripleBonds\" action=\"RenderShowDoubleTripleBonds\" />\n"
"      <separator name=\"sepMenuDefault\" />\n"
"      <menu name=\"RenderDefault\" action=\"RenderDefault\">\n"
"         <menuitem name=\"RenderDefaultStick\" action=\"RenderDefaultStick\" />\n"
"         <menuitem name=\"RenderDefaultBall\" action=\"RenderDefaultBall\" />\n"
"         <menuitem name=\"RenderDefaultZoom\" action=\"RenderDefaultZoom\" />\n"
"         <menuitem name=\"RenderDefaultDipole\" action=\"RenderDefaultDipole\" />\n"
"         <menuitem name=\"RenderDefaultCenter\" action=\"RenderDefaultCenter\" />\n"
"         <menuitem name=\"RenderDefaultAll\" action=\"RenderDefaultAll\" />\n"
"      </menu>\n"
"      <menu name=\"RenderBackgroundColor\" action=\"RenderBackgroundColor\">\n"
"         <menuitem name=\"RenderBackgroundColorBlack\" action=\"RenderBackgroundColorBlack\" />\n"
"         <menuitem name=\"RenderBackgroundColorOther\" action=\"RenderBackgroundColorOther\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuShowHide\" />\n"
"      <menuitem name=\"RenderHideHydrogenAtoms\" action=\"RenderHideHydrogenAtoms\" />\n"
"      <menuitem name=\"RenderHideNotSelectedAtoms\" action=\"RenderHideNotSelectedAtoms\" />\n"
"      <menuitem name=\"RenderHideSelectedAtoms\" action=\"RenderHideSelectedAtoms\" />\n"
"      <menuitem name=\"RenderShowHydrogenAtoms\" action=\"RenderShowHydrogenAtoms\" />\n"
"      <menuitem name=\"RenderShowAllAtoms\" action=\"RenderShowAllAtoms\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuSymmetry\" />\n"
"    <menu name=\"Symmetry\" action=\"Symmetry\">\n"
"      <menuitem name=\"SymmetryRotationalConstantes\" action=\"SymmetryRotationalConstantes\" />\n"
"      <menuitem name=\"SymmetryGroupSymmetry\" action=\"SymmetryGroupSymmetry\" />\n"
"      <menuitem name=\"SymmetryAbelianGroup\" action=\"SymmetryAbelianGroup\" />\n"
"      <separator name=\"sepMenuSymmetrySetTolerance\" />\n"
"      <menuitem name=\"SymmetrySetTolerance\" action=\"SymmetrySetTolerance\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuSet\" />\n"
"    <menu name=\"Set\" action=\"Set\">\n"
"      <menuitem name=\"SetOriginToCenterOfMolecule\" action=\"SetOriginToCenterOfMolecule\" />\n"
"      <menuitem name=\"SetOriginToCenterOfSelectedAtoms\" action=\"SetOriginToCenterOfSelectedAtoms\" />\n"
"      <menuitem name=\"SetXYZToPAX\" action=\"SetXYZToPAX\" />\n"
"      <menuitem name=\"SetXYZToPAZ\" action=\"SetXYZToPAZ\" />\n"
"      <separator name=\"sepMenuSetLayer\" />\n"
"      <menuitem name=\"SetSelectedAtomsToHighLayer\" action=\"SetSelectedAtomsToHighLayer\" />\n"
"      <menuitem name=\"SetSelectedAtomsToMediumLayer\" action=\"SetSelectedAtomsToMediumLayer\" />\n"
"      <menuitem name=\"SetSelectedAtomsToLowLayer\" action=\"SetSelectedAtomsToLowLayer\" />\n"
"      <separator name=\"sepMenuSetFixed\" />\n"
"      <menuitem name=\"SetSelectedAtomsToFixed\" action=\"SetSelectedAtomsToFixed\" />\n"
"      <menuitem name=\"SetSelectedAtomsToVariable\" action=\"SetSelectedAtomsToVariable\" />\n"
"      <separator name=\"sepMenuSetType\" />\n"
"      <menuitem name=\"SetMMTypeOfselectedAtoms\" action=\"SetMMTypeOfselectedAtoms\" />\n"
"      <menuitem name=\"SetPDBTypeOfselectedAtoms\" action=\"SetPDBTypeOfselectedAtoms\" />\n"
"      <menuitem name=\"SetChargeOfselectedAtoms\" action=\"SetChargeOfselectedAtoms\" />\n"
"      <menuitem name=\"scaleChargesOfSelectedAtoms\" action=\"scaleChargesOfSelectedAtoms\" />\n"
"      <separator name=\"sepMenuSetDipole\" />\n"
"      <menuitem name=\"SetDipole\" action=\"SetDipole\" />\n"
"      <menuitem name=\"SetDipoleFormCharges\" action=\"SetDipoleFormCharges\" />\n"
"      <separator name=\"sepMenuSetHydrogenBonds\" />\n"
"      <menuitem name=\"SetHydrogenBonds\" action=\"SetHydrogenBonds\" />\n"
"      <separator name=\"sepMenuSetPropertiesOfAtoms\" />\n"
"      <menuitem name=\"SetPropertiesOfAtoms\" action=\"SetPropertiesOfAtoms\" />\n"
"      <separator name=\"sepMenuSetMolecularMechanicsParameters\" />\n"
"      <menuitem name=\"SetMolecularMechanicsParameters\" action=\"SetMolecularMechanicsParameters\" />\n"
"      <menuitem name=\"SetPDBTemplate\" action=\"SetPDBTemplate\" />\n"
"      <separator name=\"sepMenuSetChargesUsingPDBTemplate\" />\n"
"      <menuitem name=\"SetChargesUsingPDBTemplate\" action=\"SetChargesUsingPDBTemplate\" />\n"
"      <menuitem name=\"SetAtomTypesUsingPDBTemplate\" action=\"SetAtomTypesUsingPDBTemplate\" />\n"
"      <menuitem name=\"SetAtomTypeAndChargeUsingPDBTemplate\" action=\"SetAtomTypeAndChargeUsingPDBTemplate\" />\n"
"      <menuitem name=\"SetAtomTypeCalcul\" action=\"SetAtomTypeCalcul\" />\n"
"      <menuitem name=\"SetChargesToZero\" action=\"SetChargesToZero\" />\n"
"      <separator name=\"sepMenuSetPovrayBackground\" />\n"
"      <menuitem name=\"SetPovrayBackground\" action=\"SetPovrayBackground\" />\n"
"    </menu>\n"
"    <separator name=\"sepExport\" />\n"
"    <menu name=\"Export\" action=\"Export\">\n"
"      <menuitem name=\"ExportPostscript\" action=\"ExportPostscript\" />\n"
"      <menuitem name=\"ExportEPS\" action=\"ExportEPS\" />\n"
"      <menuitem name=\"ExportPDF\" action=\"ExportPDF\" />\n"
"      <menuitem name=\"ExportSVG\" action=\"ExportSVG\" />\n"
"      <menuitem name=\"ExportPovray\" action=\"ExportPovray\" />\n"
"    </menu>\n"
"    <separator name=\"sepScreenCapture\" />\n"
"    <menu name=\"ScreenCapture\" action=\"ScreenCapture\">\n"
"      <menuitem name=\"ScreenCaptureJPG\" action=\"ScreenCaptureJPG\" />\n"
"      <menuitem name=\"ScreenCapturePPM\" action=\"ScreenCapturePPM\" />\n"
"      <menuitem name=\"ScreenCaptureBMP\" action=\"ScreenCaptureBMP\" />\n"
"      <menuitem name=\"ScreenCapturePNG\" action=\"ScreenCapturePNG\" />\n"
"      <menuitem name=\"ScreenCapturePS\" action=\"ScreenCapturePS\" />\n"
"      <menuitem name=\"ScreenCaptureCilpBoard\" action=\"ScreenCaptureCilpBoard\" />\n"
"    </menu>\n"
"    <separator name=\"sepTools\" />\n"
"    <menu name=\"Tools\" action=\"Tools\">\n"
"      <menuitem name=\"ComputeTotalCharge\" action=\"ComputeTotalCharge\" />\n"
"      <menuitem name=\"ComputeDipoleFormCharges\" action=\"ComputeDipoleFormCharges\" />\n"
"      <separator name=\"sepSel\" />\n"
"      <menuitem name=\"ComputeChargeForResidues\" action=\"ComputeChargeForResidues\" />\n"
"      <menuitem name=\"ComputeChargeOfSelectedsAtoms\" action=\"ComputeChargeOfSelectedsAtoms\" />\n"
"    </menu>\n"
"    <separator name=\"sepMolecularMechanics\" />\n"
"    <menu name=\"MolecularMechanics\" action=\"MolecularMechanics\">\n"
"      <menuitem name=\"MolecularMechanicsEnergy\" action=\"MolecularMechanicsEnergy\" />\n"
"      <menuitem name=\"MolecularMechanicsOptimization\" action=\"MolecularMechanicsOptimization\" />\n"
"      <menuitem name=\"MolecularMechanicsDynamics\" action=\"MolecularMechanicsDynamics\" />\n"
"      <menuitem name=\"MolecularMechanicsDynamicsConfo\" action=\"MolecularMechanicsDynamicsConfo\" />\n"
"    </menu>\n"
"    <separator name=\"sepSemiEmpirical\" />\n"
"    <menu name=\"SemiEmpirical\" action=\"SemiEmpirical\">\n"
/*
"      <menuitem name=\"SemiEmpiricalEnergyMopacPM6\" action=\"SemiEmpiricalEnergyMopacPM6\" />\n"
"      <menuitem name=\"SemiEmpiricalOptimisationMopacPM6\" action=\"SemiEmpiricalOptimisationMopacPM6\" />\n"
"      <menuitem name=\"SemiEmpiricalESPMopacPM6\" action=\"SemiEmpiricalESPMopacPM6\" />\n"
"      <menuitem name=\"SemiEmpiricalScanMopacPM6\" action=\"SemiEmpiricalScanMopacPM6\" />\n"
"      <separator name=\"sepSemiEmpiricalAM1Mopac\" />\n"
"      <menuitem name=\"SemiEmpiricalEnergyMopacAM1\" action=\"SemiEmpiricalEnergyMopacAM1\" />\n"
"      <menuitem name=\"SemiEmpiricalOptimisationMopacAM1\" action=\"SemiEmpiricalOptimisationMopacAM1\" />\n"
"      <menuitem name=\"SemiEmpiricalESPMopacAM1\" action=\"SemiEmpiricalESPMopacAM1\" />\n"
"      <menuitem name=\"SemiEmpiricalScanMopacAM1\" action=\"SemiEmpiricalScanMopacAM1\" />\n"
*/
"      <separator name=\"sepSemiEmpiricalMopac\" />\n"
"      <menuitem name=\"SemiEmpiricalEnergyMopac\" action=\"SemiEmpiricalEnergyMopac\" />\n"
"      <menuitem name=\"SemiEmpiricalOptimisationMopac\" action=\"SemiEmpiricalOptimisationMopac\" />\n"
"      <menuitem name=\"SemiEmpiricalESPMopac\" action=\"SemiEmpiricalESPMopac\" />\n"
"      <menuitem name=\"SemiEmpiricalScanMopac\" action=\"SemiEmpiricalScanMopac\" />\n"

"      <separator name=\"sepSemiEmpiricalOrca\" />\n"
"      <menuitem name=\"SemiEmpiricalEnergyOrca\" action=\"SemiEmpiricalEnergyOrca\" />\n"
"      <menuitem name=\"SemiEmpiricalOptimisationOrca\" action=\"SemiEmpiricalOptimisationOrca\" />\n"

"      <separator name=\"sepSemiEmpiricalPCGamess\" />\n"
"      <menuitem name=\"SemiEmpiricalEnergyPCGamessAM1\" action=\"SemiEmpiricalEnergyPCGamessAM1\" />\n"
"      <menuitem name=\"SemiEmpiricalOptimisationPCGamessAM1\" action=\"SemiEmpiricalOptimisationPCGamessAM1\" />\n"

"      <separator name=\"sepSemiEmpiricalMD\" />\n"
"      <menuitem name=\"SemiEmpiricalMD\" action=\"SemiEmpiricalMD\" />\n"
"      <menuitem name=\"SemiEmpiricalMDConfo\" action=\"SemiEmpiricalMDConfo\" />\n"
"    </menu>\n"
"    <separator name=\"sepView\" />\n"
"    <menu name=\"View\" action=\"View\">\n"
"      <menuitem name=\"ShowToolBar\" action=\"ShowToolBar\" />\n"
"      <menuitem name=\"ShowStatusBox\" action=\"ShowStatusBox\" />\n"
"    </menu>\n"
"    <separator name=\"sepClose\" />\n"
"    <menuitem name=\"Close\" action=\"Close\" />\n"
"  </popup>\n"
"  <toolbar action=\"ToolbarGL\">\n"
"      <toolitem name=\"OperationsTranslate\" action=\"OperationsTranslate\" />\n"
"      <toolitem name=\"OperationsRotation\" action=\"OperationsRotation\" />\n"
"      <toolitem name=\"OperationsRotationZ\" action=\"OperationsRotationZ\" />\n"
"      <toolitem name=\"OperationsZoom\" action=\"OperationsZoom\" />\n"
/*
"      <toolitem name=\"OperationsScaleStick\" action=\"OperationsScaleStick\" />\n"
"      <toolitem name=\"OperationsScaleBall\" action=\"OperationsScaleBall\" />\n"
"      <toolitem name=\"OperationsScaleDipole\" action=\"OperationsScaleDipole\" />\n"
*/
"      <separator name=\"sepToolBarSelectionOfAtoms\" />\n"
"      <toolitem name=\"OperationsEditObjects\" action=\"OperationsEditObjects\" />\n"
"      <toolitem name=\"SetAtomToInsert\" action=\"SetAtomToInsert\" />\n"
"      <toolitem name=\"AdjustHydrogens\" action=\"AdjustHydrogens\" />\n"
"      <toolitem name=\"OperationsInsertFrag\" action=\"OperationsInsertFrag\" />\n"
"      <toolitem name=\"OperationsSelectionOfAtoms\" action=\"OperationsSelectionOfAtoms\" />\n"
"      <toolitem name=\"OperationsDeleteObjects\" action=\"OperationsDeleteObjects\" />\n"
"      <toolitem name=\"OperationsMoveAtoms\" action=\"OperationsMoveAtoms\" />\n"
"      <toolitem name=\"OperationsRotationAtoms\" action=\"OperationsRotationAtoms\" />\n"
"      <toolitem name=\"OperationsRotationZAtoms\" action=\"OperationsRotationZAtoms\" />\n"
"      <toolitem name=\"RebuildConnectionsDuringEdition\" action=\"RebuildConnectionsDuringEdition\" />\n"
"      <separator name=\"sepToolBarMesure\" />\n"
"      <separator name=\"sepToolBarMesure1\" />\n"
"      <toolitem name=\"OperationsMesure\" action=\"OperationsMesure\" />\n"
"      <separator name=\"sepToolBarGeometryStick\" />\n"
"      <separator name=\"sepToolBarGeometryStick1\" />\n"
"      <toolitem name=\"RenderGeometryStick\" action=\"RenderGeometryStick\" />\n"
"      <toolitem name=\"RenderGeometryBallAndStick\" action=\"RenderGeometryBallAndStick\" />\n"
"      <separator name=\"sepToolBarShowMesureNoteBook\" />\n"
"      <separator name=\"sepToolBarShowMesureNoteBook1\" />\n"
"      <toolitem name=\"ShowMesureNoteBook\" action=\"ShowMesureNoteBook\" />\n"
"  </toolbar>\n"
;
/*******************************************************************************************************************************/
static void set_init_gtkActionToggleEntries()
{
	gtkActionToggleEntries[0].is_active = distances_draw_mode(); /* LabelsDistances */
	gtkActionToggleEntries[1].is_active = dipole_draw_mode(); /* LabelsDipole */
	gtkActionToggleEntries[2].is_active = pers_mode(); /* RenderPerspective */
	gtkActionToggleEntries[3].is_active = light_mode(); /* RenderLighting */
	gtkActionToggleEntries[4].is_active = cartoon_mode(); /* RenderCartoon */
	gtkActionToggleEntries[5].is_active = shad_mode(); /* RenderShad */
	gtkActionToggleEntries[6].is_active = dipole_mode(); /* RenderShowDipole */
	gtkActionToggleEntries[7].is_active = ShowHBonds; /* RenderShowHydrogenBonds */
	gtkActionToggleEntries[8].is_active = getShowMultipleBonds(); /* RenderShowDoubleTripleBonds */
	gtkActionToggleEntries[9].is_active = TRUE; /* ShowToolBar */
	gtkActionToggleEntries[10].is_active = TRUE; /* ShowStatusBox */
	gtkActionToggleEntries[11].is_active = !MesureIsHide; /* ShowMesureNoteBook */
	gtkActionToggleEntries[12].is_active = getAdjustHydrogensYesNo(); /* Ajust hydrogens */
	gtkActionToggleEntries[13].is_active = getRebuildConnectionsDuringEditionYesNo(); /* rebuild connection */
}
/*******************************************************************************************************************************/
static void add_widget (GtkUIManager *merge, GtkWidget   *widget, GtkContainer *container)
{
	GtkWidget *handlebox;

	if (!GTK_IS_TOOLBAR (widget))  return;

	handlebox =gtk_handle_box_new ();
	g_object_ref (handlebox);
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
		toolBar = toolbar;
		handleBoxToolBar = handlebox;
	}
	gtk_widget_show (widget);
	gtk_container_add (GTK_CONTAINER (handlebox), widget);
	gtk_widget_show (handlebox);
}
/*********************************************************************************************************************/
void activate_rotation()
{
	GtkAction * actionRotation = gtk_ui_manager_get_action(manager, "/MenuGeom/Operations/OperationsRotation");
	if(GTK_IS_TOGGLE_ACTION(actionRotation)) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(actionRotation), TRUE);
}
/*********************************************************************************************************************/
void activate_edit_objects()
{
	GtkAction * actionEdition = gtk_ui_manager_get_action(manager, "/MenuGeom/Operations/OperationsEditObjects");
	if(GTK_IS_TOGGLE_ACTION(actionEdition)) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(actionEdition), TRUE);
}
/*********************************************************************************************************************/
void activate_insert_fragment()
{
	GtkAction * action = gtk_ui_manager_get_action(manager, "/MenuGeom/Operations/OperationsInsertFrag");
	if(GTK_IS_TOGGLE_ACTION(action)) gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action), TRUE);
}
/*******************************************************************************************************************************/
void create_toolbar_and_popup_menu_geom(GtkWidget* box)
{
	GtkActionGroup *actionGroup = NULL;
	GtkUIManager *merge = NULL;
	GError *error = NULL;
	TypeRenderGeom mode = GEOMETRY_STICK;

  	merge = gtk_ui_manager_new ();
  	g_signal_connect_swapped (GeomDlg, "destroy", G_CALLBACK (g_object_unref), merge);

	actionGroup = gtk_action_group_new ("GabeditPopupMenuGeomActions");
	gtk_action_group_add_actions (actionGroup, gtkActionEntries, numberOfGtkActionEntries, NULL);

	set_init_gtkActionToggleEntries();
	gtk_action_group_add_toggle_actions (actionGroup, gtkActionToggleEntries, numberOfGtkActionToggleEntries, NULL);

	if(getOperationType() == ROTATION) 
	gtk_action_group_add_radio_actions (actionGroup, operationsEntries, numberOfOperationsEntries, OPERATION_ROTATION, G_CALLBACK (render_operation_radio_action), NULL);
	else
	gtk_action_group_add_radio_actions (actionGroup, operationsEntries, numberOfOperationsEntries, OPERATION_EDIT_OBJECTS, G_CALLBACK (render_operation_radio_action), NULL);

	initLabelOptions (LABELNO);
	gtk_action_group_add_radio_actions (actionGroup, labelEntries , numberOfLabelEntries, LABEL_NO, G_CALLBACK (render_label_radio_action), NULL);

	if(!StickMode) mode = GEOMETRY_BALLSTICK;
	gtk_action_group_add_radio_actions (actionGroup, rendereGeometryEntries, numberOfRenderGeometryEntries, mode, G_CALLBACK (render_geometry_radio_action), NULL);

  	gtk_ui_manager_insert_action_group (merge, actionGroup, 0);

	g_signal_connect (merge, "add_widget", G_CALLBACK (add_widget), box);
  	gtk_window_add_accel_group (GTK_WINDOW (GeomDlg), gtk_ui_manager_get_accel_group (merge));
	if (!gtk_ui_manager_add_ui_from_string (merge, uiMenuInfo, -1, &error))
	{
		g_message ("building menus failed: %s", error->message);
		g_error_free (error);
	}
	else
	{
		/*
		add_attach_functional_to_menu(merge);
		add_hydrocarbon_to_menu(merge);
		add_rings_to_menu(merge);
		add_drugs_to_menu(merge);
		add_miscellaneous_to_menu(merge);
		add_fullerene_to_menu(merge);
		*/
	}
	manager = merge;
	/*
	addGroupesToMenu();
	addFragmentsToMenu();
	*/
}
/*********************************************************************************************************************/
static void set_sensitive()
{
	GtkWidget *saveAs = gtk_ui_manager_get_widget (manager, "/MenuGeom/SaveAs");
	GtkWidget *deleteMolecule = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditDeleteMolecule");
	GtkWidget *deleteHydrogenAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditDeleteHydrogenAtoms");
	GtkWidget *deleteSelectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditDeleteSelectedAtoms");
	GtkWidget *moveSelectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditMoveCenterOfSelectedAtomsToOrigin");
	GtkWidget *alignSelectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditAlignPrincipalAxesOfSelectedAtomsToXYZ");
	GtkWidget *alignSelectedAndNotSelectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditAlignSelectedAndNotSelectedAtoms");
	GtkWidget *copySelectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditCopySelectedAtoms");
	GtkWidget *resetAllConnections = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditResetAllConnections");
	GtkWidget *resetMultipleConnections = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditResetMultipleConnections");
	GtkWidget *resetSelectedConnections = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditResetConnectionsBetweenSelectedAtoms");
	GtkWidget *resetSelectedAndNotSelectedConnections = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/EditResetConnectionsBetweenSelectedAndNotSelectedAtoms");

	GtkWidget *selectAllAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectAll");
	GtkWidget *invertSelection = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditInvertSelection");
	GtkWidget *unSelectAll = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditUnSelectAll");
	GtkWidget *selectHighAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectHighAtoms");
	GtkWidget *selectMediumAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectMediumAtoms");
	GtkWidget *selectLowAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectLowAtoms");
	GtkWidget *selectFixedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectFixedAtoms");
	GtkWidget *selectVariableAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectVariableAtoms");
	GtkWidget *selectFirstResidue = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectFirstResidue");
	GtkWidget *selectLastResidue = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectLastResidue");
	GtkWidget *selectResidueByName = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectResidueByName");
	GtkWidget *selectAtomsByType = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectAtomsByType");
	GtkWidget *selectAtomsBySymbol = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectAtomsBySymbol");
	GtkWidget *selectAtomsByPositiveCharges = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectAtomsByPositiveCharges");
	GtkWidget *selectAtomsByNegativeCharges = gtk_ui_manager_get_widget (manager, "/MenuGeom/Selection/EditSelectAtomsByNegativeCharges");
	GtkWidget *symmetry = gtk_ui_manager_get_widget (manager, "/MenuGeom/Symmetry");
	GtkWidget *export = gtk_ui_manager_get_widget (manager, "/MenuGeom/Export");
	GtkWidget *mm = gtk_ui_manager_get_widget (manager, "/MenuGeom/MolecularMechanics");
	GtkWidget *sm = gtk_ui_manager_get_widget (manager, "/MenuGeom/SemiEmpirical");
	GtkWidget *origMolecule = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetOriginToCenterOfMolecule");
	GtkWidget *dipoleCharges = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetDipoleFormCharges");
	GtkWidget *charges = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetChargesUsingPDBTemplate");
	GtkWidget *type = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetAtomTypesUsingPDBTemplate");
	GtkWidget *typeCharges = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetAtomTypeAndChargeUsingPDBTemplate");
	GtkWidget *typeCalcul = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetAtomTypeCalcul");
	GtkWidget *chargesZero = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetChargesToZero");

	GtkWidget *origAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetOriginToCenterOfSelectedAtoms");
	GtkWidget *pax = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetXYZToPAX");
	GtkWidget *paz = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetXYZToPAZ");

	GtkWidget *layerHigh = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetSelectedAtomsToHighLayer");
	GtkWidget *layerMedium = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetSelectedAtomsToMediumLayer");
	GtkWidget *layerLow = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetSelectedAtomsToLowLayer");
	GtkWidget *fixedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetSelectedAtomsToFixed");
	GtkWidget *variableAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetSelectedAtomsToVariable");
	GtkWidget *setMMTypeOfselectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetMMTypeOfselectedAtoms");
	GtkWidget *setPDBTypeOfselectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetPDBTypeOfselectedAtoms");
	GtkWidget *setChargeOfselectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/SetChargeOfselectedAtoms");
	GtkWidget *scaleChargeOfselectedAtoms = gtk_ui_manager_get_widget (manager, "/MenuGeom/Set/ScaleChargeOfselectedAtoms");
	GtkWidget *addPersonnalFragment = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/PersonalFragments/PersonalFragmentsAddMolecule");
	GtkWidget *removePersonnalFragment = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/PersonalFragments/PersonalFragmentsRemoveFragment");
	GtkWidget *removeAGroup = gtk_ui_manager_get_widget (manager, "/MenuGeom/Edit/PersonalFragments/PersonalFragmentsDeleteGroup");
	gboolean sensitive = TRUE;

  	if(Natoms<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(saveAs)) gtk_widget_set_sensitive(saveAs, sensitive);
	if(GTK_IS_WIDGET(deleteHydrogenAtoms)) gtk_widget_set_sensitive(deleteHydrogenAtoms, sensitive);
	if(GTK_IS_WIDGET(deleteMolecule)) gtk_widget_set_sensitive(deleteMolecule, sensitive);
	if(GTK_IS_WIDGET(selectAllAtoms)) gtk_widget_set_sensitive(selectAllAtoms, sensitive);
	if(GTK_IS_WIDGET(selectHighAtoms)) gtk_widget_set_sensitive(selectHighAtoms, sensitive);
	if(GTK_IS_WIDGET(selectMediumAtoms)) gtk_widget_set_sensitive(selectMediumAtoms, sensitive);
	if(GTK_IS_WIDGET(selectLowAtoms)) gtk_widget_set_sensitive(selectLowAtoms, sensitive);
	if(GTK_IS_WIDGET(selectFixedAtoms)) gtk_widget_set_sensitive(selectFixedAtoms, sensitive);
	if(GTK_IS_WIDGET(selectVariableAtoms)) gtk_widget_set_sensitive(selectVariableAtoms, sensitive);
	if(GTK_IS_WIDGET(selectFirstResidue)) gtk_widget_set_sensitive(selectFirstResidue, sensitive);
	if(GTK_IS_WIDGET(selectLastResidue)) gtk_widget_set_sensitive(selectLastResidue, sensitive);
	if(GTK_IS_WIDGET(selectResidueByName)) gtk_widget_set_sensitive(selectResidueByName, sensitive);
	if(GTK_IS_WIDGET(selectAtomsByType)) gtk_widget_set_sensitive(selectAtomsByType, sensitive);
	if(GTK_IS_WIDGET(selectAtomsBySymbol)) gtk_widget_set_sensitive(selectAtomsBySymbol, sensitive);
	if(GTK_IS_WIDGET(selectAtomsByPositiveCharges)) gtk_widget_set_sensitive(selectAtomsByPositiveCharges, sensitive);
	if(GTK_IS_WIDGET(selectAtomsByNegativeCharges)) gtk_widget_set_sensitive(selectAtomsByNegativeCharges, sensitive);
	if(GTK_IS_WIDGET(symmetry)) gtk_widget_set_sensitive(symmetry, sensitive);
	if(GTK_IS_WIDGET(export)) gtk_widget_set_sensitive(export, sensitive);
	if(GTK_IS_WIDGET(mm)) gtk_widget_set_sensitive(mm, sensitive);
	if(GTK_IS_WIDGET(sm)) gtk_widget_set_sensitive(sm, sensitive);
	if(GTK_IS_WIDGET(origMolecule)) gtk_widget_set_sensitive(origMolecule, sensitive);
	if(GTK_IS_WIDGET(dipoleCharges)) gtk_widget_set_sensitive(dipoleCharges, sensitive);
	if(GTK_IS_WIDGET(charges)) gtk_widget_set_sensitive(charges, sensitive);
	if(GTK_IS_WIDGET(type)) gtk_widget_set_sensitive(type, sensitive);
	if(GTK_IS_WIDGET(typeCharges)) gtk_widget_set_sensitive(typeCharges, sensitive);
	if(GTK_IS_WIDGET(typeCalcul)) gtk_widget_set_sensitive(typeCalcul, sensitive);
	if(GTK_IS_WIDGET(chargesZero)) gtk_widget_set_sensitive(chargesZero, sensitive);

	if(NFatoms<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(origAtoms)) gtk_widget_set_sensitive(origAtoms, sensitive);
	if(
			getOperationType()!=SELECTFRAG && 
			getOperationType()!=SELECTRESIDUE && 
			getOperationType()!=SELECTOBJECTS
	)sensitive = FALSE;
	if(GTK_IS_WIDGET(deleteSelectedAtoms)) gtk_widget_set_sensitive(deleteSelectedAtoms, sensitive);
	if(GTK_IS_WIDGET(moveSelectedAtoms)) gtk_widget_set_sensitive(moveSelectedAtoms, sensitive);
	if(GTK_IS_WIDGET(alignSelectedAtoms)) gtk_widget_set_sensitive(alignSelectedAtoms, sensitive);
	if(GTK_IS_WIDGET(alignSelectedAndNotSelectedAtoms)) gtk_widget_set_sensitive(alignSelectedAndNotSelectedAtoms, sensitive);
	if(GTK_IS_WIDGET(copySelectedAtoms)) gtk_widget_set_sensitive(copySelectedAtoms, sensitive);
	if(GTK_IS_WIDGET(setMMTypeOfselectedAtoms)) gtk_widget_set_sensitive(setMMTypeOfselectedAtoms, sensitive);
	if(GTK_IS_WIDGET(setPDBTypeOfselectedAtoms)) gtk_widget_set_sensitive(setPDBTypeOfselectedAtoms, sensitive);
	if(GTK_IS_WIDGET(setChargeOfselectedAtoms)) gtk_widget_set_sensitive(setChargeOfselectedAtoms, sensitive);
	if(GTK_IS_WIDGET(scaleChargeOfselectedAtoms)) gtk_widget_set_sensitive(scaleChargeOfselectedAtoms, sensitive);
	if(GTK_IS_WIDGET(resetSelectedConnections)) gtk_widget_set_sensitive(resetSelectedConnections, sensitive);
	if(GTK_IS_WIDGET(resetSelectedAndNotSelectedConnections)) gtk_widget_set_sensitive(resetSelectedAndNotSelectedConnections, sensitive);


	sensitive = TRUE;
  	if(Natoms<2) sensitive = FALSE;
	if(GTK_IS_WIDGET(resetAllConnections)) gtk_widget_set_sensitive(resetAllConnections, sensitive);
	if(GTK_IS_WIDGET(resetMultipleConnections)) gtk_widget_set_sensitive(resetMultipleConnections, sensitive);

	if(NFatoms<2) sensitive = FALSE;
	if(GTK_IS_WIDGET(pax)) gtk_widget_set_sensitive(pax, sensitive);
	if(GTK_IS_WIDGET(paz)) gtk_widget_set_sensitive(paz, sensitive);
	if(GTK_IS_WIDGET(fixedAtoms)) gtk_widget_set_sensitive(fixedAtoms, sensitive);
	if(GTK_IS_WIDGET(variableAtoms)) gtk_widget_set_sensitive(variableAtoms, sensitive);

	sensitive = TRUE;
  	if(Natoms<1) sensitive = FALSE;
	if(NFatoms<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(layerHigh)) gtk_widget_set_sensitive(layerHigh, sensitive);
	if(GTK_IS_WIDGET(invertSelection)) gtk_widget_set_sensitive(invertSelection, sensitive);
	if(GTK_IS_WIDGET(unSelectAll)) gtk_widget_set_sensitive(unSelectAll, sensitive);
  	if(Natoms<2) sensitive = FALSE;
	if(GTK_IS_WIDGET(layerMedium)) gtk_widget_set_sensitive(layerMedium, sensitive);
	if(GTK_IS_WIDGET(layerLow)) gtk_widget_set_sensitive(layerLow, sensitive);

	 sensitive = TRUE;
	if(getNumberOfGroups()<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(addPersonnalFragment)) gtk_widget_set_sensitive(addPersonnalFragment, sensitive);
	if(GTK_IS_WIDGET(removePersonnalFragment)) gtk_widget_set_sensitive(removePersonnalFragment, sensitive);
	if(GTK_IS_WIDGET(removeAGroup)) gtk_widget_set_sensitive(removeAGroup, sensitive);

}
/*********************************************************************************************************************/
gboolean popuo_menu_geom(guint button, guint32 time)
{
	GtkWidget *menu = gtk_ui_manager_get_widget (manager, "/MenuGeom");
	if (GTK_IS_MENU (menu)) 
	{
		set_sensitive();
		gtk_menu_popup (GTK_MENU (menu), NULL, NULL, NULL, NULL, button, time);
		return TRUE;
	}
	else printf("Erreur menu n'est pas un menu\n");
	return FALSE;
}
/*******************************************************************************************************************************/
/*
static void free_id_list(GObject* win, gchar* groupName)
{
	GSList* listOfId = NULL;
	if(!G_IS_OBJECT(manager)) return;
	listOfId = g_object_get_data(G_OBJECT(manager),groupName);
	if(!listOfId) return;
	g_slist_free(listOfId);
}
void add_a_personal_group_to_menu(gchar* groupName)
{
	guint  merge_id;
	GtkActionGroup *dag = NULL;
	GtkActionEntry *actionEntry;
	gchar* name;
	gchar* label;
	gchar* tmp;
	gchar* dagName = g_strdup_printf("PersonalFragmentsActions%s", groupName);
	GSList* listOfId = g_slist_alloc();

	if(!manager) return;
	merge_id = gtk_ui_manager_new_merge_id (GTK_UI_MANAGER (manager));

	dag = gtk_action_group_new (dagName);
	gtk_ui_manager_insert_action_group (manager, dag, 0);
  	g_signal_connect_swapped (GeomDlg, "destroy", G_CALLBACK (g_object_unref), dag);
  	g_signal_connect(GeomDlg, "destroy", G_CALLBACK (free_id_list), groupName);

	name = g_strdup_printf("%s", groupName);
	label = g_strdup_printf ("%s", groupName);

	actionEntry = g_malloc(sizeof(GtkActionEntry));
	actionEntry->name = name;
	actionEntry->stock_id = NULL;
	actionEntry->label = label;
	actionEntry->accelerator = NULL;
	actionEntry->tooltip = NULL;
	actionEntry->callback = NULL;
        gtk_action_group_add_actions (dag, actionEntry, 1, NULL);

	tmp = g_strdup_printf("/MenuGeom/Edit/PersonalFragments");
	gtk_ui_manager_add_ui(GTK_UI_MANAGER (manager), merge_id, tmp, groupName, groupName, GTK_UI_MANAGER_MENU, FALSE);
	g_free(tmp);

	listOfId = g_slist_prepend(listOfId, GUINT_TO_POINTER(merge_id));
	g_object_set_data(G_OBJECT(manager),groupName,listOfId);
	g_object_set_data(G_OBJECT(manager),dagName,dag);

	g_free(dagName);

	gtk_ui_manager_ensure_update (manager);
}
void delete_a_personal_group_from_menu(gchar* groupName)
{
	GSList* listOfId = NULL;
	gchar* dagName = NULL;
	GtkActionGroup *dag = NULL;
	guint merge_id;
	GSList*  list = NULL;

	if(!manager) return;

	listOfId = g_object_get_data(G_OBJECT(manager),groupName);
	if(!listOfId) return;

	dagName = g_strdup_printf("PersonalFragmentsActions%s", groupName);
	dag = g_object_get_data(G_OBJECT(manager), dagName);
	g_free(dagName);

	list =   listOfId;
	while(list != NULL)
	{
		merge_id = GPOINTER_TO_INT(list->data);
		if(merge_id != 0) gtk_ui_manager_remove_ui(GTK_UI_MANAGER (manager), merge_id);
		list = list->next;
	}
	if(dag)
	{
		gtk_ui_manager_remove_action_group (GTK_UI_MANAGER (manager), dag);
	}
	gtk_ui_manager_ensure_update (manager);
}
static void activate_add_personal_fragment (GtkAction *action, gpointer data)
{
	gchar* nameFrag = NULL;

	if(data) nameFrag = (gchar*) data;
	if(nameFrag)
	{
		addPersonalFragment(nameFrag, 0, NULL);
	}

}
void add_a_personnal_fragement_to_menu(gchar* groupName,gchar* fragName)
{
	const gchar* menuBase = "Edit/PersonalFragments";
	guint  merge_id;
	static GtkActionGroup *dag = NULL;
	GtkActionEntry *actionEntry;
	GtkAction *action;
	gchar* name;
	gchar* label;
	gchar* data;
	GList*  listOfActions = NULL;
	GList*  list = NULL;
	gint i;
	gchar* tmp;
	GSList* listOfId = NULL;

	if(!manager) return;
	merge_id = gtk_ui_manager_new_merge_id (GTK_UI_MANAGER (manager));

	if(!dag)
	{
		dag = gtk_action_group_new ("FragmentsActions");
		gtk_ui_manager_insert_action_group (manager, dag, 0);
  		g_signal_connect (GeomDlg, "destroy", G_CALLBACK (delete_dag), &dag);
	}
	listOfActions =   gtk_action_group_list_actions(dag);
	i = 0;
	list = listOfActions;
	tmp = g_strdup_printf("%s%s", groupName, fragName);
	while(list != NULL)
	{
		G_CONST_RETURN gchar* nameAction;
		action = (GtkAction *)(list->data);
		if(!GTK_IS_ACTION(action)) break;
		nameAction = gtk_action_get_name(GTK_ACTION(action));
		if(strstr(nameAction,tmp)) i++;
		list = list->next;
	}
	g_free(tmp);
	if(i==0)
	{
		name = g_strdup_printf("%s%s", groupName, fragName);
		label = g_strdup_printf ("%s", fragName);
		data = g_strdup_printf("%s/%s", groupName, fragName);
	}
	else
	{
		name = g_strdup_printf("%s%s%d", groupName, fragName,i);
		label = g_strdup_printf ("%s%d", fragName,i);
		data = g_strdup_printf("%s/%s%d", groupName, fragName,i);
	}
	actionEntry = g_malloc(sizeof(GtkActionEntry));
	actionEntry->name = name;
	actionEntry->stock_id = NULL;
	actionEntry->label = label;
	actionEntry->accelerator = NULL;
	actionEntry->tooltip = NULL;
	actionEntry->callback = G_CALLBACK(activate_add_personal_fragment);
        gtk_action_group_add_actions (dag, actionEntry, 1, data);


	tmp = g_strdup_printf("/MenuGeom/%s/%s", menuBase, groupName);
	gtk_ui_manager_add_ui(GTK_UI_MANAGER (manager), merge_id, tmp, name, name, GTK_UI_MANAGER_MENUITEM, TRUE);
	g_free(tmp);

	listOfId = g_object_get_data(G_OBJECT(manager),groupName);
	if(listOfId)
	{
		listOfId = g_slist_prepend(listOfId, GUINT_TO_POINTER(merge_id));
		g_object_set_data(G_OBJECT(manager),groupName,listOfId);
	}
	g_object_set_data(G_OBJECT(manager),name,GUINT_TO_POINTER(merge_id));

	gtk_ui_manager_ensure_update (manager);

}
void delete_a_personal_fragment_from_menu(gchar* groupName,gchar* fragName)
{
	GSList* listOfId = NULL;
	guint merge_id;
	GSList*  list = NULL;
	gpointer id;
	guint myId;
	gchar* name = NULL;

	if(!manager) return;

	name = g_strdup_printf("%s%s", groupName, fragName);
	id = g_object_get_data(G_OBJECT(manager),name);
	g_free(name);
	if(!id) return;

	myId = GPOINTER_TO_INT(id);
	if(myId == 0) return;

	listOfId = g_object_get_data(G_OBJECT(manager),groupName);
	if(!listOfId) return;

	list =   listOfId;
	while(list != NULL)
	{
		merge_id = GPOINTER_TO_INT(list->data);
		if(merge_id != 0 && merge_id == myId ) list->data = 0;
		list = list->next;
	}
	gtk_ui_manager_remove_ui(GTK_UI_MANAGER (manager), myId);
	gtk_ui_manager_ensure_update (manager);
}
*/
