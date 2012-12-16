include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT

DEFS=-Dlinux -D__i386__ -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXtst.a:	$(OBJS:.c=.o) 
	ar cr libXtst.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXtst.a
	cp -f libXtst.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c
