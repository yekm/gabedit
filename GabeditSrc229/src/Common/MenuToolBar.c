/* MenuToolBar.c */
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
#include "../Common/Global.h"
#include "../Utils/Utils.h"
#include "../Utils/UtilsInterface.h"
#include "../Common/Run.h"
#include "../Geometry/InterfaceGeom.h"
#include "../Files/FileChooser.h"
#include "../Common/TextEdit.h"
#include "../Common/Preferences.h"
#include "../Molcas/Molcas.h"
#include "../Molcas/MolcasBasisLibrary.h"
#include "../MPQC/MPQCBasisLibrary.h"
#include "../Molpro/Molpro.h"
#include "../Molpro/MolproBasisLibrary.h"
#include "../Gaussian/Gaussian.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/GabeditTextEdit.h"
#include "../Utils/ConvUtils.h"
#include "../Geometry/Fragments.h"
#include "../Geometry/DrawGeom.h"
#include "../Geometry/GeomGlobal.h"
#include "../Geometry/OpenBabel.h"
#include "../Common/Printer.h"
#include "../NetWork/Process.h"
#include "../NetWork/Batch.h"
#include "../MolecularMechanics/SetMMParameters.h"
#include "../MolecularMechanics/SetPDBTemplate.h"
#include "../Common/StockIcons.h"
#include "../OpenGL/Vibration.h"
#include "../Utils/GabeditXYPlot.h"
#include "../Spectrum/IRSpectrum.h"
#include "../Spectrum/RamanSpectrum.h"
#include "../Spectrum/UVSpectrum.h"
#include "../Spectrum/ECDSpectrum.h"
#include "../Spectrum/NMRSpectrum.h"
#include "../VibrationalCorrections/GabeditGaussianInput.h"
#include "../IsotopeDistribution/IsotopeDistributionCalculatorDlg.h"

