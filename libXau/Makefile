include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libXau.so.6.0~ -shared -Wl,-soname,libXau.so.6 $(OBJS:.c=.o)
	mv -f libXau.so.6.0~ libXau.so.6.0
	ln -s libXau.so.6.0 libXau.so.6
	ln -s libXau.so.6.0 libXau.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libXau.so.6.0 $(LIBDIR)
	cp -af libXau.so.6 $(LIBDIR)
	cp -af libXau.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXau.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xau.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Name: Xau" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Description: X authorization file management libary" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Version: 1.0.3" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Requires:" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Requires.private:" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Libs: -L$(PREDIR)/lib -lXau" >> $(LIBDIR)/pkgconfig/xau.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXau " >> $(LIBDIR)/pkgconfig/xau.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
