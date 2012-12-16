include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT 

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXi.a:	$(OBJS:.c=.o) 
	ar cr libXi.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXi.a
	cp -f libXi.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c