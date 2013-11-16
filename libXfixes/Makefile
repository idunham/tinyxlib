include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXfixes.so.3.0~ -shared -Wl,-soname,libXfixes.so.3 $(OBJS:.c=.o)
	mv -f libXfixes.so.3.0~ libXfixes.so.3.0
	ln -s libXfixes.so.3.0 libXfixes.so.3
	ln -s libXfixes.so.3.0 libXfixes.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXfixes.so.3.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXfixes.so.3 $(DESTDIR)/$(LIBDIR)
	cp -af libXfixes.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXfixes.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Name: Xfixes" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Description: X Fixes  Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Version: 4.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Requires: x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Requires.private: x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Libs: -L$(LIBDIR) -lXfixes" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Libs.private: -L$(LIBDIR) -lXfixes" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xfixes.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
