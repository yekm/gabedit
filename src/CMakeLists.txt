cmake_minimum_required(VERSION 3.13)
project(gabedit)

set(CMAKE_VERBOSE_MAKEFILE 1)

find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkglext REQUIRED IMPORTED_TARGET gtkglext-1.0)

find_package(GTK2 2.6 REQUIRED gtk)

find_package(OpenGL REQUIRED)

add_executable(gabedit
	src/Common/Gabedit.c
	src/Common/Help.c
	src/Common/Install.c
	src/Common/Preferences.c
	src/Common/Printer.c
	src/Common/Run.c
	src/Common/SplashScreen.c
	src/Common/TextEdit.c
	src/Common/Windows.c
	src/Common/Status.c
	src/Common/Exit.c
	src/Common/MenuToolBar.c
	src/Common/StockIcons.c
	src/Common/Global.c
)

add_library(gl2ps
	gl2ps/gl2ps.c
)

add_library(spglib
	spglib/sitesym_database.c
	spglib/symmetry.c
	spglib/overlap.c
	spglib/pointgroup.c
	spglib/tetrahedron_method.c
	spglib/determination.c
	spglib/primitive.c
	spglib/spg_database.c
	spglib/kgrid.c
	spglib/spacegroup.c
	spglib/cell.c
	spglib/mathfunc.c
	spglib/spglib.c
	spglib/test.c
	spglib/spglib_f.c
	spglib/debug.c
	spglib/arithmetic.c
	spglib/refinement.c
	spglib/site_symmetry.c
	spglib/delaunay.c
	spglib/spin.c
	spglib/hall_symbol.c
	spglib/kpoint.c
	spglib/niggli.c
)

