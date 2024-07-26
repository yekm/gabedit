OBJECTS = Cylinder.o GeomOrbXYZ.o GeomDraw.o Sphere.o TriangleDraw.o UtilsOrb.o Basis.o Grid.o IsoSurface.o ViewOrb.o GLArea.o OrbitalsMolpro.o Orbitals.o StatusOrb.o AtomicOrbitals.o Images.o GridPlans.o Contours.o ContoursDraw.o PreferencesOrb.o GridCube.o GridAdfOrbitals.o GridAdfDensity.o Textures.o Dipole.o AxisGL.o PrincipalAxisGL.o Vibration.o VibrationDraw.o ColorMap.o GridM2MSI.o AnimationRotation.o AnimationIsoSurface.o AnimationContours.o AnimationPlanesMapped.o AnimationGeomConv.o PovrayGL.o ContoursPov.o PlanesMappedDraw.o PlanesMapped.o PlanesMappedPov.o  SurfacesPov.o MenuToolBarGL.o

include ../../CONFIG

CFLAGS =  -Wall -O2 $(GTKCFLAGS)

all: compiling

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

compiling: $(OBJECTS)

clean:
	@$(REMOVEFILE) *.o 

include Dep.mk
#make dependance
dep :
	-makedepend -f- *.[ch] 2>/dev/null \
	| sed 's:/usr[^ ]*/include/[^ ]*h::g' \
	| sed 's:/usr/include/.*::g' \
	| sed 's:  *: :g; s: $$::' \
	| grep -v '.*:$$' >Dep.mk


