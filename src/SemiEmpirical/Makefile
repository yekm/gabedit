OBJECTS = AtomSE.o MoleculeSE.o SemiEmpiricalModel.o SemiEmpiricalMD.o SemiEmpirical.o SemiEmpiricalDlg.o 

include ../../CONFIG
CFLAGS =  $(COMMONCFLAGS) $(GTKCFLAGS)

all: compiling 

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

compiling: $(OBJECTS)

clean:
	@$(RM) *.chk p *o gabedit *.com *.out *.log *.test test* *.cpp  *old *.ps .*swp *~ 

include Dep.mk
#make dependance
dep :
	-makedepend -f- *.[ch] 2>/dev/null \
	| sed 's:/usr[^ ]*/include/[^ ]*h::g' \
	| sed 's:/usr/include/.*::g' \
	| sed 's:  *: :g; s: $$::' \
	| grep -v '.*:$$' >Dep.mk

