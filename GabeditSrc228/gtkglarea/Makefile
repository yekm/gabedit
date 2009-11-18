include ../CONFIG

OBJECTS = $(GDKGL).o gtkglarea.o

all: compiling

CFLAGS =  $(COMMONCFLAGS) $(GTKCFLAGS) $(OGLCFLAGS) 

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

compiling: $(OBJECTS)

clean:
	@$(RM) *.o

include Dep.mk
#make dependance
dep :
	-makedepend -f- *.[ch] 2>/dev/null \
	| sed 's:/usr[^ ]*/include/[^ ]*h::g' \
	| sed 's:/usr/include/.*::g' \
	| sed 's:  *: :g; s: $$::' \
	| grep -v '.*:$$' >Dep.mk


