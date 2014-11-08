include	../standard_definitions.mk

#-DXTSTRINGDEFINES 

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DLIBXT -DXTSTRINGDEFINES  -DXFILESEARCHPATHDEFAULT=\"/usr/lib/X11/%L/%T/%N%C%S:/usr/lib/X11/%l/%T/%N%C%S:/usr/lib/X11/%T/%N%C%S:/usr/lib/X11/%L/%T/%N%S:/usr/lib/X11/%l/%T/%N%S:/usr/lib/X11/%T/%N%S\" -DERRORDB=\"/usr/lib/X11/XtErrorDB\" -DXTERROR_PREFIX=\"\" -DXTWARNING_PREFIX=\"\" -DMALLOC_0_RETURNS_NULL -DXTMALLOC_BC -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXt.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXt.so.6.1~ -shared -Wl,-soname,libXt.so.6 $(OBJS:.c=.o) \
	-L../libSM -lSM -L../libICE -lICE -L../libtinyX11 -lX11
	mv -f libXt.so.6.1~ libXt.so.6.1
	ln -s libXt.so.6.1 libXt.so.6
	ln -s libXt.so.6.1 libXt.so
	
	@echo "prefix=$(PREDIR)" > xt.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xt.pc
	@echo "libdir=$(PREDIR)/lib" >> xt.pc
	@echo "includedir=$(PREDIR)/include" >> xt.pc
	@echo "" >> xt.pc
	@echo "Name: Xt" >> xt.pc
	@echo "Description: X Toolkit Library" >> xt.pc
	@echo "Version: 1.0.5" >> xt.pc
	@echo "Requires: sm ice x11 xau xdmcp" >> xt.pc
	@echo "Requires.private: sm ice x11 xau xdmcp" >> xt.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xt.pc
	@echo "Libs: -L$(PREDIR)/lib -lXt" >> xt.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXt" >> xt.pc
	
clean:
	rm -f *.o *.a *.so* xt.pc
	
install:
	cp -af libXt.a $(DESTDIR)$(LIBDIR)
	cp -af libXt.so.6.1 $(DESTDIR)$(LIBDIR)
	cp -af libXt.so.6 $(DESTDIR)$(LIBDIR)
	cp -af libXt.so $(DESTDIR)$(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c
