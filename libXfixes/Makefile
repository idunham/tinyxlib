include	../standard_definitions.mk

DEFS=-Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXfixes.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXfixes.so.3.0~ -shared -Wl,-soname,libXfixes.so.3 $(OBJS:.c=.o) 
	mv -f libXfixes.so.3.0~ libXfixes.so.3.0
	ln -s libXfixes.so.3.0 libXfixes.so.3
	ln -s libXfixes.so.3.0 libXfixes.so
	
	@echo "prefix=$(PREDIR)" > xfixes.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xfixes.pc
	@echo "libdir=$(PREDIR)/lib" >> xfixes.pc
	@echo "includedir=$(PREDIR)/include" >> xfixes.pc
	@echo "" >> xfixes.pc
	@echo "Name: Xfixes" >> xfixes.pc
	@echo "Description: X Fixes  Library" >> xfixes.pc
	@echo "Version: 4.0.3" >> xfixes.pc
	@echo "Requires: x11" >> xfixes.pc
	@echo "Requires.private: x11" >> xfixes.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xfixes.pc
	@echo "Libs: -L$(PREDIR)/lib -lXfixes" >> xfixes.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXfixes" >> xfixes.pc
	
clean:
	rm -f *.o *.a *.so* xfixes.pc
	
install:
	cp -af libXfixes.a $(DESTDIR)$(LIBDIR)
	cp -af libXfixes.so.3.0 $(DESTDIR)$(LIBDIR)
	cp -af libXfixes.so.3 $(DESTDIR)$(LIBDIR)
	cp -af libXfixes.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
