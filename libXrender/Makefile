include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT -DTINY

DEFS=-Dlinux -D__i386__ -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO   -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

#OBJS=$(wildcard *.c)
OBJS=Xrender.c Composite.c Glyph.c Picture.c FillRect.c FillRects.c

libXrender.a:	$(OBJS:.c=.o) 
	ar cr libXrender.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXrender.a
	cp -f libXrender.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c
