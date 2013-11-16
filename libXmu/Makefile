include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DHAS_SNPRINTF -DXTSTRINGDEFINES -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DBITMAPDIR=\"/usr/include/X11/bitmaps\" -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXmu.so.6.2~ -shared -Wl,-soname,libXmu.so.6 $(OBJS:.c=.o)
	mv -f libXmu.so.6.2~ libXmu.so.6.2
	ln -s libXmu.so.6.2 libXmu.so.6
	ln -s libXmu.so.6.2 libXmu.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXmu.so.6.2 $(LIBDIR)
	cp -af libXmu.so.6 $(LIBDIR)
	cp -af libXmu.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXmu.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xmu.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Name: Xmu" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Description: Xmu Library" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Version: 1.0.3" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Requires: xt sm ice xext x11 xau xdmcp" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Requires.private: xt sm ice xext x11 xau xdmcp" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Libs: -L$(PREDIR)/lib -lXmu" >> $(LIBDIR)/pkgconfig/xmu.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXmu" >> $(LIBDIR)/pkgconfig/xmu.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
