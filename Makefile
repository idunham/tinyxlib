all:	clean
	make -C libXau
	make -C libtinyX11
	make -C libICE
	make -C libSM
	make -C libXmu
	make -C libXt
	make -C libXv
	make -C libXext
	make -C libXinerama
	make -C libXrender
	make -C libXpm
	make -C libXtst
	make -C libXfont
	make -C libXdmcp
	make -C libXi
	make -C libXaw
clean:
	make clean -C libtinyX11
	make clean -C libICE
	make clean -C libSM
	make clean -C libXmu
	make clean -C libXt
	make clean -C libXv
	make clean -C libXext
	make clean -C libXinerama
	make clean -C libXau
	make clean -C libXrender
	make clean -C libXpm
	make clean -C libXtst
	make clean -C libXfont
	make clean -C libXdmcp
	make clean -C libXi
	make clean -C libXaw
install:	all
	make install -C libXau
	make install -C libtinyX11
	make install -C libICE
	make install -C libSM
	make install -C libXmu
	make install -C libXt
	make install -C libXv
	make install -C libXext
	make install -C libXinerama
	make install -C libXrender
	make install -C libXpm
	make install -C libXtst
	make install -C libXfont
	make install -C libXdmcp
	make install -C libXi
	make install -C libXaw
	cd include; make install; cd ..
tarball:	clean
	./make-tarball.sh

