include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT

DEFS=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t -DOLDXAW

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

libXaw.a:	$(OBJS:.c=.o) 
	ar cr libXaw.a $(OBJS:.c=.o) 
clean:
	rm -f *.o *.a
install:	libXaw.a
	cp -f libXaw.a $(LIBDIR)
depend:
	gccmakedep -- $(CFLAGS) -- *.c
