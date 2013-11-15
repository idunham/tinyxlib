include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE	-D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
	@echo "prefix=$(PREDIR)" > sm.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> sm.pc
	@echo "libdir=$(PREDIR)/lib" >> sm.pc
	@echo "includedir=$(PREDIR)/include" >> sm.pc
	@echo "" >> sm.pc
	@echo "Name: SM" >> sm.pc
	@echo "Description: X Session Management Library" >> sm.pc
	@echo "Version: 1.0.3" >> sm.pc
	@echo "Requires: ice" >> sm.pc
	@echo "Requires.private: ice" >> sm.pc
	@echo "Cflags: -I$(PREDIR)/include" >> sm.pc
	@echo "Libs: -L$(PREDIR)/lib -lSM" >> sm.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lSM" >> sm.pc

clean:
	rm -f *.o sm.pc

install:
	ln -s libX11.a $(LIBDIR)/libSM.a

depend:
	gccmakedep -- $(CFLAGS) -- *.c
