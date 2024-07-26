OBJECTS = Cylinder.o GeomOrbXYZ.o BondsOrb.o GeomDraw.o Sphere.o TriangleDraw.o UtilsOrb.o Basis.o Grid.o IsoSurface.o ViewOrb.o GLArea.o OrbitalsGamess.o OrbitalsMolpro.o OrbitalsQChem.o Orbitals.o StatusOrb.o AtomicOrbitals.o Images.o GridPlans.o Contours.o ContoursDraw.o PreferencesOrb.o GridCube.o GridAdfOrbitals.o GridAdfDensity.o Textures.o Dipole.o AxisGL.o PrincipalAxisGL.o Vibration.o VibrationDraw.o ColorMap.o GridM2MSI.o AnimationRotation.o AnimationIsoSurface.o AnimationContours.o AnimationPlanesMapped.o AnimationGeomConv.o AnimationMD.o PovrayGL.o ContoursPov.o PlanesMappedDraw.o PlanesMapped.o PlanesMappedPov.o  SurfacesPov.o RingsPov.o MenuToolBarGL.o LabelsGL.o RingsOrb.o

include ../../CONFIG

CFLAGS =  -Wall -O2 $(GTKCFLAGS) $(OGLCFLAGS)

all: compiling

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

compiling: $(OBJECTS)

clean:
	@$(REMOVEFILE) *.chk p *o gabedit *.com *.out *.log *.test test* *.cpp  *old *.ps .*swp *~ 

include Dep.mk
#make dependance
dep :
	-makedepend -f- *.[ch] 2>/dev/null \
	| sed 's:/usr[^ ]*/include/[^ ]*h::g' \
	| sed 's:/usr/include/.*::g' \
	| sed 's:  *: :g; s: $$::' \
	| grep -v '.*:$$' >Dep.mk


