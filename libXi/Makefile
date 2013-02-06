include	../standard_definitions.mk

DEFS=-DICE_t -DTRANS_CLIENT 

CFLAGS= -I../include -I../include/X11 -I../libxtrans $(COMMONDEFS) $(DEFS)

OBJS=$(wildcard *.c)

all:	$(OBJS:.c=.o) 
	ar cr libXi.a $(OBJS:.c=.o) 
	$(CC) $(LDFLAGS) -o libXi.so.6.0~ -shared -Wl,-soname,libXi.so.6 $(OBJS:.c=.o) 
	mv -f libXi.so.6.0~ libXi.so.6.0
	ln -s libXi.so.6.0 libXi.so.6
	ln -s libXi.so.6.0 libXi.so	
	
clean:
	rm -f *.o *.a *.so*
	
install:
	cp -af libXi.a $(LIBDIR)
	cp -af libXi.so.6.0 $(LIBDIR)
	cp -af libXi.so.6 $(LIBDIR)
	cp -af libXi.so $(LIBDIR)
	
depend:
	gccmakedep -- $(CFLAGS) -- *.c