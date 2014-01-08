include	../standard_definitions.mk

#DEFS=-DICE_t -DTRANS_CLIENT 

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DHAS_FCHOWN -DIPv6 -DICE_t -DTRANS_CLIENT -DTRANS_SERVER

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libICE.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libICE.so.6.3~ -shared -Wl,-soname,libICE.so.6 $(OBJS:.c=.o) 
	mv -f libICE.so.6.3~ libICE.so.6.3
	ln -s libICE.so.6.3 libICE.so.6
	ln -s libICE.so.6.3 libICE.so
	
	@echo "prefix=$(PREDIR)" > ice.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> ice.pc
	@echo "libdir=$(PREDIR)/lib" >> ice.pc
	@echo "includedir=$(PREDIR)/include" >> ice.pc
	@echo "" >> ice.pc
	@echo "Name: ICE" >> ice.pc
	@echo "Description: X Inter Client Exchange Library" >> ice.pc
	@echo "Version: 1.0.4" >> ice.pc
	@echo "Requires: x11" >> ice.pc
	@echo "Requires.private: x11" >> ice.pc
	@echo "Cflags: -I$(PREDIR)/include" >> ice.pc
	@echo "Libs: -L$(PREDIR)/lib -lICE" >> ice.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lICE" >> ice.pc		
	
clean:
	rm -f *.o *.a *.so* ice.pc
	
install:
	cp -af libICE.a $(DESTDIR)$(LIBDIR)
	cp -af libICE.so.6.3 $(DESTDIR)$(LIBDIR)
	cp -af libICE.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libICE.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c