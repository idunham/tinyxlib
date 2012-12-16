include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT
CFLAGS= -I../include -I../ $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXpm.a:	$(OBJS:.c=.o) 
	ar cr libXpm.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXpm.a
	cp -f libXpm.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c