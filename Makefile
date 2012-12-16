all:	clean
	cd libXau; make; cd ..
	cd libtinyX11; make; cd ..
	cd libICE; make; cd ..
	cd libSM; make; cd ..
	cd libXmu; make; cd ..
	cd libXt; make; cd ..
	cd libXv; make; cd ..
	cd libXext; make; cd ..
	cd libXinerama; make; cd ..
	cd libXrender; make; cd ..
	cd libXpm; make; cd ..
	cd libXtst; make; cd ..
	cd libXfont; make; cd ..
	cd libXdmcp; make; cd ..
	cd libXi; make; cd ..
	cd libXaw; make; cd ..
clean:
	cd libtinyX11; make clean; cd ..
	cd libICE; make clean; cd ..
	cd libSM; make clean; cd ..
	cd libXmu; make clean; cd ..
	cd libXt; make clean; cd ..
	cd libXv; make clean; cd ..
	cd libXext; make clean; cd ..
	cd libXinerama; make clean; cd ..
	cd libXau; make clean; cd ..
	cd libXrender; make clean; cd ..
	cd libXpm; make clean; cd ..
	cd libXtst; make clean; cd ..
	cd libXfont; make clean; cd ..
	cd libXdmcp; make clean; cd ..
	cd libXi; make clean; cd ..
	cd libXaw; make clean; cd ..
install:	all
	cd libXau; make install; cd ..
	cd libtinyX11; make install; cd ..
	cd libICE; make install; cd ..
	cd libSM; make install; cd ..
	cd libXmu; make install; cd ..
	cd libXt; make install; cd ..
	cd libXv; make install; cd ..
	cd libXext; make install; cd ..
	cd libXinerama; make install; cd ..
	cd libXrender; make install; cd ..
	cd libXpm; make install; cd ..
	cd libXtst; make install; cd ..
	cd libXfont; make install; cd ..
	cd libXdmcp; make install; cd ..
	cd libXi; make install; cd ..
	cd libXaw; make install; cd ..
	cd include; make install; cd ..
tarball:	clean
	./make-tarball.sh

