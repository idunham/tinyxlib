include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT
CFLAGS= -I../include -I../ $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXpm.so.1.0~ -shared -Wl,-soname,libXpm.so.1 $(OBJS:.c=.o)
	mv -f libXpm.so.1.0~ libXpm.so.1.0
	ln -s libXpm.so.1.0 libXpm.so.1
	ln -s libXpm.so.1.0 libXpm.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXpm.so.1.0 $(DESTDIR)/$(LIBDIR)
	cp -af libXpm.so.1 $(DESTDIR)/$(LIBDIR)
	cp -af libXpm.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libXpm.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Name: Xpm" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Description: X Pixmap Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Version: 3.5.7" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Requires: x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Requires.private: x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Libs: -L$(LIBDIR) -lXpm" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc
	@echo "Libs.private: -L$(LIBDIR) -lXpm" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/xpm.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c