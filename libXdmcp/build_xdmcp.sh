#!/bin/sh
#build libXdmcp 34K  
rm -f *.o libXdmcp.a

CC="/usr/i386-linux-uclibc/bin/i386-uclibc-gcc"

CFLAGS=" -pipe -Os -Wall -mtune=i386 -static -s -fno-exceptions"	

INCLUDE_DIRS=" -I../.. -I../../include "

LDFLAGS=" -Wl,--gc-sections "


DEFINES='-DNOERROR -L/usr/i386-linux-uclibc/lib -c -Dlinux -D__i386__ -D_POSIX_SOURCE -D_POSIX_C_SOURCE=2 -D_BSD_SOURCE -D_SVID_SOURCE -D_GNU_SOURCE -DX_LOCALE -DFUNCPROTO=15 -DNARROWPROTO'

for x in A8Eq.c AA8.c AA16.c AA32.c AofA8.c CA8.c DA8.c 	DA16.c DA32.c DAofA8.c Fill.c Flush.c RA8.c RA16.c RA32.c RAofA8.c RC8.c RC16.c RC32.c RHead.c RR.c RaA8.c RaA16.c RaA32.c RaAoA8.c WA8.c WA16.c WA32.c WAofA8.c WC8.c WC16.c WC32.c Whead.c Alloc.c CmpKey.c DecKey.c GenKey.c IncKey.c; do
	#echo ${CC} ${DEFINES} -c ${CFLAGS} ${INCLUDE_DIRS} $x
	${CC} ${DEFINES} -c ${CFLAGS} ${INCLUDE_DIRS} $x &
done
wait


ar clq libXdmcp.a A8Eq.o AA8.o AA16.o AA32.o AofA8.o CA8.o DA8.o 	DA16.o DA32.o DAofA8.o Fill.o Flush.o RA8.o RA16.o RA32.o RAofA8.o RC8.o RC16.o RC32.o RHead.o RR.o RaA8.o RaA16.o RaA32.o RaAoA8.o WA8.o WA16.o WA32.o WAofA8.o WC8.o WC16.o WC32.o Whead.o Alloc.o CmpKey.o DecKey.o GenKey.o IncKey.o 	

ranlib libXdmcp.a
rm -f ../../exports/lib/libXdmcp.a
cd ../../exports/lib && ln -s ../../lib/Xdmcp/libXdmcp.a .

exit

