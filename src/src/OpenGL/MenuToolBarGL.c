/* MenuToolBarGL.c */
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
#include "GlobalOrb.h"
#include "../OpenGL/GeomOrbXYZ.h"
#include "../OpenGL/UtilsOrb.h"
#include "../OpenGL/GridCube.h"
#include "../OpenGL/GridAdfOrbitals.h"
#include "../OpenGL/GridAdfDensity.h"
#include "../OpenGL/GridM2MSI.h"
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
#include "../OpenGL/AnimationContours.h"
#include "../OpenGL/AnimationPlanesMapped.h"
#include "../OpenGL/AnimationIsoSurface.h"
#include "../OpenGL/Dipole.h"
#include "../OpenGL/AxisGL.h"
#include "../OpenGL/PrincipalAxisGL.h"
#include "../OpenGL/PovrayGL.h"
#include "../OpenGL/StatusOrb.h"
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
	gfloat min = 0;
	gfloat max = 0;
  	gboolean perspective = FALSE;
  	gfloat zn, zf, zo;

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
	get_camera_values(&zn, &zf, &zo, &perspective);
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
	else if(!strcmp(name ,"GeometryMPQCFirst"))
 		file_chooser_open(gl_read_first_mpqc_file,"Read the first geometry from a MPQC output file",GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMPQCLast"))
 		file_chooser_open(gl_read_last_mpqc_file,"Read the last geometry from a MPQC output file",GABEDIT_TYPEFILE_MPQC,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryGabedit"))
 		file_chooser_open(gl_read_gabedit_file,"Read geometry from a gabedit file",GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name ,"GeometryMolden"))
 		file_chooser_open(gl_read_molden_file,"Read geometry from a molden file",GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_ORB);
	/*
	else if(!strcmp(name , "OrbitalsDalton"))
 			file_chooser_open(read_dalton_orbitals_sel,"Read Geometry and Orbitals from a Dalton output file",GABEDIT_TYPEFILE_DALTON,GABEDIT_TYPEWIN_ORB);
			*/
	else if(!strcmp(name , "OrbitalsGaussian"))
 			file_chooser_open(read_gauss_orbitals_sel,"Read Geometry and Orbitals from a Gaussian output file",GABEDIT_TYPEFILE_GAUSSIAN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsMolpro"))
 			file_chooser_open(read_molpro_orbitals_sel,"Read Geometry and Orbitals from a Molpro output file",GABEDIT_TYPEFILE_MOLPRO,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsGabeditRead"))
 			file_chooser_open(read_gabedit_orbitals_sel,"Read Geometry and Orbitals from a Gabedit file",GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsMolden"))
 			file_chooser_open(read_molden_orbitals_sel,"Read Geometry and Orbitals from a Molden file",GABEDIT_TYPEFILE_MOLDEN,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsGabeditSave"))
			file_chooser_save(save_gabedit_orbitals_sel,"Save Geometry and Orbitals in a Gabedit file",GABEDIT_TYPEFILE_GABEDIT,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "OrbitalsSelection"))
	{
			TypeGrid = GABEDIT_TYPEGRID_ORBITAL;
			create_list_orbitals();
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
	else if(!strcmp(name , "CubeLoadMolcasM2MSIOrbitals"))
 		file_chooser_open(load_m2msi_file_orbitals,"Load Orbitals from m2msi file",GABEDIT_TYPEFILE_CUBEM2MSI,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolcasM2MSIDensity"))
 		file_chooser_open(load_m2msi_file_density,"Load density from m2msi file",GABEDIT_TYPEFILE_CUBEM2MSI,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolcasCubeOrbitals"))
 		file_chooser_open(load_cube_gauss_orbitals_file,"Load Orbitals from molcas cube file",GABEDIT_TYPEFILE_CUBEMOLCAS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadMolcasCubeDensity"))
 		file_chooser_open(load_cube_gauss_density_file,"Load density from molcas cube file",GABEDIT_TYPEFILE_CUBEMOLCAS,GABEDIT_TYPEWIN_ORB);
	else if(!strcmp(name , "CubeLoadGabeditRead"))
 		file_chooser_open(load_cube_gabedit_file,"Load Gabedit cube file",GABEDIT_TYPEFILE_CUBEGABEDIT,GABEDIT_TYPEWIN_ORB);
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
	else if(!strcmp(name , "ExportPovray")) create_save_povray_orb(PrincipalWindow);
	else if(!strcmp(name , "AnimationVibration")) vibrationDlg();
	else if(!strcmp(name , "AnimationGeometryConvergence")) geometryConvergenceDlg();
	else if(!strcmp(name , "AnimationRotation")) animationRotationDlg();
	else if(!strcmp(name , "AnimationContours")) animationContoursDlg();
	else if(!strcmp(name , "AnimationPlanesColorcoded")) animationPlanesMappedDlg();
	else if(!strcmp(name , "AnimationIsosurface")) animationIsoSurfaceDlg();

	else if(!strcmp(name , "Close")) close_window_orb(NULL,NULL);
}
/*********************************************************************************************************************/
static GtkActionEntry gtkActionEntries[] =
{
	{"Geometry",     NULL, "_Geometry"},
	{"GeometryXYZ", NULL, "Read the geometry from a _xyz file", NULL, "Read the geometry from a xyz file", G_CALLBACK (activate_action) },
	{"GeometryPDB", GABEDIT_STOCK_PDB, "Read the geometry from a _pdb file", NULL, "Read the geometry from a pdb file", G_CALLBACK (activate_action) },
	{"GeometryHIN", NULL, "Read the geometry from a _hyperchem file", NULL, "Read the geometry from a hyperchem file", G_CALLBACK (activate_action) },
	{"GeometryOpenBabel", GABEDIT_STOCK_OPEN_BABEL, "Other format (using Open _Babel)", NULL, "Other format (using Open _Babel)", G_CALLBACK (activate_action) },
	{"GeometryDaltonFirst", GABEDIT_STOCK_DALTON, "Read the _first geometry from a Dalton output log file", 
		NULL, "Read the first geometry from a Dalton output file", G_CALLBACK (activate_action) },
	{"GeometryDaltonLast", GABEDIT_STOCK_DALTON, "Read the _last geometry from a Dalton output log file", 
		NULL, "Read the last geometry from a Dalton output file", G_CALLBACK (activate_action) },
	{"GeometryGaussianFirst", GABEDIT_STOCK_GAUSSIAN, "Read the _first geometry from a gaussian log file", 
		NULL, "Read the first geometry from a gaussian log file", G_CALLBACK (activate_action) },
	{"GeometryGaussianLast", GABEDIT_STOCK_GAUSSIAN, "Read the _last geometry from a gaussian file", 
		NULL, "Read the last geometry from a gaussian log file", G_CALLBACK (activate_action) },
	{"GeometryMolcasFirst", GABEDIT_STOCK_MOLCAS, "Read the _first geometry from a molcas output file", 
		NULL, "Read the first geometry from a molcas output file", G_CALLBACK (activate_action) },
	{"GeometryMolcasLast", GABEDIT_STOCK_MOLCAS, "Read the _last geometry from a molcas output file", 
		NULL, "Read the last geometry from a molcas output file", G_CALLBACK (activate_action) },
	{"GeometryMolproFirst", GABEDIT_STOCK_MOLPRO, "Read the _first geometry from a molpro output file", 
		NULL, "Read the first geometry from a molpro output file", G_CALLBACK (activate_action) },
	{"GeometryMolproLast", GABEDIT_STOCK_MOLPRO, "Read the _last geometry from a molpro output file", 
		NULL, "Read the last geometry from a molpro output file", G_CALLBACK (activate_action) },
	{"GeometryMPQCFirst", GABEDIT_STOCK_MPQC, "Read the _first geometry from a MPQC output file", 
		NULL, "Read the first geometry from a MPQC output file", G_CALLBACK (activate_action) },
	{"GeometryMPQCLast", GABEDIT_STOCK_MPQC, "Read the _last geometry from a MPQC output file", 
		NULL, "Read the last geometry from a MPQC output file", G_CALLBACK (activate_action) },
	{"GeometryGabedit", GABEDIT_STOCK_GABEDIT, "Read from a G_abedit file", 
		NULL, "Read the geometry from a Gabedit file", G_CALLBACK (activate_action) },
	{"GeometryMolden", GABEDIT_STOCK_MOLDEN, "Read from a Mol_den file", 
		NULL, "Read the from a Molden file", G_CALLBACK (activate_action) },
	{"Orbitals",     NULL, "_Orbitals"},
	/*
	{"OrbitalsDalton", GABEDIT_STOCK_DALTON, "Read geometry and orbiatls from a _Dalton output file", 
		NULL, "Read geometry and orbiatls from a Dalton output file", G_CALLBACK (activate_action) },
		*/
	{"OrbitalsGaussian", GABEDIT_STOCK_GAUSSIAN, "Read geometry and orbiatls from a _Gaussian log file", 
		NULL, "Read geometry and orbiatls from a Gaussian log file", G_CALLBACK (activate_action) },
	{"OrbitalsMolpro", GABEDIT_STOCK_MOLPRO, "Read geometry and orbiatls from a Mol_pro output file", 
		NULL, "Read geometry and orbiatls from a Molpro output file", G_CALLBACK (activate_action) },
	{"OrbitalsGabeditRead", GABEDIT_STOCK_GABEDIT, "Read geometry and orbiatls from a G_abedit file", 
		NULL, "Read geometry and orbiatls from a Gabedit file", G_CALLBACK (activate_action) },
	{"OrbitalsMolden", GABEDIT_STOCK_MOLDEN, "Read geometry and orbiatls from a Mol_den file", 
		NULL, "Read geometry and orbiatls from a Molden file", G_CALLBACK (activate_action) },
	{"OrbitalsGabeditSave", GABEDIT_STOCK_SAVE, "Save in a G_abedit file", 
		NULL, "Save in Gabedit file", G_CALLBACK (activate_action) },
	{"OrbitalsSelection", GABEDIT_STOCK_SELECT_ALL, "_Selection", 
		NULL, "Select an orbital", G_CALLBACK (activate_action) },
	{"Cube",     NULL, "_Cube"},

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
	{"CubeLoadMolcasM2MSI",     NULL, "_M2MSI ASCII file"},
	{"CubeLoadMolcasM2MSIOrbitals", NULL, "_Orbitals", NULL, "Read the orbitals from a M2MSI ascii file", G_CALLBACK (activate_action) },
	{"CubeLoadMolcasM2MSIDensity", NULL, "_Density", NULL, "Read the density from a M2MSI ascii file", G_CALLBACK (activate_action) },
	{"CubeLoadMolcasCube",     NULL, "_Cube file"},
	{"CubeLoadMolcasCubeOrbitals", NULL, "_Orbitals", NULL, "Read the orbitals from a molcas cube file", G_CALLBACK (activate_action) },
	{"CubeLoadMolcasCubeDensity", NULL, "_Density", NULL, "Read the density from a molcas cube file", G_CALLBACK (activate_action) },

	{"CubeLoadGabeditRead", GABEDIT_STOCK_GABEDIT, "Load G_abedit cube file", NULL, "Read a Gabedit cube file", G_CALLBACK (activate_action) },
	{"CubeLoadGabeditSave", GABEDIT_STOCK_SAVE, "_Save", NULL, "Save in a Gabedit cube file", G_CALLBACK (activate_action) },
	{"CubeSubtract", NULL, "Su_btract", NULL, "Subtract", G_CALLBACK (activate_action) },
	{"CubeScale", NULL, "Scal_e", NULL, "Scale", G_CALLBACK (activate_action) },
	{"CubeColorMapping", NULL, "_Color Mapping", NULL, "Color Mapping", G_CALLBACK (activate_action) },

	{"Density",     NULL, "_Density"},
	{"DensityElectronic", NULL, "_Electronic", NULL, "Compute and draw electronic density", G_CALLBACK (activate_action) },
	{"DensityBonds", NULL, "_Bonds", NULL, "Compute and draw bonds (electronic-atomics)", G_CALLBACK (activate_action) },
	{"DensitySpin", NULL, "_Spin", NULL, "Compute and draw spin density", G_CALLBACK (activate_action) },
	{"DensityAtomics", NULL, "_Atomic", NULL, "Compute and draw electronic density of atoms", G_CALLBACK (activate_action) },

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
	{"Render",     NULL, "_Render"},
	{"RenderGeometry",     NULL, "_Geometry"},
	{"RenderSurface",     NULL, "_Surface"},
	{"RenderSurfacePositive",     NULL, "_Positive surface"},
	{"RenderSurfaceNegative",     NULL, "_Negative surface"},
	{"RenderBackGround",     NULL, "_BackGround"},
	{"RenderLight",     NULL, "_Light"},
	{"RenderOptimal",     NULL, "_Optimal"},
	{"RenderOptimal", GABEDIT_STOCK_O, "_Optimal", NULL, "Optimal camera", G_CALLBACK (activate_action) },
	{"Set",     NULL, "_Set"},
	{"Operation",     NULL, "_Operation"},
	{"SetCamera", GABEDIT_STOCK_CAMERA, "_Camera", NULL, "set the camera", G_CALLBACK (activate_action) },
	{"SetLigthPositions", NULL, "_Ligth positions", NULL, "set Ligth positions", G_CALLBACK (activate_action) },
	{"SetSurfaceColors", NULL, "_Surface colors", NULL, "set surface colors", G_CALLBACK (activate_action) },
	{"SetDipole", NULL, "_Dipole", NULL, "set dipole", G_CALLBACK (activate_action) },
	{"SetDipoleDensity", NULL, "_Compute Dipole from density", NULL, "Compute Dipole from density", G_CALLBACK (activate_action) },
	{"SetPropertiesOfAtoms", NULL, "P_roperties of atoms", NULL, "set the properties of atoms", G_CALLBACK (activate_action) },
	{"SetHydrogenBondsParameters", NULL, "_Hydrogen bonds parameters", NULL, "set the Hydrogen bonds parameters", G_CALLBACK (activate_action) },
	{"SetXYZAxesProperties", NULL, "XYZ _Axes properties", NULL, "set the properties of the XYZ Axes", G_CALLBACK (activate_action) },
	{"SetPrincipalAxesProperties", NULL, "_Principal Axes properties", NULL, "set the properties of the principal Axes", G_CALLBACK (activate_action) },
	{"SetPovrayBackGround", NULL, "_Povray background", NULL, "set the background for the Povray file", G_CALLBACK (activate_action) },
	{"ScreenCapture",     NULL, "Screen Ca_pture"},
	{"ScreenCaptureJPG", NULL, "_JPG format", NULL, "save image in a JPG file", G_CALLBACK (activate_action) },
	{"ScreenCapturePPM", NULL, "_PPM format", NULL, "save image in a PPM file", G_CALLBACK (activate_action) },
	{"ScreenCaptureBMP", NULL, "_BMP format", NULL, "save image in a BMP file", G_CALLBACK (activate_action) },
	{"ScreenCapturePNG", NULL, "_PNG format", NULL, "save image in a PNG file", G_CALLBACK (activate_action) },
	{"ScreenCapturePNGNoBackGround", NULL, "_PNG format(tansparent background)", NULL, "save image in a PNG file without background", G_CALLBACK (activate_action) },
	{"ScreenCapturePS", NULL, "P_S format", NULL, "save image in a PS file", G_CALLBACK (activate_action) },

	{"Export",     NULL, "_Export"},
	{"ExportPovray", NULL, "_Povray", NULL, "create a povray file", G_CALLBACK (activate_action) },

	{"Animation",     NULL, "_Animation"},
	{"AnimationVibration", NULL, "_Vibration", NULL, "Vibration", G_CALLBACK (activate_action) },
	{"AnimationGeometryConvergence", NULL, "Geometry _convergence", NULL, "Animation of Geometry convergence", G_CALLBACK (activate_action) },
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
	else if(!strcmp(name,"RenderhydrogenBonds"))
	{
		ShowHBondOrb = !ShowHBondOrb;
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
  		gfloat zn, zf, zo;
		get_camera_values(&zn, &zf, &zo, &perspective);

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
}

static GtkToggleActionEntry gtkActionToggleEntries[] =
{
	{ "RenderSurfaceTransparency", NULL, "_Transparency", NULL, "render transparency", G_CALLBACK (toggle_action), TRUE },
	{ "RenderLightOnOff1", NULL, "OnOff _1", NULL, "On/Of the light number 1", G_CALLBACK (toggle_action), TRUE },
	{ "RenderLightOnOff2", NULL, "OnOff _2", NULL, "On/Of the light number 2", G_CALLBACK (toggle_action), FALSE },
	{ "RenderLightOnOff3", NULL, "OnOff _3", NULL, "On/Of the light number 3", G_CALLBACK (toggle_action), FALSE },
	{ "RenderDipole", NULL, "Show _dipole", NULL, "Show dipole", G_CALLBACK (toggle_action), FALSE },
	{ "RenderhydrogenBonds", NULL, "Show _hydrogen bonds", NULL, "Show hydrogen bonds", G_CALLBACK (toggle_action), FALSE },
	{ "RenderXYZAxes", NULL, "Show XYZ _Axes", NULL, "Show XYZ Axes", G_CALLBACK (toggle_action), FALSE },
	{ "RenderPrincipalAxes", NULL, "Show the _principal Axes", NULL, "Show principal Axes", G_CALLBACK (toggle_action), FALSE },
	{ "RenderPerspective", GABEDIT_STOCK_PERSPECTIVE, "Perspective", NULL, "Perspective/Orthographic", G_CALLBACK (toggle_action), TRUE},
	{ "ShowToolBar", NULL, "_Show toolbar", NULL, "show toolbar", G_CALLBACK (toggle_action), TRUE },
	{ "ShowStatusHandleBox", NULL, "_show status handlebox", NULL, "show status handlebox", G_CALLBACK (toggle_action), TRUE},
	{ "ShowProgressBar", NULL, "_show progress bar", NULL, "show progress bar", G_CALLBACK (toggle_action), TRUE},
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
"    <menu name=\"_Geometry\" action=\"Geometry\">\n"
"      <menuitem name=\"GeometryXYZ\" action=\"GeometryXYZ\" />\n"
"      <menuitem name=\"GeometryPDB\" action=\"GeometryPDB\" />\n"
"      <menuitem name=\"GeometryHIN\" action=\"GeometryHIN\" />\n"
"      <separator name=\"sepMenuXYZ\" />\n"
"      <menuitem name=\"GeometryDaltonFirst\" action=\"GeometryDaltonFirst\" />\n"
"      <menuitem name=\"GeometryDaltonLast\" action=\"GeometryDaltonLast\" />\n"
"      <separator name=\"sepMenuDaltonGeom\" />\n"
"      <menuitem name=\"GeometryGaussianFirst\" action=\"GeometryGaussianFirst\" />\n"
"      <menuitem name=\"GeometryGaussianLast\" action=\"GeometryGaussianLast\" />\n"
"      <separator name=\"sepMenuGaussianGeom\" />\n"
"      <menuitem name=\"GeometryMolcasFirst\" action=\"GeometryMolcasFirst\" />\n"
"      <menuitem name=\"GeometryMolcasLast\" action=\"GeometryMolcasLast\" />\n"
"      <separator name=\"sepMenuMolcasGeom\" />\n"
"      <menuitem name=\"GeometryMolproFirst\" action=\"GeometryMolproFirst\" />\n"
"      <menuitem name=\"GeometryMolproLast\" action=\"GeometryMolproLast\" />\n"
"      <separator name=\"sepMenuMolproGeom\" />\n"
"      <menuitem name=\"GeometryMPQCFirst\" action=\"GeometryMPQCFirst\" />\n"
"      <menuitem name=\"GeometryMPQCLast\" action=\"GeometryMPQCLast\" />\n"
"      <separator name=\"sepMenuMPQCGeom\" />\n"
"      <menuitem name=\"GeometryGabedit\" action=\"GeometryGabedit\" />\n"
"      <separator name=\"sepMenuGabeditGeom\" />\n"
"      <menuitem name=\"GeometryMolden\" action=\"GeometryMolden\" />\n"
"      <separator name=\"sepMenuBABEL\" />\n"
"      <menuitem name=\"GeometryOpenBabel\" action=\"GeometryOpenBabel\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuOrbitals\" />\n"
"    <menu name=\"Orbitals\" action = \"Orbitals\">\n"
//"      <menuitem name=\"OrbitalsDalton\" action=\"OrbitalsDalton\" />\n"
"      <menuitem name=\"OrbitalsGaussian\" action=\"OrbitalsGaussian\" />\n"
"      <menuitem name=\"OrbitalsMolpro\" action=\"OrbitalsMolpro\" />\n"
"      <menuitem name=\"OrbitalsGabeditRead\" action=\"OrbitalsGabeditRead\" />\n"
"      <menuitem name=\"OrbitalsMolden\" action=\"OrbitalsMolden\" />\n"
"      <separator name=\"sepMenuGabeditOrbSave\" />\n"
"      <menuitem name=\"OrbitalsGabeditSave\" action=\"OrbitalsGabeditSave\" />\n"
"      <separator name=\"sepMenuGabeditOrbSel\" />\n"
"      <menuitem name=\"OrbitalsSelection\" action=\"OrbitalsSelection\" />\n"
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
"        <menu name=\"CubeLoadMolcasM2MSI\" action = \"CubeLoadMolcasM2MSI\">\n"
"          <menuitem name=\"CubeLoadMolcasM2MSIOrbitals\" action=\"CubeLoadMolcasM2MSIOrbitals\" />\n"
"          <menuitem name=\"CubeLoadMolcasM2MSIDensity\" action=\"CubeLoadMolcasM2MSIDensity\" />\n"
"        </menu>\n"
"        <menu name=\"CubeLoadMolcasCube\" action = \"CubeLoadMolcasCube\">\n"
"          <menuitem name=\"CubeLoadMolcasCubeOrbitals\" action=\"CubeLoadMolcasCubeOrbitals\" />\n"
"          <menuitem name=\"CubeLoadMolcasCubeDensity\" action=\"CubeLoadMolcasCubeDensity\" />\n"
"        </menu>\n"
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
"      <separator name=\"sepMenuCubeLoadGabeditRead\" />\n"
"      <menuitem name=\"CubeLoadGabeditRead\" action=\"CubeLoadGabeditRead\" />\n"
"      <separator name=\"sepMenuCubeLoadGabeditSave\" />\n"
"      <menuitem name=\"CubeLoadGabeditSave\" action=\"CubeLoadGabeditSave\" />\n"
"      <separator name=\"sepMenuCubeSub\" />\n"
"      <menuitem name=\"CubeSubtract\" action=\"CubeSubtract\" />\n"
"      <separator name=\"sepMenuCubeScale\" />\n"
"      <menuitem name=\"CubeScale\" action=\"CubeScale\" />\n"
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

"    <separator name=\"sepMenuContours\" />\n"
"    <menu name=\"Contours\" action = \"Contours\">\n"
"        <menuitem name=\"ContoursFirst\" action=\"ContoursFirst\" />\n"
"        <menuitem name=\"ContoursSecond\" action=\"ContoursSecond\" />\n"
"        <menuitem name=\"ContoursThird\" action=\"ContoursThird\" />\n"
"        <menuitem name=\"ContoursOther\" action=\"ContoursOther\" />\n"
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
"       <separator name=\"sepMenuRenderDipole\" />\n"
"      <menuitem name=\"RenderDipole\" action=\"RenderDipole\" />\n"
"      <menuitem name=\"RenderhydrogenBonds\" action=\"RenderhydrogenBonds\" />\n"
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
"        <separator name=\"sepMenuSetPropOfAtoms\" />\n"
"        <menuitem name=\"SetPropertiesOfAtoms\" action=\"SetPropertiesOfAtoms\" />\n"
"        <separator name=\"sepMenuSetHBond\" />\n"
"        <menuitem name=\"SetHydrogenBondsParameters\" action=\"SetHydrogenBondsParameters\" />\n"
"        <separator name=\"sepMenuSetXYZ\" />\n"
"        <menuitem name=\"SetXYZAxesProperties\" action=\"SetXYZAxesProperties\" />\n"
"        <menuitem name=\"SetPrincipalAxesProperties\" action=\"SetPrincipalAxesProperties\" />\n"
"        <separator name=\"sepMenuSetPovRay\" />\n"
"        <menuitem name=\"SetPovrayBackGround\" action=\"SetPovrayBackGround\" />\n"
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
"    </menu>\n"
"    <separator name=\"sepMenuExport\" />\n"
"    <menu name=\"Export\" action = \"Export\">\n"
"        <menuitem name=\"ExportPovray\" action=\"ExportPovray\" />\n"
"    </menu>\n"
"    <separator name=\"sepMenuAnimation\" />\n"
"    <menu name=\"Animation\" action = \"Animation\">\n"
"        <menuitem name=\"AnimationVibration\" action=\"AnimationVibration\" />\n"
"        <separator name=\"sepMenuAnimationGeomConv\" />\n"
"        <menuitem name=\"AnimationGeometryConvergence\" action=\"AnimationGeometryConvergence\" />\n"
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
  	gfloat zn, zf, zo;
  	gboolean perspective = FALSE;

	gtkActionToggleEntries[0].is_active = TRUE; /* "RenderSurfaceTransparency" */
	gtkActionToggleEntries[1].is_active = TRUE; /* RenderLightOnOff1 */
	gtkActionToggleEntries[2].is_active = FALSE; /* RenderLightOnOff2 */
	gtkActionToggleEntries[3].is_active = FALSE; /* RenderLightOnOff3 */
	gtkActionToggleEntries[4].is_active = ShowDipoleOrb; /* RenderDipole */
	gtkActionToggleEntries[5].is_active = ShowHBondOrb ; /* RenderhydrogenBonds */
	gtkActionToggleEntries[6].is_active = testShowAxis() ; /* RenderXYZAxes */
	gtkActionToggleEntries[7].is_active = testShowPrincipalAxisGL() ; /* RenderPrincipalAxes */

  	get_camera_values(&zn, &zf, &zo, &perspective);
	gtkActionToggleEntries[8].is_active = perspective; /* RenderPerspective */
	gtkActionToggleEntries[9].is_active = TRUE; /* ShowToolBar */
	gtkActionToggleEntries[10].is_active = TRUE; /* ShowStatusHandleBox */
	gtkActionToggleEntries[11].is_active = TRUE; /* ShowProgressBar */
}

/*******************************************************************************************************************************/
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
	gtk_action_group_add_radio_actions (actionGroup, renderBackGroundEntries, numberOfBackGroundEntries, BACKGROUND_BLACK, G_CALLBACK (render_background_radio_action), NULL);
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
	gboolean sensitive = TRUE;
  	if(NAOrb<1) sensitive = FALSE;
	if(GTK_IS_WIDGET(orbSave)) gtk_widget_set_sensitive(orbSave, sensitive);
	if(GTK_IS_WIDGET(orbSelection)) gtk_widget_set_sensitive(orbSelection, sensitive);
}
/*********************************************************************************************************************/
static void set_sensitive_cube()
{
	GtkWidget *cubeSave = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeLoadGabeditSave");
	GtkWidget *cubeSubtract = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeSubtract");
	GtkWidget *cubeScale = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeScale");
	GtkWidget *cubeColor = gtk_ui_manager_get_widget (manager, "/MenuGL/Cube/CubeColorMapping");
	gboolean sensitive = TRUE;
  	if(!grid) sensitive = FALSE;
	if(GTK_IS_WIDGET(cubeSave)) gtk_widget_set_sensitive(cubeSave, sensitive);
	if(GTK_IS_WIDGET(cubeSubtract)) gtk_widget_set_sensitive(cubeSubtract, sensitive);
	if(GTK_IS_WIDGET(cubeScale)) gtk_widget_set_sensitive(cubeScale, sensitive);
	if(GTK_IS_WIDGET(cubeColor)) gtk_widget_set_sensitive(cubeColor, sensitive);
}
/*********************************************************************************************************************/
static void set_sensitive_density()
{
	GtkWidget *density = gtk_ui_manager_get_widget (manager, "/MenuGL/Density");
	GtkWidget *atomic = gtk_ui_manager_get_widget (manager, "/MenuGL/Density/DensityAtomics");
	GtkWidget *bonds = gtk_ui_manager_get_widget (manager, "/MenuGL/Density/DensityBonds");

	if(!GeomOrb || !CoefAlphaOrbitals)
	{
		if(GTK_IS_WIDGET(density)) gtk_widget_set_sensitive(density, FALSE);
		return;
	}
	if(GTK_IS_WIDGET(density)) gtk_widget_set_sensitive(density, TRUE);

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
static void set_sensitive_povray()
{
	GtkWidget *povray = gtk_ui_manager_get_widget (manager, "/MenuGL/Export/ExportPovray");
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
		set_sensitive_povray();
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
  		gfloat zn, zf, zo;
		get_camera_values(&zn, &zf, &zo, &perspective);
		gtk_toggle_action_set_active(GTK_TOGGLE_ACTION(action), perspective);

	}
	else
		printf("C'est une autre widget\n");
}
/*********************************************************************************************************************/
