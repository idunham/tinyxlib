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
	cp -af libXfixes.so.3.0 $(LIBDIR)
	cp -af libXfixes.so.3 $(LIBDIR)
	cp -af libXfixes.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXfixes.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Name: Xfixes" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Description: X Fixes  Library" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Version: 4.0.3" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Requires: x11" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Requires.private: x11" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Libs: -L$(PREDIR)/lib -lXfixes" >> $(LIBDIR)/pkgconfig/xfixes.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXfixes" >> $(LIBDIR)/pkgconfig/xfixes.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
