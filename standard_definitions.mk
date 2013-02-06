
#compiler
CC=/usr/bin/gcc

#compilerflags
COMPFLAGS=-pipe -Os -mtune=i386 -Wall -D_BSD_SOURCE -D_GNU_SOURCE -fno-strength-reduce -nodefaultlibs -fno-strict-aliasing  -I. -ffunction-sections -fdata-sections

COMMONDEFS=$(COMPFLAGS) -D_BSD_SOURCE -D_GNU_SOURCE

LDFLAGS=-static -Wl,--gc-sections,--sort-common,-s

LINKDIR=-L/usr/lib

LIBDIR=/usr/lib

INCDIR=/usr/include

PREDIR=/usr


