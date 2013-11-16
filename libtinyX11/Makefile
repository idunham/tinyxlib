include	../standard_definitions.mk

#-DXOS_USE_MTSAFE_PWDAPI needed for GetDflt.c

DEFS=-Dlinux -DXTHREADS -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO -DMALLOC_0_RETURNS_NULL -DHAS_SNPRINTF -DLIBX11 -DUNIXCONN -DTCPCONN -DX11_t -DTRANS_CLIENT  -DKEYSYMDB=\"/usr/X11R7/lib/X11/XKeysymDB\" -DXLOCALEDIR=\"/usr/share/locale\" -DX_LOCALE -DTINY -DXOS_USE_MTSAFE_PWDAPI

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

#XAUOBJS=$(wildcard ../libXau/*.c)
XAUOBJS=../libXau/AuDispose.c ../libXau/AuFileName.c ../libXau/AuGetBest.c ../libXau/AuRead.c

all:	$(OBJS:.c=.o)
ifeq ($(STATIC),0)
	$(CC) $(LDFLAGS) -o libX11.so.6.2~ -shared -Wl,-soname,libX11.so.6.2 $(OBJS:.c=.o) $(XAUOBJS:.c=.o)
	mv -f libX11.so.6.2~ libX11.so.6.2
	ln -s libX11.so.6.2 libX11.so.6
	ln -s libX11.so.6.2 libX11.so
endif

#KeysymStr.o:	KeysymStr.c ks_tables.h
#makekeys:	makekeys.o
#	$(CC) $(LDFLAGS) -o makekeys makekeys.o
#ks_tables.h:	makekeys
#	./makekeys < ../include/X11/keysymdef.h >ks_tables.h

transport.o:	transport.c xtrans/Xtranssock.c
	$(CC) -c $(CFLAGS) transport.c

clean:
	rm -f *.o *.so*
#rm -f makekeys

install:
ifeq ($(STATIC),0)
	cp -af libX11.so.6.2 $(LIBDIR)
	cp -af libX11.so.6 $(LIBDIR)
	cp -af libX11.so $(LIBDIR)
endif
	@echo "prefix=$(PREDIR)" > $(LIBDIR)/pkgconfig/x11.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "libdir=$(PREDIR)/lib" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "includedir=$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "xthreadlib=-lpthread" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Name: X11" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Description: X Library" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Version: 1.1.3" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Requires: xau xdmcp " >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Requires.private: xau xdmcp " >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Cflags: -I$(PREDIR)/include" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Libs: -L$(PREDIR)/lib -lX11" >> $(LIBDIR)/pkgconfig/x11.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lX11 -lpthread" >> $(LIBDIR)/pkgconfig/x11.pc

depend:
	gccmakedep -- $(CFLAGS) -- *.c