include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE  -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXau.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXau.so.6.0~ -shared -Wl,-soname,libXau.so.6 $(OBJS:.c=.o)
	mv -f libXau.so.6.0~ libXau.so.6.0
	ln -s libXau.so.6.0 libXau.so.6
	ln -s libXau.so.6.0 libXau.so
	
	@echo "prefix=$(PREDIR)" > xau.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xau.pc
	@echo "libdir=$(PREDIR)/lib" >> xau.pc
	@echo "includedir=$(PREDIR)/include" >> xau.pc
	@echo "" >> xau.pc
	@echo "Name: Xau" >> xau.pc
	@echo "Description: X authorization file management libary" >> xau.pc
	@echo "Version: 1.0.3" >> xau.pc
	@echo "Requires:" >> xau.pc
	@echo "Requires.private:" >> xau.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xau.pc
	@echo "Libs: -L$(PREDIR)/lib -lXau" >> xau.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXau " >> xau.pc
	
clean:
	rm -f *.o *.a *.so* xau.pc
	
install:	
	cp -af libXau.a $(DESTDIR)$(LIBDIR)
	cp -af libXau.so.6.0 $(DESTDIR)$(LIBDIR)
	cp -af libXau.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libXau.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
