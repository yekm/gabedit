include ../CONFIG

OBJECTS = $(GDKGL).o gtkglarea.o

all: compiling

CFLAGS =  -Wall -O2 $(GTKCFLAGS) $(OGLCFLAGS) 

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


