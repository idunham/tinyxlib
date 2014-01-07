include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DHAS_SNPRINTF -DXTSTRINGDEFINES -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DBITMAPDIR=\"/usr/include/X11/bitmaps\" -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXmuu.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXmuu.so.1.0~ -shared -Wl,-soname,libXmuu.so.1 $(OBJS:.c=.o)
	mv -f libXmuu.so.1.0~ libXmuu.so.1.0
	ln -s libXmuu.so.1.0 libXmuu.so.1
	ln -s libXmuu.so.1.0 libXmuu.so	
	
	@echo "prefix=$(PREDIR)" > xmuu.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xmuu.pc
	@echo "libdir=$(PREDIR)/lib" >> xmuu.pc
	@echo "includedir=$(PREDIR)/include" >> xmuu.pc
	@echo "" >> xmuu.pc
	@echo "Name: Xmuu" >> xmuu.pc
	@echo "Description: Mini Xmu Library" >> xmuu.pc
	@echo "Version: 1.0.3" >> xmuu.pc
	@echo "Requires: x11 xau xdmcp" >> xmuu.pc
	@echo "Requires.private: x11 xau xdmcp" >> xmuu.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xmuu.pc
	@echo "Libs: -L$(PREDIR)/lib -lXmuu" >> xmuu.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXmuu" >> xmuu.pc
	
clean:
	rm -f *.o *.a *.so* xmuu.pc
	
install:
	cp -af libXmuu.a $(DESTDIR)$(LIBDIR)
	cp -af libXmuu.so.1.0 $(DESTDIR)$(LIBDIR)
	cp -af libXmuu.so.1 $(DESTDIR)$(LIBDIR)
	cp -af libXmuu.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
