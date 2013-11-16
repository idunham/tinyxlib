include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXdmcp.so.6.0~ -shared -Wl,-soname,libXdmcp.so.6 $(OBJS:.c=.o)
	mv -f libXdmcp.so.6.0~ libXdmcp.so.6.0
	ln -s libXdmcp.so.6.0 libXdmcp.so.6
	ln -s libXdmcp.so.6.0 libXdmcp.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXdmcp.so.6.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXdmcp.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXdmcp.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXdmcp.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Name: Xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Description: X Display Manager Control Protocol library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Version: 1.0.2" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Requires:" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Requires.private: " >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Libs: -L$(LIBDIR) -lXdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Libs.private: -L$(LIBDIR) -lXdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xdmcp.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
