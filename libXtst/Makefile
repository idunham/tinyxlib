include	../standard_definitions.mk

DEFS=-Dlinux -D__i386__ -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXtst.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXtst.so.6.1~ -shared -Wl,-soname,libXtst.so.6 $(OBJS:.c=.o)
	mv -f libXtst.so.6.1~ libXtst.so.6.1
	ln -s libXtst.so.6.1 libXtst.so.6
	ln -s libXtst.so.6.1 libXtst.so
	
	@echo "prefix=$(PREDIR)" > xtst.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xtst.pc
	@echo "libdir=$(PREDIR)/lib" >> xtst.pc
	@echo "includedir=$(PREDIR)/include" >> xtst.pc
	@echo "" >> xtst.pc
	@echo "Name: Xtst" >> xtst.pc
	@echo "Description: The Xtst Library" >> xtst.pc
	@echo "Version: 1.0.3" >> xtst.pc
	@echo "Requires: xx11 xext" >> xtst.pc
	@echo "Requires.private: x11 xext" >> xtst.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xtst.pc
	@echo "Libs: -L$(PREDIR)/lib -lXtst" >> xtst.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXtst" >> xtst.pc
	
clean:
	rm -f *.o *.a *.so* xtst.pc
	
install:
	cp -af libXtst.a $(DESTDIR)$(LIBDIR)
	cp -af libXtst.so.6.1 $(DESTDIR)$(LIBDIR)
	cp -af libXtst.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libXtst.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
