include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO   -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

#OBJS=$(wildcard *.c)
OBJS=Xrender.c Composite.c Glyph.c Picture.c FillRect.c FillRects.c

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXrender.so.1.1~ -shared -Wl,-soname,libXrender.so.1 $(OBJS:.c=.o)
	mv -f libXrender.so.1.1~ libXrender.so.1.1
	ln -s libXrender.so.1.1 libXrender.so.1
	ln -s libXrender.so.1.1 libXrender.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXrender.so.1.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXrender.so.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXrender.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXrender.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Name: Xrender" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Description: X Render Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Version: 1.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Requires: x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Requires.private: x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Libs: -L$(LIBDIR) -lXrender" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc
	@echo "Libs.private: -L$(LIBDIR) -lXrender" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xrender.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
