include	../standard_definitions.mk

DEFS=-DNOERROR -Dlinux -D__i386__ -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DMALLOC_0_RETURNS_NULL

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXext.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXext.so.6.5~ -shared -Wl,-soname,libXext.so.6 $(OBJS:.c=.o)
	mv -f libXext.so.6.5~ libXext.so.6.5
	ln -s libXext.so.6.5 libXext.so.6
	ln -s libXext.so.6.5 libXext.so	
	
	@echo "prefix=$(PREDIR)" > xext.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xext.pc
	@echo "libdir=$(PREDIR)/lib" >> xext.pc
	@echo "includedir=$(PREDIR)/include" >> xext.pc
	@echo "" >> xext.pc
	@echo "Name: Xext" >> xext.pc
	@echo "Description: Misc X Extension Library" >> xext.pc
	@echo "Version: 1.0.3" >> xext.pc
	@echo "Requires: x11 xau xdmcp" >> xext.pc
	@echo "Requires.private: x11 xau xdmcp" >> xext.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xext.pc
	@echo "Libs: -L$(PREDIR)/lib -lXext" >> xext.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXext" >> xext.pc
	
clean:
	rm -f *.o *.a *.so* xext.pc
	
install:
	cp -af libXext.a $(DESTDIR)$(LIBDIR)
	cp -af libXext.so.6.5 $(DESTDIR)$(LIBDIR)
	cp -af libXext.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libXext.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
