include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXcursor.so.6.0~ -shared -Wl,-soname,libXcursor.so.6 $(OBJS:.c=.o)
	mv -f libXcursor.so.6.0~ libXcursor.so.6.0
	ln -s libXcursor.so.6.0 libXcursor.so.6
	ln -s libXcursor.so.6.0 libXcursor.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXcursor.so.6.0 $(LIBDIR)
	cp -af libXcursor.so.6 $(LIBDIR)
	cp -af libXcursor.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXcursor.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Name: Xcursor" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Description: X Cursor library" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Version: .0" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Requires:" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Requires.private:" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Libs: -L$(PREDIR)/lib -lXcursor" >> $(LIBDIR)/pkgconfig/xcursor.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXcursor" >> $(LIBDIR)/pkgconfig/xcursor.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
