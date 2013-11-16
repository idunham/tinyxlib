include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DHAS_SNPRINTF -DXTSTRINGDEFINES -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DBITMAPDIR=\"/usr/include/X11/bitmaps\" -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXmuu.so.1.0~ -shared -Wl,-soname,libXmuu.so.1 $(OBJS:.c=.o)
	mv -f libXmuu.so.1.0~ libXmuu.so.1.0
	ln -s libXmuu.so.1.0 libXmuu.so.1
	ln -s libXmuu.so.1.0 libXmuu.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXmuu.so.1.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXmuu.so.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXmuu.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXmuu.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Name: Xmuu" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Description: Mini Xmu Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Version: 1.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Requires: x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Requires.private: x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Libs: -L$(LIBDIR) -lXmuu" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc
	@echo "Libs.private: -L$(LIBDIR) -lXmuu" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xmuu.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
