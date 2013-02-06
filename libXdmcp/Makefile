include	../standard_definitions.mk

DEFS=-Dlinux -D__i386__ -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXdmcp.a $(OBJS:.c=.o)
	$(CC) $(LDFLAGS) -o libXdmcp.so.6.0~ -shared -Wl,-soname,libXdmcp.so.6 $(OBJS:.c=.o)
	mv -f libXdmcp.so.6.0~ libXdmcp.so.6.0
	ln -s libXdmcp.so.6.0 libXdmcp.so.6
	ln -s libXdmcp.so.6.0 libXdmcp.so
	
	@echo "prefix=$(PREDIR)" > xdmcp.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xdmcp.pc
	@echo "libdir=$(PREDIR)/lib" >> xdmcp.pc
	@echo "includedir=$(PREDIR)/include" >> xdmcp.pc
	@echo "" >> xdmcp.pc
	@echo "Name: Xdmcp" >> xdmcp.pc
	@echo "Description: X Display Manager Control Protocol library" >> xdmcp.pc
	@echo "Version: 1.0.2" >> xdmcp.pc
	@echo "Requires:" >> xdmcp.pc
	@echo "Requires.private: " >> xdmcp.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xdmcp.pc
	@echo "Libs: -L$(PREDIR)/lib -lXdmcp" >> xdmcp.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXdmcp" >> xdmcp.pc
	
clean:
	rm -f *.o *.a *.so* xdmcp.pc
	
install:	libXdmcp.a libXdmcp.so.6.0 libXdmcp.so.6 libXdmcp.so
	cp -af libXdmcp.a $(LIBDIR)
	cp -af libXdmcp.so.6.0 $(LIBDIR)
	cp -af libXdmcp.so.6 $(LIBDIR)
	cp -af libXdmcp.so $(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
