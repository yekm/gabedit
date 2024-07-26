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
GAMESS     = src/Gamess/*.o
OPENGL     = src/OpenGL/*.o

include CONFIG
 
SUBDIRS = gtkglarea gtkplot src/OpenGL src/Common src/Files src/Gaussian \
	src/Geometry src/Curve src/MolecularMechanics src/Molpro src/Molcas \
	src/MPQC src/Gamess src/NetWork src/Utils src/Symmetry
 
TARGETS = all clean dep
 
.PHONY: $(SUBDIRS)

$(TARGETS): $(SUBDIRS)

$(SUBDIRS):
	@$(MAKENAME) --directory=$@ $(MAKECMDGOALS)

all: gabedit

gabedit: $(SUBDIRS)
	$(CC)  $(X11LIB) $(GTKGL) $(GTKPLOT) $(COMMON) $(FILES) $(GAUSS) $(GEOM) $(CURVE) $(MODELS) $(MOLPRO) $(MOLCAS) $(MPQC) $(GAMESS) $(NETWORK) $(OPENGL) $(UTILS) $(SYMMETRY) -o gabedit $(GTKLIB) $(OGLLIB) $(JPEGLIB) $(PTHREADLIB) $(WIN32LIB) -g
 
clean:
	@$(REMOVEFILE) gabedit
	@$(REMOVEFILE) gabedit.exe
	@$(REMOVEFILE) *.com
	@$(REMOVEFILE) p
	@$(REMOVEFILE) pp
	@$(REMOVEFILE) p.c
