include	../standard_definitions.mk

DEFS=-DNOERROR -Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DHAS_WCHAR_H -DHAS_WCTYPE_H -DNO_WIDEC_H -DPROJECT_ROOT=\"/usr\" -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXaw.so.7.1~ -shared -Wl,-soname,libXaw.so.7 $(OBJS:.c=.o)
	mv -f libXaw.so.7.1~ libXaw.so.7.1
	ln -s libXaw.so.7.1 libXaw.so.7
	ln -s libXaw.so.7.1 libXaw.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXaw.so.7.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXaw.so.7 $(DESTDIR)/$(LIBDIR)
	cp -af libXaw.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXaw.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Name: Xaw" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Description: X Athena Widgets Library, version 7" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Version: 1.0.4" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Requires: xpm xproto xt xmu" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Requires.private: xpm xt xmu xext x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Libs: -L$(LIBDIR) -lXaw" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Libs.private: -L$(LIBDIR) -lXaw" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xaw7.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
