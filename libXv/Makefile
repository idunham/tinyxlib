include	../standard_definitions.mk

#DEFS=-DX11_t -DTRANS_CLIENT

DEFINES=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXv.a:	$(OBJS:.c=.o) 
	ar cr libXv.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXv.a
	cp -f libXv.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c
