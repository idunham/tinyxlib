include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE  -DFUNCPROTO=15 -DNARROWPROTO -DFONTDIRATTRIB -DFONT_ENCODINGS_DIRECTORY=\"/usr/X11R7/lib/X11/fonts/encodings/encodings.dir\" -DPCFFORMAT -DX_GZIP_FONT_COMPRESSION -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DFONT_t -DTRANS_CLIENT -DTRANS_SERVER -DTRANS_REOPEN -DSHAPE -DTOGCUP -DKDRIVESERVER -DGCCUSESGAS -DDDXOSINIT -DSMART_SCHEDULE -DNOFONTSERVERACCESS -DNDEBUG -DFONTCACHE

CFLAGS= -I../include -I./include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard bitmap/*.c fontfile/*.c fontcache/*.c fc/*.c  util/*.c stubs/*.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXfont.so.6.0~ -shared -Wl,-soname,libXfont.so.6 $(OBJS:.c=.o)
	mv -f libXfont.so.6.0~ libXfont.so.6.0
	ln -s libXfont.so.6.0 libXfont.so.6
	ln -s libXfont.so.6.0 libXfont.so
endif

clean:
	rm -f bitmap/*.o fontfile/*.o fontcache/*.o fc/*.o  util/*.o stubs/*.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXfont.so.6.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXfont.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXfont.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXfont.a
endif

depend:
	gccmakedep -- $(CFLAGS) -- *.c
