/* MenuToolBarGL.c */
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
#include "GlobalOrb.h"
#include "../OpenGL/GeomOrbXYZ.h"
#include "../OpenGL/UtilsOrb.h"
#include "../OpenGL/GridCube.h"
#include "../OpenGL/GridAdfOrbitals.h"
#include "../OpenGL/GridAdfDensity.h"
#include "../OpenGL/GridMolcas.h"
#include "../OpenGL/GridQChem.h"
#include "../OpenGL/GridCP.h"
#include "../Utils/AtomsProp.h"
#include "../Utils/UtilsInterface.h"
#include "../Utils/HydrogenBond.h"
#include "../Utils/PovrayUtils.h"
#include "../Files/FileChooser.h"
#include "../OpenGL/GLArea.h"
#include "../OpenGL/Orbitals.h"
#include "../OpenGL/Images.h"
#include "../OpenGL/GridPlans.h"
#include "../OpenGL/Contours.h"
#include "../OpenGL/PlanesMapped.h"
#include "../OpenGL/PreferencesOrb.h"
#include "../OpenGL/PreferencesOrb.h"
#include "../OpenGL/Vibration.h"
#include "../OpenGL/AnimationRotation.h"
#include "../OpenGL/AnimationGeomConv.h"
#include "../OpenGL/AnimationMD.h"
#include "../OpenGL/AnimationContours.h"
#include "../OpenGL/AnimationPlanesMapped.h"
#include "../OpenGL/AnimationIsoSurface.h"
#include "../OpenGL/Dipole.h"
#include "../OpenGL/AxisGL.h"
#include "../OpenGL/PrincipalAxisGL.h"
#include "../OpenGL/PovrayGL.h"
#include "../OpenGL/ExportGL.h"
#include "../OpenGL/StatusOrb.h"
#include "../OpenGL/LabelsGL.h"
#include "../OpenGL/RingsOrb.h"
#include "../OpenGL/ContoursDraw.h"
#include "../OpenGL/CaptureOrbitals.h"
#include "../OpenGL/IntegralOrbitals.h"
#include "../OpenGL/BondsOrb.h"
#include "../Common/StockIcons.h"

