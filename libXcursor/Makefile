include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXcursor.so.6.0~ -shared -Wl,-soname,libXcursor.so.6 $(OBJS:.c=.o)
	mv -f libXcursor.so.6.0~ libXcursor.so.6.0
	ln -s libXcursor.so.6.0 libXcursor.so.6
	ln -s libXcursor.so.6.0 libXcursor.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXcursor.so.6.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXcursor.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXcursor.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXcursor.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Name: Xcursor" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Description: X Cursor library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Version: .0" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Requires:" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Requires.private:" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Libs: -L$(LIBDIR) -lXcursor" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Libs.private: -L$(LIBDIR) -lXcursor" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xcursor.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
