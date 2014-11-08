include	../standard_definitions.mk

DEFS=-DNOERROR -Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DHAS_WCHAR_H -DHAS_WCTYPE_H -DNO_WIDEC_H -DPROJECT_ROOT=\"/usr\" -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUNIXCONN -DTCPCONN -DHAS_STICKY_DIR_BIT -DIPv6 -DICE_t 

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXaw.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXaw.so.7.1~ -shared -Wl,-soname,libXaw.so.7 $(OBJS:.c=.o) \
	-L../libXpm -lXpm -L../libXmu -lXmu 
	mv -f libXaw.so.7.1~ libXaw.so.7.1
	ln -s libXaw.so.7.1 libXaw.so.7
	ln -s libXaw.so.7.1 libXaw.so
	
	@echo "prefix=$(PREDIR)" > xaw7.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xaw7.pc
	@echo "libdir=$(PREDIR)/lib" >> xaw7.pc
	@echo "includedir=$(PREDIR)/include" >> xaw7.pc
	@echo "" >> xaw7.pc
	@echo "Name: Xaw" >> xaw7.pc
	@echo "Description: X Athena Widgets Library, version 7" >> xaw7.pc
	@echo "Version: 1.0.4" >> xaw7.pc
	@echo "Requires: xpm xproto xt xmu" >> xaw7.pc
	@echo "Requires.private: xpm xt xmu xext x11" >> xaw7.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xaw7.pc
	@echo "Libs: -L$(PREDIR)/lib -lXaw" >> xaw7.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXaw" >> xaw7.pc	
	
clean:
	rm -f *.o *.a *.so* xaw7.pc
	
install:
	cp -af libXaw.a $(DESTDIR)$(LIBDIR)
	cp -af libXaw.so.7.1 $(DESTDIR)$(LIBDIR)
	cp -af libXaw.so.7 $(DESTDIR)$(LIBDIR)
	cp -af libXaw.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
