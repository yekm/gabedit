OBJECTS = DrawGeom.o EnergiesCurves.o Fragments.o GeomConversion.o GeomXYZ.o GeomZmatrix.o ImagesGeom.o InterfaceGeom.o Mesure.o Postscript.o Povray.o ResultsAnalise.o Symmetry.o RotFragments.o BuildLinear.o BuildRing.o BuildRoZPhi.o BuildPolyPeptide.o FragmentsPPD.o FragmentsPSC.o FragmentsPNA.o BuildPolySaccharide.o BuildPolyNucleicAcid.o BuildNanoTube.o PersonalFragments.o SavePersonalFragments.o LoadPersonalFragments.o FragmentsSelector.o OpenBabel.o MenuToolBarGeom.o PreviewGeom.o FragmentsTree.o

include ../../CONFIG
CFLAGS =  -Wall -O2 $(GTKCFLAGS)

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