add_library(EVERYTHING
	src/Molcas/Molcas.c
	src/Molcas/MolcasGateWay.c
	src/Molcas/MolcasSeward.c
	src/Molcas/MolcasScf.c
	src/Molcas/MolcasGridIT.c
	src/Molcas/MolcasOptimization.c
	src/Molcas/MolcasVariables.c
	src/Molcas/MolcasLib.c
	src/Molcas/MolcasBasisLibrary.c
	src/Molcas/MolcasBasis.c
	src/Molcas/MolcasGlobal.c

	src/Mopac/Mopac.c
	src/Mopac/MopacMolecule.c
	src/Mopac/MopacRem.c
	src/Mopac/MopacGlobal.c

	src/MultiGrid/DomainMG.c
	src/MultiGrid/GridMG.c
	src/MultiGrid/PoissonMG.c

	src/SemiEmpirical/AtomSE.c
	src/SemiEmpirical/MoleculeSE.c
	src/SemiEmpirical/SemiEmpiricalModel.c
	src/SemiEmpirical/SemiEmpiricalMD.c
	src/SemiEmpirical/SemiEmpirical.c
	src/SemiEmpirical/SemiEmpiricalDlg.c

	src/DeMon/DeMon.c
	src/DeMon/DeMonMolecule.c
	src/DeMon/DeMonKeywords.c
	src/DeMon/DeMonGuess.c
	src/DeMon/DeMonBasis.c
	src/DeMon/DeMonGlobal.c

	src/FireFly/FireFly.c
	src/FireFly/FireFlyMolecule.c
	src/FireFly/FireFlyControl.c
	src/FireFly/FireFlyBasis.c
	src/FireFly/FireFlyGuess.c
	src/FireFly/FireFlySCF.c
	src/FireFly/FireFlyGlobal.c

	src/Display/GeomOrbXYZ.c
	src/Display/BondsOrb.c
	src/Display/GeomDraw.c
	src/Display/TriangleDraw.c
	src/Display/UtilsOrb.c
	src/Display/Basis.c
	src/Display/Grid.c
	src/Display/IsoSurface.c
	src/Display/ViewOrb.c
	src/Display/GLArea.c
	src/Display/OrbitalsGamess.c
	src/Display/OrbitalsMolpro.c
	src/Display/OrbitalsOrca.c
	src/Display/OrbitalsQChem.c
	src/Display/OrbitalsNWChem.c
	src/Display/OrbitalsMopac.c
	src/Display/OrbitalsNBO.c
	src/Display/Orbitals.c
	src/Display/StatusOrb.c
	src/Display/AtomicOrbitals.c
	src/Display/Images.c
	src/Display/GridPlans.c
	src/Display/Contours.c
	src/Display/ContoursDraw.c
	src/Display/PreferencesOrb.c
	src/Display/GridCube.c
	src/Display/GridAdfOrbitals.c
	src/Display/GridAdfDensity.c
	src/Display/Textures.c
	src/Display/Dipole.c
	src/Display/AxisGL.c
	src/Display/PrincipalAxisGL.c
	src/Display/Vibration.c
	src/Display/VibrationDraw.c
	src/Display/VibrationLocal.c
	src/Display/ColorMap.c
	src/Display/GridMolcas.c
	src/Display/GridQChem.c
	src/Display/AnimationRotation.c
	src/Display/AnimationIsoSurface.c
	src/Display/AnimationContours.c
	src/Display/AnimationPlanesMapped.c
	src/Display/AnimationGeomConv.c
	src/Display/AnimationMD.c
	src/Display/PovrayGL.c
	src/Display/ContoursPov.c
	src/Display/PlanesMappedDraw.c
	src/Display/PlanesMapped.c
	src/Display/PlanesMappedPov.c
	src/Display/SurfacesPov.c
	src/Display/RingsPov.c
	src/Display/MenuToolBarGL.c
	src/Display/LabelsGL.c
	src/Display/RingsOrb.c
	src/Display/ExportGL.c
	src/Display/CaptureOrbitals.c
	src/Display/IntegralOrbitals.c
	src/Display/GridCP.c
	src/Display/AnimationGrids.c
	src/Display/NCI.c
	src/Display/ReactivityIndices.c
	src/Display/wfx.c
	src/Display/GlobalOrb.c

	src/Spectrum/SpectrumWin.c
	src/Spectrum/IRSpectrum.c
	src/Spectrum/RamanSpectrum.c
	src/Spectrum/UVSpectrum.c
	src/Spectrum/ECDSpectrum.c
	src/Spectrum/NMRSpectrum.c
	src/Spectrum/DOS.c
	src/Spectrum/VASPSpectra.c
	src/Spectrum/IGVPT2Spectrum.c

	src/NetWork/Ftp.c
	src/NetWork/Process.c
	src/NetWork/Rsh.c
	src/NetWork/Ssh.c
	src/NetWork/Scp.c
	src/NetWork/FilesTransfer.c
	src/NetWork/RemoteCommand.c
	src/NetWork/Batch.c

	src/Orca/Orca.c
	src/Orca/OrcaMolecule.c
	src/Orca/OrcaKeywords.c
	src/Orca/OrcaGuess.c
	src/Orca/OrcaBasis.c
	src/Orca/OrcaGlobal.c

	src/IsotopeDistribution/IsotopeDistributionCalculator.c
	src/IsotopeDistribution/IsotopeDistributionCalculatorDlg.c

	src/Files/FileChooser.c
	src/Files/FolderChooser.c
	src/Files/ListeFiles.c
	src/Files/GabeditFolderChooser.c
	src/Files/GabeditFileChooser.c

	src/MolecularMechanics/Atom.c
	src/MolecularMechanics/Molecule.c
	src/MolecularMechanics/ForceField.c
	src/MolecularMechanics/MolecularMechanics.c
	src/MolecularMechanics/ConjugateGradient.c
	src/MolecularMechanics/SteepestDescent.c
	src/MolecularMechanics/QuasiNewton.c
	src/MolecularMechanics/MolecularMechanicsDlg.c
	src/MolecularMechanics/CreateMolecularMechanicsFile.c
	src/MolecularMechanics/CreatePersonalMMFile.c
	src/MolecularMechanics/LoadMMParameters.c
	src/MolecularMechanics/SetMMParameters.c
	src/MolecularMechanics/CreateDefaultPDBTpl.c
	src/MolecularMechanics/LoadPDBTemplate.c
	src/MolecularMechanics/PDBTemplate.c
	src/MolecularMechanics/SetPDBTemplate.c
	src/MolecularMechanics/SavePDBTemplate.c
	src/MolecularMechanics/CalculTypesAmber.c
	src/MolecularMechanics/MolecularDynamics.c

	src/Utils/GabeditTextEdit.c
	src/Utils/AtomsProp.c
	src/Utils/Jacobi.c
	src/Utils/QL.c
	src/Utils/Transformation.c
	src/Utils/Utils.c
	src/Utils/UtilsInterface.c
	src/Utils/Vector3d.c
	src/Utils/Matrix3D.c
	src/Utils/HydrogenBond.c
	src/Utils/PovrayUtils.c
	src/Utils/UtilsGL.c
	src/Utils/ConvUtils.c
	src/Utils/GabeditXYPlot.c
	src/Utils/GabeditContoursPlot.c
	src/Utils/UtilsCairo.c
	src/Utils/Zlm.c
	src/Utils/MathFunctions.c
	src/Utils/GTF.c
	src/Utils/TTables.c
	src/Utils/Interpolation.c
	src/Utils/Point3D.c
	src/Utils/UtilsVASP.c

	src/Gaussian/GInterfaceBasis.c
	src/Gaussian/GInterfaceGeom.c
	src/Gaussian/GInterfaceLink.c
	src/Gaussian/GInterfaceMethodeBase.c
	src/Gaussian/GInterfaceRoute.c
	src/Gaussian/Gaussian.c
	src/Gaussian/GaussGlobal.c

	src/Psicode/Psicode.c
	src/Psicode/PsicodeMolecule.c
	src/Psicode/PsicodeKeywords.c
	src/Psicode/PsicodeGuess.c
	src/Psicode/PsicodeBasis.c
	src/Psicode/PsicodeGlobal.c

	src/QFF/Gabedit2MRQFF.c

	src/Gamess/Gamess.c
	src/Gamess/GamessMolecule.c
	src/Gamess/GamessControl.c
	src/Gamess/GamessBasis.c
	src/Gamess/GamessGuess.c
	src/Gamess/GamessSCF.c
	src/Gamess/GamessGlobal.c

	src/Molpro/MolproLib.c
	src/Molpro/MInterfaceBasis.c
	src/Molpro/MInterfaceComm.c
	src/Molpro/MInterfaceGene.c
	src/Molpro/MInterfaceGeom.c
	src/Molpro/Molpro.c
	src/Molpro/MolproBasisLibrary.c

	src/MPQC/MPQC.c
	src/MPQC/MPQCMolecule.c
	src/MPQC/MPQCMole.c
	src/MPQC/MPQCGuessWaveFunction.c
	src/MPQC/MPQCMpqc.c
	src/MPQC/MPQCBasis.c
	src/MPQC/MPQCLib.c
	src/MPQC/MPQCBasisLibrary.c
	src/MPQC/MPQCFunctionals.c
	src/MPQC/MPQCOptimization.c
	src/MPQC/MPQCProperties.c
	src/MPQC/MPQCGlobal.c

	src/Geometry/EnergiesCurves.c
	src/Geometry/Fragments.c
	src/Geometry/GeomConversion.c
	src/Geometry/GeomXYZ.c
	src/Geometry/GeomZmatrix.c
	src/Geometry/ImagesGeom.c
	src/Geometry/InterfaceGeom.c
	src/Geometry/Measure.c
	src/Geometry/Povray.c
	src/Geometry/ResultsAnalise.c
	src/Geometry/GeomSymmetry.c
	src/Geometry/RotFragments.c
	src/Geometry/BuildLinear.c
	src/Geometry/BuildRing.c
	src/Geometry/BuildRoZPhi.c
	src/Geometry/BuildPolyPeptide.c
	src/Geometry/FragmentsPPD.c
	src/Geometry/FragmentsPSC.c
	src/Geometry/FragmentsPNA.c
	src/Geometry/FragmentsCrystal.c
	src/Geometry/BuildPolySaccharide.c
	src/Geometry/BuildPolyNucleicAcid.c
	src/Geometry/BuildNanoTube.c
	src/Geometry/BuildCrystal.c
	src/Geometry/PersonalFragments.c
	src/Geometry/SavePersonalFragments.c
	src/Geometry/LoadPersonalFragments.c
	src/Geometry/FragmentsSelector.c
	src/Geometry/OpenBabel.c
	src/Geometry/MenuToolBarGeom.c
	src/Geometry/PreviewGeom.c
	src/Geometry/FragmentsTree.c
	src/Geometry/ExportGeom.c
	src/Geometry/TreeMolecule.c
	src/Geometry/DrawGeomGL.c
	src/Geometry/AxesGeomGL.c
	src/Geometry/DrawGeomCairo.c
	src/Geometry/SelectionDlg.c
	src/Geometry/GeomGlobal.c

	src/NWChem/NWChem.c
	src/NWChem/NWChemMolecule.c
	src/NWChem/NWChemKeywords.c
	src/NWChem/NWChemGuess.c
	src/NWChem/NWChemBasis.c
	src/NWChem/NWChemGlobal.c

	src/Crystallography/Crystallo.c
	src/Crystallography/UtilsCIF.c
	src/Crystallography/GabeditSPG.c
	src/Crystallography/GabeditKPoints.c

	src/QChem/QChem.c
	src/QChem/QChemMolecule.c
	src/QChem/QChemRem.c
	src/QChem/QChemGuess.c
	src/QChem/QChemBasis.c
	src/QChem/QChemLib.c
	src/QChem/QChemGlobal.c

	src/VibrationalCorrections/GabeditGaussianInput.c

	src/Symmetry/MoleculeSymmetry.c
	src/Symmetry/MoleculeSymmetryInterface.c
	src/Symmetry/PolyHedralOperators.c
	src/Symmetry/ReducePolyHedralMolecule.c
	src/Symmetry/PrincipalAxis.c
	src/Symmetry/ReduceMolecule.c
	src/Symmetry/SymmetryOperators.c
	src/Symmetry/GenerateMolecule.c
	src/Symmetry/Element.c
	src/Symmetry/SAtom.c
	src/Symmetry/SMolecule.c
	src/Symmetry/Elements.c
	src/Symmetry/SOperation.c
	src/Symmetry/SOperations.c
	src/Symmetry/HashMapSAtoms.c
	src/Symmetry/PointGroupGabedit.c
	src/Symmetry/PointGroups.c
	src/Symmetry/SymmetryGabedit.c
)

add_definitions(-DENABLE_DEPRECATED -DUSE_DEPRECATED_MACROS -DDRAWGEOMGL -Wno-deprecated-declarations)

include_directories(${GTK2_INCLUDE_DIRS} ${gtkglext_INCLUDE_DIRS})

#target_include_directories(gabedit PRIVATE ${GTK2_INCLUDE_DIRS})

target_link_libraries(gabedit
PUBLIC
	EVERYTHING spglib gl2ps
PRIVATE
	${GTK2_LIBRARIES}
	${gtkglext_LIBRARIES}
	${OPENGL_LIBRARY}
	m
	)
