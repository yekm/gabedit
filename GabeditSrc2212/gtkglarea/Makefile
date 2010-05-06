include ../CONFIG

OBJECTS = $(GDKGL).o gtkglarea.o

all: compiling

CFLAGS =  $(COMMONCFLAGS) $(GTKCFLAGS) $(OGLCFLAGS) 

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@

compiling: $(OBJECTS)

clean:
	@$(RM) *.o

#make dependance
SRCS = $(OBJECTS:%.o=%.c)
dep :
	gcc -MM $(SRCS) > Dep.mk

-include Dep.mk

