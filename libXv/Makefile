include	../standard_definitions.mk

#DEFS=-DX11_t -DTRANS_CLIENT

DEFINES=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXv.so.1.0~ -shared -Wl,-soname,libXv.so.1 $(OBJS:.c=.o)
	mv -f libXv.so.1.0~ libXv.so.1.0
	ln -s libXv.so.1.0 libXv.so.1
	ln -s libXv.so.1.0 libXv.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXv.so.1.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXv.so.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXv.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXv.a
endif

depend:
	gccmakedep -- $(CFLAGS) -- *.c
