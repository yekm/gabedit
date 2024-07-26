GTKGL      = gtkglarea/*.o
COMMON     = src/Common/*.o
FILES      = src/Files/*.o
GAUSS      = src/Gaussian/*.o
GEOM       = src/Geometry/*.o
CURVE      = src/Spectrum/*.o
MODELS     = src/MolecularMechanics/*.o
MOLPRO     = src/Molpro/*.o
NETWORK    = src/NetWork/*.o
OPENGL     = src/OpenGL/*.o
UTILS      = src/Utils/*.o
SYMMETRY   = src/Symmetry/*.o
MOLCAS     = src/Molcas/*.o
MPQC       = src/MPQC/*.o
GAMESS     = src/Gamess/*.o
PCGAMESS     = src/PCGamess/*.o
QCHEM     = src/QChem/*.o
MOPAC     = src/Mopac/*.o
OPENGL     = src/OpenGL/*.o
MULTIGRID     = src/MultiGrid/*.o

include CONFIG
 
SUBDIRS = gtkglarea src/OpenGL src/Common src/Files src/Gaussian \
	src/Geometry src/Spectrum src/MolecularMechanics src/Molpro src/Molcas \
	src/MPQC src/Gamess src/QChem src/Mopac src/NetWork src/Utils src/Symmetry \
	src/PCGamess src/MultiGrid
 
TARGETS = all clean dep
 
.PHONY: $(SUBDIRS)

$(TARGETS): $(SUBDIRS)

$(SUBDIRS):
	@$(MAKENAME) --directory=$@ $(MAKECMDGOALS)

all: gabedit

gabedit: $(SUBDIRS)
	$(CC)  $(X11LIB) $(GTKGL) $(GTKPLOT) $(COMMON) $(FILES) $(GAUSS) $(GEOM) $(CURVE) $(MODELS) $(MOLPRO) $(MOLCAS) $(MPQC) $(GAMESS) $(PCGAMESS) $(QCHEM) $(MOPAC) $(NETWORK) $(OPENGL) $(UTILS) $(SYMMETRY) $(MULTIGRID) -o gabedit $(GTKLIB) $(OGLLIB) $(JPEGLIB) $(LIBPTHREAD) $(WIN32LIB) -g
 
clean:
	@$(REMOVEFILE) gabedit
	@$(REMOVEFILE) gabedit.exe
	@$(REMOVEFILE) *.com
	@$(REMOVEFILE) p
	@$(REMOVEFILE) pp
	@$(REMOVEFILE) p.c
	@$(REMOVEFILE) *.gab
