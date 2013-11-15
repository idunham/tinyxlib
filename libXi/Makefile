include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)

clean:
	rm -f *.o

install:
	ln -s libX11.a $(LIBDIR)/libXi.a

depend:
	gccmakedep -- $(CFLAGS) -- *.c