include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXss.so.1.0~ -shared -Wl,-soname,libXss.so.6 $(OBJS:.c=.o)
	mv -f libXss.so.1.0~ libXss.so.1.0
	ln -s libXss.so.1.0 libXss.so.1
	ln -s libXss.so.1.0 libXss.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXss.so.1.0 $(LIBDIR)
	cp -af libXss.so.1 $(LIBDIR)
	cp -af libXss.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXss.a
endif

depend:
	gccmakedep -- $(CFLAGS) -- *.c
