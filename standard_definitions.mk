
#compiler
CC=/usr/bin/gcc
#CC=/opt/musl/bin/musl-gcc

#compilerflags
COMPFLAGS=-pipe -Os -mtune=i386 -Wall -D_XOPEN_SOURCE=600 -D_BSD_SOURCE -D_GNU_SOURCE -D_DEFAULT_SOURCE -fno-strength-reduce -nodefaultlibs -fno-strict-aliasing  -I. -ffunction-sections -fdata-sections

COMMONDEFS=$(COMPFLAGS) -D_BSD_SOURCE -D_GNU_SOURCE -D_DEFAULT_SOURCE -DUSECMS

LDFLAGS=-Wl,--gc-sections,--sort-common,-s

#LINKDIR=-L/opt/musl/lib
LINKDIR=-L/usr/lib

#PREDIR=/opt/musl
PREDIR=/usr

LIBDIR=${PREDIR}/lib

INCDIR=${PREDIR}/include

#If you do not have setlocale, set this:
#COMMONDEFS+= -DX_LOCALE -DXLOCALEDIR=\"/usr/share/locale\" 
#KEYSYMDB=/usr/X11R7/lib/X11/XKeysymDB
KEYSYMDB=${PREDIR}/share/X11/XKeysymDB
