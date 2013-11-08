include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DHAS_SNPRINTF -DXTSTRINGDEFINES -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DBITMAPDIR=\"/usr/include/X11/bitmaps\" -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
	ar cr libXmu.a $(OBJS:.c=.o)

	@echo "prefix=$(PREDIR)" > xmu.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xmu.pc
	@echo "libdir=$(PREDIR)/lib" >> xmu.pc
	@echo "includedir=$(PREDIR)/include" >> xmu.pc
	@echo "" >> xmu.pc
	@echo "Name: Xmu" >> xmu.pc
	@echo "Description: Xmu Library" >> xmu.pc
	@echo "Version: 1.0.3" >> xmu.pc
	@echo "Requires: xt sm ice xext x11 xau xdmcp" >> xmu.pc
	@echo "Requires.private: xt sm ice xext x11 xau xdmcp" >> xmu.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xmu.pc
	@echo "Libs: -L$(PREDIR)/lib -lXmu" >> xmu.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXmu" >> xmu.pc

clean:
	rm -f *.o *.a xmu.pc

install:
	cp -af libXmu.a $(LIBDIR)

depend:
	gccmakedep -- $(CFLAGS) -- *.c
