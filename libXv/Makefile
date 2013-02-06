include	../standard_definitions.mk

#DEFS=-DX11_t -DTRANS_CLIENT

DEFINES=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXv.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXv.so.1.0~ -shared -Wl,-soname,libXv.so.1 $(OBJS:.c=.o)
	mv -f libXv.so.1.0~ libXv.so.1.0
	ln -s libXv.so.1.0 libXv.so.1
	ln -s libXv.so.1.0 libXv.so	
	
clean:
	rm -f *.o *.a *.so*
	
install:
	cp -af libXv.a $(LIBDIR)
	cp -af libXv.so.1.0 $(LIBDIR)
	cp -af libXv.so.1 $(LIBDIR)
	cp -af libXv.so $(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
