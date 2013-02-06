#!/bin/sh
#find duplicates of files named the same

#set a filter for know duplicates we need
FILTER="Makefile CrCmap.c RdBitF.c README sharedlib.c SaveSet.c misc.c Pixmap.c CHANGES Object.h.redundant TextP.h.redundant jump_vars List.c Text.c RectObj.h.redundant jump_funcs Text.h.redundant Tree.c parse.c Image.c Xlib.h Shell.h keysym.h X.h Xauth.h StringDefs.h.deactivated Xdmcp.h Sync.c Misc.c Text16.c Bell.c NextEvent.c Flush.c Display.c Create.c Wrap.c
"

find -type f | grep -v .*\.o > names.lst
#cat names.lst | grep -v .*\.o > names.lst

while read name; do
    bn="$( basename "$name" )"
    name2="$( grep "$bn"$ names.lst | grep -v "$name" )"
    if [ ! "$name2" = "" ]; then
    	
    	if [ "$(echo $FILTER | grep "$bn")" = "" ]; then 
    	echo "found duplicate"
		echo "$name"
		echo
		echo "$name2"
		
		# lets remove the name2 from names.lst to avoid refinding NOTWORKING
		#for X in $(echo $name2); do
		#echo dada ${X}
		#	grep -v "${X}" names.lst > names2.lst
		#done
		exit
		fi
    fi
done < names.lst