enum 
{
	BACKGROUND_BLACK,
	BACKGROUND_WHITE,
	BACKGROUND_RED1,
	BACKGROUND_GREEN1,
	BACKGROUND_BLUE1,
	BACKGROUND_PEACH,
	BACKGROUND_GRAY,
	BACKGROUND_CHECKER
};
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
static void set_optimal_view()
{
	gint i,j;
	gdouble min = 0;
	gdouble max = 0;
  	gboolean perspective = FALSE;
  	gdouble zn, zf, zo;
  	gdouble aspect;

	if(!GeomOrb || Ncenters<1 ) return;
 
	min = GeomOrb[0].C[0];
	max = GeomOrb[0].C[0];
	for(i=0;i<Ncenters;i++)
	{
		for(j=0;j<3;j++)
		{
			if(min>GeomOrb[i].C[j]) min = GeomOrb[i].C[j];
			if(max<GeomOrb[i].C[j]) max = GeomOrb[i].C[j];
		}
	}
	if(grid)
	{
		for(j=0;j<3;j++)
		{
			if(min>grid->limits.MinMax[0][j]) min = grid->limits.MinMax[0][j];
			if(max<grid->limits.MinMax[1][j]) max = grid->limits.MinMax[1][j];
		}
	}
	get_camera_values(&zn, &zf, &zo, &aspect, &perspective);
	zn = 1;
	zf = fabs(max-min)*5;
	if(Ncenters<2) zf = 100;
	if(perspective) zo = 1.0;
	else
	{
		gdouble d = fabs(max-min);
		if(d>1e-10) zo = 20/d;
		else zo = 1.0;
	}

	zo = 1/zo*45;
	set_camera_values(zn,zf,zo,perspective);
}
/*********************************************************************************************************************/
static void activate_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	/* const gchar *typename = G_OBJECT_TYPE_NAME (action);*/

	if(!strcmp(name,"GeometryAuto"))
		file_chooser_open(gl_read_geom_any_file_sel,"Read geometry",GABEDIT_TYPEFILE_UNKNOWN,GABEDIT_TYPEWIN_ORB);
	if(!strcmp(name,"GeometryXYZ"))
		file_chooser_open(gl_read_xyz_file_sel,"Read a xyz file",GABEDIT_TYPEFILE_XYZ,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryPDB"))
		file_chooser_open(gl_read_pdb_file_sel,"Read a pdb file",GABEDIT_TYPEFILE_PDB,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryHIN"))
		file_chooser_open(gl_read_hin_file_sel,"Read a hyperchem file",GABEDIT_TYPEFILE_HIN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryOpenBabel"))
		gl_create_babel_read_dialogue();
	else if(!strcmp(name,"GeometryDaltonFirst"))
 		file_chooser_open(gl_read_first_dalton_file,"Read the first geometry in a Dalton output file",GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryDaltonLast"))
 		file_chooser_open(gl_read_last_dalton_file,"Read the last geometry in a Dalton output file",GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryGamessFirst"))
 		file_chooser_open(gl_read_first_gamess_file,"Read the first geometry in a Gamess output file",GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryGamessLast"))
 		file_chooser_open(gl_read_last_gamess_file,"Read the last geometry in a Gamess output file",GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryGaussianFirst"))
 		file_chooser_open(gl_read_first_gauss_file,"Read the first geometry in a Gaussian output file",GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryGaussianLast"))
 		file_chooser_open(gl_read_last_gauss_file,"Read the last geometry in a Gaussian output file",GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMolcasFirst"))
 		file_chooser_open(gl_read_first_molcas_file,"Read the first geometry in a Molcas output file",GABEDIT_TYPEFILE_MOLCAS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMolcasLast"))
 		file_chooser_open(gl_read_last_molcas_file,"Read the last geometry in a Molcas output file",GABEDIT_TYPEFILE_MOLCAS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMolproFirst"))
 		file_chooser_open(gl_read_first_molpro_file,"Read the first geometry in a Molpro output file",GABEDIT_TYPEFILE_MOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMolproLast"))
 		file_chooser_open(gl_read_last_molpro_file,"Read the last geometry in a Molpro output file",GABEDIT_TYPEFILE_MOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMopacOutFirst"))
 		file_chooser_open(gl_read_first_mopac_output_file,"Read the first geometry from a Mopac output file",GABEDIT_TYPEFILE_MOPAC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMopacOutLast"))
 		file_chooser_open(gl_read_last_mopac_output_file,"Read the last geometry from a Mopac output file",GABEDIT_TYPEFILE_MOPAC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMopacAuxFirst"))
 		file_chooser_open(gl_read_first_mopac_aux_file,"Read the first geometry from a Mopac aux file",GABEDIT_TYPEFILE_MOPAC_AUX,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMopacAuxLast"))
 		file_chooser_open(gl_read_last_mopac_aux_file,"Read the last geometry from a Mopac aux file",GABEDIT_TYPEFILE_MOPAC_AUX,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMPQCFirst"))
 		file_chooser_open(gl_read_first_mpqc_file,"Read the first geometry from a MPQC output file",GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMPQCLast"))
 		file_chooser_open(gl_read_last_mpqc_file,"Read the last geometry from a MPQC output file",GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryOrcaFirst"))
 		file_chooser_open(gl_read_first_orca_file,"Read the first geometry in a Orca output file",GABEDIT_TYPEFILE_ORCA,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryOrcaLast"))
 		file_chooser_open(gl_read_last_orca_file,"Read the last geometry in a Orca output file",GABEDIT_TYPEFILE_ORCA,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryPCGamessFirst"))
 		file_chooser_open(gl_read_first_gamess_file,"Read the first geometry in a PCGamess output file",GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name,"GeometryPCGamessLast"))
 		file_chooser_open(gl_read_last_gamess_file,"Read the last geometry in a PCGamess output file",GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);

	else if(!strcmp(name ,"GeometryQChemFirst"))
 		file_chooser_open(gl_read_first_qchem_file,"Read the first geometry from a Q-Chem output file",GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryQChemLast"))
 		file_chooser_open(gl_read_last_qchem_file,"Read the last geometry from a Q-Chem output file",GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryGabedit"))
 		file_chooser_open(gl_read_gabedit_file,"Read geometry from a gabedit file",GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMolden"))
 		file_chooser_open(gl_read_molden_file,"Read geometry from a molden file",GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_ORB);

	else if(!strcmp(name , "OrbitalsAuto"))
 			file_chooser_open(read_orbitals_sel,"Read Geometry and Orbitals(Auto)",GABEDIT_TYPEFILE_UNKNOWN,GABEDIT_TYPEWIN_ORB);
	/*
	else if(!strcmp(name , "OrbitalsDalton"))
 			file_chooser_open(read_dalton_orbitals_sel,"Read Geometry and Orbitals from a Dalton output file",GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_ORB);
			*/
	else if(!strcmp(name , "OrbitalsGamess"))
 			file_chooser_open(read_gamess_orbitals_sel,"Read Geometry and Orbitals from a Gamess output file",GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsOrca"))
 			file_chooser_open(read_orca_orbitals_sel,"Read Geometry and Orbitals from a Orca files",GABEDIT_TYPEFILE_ORCA,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsOrca2mkl"))
 			file_chooser_open(read_orca_orbitals_sel_2mkl,"Read Geometry and Orbitals from a Orca files",GABEDIT_TYPEFILE_ORCA,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsPCGamess"))
 			file_chooser_open(read_gamess_orbitals_sel,"Read Geometry and Orbitals from a PCGamess output file",GABEDIT_TYPEFILE_GAMESS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsQChem"))
 			file_chooser_open(read_qchem_orbitals_sel,"Read Geometry and Orbitals from a Q-Chem output file",GABEDIT_TYPEFILE_QCHEM,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsMopac"))
 			file_chooser_open(read_mopac_orbitals_sel,"Read Geometry and Orbitals from a Mopac output file",GABEDIT_TYPEFILE_MOPAC_AUX,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsGaussian"))
 			file_chooser_open(read_gauss_orbitals_sel,"Read Geometry and Orbitals from a Gaussian output file",GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsMolpro"))
 			file_chooser_open(read_molpro_orbitals_sel,"Read Geometry and Orbitals from a Molpro output file",GABEDIT_TYPEFILE_MOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsGabeditRead"))
 			file_chooser_open(read_gabedit_orbitals_sel,"Read Geometry and Orbitals from a Gabedit file",GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsMolden"))
 			file_chooser_open(read_molden_orbitals_sel,"Read Geometry and Orbitals from a Molden file",GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsGabeditSave"))
	{
		if(Type) file_chooser_save(save_gabedit_orbitals_sel,"Save Geometry and Orbitals in a Gabedit file",GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);
		else Message("Sorry, I cannot save this type of orbitals \n(probably these are molpro or mopac orbitals)","Error",TRUE);
	}
	else if(!strcmp(name , "OrbitalsSelection"))
	{
			TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
			create_list_orbitals();
	}
	else if(!strcmp(name , "OrbitalsCapture"))
	{
			TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
			 capture_orbitals_dlg();
	}
	else if(!strcmp(name , "OrbitalsCoulomb"))
	{
			TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
			coulomb_orbitals_dlg();
	}
	else if(!strcmp(name , "OrbitalsTransition"))
	{
			TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
			transition_matrix_orbitals_dlg();
	}
	else if(!strcmp(name , "OrbitalsOverlap"))
	{
			TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
			 compute_overlap_matrix(1);
	}
	else if(!strcmp(name , "CubeLoadGaussianOrbitals" ))
 		file_chooser_open(load_cube_gauss_orbitals_file,"Load Gaussian orbitals cube file",GABEDIT_TYPEFILE_CUBEGAUSS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGaussianDensity"))
 		file_chooser_open(load_cube_gauss_density_file,"Load Gaussian density cube file",GABEDIT_TYPEFILE_CUBEGAUSS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGaussianDensityGradient"))
 		file_chooser_open(load_cube_gauss_gradient_file,"Load Gaussian gradient cube file",GABEDIT_TYPEFILE_CUBEGAUSS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGaussianLaplacian" ))
 		file_chooser_open(load_cube_gauss_laplacian_file,"Load Gaussian laplacian cube file",GABEDIT_TYPEFILE_CUBEGAUSS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGaussianNormGradient"))
 		file_chooser_open(load_cube_gauss_normgrad_file,"Load Gaussian norm gradient cube file",GABEDIT_TYPEFILE_CUBEGAUSS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGaussianPotential"))
 		file_chooser_open(load_cube_gauss_potential_file,"Load Gaussian potential cube file",GABEDIT_TYPEFILE_CUBEGAUSS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolproOrbitalsOne"))
 		file_chooser_open(load_cube_molpro_orbital_file,"Load Molpro one orbital cube file",GABEDIT_TYPEFILE_CUBEMOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolproOrbitalsSeveral")) 
 		file_chooser_open(load_cube_molpro_orbitals_file,"Load Molpro several orbitals cube file",GABEDIT_TYPEFILE_CUBEMOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolproDensityOne"))
 		file_chooser_open(load_cube_molpro_density_file,"Load Molpro density cube file",GABEDIT_TYPEFILE_CUBEMOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolproDensityGradient"))
 		file_chooser_open(load_cube_molpro_density_gradient_file,"Load Molpro gradient cube file",GABEDIT_TYPEFILE_CUBEMOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolproDensityGradientLaplacianDensity"))
 		file_chooser_open(load_cube_molpro_laplacian_density_file,"Load density from Molpro laplacian cube file",GABEDIT_TYPEFILE_CUBEMOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolproDensityGradientLaplacianLaplacian"))
 		file_chooser_open(load_cube_molpro_laplacian_laplacian_file,"Load Molpro laplacian cube file",GABEDIT_TYPEFILE_CUBEMOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadAdfOrbitals"))
 		file_chooser_open(load_adf_file_orbitals,"Load orbitals from adf file",GABEDIT_TYPEFILE_CUBEADF,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadAdfDensity"))
 		file_chooser_open(load_adf_file_density,"Load density from adf file",GABEDIT_TYPEFILE_CUBEADF,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolcasGridOrbitals"))
 		file_chooser_open(load_molcasgrid_file_orbitals,"Load Orbitals from molcasgrid file",GABEDIT_TYPEFILE_MOLCASGRID,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolcasGridDensity"))
 		file_chooser_open(load_molcasgrid_file_density,"Load density from molcasgrid file",GABEDIT_TYPEFILE_MOLCASGRID,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGabeditRead"))
 		file_chooser_open(load_cube_gabedit_file,"Load Gabedit cube file",GABEDIT_TYPEFILE_CUBEGABEDIT,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadQChem"))
 		file_chooser_open(load_qchemgrid_file,"Load Q-Chem Grid file",GABEDIT_TYPEFILE_CUBEQCHEM,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGabeditSave"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else file_chooser_save(save_cube_gabedit_file,"Save density",GABEDIT_TYPEFILE_CUBEGABEDIT,GABEDIT_TYPEWIN_ORB);
	}
	else if(!strcmp(name , "CubeSubtract"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else file_chooser_open(subtract_cube,"Subtract",GABEDIT_TYPEFILE_CUBEGABEDIT,GABEDIT_TYPEWIN_ORB);
	}
	else if(!strcmp(name , "CubeScale"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else create_scale_dlg();
	}
	else if(!strcmp(name , "CubeSquare"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else square_cube();
	}
	else if(!strcmp(name , "CubeRestriction"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else restriction_cube();
	}
	else if(!strcmp(name , "CubeAIMChargesNearGrid"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else computeAIMCharges(grid, FALSE);
	}
	else if(!strcmp(name , "CubeAIMChargesOnGrid"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else computeAIMCharges(grid, TRUE);
	}
	else if(!strcmp(name , "CubeColorMapping"))
	{
		if(!grid) Message("Sorry, you have not a default grid","Error",TRUE);
		else file_chooser_open(mapping_cube,"Color Mapping",GABEDIT_TYPEFILE_CUBEGABEDIT,GABEDIT_TYPEWIN_ORB);
	}
	else if(!strcmp(name , "DensityElectronic"))
	{
		TypeGrid = GABEDIT_TYPEGRID_EDENSITY;
		create_grid("Calculation of molecular electronic density grid");
	}
	else if(!strcmp(name , "DensityBonds"))
	{
		TypeGrid = GABEDIT_TYPEGRID_DDENSITY;
		create_grid("Calculation of (molecular - atomic) density grid");
	}
	else if(!strcmp(name , "DensitySpin"))
	{
		TypeGrid = GABEDIT_TYPEGRID_SDENSITY;
		create_grid("Calculation of molecular electronic spin density grid");
	}
	else if(!strcmp(name , "DensityAtomics")) 
	{
			TypeGrid = GABEDIT_TYPEGRID_ADENSITY;
			create_grid("Calculation of atomic electronic density grid");
	}
	else if(!strcmp(name , "ELFBecke"))
	{
		TypeGrid = GABEDIT_TYPEGRID_ELFBECKE;
		create_grid("Calculation of Becke ELF");
	}
	else if(!strcmp(name , "ELFSavin"))
	{
		TypeGrid = GABEDIT_TYPEGRID_ELFSAVIN;
		create_grid("Calculation of Savin ELF");
	}
	else if(!strcmp(name , "ELFSavinAttractors"))
	{
		TypeGrid = GABEDIT_TYPEGRID_ELFSAVIN;
		create_grid_ELF_Dens_analyze(TRUE);
	}
	else if(!strcmp(name , "FEDElectrophilic"))
	{
		TypeGrid = GABEDIT_TYPEGRID_FEDELECTROPHILIC;
		create_grid("Calculation of FED Electrophilic susceptibility");
	}
	else if(!strcmp(name , "FEDNucleophilic"))
	{
		TypeGrid = GABEDIT_TYPEGRID_FEDNUCLEOPHILIC;
		create_grid("Calculation of FED Nucleophilic susceptibility");
	}
	else if(!strcmp(name , "FEDRadical"))
	{
		TypeGrid = GABEDIT_TYPEGRID_FEDRADICAL;
		create_grid("Calculation of FED Radical susceptibility");
	}
	else if(!strcmp(name , "FEDSetAlpha"))
	{
		set_alphaFED_dialog ();
	}
	else if(!strcmp(name , "SASCompute"))
	{
		TypeGrid = GABEDIT_TYPEGRID_SAS;
		create_grid_sas("Compute Solvent Accessible Surface");
	}
	else if(!strcmp(name , "SASMappCompute"))
	{
		TypeGrid = GABEDIT_TYPEGRID_SASMAP;
		create_grid_sas("Compute Solvent Accessible Surface");
	}
	else if(!strcmp(name , "MEPOrbitalsMultipol"))
	{
		TypeGrid = GABEDIT_TYPEGRID_MEP_MULTIPOL;
		CancelCalcul = FALSE;
		create_grid("Calculation of MEP using Molecular Orbitals");
	}
	else if(!strcmp(name , "MEPOrbitalsCG"))
	{
		TypeGrid = GABEDIT_TYPEGRID_MEP_CG;
		CancelCalcul = FALSE;
		create_grid("Calculation of MEP from Molecular Orbitals/Poisson by Congugate Gradient");
	}
	else if(!strcmp(name , "MEPOrbitalsMG"))
	{
		TypeGrid = GABEDIT_TYPEGRID_MEP_MG;
		CancelCalcul = FALSE;
		create_grid("Calculation of MEP from Molecular Orbitals/Poisson by Multigrid");
	}
	else if(!strcmp(name , "MEPFromCharges"))
	{
		TypeGrid = GABEDIT_TYPEGRID_MEP_CHARGES;
		CancelCalcul = FALSE;
		create_grid("Calculation of MEP from partial charges of atoms");
	}
	else if(!strcmp(name , "MEPGridMultipol"))
	{
		CancelCalcul = FALSE;
		Grid* esp = compute_mep_grid_using_multipol_from_density_grid(grid, 4);
		if(esp)
		{
			free_grid(grid);
			grid = esp;
			TypeGrid = GABEDIT_TYPEGRID_MEP_MULTIPOL;
			limits = grid->limits;
			create_iso_orbitals();
		}
	}
	else if(!strcmp(name , "MEPGridCG"))
	{
		CancelCalcul = FALSE;
		Grid* esp = solve_poisson_equation_from_density_grid(grid,GABEDIT_CG);
		if(esp)
		{
			free_grid(grid);
			grid = esp;
			TypeGrid = GABEDIT_TYPEGRID_MEP_CG;
			limits = grid->limits;
			create_iso_orbitals();
		}
	}
	else if(!strcmp(name , "MEPGridMG"))
	{
		CancelCalcul = FALSE;
		Grid* esp = solve_poisson_equation_from_density_grid(grid,GABEDIT_MG);
		if(esp)
		{
			free_grid(grid);
			grid = esp;
			TypeGrid = GABEDIT_TYPEGRID_MEP_MG;
			limits = grid->limits;
			create_iso_orbitals();
		}
	}
	else if(!strcmp(name , "MEPMappingCharges"))
	{
		CancelCalcul = FALSE;
		mapping_with_mep_from_charges();
	}
	else if(!strcmp(name , "MEPMappingMultipol"))
	{
		CancelCalcul = FALSE;
		mapping_with_mep_from_multipol(2);
	}
	else if(!strcmp(name , "MEPMappingCG"))
	{
		CancelCalcul = FALSE;
		mapping_with_mep(grid->N,grid->limits, GABEDIT_CG);
	}
	else if(!strcmp(name , "MEPMappingMG"))
	{
		CancelCalcul = FALSE;
		mapping_with_mep(grid->N,grid->limits, GABEDIT_MG);
	}
	else if(!strcmp(name , "FEDElectrophilicMapping"))
	{
		CancelCalcul = FALSE;
		mapping_with_fed(0);
	}
	else if(!strcmp(name , "FEDNucleophilicMapping"))
	{
		CancelCalcul = FALSE;
		mapping_with_fed(2);
	}
	else if(!strcmp(name , "FEDRadicalMapping"))
	{
		CancelCalcul = FALSE;
		mapping_with_fed(1);
	}
	else if(!strcmp(name , "CubeComputeLaplacian")) 
	{
			Grid* lapGrid = get_grid_laplacian(grid,2);
			if(lapGrid)
			{
				free_grid(grid);
				grid = lapGrid;
				TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
				limits = grid->limits;
				create_iso_orbitals();
			}
	}
	else if(!strcmp(name , "CubeComputeNormGradient")) 
	{
			Grid* gradGrid = get_grid_norm_gradient(grid,2);
			if(gradGrid)
			{
				free_grid(grid);
				grid = gradGrid;
				TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
				limits = grid->limits;
				create_iso_orbitals();
			}
	}
	else if(!strcmp(name , "ContoursFirst"))
		create_contours("Contours in a plane perpendicular to first direction",0);
	else if(!strcmp(name , "ContoursSecond"))
		create_contours("Contours in a plane perpendicular to second direction",1);
	else if(!strcmp(name , "ContoursThird"))
		create_contours("Contours in a plane perpendicular to third direction",2);
	else if(!strcmp(name , "ContoursOther"))
	{
	  	create_planeGrid_center_vector("Contours");
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "ContoursDelete"))
	{
		free_contours_all();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "PlanesColorCodedFirst"))
		create_maps("Plane perpendicular to first direction",0);
	else if(!strcmp(name , "PlanesColorCodedSecond"))
		create_maps("Plane perpendicular to second direction",1);
	else if(!strcmp(name , "PlanesColorCodedThird"))
		create_maps("Plane perpendicular to third direction",2);
	else if(!strcmp(name , "PlanesColorCodedOther"))
	{
	  	create_planeGrid_center_vector("Maps");
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "PlanesColorCodedDelete"))
	{
		free_planes_mapped_all();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "SurfacesResetIsovalue"))
	{
		CancelCalcul = FALSE;
		newSurface = FALSE;
		create_iso_orbitals();
	}
	else if(!strcmp(name , "SurfacesNew"))
	{
		CancelCalcul = FALSE;
		newSurface = TRUE;
		create_iso_orbitals();
	}
	else if(!strcmp(name , "SurfacesDelete"))
	{
			free_surfaces_all();
			glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "Rings3"))
	{
		build_rings(3);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "Rings4"))
	{
		build_rings(4);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "Rings5"))
	{
		build_rings(5);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "Rings6"))
	{
		build_rings(6);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "Rings7"))
	{
		build_rings(7);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "Rings8"))
	{
		build_rings(8);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "RingsDelete"))
	{
		delete_rings_all();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "RenderOptimal")) set_optimal_view();
	else if(!strcmp(name , "SetCamera")) set_camera();
	else if(!strcmp(name , "SetLigthPositions")) set_light_positions("Set Light Positions");
	else if(!strcmp(name , "SetSurfaceColors")) set_colors_surfaces("Set Surface Colors");
	else if(!strcmp(name , "SetDipole"))
	{
		GtkWidget* win = set_dipole_dialog();
		RebuildGeom = TRUE;
  		gtk_window_set_transient_for(GTK_WINDOW(win),GTK_WINDOW(PrincipalWindow));
	}
	else if(!strcmp(name , "SetDipoleDensity"))
	{
		RebuildGeom = TRUE;
		compute_total_dipole();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "SetMultipleBonds"))
	{
		RebuildGeom = TRUE;
		buildMultipleBonds();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "SetAllBonds"))
	{
		RebuildGeom = TRUE;
		buildBondsOrb();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "SetPropertiesOfAtoms")) create_table_prop();
	else if(!strcmp(name , "SetHydrogenBondsParameters"))
	{
		RebuildGeom = TRUE;
		set_HBonds_dialog (PrincipalWindow);
	}
	else if(!strcmp(name , "SetXYZAxesProperties"))
	{
		RebuildGeom = TRUE;
		set_axis_dialog();
	}
	else if(!strcmp(name , "SetPrincipalAxesProperties"))
	{
		RebuildGeom = TRUE;
		set_principal_axisGL_dialog();
	}
	else if(!strcmp(name , "SetPovrayBackGround")) createPovrayOptionsWindow(PrincipalWindow);
	else if(!strcmp(name , "SetColorMap")) createColorMapOptionsWindow(PrincipalWindow);
	else if(!strcmp(name , "SetTitle")) set_title_dlg();
	else if(!strcmp(name , "SetScaleBallStick")) set_scale_ball_stick_dlg();
	else if(!strcmp(name , "ScreenCaptureJPG"))
	{
 		GtkWidget* chooser = file_chooser_save(save_jpeg_file,"Save image in jpg file format",GABEDIT_TYPEFILE_JPEG,GABEDIT_TYPEWIN_ORB);
		fit_windows_position(PrincipalWindow, chooser);
	}
	else if(!strcmp(name , "ScreenCapturePPM"))
	{
 		GtkWidget* chooser = file_chooser_save(save_ppm_file,"Save image in ppm file format",GABEDIT_TYPEFILE_PPM,GABEDIT_TYPEWIN_ORB);
		fit_windows_position(PrincipalWindow, chooser);
	}
	else if(!strcmp(name , "ScreenCaptureBMP"))
	{
 		GtkWidget* chooser = file_chooser_save(save_bmp_file,"Save image in bmp file format",GABEDIT_TYPEFILE_BMP,GABEDIT_TYPEWIN_ORB);
		fit_windows_position(PrincipalWindow, chooser);
	}
	else if(!strcmp(name , "ScreenCapturePNG"))
	{
 		GtkWidget* chooser = file_chooser_save(save_png_file,"Save image in png file format",GABEDIT_TYPEFILE_PNG,GABEDIT_TYPEWIN_ORB);
		fit_windows_position(PrincipalWindow, chooser);
	}
	else if(!strcmp(name , "ScreenCapturePNGNoBackGround"))
	{
 		GtkWidget* chooser = file_chooser_save(save_png_no_background_file,"Save image in png file format",GABEDIT_TYPEFILE_PNG,GABEDIT_TYPEWIN_ORB);
		fit_windows_position(PrincipalWindow, chooser);
	}
	else if(!strcmp(name , "ScreenCapturePS"))
	{
 		GtkWidget* chooser = file_chooser_save(save_ps_file,"Save image in ps file format",GABEDIT_TYPEFILE_PS,GABEDIT_TYPEWIN_ORB);
		fit_windows_position(PrincipalWindow, chooser);
	}
	else if(!strcmp(name , "ScreenCaptureClipBoard"))
	{
		copy_to_clipboard();
	}
	else if(!strcmp(name , "ExportPovray")) 
	{
		/* create_save_povray_orb(PrincipalWindow);*/
		exportPOVDlg(PrincipalWindow);
	}
	else if(!strcmp(name , "ExportEPS")) export_scene(PrincipalWindow,"eps");
	else if(!strcmp(name , "ExportPS")) export_scene(PrincipalWindow,"ps");
	else if(!strcmp(name , "ExportPDF")) export_scene(PrincipalWindow,"pdf");
	else if(!strcmp(name , "ExportSVG")) export_scene(PrincipalWindow,"svg");
	else if(!strcmp(name , "AnimationVibration")) vibrationDlg();
	else if(!strcmp(name , "AnimationGeometryConvergence")) geometryConvergenceDlg();
	else if(!strcmp(name , "AnimationMD")) geometriesMDDlg();
	else if(!strcmp(name , "AnimationRotation")) animationRotationDlg();
	else if(!strcmp(name , "AnimationContours")) animationContoursDlg();
	else if(!strcmp(name , "AnimationPlanesColorcoded")) animationPlanesMappedDlg();
	else if(!strcmp(name , "AnimationIsosurface")) animationIsoSurfaceDlg();

	else if(!strcmp(name , "Close")) 
	{
		gtk_widget_hide(PrincipalWindow);
		/* close_window_orb(NULL,NULL);*/
	}
	if(strstr(name,"Geometry")) destroy_win_list();
	if(strstr(name,"CubeLoad")) destroy_win_list();
}
/*********************************************************************************************************************/
static GtkActionEntry gtkActionEntries[] =
{
	{"Geometry",     NULL, "_Geometry"},
	{"GeometryAuto", NULL, "Read (Auto)", NULL, "Read the geometry from file", G_CALLBACK (activate_action) },
	{"GeometryXYZ", NULL, "Read the geometry from a _xyz file", NULL, "Read the geometry from a xyz file", G_CALLBACK (activate_action) },
	{"GeometryPDB", GABEDIT_STOCK_PDB, "Read the geometry from a _pdb file", NULL, "Read the geometry from a pdb file", G_CALLBACK (activate_action) },
	{"GeometryHIN", NULL, "Read the geometry from a _hyperchem file", NULL, "Read the geometry from a hyperchem file", G_CALLBACK (activate_action) },
	{"GeometryOpenBabel", GABEDIT_STOCK_OPEN_BABEL, "Other format (using Open _Babel)", NULL, "Other format (using Open _Babel)", G_CALLBACK (activate_action) },
	{"GeometryDalton",     GABEDIT_STOCK_DALTON, "Geometry _Dalton"},
	{"GeometryDaltonFirst", GABEDIT_STOCK_DALTON, "Read the _first geometry from a Dalton output log file", 
		NULL, "Read the first geometry from a Dalton output file", G_CALLBACK (activate_action) },
	{"GeometryDaltonLast", GABEDIT_STOCK_DALTON, "Read the _last geometry from a Dalton output log file", 
		NULL, "Read the last geometry from a Dalton output file", G_CALLBACK (activate_action) },
	{"GeometryGamess",     GABEDIT_STOCK_GAMESS, "Geometry Ga_mess"},
	{"GeometryGamessFirst", GABEDIT_STOCK_GAMESS, "Read the _first geometry from a Gamess output log file", 
		NULL, "Read the first geometry from a Gamess output file", G_CALLBACK (activate_action) },
	{"GeometryGamessLast", GABEDIT_STOCK_GAMESS, "Read the _last geometry from a Gamess output log file", 
		NULL, "Read the last geometry from a Gamess output file", G_CALLBACK (activate_action) },
	{"GeometryGaussian",     GABEDIT_STOCK_GAUSSIAN, "Geometry _Gaussian"},
	{"GeometryGaussianFirst", GABEDIT_STOCK_GAUSSIAN, "Read the _first geometry from a gaussian log file", 
		NULL, "Read the first geometry from a gaussian log file", G_CALLBACK (activate_action) },
	{"GeometryGaussianLast", GABEDIT_STOCK_GAUSSIAN, "Read the _last geometry from a gaussian file", 
		NULL, "Read the last geometry from a gaussian log file", G_CALLBACK (activate_action) },
	{"GeometryMolcas",     GABEDIT_STOCK_MOLCAS, "Geometry Mol_cas"},
	{"GeometryMolcasFirst", GABEDIT_STOCK_MOLCAS, "Read the _first geometry from a molcas output file", 
		NULL, "Read the first geometry from a molcas output file", G_CALLBACK (activate_action) },
	{"GeometryMolcasLast", GABEDIT_STOCK_MOLCAS, "Read the _last geometry from a molcas output file", 
		NULL, "Read the last geometry from a molcas output file", G_CALLBACK (activate_action) },
	{"GeometryMolpro",     GABEDIT_STOCK_MOLPRO, "Geometry Mol_pro"},
	{"GeometryMolproFirst", GABEDIT_STOCK_MOLPRO, "Read the _first geometry from a molpro output file", 
		NULL, "Read the first geometry from a molpro output file", G_CALLBACK (activate_action) },
	{"GeometryMolproLast", GABEDIT_STOCK_MOLPRO, "Read the _last geometry from a molpro output file", 
		NULL, "Read the last geometry from a molpro output file", G_CALLBACK (activate_action) },
	{"GeometryMopac",     GABEDIT_STOCK_MOPAC, "Geometry _Mopac"},
	{"GeometryMopacOutFirst", GABEDIT_STOCK_MOPAC, "Read the _first geometry from a Mopac output file", 
		NULL, "Read the first geometry from a Mopac output file", G_CALLBACK (activate_action) },
	{"GeometryMopacOutLast", GABEDIT_STOCK_MOPAC, "Read the _last geometry from a Mopac output file", 
		NULL, "Read the last geometry from a Mopac-Chem output file", G_CALLBACK (activate_action) },
	{"GeometryMopacAuxFirst", GABEDIT_STOCK_MOPAC, "Read the _first geometry from a Mopac aux file", 
		NULL, "Read the first geometry from a Mopac aux file", G_CALLBACK (activate_action) },
	{"GeometryMopacAuxLast", GABEDIT_STOCK_MOPAC, "Read the _last geometry from a Mopac aux file", 
		NULL, "Read the last geometry from a Mopac-Chem aux file", G_CALLBACK (activate_action) },
	{"GeometryMPQC",     GABEDIT_STOCK_MPQC, "Geometry MP_QC"},
	{"GeometryMPQCFirst", GABEDIT_STOCK_MPQC, "Read the _first geometry from a MPQC output file", 
		NULL, "Read the first geometry from a MPQC output file", G_CALLBACK (activate_action) },
	{"GeometryMPQCLast", GABEDIT_STOCK_MPQC, "Read the _last geometry from a MPQC output file", 
		NULL, "Read the last geometry from a MPQC output file", G_CALLBACK (activate_action) },
	{"GeometryOrca",     GABEDIT_STOCK_ORCA, "Geometry _Orca"},
	{"GeometryOrcaFirst", GABEDIT_STOCK_ORCA, "Read the _first geometry from a Orca output log file", 
		NULL, "Read the first geometry from a Orca output file", G_CALLBACK (activate_action) },
	{"GeometryOrcaLast", GABEDIT_STOCK_ORCA, "Read the _last geometry from a ORCA output log file", 
		NULL, "Read the last geometry from a Orca output file", G_CALLBACK (activate_action) },
	{"GeometryPCGamess",     GABEDIT_STOCK_PCGAMESS, "Geometry _PCGamess"},
	{"GeometryPCGamessFirst", GABEDIT_STOCK_PCGAMESS, "Read the _first geometry from a PCGamess output log file", 
		NULL, "Read the first geometry from a PCGamess output file", G_CALLBACK (activate_action) },
	{"GeometryPCGamessLast", GABEDIT_STOCK_PCGAMESS, "Read the _last geometry from a PCGamess output log file", 
		NULL, "Read the last geometry from a PCGamess output file", G_CALLBACK (activate_action) },
	{"GeometryQChem",     GABEDIT_STOCK_QCHEM, "Geometry Q-_Chem"},
	{"GeometryQChemFirst", GABEDIT_STOCK_QCHEM, "Read the _first geometry from a Q-Chem output file", 
		NULL, "Read the first geometry from a Q-Chem output file", G_CALLBACK (activate_action) },
	{"GeometryQChemLast", GABEDIT_STOCK_QCHEM, "Read the _last geometry from a Q-Chem output file", 
		NULL, "Read the last geometry from a Q-Chem output file", G_CALLBACK (activate_action) },
	{"GeometryGabedit", GABEDIT_STOCK_GABEDIT, "Read from a G_abedit file", 
		NULL, "Read the geometry from a Gabedit file", G_CALLBACK (activate_action) },
	{"GeometryMolden", GABEDIT_STOCK_MOLDEN, "Read from a Mol_den file", 
		NULL, "Read the from a Molden file", G_CALLBACK (activate_action) },
	{"Orbitals",     NULL, "_Orbitals"},
	{"OrbitalsAuto", NULL, "Read geometry and orbitals (_Auto)", 
		NULL, "Read geometry and orbitals from a Gamess output file", G_CALLBACK (activate_action) },
	/*
	{"OrbitalsDalton", GABEDIT_STOCK_DALTON, "Read geometry and orbitals from a _Dalton output file", 
		NULL, "Read geometry and orbitals from a Dalton output file", G_CALLBACK (activate_action) },
		*/
	{"OrbitalsGamess", GABEDIT_STOCK_GAMESS, "Read geometry and orbitals from a _Gamess output file", 
		NULL, "Read geometry and orbitals from a Gamess output file", G_CALLBACK (activate_action) },
	{"OrbitalsGaussian", GABEDIT_STOCK_GAUSSIAN, "Read geometry and orbitals from a _Gaussian log file", 
		NULL, "Read geometry and orbitals from a Gaussian log file", G_CALLBACK (activate_action) },
	{"OrbitalsMolpro", GABEDIT_STOCK_MOLPRO, "Read geometry and orbitals from a Mol_pro output file", 
		NULL, "Read geometry and orbitals from a Molpro output file", G_CALLBACK (activate_action) },
	{"OrbitalsOrca", GABEDIT_STOCK_ORCA, "Read geometry and orbitals from a _Orca output file", 
		NULL, "Read geometry and orbitals from a Orca output files", G_CALLBACK (activate_action) },
	{"OrbitalsOrca2mkl", GABEDIT_STOCK_ORCA, "Read geometry and orbitals from a _Orca files using orca_2mkl", 
		NULL, "Read geometry and orbitals from a Orca output files", G_CALLBACK (activate_action) },
	{"OrbitalsPCGamess", GABEDIT_STOCK_PCGAMESS, "Read geometry and orbitals from a _PCGamess output file", 
		NULL, "Read geometry and orbitals from a PCGamess output file", G_CALLBACK (activate_action) },
	{"OrbitalsQChem", GABEDIT_STOCK_QCHEM, "Read geometry and orbitals from a Q-_Chem output file", 
		NULL, "Read geometry and orbitals from a Q-Chem output file", G_CALLBACK (activate_action) },
	{"OrbitalsMopac", GABEDIT_STOCK_MOPAC, "Read geometry and orbitals from a _Mopac aux file", 
		NULL, "Read geometry and orbitals from a Mopac aux file", G_CALLBACK (activate_action) },
	{"OrbitalsGabeditRead", GABEDIT_STOCK_GABEDIT, "Read geometry and orbitals from a G_abedit file", 
		NULL, "Read geometry and orbitals from a Gabedit file", G_CALLBACK (activate_action) },
	{"OrbitalsMolden", GABEDIT_STOCK_MOLDEN, "Read geometry and orbitals from a Mol_den file", 
		NULL, "Read geometry and orbitals from a Molden file", G_CALLBACK (activate_action) },
	{"OrbitalsGabeditSave", GABEDIT_STOCK_SAVE, "Save in a G_abedit file", 
		NULL, "Save in Gabedit file", G_CALLBACK (activate_action) },
	{"OrbitalsSelection", GABEDIT_STOCK_SELECT_ALL, "_Selection", 
		NULL, "Select an orbital", G_CALLBACK (activate_action) },
	{"OrbitalsCapture", GABEDIT_STOCK_SELECT_ALL, "_Slideshow", NULL, "Slideshow", G_CALLBACK (activate_action) },
	{"OrbitalsCoulomb", NULL, "_Coulomb integral", NULL, "Coulomb", G_CALLBACK (activate_action) },
	{"OrbitalsTransition", NULL, "_Transition matrix elements", NULL, "TM", G_CALLBACK (activate_action) },
	{"OrbitalsOverlap", NULL, "Compute _overlap matrix", NULL, "Overlap", G_CALLBACK (activate_action) },
	{"Cube",     NULL, "_Cube&Grid"},

	{"CubeLoadGaussian",     GABEDIT_STOCK_GAUSSIAN, "Load _Gaussian cube"},
	{"CubeLoadGaussianOrbitals", NULL, "_Orbitals file", 
		NULL, "Read cube from a Gaussian cube orbitals file", G_CALLBACK (activate_action) },
	{"CubeLoadGaussianDensity", NULL, "_Density only file", 
		NULL, "Read a Gaussian cube file contain density only", G_CALLBACK (activate_action) },
	{"CubeLoadGaussianDensityGradient", NULL, "Density and _Gradient file", 
		NULL, "Read a Gaussian cube file contain density and gradient", G_CALLBACK (activate_action) },
	{"CubeLoadGaussianLaplacian", NULL, "_Laplacian file", 
		NULL, "Read a Gaussian cube file contain laplacian", G_CALLBACK (activate_action) },
	{"CubeLoadGaussianNormGradient", NULL, "_Norm gradient file", 
		NULL, "Read a Gaussian cube file contain the norm of gradient", G_CALLBACK (activate_action) },
	{"CubeLoadGaussianPotential", NULL, "_Potential file", 
		NULL, "Read a Gaussian cube file contain a potential", G_CALLBACK (activate_action) },
	{"CubeLoadMolpro",     GABEDIT_STOCK_MOLPRO, "Load Mol_pro cube"},
	{"CubeLoadMolproOrbitals",     NULL, "Load Molpro cube _orbitals"},
	{"CubeLoadMolproOrbitalsOne", NULL, "_One Orbitale", 
		NULL, "Read a Molpro cube file contain one orbital", G_CALLBACK (activate_action) },
	{"CubeLoadMolproOrbitalsSeveral", NULL, "_Several Orbitales", 
		NULL, "Read a Molpro cube file contain several orbitales", G_CALLBACK (activate_action) },
	{"CubeLoadMolproDensityOne", NULL, "Contain the _Density only", 
		NULL, "Read a Molpro cube file contain the density", G_CALLBACK (activate_action) },
	{"CubeLoadMolproDensityGradient", NULL, "Contain the Density and the _Gradient", 
		NULL, "Read a Molpro cube file contain the density and the gradient of density", G_CALLBACK (activate_action) },
	{"CubeLoadMolproDensityGradientLaplacian",  NULL, "Density , Gradient and _Laplacian file"},
	{"CubeLoadMolproDensityGradientLaplacianDensity", NULL, "Load _Density", 
		NULL, "Read the density from a Molpro cube file contain density, gradient and laplacian", G_CALLBACK (activate_action) },
	{"CubeLoadMolproDensityGradientLaplacianLaplacian", NULL, "Load _Laplacian", 
		NULL, "Read the laplacian from a Molpro cube file contain density, gradient and laplacian", G_CALLBACK (activate_action) },
	{"CubeLoadAdf",     GABEDIT_STOCK_ADF, "Load _Adf tape 41"},
	{"CubeLoadAdfOrbitals", NULL, "_Orbitals", NULL, "Read the orbitals from a ADF tape 41 file", G_CALLBACK (activate_action) },
	{"CubeLoadAdfDensity", NULL, "_Density", NULL, "Read the density from a ADF tape 41 file", G_CALLBACK (activate_action) },

	{"CubeLoadMolcas",     GABEDIT_STOCK_MOLCAS, "Load Mol_cas"},
	{"CubeLoadMolcasGridOrbitals", NULL, "_Orbitals", NULL, "Read the orbitals from a Grid ascii file", G_CALLBACK (activate_action) },
	{"CubeLoadMolcasGridDensity", NULL, "_Density", NULL, "Read the density from a Grid ascii file", G_CALLBACK (activate_action) },
	{"CubeLoadQChem", GABEDIT_STOCK_QCHEM, "Load _Q-Chem grid file", NULL, "Read a Q-Chem cube file", G_CALLBACK (activate_action) },
	{"CubeLoadGabeditRead", GABEDIT_STOCK_GABEDIT, "Load G_abedit cube file", NULL, "Read a Gabedit cube file", G_CALLBACK (activate_action) },
	{"CubeLoadGabeditSave", GABEDIT_STOCK_SAVE, "_Save", NULL, "Save in a Gabedit cube file", G_CALLBACK (activate_action) },
	{"CubeComputeLaplacian", NULL, "Compute _laplacian", NULL, "Compute laplacian", G_CALLBACK (activate_action) },
	{"CubeComputeNormGradient", NULL, "Compute the norm of the _gradient", NULL, "Compute the norm of the _gradient", G_CALLBACK (activate_action) },
	{"CubeSubtract", NULL, "Su_btract", NULL, "Subtract", G_CALLBACK (activate_action) },
	{"CubeScale", NULL, "Scal_e", NULL, "Scale", G_CALLBACK (activate_action) },
	{"CubeSquare", NULL, "S_quare", NULL, "Square", G_CALLBACK (activate_action) },
	{"CubeRestriction", NULL, "_Restriction", NULL, "Restriction", G_CALLBACK (activate_action) },
	{"CubeAIMChargesNearGrid", NULL, "AIM Charges[W. Tang et al J. Phys. Cond.. Matt. 21, 084204(09)]", NULL, "AIM Charges", G_CALLBACK (activate_action) },
	{"CubeAIMChargesOnGrid", NULL, "AIM Charges[OnGrid]", NULL, "AIM Charges on grid", G_CALLBACK (activate_action) },
	{"CubeColorMapping", NULL, "_Color Mapping", NULL, "Color Mapping", G_CALLBACK (activate_action) },

	{"Density",     NULL, "_Density"},
	{"DensityElectronic", NULL, "_Electronic", NULL, "Compute and draw electronic density", G_CALLBACK (activate_action) },
	{"DensityBonds", NULL, "_Bonds", NULL, "Compute and draw bonds (electronic-atomics)", G_CALLBACK (activate_action) },
	{"DensitySpin", NULL, "_Spin", NULL, "Compute and draw spin density", G_CALLBACK (activate_action) },
	{"DensityAtomics", NULL, "_Atomic", NULL, "Compute and draw electronic density of atoms", G_CALLBACK (activate_action) },

	{"ELF",     NULL, "_ELF"},
	{"ELFBecke", NULL, "Compute _Becke Electron Localization Function[see JCP,92(1990)5397]", NULL, "Compute Becke Electron Localization Function", G_CALLBACK (activate_action) },
	{"ELFSavin", NULL, "Compute _Savin Electron Localization Function[see Can.J.Chem.,74(1996)1088]", NULL, "Compute Savin Electron Localization Function", G_CALLBACK (activate_action) },
	{"ELFSavinAttractors", NULL, "Compute _Savin ELF + Attractors", NULL, "Compute Savin ELF+Attractors", G_CALLBACK (activate_action) },
	{"Fukui",     NULL, "_Fukui"},
	{"FEDElectrophilic", NULL, "Compute Frontier MO _electrophilic susceptibility", NULL, "Compute Frontier MO electrophilic susceptibility", G_CALLBACK (activate_action) },
	{"FEDNucleophilic", NULL, "Compute Frontier MO _nucleophilic susceptibility", NULL, "Compute Frontier MO nucleophilic susceptibility", G_CALLBACK (activate_action) },
	{"FEDRadical", NULL, "Compute Frontier MO _radical susceptibility", NULL, "Compute Frontier MO radical susceptibility", G_CALLBACK (activate_action) },
	{"FEDSetAlpha", NULL, "Set the value of _alpha parameter", NULL, "Set the value of _alpha parameter", G_CALLBACK (activate_action) },

	{"SAS",     NULL, "_SAS"},
	{"SASCompute", NULL, "_Solvent Accessible Surface", NULL, "Compute and draw Solvent Accessible Surface", G_CALLBACK (activate_action) },
	{"SASMappCompute", NULL, "Solvent Accessible Surface _mapped by MEP from charges", NULL, "Compute and draw Solvent Accessible Surface  mapped by MEP from charges", G_CALLBACK (activate_action) },
	{"MEP",     NULL, "_MEP"},
	{"MEPMapping",     NULL, "_Mapped the current grid"},
	{"MEPOrbitals",     NULL, "Using _Molecular Orbitals"},
	{"MEPGrid",     NULL, "Using Current _Grid"},

	{"MEPMappingMG", NULL, "MEP by solving Poisson Equation using _Multigrid method", NULL, "MEP by solving Poisson Equation using Multigrid method", G_CALLBACK (activate_action) },
	{"MEPMappingCG", NULL, "MEP by solving Poisson Equation using _Congugate Gradient method", NULL, "MEP by solving Poisson Equation using Congugate Gradient method", G_CALLBACK (activate_action) },
	{"MEPMappingMultipol", NULL, "MEP using Multipole", NULL, "MEP using Multipole", G_CALLBACK (activate_action) },
	{"MEPMappingCharges", NULL, "MEP using partial charges", NULL, "MEP using partial charges", G_CALLBACK (activate_action) },
	{"FEDElectrophilicMapping", NULL, "Mapping by the _electrophilic susceptibility", NULL, "Mapping by the _electrophilic susceptibility", G_CALLBACK (activate_action) },
	{"FEDNucleophilicMapping", NULL, "Mapping by the _nucleophilic susceptibility", NULL, "Mapping by the _nucleophilic susceptibility", G_CALLBACK (activate_action) },
	{"FEDRadicalMapping", NULL, "Mapping by the _radical susceptibility", NULL, "Mapping by the _radical susceptibility", G_CALLBACK (activate_action) },

	{"MEPOrbitalsMG", NULL, "MEP by solving Poisson Equation using _Multigrid method", NULL, "MEP by solving Poisson Equation using Multigrid method", G_CALLBACK (activate_action) },
	{"MEPOrbitalsCG", NULL, "MEP by solving Poisson Equation using _Congugate Gradient method", NULL, "MEP by solving Poisson Equation using Congugate Gradient method", G_CALLBACK (activate_action) },
	{"MEPOrbitalsMultipol", NULL, "MEP using Multipole", NULL, "MEP using Multipole", G_CALLBACK (activate_action) },

	{"MEPGridMG", NULL, "MEP by solving Poisson Equation using _Multigrid method", NULL, "MEP by solving Poisson Equation using Multigrid method", G_CALLBACK (activate_action) },
	{"MEPGridCG", NULL, "MEP by solving Poisson Equation using _Congugate Gradient method", NULL, "MEP by solving Poisson Equation using Congugate Gradient method", G_CALLBACK (activate_action) },
	{"MEPGridMultipol", NULL, "MEP using Multipole", NULL, "MEP using Multipole", G_CALLBACK (activate_action) },
	{"MEPFromCharges", NULL, "MEP using partial _charges", NULL, "MEP using partial charges", G_CALLBACK (activate_action) },

	{"Contours",     NULL, "Co_ntours"},
	{"ContoursFirst", NULL, "plane perpendicular to the _first direction", 
		NULL, "contours in a plane perpendicular to first direction", G_CALLBACK (activate_action) },
	{"ContoursSecond", NULL, "plane perpendicular to the _second direction", 
		NULL, "contours in a plane perpendicular to second direction", G_CALLBACK (activate_action) },
	{"ContoursThird", NULL, "plane perpendicular to the _third direction", 
		NULL, "contours in a plane perpendicular to the third direction", G_CALLBACK (activate_action) },
	{"ContoursOther", NULL, "_Others plane", NULL, "contours in a any other plane", G_CALLBACK (activate_action) },
	{"ContoursDelete", NULL, "_Delete all", NULL, "delete all contours", G_CALLBACK (activate_action) },

	{"PlanesColorCoded",     NULL, "_Planes colorcoded"},
	{"PlanesColorCodedFirst", NULL, "plane perpendicular to the _first direction", 
		NULL, "Color-coded plane, plane perpendicular to first direction", G_CALLBACK (activate_action) },
	{"PlanesColorCodedSecond", NULL, "plane perpendicular to the _second direction", 
		NULL, "Color-coded plane, plane perpendicular to second direction", G_CALLBACK (activate_action) },
	{"PlanesColorCodedThird", NULL, "plane perpendicular to the _third direction", 
		NULL, "Color-coded plane, plane perpendicular to third direction", G_CALLBACK (activate_action) },
	{"PlanesColorCodedOther", NULL, "_Other plane", 
		NULL, "any other Color-coded plane", G_CALLBACK (activate_action) },
	{"PlanesColorCodedDelete", NULL, "_Delete all", 
		NULL, "delete all color-coded planes", G_CALLBACK (activate_action) },
	{"Surfaces",     NULL, "_Surfaces"},
	{"SurfacesResetIsovalue", NULL, "re_set isovalue", NULL, "re_set the isovalue for the last surface", G_CALLBACK (activate_action) },
	{"SurfacesNew", NULL, "_new", NULL, "new surface", G_CALLBACK (activate_action) },
	{"SurfacesDelete", NULL, "_delete all", NULL, "delete all surfaces", G_CALLBACK (activate_action) },
	{"Rings",     NULL, "_Rings"},
	{"Rings3", NULL, "Find and show _triangles", NULL, "Find and show triangles", G_CALLBACK (activate_action) },
	{"Rings4", NULL, "Find and show _squares & rectangles", NULL, "Find and show squares & rectangles", G_CALLBACK (activate_action) },
	{"Rings5", NULL, "Find and show _pentagons", NULL, "Find and show pentagons", G_CALLBACK (activate_action) },
	{"Rings6", NULL, "Find and show he_xagons", NULL, "Find and show hexagons", G_CALLBACK (activate_action) },
	{"Rings7", NULL, "Find and show he_ptagons", NULL, "Find and show heptagons", G_CALLBACK (activate_action) },
	{"Rings8", NULL, "Find and show _octagons", NULL, "Find and show octagons", G_CALLBACK (activate_action) },
	{"RingsDelete", NULL, "_delete all", NULL, "delete all rings", G_CALLBACK (activate_action) },
	{"Render",     NULL, "_Render"},
	{"RenderGeometry",     NULL, "_Geometry"},
	{"RenderLabel",     NULL, "Labe_l"},
	{"RenderSurface",     NULL, "_Surface"},
	{"RenderSurfacePositive",     NULL, "_Positive surface"},
	{"RenderSurfaceNegative",     NULL, "_Negative surface"},
	{"RenderBackGround",     NULL, "_BackGround"},
	{"RenderLight",     NULL, "_Light"},
	{"RenderOptimal", GABEDIT_STOCK_O, "_Optimal", NULL, "Optimal camera", G_CALLBACK (activate_action) },
	{"Set",     NULL, "_Set"},
	{"Operation",     NULL, "_Operation"},
	{"SetCamera", GABEDIT_STOCK_CAMERA, "_Camera", NULL, "set the camera", G_CALLBACK (activate_action) },
	{"SetLigthPositions", NULL, "_Ligth positions", NULL, "set Ligth positions", G_CALLBACK (activate_action) },
	{"SetSurfaceColors", NULL, "_Surface colors", NULL, "set surface colors", G_CALLBACK (activate_action) },
	{"SetDipole", NULL, "_Dipole", NULL, "set dipole", G_CALLBACK (activate_action) },
	{"SetDipoleDensity", NULL, "_Compute Dipole from density", NULL, "Compute Dipole from density", G_CALLBACK (activate_action) },
	{"SetAllBonds", NULL, "Compute all _bonds", NULL, "Compute all bonds", G_CALLBACK (activate_action) },
	{"SetMultipleBonds", NULL, "Compute _multiple bonds", NULL, "Compute multiple bonds", G_CALLBACK (activate_action) },
	{"SetPropertiesOfAtoms", NULL, "P_roperties of atoms", NULL, "set the properties of atoms", G_CALLBACK (activate_action) },
	{"SetHydrogenBondsParameters", NULL, "_Hydrogen bonds parameters", NULL, "set the Hydrogen bonds parameters", G_CALLBACK (activate_action) },
	{"SetXYZAxesProperties", NULL, "XYZ _Axes properties", NULL, "set the properties of the XYZ Axes", G_CALLBACK (activate_action) },
	{"SetPrincipalAxesProperties", NULL, "_Principal Axes properties", NULL, "set the properties of the principal Axes", G_CALLBACK (activate_action) },
	{"SetPovrayBackGround", NULL, "_Povray background", NULL, "set the background for the Povray file", G_CALLBACK (activate_action) },
	{"SetColorMap", NULL, "Color _mapping", NULL, "set the color mapping options", G_CALLBACK (activate_action) },
	{"SetTitle", NULL, "_Title", NULL, "Set title", G_CALLBACK (activate_action) },
	{"SetScaleBallStick", NULL, "_Scale ball&stick", NULL, "Scale ball&stick", G_CALLBACK (activate_action) },
	{"ScreenCapture",     NULL, "Screen Ca_pture"},
	{"ScreenCaptureJPG", NULL, "_JPG format", NULL, "save image in a JPG file", G_CALLBACK (activate_action) },
	{"ScreenCapturePPM", NULL, "_PPM format", NULL, "save image in a PPM file", G_CALLBACK (activate_action) },
	{"ScreenCaptureBMP", NULL, "_BMP format", NULL, "save image in a BMP file", G_CALLBACK (activate_action) },
	{"ScreenCapturePNG", NULL, "_PNG format", NULL, "save image in a PNG file", G_CALLBACK (activate_action) },
	{"ScreenCapturePNGNoBackGround", NULL, "_PNG format(tansparent background)", NULL, "save image in a PNG file without background", G_CALLBACK (activate_action) },
	{"ScreenCapturePS", NULL, "P_S format", NULL, "save image in a PS file", G_CALLBACK (activate_action) },
	{"ScreenCaptureClipBoard", NULL, "_Copy to clipboard (Ctrl C or Alt C)", NULL, "copy to clipboard", G_CALLBACK (activate_action) },

	{"Export",     NULL, "_Export"},
	{"ExportPovray", NULL, "_Povray", NULL, "export in a povray file", G_CALLBACK (activate_action) },
	{"ExportEPS", NULL, "_EPS", NULL, "export in a eps file", G_CALLBACK (activate_action) },
	{"ExportPS", NULL, "_PS", NULL, "export in a ps file", G_CALLBACK (activate_action) },
	{"ExportPDF", NULL, "_PDF", NULL, "export in a pdf file", G_CALLBACK (activate_action) },
	{"ExportSVG", NULL, "_SVG", NULL, "export in a svg file", G_CALLBACK (activate_action) },

	{"Animation",     NULL, "_Animation"},
	{"AnimationVibration", NULL, "_Vibration", NULL, "Vibration", G_CALLBACK (activate_action) },
	{"AnimationGeometryConvergence", NULL, "_several geometries (Convergence/IRC)", NULL, "several geometries (Convergence/IRC)", G_CALLBACK (activate_action) },
	{"AnimationMD", NULL, "_Molecular dynamics trajectory", NULL, "Molecular dynamics trajectory", G_CALLBACK (activate_action) },
	{"AnimationRotation", NULL, "_Rotation", NULL, "Animation of the rotation", G_CALLBACK (activate_action) },
	{"AnimationContours", NULL, "_Contours", NULL, "Animation of the contours", G_CALLBACK (activate_action) },
	{"AnimationPlanesColorcoded", NULL, "_Planes colorcoded", NULL, "Animation of the color-coded planes", G_CALLBACK (activate_action) },
	{"AnimationIsosurface", NULL, "_Isosurface", NULL, "Animation of the surfaces", G_CALLBACK (activate_action) },

	{"View",     NULL, "_View"},

	{"Close", GABEDIT_STOCK_CLOSE, "_Close", NULL, "Close this window", G_CALLBACK (activate_action) },

};
static guint numberOfGtkActionEntries = G_N_ELEMENTS (gtkActionEntries);
/*********************************************************************************************************************/
static void toggle_action (GtkAction *action)
{
	const gchar *name = gtk_action_get_name (action);
	if(!strcmp(name,"RenderSurfaceTransparency"))
	{
		if(TypeBlend==GABEDIT_BLEND_YES)
			TypeBlend = GABEDIT_BLEND_NO;
		else
			TypeBlend = GABEDIT_BLEND_YES;
		RebuildSurf = TRUE;
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLightOnOff1"))
	{
		set_light_on_off(0);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLightOnOff2"))
	{
		set_light_on_off(1);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLightOnOff3"))
	{
		set_light_on_off(2);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderDipole"))
	{
		ShowDipoleOrb = !ShowDipoleOrb;
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderHydrogenBonds"))
	{
		ShowHBondOrb = !ShowHBondOrb;
		buildHBonds();
		RebuildGeom = TRUE;
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderHydrogenAtoms"))
	{
		ShowHAtomOrb = !ShowHAtomOrb;
		RebuildGeom = TRUE;
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderMultiBonds"))
	{
		ShowMultiBondsOrb = !ShowMultiBondsOrb;
		RebuildGeom = TRUE;
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderXYZAxes"))
	{
			if(testShowAxis()) hideAxis();
			else showAxis();
			glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderPrincipalAxes"))
	{
		if(testShowPrincipalAxisGL()) hidePrincipalAxisGL();
		else showPrincipalAxisGL();
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderPerspective"))
	{
  		gboolean perspective = FALSE;
  		gdouble aspect, zn, zf, zo;
		get_camera_values(&zn, &zf, &zo, &aspect, &perspective);

		perspective = !perspective;
		set_camera_values(zn,zf,zo,perspective);
	}
	else if(!strcmp(name , "ShowToolBar")) view_toolbar();
	else if(!strcmp(name,"ShowStatusHandleBox"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		show_handlebox_status(show);
	}
	else if(!strcmp(name,"ShowProgressBar"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		show_progress_bar(show);
	}
	else if(!strcmp(name,"RenderLabelSymbols"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_show_symbols(show);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLabelNumbers"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_show_numbers(show);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLabelCharges"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_show_charges(show);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLabelDistances"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_show_distances(show);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLabelDipole"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_show_dipole(show);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLabelAxes"))
	{
		gboolean show = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_show_axes(show);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name,"RenderLabelsOrtho"))
	{
		gboolean ortho = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_labels_ortho(ortho);
		glarea_rafresh(GLArea);
	}
	else if(!strcmp(name , "RingsDeleteNotPlaner"))
	{
		gboolean showNotPlaner = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		ringsSetNotPlanar(!showNotPlaner);
	}
	else if(!strcmp(name , "RingsRandumColors"))
	{
		gboolean randumColors = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		ringsSetRandumColors(randumColors);
	}
	else if(!strcmp(name , "ContoursNegativeDotted"))
	{
		gboolean dotted = gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action));
		set_dotted_negative_contours(dotted);
	}
}

static GtkToggleActionEntry gtkActionToggleEntries[] =
{
	{ "RenderSurfaceTransparency", NULL, "_Transparency", NULL, "render transparency", G_CALLBACK (toggle_action), FALSE },
	{ "RenderLightOnOff1", NULL, "OnOff _1", NULL, "On/Of the light number 1", G_CALLBACK (toggle_action), TRUE },
	{ "RenderLightOnOff2", NULL, "OnOff _2", NULL, "On/Of the light number 2", G_CALLBACK (toggle_action), FALSE },
	{ "RenderLightOnOff3", NULL, "OnOff _3", NULL, "On/Of the light number 3", G_CALLBACK (toggle_action), FALSE },
	{ "RenderDipole", NULL, "Show _dipole", NULL, "Show dipole", G_CALLBACK (toggle_action), FALSE },
	{ "RenderHydrogenAtoms", NULL, "Show _hydrogen atoms", NULL, "Show hydrogen atoms", G_CALLBACK (toggle_action), FALSE },
	{ "RenderHydrogenBonds", NULL, "Show _hydrogen bonds", NULL, "Show hydrogen bonds", G_CALLBACK (toggle_action), FALSE },
	{ "RenderMultiBonds", NULL, "Show double and triple _bonds", NULL, "Show double and triple bonds", G_CALLBACK (toggle_action), FALSE },
	{ "RenderXYZAxes", NULL, "Show XYZ _Axes", NULL, "Show XYZ Axes", G_CALLBACK (toggle_action), FALSE },
	{ "RenderPrincipalAxes", NULL, "Show the _principal Axes", NULL, "Show principal Axes", G_CALLBACK (toggle_action), FALSE },
	{ "RenderPerspective", GABEDIT_STOCK_PERSPECTIVE, "Perspective", NULL, "Perspective/Orthographic", G_CALLBACK (toggle_action), TRUE},
	{ "ShowToolBar", NULL, "_Show toolbar", NULL, "show toolbar", G_CALLBACK (toggle_action), TRUE },
	{ "ShowStatusHandleBox", NULL, "_show status handlebox", NULL, "show status handlebox", G_CALLBACK (toggle_action), TRUE},
	{ "ShowProgressBar", NULL, "_show progress bar", NULL, "show progress bar", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelSymbols", NULL, "show symbo_ls", NULL, "show symbols", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelNumbers", NULL, "show _numbers", NULL, "show numbers", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelCharges", NULL, "show _charges", NULL, "show charges", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelDistances", NULL, "show _distances", NULL, "show distances", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelDipole", NULL, "show _dipole value", NULL, "show dipole value", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelAxes", NULL, "show _axis labels", NULL, "show axis labels", G_CALLBACK (toggle_action), TRUE},
	{ "RenderLabelsOrtho", NULL, "_orthographic labels", NULL, "orthographic labels", G_CALLBACK (toggle_action), TRUE},
	{ "RingsDeleteNotPlaner", NULL, "Show ring with not co-_planer atoms", NULL, "Show ring with not co-planer atoms", G_CALLBACK (toggle_action), TRUE},
	{ "RingsRandumColors", NULL, "_randum colors", NULL, "randum colors", G_CALLBACK (toggle_action), TRUE},
	{ "ContoursNegativeDotted", NULL, "_dotted contours for negative values", NULL, "dotted contours for negative values", G_CALLBACK (toggle_action), FALSE},
};

static guint numberOfGtkActionToggleEntries = G_N_ELEMENTS (gtkActionToggleEntries);
/*********************************************************************************************************************/
enum 
{
	GEOMETRY_STICK,
	GEOMETRY_BALLSTICK,
	GEOMETRY_WIREFRAME,
	GEOMETRY_SPACEFILL,
	GEOMETRY_NO
};
static void render_geometry_radio_action (GtkAction *action)
{
	/*
	const gchar *name = gtk_action_get_name (action);
	*/
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	/*
	gtk_toggle_action_get_active (GTK_TOGGLE_ACTION (action)),
	*/
	switch(value)
	{
		case GEOMETRY_STICK :
			TypeGeom = GABEDIT_TYPEGEOM_STICK;
			RebuildGeom = TRUE;
			glarea_rafresh(GLArea);
			break;
		case GEOMETRY_BALLSTICK :
			TypeGeom = GABEDIT_TYPEGEOM_BALLSTICK;
			RebuildGeom = TRUE;
			glarea_rafresh(GLArea);
			break;
		case GEOMETRY_WIREFRAME :
			TypeGeom = GABEDIT_TYPEGEOM_WIREFRAME;
			RebuildGeom = TRUE;
			glarea_rafresh(GLArea);
			break;
		case GEOMETRY_SPACEFILL :
			TypeGeom = GABEDIT_TYPEGEOM_SPACE;
			RebuildGeom = TRUE;
			glarea_rafresh(GLArea);
			break;
		case GEOMETRY_NO :
			TypeGeom = GABEDIT_TYPEGEOM_NO;
			glarea_rafresh(GLArea);
			break;
	}
}
static GtkRadioActionEntry rendereGeometryEntries[] = {
  { "RenderGeometryStick", GABEDIT_STOCK_RENDER_STICK, "_Stick", NULL, "render stick", GEOMETRY_STICK },
  { "RenderGeometryWireFrame", GABEDIT_STOCK_RENDER_WIREFRAME, "_WireFrame", NULL, "render wireframe", GEOMETRY_WIREFRAME },
  { "RenderGeometryBallAndStick", GABEDIT_STOCK_RENDER_BALL_STICK, "_Ball&Stick", NULL, "render Ball&Stick", GEOMETRY_BALLSTICK },
  { "RenderGeometrySpaceFill", NULL, "Space_Fill", NULL, "render Space Fill", GEOMETRY_SPACEFILL },
  { "RenderGeometryNothing", NULL, "_Nothing", NULL, "hide geometry", GEOMETRY_NO },
};
static guint numberOfRenderGeometryEntries = G_N_ELEMENTS (rendereGeometryEntries);
/*********************************************************************************************************************/
enum 
{
	SURFACE_POSITIVE_FILL,
	SURFACE_POSITIVE_WIREFRAME
};
static void render_surface_positive_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	switch(value)
	{
		case SURFACE_POSITIVE_FILL:
			TypePosWireFrame = GABEDIT_POS_WIREFRAME_NO;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
			break;
		case SURFACE_POSITIVE_WIREFRAME:
			TypePosWireFrame = GABEDIT_POS_WIREFRAME_YES;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
 			break;
	}
}
static GtkRadioActionEntry renderSurfacePositiveEntries[] = {
  { "RenderSurfacePositiveFill", NULL, "_Fill", NULL, "render fill the positive surface", SURFACE_POSITIVE_FILL },
  { "RenderSurfacePositiveWireFrame", NULL, "_WireFrame", NULL, "render wireframe the positive surface", SURFACE_POSITIVE_WIREFRAME },
};
static guint numberOfRenderSurfacePositiveEntrie = G_N_ELEMENTS (renderSurfacePositiveEntries);
/*********************************************************************************************************************/
enum 
{
	SURFACE_NEGATIVE_FILL,
	SURFACE_NEGATIVE_WIREFRAME
};
static void render_surface_negative_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	switch(value)
	{
		case SURFACE_NEGATIVE_FILL:
			TypeNegWireFrame = GABEDIT_NEG_WIREFRAME_NO;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
			break;
		case SURFACE_NEGATIVE_WIREFRAME:
			TypeNegWireFrame = GABEDIT_NEG_WIREFRAME_YES;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
 			break;
	}
}
static GtkRadioActionEntry renderSurfaceNegativeEntries[] = {
  { "RenderSurfaceNegariveFill", NULL, "_Fill", NULL, "render fill the negative surface", SURFACE_NEGATIVE_FILL },
  { "RenderSurfaceNegativeWireFrame", NULL, "_WireFrame", NULL, "render wireframe the negative surface", SURFACE_NEGATIVE_WIREFRAME },
};
static guint numberOfRenderSurfaceNegativeEntries = G_N_ELEMENTS (renderSurfaceNegativeEntries);
/*********************************************************************************************************************/
enum 
{
	SURFACE_POSITIVENEGATIVE,
	SURFACE_POSITIVE,
	SURFACE_NEGATIVE,
	SURFACE_NO
};
static void render_surface_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	switch(value)
	{
		case SURFACE_POSITIVENEGATIVE:
			SurfShow = GABEDIT_SURFSHOW_POSNEG;
			glarea_rafresh(GLArea);
			break;
		case SURFACE_POSITIVE:
			SurfShow = GABEDIT_SURFSHOW_POSITIVE;
			glarea_rafresh(GLArea);
			break;
		case SURFACE_NEGATIVE:
			SurfShow = GABEDIT_SURFSHOW_NEGATIVE;
			glarea_rafresh(GLArea);
			break;
		case SURFACE_NO:
			SurfShow = GABEDIT_SURFSHOW_NO;
			glarea_rafresh(GLArea);
			break;
	}
}
static GtkRadioActionEntry renderSurfaceEntries[] = {
  { "RenderSurfacePositiveNegativeShow", NULL, "Positive_&Neg_ative", NULL, "show the Positive&Neg_ative surfaces", SURFACE_POSITIVENEGATIVE },
  { "RenderSurfacePositiveShow", NULL, "_Positive", NULL, "show the Positive surface", SURFACE_POSITIVE },
  { "RenderSurfaceNegativeShow", NULL, "_Negative", NULL, "show the Neg_ative surfaces", SURFACE_NEGATIVE },
  { "RenderSurfaceNothingShow", NULL, "N_othing", NULL, "hide surfaces", SURFACE_NO },
};
static guint numberOfRenderSurfaceEntries = G_N_ELEMENTS (renderSurfaceEntries);
/*********************************************************************************************************************/
enum 
{
	TEXTURE_NO,
	TEXTURE_1,
	TEXTURE_2,
	TEXTURE_3,
};
static void render_surface_texture_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	switch(value)
	{
		case TEXTURE_NO:
			TypeTexture = GABEDIT_TYPETEXTURE_NONE;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
			break;
		case TEXTURE_1:
			TypeTexture = GABEDIT_TYPETEXTURE_1;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
			break;
		case TEXTURE_2:
			TypeTexture = GABEDIT_TYPETEXTURE_2;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
			break;
		case TEXTURE_3:
			TypeTexture = GABEDIT_TYPETEXTURE_3;
			RebuildSurf = TRUE;
			glarea_rafresh(GLArea);
			break;
	}
}
static GtkRadioActionEntry renderSurfaceTextureEntries[] = {
  { "RenderSurfaceTextureNothing", NULL, "_No Texture", NULL, "No Texture", TEXTURE_NO },
  { "RenderSurfaceTexture1", NULL, "Texture _1", NULL, "Texture number 1", TEXTURE_1 },
  { "RenderSurfaceTexture2", NULL, "Texture _2", NULL, "Texture number 2", TEXTURE_2 },
  { "RenderSurfaceTexture3", NULL, "Texture _3", NULL, "Texture number 3", TEXTURE_3 },
};
static guint numberOfRenderSurfacetextureEntries = G_N_ELEMENTS (renderSurfaceTextureEntries);
/*********************************************************************************************************************/
static void render_background_radio_action (GtkAction *action)
{
	/*
	const gchar *name = gtk_action_get_name (action);
	*/
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	if(value>=BACKGROUND_BLACK && value<=BACKGROUND_CHECKER)
	{
		if( value==BACKGROUND_CHECKER) set_background_optcolor(-1);
		else set_background_optcolor(value-BACKGROUND_BLACK);
		glarea_rafresh(GLArea);
	}
}
static GtkRadioActionEntry renderBackGroundEntries[] = {
  { "RenderBackGroundBlack", NULL, "_Black", NULL, "Black background", BACKGROUND_BLACK },
  { "RenderBackGroundWhite", NULL, "_White", NULL, "White background", BACKGROUND_WHITE },
  { "RenderBackGroundRed", NULL, "_Red", NULL, "Red background", BACKGROUND_RED1 },
  { "RenderBackGroundGreen", NULL, "_Green", NULL, "Green background", BACKGROUND_GREEN1 },
  { "RenderBackGroundBlue", NULL, "_Blue", NULL, "Blue background", BACKGROUND_BLUE1 },
  { "RenderBackGroundPeach", NULL, "_Peach", NULL, "Peach background", BACKGROUND_PEACH },
  { "RenderBackGroundGray", NULL, "_Gray", NULL, "Gray background", BACKGROUND_GRAY },
  { "RenderBackGroundCheckerAndSky", NULL, "_Checker&sky", NULL, "Checker&sky", BACKGROUND_CHECKER },
};
static guint numberOfBackGroundEntries = G_N_ELEMENTS (renderBackGroundEntries);
/*********************************************************************************************************************/
enum 
{
	OPERATION_ROTATION_FREE,
	OPERATION_ROTATION_X,
	OPERATION_ROTATION_Y,
	OPERATION_ROTATION_Z,
	OPERATION_TRANSLATION,
	OPERATION_ZOOM,
};
static void render_operation_radio_action (GtkAction *action)
{
	gint value = gtk_radio_action_get_current_value (GTK_RADIO_ACTION (action));
	if(value>=OPERATION_ROTATION_FREE && value<=OPERATION_ZOOM)
				set_operation_type(value-OPERATION_ROTATION_FREE);
}
static GtkRadioActionEntry operationEntries[] = {
  { "OperationRotationFree", GABEDIT_STOCK_ROTATION, "_Free rotation", "<control>R", "Free rotation", OPERATION_ROTATION_FREE },
  { "OperationRotationX", GABEDIT_STOCK_ROTATION_X, "Rotation about _X axis", "<control>X", "Rotation about X axis", OPERATION_ROTATION_X },
  { "OperationRotationY", GABEDIT_STOCK_ROTATION_Y, "Rotation about _Y axis", "<control>Y", "Rotation about Y axis", OPERATION_ROTATION_Y },
  { "OperationRotationZ", GABEDIT_STOCK_ROTATION_Z, "Rotation about _Z axis", "<control>Z", "Rotation about Z axis", OPERATION_ROTATION_Z },
  { "OperationZoom", GABEDIT_STOCK_ZOOM, "Z_oom", "<control>o", "Zoom axis", OPERATION_ZOOM },
  { "OperationTranslation", GABEDIT_STOCK_TRANSLATE, "_Translation", "<control>T", "Translation", OPERATION_TRANSLATION },
};
static guint numberOfOperationEntries = G_N_ELEMENTS (operationEntries);
/*********************************************************************************************************************/

/* XML description of the menus for the test app.  The parser understands
 * a subset of the Bonobo UI XML format, and uses GMarkup for parsing */
static const gchar *uiMenuInfo =
"  <popup name=\"MenuGL\">\n"
"    <menu name=\"Geometry\" action=\"Geometry\">\n"
"      <menuitem name=\"GeometryAuto\" action=\"GeometryAuto\" />\n"
"      <separator name=\"sepMenuGeomAuto\" />\n"
"      <menuitem name=\"GeometryXYZ\" action=\"GeometryXYZ\" />\n"
"      <menuitem name=\"GeometryPDB\" action=\"GeometryPDB\" />\n"
"      <menuitem name=\"GeometryHIN\" action=\"GeometryHIN\" />\n"
"      <separator name=\"sepMenuXYZ\" />\n"
"      <menu name=\"GeometryDalton\" action=\"GeometryDalton\">\n"
"        <menuitem name=\"GeometryDaltonFirst\" action=\"GeometryDaltonFirst\" />\n"
"        <menuitem name=\"GeometryDaltonLast\" action=\"GeometryDaltonLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuDaltonGeom\" />\n"
"      <menu name=\"GeometryGamess\" action=\"GeometryGamess\">\n"
"        <menuitem name=\"GeometryGamessFirst\" action=\"GeometryGamessFirst\" />\n"
"        <menuitem name=\"GeometryGamessLast\" action=\"GeometryGamessLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuGamessGeom\" />\n"
"      <menu name=\"GeometryGaussian\" action=\"GeometryGaussian\">\n"
"        <menuitem name=\"GeometryGaussianFirst\" action=\"GeometryGaussianFirst\" />\n"
"        <menuitem name=\"GeometryGaussianLast\" action=\"GeometryGaussianLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuGaussianGeom\" />\n"
"      <menu name=\"GeometryMolcas\" action=\"GeometryMolcas\">\n"
"        <menuitem name=\"GeometryMolcasFirst\" action=\"GeometryMolcasFirst\" />\n"
"        <menuitem name=\"GeometryMolcasLast\" action=\"GeometryMolcasLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuMolcasGeom\" />\n"
"      <menu name=\"GeometryMolpro\" action=\"GeometryMolpro\">\n"
"        <menuitem name=\"GeometryMolproFirst\" action=\"GeometryMolproFirst\" />\n"
"        <menuitem name=\"GeometryMolproLast\" action=\"GeometryMolproLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuMolproGeom\" />\n"
"      <menu name=\"GeometryMopac\" action=\"GeometryMopac\">\n"
"        <menuitem name=\"GeometryMopacOutFirst\" action=\"GeometryMopacOutFirst\" />\n"
"        <menuitem name=\"GeometryMopacOutLast\" action=\"GeometryMopacOutLast\" />\n"
"        <menuitem name=\"GeometryMopacAuxFirst\" action=\"GeometryMopacAuxFirst\" />\n"
"        <menuitem name=\"GeometryMopacAuxLast\" action=\"GeometryMopacAuxLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuMopacGeom\" />\n"
"      <menu name=\"GeometryMPQC\" action=\"GeometryMPQC\">\n"
"        <menuitem name=\"GeometryMPQCFirst\" action=\"GeometryMPQCFirst\" />\n"
"        <menuitem name=\"GeometryMPQCLast\" action=\"GeometryMPQCLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuMPQCGeom\" />\n"
"      <menu name=\"GeometryOrca\" action=\"GeometryOrca\">\n"
"        <menuitem name=\"GeometryOrcaFirst\" action=\"GeometryOrcaFirst\" />\n"
"        <menuitem name=\"GeometryOrcaLast\" action=\"GeometryOrcaLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuOrcaGeom\" />\n"
"      <menu name=\"GeometryPCGamess\" action=\"GeometryPCGamess\">\n"
"        <menuitem name=\"GeometryPCGamessFirst\" action=\"GeometryPCGamessFirst\" />\n"
"        <menuitem name=\"GeometryPCGamessLast\" action=\"GeometryPCGamessLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuPCGamessGeom\" />\n"
"      <menu name=\"GeometryQChem\" action=\"GeometryQChem\">\n"
"        <menuitem name=\"GeometryQChemFirst\" action=\"GeometryQChemFirst\" />\n"
"        <menuitem name=\"GeometryQChemLast\" action=\"GeometryQChemLast\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuQChemGeom\" />\n"
"      <menuitem name=\"GeometryGabedit\" action=\"GeometryGabedit\" />\n"
"      <separator name=\"sepMenuGabeditGeom\" />\n"
"      <menuitem name=\"GeometryMolden\" action=\"GeometryMolden\" />\n"
"      <separator name=\"sepMenuBABEL\" />\n"
"      <menuitem name=\"GeometryOpenBabel\" action=\"GeometryOpenBabel\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuOrbitals\" />\n"
"    <menu name=\"Orbitals\" action = \"Orbitals\">\n"
"      <menuitem name=\"OrbitalsAuto\" action=\"OrbitalsAuto\" />\n"
"      <separator name=\"sepMenuOrbitalsAuto\" />\n"
/*"      <menuitem name=\"OrbitalsDalton\" action=\"OrbitalsDalton\" />\n"*/
"      <menuitem name=\"OrbitalsGamess\" action=\"OrbitalsGamess\" />\n"
"      <menuitem name=\"OrbitalsGaussian\" action=\"OrbitalsGaussian\" />\n"
"      <menuitem name=\"OrbitalsMolpro\" action=\"OrbitalsMolpro\" />\n"
"      <menuitem name=\"OrbitalsMopac\" action=\"OrbitalsMopac\" />\n"
"      <menuitem name=\"OrbitalsOrca\" action=\"OrbitalsOrca\" />\n"
"      <menuitem name=\"OrbitalsOrca2mkl\" action=\"OrbitalsOrca2mkl\" />\n"
"      <menuitem name=\"OrbitalsPCGamess\" action=\"OrbitalsPCGamess\" />\n"
"      <menuitem name=\"OrbitalsQChem\" action=\"OrbitalsQChem\" />\n"
"      <menuitem name=\"OrbitalsGabeditRead\" action=\"OrbitalsGabeditRead\" />\n"
"      <menuitem name=\"OrbitalsMolden\" action=\"OrbitalsMolden\" />\n"
"      <separator name=\"sepMenuGabeditOrbSave\" />\n"
"      <menuitem name=\"OrbitalsGabeditSave\" action=\"OrbitalsGabeditSave\" />\n"
"      <separator name=\"sepMenuGabeditOrbSel\" />\n"
"      <menuitem name=\"OrbitalsSelection\" action=\"OrbitalsSelection\" />\n"
"      <separator name=\"sepMenuGabeditOrbCap\" />\n"
"      <menuitem name=\"OrbitalsCapture\" action=\"OrbitalsCapture\" />\n"
"      <separator name=\"sepMenuGabeditOrbCoul\" />\n"
"      <menuitem name=\"OrbitalsCoulomb\" action=\"OrbitalsCoulomb\" />\n"
"      <menuitem name=\"OrbitalsTransition\" action=\"OrbitalsTransition\" />\n"
/*
"      <menuitem name=\"OrbitalsOverlap\" action=\"OrbitalsOverlap\" />\n"
*/
"    </menu>\n"
"    <separator name=\"sepMenuCube\" />\n"
"    <menu name=\"Cube\" action = \"Cube\">\n"
"      <menu name=\"CubeLoadGaussian\" action = \"CubeLoadGaussian\">\n"
"      <menuitem name=\"CubeLoadGaussianOrbitals\" action=\"CubeLoadGaussianOrbitals\" />\n"
"      <menuitem name=\"CubeLoadGaussianDensity\" action=\"CubeLoadGaussianDensity\" />\n"
"      <menuitem name=\"CubeLoadGaussianDensityGradient\" action=\"CubeLoadGaussianDensityGradient\" />\n"
"      <menuitem name=\"CubeLoadGaussianLaplacian\" action=\"CubeLoadGaussianLaplacian\" />\n"
"      <menuitem name=\"CubeLoadGaussianNormGradient\" action=\"CubeLoadGaussianNormGradient\" />\n"
"      <menuitem name=\"CubeLoadGaussianPotential\" action=\"CubeLoadGaussianPotential\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuCubeLoadMolcas\" />\n"
"      <menu name=\"CubeLoadMolcas\" action = \"CubeLoadMolcas\">\n"
"          <menuitem name=\"CubeLoadMolcasGridOrbitals\" action=\"CubeLoadMolcasGridOrbitals\" />\n"
"          <menuitem name=\"CubeLoadMolcasGridDensity\" action=\"CubeLoadMolcasGridDensity\" />\n"
"      </menu>\n"
"    <separator name=\"sepMenuCubeLoadMolpro\" />\n"
"      <menu name=\"CubeLoadMolpro\" action = \"CubeLoadMolpro\">\n"
"        <menu name=\"CubeLoadMolproOrbitals\" action = \"CubeLoadMolproOrbitals\">\n"
"           <menuitem name=\"CubeLoadMolproOrbitalsOne\" action=\"CubeLoadMolproOrbitalsOne\" />\n"
"           <menuitem name=\"CubeLoadMolproOrbitalsSeveral\" action=\"CubeLoadMolproOrbitalsSeveral\" />\n"
"        </menu>\n"
"        <menuitem name=\"CubeLoadMolproDensityOne\" action=\"CubeLoadMolproDensityOne\" />\n"
"        <menuitem name=\"CubeLoadMolproDensityGradient\" action=\"CubeLoadMolproDensityGradient\" />\n"
"        <menu name=\"CubeLoadMolproDensityGradientLaplacian\" action = \"CubeLoadMolproDensityGradientLaplacian\">\n"
"           <menuitem name=\"CubeLoadMolproDensityGradientLaplacianDensity\" action=\"CubeLoadMolproDensityGradientLaplacianDensity\" />\n"
"           <menuitem name=\"CubeLoadMolproDensityGradientLaplacianLaplacian\" action=\"CubeLoadMolproDensityGradientLaplacianLaplacian\" />\n"
"        </menu>\n"
"      </menu>\n"
"      <separator name=\"sepMenuCubeLoadAdf\" />\n"
"      <menu name=\"CubeLoadAdf\" action = \"CubeLoadAdf\">\n"
"        <menuitem name=\"CubeLoadAdfOrbitals\" action=\"CubeLoadAdfOrbitals\" />\n"
"        <menuitem name=\"CubeLoadAdfDensity\" action=\"CubeLoadAdfDensity\" />\n"
"      </menu>\n"
"      <separator name=\"sepMenuCubeLoadQChem\" />\n"
"      <menuitem name=\"CubeLoadQChem\" action=\"CubeLoadQChem\" />\n"
"      <separator name=\"sepMenuCubeLoadGabeditRead\" />\n"
"      <menuitem name=\"CubeLoadGabeditRead\" action=\"CubeLoadGabeditRead\" />\n"
"      <separator name=\"sepMenuCubeLoadGabeditSave\" />\n"
"      <menuitem name=\"CubeLoadGabeditSave\" action=\"CubeLoadGabeditSave\" />\n"
"      <separator name=\"sepMenuCubeComputeLaplacian\" />\n"
"      <menuitem name=\"CubeComputeLaplacian\" action=\"CubeComputeLaplacian\" />\n"
"      <separator name=\"sepMenuCubeComputeNormGradient\" />\n"
"      <menuitem name=\"CubeComputeNormGradient\" action=\"CubeComputeNormGradient\" />\n"
"      <separator name=\"sepMenuCubeSub\" />\n"
"      <menuitem name=\"CubeSubtract\" action=\"CubeSubtract\" />\n"
"      <separator name=\"sepMenuCubeScale\" />\n"
"      <menuitem name=\"CubeScale\" action=\"CubeScale\" />\n"
"      <separator name=\"sepMenuCubeSquare\" />\n"
"      <menuitem name=\"CubeSquare\" action=\"CubeSquare\" />\n"
"      <separator name=\"sepMenuCubeRestriction\" />\n"
"      <menuitem name=\"CubeRestriction\" action=\"CubeRestriction\" />\n"
"      <separator name=\"sepMenuCubeAIMChargesNearGrid\" />\n"
"      <menuitem name=\"CubeAIMChargesNearGrid\" action=\"CubeAIMChargesNearGrid\" />\n"
"      <menuitem name=\"CubeAIMChargesOnGrid\" action=\"CubeAIMChargesOnGrid\" />\n"
"      <separator name=\"sepMenuCubeColor\" />\n"
"      <menuitem name=\"CubeColorMapping\" action=\"CubeColorMapping\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuDensity\" />\n"
"    <menu name=\"Density\" action = \"Density\">\n"
"        <menuitem name=\"DensityElectronic\" action=\"DensityElectronic\" />\n"
"        <menuitem name=\"DensityBonds\" action=\"DensityBonds\" />\n"
"        <menuitem name=\"DensityAtomics\" action=\"DensityAtomics\" />\n"
"        <menuitem name=\"DensitySpin\" action=\"DensitySpin\" />\n"
"    </menu>\n"

"    <separator name=\"sepMenuELF\" />\n"
"    <menu name=\"ELF\" action = \"ELF\">\n"
"        <menuitem name=\"ELFSavin\" action=\"ELFSavin\" />\n"
"        <menuitem name=\"ELFBecke\" action=\"ELFBecke\" />\n"
"    </menu>\n"
/*
"        <menuitem name=\"ELFSavinAttractors\" action=\"ELFSavinAttractors\" />\n"
*/
"    <separator name=\"sepMenuFED\" />\n"
"    <menu name=\"Fukui\" action = \"Fukui\">\n"
"        <menuitem name=\"FEDElectrophilic\" action=\"FEDElectrophilic\" />\n"
"        <menuitem name=\"FEDNucleophilic\" action=\"FEDNucleophilic\" />\n"
"        <menuitem name=\"FEDRadical\" action=\"FEDRadical\" />\n"
"        <separator name=\"sepMappingFED\" />\n"
"        <menuitem name=\"FEDElectrophilicMapping\" action=\"FEDElectrophilicMapping\" />\n"
"        <menuitem name=\"FEDNucleophilicMapping\" action=\"FEDNucleophilicMapping\" />\n"
"        <menuitem name=\"FEDRadicalMapping\" action=\"FEDRadicalMapping\" />\n"
"        <separator name=\"sepAlphaFED\" />\n"
"        <menuitem name=\"FEDSetAlpha\" action=\"FEDSetAlpha\" />\n"
"    </menu>\n"

"    <separator name=\"sepMenuSAS\" />\n"
"    <menu name=\"SAS\" action = \"SAS\">\n"
"        <menuitem name=\"SASCompute\" action=\"SASCompute\" />\n"
"        <menuitem name=\"SASMappCompute\" action=\"SASMappCompute\" />\n"
"    </menu>\n"

"    <separator name=\"sepMenuMEP\" />\n"
"    <menu name=\"MEP\" action = \"MEP\">\n"
"      <menu name=\"MEPMapping\" action = \"MEPMapping\">\n"
"        <menuitem name=\"MEPMappingMG\" action=\"MEPMappingMG\" />\n"
"        <menuitem name=\"MEPMappingCG\" action=\"MEPMappingCG\" />\n"
"        <menuitem name=\"MEPMappingMultipol\" action=\"MEPMappingMultipol\" />\n"
"        <menuitem name=\"MEPMappingCharges\" action=\"MEPMappingCharges\" />\n"
"      </menu>\n"
"      <menu name=\"MEPOrbitals\" action = \"MEPOrbitals\">\n"
"        <menuitem name=\"MEPOrbitalsMG\" action=\"MEPOrbitalsMG\" />\n"
"        <menuitem name=\"MEPOrbitalsCG\" action=\"MEPOrbitalsCG\" />\n"
"        <menuitem name=\"MEPOrbitalsMultipol\" action=\"MEPOrbitalsMultipol\" />\n"
"      </menu>\n"
"      <menu name=\"MEPGrid\" action = \"MEPGrid\">\n"
"        <menuitem name=\"MEPGridMG\" action=\"MEPGridMG\" />\n"
"        <menuitem name=\"MEPGridCG\" action=\"MEPGridCG\" />\n"
"        <menuitem name=\"MEPGridMultipol\" action=\"MEPGridMultipol\" />\n"
"      </menu>\n"
"        <menuitem name=\"MEPFromCharges\" action=\"MEPFromCharges\" />\n"
"    </menu>\n"

"    <separator name=\"sepMenuContours\" />\n"
"    <menu name=\"Contours\" action = \"Contours\">\n"
"        <menuitem name=\"ContoursFirst\" action=\"ContoursFirst\" />\n"
"        <menuitem name=\"ContoursSecond\" action=\"ContoursSecond\" />\n"
"        <menuitem name=\"ContoursThird\" action=\"ContoursThird\" />\n"
"        <menuitem name=\"ContoursOther\" action=\"ContoursOther\" />\n"
"        <separator name=\"sepMenuContoursNegativeDotted\" />\n"
"        <menuitem name=\"ContoursNegativeDotted\" action=\"ContoursNegativeDotted\" />\n"
"        <separator name=\"sepMenuContoursDelete\" />\n"
"        <menuitem name=\"ContoursDelete\" action=\"ContoursDelete\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuPlanesColorCoded\" />\n"
"    <menu name=\"PlanesColorCoded\" action = \"PlanesColorCoded\">\n"
"        <menuitem name=\"PlanesColorCodedFirst\" action=\"PlanesColorCodedFirst\" />\n"
"        <menuitem name=\"PlanesColorCodedSecond\" action=\"PlanesColorCodedSecond\" />\n"
"        <menuitem name=\"PlanesColorCodedThird\" action=\"PlanesColorCodedThird\" />\n"
"        <menuitem name=\"PlanesColorCodedOther\" action=\"PlanesColorCodedOther\" />\n"
"        <separator name=\"sepMenuPlanesColorCodedDelete\" />\n"
"        <menuitem name=\"PlanesColorCodedDelete\" action=\"PlanesColorCodedDelete\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuSurfaces\" />\n"
"    <menu name=\"Surfaces\" action = \"Surfaces\">\n"
"        <menuitem name=\"SurfacesResetIsovalue\" action=\"SurfacesResetIsovalue\" />\n"
"        <menuitem name=\"SurfacesNew\" action=\"SurfacesNew\" />\n"
"        <menuitem name=\"SurfacesDelete\" action=\"SurfacesDelete\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuRings\" />\n"
"    <menu name=\"Rings\" action = \"Rings\">\n"
"        <menuitem name=\"Rings3\" action=\"Rings3\" />\n"
"        <menuitem name=\"Rings4\" action=\"Rings4\" />\n"
"        <menuitem name=\"Rings5\" action=\"Rings5\" />\n"
"        <menuitem name=\"Rings6\" action=\"Rings6\" />\n"
"        <menuitem name=\"Rings7\" action=\"Rings7\" />\n"
"        <menuitem name=\"Rings8\" action=\"Rings8\" />\n"
"        <separator name=\"sepMenuRingsShowNotPlaner\" />\n"
"        <menuitem name=\"RingsDeleteNotPlaner\" action=\"RingsDeleteNotPlaner\" />\n"
"        <menuitem name=\"RingsRandumColors\" action=\"RingsRandumColors\" />\n"
"        <separator name=\"sepMenuRingsDelete\" />\n"
"        <menuitem name=\"RingsDelete\" action=\"RingsDelete\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuRender\" />\n"
"    <menu name=\"Render\" action = \"Render\">\n"
"       <menu name=\"RenderGeometry\" action = \"RenderGeometry\">\n"
"           <menuitem name=\"RenderGeometryStick\" action=\"RenderGeometryStick\" />\n"
"           <menuitem name=\"RenderGeometryWireFrame\" action=\"RenderGeometryWireFrame\" />\n"
"           <menuitem name=\"RenderGeometryBallAndStick\" action=\"RenderGeometryBallAndStick\" />\n"
"           <menuitem name=\"RenderGeometrySpaceFill\" action=\"RenderGeometrySpaceFill\" />\n"
"           <menuitem name=\"RenderGeometryNothing\" action=\"RenderGeometryNothing\" />\n"
"       </menu>\n"
"       <separator name=\"sepRenderSurfaces\" />\n"
"       <menu name=\"RenderSurface\" action = \"RenderSurface\">\n"
"         <menuitem name=\"RenderSurfaceTransparency\" action=\"RenderSurfaceTransparency\" />\n"
"         <separator name=\"sepSurfacePositive\" />\n"
"         <menu name=\"RenderSurfacePositive\" action = \"RenderSurfacePositive\">\n"
"           <menuitem name=\"RenderSurfacePositiveFill\" action=\"RenderSurfacePositiveFill\" />\n"
"           <menuitem name=\"RenderSurfacePositiveWireFrame\" action=\"RenderSurfacePositiveWireFrame\" />\n"
"         </menu>\n"
"         <separator name=\"sepSurfaceNegative\" />\n"
"         <menu name=\"RenderSurfaceNegative\" action = \"RenderSurfaceNegative\">\n"
"           <menuitem name=\"RenderSurfaceNegariveFill\" action=\"RenderSurfaceNegariveFill\" />\n"
"           <menuitem name=\"RenderSurfaceNegativeWireFrame\" action=\"RenderSurfaceNegativeWireFrame\" />\n"
"         </menu>\n"
"         <separator name=\"sepSurfaceShow\" />\n"
"         <menuitem name=\"RenderSurfacePositiveNegativeShow\" action=\"RenderSurfacePositiveNegativeShow\" />\n"
"         <menuitem name=\"RenderSurfacePositiveShow\" action=\"RenderSurfacePositiveShow\" />\n"
"         <menuitem name=\"RenderSurfaceNegativeShow\" action=\"RenderSurfaceNegativeShow\" />\n"
"         <menuitem name=\"RenderSurfaceNothingShow\" action=\"RenderSurfaceNothingShow\" />\n"
"         <separator name=\"sepTexture\" />\n"
"         <menuitem name=\"RenderSurfaceTextureNothing\" action=\"RenderSurfaceTextureNothing\" />\n"
"         <menuitem name=\"RenderSurfaceTexture1\" action=\"RenderSurfaceTexture1\" />\n"
"         <menuitem name=\"RenderSurfaceTexture2\" action=\"RenderSurfaceTexture2\" />\n"
"         <menuitem name=\"RenderSurfaceTexture3\" action=\"RenderSurfaceTexture3\" />\n"
"       </menu>\n"
"       <separator name=\"sepMenuBackGround\" />\n"
"       <menu name=\"RenderBackGround\" action = \"RenderBackGround\">\n"
"           <menuitem name=\"RenderBackGroundBlack\" action=\"RenderBackGroundBlack\" />\n"
"           <menuitem name=\"RenderBackGroundWhite\" action=\"RenderBackGroundWhite\" />\n"
"           <menuitem name=\"RenderBackGroundRed\" action=\"RenderBackGroundRed\" />\n"
"           <menuitem name=\"RenderBackGroundGreen\" action=\"RenderBackGroundGreen\" />\n"
"           <menuitem name=\"RenderBackGroundPeach\" action=\"RenderBackGroundPeach\" />\n"
"           <menuitem name=\"RenderBackGroundGray\" action=\"RenderBackGroundGray\" />\n"
"           <menuitem name=\"RenderBackGroundCheckerAndSky\" action=\"RenderBackGroundCheckerAndSky\" />\n"
"       </menu>\n"
"       <separator name=\"sepMenuRenderLight\" />\n"
"       <menu name=\"RenderLight\" action = \"RenderLight\">\n"
"           <menuitem name=\"RenderLightOnOff1\" action=\"RenderLightOnOff1\" />\n"
"           <menuitem name=\"RenderLightOnOff2\" action=\"RenderLightOnOff2\" />\n"
"           <menuitem name=\"RenderLightOnOff3\" action=\"RenderLightOnOff3\" />\n"
"       </menu>\n"
"       <separator name=\"sepMenuRenderLabel\" />\n"
"       <menu name=\"RenderLabel\" action = \"RenderLabel\">\n"
"           <menuitem name=\"RenderLabelSymbols\" action=\"RenderLabelSymbols\" />\n"
"           <menuitem name=\"RenderLabelNumbers\" action=\"RenderLabelNumbers\" />\n"
"           <menuitem name=\"RenderLabelCharges\" action=\"RenderLabelCharges\" />\n"
"           <menuitem name=\"RenderLabelDistances\" action=\"RenderLabelDistances\" />\n"
"           <menuitem name=\"RenderLabelDipole\" action=\"RenderLabelDipole\" />\n"
"           <menuitem name=\"RenderLabelAxes\" action=\"RenderLabelAxes\" />\n"
"           <separator name=\"sepMenuRenderOrtho\" />\n"
"           <menuitem name=\"RenderLabelsOrtho\" action=\"RenderLabelsOrtho\" />\n"
"       </menu>\n"
"       <separator name=\"sepMenuRenderDipole\" />\n"
"      <menuitem name=\"RenderDipole\" action=\"RenderDipole\" />\n"
"      <menuitem name=\"RenderHydrogenAtoms\" action=\"RenderHydrogenAtoms\" />\n"
"      <menuitem name=\"RenderHydrogenBonds\" action=\"RenderHydrogenBonds\" />\n"
"      <menuitem name=\"RenderMultiBonds\" action=\"RenderMultiBonds\" />\n"
"      <menuitem name=\"RenderXYZAxes\" action=\"RenderXYZAxes\" />\n"
"      <menuitem name=\"RenderPrincipalAxes\" action=\"RenderPrincipalAxes\" />\n"
"       <separator name=\"sepMenuRenderPerspective\" />\n"
"      <menuitem name=\"RenderPerspective\" action=\"RenderPerspective\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuSet\" />\n"
"    <menu name=\"Set\" action = \"Set\">\n"
"        <menuitem name=\"SetCamera\" action=\"SetCamera\" />\n"
"        <menuitem name=\"SetLigthPositions\" action=\"SetLigthPositions\" />\n"
"        <menuitem name=\"SetSurfaceColors\" action=\"SetSurfaceColors\" />\n"
"        <separator name=\"sepMenuSetDipole\" />\n"
"        <menuitem name=\"SetDipole\" action=\"SetDipole\" />\n"
"        <menuitem name=\"SetDipoleDensity\" action=\"SetDipoleDensity\" />\n"
"        <separator name=\"sepMenuSetBonds\" />\n"
"        <menuitem name=\"SetAllBonds\" action=\"SetAllBonds\" />\n"
"        <menuitem name=\"SetMultipleBonds\" action=\"SetMultipleBonds\" />\n"
"        <separator name=\"sepMenuSetPropOfAtoms\" />\n"
"        <menuitem name=\"SetPropertiesOfAtoms\" action=\"SetPropertiesOfAtoms\" />\n"
"        <separator name=\"sepMenuSetHBond\" />\n"
"        <menuitem name=\"SetHydrogenBondsParameters\" action=\"SetHydrogenBondsParameters\" />\n"
"        <separator name=\"sepMenuSetXYZ\" />\n"
"        <menuitem name=\"SetXYZAxesProperties\" action=\"SetXYZAxesProperties\" />\n"
"        <menuitem name=\"SetPrincipalAxesProperties\" action=\"SetPrincipalAxesProperties\" />\n"
"        <separator name=\"sepMenuSetPovRay\" />\n"
"        <menuitem name=\"SetPovrayBackGround\" action=\"SetPovrayBackGround\" />\n"
"        <separator name=\"sepMenuSetColorMap\" />\n"
"        <menuitem name=\"SetColorMap\" action=\"SetColorMap\" />\n"
"        <separator name=\"sepMenuSetTitle\" />\n"
"        <menuitem name=\"SetTitle\" action=\"SetTitle\" />\n"
"        <separator name=\"sepMenuSetScaleBallStick\" />\n"
"        <menuitem name=\"SetScaleBallStick\" action=\"SetScaleBallStick\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuOperation\" />\n"
"    <menu name=\"Operation\" action = \"Operation\">\n"
"        <menuitem name=\"OperationTranslation\" action=\"OperationTranslation\" />\n"
"        <menuitem name=\"OperationRotationFree\" action=\"OperationRotationFree\" />\n"
"        <menuitem name=\"OperationRotationX\" action=\"OperationRotationX\" />\n"
"        <menuitem name=\"OperationRotationY\" action=\"OperationRotationY\" />\n"
"        <menuitem name=\"OperationRotationZ\" action=\"OperationRotationZ\" />\n"
"        <menuitem name=\"OperationZoom\" action=\"OperationZoom\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuCapture\" />\n"
"    <menu name=\"ScreenCapture\" action = \"ScreenCapture\">\n"
"        <menuitem name=\"ScreenCaptureBMP\" action=\"ScreenCaptureBMP\" />\n"
"        <menuitem name=\"ScreenCapturePNG\" action=\"ScreenCapturePNG\" />\n"
"        <menuitem name=\"ScreenCapturePNGNoBackGround\" action=\"ScreenCapturePNGNoBackGround\" />\n"
"        <menuitem name=\"ScreenCaptureJPG\" action=\"ScreenCaptureJPG\" />\n"
"        <menuitem name=\"ScreenCapturePPM\" action=\"ScreenCapturePPM\" />\n"
"        <menuitem name=\"ScreenCapturePS\" action=\"ScreenCapturePS\" />\n"
"        <menuitem name=\"ScreenCaptureClipBoard\" action=\"ScreenCaptureClipBoard\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuExport\" />\n"
"    <menu name=\"Export\" action = \"Export\">\n"
"        <menuitem name=\"ExportPovray\" action=\"ExportPovray\" />\n"
"        <menuitem name=\"ExportEPS\" action=\"ExportEPS\" />\n"
"        <menuitem name=\"ExportPS\" action=\"ExportPS\" />\n"
"        <menuitem name=\"ExportPDF\" action=\"ExportPDF\" />\n"
"        <menuitem name=\"ExportSVG\" action=\"ExportSVG\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuAnimation\" />\n"
"    <menu name=\"Animation\" action = \"Animation\">\n"
"        <menuitem name=\"AnimationVibration\" action=\"AnimationVibration\" />\n"
"        <separator name=\"sepMenuAnimationGeomConv\" />\n"
"        <menuitem name=\"AnimationGeometryConvergence\" action=\"AnimationGeometryConvergence\" />\n"
"        <separator name=\"sepMenuAnimationMD\" />\n"
"        <menuitem name=\"AnimationMD\" action=\"AnimationMD\" />\n"
"        <separator name=\"sepMenuAnimationRotation\" />\n"
"        <menuitem name=\"AnimationRotation\" action=\"AnimationRotation\" />\n"
"        <separator name=\"sepMenuAnimationContours\" />\n"
"        <menuitem name=\"AnimationContours\" action=\"AnimationContours\" />\n"
"        <separator name=\"sepMenuAnimationPlane\" />\n"
"        <menuitem name=\"AnimationPlanesColorcoded\" action=\"AnimationPlanesColorcoded\" />\n"
"        <separator name=\"sepMenuAnimationIsoSurface\" />\n"
"        <menuitem name=\"AnimationIsosurface\" action=\"AnimationIsosurface\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuView\" />\n"
"    <menu name=\"View\" action = \"View\">\n"
"        <menuitem name=\"ShowToolBar\" action=\"ShowToolBar\" />\n"
"        <menuitem name=\"ShowStatusHandleBox\" action=\"ShowStatusHandleBox\" />\n"
"        <menuitem name=\"ShowProgressBar\" action=\"ShowProgressBar\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuClose\" />\n"
"      <menuitem name=\"_Close\" action=\"Close\" />\n"
"  </popup>\n"
"  <toolbar action=\"ToolbarGL\">\n"
"      <separator name=\"sepToolBarOperation\" />\n"
"      <toolitem name=\"OperationTranslation\" action=\"OperationTranslation\" />\n"
"      <toolitem name=\"OperationRotationFree\" action=\"OperationRotationFree\" />\n"
"      <toolitem name=\"OperationRotationX\" action=\"OperationRotationX\" />\n"
"      <toolitem name=\"OperationRotationY\" action=\"OperationRotationY\" />\n"
"      <toolitem name=\"OperationRotationZ\" action=\"OperationRotationZ\" />\n"
"      <toolitem name=\"OperationZoom\" action=\"OperationZoom\" />\n"
"      <separator name=\"sepToolBarGlPerspective\" />\n"
"      <toolitem name=\"RenderPerspective\" action=\"RenderPerspective\" />\n"
"      <toolitem name=\"RenderOptimal\" action=\"RenderOptimal\" />\n"
"      <separator name=\"sepToolBarGlGeometry\" />\n"
"      <toolitem name=\"RenderGeometryWireFrame\" action=\"RenderGeometryWireFrame\" />\n"
"      <toolitem name=\"RenderGeometryStick\" action=\"RenderGeometryStick\" />\n"
"      <toolitem name=\"RenderGeometryBallAndStick\" action=\"RenderGeometryBallAndStick\" />\n"
"      <separator name=\"sepToolBarGlEnd\" />\n"
"  </toolbar>\n"
;

/*********************************************************************************************************************/
static void set_init_gtkActionToggleEntries()
{
  	gdouble aspect, zn, zf, zo;
  	gboolean perspective = FALSE;

	if(TypeBlend==GABEDIT_BLEND_YES)
	gtkActionToggleEntries[0].is_active = TRUE; /* "RenderSurfaceTransparency" */
	else
	gtkActionToggleEntries[0].is_active = FALSE; /* "RenderSurfaceTransparency" */

	gtkActionToggleEntries[1].is_active = TRUE; /* RenderLightOnOff1 */
	gtkActionToggleEntries[2].is_active = FALSE; /* RenderLightOnOff2 */
	gtkActionToggleEntries[3].is_active = FALSE; /* RenderLightOnOff3 */
	gtkActionToggleEntries[4].is_active = ShowDipoleOrb; /* RenderDipole */
	gtkActionToggleEntries[5].is_active = ShowHAtomOrb ; /* RenderHydrogenBonds */
	gtkActionToggleEntries[6].is_active = ShowHBondOrb ; /* RenderHydrogenBonds */
	gtkActionToggleEntries[7].is_active = ShowMultiBondsOrb ; /* RenderMultiBonds */
	gtkActionToggleEntries[8].is_active = testShowAxis() ; /* RenderXYZAxes */
	gtkActionToggleEntries[9].is_active = testShowPrincipalAxisGL() ; /* RenderPrincipalAxes */

  	get_camera_values(&zn, &zf, &zo, &aspect, &perspective);
	gtkActionToggleEntries[10].is_active = perspective; /* RenderPerspective */
	gtkActionToggleEntries[11].is_active = TRUE; /* ShowToolBar */
	gtkActionToggleEntries[12].is_active = TRUE; /* ShowStatusHandleBox */
	gtkActionToggleEntries[13].is_active = TRUE; /* ShowProgressBar */
	gtkActionToggleEntries[14].is_active = FALSE; /* RenderLabelSymbols */
	gtkActionToggleEntries[15].is_active = FALSE; /* RenderLabelNumbers */
	gtkActionToggleEntries[16].is_active = FALSE; /* RenderLabelCharges */
	gtkActionToggleEntries[17].is_active = FALSE; /* RenderLabelDistances */
	gtkActionToggleEntries[18].is_active = FALSE; /* RenderLabelDipole */
	gtkActionToggleEntries[19].is_active = FALSE; /* RenderLabelAxes */
	gtkActionToggleEntries[20].is_active = get_labels_ortho(); /* RenderLabelsOrtho*/
	gtkActionToggleEntries[21].is_active = !ringsGetNotPlanar(); /* RingsDeleteNotPlaner*/
	gtkActionToggleEntries[22].is_active = ringsGetRandumColors(); /* RingsRandumColors*/
	gtkActionToggleEntries[23].is_active = get_dotted_negative_contours(); /* "ContoursNegativeDotted" */
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
/*******************************************************************************************************************************/
void create_toolbar_and_popup_menu_GL(GtkWidget* box)
{
	GtkActionGroup *actionGroup = NULL;
	GtkUIManager *merge = NULL;
	GError *error = NULL;

  	merge = gtk_ui_manager_new ();
  	g_signal_connect_swapped (PrincipalWindow, "destroy", G_CALLBACK (g_object_unref), merge);

	actionGroup = gtk_action_group_new ("GabeditPopupMenuGLActions");
	gtk_action_group_add_actions (actionGroup, gtkActionEntries, numberOfGtkActionEntries, NULL);

	set_init_gtkActionToggleEntries();
	gtk_action_group_add_toggle_actions (actionGroup, gtkActionToggleEntries, numberOfGtkActionToggleEntries, NULL);
	gtk_action_group_add_radio_actions (actionGroup, rendereGeometryEntries, numberOfRenderGeometryEntries, GEOMETRY_STICK, G_CALLBACK (render_geometry_radio_action), NULL);
	/* gtk_action_group_add_radio_actions (actionGroup, renderBackGroundEntries, numberOfBackGroundEntries, BACKGROUND_BLACK, G_CALLBACK (render_background_radio_action), NULL);*/
	gtk_action_group_add_radio_actions (actionGroup, renderBackGroundEntries, numberOfBackGroundEntries, getOptCol(), G_CALLBACK (render_background_radio_action), NULL);
	gtk_action_group_add_radio_actions (actionGroup, renderSurfaceTextureEntries, numberOfRenderSurfacetextureEntries, TEXTURE_NO, G_CALLBACK (render_surface_texture_radio_action), NULL);

	gtk_action_group_add_radio_actions (actionGroup, renderSurfaceEntries, numberOfRenderSurfaceEntries, SURFACE_POSITIVENEGATIVE, G_CALLBACK (render_surface_radio_action), NULL);

	gtk_action_group_add_radio_actions (actionGroup, renderSurfacePositiveEntries, numberOfRenderSurfacePositiveEntrie, SURFACE_POSITIVE_FILL, G_CALLBACK (render_surface_positive_radio_action), NULL);
	gtk_action_group_add_radio_actions (actionGroup, renderSurfaceNegativeEntries, numberOfRenderSurfaceNegativeEntries, SURFACE_NEGATIVE_FILL, G_CALLBACK (render_surface_negative_radio_action), NULL);

	gtk_action_group_add_radio_actions (actionGroup, operationEntries, numberOfOperationEntries, OPERATION_ROTATION_FREE, G_CALLBACK (render_operation_radio_action), NULL);

  	gtk_ui_manager_insert_action_group (merge, actionGroup, 0);

	g_signal_connect (merge, "add_widget", G_CALLBACK (add_widget), box);
  	gtk_window_add_accel_group (GTK_WINDOW (PrincipalWindow), gtk_ui_manager_get_accel_group (merge));
	if (!gtk_ui_manager_add_ui_from_string (merge, uiMenuInfo, -1, &error))
	{
		g_message ("building menus failed: %s", error->message);
		g_error_free (error);
	}
	manager = merge;
}
/*********************************************************************************************************************/
static void set_sensitive_orbitals()
{
	GtkWidget *orbSave = gtk_ui_manager_get_widget (manager, "/MenuGL/Orbitals/OrbitalsGabeditSave");
	GtkWidget *orbSelection = gtk_ui_manager_get_widget (manager, "/MenuGL/Orbitals/OrbitalsSelection");
	GtkWidget *orbCapture = gtk_ui_manager_get_widget (manager, "/MenuGL/Orbitals/OrbitalsCapture");
	GtkWidget *orbCoulomb = gtk_ui_manager_get_widget (manager, "/MenuGL/Orbitals/OrbitalsCoulomb");
	GtkWidget *orbTransition = gtk_ui_manager_get_widget (manager, "/MenuGL/Orbitals/OrbitalsTransition");
	GtkWidget *orbOverlap = gtk_ui_manager_get_widget (manager, "/MenuGL/Orbitals/OrbitalsOverlap");
	gboolean sensitive = TRUE;
  	if(NAOrb<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(orbSave)) gtk_widget_set_sensitive(orbSave, sensitive);
	if(GTK_IS_WIDGET(orbSelection)) gtk_widget_set_sensitive(orbSelection, sensitive);
	if(GTK_IS_WIDGET(orbCapture)) gtk_widget_set_sensitive(orbCapture, sensitive);
	if(GTK_IS_WIDGET(orbCoulomb)) gtk_widget_set_sensitive(orbCoulomb, sensitive);
	if(GTK_IS_WIDGET(orbTransition)) gtk_widget_set_sensitive(orbTransition, sensitive);
	if(GTK_IS_WIDGET(orbOverlap)) gtk_widget_set_sensitive(orbOverlap, sensitive);
}
/*********************************************************************************************************************/
static void set_sensitive_cube()
{
	GtkWidget *cubeSave = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeLoadGabeditSave");
	GtkWidget *cubeSubtract = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeSubtract");
	GtkWidget *cubeScale = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeScale");
	GtkWidget *cubeSquare = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeSquare");
	GtkWidget *cubeRestriction = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeRestriction");
	GtkWidget *cubeAUMChargesNear = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeAIMChargesNearGrid");
	GtkWidget *cubeAUMChargesOn = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeAIMChargesOnGrid");
	GtkWidget *cubeColor = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeColorMapping");
	GtkWidget *cubeComputeLap = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeComputeLaplacian");
	GtkWidget *cubeComputeGard = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeComputeNormGradient");
	gboolean sensitive = TRUE;
  	if(!grid) sensitive = FALSE;
	if(GTK_IS_WIDGET(cubeSave)) gtk_widget_set_sensitive(cubeSave, sensitive);
	if(GTK_IS_WIDGET(cubeSubtract)) gtk_widget_set_sensitive(cubeSubtract, sensitive);
	if(GTK_IS_WIDGET(cubeScale)) gtk_widget_set_sensitive(cubeScale, sensitive);
	if(GTK_IS_WIDGET(cubeSquare)) gtk_widget_set_sensitive(cubeSquare, sensitive);
	if(GTK_IS_WIDGET(cubeRestriction)) gtk_widget_set_sensitive(cubeRestriction, sensitive);
	if(GTK_IS_WIDGET(cubeAUMChargesNear)) gtk_widget_set_sensitive(cubeAUMChargesNear, sensitive);
	if(GTK_IS_WIDGET(cubeAUMChargesOn)) gtk_widget_set_sensitive(cubeAUMChargesOn, sensitive);
	if(GTK_IS_WIDGET(cubeColor)) gtk_widget_set_sensitive(cubeColor, sensitive);
	if(GTK_IS_WIDGET(cubeComputeLap)) gtk_widget_set_sensitive(cubeComputeLap, sensitive);
	if(GTK_IS_WIDGET(cubeComputeGard)) gtk_widget_set_sensitive(cubeComputeGard, sensitive);
}
/*********************************************************************************************************************/
static void set_sensitive_density()
{
	GtkWidget *density = gtk_ui_manager_get_widget (manager, "/MenuGL/Density");
	GtkWidget *elf = gtk_ui_manager_get_widget (manager, "/MenuGL/ELF");
	GtkWidget *fed = gtk_ui_manager_get_widget (manager, "/MenuGL/Fukui");
	GtkWidget *atomic = gtk_ui_manager_get_widget (manager, "/MenuGL/Density/DensityAtomics");
	GtkWidget *bonds = gtk_ui_manager_get_widget (manager, "/MenuGL/Density/DensityBonds");
	GtkWidget *sas = gtk_ui_manager_get_widget (manager, "/MenuGL/SAS");
	GtkWidget *esp = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP");
	GtkWidget *espOrb = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP/MEPOrbitals");
	GtkWidget *espGrid = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP/MEPGrid");
	GtkWidget *espMapping = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP/MEPMapping");
	GtkWidget *espMappingMG = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP/MEPMapping/MEPMappingMG");
	GtkWidget *espMappingCG = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP/MEPMapping/MEPMappingCG");
	GtkWidget *espMappingMP = gtk_ui_manager_get_widget (manager, "/MenuGL/MEP/MEPMapping/MEPMappingMultipol");
	GtkWidget *fedElectroMapping = gtk_ui_manager_get_widget (manager, "/MenuGL/Fukui/FEDElectrophilicMapping");
	GtkWidget *fedNucleoMapping = gtk_ui_manager_get_widget (manager, "/MenuGL/Fukui/FEDNucleophilicMapping");
	GtkWidget *fedRadicalMapping = gtk_ui_manager_get_widget (manager, "/MenuGL/Fukui/FEDRadicalMapping");

	if(GTK_IS_WIDGET(esp)) gtk_widget_set_sensitive(esp, FALSE);
	if(GTK_IS_WIDGET(espGrid)) gtk_widget_set_sensitive(espGrid, FALSE);
	if(GTK_IS_WIDGET(espOrb)) gtk_widget_set_sensitive(espOrb, FALSE);
	if(GTK_IS_WIDGET(espMapping)) gtk_widget_set_sensitive(espMapping, FALSE);
	if(GTK_IS_WIDGET(espMappingMG)) gtk_widget_set_sensitive(espMappingMG, FALSE);
	if(GTK_IS_WIDGET(espMappingCG)) gtk_widget_set_sensitive(espMappingCG, FALSE);
	if(GTK_IS_WIDGET(espMappingMP)) gtk_widget_set_sensitive(espMappingMP, FALSE);
	if(GTK_IS_WIDGET(fedElectroMapping)) gtk_widget_set_sensitive(fedElectroMapping, FALSE);
	if(GTK_IS_WIDGET(fedNucleoMapping)) gtk_widget_set_sensitive(fedNucleoMapping, FALSE);
	if(GTK_IS_WIDGET(fedRadicalMapping)) gtk_widget_set_sensitive(fedRadicalMapping, FALSE);
	if(!GeomOrb)
	{
		if(GTK_IS_WIDGET(sas)) gtk_widget_set_sensitive(sas, FALSE);
		if(GTK_IS_WIDGET(density)) gtk_widget_set_sensitive(density, FALSE);
		if(GTK_IS_WIDGET(elf)) gtk_widget_set_sensitive(elf, FALSE);
		if(GTK_IS_WIDGET(fed)) gtk_widget_set_sensitive(fed, FALSE);
		return;
	}
	if(GeomOrb && GTK_IS_WIDGET(esp)) gtk_widget_set_sensitive(esp, TRUE);
	if( grid && GTK_IS_WIDGET(espGrid)) gtk_widget_set_sensitive(espGrid, TRUE);
	if( CoefAlphaOrbitals && GeomOrb && GTK_IS_WIDGET(espOrb)) gtk_widget_set_sensitive(espOrb, TRUE);
	if( grid && GeomOrb && GTK_IS_WIDGET(espMapping)) gtk_widget_set_sensitive(espMapping, TRUE);
	if( grid && CoefAlphaOrbitals && GeomOrb && GTK_IS_WIDGET(espMapping)) 
	{
		if(GTK_IS_WIDGET(espMappingMG)) gtk_widget_set_sensitive(espMappingMG, TRUE);
		if(GTK_IS_WIDGET(espMappingCG)) gtk_widget_set_sensitive(espMappingCG, TRUE);
		if(GTK_IS_WIDGET(espMappingMP)) gtk_widget_set_sensitive(espMappingMP, TRUE);
	}
	if( grid && GeomOrb) 
	{
		if(GTK_IS_WIDGET(fedElectroMapping)) gtk_widget_set_sensitive(fedElectroMapping, TRUE);
		if(GTK_IS_WIDGET(fedNucleoMapping)) gtk_widget_set_sensitive(fedNucleoMapping, TRUE);
		if(GTK_IS_WIDGET(fedRadicalMapping)) gtk_widget_set_sensitive(fedRadicalMapping, TRUE);
	}

	if(GTK_IS_WIDGET(sas)) gtk_widget_set_sensitive(sas, TRUE);
	if(!GeomOrb || !CoefAlphaOrbitals)
	{
		if(GTK_IS_WIDGET(density)) gtk_widget_set_sensitive(density, FALSE);
		if(GTK_IS_WIDGET(elf)) gtk_widget_set_sensitive(elf, FALSE);
		if(GTK_IS_WIDGET(fed)) gtk_widget_set_sensitive(fed, FALSE);
		return;
	}
	if(GTK_IS_WIDGET(density)) gtk_widget_set_sensitive(density, TRUE);
	if(GTK_IS_WIDGET(elf)) gtk_widget_set_sensitive(elf, TRUE);
	if(GTK_IS_WIDGET(fed)) gtk_widget_set_sensitive(fed, TRUE);

	if(!AOAvailable)
	{
		if(GTK_IS_WIDGET(atomic)) gtk_widget_set_sensitive(atomic, FALSE);
		if(GTK_IS_WIDGET(bonds)) gtk_widget_set_sensitive(bonds, FALSE);
		return;
	}
	if(GTK_IS_WIDGET(atomic)) gtk_widget_set_sensitive(atomic, TRUE);
	if(GTK_IS_WIDGET(bonds)) gtk_widget_set_sensitive(bonds, TRUE);
}
/*********************************************************************************************************************/
static void set_sensitive_contours()
{
	GtkWidget *contours = gtk_ui_manager_get_widget (manager, "/MenuGL/Contours");
	GtkWidget *contours1 = gtk_ui_manager_get_widget (manager, "/MenuGL/Contours/ContoursFirst");
	GtkWidget *contours2 = gtk_ui_manager_get_widget (manager, "/MenuGL/Contours/ContoursSecond");
	GtkWidget *contours3 = gtk_ui_manager_get_widget (manager, "/MenuGL/Contours/ContoursThird");
	GtkWidget *contoursOther = gtk_ui_manager_get_widget (manager, "/MenuGL/Contours/ContoursOther");
	gboolean s = TRUE;

	if(!GeomOrb)
	{
		gtk_widget_set_sensitive(contours, FALSE);
		return;
	}
	gtk_widget_set_sensitive(contours, TRUE);
	if(!grid)  s = FALSE;

	if(GTK_IS_WIDGET(contours1)) gtk_widget_set_sensitive(contours1, s);
	if(GTK_IS_WIDGET(contours2)) gtk_widget_set_sensitive(contours2, s);
	if(GTK_IS_WIDGET(contours3)) gtk_widget_set_sensitive(contours3, s);

	if(!GeomOrb || !CoefAlphaOrbitals)
	{
		if(GTK_IS_WIDGET(contoursOther)) gtk_widget_set_sensitive(contoursOther, FALSE);
		return;
	}
	if(GTK_IS_WIDGET(contoursOther)) gtk_widget_set_sensitive(contoursOther, TRUE);
}
/*********************************************************************************************************************/
static void set_sensitive_colorcoded_planes()
{
	GtkWidget *colorcodedplanes = gtk_ui_manager_get_widget (manager, "/MenuGL/PlanesColorCoded");
	GtkWidget *colorcodedplanes1 = gtk_ui_manager_get_widget (manager, "/MenuGL/PlanesColorCoded/PlanesColorCodedFirst");
	GtkWidget *colorcodedplanes2 = gtk_ui_manager_get_widget (manager, "/MenuGL/PlanesColorCoded/PlanesColorCodedSecond");
	GtkWidget *colorcodedplanes3 = gtk_ui_manager_get_widget (manager, "/MenuGL/PlanesColorCoded/PlanesColorCodedThird");
	GtkWidget *colorcodedplanesOther = gtk_ui_manager_get_widget (manager, "/MenuGL/PlanesColorCoded/PlanesColorCodedOther");
	gboolean s = TRUE;

	if(!GeomOrb)
	{
		gtk_widget_set_sensitive(colorcodedplanes, FALSE);
		return;
	}
	gtk_widget_set_sensitive(colorcodedplanes, TRUE);
	if(!grid)  s = FALSE;

	if(GTK_IS_WIDGET(colorcodedplanes1)) gtk_widget_set_sensitive(colorcodedplanes1, s);
	if(GTK_IS_WIDGET(colorcodedplanes2)) gtk_widget_set_sensitive(colorcodedplanes2, s);
	if(GTK_IS_WIDGET(colorcodedplanes3)) gtk_widget_set_sensitive(colorcodedplanes3, s);

	if(!GeomOrb || !CoefAlphaOrbitals)
	{
		if(GTK_IS_WIDGET(colorcodedplanesOther)) gtk_widget_set_sensitive(colorcodedplanesOther, FALSE);
		return;
	}
	if(GTK_IS_WIDGET(colorcodedplanesOther)) gtk_widget_set_sensitive(colorcodedplanesOther, TRUE);
}
/*********************************************************************************************************************/
static void set_sensitive_surfaces()
{
	GtkWidget *surfaces = gtk_ui_manager_get_widget (manager, "/MenuGL/Surfaces");
	gboolean s = TRUE;
	if(!grid) s = FALSE;

	if(GTK_IS_WIDGET(surfaces)) gtk_widget_set_sensitive(surfaces, s);
}
/*********************************************************************************************************************/
static void set_sensitive_set()
{
	GtkWidget *computeDipole = gtk_ui_manager_get_widget (manager, "/MenuGL/Set/SetDipoleDensity");
	gboolean sensitive = TRUE;
  	if(!grid) sensitive = FALSE;
	if(GTK_IS_WIDGET(computeDipole)) gtk_widget_set_sensitive(computeDipole, sensitive);
}
/*********************************************************************************************************************/
static void set_sensitive_export()
{
	GtkWidget *povray = gtk_ui_manager_get_widget (manager, "/MenuGL/Export");
	gboolean sensitive = TRUE;
  	if(!GeomOrb) sensitive = FALSE;
	if(GTK_IS_WIDGET(povray)) gtk_widget_set_sensitive(povray, sensitive);
}
/*********************************************************************************************************************/
static void set_sensitive_animation()
{
	GtkWidget *rotation = gtk_ui_manager_get_widget (manager, "/MenuGL/Animation/AnimationRotation");
	GtkWidget *contours = gtk_ui_manager_get_widget (manager, "/MenuGL/Animation/AnimationContours");
	GtkWidget *colorPlane = gtk_ui_manager_get_widget (manager, "/MenuGL/Animation/AnimationPlanesColorcoded");
	GtkWidget *surfaces = gtk_ui_manager_get_widget (manager, "/MenuGL/Animation/AnimationIsosurface");
	gboolean sRotation = TRUE;
	gboolean sContours = TRUE;
	gboolean sPlanes = TRUE;
	gboolean sSurface = TRUE;
  	if(!grid)
	{
		sSurface = FALSE;
		sPlanes = FALSE;
		sContours = FALSE;
	}
	if(!GeomOrb) sRotation = FALSE;

	if(GTK_IS_WIDGET(rotation)) gtk_widget_set_sensitive(rotation, sRotation);
	if(GTK_IS_WIDGET(contours)) gtk_widget_set_sensitive(contours, sContours);
	if(GTK_IS_WIDGET(colorPlane)) gtk_widget_set_sensitive(colorPlane, sPlanes);
	if(GTK_IS_WIDGET(surfaces)) gtk_widget_set_sensitive(surfaces, sSurface);
}
/*********************************************************************************************************************/
static void set_sensitive_png_background()
{
	guchar color[3];
	gint numCol = get_background_color(color);
	GtkWidget *pngTrans = gtk_ui_manager_get_widget (manager, "/MenuGL/ScreenCapture/ScreenCapturePNGNoBackGround");
	gboolean sensitive = TRUE;

	if(numCol<0) sensitive = FALSE;
	if(GTK_IS_WIDGET(pngTrans)) gtk_widget_set_sensitive(pngTrans, sensitive);
}
/*********************************************************************************************************************/
gboolean popuo_menu_GL(guint button, guint32 time)
{
	GtkWidget *menu = gtk_ui_manager_get_widget (manager, "/MenuGL");
	if (GTK_IS_MENU (menu)) 
	{

		set_sensitive_orbitals();
		set_sensitive_cube();
		set_sensitive_density();
		set_sensitive_contours();
		set_sensitive_colorcoded_planes();
		set_sensitive_surfaces();
		set_sensitive_set();
		set_sensitive_export();
		set_sensitive_animation();
		set_sensitive_png_background();
		gtk_menu_popup (GTK_MENU (menu), NULL, NULL, NULL, NULL, button, time);
		return TRUE;
	}
	else printf("Erreur menu n'est pas un menu\n");
	return FALSE;
}
/*********************************************************************************************************************/
void rafresh_perspective_button()
{
	GtkAction * action = gtk_ui_manager_get_action(manager, "/ToolbarGL/RenderPerspective");

	if(GTK_IS_TOGGLE_ACTION(action))
	{
  		gboolean perspective = FALSE;
  		gdouble aspect, zn, zf, zo;
		get_camera_values(&zn, &zf, &zo, &aspect, &perspective);
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action), perspective);

	}
	else
		printf("C'est une autre widget\n");
}
/*********************************************************************************************************************/
