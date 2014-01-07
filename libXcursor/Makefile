include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXcursor.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXcursor.so.6.0~ -shared -Wl,-soname,libXcursor.so.6 $(OBJS:.c=.o)
	mv -f libXcursor.so.6.0~ libXcursor.so.6.0
	ln -s libXcursor.so.6.0 libXcursor.so.6
	ln -s libXcursor.so.6.0 libXcursor.so
	
	@echo "prefix=$(PREDIR)" > xcursor.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xcursor.pc
	@echo "libdir=$(PREDIR)/lib" >> xcursor.pc
	@echo "includedir=$(PREDIR)/include" >> xcursor.pc
	@echo "" >> xcursor.pc
	@echo "Name: Xcursor" >> xcursor.pc
	@echo "Description: X Cursor library" >> xcursor.pc
	@echo "Version: .0" >> xcursor.pc
	@echo "Requires:" >> xcursor.pc
	@echo "Requires.private:" >> xcursor.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xcursor.pc
	@echo "Libs: -L$(PREDIR)/lib -lXcursor" >> xcursor.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXcursor" >> xcursor.pc
	
clean:
	rm -f *.o *.a *.so* xcursor.pc
	
install:	
	cp -af libXcursor.a $(DESTDIR)$(LIBDIR)
	cp -af libXcursor.so.6.0 $(DESTDIR)$(LIBDIR)
	cp -af libXcursor.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libXcursor.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
