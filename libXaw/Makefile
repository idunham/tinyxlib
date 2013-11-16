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
	cp -af libXaw.so.7.1 $(LIBDIR)
	cp -af libXaw.so.7 $(LIBDIR)
	cp -af libXaw.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXaw.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Name: Xaw" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Description: X Athena Widgets Library, version 7" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Version: 1.0.4" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Requires: xpm xproto xt xmu" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Requires.private: xpm xt xmu xext x11" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Libs: -L$(PREDIR)/lib -lXaw" >> $(LIBDIR)/pkgconfig/xaw7.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXaw" >> $(LIBDIR)/pkgconfig/xaw7.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
