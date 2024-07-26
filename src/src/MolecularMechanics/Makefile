OBJECTS = Atom.o Molecule.o ForceField.o MolecularMechanics.o ConjugateGradient.o SteepestDescent.o QuasiNewton.o MolecularMechanicsDlg.o CreateMolecularMechanicsFile.o CreatePersonalMMFile.o LoadMMParameters.o SetMMParameters.o CreateDefaultPDBTpl.o LoadPDBTemplate.o PDBTemplate.o SetPDBTemplate.o SavePDBTemplate.o

include ../../CONFIG
CFLAGS =  -Wall -O2 $(GTKCFLAGS)

all: compiling 

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

compiling: $(OBJECTS)

clean:
	@$(REMOVEFILE) *.chk p *o gabedit *.com *.out *.log *.test test* *.cpp  *old *.ps

include Dep.mk
#make dependance
dep :
	-makedepend -f- *.[ch] 2>/dev/null \
	| sed 's:/usr[^ ]*/include/[^ ]*h::g' \
	| sed 's:/usr/include/.*::g' \
	| sed 's:  *: :g; s: $$::' \
	| grep -v '.*:$$' >Dep.mk

