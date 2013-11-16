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
	cp -af libXpm.so.1.0 $(LIBDIR)
	cp -af libXpm.so.1 $(LIBDIR)
	cp -af libXpm.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXpm.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xpm.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Name: Xpm" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Description: X Pixmap Library" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Version: 3.5.7" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Requires: x11" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Requires.private: x11" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Libs: -L$(PREDIR)/lib -lXpm" >> $(LIBDIR)/pkgconfig/xpm.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXpm" >> $(LIBDIR)/pkgconfig/xpm.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c