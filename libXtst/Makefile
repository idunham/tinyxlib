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
	cp -af libXtst.so.6.1 $(LIBDIR)
	cp -af libXtst.so.6 $(LIBDIR)
	cp -af libXtst.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXtst.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xtst.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Name: Xtst" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Description: The Xtst Library" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Version: 1.0.3" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Requires: xx11 xext" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Requires.private: x11 xext" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Libs: -L$(PREDIR)/lib -lXtst" >> $(LIBDIR)/pkgconfig/xtst.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXtst" >> $(LIBDIR)/pkgconfig/xtst.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
