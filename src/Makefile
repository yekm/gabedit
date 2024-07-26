GTKGL      = gtkglarea/*.o
GTKPLOT    = gtkplot/*.o
COMMON     = src/Common/*.o
FILES      = src/Files/*.o
GAUSS      = src/Gaussian/*.o
GEOM       = src/Geometry/*.o
CURVE      = src/Curve/*.o
MODELS     = src/MolecularMechanics/*.o
MOLPRO     = src/Molpro/*.o
NETWORK    = src/NetWork/*.o
OPENGL     = src/OpenGL/*.o
UTILS      = src/Utils/*.o
SYMMETRY   = src/Symmetry/*.o
MOLCAS     = src/Molcas/*.o
MPQC       = src/MPQC/*.o
LIBPTHREAD = -lpthread
GTKGL      = gtkglarea/*.o
OPENGL     = src/OpenGL/*.o

include CONFIG


all:compile link 

compile:
	@$(CDMAKE) gtkglarea $(MAKENAME) all
	@$(CDMAKE) gtkplot $(MAKENAME) all
	@$(CDMAKE) gtkplot $(MAKENAME) all
	@$(CDMAKE) src/OpenGL $(MAKENAME) all
	@$(CDMAKE) src/Common $(MAKENAME) all
	@$(CDMAKE) src/Files $(MAKENAME) all
	@$(CDMAKE) src/Gaussian $(MAKENAME) all
	@$(CDMAKE) src/Geometry $(MAKENAME) all
	@$(CDMAKE) src/Curve $(MAKENAME) all
	@$(CDMAKE) src/MolecularMechanics $(MAKENAME) all
	@$(CDMAKE) src/Molpro $(MAKENAME) all
	@$(CDMAKE) src/Molcas $(MAKENAME) all
	@$(CDMAKE) src/MPQC $(MAKENAME) all
	@$(CDMAKE) src/NetWork $(MAKENAME) all
	@$(CDMAKE) src/Utils/ $(MAKENAME) all
	@$(CDMAKE) src/Symmetry/ $(MAKENAME) all

link:
	$(CC)  $(GTKGL) $(GTKPLOT) $(COMMON) $(FILES) $(GAUSS) $(GEOM) $(CURVE) $(MODELS) $(MOLPRO) $(MOLCAS) $(MPQC) $(NETWORK) $(OPENGL) $(UTILS) $(SYMMETRY) -o gabedit $(GTKLIB) $(OGLLIB) $(JPEGLIB) $(PTHREADLIB) $(WIN32LIB) -g;\

clean:
	@$(CDMAKE) gtkglarea $(MAKENAME) clean
	@$(CDMAKE) gtkplot $(MAKENAME) clean
	@$(CDMAKE) src/Common $(MAKENAME) clean
	@$(CDMAKE) src/Files $(MAKENAME) clean
	@$(CDMAKE) src/Gaussian $(MAKENAME) clean
	@$(CDMAKE) src/Geometry $(MAKENAME) clean
	@$(CDMAKE) src/Curve $(MAKENAME) clean
	@$(CDMAKE) src/MolecularMechanics $(MAKENAME) clean
	@$(CDMAKE) src/Molpro $(MAKENAME) clean
	@$(CDMAKE) src/Molcas $(MAKENAME) clean
	@$(CDMAKE) src/MPQC $(MAKENAME) clean
	@$(CDMAKE) src/NetWork $(MAKENAME) clean
	@$(CDMAKE) src/Utils/ $(MAKENAME) clean
	@$(CDMAKE) src/Symmetry/ $(MAKENAME) clean
	@$(CDMAKE) src/OpenGL $(MAKENAME) clean
	@$(REMOVEFILE) gabedit
	@$(REMOVEFILE) gabedit.exe
	@$(REMOVEFILE) *.com
	@$(REMOVEFILE) *.cmd
	@$(REMOVEFILE) *.out
	@$(REMOVEFILE) *.log
	@$(REMOVEFILE) *.molden
	@$(REMOVEFILE) *.gab
	@$(REMOVEFILE) p
	@$(REMOVEFILE) pp
	@$(REMOVEFILE) p.c

dep :
	@$(CDMAKE) gtkglarea $(MAKENAME) dep
	@$(CDMAKE) gtkplot $(MAKENAME) dep
	@$(CDMAKE) src/Common $(MAKENAME) dep
	@$(CDMAKE) src/Files $(MAKENAME) dep
	@$(CDMAKE) src/Gaussian $(MAKENAME) dep
	@$(CDMAKE) src/Geometry $(MAKENAME) dep
	@$(CDMAKE) src/Curve $(MAKENAME) dep
	@$(CDMAKE) src/MolecularMechanics $(MAKENAME) dep
	@$(CDMAKE) src/Molpro $(MAKENAME) dep
	@$(CDMAKE) src/Molcas $(MAKENAME) dep
	@$(CDMAKE) src/MPQC $(MAKENAME) dep
	@$(CDMAKE) src/NetWork $(MAKENAME) dep
	@$(CDMAKE) src/Utils/ $(MAKENAME) dep
	@$(CDMAKE) src/Symmetry/ $(MAKENAME) dep
	@$(CDMAKE) src/OpenGL $(MAKENAME) dep

