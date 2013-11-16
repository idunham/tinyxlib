include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXtst.so.6.1~ -shared -Wl,-soname,libXtst.so.6 $(OBJS:.c=.o)
	mv -f libXtst.so.6.1~ libXtst.so.6.1
	ln -s libXtst.so.6.1 libXtst.so.6
	ln -s libXtst.so.6.1 libXtst.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXtst.so.6.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXtst.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXtst.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXtst.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Name: Xtst" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Description: The Xtst Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Version: 1.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Requires: xx11 xext" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Requires.private: x11 xext" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Libs: -L$(LIBDIR) -lXtst" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc
	@echo "Libs.private: -L$(LIBDIR) -lXtst" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xtst.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
