include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT -DTINY

DEFINES=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUSE_SNPRINTF -DLIBXT -DXFILESEARCHPATHDEFAULT=\"/usr/lib/X11/%L/%T/%N%C%S:/usr/lib/X11/%l/%T/%N%C%S:/usr/lib/X11/%T/%N%C%S:/usr/lib/X11/%L/%T/%N%S:/usr/lib/X11/%l/%T/%N%S:/usr/lib/X11/%T/%N%S\" -DERRORDB=\"/usr/lib/X11/XtErrorDB\" -DXTERROR_PREFIX=\"\" -DXTWARNING_PREFIX=\"\" -DMALLOC_0_RETURNS_NULL -DXTMALLOC_BC -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXt.a:	$(OBJS:.c=.o) 
	ar cr libXt.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXt.a
	cp -f libXt.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c
