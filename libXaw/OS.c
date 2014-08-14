/* $XFree86: xc/lib/Xaw/OS.c,v 1.2 1998/12/06 11:24:32 dawes Exp $ */

/* Some OS-dependent utility code */

#include <X11/Xosdefs.h>
#include <X11/Xt/IntrinsicP.h>
#include "Private.h"

#include <unistd.h>	/* for sysconf(), and getpagesize() */

#if defined(linux)
//#include <asm/page.h>	/* for PAGE_SIZE */
#include <limits.h>
#define HAS_GETPAGESIZE
#define HAS_SC_PAGESIZE	/* _SC_PAGESIZE may be an enum for Linux */
#endif

#if defined(CSRG_BASED)
#define HAS_GETPAGESIZE
#endif


int
_XawGetPageSize()
{
    static int pagesize = -1;

    if (pagesize != -1)
	return pagesize;

    /* Try each supported method in the preferred order */

#if defined(_SC_PAGESIZE) || defined(HAS_SC_PAGESIZE)
    pagesize = sysconf(_SC_PAGESIZE);
#endif

#ifdef _SC_PAGE_SIZE
    if (pagesize == -1)
	pagesize = sysconf(_SC_PAGE_SIZE);
#endif

#ifdef HAS_GETPAGESIZE
    if (pagesize == -1)
	pagesize = getpagesize();
#endif

#ifdef PAGE_SIZE
    if (pagesize == -1)
	pagesize = PAGE_SIZE;
#endif

    if (pagesize == -1)
	pagesize = 0;

    return pagesize;
}
