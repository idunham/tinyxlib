include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
	ar cr libXdmcp.a $(OBJS:.c=.o)

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
	rm -f *.o *.a xdmcp.pc

install:	libXdmcp.a
	cp -af libXdmcp.a $(LIBDIR)

depend:
	gccmakedep -- $(CFLAGS) -- *.c
