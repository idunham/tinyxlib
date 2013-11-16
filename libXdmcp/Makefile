include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXdmcp.so.6.0~ -shared -Wl,-soname,libXdmcp.so.6 $(OBJS:.c=.o)
	mv -f libXdmcp.so.6.0~ libXdmcp.so.6.0
	ln -s libXdmcp.so.6.0 libXdmcp.so.6
	ln -s libXdmcp.so.6.0 libXdmcp.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXdmcp.so.6.0 $(LIBDIR)
	cp -af libXdmcp.so.6 $(LIBDIR)
	cp -af libXdmcp.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXdmcp.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Name: Xdmcp" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Description: X Display Manager Control Protocol library" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Version: 1.0.2" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Requires:" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Requires.private: " >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Libs: -L$(PREDIR)/lib -lXdmcp" >> $(LIBDIR)/pkgconfig/xdmcp.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXdmcp" >> $(LIBDIR)/pkgconfig/xdmcp.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
