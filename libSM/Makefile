include	../standard_definitions.mk

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DIPv6 -DICE_t

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libSM.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libSM.so.6.0~ -shared -Wl,-soname,libSM.so.6 $(OBJS:.c=.o) 
	mv -f libSM.so.6.0~ libSM.so.6.0
	ln -s libSM.so.6.0 libSM.so.6
	ln -s libSM.so.6.0 libSM.so	
	
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
	rm -f *.o *.a *.so* sm.pc
	
install:
	cp -af libSM.a $(DESTDIR)$(LIBDIR)
	cp -af libSM.so.6.0 $(DESTDIR)$(LIBDIR)
	cp -af libSM.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libSM.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
