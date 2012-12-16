include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT -DTINY

DEFS=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DHAS_SNPRINTF -DXTSTRINGDEFINES -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DBITMAPDIR=\"/usr/include/X11/bitmaps\" -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXmu.a:	$(OBJS:.c=.o) 
	ar cr libXmu.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXmu.a
	cp -f libXmu.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c
