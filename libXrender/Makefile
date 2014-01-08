include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO   -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

#OBJS=$(wildcard *.c)
OBJS=Xrender.c Composite.c Glyph.c Picture.c FillRect.c FillRects.c

all:	$(OBJS:.c=.o) 
	ar cr libXrender.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXrender.so.1.1~ -shared -Wl,-soname,libXrender.so.1 $(OBJS:.c=.o) 
	mv -f libXrender.so.1.1~ libXrender.so.1.1
	ln -s libXrender.so.1.1 libXrender.so.1
	ln -s libXrender.so.1.1 libXrender.so	
	
	@echo "prefix=$(PREDIR)" > xrender.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xrender.pc
	@echo "libdir=$(PREDIR)/lib" >> xrender.pc
	@echo "includedir=$(PREDIR)/include" >> xrender.pc
	@echo "" >> xrender.pc
	@echo "Name: Xrender" >> xrender.pc
	@echo "Description: X Render Library" >> xrender.pc
	@echo "Version: 1.0.3" >> xrender.pc
	@echo "Requires: x11 xau xdmcp" >> xrender.pc
	@echo "Requires.private: x11 xau xdmcp" >> xrender.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xrender.pc
	@echo "Libs: -L$(PREDIR)/lib -lXrender" >> xrender.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXrender" >> xrender.pc
	
clean:
	rm -f *.o *.a *.so* xrender.pc
	
install:
	cp -af libXrender.a $(DESTDIR)$(LIBDIR)
	cp -af libXrender.so.1.1 $(DESTDIR)$(LIBDIR)
	cp -af libXrender.so.1 $(DESTDIR)$(LIBDIR)
	cp -af libXrender.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
