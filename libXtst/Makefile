include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
	ar cr libXtst.a $(OBJS:.c=.o)

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
	rm -f *.o *.a xtst.pc

install:
	cp -af libXtst.a $(LIBDIR)

depend:
	gccmakedep -- $(CFLAGS) -- *.c
