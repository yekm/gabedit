OBJECTS = gtkextra-marshal.o gtkplot3d.o gtkplot.o gtkplotcanvas.o gtkplotdata.o gtkplotdt.o gtkplotgdk.o gtkplotpc.o gtkplotprint.o gtkplotps.o gtkplotsurface.o gtkpsfont.o gtkplotpolar.o gtkextra.o

include ../CONFIG
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


