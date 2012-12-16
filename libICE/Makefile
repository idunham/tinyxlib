include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT 

DEFS=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t -DTRANS_CLIENT -DTRANS_SERVER


CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libICE.a:	$(OBJS:.c=.o) 
	ar cr libICE.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libICE.a
	cp -f libICE.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c