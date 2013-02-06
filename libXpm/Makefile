include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT
CFLAGS= -I../include -I../ $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXpm.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXpm.so.1.0~ -shared -Wl,-soname,libXpm.so.1 $(OBJS:.c=.o) 
	mv -f libXpm.so.1.0~ libXpm.so.1.0
	ln -s libXpm.so.1.0 libXpm.so.1
	ln -s libXpm.so.1.0 libXpm.so
	
	@echo "prefix=$(PREDIR)" > xpm.pc
	@echo "exec_prefix=$(PREDIR)/bin" >> xpm.pc
	@echo "libdir=$(PREDIR)/lib" >> xpm.pc
	@echo "includedir=$(PREDIR)/include" >> xpm.pc
	@echo "" >> xpm.pc
	@echo "Name: Xpm" >> xpm.pc
	@echo "Description: X Pixmap Library" >> xpm.pc
	@echo "Version: 3.5.7" >> xpm.pc
	@echo "Requires: x11" >> xpm.pc
	@echo "Requires.private: x11" >> xpm.pc
	@echo "Cflags: -I$(PREDIR)/include" >> xpm.pc
	@echo "Libs: -L$(PREDIR)/lib -lXpm" >> xpm.pc
	@echo "Libs.private: -L$(PREDIR)/lib -lXpm" >> xpm.pc
	
clean:
	rm -f *.o *.a *.so* xpm.pc
	
install:
	cp -af libXpm.a $(LIBDIR)
	cp -af libXpm.so.1.0 $(LIBDIR)
	cp -af libXpm.so.1 $(LIBDIR)
	cp -af libXpm.so $(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c