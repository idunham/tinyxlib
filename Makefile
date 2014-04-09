include	./standard_definitions.mk

all:
	cd libXau; make
	cd libtinyX11; make
	cd libICE; make
	cd libSM; make
	cd libXmu; make
	cd libXt; make
	cd libXv; make
	cd libXext; make
	cd libXinerama; make
	cd libXrender; make
	cd libXpm; make
	cd libXtst; make
	cd libXfont; make
	cd libXdmcp; make
	cd libXi; make
	cd libXaw; make
	cd libXmuu; make
	cd libXss; make
	cd libXfixes; make
	cd libXcursor; make
ifeq ($(STATIC),1)
	ar cr libX11.a `find -name '*.o'`
endif
clean:
	rm -f libX11.a
	cd libtinyX11; make clean
	cd libICE; make clean
	cd libSM; make clean
	cd libXmu; make clean
	cd libXt; make clean
	cd libXv; make clean
	cd libXext; make clean
	cd libXinerama; make clean
	cd libXau; make clean
	cd libXrender; make clean
	cd libXpm; make clean
	cd libXtst; make clean
	cd libXfont; make clean
	cd libXdmcp; make clean
	cd libXi; make clean
	cd libXaw; make clean
	cd libXmuu; make clean
	cd libXss; make clean
	cd libXfixes; make clean
	cd libXcursor; make clean
install:
	mkdir -p $(DESTDIR)/$(LIBDIR)/pkgconfig $(DESTDIR)/$(INCDIR)
ifeq ($(STATIC),1)
	install -m 644 libX11.a $(DESTDIR)/$(LIBDIR)/libX11.a
endif
	cd libXau; make install
	cd libtinyX11; make install
	cd libICE; make install
	cd libSM; make install
	cd libXmu; make install
	cd libXt; make install
	cd libXv; make install
	cd libXext; make install
	cd libXinerama; make install
	cd libXrender; make install
	cd libXpm; make install
	cd libXtst; make install
	cd libXfont; make install
	cd libXdmcp; make install
	cd libXi; make install
	cd libXaw; make install
	cd libXmuu; make install
	cd libXss; make install
	cd libXfixes; make install
	cd libXcursor; make install
	cd util-macros; make install
	cd include; make install
