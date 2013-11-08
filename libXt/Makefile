include	../standard_definitions.mk

#-DXTSTRINGDEFINES

DEFS=-Dlinux -D_POSIX_C_SOURCE=199309L -D_POSIX_SOURCE -D_XOPEN_SOURCE -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DFUNCPROTO=15 -DNARROWPROTO -DXTHREADS -D_REENTRANT -DXUSE_MTSAFE_API -DUSE_SNPRINTF -DLIBXT -DXTSTRINGDEFINES  -DXFILESEARCHPATHDEFAULT=\"/usr/lib/X11/%L/%T/%N%C%S:/usr/lib/X11/%l/%T/%N%C%S:/usr/lib/X11/%T/%N%C%S:/usr/lib/X11/%L/%T/%N%S:/usr/lib/X11/%l/%T/%N%S:/usr/lib/X11/%T/%N%S\" -DERRORDB=\"/usr/lib/X11/XtErrorDB\" -DXTERROR_PREFIX=\"\" -DXTWARNING_PREFIX=\"\" -DMALLOC_0_RETURNS_NULL -DXTMALLOC_BC -DTINY

CFLAGS= -I../include -I../include/X11 $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o)
	ar cr libXt.a $(OBJS:.c=.o)

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
	rm -f *.o *.a xt.pc

install:
	cp -af libXt.a $(LIBDIR)

depend:
	gccmakedep -- $(CFLAGS) -- *.c
