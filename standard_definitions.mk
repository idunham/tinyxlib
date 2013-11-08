
#compiler
CC=/mnt/sda6/Stuff/git/lazyux/sysroot/bin/musl-gcc

#compilerflags
COMPFLAGS=-pipe -fPIC -Os -Wall -D_XOPEN_SOURCE=600 -D_BSD_SOURCE -D_GNU_SOURCE -fno-strength-reduce -nodefaultlibs -fno-strict-aliasing  -I. -ffunction-sections -fdata-sections

COMMONDEFS=$(COMPFLAGS) -D_BSD_SOURCE -D_GNU_SOURCE

LDFLAGS=-Wl,--gc-sections,--sort-common,-s

LINKDIR=-L/mnt/sda6/Stuff/git/lazyux/sysroot/lib

LIBDIR=/mnt/sda6/Stuff/git/lazyux/sysroot/lib

INCDIR=/mnt/sda6/Stuff/git/lazyux/sysroot/usr/include

PREDIR=/mnt/sda6/Stuff/git/lazyux/sysroot/lib