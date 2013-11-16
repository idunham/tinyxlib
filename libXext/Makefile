include	../standard_definitions.mk

DEFS=-DNOERROR -Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXext.so.6.5~ -shared -Wl,-soname,libXext.so.6 $(OBJS:.c=.o)
	mv -f libXext.so.6.5~ libXext.so.6.5
	ln -s libXext.so.6.5 libXext.so.6
	ln -s libXext.so.6.5 libXext.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXext.so.6.5 $(DESTDIR)/$(LIBDIR)
	cp -af libXext.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libXext.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXext.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Name: Xext" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Description: Misc X Extension Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Version: 1.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Requires: x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Requires.private: x11 xau xdmcp" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Libs: -L$(LIBDIR) -lXext" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc
	@echo "Libs.private: -L$(LIBDIR) -lXext" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xext.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
