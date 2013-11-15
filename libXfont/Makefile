include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE  -DFUNCPROTO=15 -DNARROWPROTO -DFONTDIRATTRIB -DFONT_ENCODINGS_DIRECTORY=\"/usr/X11R7/lib/X11/fonts/encodings/encodings.dir\" -DPCFFORMAT -DX_GZIP_FONT_COMPRESSION -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DFONT_t -DTRANS_CLIENT -DTRANS_SERVER -DTRANS_REOPEN -DSHAPE -DTOGCUP -DKDRIVESERVER -DGCCUSESGAS -DDDXOSINIT -DSMART_SCHEDULE -DNOFONTSERVERACCESS -DNDEBUG -DFONTCACHE

CFLAGS= -I../include -I./include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard bitmap/*.c fontfile/*.c fontcache/*.c fc/*.c  util/*.c stubs/*.c)

all:	$(OBJS:.c=.o)

clean:
	rm -f bitmap/*.o fontfile/*.o fontcache/*.o fc/*.o  util/*.o stubs/*.o

install:
	ln -s libX11.a $(LIBDIR)/libXfont.a

depend:
	gccmakedep -- $(CFLAGS) -- *.c
