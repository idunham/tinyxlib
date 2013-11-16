include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXi.so.6.0~ -shared -Wl,-soname,libXi.so.6 $(OBJS:.c=.o)
	mv -f libXi.so.6.0~ libXi.so.6.0
	ln -s libXi.so.6.0 libXi.so.6
	ln -s libXi.so.6.0 libXi.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXi.so.6.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXi.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXi.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXi.a
endif

depend:
	gccmakedep -- $(CFLAGS) -- *.c