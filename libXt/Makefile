include	../standard_definitions.mk

#-DXTSTRINGDEFINES

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUSE_SNPRINTF -DLIBXT -DXTSTRINGDEFINES  -DXFILESEARCHPATHDEFAULT=\"/usr/lib/X11/%L/%T/%N%C%S:/usr/lib/X11/%l/%T/%N%C%S:/usr/lib/X11/%T/%N%C%S:/usr/lib/X11/%L/%T/%N%S:/usr/lib/X11/%l/%T/%N%S:/usr/lib/X11/%T/%N%S\" -DERRORDB=\"/usr/lib/X11/XtErrorDB\" -DXTERROR_PREFIX=\"\" -DXTWARNING_PREFIX=\"\" -DMALLOC_0_RETURNS_NULL -DXTMALLOC_BC -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXt.so.6.1~ -shared -Wl,-soname,libXt.so.6 $(OBJS:.c=.o)
	mv -f libXt.so.6.1~ libXt.so.6.1
	ln -s libXt.so.6.1 libXt.so.6
	ln -s libXt.so.6.1 libXt.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXt.so.6.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXt.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXt.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXt.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Name: Xt" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Description: X Toolkit Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Version: 1.0.5" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Requires: sm ice x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Requires.private: sm ice x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Libs: -L$(LIBDIR) -lXt" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc
	@echo "Libs.private: -L$(LIBDIR) -lXt" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xt.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