/*********************************************************************************************************************/
static gboolean ViewWindows = FALSE;
static gboolean ViewList = TRUE;
static GtkToolbar* toolBar = NULL;
static GtkWidget* handleBoxToolBar = NULL;
static gboolean ViewToolBar = TRUE;
static	GtkUIManager *manager = NULL;
/*********************************************************************************************************************/
static void view_icons()
{
	static gboolean mini=TRUE;
	mini = !mini;
	if(mini)
	gtk_rc_parse_string("gtk-toolbar-icon-size = small-toolbar");
	else
	gtk_rc_parse_string("gtk-toolbar-icon-size = large-toolbar");
}
/*********************************************************************************************************************/
static void view_windows_frame ()
{
	 if(!FrameWins) return;
	if(ViewWindows) gtk_widget_hide (GTK_WIDGET(FrameWins));
	else gtk_widget_show (GTK_WIDGET(FrameWins));
	ViewWindows = !ViewWindows;
}
/*********************************************************************************************************************/
static void view_projects_list ()
{
	if(!FrameList) return;
	if(ViewList)
	{
 		gtk_widget_hide (GTK_WIDGET(FrameList));
		gtk_widget_set_size_request(GTK_WIDGET(FrameList),1,-1);
 		gtk_widget_hide (GTK_WIDGET(Hpaned));
  		GTK_PANED(Hpaned)->child1_size = 1;    
 		gtk_widget_show (GTK_WIDGET(Hpaned));
	}
	else
 	{
  		GTK_PANED(Hpaned)->child1_size = (gint)(ScreenHeight*0.15);    
		gtk_widget_set_size_request(GTK_WIDGET(FrameList),(gint)(ScreenHeight*0.15),-1);
 		gtk_widget_hide (GTK_WIDGET(Hpaned));
  		gtk_widget_show (GTK_WIDGET(FrameList));
 		gtk_widget_show (GTK_WIDGET(Hpaned));
	}
	ViewList = !ViewList;
}
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
static void cut_text()
{
	if(gtk_notebook_get_current_page(GTK_NOTEBOOK(NoteBookText))==0)
		gabedit_text_cut_clipboard(text); 
	else
		gabedit_text_cut_clipboard(textresult); 
}
/********************************************************************************/
static void copy_text()
{
	if(gtk_notebook_get_current_page(GTK_NOTEBOOK(NoteBookText))==0)
		gabedit_text_copy_clipboard(text); 
	else
		gabedit_text_copy_clipboard(textresult); 
}
/********************************************************************************/
static void paste_text()
{
	if(gtk_notebook_get_current_page(GTK_NOTEBOOK(NoteBookText))==0)
		gabedit_text_paste_clipboard(text); 
	else
		gabedit_text_paste_clipboard(textresult); 
}
/*********************************************************************************************************************/
static void activate_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	/* const gchar *typename = G_OBJECT_TYPE_NAME (action);*/

	if(!strcmp(name,"GamessInput")) new_gamess(NULL, NULL);
	else if(!strcmp(name,"GaussianInput")) new_gauss(NULL, NULL);
	else if(!strcmp(name,"MolcasInput")) new_molcas(NULL, NULL);
	else if(!strcmp(name,"MolproInput")) new_molpro(NULL, NULL);
	else if(!strcmp(name,"MopacInput")) new_mopac(NULL, NULL);
	else if(!strcmp(name,"MPQCInput")) new_mpqc(NULL, NULL);
	else if(!strcmp(name,"OrcaInput")) new_orca(NULL, NULL);
	else if(!strcmp(name,"PCGamessInput")) new_pcgamess(NULL, NULL);
	else if(!strcmp(name,"QChemInput")) new_qchem(NULL, NULL);
	else if(!strcmp(name,"OtherInput")) new_other(NULL, NULL);
	else if(!strcmp(name,"Open")) open_file(NULL, NULL);
	else if(!strcmp(name,"Include")) inserrer_doc();
	else if(!strcmp(name,"SaveAs")) save_as_doc();
	else if(!strcmp(name,"Save")) save_doc();
	else if(!strcmp(name,"Print")) create_print_page();
	else if(!strcmp(name,"Exit")) 
	{
		if(imodif == DATA_MOD_NO ) exit_all(NULL,NULL);
		else Save_YesNo();
	}
	else if(!strcmp(name,"Cut"))  cut_text();
	else if(!strcmp(name,"Copy"))  copy_text();
	else if(!strcmp(name,"Paste")) paste_text();
	else if(!strcmp(name,"Find")) find_text_win();
	else if(!strcmp(name,"SelectAll")) select_all();
	else if(!strcmp(name,"InsertGaussianGeometry")) { iprogram = PROG_IS_GAUSS; insert_gaussian(2); }
	else if(!strcmp(name,"InsertGaussianMultiStep")) { iprogram = PROG_IS_GAUSS; insert_doc_gauss();}
	else if(!strcmp(name,"InsertMolcasAddToFile")) { iprogram = PROG_IS_MOLCAS; insertMolcas();}
	else if(!strcmp(name,"InsertMolproGeneral")) {iprogram = PROG_IS_MOLPRO; insert_molpro(1);  }
	else if(!strcmp(name,"InsertMolproGeometry")) {iprogram = PROG_IS_MOLPRO; insert_molpro(2);  }
	else if(!strcmp(name,"InsertMolproBasis")) { iprogram = PROG_IS_MOLPRO; insert_molpro(3);}
	else if(!strcmp(name,"InsertMolproCommands")) { iprogram = PROG_IS_MOLPRO; insert_molpro(4);}
	else if(!strcmp(name,"GeometryMolpro")) {iprogram = PROG_IS_MOLPRO; insert_molpro(2); }
	else if(!strcmp(name,"GeometryGaussian")) {iprogram = PROG_IS_GAUSS; insert_gaussian(2); }
	else if(!strcmp(name,"GeometryEdit")) {edit_geometry();}
	else if(!strcmp(name,"GeometryDraw"))
	{
		if(ZoneDessin==NULL) create_window_drawing();
		else rafresh_drawing();
	}
	else if(!strcmp(name,"DisplayDensity")) { draw_density_orbitals_gamess_or_gauss_or_molcas_or_molpro(NULL,NULL); }
	else if(!strcmp(name,"ToolsUnitConversion")) {create_conversion_dlg();}
	else if(!strcmp(name,"ToolsProcessLocalAll")) {run_process_all(FALSE);}
	else if(!strcmp(name,"ToolsProcessLocalUser")) {run_process_user(FALSE,NULL,NULL,NULL);}
	else if(!strcmp(name,"ToolsProcessRemoteAll")) {create_process_remote(TRUE);}
	else if(!strcmp(name,"ToolsProcessRemoteUser")) {create_process_remote(FALSE);}
	else if(!strcmp(name,"ToolsBatchLocalAll")) {run_batch_all(FALSE);}
	else if(!strcmp(name,"ToolsBatchLocalUser")) {run_batch_user(FALSE,NULL,NULL,NULL);}
	else if(!strcmp(name,"ToolsBatchRemoteAll")) {create_batch_remote(TRUE);}
	else if(!strcmp(name,"ToolsBatchRemoteUser")) {create_batch_remote(FALSE);}
	else if(!strcmp(name,"ToolsOpenBabel")) {create_babel_dialogue();}
	else if(!strcmp(name,"ToolsXYPlot")) { gabedit_xyplot_new_window(NULL,Fenetre);}
	else if(!strcmp(name,"ToolsIRSpectrumGabedit")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_GABEDIT);}
	else if(!strcmp(name,"ToolsIRSpectrumDalton")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_DALTON);}
	else if(!strcmp(name,"ToolsIRSpectrumGamess")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_GAMESS);}
	else if(!strcmp(name,"ToolsIRSpectrumOrca")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_ORCA);}
	else if(!strcmp(name,"ToolsIRSpectrumPCGamess")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_PCGAMESS);}
	else if(!strcmp(name,"ToolsIRSpectrumGaussian")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_GAUSSIAN);}
	else if(!strcmp(name,"ToolsIRSpectrumMolpro")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_MOLPRO);}
	else if(!strcmp(name,"ToolsIRSpectrumQChem")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_QCHEM);}
	else if(!strcmp(name,"ToolsIRSpectrumAdf")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_ADF);}
	else if(!strcmp(name,"ToolsIRSpectrumMolden")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_MOLDEN);}
	else if(!strcmp(name,"ToolsIRSpectrumTxt")) { createIRSpectrum(Fenetre,GABEDIT_TYPEFILE_TXT);}
	else if(!strcmp(name,"ToolsRamanSpectrumGabedit")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_GABEDIT);}
	else if(!strcmp(name,"ToolsRamanSpectrumGamess")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_GAMESS);}
	else if(!strcmp(name,"ToolsRamanSpectrumGaussian")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_GAUSSIAN);}
	else if(!strcmp(name,"ToolsRamanSpectrumOrca")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_ORCA);}
	else if(!strcmp(name,"ToolsRamanSpectrumPCGamess")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_GAMESS);}
	else if(!strcmp(name,"ToolsRamanSpectrumMolden")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_MOLDEN);}
	else if(!strcmp(name,"ToolsRamanSpectrumTxt")) { createRamanSpectrum(Fenetre,GABEDIT_TYPEFILE_TXT);}
	else if(!strcmp(name,"ToolsUVSpectrumGabedit")) { createUVSpectrum(Fenetre,GABEDIT_TYPEFILE_GABEDIT);}
	else if(!strcmp(name,"ToolsUVSpectrumGaussian")) { createUVSpectrum(Fenetre,GABEDIT_TYPEFILE_GAUSSIAN);}
	else if(!strcmp(name,"ToolsUVSpectrumPCGamess")) { createUVSpectrum(Fenetre,GABEDIT_TYPEFILE_PCGAMESS);}
	else if(!strcmp(name,"ToolsUVSpectrumOrca")) { createUVSpectrum(Fenetre,GABEDIT_TYPEFILE_ORCA);}
	else if(!strcmp(name,"ToolsUVSpectrumQChem")) { createUVSpectrum(Fenetre,GABEDIT_TYPEFILE_QCHEM);}
	else if(!strcmp(name,"ToolsUVSpectrumTxt")) { createUVSpectrum(Fenetre,GABEDIT_TYPEFILE_TXT);}

	else if(!strcmp(name,"ToolsECDSpectrumGabedit")) { createECDSpectrum(Fenetre,GABEDIT_TYPEFILE_GABEDIT);}
	else if(!strcmp(name,"ToolsECDSpectrumGaussian")) { createECDSpectrum(Fenetre,GABEDIT_TYPEFILE_GAUSSIAN);}
	else if(!strcmp(name,"ToolsECDSpectrumOrca")) { createECDSpectrum(Fenetre,GABEDIT_TYPEFILE_ORCA);}
	else if(!strcmp(name,"ToolsECDSpectrumTxt")) { createECDSpectrum(Fenetre,GABEDIT_TYPEFILE_TXT);}

	else if(!strcmp(name,"ToolsNMRSpectrumTxt")) { createNMRSpectrum(Fenetre,GABEDIT_TYPEFILE_TXT);}
	else if(!strcmp(name,"ToolsNMR2SpectrumTxt")) { createNMR2Spectrum(Fenetre,GABEDIT_TYPEFILE_TXT);}

	else if(!strcmp(name,"ToolsVibCorrectionsGaussian")) {read_vibcorrection_gaussian_file_dlg(); }
	else if(!strcmp(name,"ToolsIsotopeDistribution")) { compute_distribution_dlg(Fenetre, NULL); }

	else if(!strcmp(name,"RunAbinitio")) {create_run();}
	else if(!strcmp(name,"RunViewResult")) {view_result();}
	else if(!strcmp(name,"SettingsMolecularMechanicsParameters")) {setMMParamatersDlg();}
	else if(!strcmp(name,"SettingsPDBTemplate")) {setPDBTemplateDlg();}
	else if(!strcmp(name,"SettingsBasisMolcas")) {setMolcasBasisDlg();}
	else if(!strcmp(name,"SettingsBasisMolpro")) {setMolproBasisDlg();}
	else if(!strcmp(name,"SettingsBasisMPQC")) {setMPQCBasisDlg();}
	else if(!strcmp(name,"SettingsPreferences")) {create_preferences();}
	else if(!strcmp(name,"HelpAbout")) {show_about();}
	else if(!strcmp(name,"HelpVersion")) {show_version();}
}
/*********************************************************************************************************************/
static GtkActionEntry gtkActionEntries[] =
{
	{"File",     NULL, "_File"},
	{"FileNew",  GTK_STOCK_NEW, "_New"},
	{"GamessInput", GABEDIT_STOCK_GAMESS, "_Gamess input", NULL, "New Gamess input file", G_CALLBACK (activate_action) },
	{"GaussianInput", GABEDIT_STOCK_GAUSSIAN, "_Gaussian input", NULL, "New Gaussian input file", G_CALLBACK (activate_action) },
	{"MolcasInput", GABEDIT_STOCK_MOLCAS, "Mol_cas input", NULL, "New Molcas input file", G_CALLBACK (activate_action) },
	{"MolproInput", GABEDIT_STOCK_MOLPRO, "Mol_pro input", NULL, "New Molpro input file", G_CALLBACK (activate_action) },
	{"MopacInput", GABEDIT_STOCK_MOPAC, "_Mopac input", NULL, "New Mopac input file", G_CALLBACK (activate_action) },
	{"MPQCInput", GABEDIT_STOCK_MPQC, "MP_QC input", NULL, "New MPQC input file", G_CALLBACK (activate_action) },
	{"OrcaInput", GABEDIT_STOCK_ORCA, "_Orca input", NULL, "New Orca input file", G_CALLBACK (activate_action) },
	{"PCGamessInput", GABEDIT_STOCK_PCGAMESS, "_PCGamess input", NULL, "New PCGamess input file", G_CALLBACK (activate_action) },
	{"QChemInput", GABEDIT_STOCK_QCHEM, "Q-_Chem input", NULL, "New Q-Chem input file", G_CALLBACK (activate_action) },
	{"OtherInput", NULL, "_Other", NULL, "New file", G_CALLBACK (activate_action) },
	{"Open", GTK_STOCK_OPEN, "_Open", "<control>O", "open a file", G_CALLBACK (activate_action) },
	{"Save", GTK_STOCK_SAVE, "_Save", "<control>S", "Save", G_CALLBACK (activate_action) },
	{"SaveAs", GTK_STOCK_SAVE_AS, "Save _as", "<control>s", "Save as", G_CALLBACK (activate_action) },
	{"Include", GABEDIT_STOCK_INSERT, "_Include", "<control>I", "Include a file", G_CALLBACK (activate_action) },
	{"Print", GTK_STOCK_PRINT, "_Print", "<control>P", "Print", G_CALLBACK (activate_action) },
	{"Exit", GTK_STOCK_QUIT, "E_xit", "<control>Q", "Exit", G_CALLBACK (activate_action) },
	{"Edit",  NULL, "_Edit"},
	{"Cut", GTK_STOCK_CUT, "C_ut", "<control>X", "Cut the selected text to the clipboard", G_CALLBACK (activate_action) },
	{"Copy", GTK_STOCK_COPY, "_Copy", "<control>C", "Copy the selected text to the clipboard", G_CALLBACK (activate_action) },
	{"Paste", GTK_STOCK_PASTE, "_Paste", "<control>V", "Paste the text from the clipboard", G_CALLBACK (activate_action) },
	{"Find", GTK_STOCK_FIND, "_Find", "<control>F", "Find a string", G_CALLBACK (activate_action) },
	{"SelectAll",  GABEDIT_STOCK_SELECT_ALL, "Select _all", "<control>A", "Select All", G_CALLBACK (activate_action) },

	{"Insert",  NULL, "_Insert"},
	{"InsertGaussian",  GABEDIT_STOCK_GAUSSIAN, "_Gaussian"},
	{"InsertMolcas",  GABEDIT_STOCK_MOLCAS, "Mol_cas"},
	{"InsertMolpro",  GABEDIT_STOCK_MOLPRO, "Mol_pro"},
	{"InsertGaussianMultiStep", NULL, "_Add Input File(Multi-Step Job)", NULL, "Add Input File(Multi-Step Job)", G_CALLBACK (activate_action) },
	{"InsertGaussianGeometry", NULL, "G_eometry", NULL, "Insert Gaussian geometry", G_CALLBACK (activate_action) },
	{"InsertMolproGeneral", NULL, "_General", NULL, "Insert Molpro general", G_CALLBACK (activate_action) },
	{"InsertMolproGeometry", NULL, "G_eometry", NULL, "Insert Molpro geometry", G_CALLBACK (activate_action) },
	{"InsertMolproBasis", NULL, "_Basis", NULL, "Insert Molpro basis", G_CALLBACK (activate_action) },
	{"InsertMolproCommands", NULL, "_Commands", NULL, "Insert Molpro commands", G_CALLBACK (activate_action) },
	{"InsertMolcasAddToFile", NULL, "_Add to file", NULL, "Insert Molcas add to file", G_CALLBACK (activate_action) },

	{"View",  NULL, "_View"},

	{"Geometry",  NULL, "_Geometry"},
	{"GeometryMolpro", GABEDIT_STOCK_MOLPRO, "Mol_pro", NULL, "Edit Molpro geometry", G_CALLBACK (activate_action) },
	{"GeometryGaussian", GABEDIT_STOCK_GAUSSIAN, "_Gaussian", NULL, "Edit Gaussian geometry", G_CALLBACK (activate_action) },
	{"GeometryEdit", NULL, "_Edit", NULL, "Edit geometry", G_CALLBACK (activate_action) },
	{"GeometryDraw", GABEDIT_STOCK_GEOMETRY, "_Draw", NULL, "Draw geometry", G_CALLBACK (activate_action) },

	{"DisplayDensity", GABEDIT_STOCK_ORBITALS, "_Display", NULL, "Display Geometry/Orbitals/Density/Vibration", G_CALLBACK (activate_action) },

	{"Tools",  NULL, "_Tools"},
	{"ToolsProcess",  NULL, "_Process"},
	{"ToolsProcessLocal",  NULL, "_Local"},
	{"ToolsUnitConversion", GABEDIT_STOCK_CONVERT_UNIT, "Unit _conversion utility", NULL, "Unit conversion utility", G_CALLBACK (activate_action) },
	{"ToolsProcessLocalAll", NULL, "_All local process", NULL, "All local process", G_CALLBACK (activate_action) },
	{"ToolsProcessLocalUser", NULL, "_User local process", NULL, "User local process", G_CALLBACK (activate_action) },
	{"ToolsProcessRemote",  NULL, "_Remote"},
	{"ToolsProcessRemoteAll", NULL, "_All remote process", NULL, "All remote process", G_CALLBACK (activate_action) },
	{"ToolsProcessRemoteUser", NULL, "_User remote process", NULL, "User remote process", G_CALLBACK (activate_action) },
	{"ToolsBatch",  NULL, "_Batch"},
	{"ToolsBatchLocal",  NULL, "_Local"},
	{"ToolsBatchLocalAll", NULL, "_All local batch jobs", NULL, "All local batch jobs", G_CALLBACK (activate_action) },
	{"ToolsBatchLocalUser", NULL, "_User local batch jobs", NULL, "User local batch jobs", G_CALLBACK (activate_action) },
	{"ToolsBatchRemote",  NULL, "_Remote"},
	{"ToolsBatchRemoteAll", NULL, "_All remote batch jobs", NULL, "All remote batch jobs", G_CALLBACK (activate_action) },
	{"ToolsBatchRemoteUser", NULL, "_User remote batch jobs", NULL, "User remote batch jobs", G_CALLBACK (activate_action) },
	{"ToolsOpenBabel",  GABEDIT_STOCK_OPEN_BABEL, "Open B_abel", NULL, "Open babel", G_CALLBACK (activate_action) },
	{"ToolsXYPlot",  GABEDIT_STOCK_GABEDIT, "XY plotter", NULL, "XYPlotter", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrum",  NULL, "_IR spectrum"},

	{"ToolsIRSpectrumGabedit",  GABEDIT_STOCK_GABEDIT, "Read frequencies and intensities from a _Gabedit file", NULL, "Gabedit", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumDalton",  GABEDIT_STOCK_DALTON, "Read frequencies and intensities from a _Dalton output file", NULL, "Dalton", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumGamess",  GABEDIT_STOCK_GAMESS, "Read frequencies and intensities from a _Gamess output file", NULL, "Gamess", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumGaussian",  GABEDIT_STOCK_GAUSSIAN, "Read frequencies and intensities from a _Gaussian output file", NULL, "Gaussian", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumMolpro",  GABEDIT_STOCK_MOLPRO, "Read frequencies and intensities from a _Molpro output file", NULL, "Molpro", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumOrca",  GABEDIT_STOCK_ORCA, "Read frequencies and intensities from a _Orca output file", NULL, "Orca", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumPCGamess",  GABEDIT_STOCK_PCGAMESS, "Read frequencies and intensities from a _PCGamess output file", NULL, "PCGamess", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumQChem",  GABEDIT_STOCK_QCHEM, "Read frequencies and intensities from a _Q-Chem output file", NULL, "QChem", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumAdf",  GABEDIT_STOCK_ADF, "Read frequencies and intensities from a _ADF output file", NULL, "ADF", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumMolden",  GABEDIT_STOCK_MOLDEN, "Read frequencies and intensities from a Mo_lden file", NULL, "Molden", G_CALLBACK (activate_action) },
	{"ToolsIRSpectrumTxt",  NULL, "Read frequencies and intensities from an ASCII XY file(2 columns)", NULL, "Txt", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrum",  NULL, "_Raman spectrum"},

	{"ToolsRamanSpectrumGabedit",  GABEDIT_STOCK_GABEDIT, "Read frequencies and intensities from a _Gabedit file", NULL, "Gabedit", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrumGamess",  GABEDIT_STOCK_GAMESS, "Read frequencies and intensities from a Game_ss output file", NULL, "Gamess", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrumGaussian",  GABEDIT_STOCK_GAUSSIAN, "Read frequencies and intensities from a _Gaussian output file", NULL, "Gaussian", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrumOrca",  GABEDIT_STOCK_ORCA, "Read frequencies and intensities from a _Orca output file", NULL, "Orca", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrumPCGamess",  GABEDIT_STOCK_PCGAMESS, "Read frequencies and intensities from a _PCGamess output file", NULL, "PCGamess", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrumMolden",  GABEDIT_STOCK_MOLDEN, "Read frequencies and intensities from a Mo_lden file", NULL, "Molden", G_CALLBACK (activate_action) },
	{"ToolsRamanSpectrumTxt",  NULL, "Read frequencies and intensities from an ASCII XY file(2 columns)", NULL, "Txt", G_CALLBACK (activate_action) },
	{"ToolsUVSpectrum",  NULL, "_UV spectrum"},
	{"ToolsUVSpectrumGabedit",  GABEDIT_STOCK_GABEDIT, "Read energies and intensities from a _Gabedit file", NULL, "Gabedit", G_CALLBACK (activate_action) },
	{"ToolsUVSpectrumGaussian",  GABEDIT_STOCK_GAUSSIAN, "Read energies and intensities from a _Gaussian output file", NULL, "Gaussian", G_CALLBACK (activate_action) },
	{"ToolsUVSpectrumPCGamess",  GABEDIT_STOCK_PCGAMESS, "Read energies and intensities from a _PCGamess output file", NULL, "PCGamess", G_CALLBACK (activate_action) },
	{"ToolsUVSpectrumOrca",  GABEDIT_STOCK_ORCA, "Read energies and intensities from a Orca output file", NULL, "Orca", G_CALLBACK (activate_action) },
	{"ToolsUVSpectrumQChem",  GABEDIT_STOCK_QCHEM, "Read energies and intensities from a Q_Chem output file", NULL, "QChem", G_CALLBACK (activate_action) },
	{"ToolsUVSpectrumTxt",  NULL, "Read energies and intensities from an ASCII XY file(2 columns)", NULL, "Txt", G_CALLBACK (activate_action) },

	{"ToolsECDSpectrum",  NULL, "_ECD spectrum"},
	{"ToolsECDSpectrumGabedit",  GABEDIT_STOCK_GABEDIT, "Read energies and intensities from a _Gabedit file", NULL, "Gabedit", G_CALLBACK (activate_action) },
	{"ToolsECDSpectrumGaussian",  GABEDIT_STOCK_GAUSSIAN, "Read energies and intensities from a _Gaussian output file", NULL, "Gaussian", G_CALLBACK (activate_action) },
	{"ToolsECDSpectrumOrca",  GABEDIT_STOCK_ORCA, "Read energies and intensities from a _Orca output file", NULL, "Orca", G_CALLBACK (activate_action) },
	{"ToolsECDSpectrumTxt",  NULL, "Read energies and intensities from an ASCII XY file(2 columns)", NULL, "Txt", G_CALLBACK (activate_action) },

	{"ToolsNMRSpectrum",  NULL, "_NMR spectrum"},
	{"ToolsNMRSpectrumTxt",  NULL, "NMR Spin-Spin Splitting Simulation", NULL, "Txt", G_CALLBACK (activate_action) },
	{"ToolsNMR2SpectrumTxt",  NULL, "Read NMR frequencies and intensities from an ASCII XY file(2 columns)", NULL, "Txt", G_CALLBACK (activate_action) },

	{"ToolsVibCorrections",  NULL, "Ro_vibrational corrections"},
	{"ToolsVibCorrectionsGaussian",  NULL, "Read Gaussian output file for compute the ro-vibrational corrections", NULL, "Gaussian", G_CALLBACK (activate_action) },
	{"ToolsIsotopeDistribution",  NULL, "Compute the isotope distribution for a molecule", NULL, "Isotope distribution", G_CALLBACK (activate_action) },

	{"Run",  NULL, "_Run"},
	{"RunAbinitio", GTK_STOCK_EXECUTE, "_Run a abtinio program",  "<control>R", "Run a abtinio program", G_CALLBACK (activate_action) },
	{"RunViewResult", NULL, "_View result of calculation", NULL, "View result of calculation", G_CALLBACK (activate_action) },

	{"Settings",  NULL, "_Settings"},
	{"SettingsMolecularMechanicsParameters", NULL, "_Molecular Mechanics Parameters", NULL, "Set Molecular Mechanics Parameters", G_CALLBACK (activate_action) },
	{"SettingsPDBTemplate", NULL, "_PDB Template", NULL, "Set PDB Template", G_CALLBACK (activate_action) },
	{"SettingsBasis",  NULL, "_Basis"},
	{"SettingsBasisMolcas", GABEDIT_STOCK_MOLCAS, "Mol_cas", NULL, "Set molcas basis list", G_CALLBACK (activate_action) },
	{"SettingsBasisMolpro", GABEDIT_STOCK_MOLPRO, "Mol_pro", NULL, "Set molpro basis list", G_CALLBACK (activate_action) },
	{"SettingsBasisMPQC", GABEDIT_STOCK_MPQC, "MP_QC", NULL, "Set MPQC basis list", G_CALLBACK (activate_action) },
	{"SettingsPreferences", GTK_STOCK_PREFERENCES, "P_references", NULL, "Set preference parameters", G_CALLBACK (activate_action) },

	{"Window",  NULL, "_Window", NULL, NULL, G_CALLBACK (activate_action)},

	{"Help",  NULL, "_Help"},
	{"HelpAbout", GTK_STOCK_ABOUT, "_About...", NULL, "About...", G_CALLBACK (activate_action) },
	{"HelpVersion", NULL, "_Version...", NULL, "Version...", G_CALLBACK (activate_action) },
};
static guint numberOfGtkActionEntries = G_N_ELEMENTS (gtkActionEntries);
/*********************************************************************************************************************/
static void toggle_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	/* const gchar *typename = G_OBJECT_TYPE_NAME (action);*/

	if(!strcmp(name,"ViewWindowsFrame")) { view_windows_frame(); }
	else if(!strcmp(name,"ViewProjectsList")) { view_projects_list( );}
	else if(!strcmp(name,"ViewToolbar")) { view_toolbar(); }
	else if(!strcmp(name,"ViewMiniIcons")) { view_icons(); }
}
static GtkToggleActionEntry gtkActionToggleEntries[] =
{

	{ "ViewWindowsFrame", NULL, "Show _Windows frame", NULL, "Show windows frame", G_CALLBACK (toggle_action), FALSE },
	{ "ViewProjectsList", NULL, "Show _Projects List", NULL, "Show projects List", G_CALLBACK (toggle_action), TRUE },
	{ "ViewToolbar", NULL, "Show toolbar", NULL, "Show toolbar", G_CALLBACK (toggle_action), TRUE},
	{ "ViewMiniIcons", NULL, "Mini icons", NULL, "Mini icons", G_CALLBACK (toggle_action), TRUE}
};

static guint numberOfGtkActionToggleEntries = G_N_ELEMENTS (gtkActionToggleEntries);
/*********************************************************************************************************************/

/* XML description of the menus for the test app.  The parser understands
 * a subset of the Bonobo UI XML format, and uses GMarkup for parsing */
static const gchar *uiInfo =
"  <menubar>\n"
"    <menu name=\"_File\" action=\"File\">\n"
"      <menu name=\"_New\" action=\"FileNew\">\n"
"         <menuitem name=\"GamessInput\" action=\"GamessInput\" />\n"
"         <menuitem name=\"GaussianInput\" action=\"GaussianInput\" />\n"
"         <menuitem name=\"MolcasInput\" action=\"MolcasInput\" />\n"
"         <menuitem name=\"MolproInput\" action=\"MolproInput\" />\n"
"         <menuitem name=\"MopacInput\" action=\"MopacInput\" />\n"
"         <menuitem name=\"MPQCInput\" action=\"MPQCInput\" />\n"
"         <menuitem name=\"OrcaInput\" action=\"OrcaInput\" />\n"
"         <menuitem name=\"PCGamessInput\" action=\"PCGamessInput\" />\n"
"         <menuitem name=\"QChemInput\" action=\"QChemInput\" />\n"
"         <menuitem name=\"Other\" action=\"OtherInput\" />\n"
"      </menu>\n"
"      <menuitem name=\"_Open\" action=\"Open\" />\n"
"      <menuitem name=\"_Save\" action=\"Save\" />\n"
"      <menuitem name=\"Save _as\" action=\"SaveAs\" />\n"
"      <menuitem name=\"_Include\" action=\"Include\" />\n"
"      <separator name=\"sepMenuPrint\" />\n"
"      <menuitem name=\"_Print\" action=\"Print\" />\n"
"      <separator name=\"sepMenuExit\" />\n"
"      <menuitem name=\"_Exit\" action=\"Exit\" />\n"
"    </menu>\n"
"    <menu name=\"_Edit\" action=\"Edit\">\n"
"      <menuitem name=\"C_ut\" action=\"Cut\" />\n"
"      <menuitem name=\"_Copy\" action=\"Copy\" />\n"
"      <menuitem name=\"_Paste\" action=\"Paste\" />\n"
"      <menuitem name=\"_Select All\" action=\"SelectAll\" />\n"
"      <separator name=\"sepMenuFind\" />\n"
"      <menuitem name=\"_Find\" action=\"Find\" />\n"
"    </menu>\n"
"    <menu name=\"_Insert\" action=\"Insert\">\n"
"      <menu name=\"_Gaussian\" action=\"InsertGaussian\">\n"
"        <menuitem name=\"_Add Input File(Multi-Step Job)\" action=\"InsertGaussianMultiStep\" />\n"
"        <menuitem name=\"G_eometry\" action=\"InsertGaussianGeometry\" />\n"
"      </menu>\n"
"      <menu name=\"Mol_cas\" action=\"InsertMolcas\">\n"
"        <menuitem name=\"_Add to file\" action=\"InsertMolcasAddToFile\" />\n"
"      </menu>\n"
"      <menu name=\"Mol_pro\" action=\"InsertMolpro\">\n"
"        <menuitem name=\"_General\" action=\"InsertMolproGeneral\" />\n"
"        <menuitem name=\"G_eometry\" action=\"InsertMolproGeometry\" />\n"
"        <menuitem name=\"_Basis\" action=\"InsertMolproBasis\" />\n"
"        <menuitem name=\"_Commands\" action=\"InsertMolproCommands\" />\n"
"      </menu>\n"
"    </menu>\n"
"    <menu name=\"_View\" action=\"View\">\n"
"      <menuitem name=\"_Windows frame\" action=\"ViewWindowsFrame\" />\n"
"      <menuitem name=\"_Projects List\" action=\"ViewProjectsList\" />\n"
"      <menuitem name=\"_ToolBar\" action=\"ViewToolbar\" />\n"
"      <menuitem name=\"_ToolBar\" action=\"ViewMiniIcons\" />\n"
"      <separator name=\"sepMenuIcons\" />\n"
"    </menu>\n"
"    <menu name=\"_Geometry\" action=\"Geometry\">\n"
"      <menuitem name=\"_Gaussian\" action=\"GeometryGaussian\" />\n"
"      <menuitem name=\"Mol_pro\" action=\"GeometryMolpro\" />\n"
"      <menuitem name=\"_Edit\" action=\"GeometryEdit\" />\n"
"      <menuitem name=\"_Draw\" action=\"GeometryDraw\" />\n"
"    </menu>\n"
"    <menu name=\"_Tools\" action=\"Tools\">\n"
"      <menu name=\"_Process\" action=\"ToolsProcess\">\n"
"        <menu name=\"_Local\" action=\"ToolsProcessLocal\">\n"
"          <menuitem name=\"All local process\" action=\"ToolsProcessLocalAll\" />\n"
"          <menuitem name=\"User local process\" action=\"ToolsProcessLocalUser\" />\n"
"        </menu>\n"
"        <menu name=\"_Remote\" action=\"ToolsProcessRemote\">\n"
"          <menuitem name=\"All remote process\" action=\"ToolsProcessRemoteAll\" />\n"
"          <menuitem name=\"User remote process\" action=\"ToolsProcessRemoteUser\" />\n"
"        </menu>\n"
"      </menu>\n"
"      <menu name=\"_Batch\" action=\"ToolsBatch\">\n"
"        <menu name=\"_Local\" action=\"ToolsBatchLocal\">\n"
"          <menuitem name=\"All local batch\" action=\"ToolsBatchLocalAll\" />\n"
"          <menuitem name=\"User local batch\" action=\"ToolsBatchLocalUser\" />\n"
"        </menu>\n"
"        <menu name=\"_Remote\" action=\"ToolsBatchRemote\">\n"
"          <menuitem name=\"All remote batch\" action=\"ToolsBatchRemoteAll\" />\n"
"          <menuitem name=\"User remote batch\" action=\"ToolsBatchRemoteUser\" />\n"
"        </menu>\n"
"      </menu>\n"
"      <menuitem name=\"Open B_abel\" action=\"ToolsOpenBabel\" />\n"
"      <separator name=\"sepUnitConv\" />\n"
"      <menuitem name=\"Unit conversion\" action=\"ToolsUnitConversion\" />\n"
"      <separator name=\"sepXYPlot\" />\n"
"      <menuitem name=\"ToolsXYPlot\" action=\"ToolsXYPlot\" />\n"

"      <separator name=\"sepIRSpectrum\" />\n"
"      <menu name=\"ToolsIRSpectrum\" action=\"ToolsIRSpectrum\">\n"
"          <menuitem name=\"ToolsIRSpectrumGabedit\" action=\"ToolsIRSpectrumGabedit\" />\n"
"          <menuitem name=\"ToolsIRSpectrumDalton\" action=\"ToolsIRSpectrumDalton\" />\n"
"          <menuitem name=\"ToolsIRSpectrumGamess\" action=\"ToolsIRSpectrumGamess\" />\n"
"          <menuitem name=\"ToolsIRSpectrumGaussian\" action=\"ToolsIRSpectrumGaussian\" />\n"
"          <menuitem name=\"ToolsIRSpectrumMolpro\" action=\"ToolsIRSpectrumMolpro\" />\n"
"          <menuitem name=\"ToolsIRSpectrumOrca\" action=\"ToolsIRSpectrumOrca\" />\n"
"          <menuitem name=\"ToolsIRSpectrumPCGamess\" action=\"ToolsIRSpectrumPCGamess\" />\n"
"          <menuitem name=\"ToolsIRSpectrumQChem\" action=\"ToolsIRSpectrumQChem\" />\n"
"          <menuitem name=\"ToolsIRSpectrumAdf\" action=\"ToolsIRSpectrumAdf\" />\n"
"          <menuitem name=\"ToolsIRSpectrumMolden\" action=\"ToolsIRSpectrumMolden\" />\n"
"          <menuitem name=\"ToolsIRSpectrumTxt\" action=\"ToolsIRSpectrumTxt\" />\n"
"      </menu>\n"
"      <separator name=\"sepRamanSpectrum\" />\n"
"      <menu name=\"ToolsRamanSpectrum\" action=\"ToolsRamanSpectrum\">\n"
"          <menuitem name=\"ToolsRamanSpectrumGabedit\" action=\"ToolsRamanSpectrumGabedit\" />\n"
"          <menuitem name=\"ToolsRamanSpectrumGamess\" action=\"ToolsRamanSpectrumGamess\" />\n"
"          <menuitem name=\"ToolsRamanSpectrumGaussian\" action=\"ToolsRamanSpectrumGaussian\" />\n"
"          <menuitem name=\"ToolsRamanSpectrumOrca\" action=\"ToolsRamanSpectrumOrca\" />\n"
"          <menuitem name=\"ToolsRamanSpectrumPCGamess\" action=\"ToolsRamanSpectrumPCGamess\" />\n"
"          <menuitem name=\"ToolsRamanSpectrumMolden\" action=\"ToolsRamanSpectrumMolden\" />\n"
"          <menuitem name=\"ToolsRamanSpectrumTxt\" action=\"ToolsRamanSpectrumTxt\" />\n"
"      </menu>\n"
"      <separator name=\"sepUVSpectrum\" />\n"
"      <menu name=\"ToolsUVSpectrum\" action=\"ToolsUVSpectrum\">\n"
"          <menuitem name=\"ToolsUVSpectrumGabedit\" action=\"ToolsUVSpectrumGabedit\" />\n"
"          <menuitem name=\"ToolsUVSpectrumGaussian\" action=\"ToolsUVSpectrumGaussian\" />\n"
"          <menuitem name=\"ToolsUVSpectrumOrca\" action=\"ToolsUVSpectrumOrca\" />\n"
"          <menuitem name=\"ToolsUVSpectrumPCGamess\" action=\"ToolsUVSpectrumPCGamess\" />\n"
"          <menuitem name=\"ToolsUVSpectrumQChem\" action=\"ToolsUVSpectrumQChem\" />\n"
"          <menuitem name=\"ToolsUVSpectrumTxt\" action=\"ToolsUVSpectrumTxt\" />\n"
"      </menu>\n"
"      <separator name=\"sepECDSpectrum\" />\n"
"      <menu name=\"ToolsECDSpectrum\" action=\"ToolsECDSpectrum\">\n"
"          <menuitem name=\"ToolsECDSpectrumGabedit\" action=\"ToolsECDSpectrumGabedit\" />\n"
"          <menuitem name=\"ToolsECDSpectrumGaussian\" action=\"ToolsECDSpectrumGaussian\" />\n"
"          <menuitem name=\"ToolsECDSpectrumOrca\" action=\"ToolsECDSpectrumOrca\" />\n"
"          <menuitem name=\"ToolsECDSpectrumTxt\" action=\"ToolsECDSpectrumTxt\" />\n"
"      </menu>\n"
"      <separator name=\"sepNMRSpectrum\" />\n"
"      <menu name=\"ToolsNMRSpectrum\" action=\"ToolsNMRSpectrum\">\n"
"          <menuitem name=\"ToolsNMRSpectrumTxt\" action=\"ToolsNMRSpectrumTxt\" />\n"
"          <menuitem name=\"ToolsNMR2SpectrumTxt\" action=\"ToolsNMR2SpectrumTxt\" />\n"
"      </menu>\n"
"      <separator name=\"sepIsotopDistribution\" />\n"
"      <menuitem name=\"ToolsIsotopeDistribution\" action=\"ToolsIsotopeDistribution\" />\n"
"      <separator name=\"sepVibCorrections\" />\n"
"      <menu name=\"ToolsVibCorrections\" action=\"ToolsVibCorrections\">\n"
"          <menuitem name=\"ToolsVibCorrectionsGaussian\" action=\"ToolsVibCorrectionsGaussian\" />\n"
"      </menu>\n"
"    </menu>\n"
"    <menu name=\"_Run\" action=\"Run\">\n"
"      <menuitem name=\"_Run a abtinio program\" action=\"RunAbinitio\" />\n"
"      <menuitem name=\"_View result of calculation\" action=\"RunViewResult\" />\n"
"    </menu>\n"
"    <menu name=\"_Settings\" action=\"Settings\">\n"
"      <menuitem name=\"_Molecular Mechanics Parameters\" action=\"SettingsMolecularMechanicsParameters\" />\n"
"      <menuitem name=\"_PDB Template\" action=\"SettingsPDBTemplate\" />\n"
"      <separator name=\"sepMenuBasis\" />\n"
"      <menu name=\"_Basis\" action=\"SettingsBasis\">\n"
"         <menuitem name=\"Mol_pro\" action=\"SettingsBasisMolpro\" />\n"
"         <menuitem name=\"Mol_cas\" action=\"SettingsBasisMolcas\" />\n"
"         <menuitem name=\"MP_QC\" action=\"SettingsBasisMPQC\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuPreferences\" />\n"
"      <menuitem name=\"P_references\" action=\"SettingsPreferences\" />\n"
"    </menu>\n"
"    <menu name=\"_Window\" action=\"Window\">\n"
"      <separator name=\"sepMenuWin\" />\n"
"    </menu>\n"
"    <menu name=\"_Help\" action=\"Help\" position=\"bot\">\n"
"      <menuitem name=\"_About...\" action=\"HelpAbout\" />\n"
"      <menuitem name=\"_Version...\" action=\"HelpVersion\" />\n"
"    </menu>\n"
"  </menubar>\n"
"  <toolbar action=\"Toolbar\">\n"
"      <toolitem name=\"GamessInput\" action=\"GamessInput\" />\n"
"      <toolitem name=\"GaussianInput\" action=\"GaussianInput\" />\n"
"      <toolitem name=\"MolcasInput\" action=\"MolcasInput\" />\n"
"      <toolitem name=\"MolproInput\" action=\"MolproInput\" />\n"
"      <toolitem name=\"MopacInput\" action=\"MopacInput\" />\n"
"      <toolitem name=\"MPQCInput\" action=\"MPQCInput\" />\n"
"      <toolitem name=\"OrcaInput\" action=\"OrcaInput\" />\n"
"      <toolitem name=\"PCGamessInput\" action=\"PCGamessInput\" />\n"
"      <toolitem name=\"QChemInput\" action=\"QChemInput\" />\n"
"      <toolitem name=\"_Include\" action=\"Include\" />\n"
"      <toolitem name=\"_Open\" action=\"Open\" />\n"
"      <toolitem name=\"_Save\" action=\"Save\" />\n"
"      <toolitem name=\"Save _as\" action=\"SaveAs\" />\n"
"      <toolitem name=\"_Print\" action=\"Print\" />\n"
"      <separator name=\"sepToolBarCut\" />\n"
"      <toolitem name=\"C_ut\" action=\"Cut\" />\n"
"      <toolitem name=\"_Copy\" action=\"Copy\" />\n"
"      <toolitem name=\"_Paste\" action=\"Paste\" />\n"
"      <toolitem name=\"_Find\" action=\"Find\" />\n"
"      <toolitem name=\"_Select All\" action=\"SelectAll\" />\n"
"      <separator name=\"sepToolBarRun\" />\n"
"      <toolitem name=\"_Run a abtinio program\" action=\"RunAbinitio\" />\n"
"      <separator name=\"sepToolBarGeom\" />\n"
"      <toolitem name=\"_Draw Geometry\" action=\"GeometryDraw\" />\n"
"      <toolitem name=\"_Display\" action=\"DisplayDensity\" />\n"
"      <separator name=\"sepToolBarBabel\" />\n"
/*
"      <toolitem name=\"Open B_abel\" action=\"ToolsOpenBabel\" />\n"
*/
"      <toolitem name=\"Unit _conversion utility\" action=\"ToolsUnitConversion\" />\n"
"      <separator name=\"sepToolBarExit\" />\n"
"      <toolitem name=\"_Exit\" action=\"Exit\" />\n"
"      <separator name=\"sepToolBarAbout\" />\n"
"      <toolitem name=\"_About...\" action=\"HelpAbout\" />\n"
"  </toolbar>\n"
;

/*******************************************************************************************************************************/
static void add_widget (GtkUIManager *merge, GtkWidget   *widget, GtkContainer *container)
{
	GtkWidget *handlebox;

	handlebox =gtk_handle_box_new ();
	g_object_ref (handlebox);
	gtk_handle_box_set_shadow_type(GTK_HANDLE_BOX(handlebox),GTK_SHADOW_NONE);
	gtk_box_pack_start (GTK_BOX (container), handlebox, FALSE, FALSE, 0);

	if (GTK_IS_TOOLBAR (widget)) 
	{
		GtkToolbar *toolbar;
		toolbar = GTK_TOOLBAR (widget);
		gtk_toolbar_set_show_arrow (toolbar, TRUE);
		gtk_toolbar_set_style(toolbar, GTK_TOOLBAR_ICONS);
		gtk_toolbar_set_orientation(toolbar,  GTK_ORIENTATION_HORIZONTAL);
		toolBar = toolbar;
		handleBoxToolBar = handlebox;
	}
	gtk_widget_show (widget);
	gtk_container_add (GTK_CONTAINER (handlebox), widget);
}
/*******************************************************************************************************************************/
void add_menu_toolbar()
{
	GtkWidget *box;
  	GtkUIManager *merge;
	GError *error = NULL;
	GtkActionGroup *actionGroup = NULL;

	box = gtk_vbox_new (FALSE, 0);
	gtk_box_pack_start (GTK_BOX (vboxmain), box, FALSE, FALSE, 0);
	gtk_widget_show (box);

  	merge = gtk_ui_manager_new ();
  	g_signal_connect_swapped (Fenetre, "destroy", G_CALLBACK (g_object_unref), merge);

	actionGroup = gtk_action_group_new ("GabeditActions");
	gtk_action_group_add_actions (actionGroup, gtkActionEntries, numberOfGtkActionEntries, NULL);
	gtk_action_group_add_toggle_actions (actionGroup, gtkActionToggleEntries, numberOfGtkActionToggleEntries, NULL);
  	gtk_ui_manager_insert_action_group (merge, actionGroup, 0);



	g_signal_connect (merge, "add_widget", G_CALLBACK (add_widget), box);
	
  	gtk_window_add_accel_group (GTK_WINDOW (Fenetre), gtk_ui_manager_get_accel_group (merge));
	if (!gtk_ui_manager_add_ui_from_string (merge, uiInfo, -1, &error))
	{
		g_message ("building menus failed: %s", error->message);
		g_error_free (error);
	}
	manager = merge;
}
/*********************************************************************************************************************/
static void activate_action_window (GtkAction *action, gpointer data)
{
	const gchar *name = gtk_action_get_name (action);

	if(strstr(name,"WinDynamic"))
	{
		GtkWidget* win = (GtkWidget*)data;
		if(GTK_IS_WIDGET(win))
		{
			gtk_widget_hide(win);
			gtk_widget_show(win);
		}
	}
}
/*******************************************************************************************************************************/
void window_add(gchar *str,GtkWidget* Win)
{
	guint  merge_id;
	static GtkActionGroup *dag = NULL;
	GtkActionEntry *actionEntry;
	GtkAction *action;
	gchar* name;
	gchar* label;
	GList*  listOfActions = NULL;
	GList*  list = NULL;
	gint i;
	gchar* tmp;

	if(!manager) return;
	merge_id = gtk_ui_manager_new_merge_id (GTK_UI_MANAGER (manager));

	if(!dag)
	{
		dag = gtk_action_group_new ("WindowActions");
		gtk_ui_manager_insert_action_group (manager, dag, 0);
	}
	listOfActions =   gtk_action_group_list_actions(dag);
	i = 0;
	list = listOfActions;
	tmp = g_strdup_printf("WinDynamic%s", str);
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
		name = g_strdup_printf ("WinDynamic%s", str);
		label = g_strdup_printf ("%s", str);
	}
	else
	{
		name = g_strdup_printf ("WinDynamic%s%d", str,i);
		label = g_strdup_printf ("%s%d", str,i);
	}
	actionEntry = g_malloc(sizeof(GtkActionEntry));
	actionEntry->name = name;
	actionEntry->stock_id = NULL;
	actionEntry->label = label;
	actionEntry->accelerator = NULL;
	actionEntry->tooltip = NULL;
	actionEntry->callback = G_CALLBACK(activate_action_window);
        gtk_action_group_add_actions (dag, actionEntry, 1, Win);


	gtk_ui_manager_add_ui(GTK_UI_MANAGER (manager), merge_id, "/menubar/_Window", name, name, GTK_UI_MANAGER_MENUITEM, TRUE);
	g_object_set_data(G_OBJECT(Win),"WinId",GUINT_TO_POINTER(merge_id));
	gtk_ui_manager_ensure_update (manager);

}
/*******************************************************************************************************************************/
void window_delete(GtkWidget* Win)
{
	guint  merge_id;

	if(!manager) return;
	merge_id =  GPOINTER_TO_UINT (g_object_get_data (G_OBJECT (Win), "WinId"));
	gtk_ui_manager_remove_ui(GTK_UI_MANAGER (manager), merge_id);
	gtk_ui_manager_ensure_update (manager);
}
