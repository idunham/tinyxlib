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
	cp -af libXext.so.6.5 $(LIBDIR)
	cp -af libXext.so.6 $(LIBDIR)
	cp -af libXext.so $(LIBDIR)
else
	ln -s libX11.a $(LIBDIR)/libXext.a
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/xext.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Name: Xext" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Description: Misc X Extension Library" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Version: 1.0.3" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Requires: x11 xau xdmcp" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Requires.private: x11 xau xdmcp" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Libs: -L$(PREDIR)/lib -lXext" >> $(LIBDIR)/pkgconfig/xext.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXext" >> $(LIBDIR)/pkgconfig/xext.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
