include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
	ar cr libXi.a $(OBJS:.c=.o)

clean:
	rm -f *.o *.a *.so*

install:
	cp -af libXi.a $(LIBDIR)

depend:
	gccmakedep -- $(CFLAGS) -- *.c