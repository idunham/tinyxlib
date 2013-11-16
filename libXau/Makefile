include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXau.so.6.0~ -shared -Wl,-soname,libXau.so.6 $(OBJS:.c=.o)
	mv -f libXau.so.6.0~ libXau.so.6.0
	ln -s libXau.so.6.0 libXau.so.6
	ln -s libXau.so.6.0 libXau.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXau.so.6.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXau.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXau.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXau.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Name: Xau" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Description: X authorization file management libary" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Version: 1.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Requires:" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Requires.private:" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Libs: -L$(LIBDIR) -lXau" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc
	@echo "Libs.private: -L$(LIBDIR) -lXau " >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xau.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
