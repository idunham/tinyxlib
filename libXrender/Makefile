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
	cp -af libXrender.so.1.1 $(LIBDIR)
	cp -af libXrender.so.1 $(LIBDIR)
	cp -af libXrender.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXrender.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xrender.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Name: Xrender" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Description: X Render Library" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Version: 1.0.3" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Requires: x11 xau xdmcp" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Requires.private: x11 xau xdmcp" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Libs: -L$(PREDIR)/lib -lXrender" >> $(LIBDIR)/pkgconfig/xrender.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXrender" >> $(LIBDIR)/pkgconfig/xrender.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
