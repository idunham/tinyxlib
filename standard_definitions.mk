
#compiler
#CC=/usr/bin/gcc
CC=/opt/musl/bin/musl-gcc

#compilerflags
COMPFLAGS=-pipe -Os -mtune=i386 -Wall -D_XOPEN_SOURCE=600 -D_BSD_SOURCE -D_GNU_SOURCE -fno-strength-reduce -nodefaultlibs -fno-strict-aliasing  -I. -ffunction-sections -fdata-sections

COMMONDEFS=$(COMPFLAGS) -D_BSD_SOURCE -D_GNU_SOURCE

LDFLAGS=-static -Wl,--gc-sections,--sort-common,-s

LINKDIR=-L/opt/musl/lib

LIBDIR=/opt/musl/lib

INCDIR=/opt/musl/include

PREDIR=/opt/musl


