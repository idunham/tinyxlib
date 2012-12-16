include	../standard_definitions.mk

#DEFS=-DTINY -DX11_t -DTRANS_CLIENT -DTCPCONN -DXTHREADS -DXOS_USE_MTSAFE_PWDAPI -D_POSIX_THREAD_SAFE_FUNCTIONS -DXUSE_MTSAFE_NETDBAPI

#-DXOS_USE_MTSAFE_PWDAPI needed for GetDflt.c

DEFS=-Dlinux -DXTHREADS -D__i386__ -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO -DMALLOC_0_RETURNS_NULL -DHAS_SNPRINTF -DLIBX11 -DUNIXCONN -DTCPCONN -DX11_t -DTRANS_CLIENT  -DKEYSYMDB=\"/usr/X11R7/lib/X11/XKeysymDB\" -DXLOCALEDIR=\"/usr/share/locale\" -DX_LOCALE -DTINY -DXOS_USE_MTSAFE_PWDAPI

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

#XAUOBJS=$(wildcard ../libXau/*.c)
XAUOBJS=../libXau/AuDispose.c ../libXau/AuFileName.c ../libXau/AuGetBest.c ../libXau/AuRead.c

libX11.a:	$(OBJS:.c=.o) 
	ar cr libX11.a $(OBJS:.c=.o) $(XAUOBJS:.c=.o)
KeysymStr.o:	KeysymStr.c ks_tables.h
#makekeys:	makekeys.o
#	$(CC) $(LDFLAGS) -o makekeys makekeys.o
#ks_tables.h:	makekeys
#	./makekeys < ../include/X11/keysymdef.h >ks_tables.h
transport.o:	transport.c xtrans/Xtranssock.c
	$(CC) -c $(CFLAGS) transport.c
clean:
	rm -f *.o *.a makekeys
install:	libX11.a
	cp -f libX11.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c