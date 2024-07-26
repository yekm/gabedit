
include CONFIG

COMMON     = src/Common/*.o
CURVE      = src/Spectrum/*.o
FILES      = src/Files/*.o
GAMESS     = src/Gamess/*.o
GAUSS      = src/Gaussian/*.o
GEOM       = src/Geometry/*.o
MODELS     = src/MolecularMechanics/*.o
MOLCAS     = src/Molcas/*.o
MOLPRO     = src/Molpro/*.o
MOPAC      = src/Mopac/*.o
MPQC       = src/MPQC/*.o
MULTIGRID  = src/MultiGrid/*.o
NETWORK    = src/NetWork/*.o
OPENGL     = src/OpenGL/*.o
PCGAMESS   = src/PCGamess/*.o
QCHEM      = src/QChem/*.o
SEMIEMP    = src/SemiEmpirical/*.o
UTILS      = src/Utils/*.o
SYMMETRY   = src/Symmetry/*.o

 
OBJECTS = \
	$(COMMON) $(CURVE) $(FILES) $(GAMESS) $(GAUSS) $(GEOM) $(MODELS) \
	$(MOLCAS) $(MOLPRO) $(MOPAC) $(MPQC) $(MULTIGRID) $(NETWORK) \
	$(OPENGL) $(PCGAMESS) $(QCHEM) $(SEMIEMP) $(UTILS) $(SYMMETRY)

SUBDIRS = \
	src/OpenGL src/Common src/Files src/Gaussian \
 	src/Geometry src/Spectrum src/MolecularMechanics src/Molpro src/Molcas \
	src/MPQC src/Gamess src/QChem src/Mopac src/NetWork src/Utils \
	src/Symmetry src/PCGamess src/MultiGrid src/SemiEmpirical

ifneq ($(external_gtkglarea),1)
GTKGL     = gtkglarea/*.o
OBJECTS  += $(GTKGL)
SUBDIRS  += gtkglarea
else
OBJECTS  += -lgtkgl-2.0
endif

ifneq ($(external_gl2ps),1)
GL2PS     = gl2ps/*.o
OBJECTS  += $(GL2PS)
SUBDIRS  += gl2ps
else
OBJECTS  += -lgl2ps
endif
 
TARGETS = all clean dep
 
.PHONY: $(SUBDIRS)

$(TARGETS): $(SUBDIRS)

$(SUBDIRS):
	@$(MAKE) --directory=$@ $(MAKECMDGOALS)

all: gabedit

gabedit: $(SUBDIRS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o gabedit $(X11LIB) $(GTKLIB) $(OGLLIB) $(JPEGLIB) $(LIBPTHREAD) $(WIN32LIB) -g
 
clean:
	@$(RM) gabedit
	@$(RM) gabedit.exe
	@$(RM) *.com
	@$(RM) p
	@$(RM) pp
	@$(RM) p.c
	@$(RM) *.gab
	@$(RM) *.inp
	@$(RM) *.mop
	@$(RM) *.log
	@$(RM) *.out
	@$(RM) *.pun
	@$(RM) *.dat
	@$(RM) *.arc
	@$(RM) *.aux
	@$(RM) *.cmd
	@$(RM) *.chk
	@$(RM) *.sh
	@$(RM) pm6*.*
