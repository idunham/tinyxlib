include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libSM.so.6.0~ -shared -Wl,-soname,libSM.so.6 $(OBJS:.c=.o)
	mv -f libSM.so.6.0~ libSM.so.6.0
	ln -s libSM.so.6.0 libSM.so.6
	ln -s libSM.so.6.0 libSM.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libSM.so.6.0 $(DESTDIR)/$(LIBDIR)
	cp -af libSM.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libSM.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libSM.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Name: SM" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Description: X Session Management Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Version: 1.0.3" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Requires: ice" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Requires.private: ice" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Libs: -L$(LIBDIR) -lSM" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc
	@echo "Libs.private: -L$(LIBDIR) -lSM" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/sm.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c
