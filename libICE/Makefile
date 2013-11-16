include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t -DTRANS_CLIENT -DTRANS_SERVER

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libICE.so.6.3~ -shared -Wl,-soname,libICE.so.6 $(OBJS:.c=.o)
	mv -f libICE.so.6.3~ libICE.so.6.3
	ln -s libICE.so.6.3 libICE.so.6
	ln -s libICE.so.6.3 libICE.so
endif

clean:
	rm -f *.o *.so*

install:
ifeq ($(STATIC),0)
	cp -af libICE.so.6.3 $(DESTDIR)/$(LIBDIR)
	cp -af libICE.so.6 $(DESTDIR)/$(LIBDIR)
	cp -af libICE.so $(DESTDIR)/$(LIBDIR)
else
	ln -s libX11.a $(DESTDIR)/$(LIBDIR)/libICE.a
endif
	@echo "prefix=$(PREFIX)" > $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "exec_prefix=$(BINDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "libdir=$(LIBDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "includedir=$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Name: ICE" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Description: X Inter Client Exchange Library" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Version: 1.0.4" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Requires: x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Requires.private: x11" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Cflags: -I$(INCDIR)" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Libs: -L$(LIBDIR) -lICE" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc
	@echo "Libs.private: -L$(LIBDIR) -lICE" >> $(DESTDIR)/$(LIBDIR)/pkgconfig/ice.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c