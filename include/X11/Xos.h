/*
 * $Xorg: Xos.h,v 1.6 2001/02/09 02:03:22 xorgcvs Exp $
 * 
 * 
Copyright 1987, 1998  The Open Group

Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation.

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
OPEN GROUP BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN
AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

Except as contained in this notice, the name of The Open Group shall not be
used in advertising or otherwise to promote the sale, use or other dealings
in this Software without prior written authorization from The Open Group.
 *
 * The X Window System is a Trademark of The Open Group.
 *
 */
/* $XFree86: xc/include/Xos.h,v 3.36 2001/12/14 19:53:26 dawes Exp $ */

/* This is a collection of things to try and minimize system dependencies
 * in a "signficant" number of source files.
 */

#ifndef _XOS_H_
#define _XOS_H_

#include "Xosdefs.h"

/*
 * Get major data types (esp. caddr_t)
 */

#include <sys/types.h>


/*
 * Just about everyone needs the strings routines.  We provide both forms here,
 * index/rindex and strchr/strrchr, so any systems that don't provide them all
 * need to have #defines here.
 *
 * These macros are defined this way, rather than, e.g.:
 *    #defined index(s,c) strchr(s,c)
 * because someone might be using them as function pointers, and such
 * a change would break compatibility for anyone who's relying on them
 * being the way they currently are. So we're stuck with them this way,
 * which can be really inconvenient. :-(
 */


#include <string.h>
#ifndef index
#define index(s,c) (strchr((s),(c)))
#endif
#ifndef rindex
#define rindex(s,c) (strrchr((s),(c)))
#endif


/*
 * strerror()
 */

/*
 * Get open(2) constants
 */
#if defined(X_NOT_POSIX)
#include <fcntl.h>
#if defined(USL) || defined(CRAY) || defined(MOTOROLA) || (defined(i386) && (defined(SYSV) || defined(SVR4))) || defined(__sxg__)
#include <unistd.h>
#endif
#include <sys/file.h>
#else /* X_NOT_POSIX */
#include <fcntl.h>
#include <unistd.h>
#endif /* X_NOT_POSIX else */

#ifdef CSRG_BASED
#include <stdlib.h>
#include <unistd.h>
#endif /* CSRG_BASED */

/*
 * Get struct timeval and struct tm
 */


#if   defined(_SEQUENT_) || defined(Lynx)
#include <time.h>
#else
#include <sys/time.h>
#include <time.h>
#endif /* defined(_POSIX_SOURCE) && defined(SVR4) */


/* define X_GETTIMEOFDAY macro, a portable gettimeofday() */
#if defined(_XOPEN_XPG4) || defined(_XOPEN_UNIX) /* _XOPEN_UNIX is XPG4.2 */
#define X_GETTIMEOFDAY(t) gettimeofday(t, (struct timezone*)0)
#else
#if defined(SVR4) || defined(VMS) || defined(WIN32)
#define X_GETTIMEOFDAY(t) gettimeofday(t)
#else
#define X_GETTIMEOFDAY(t) gettimeofday(t, (struct timezone*)0)
#endif
#endif /* XPG4 else */

#ifdef __EMX__
typedef unsigned long fd_mask;
#include <limits.h>
#define MAX_PATH _POSIX_PATH_MAX
#endif

#ifdef __GNU__
#define PATH_MAX 4096
#define MAXPATHLEN 4096
#define OPEN_MAX 256 /* We define a reasonable limit.  */
#endif

/* use POSIX name for signal */

#ifdef ISC
#include <sys/bsdtypes.h>
#include <sys/limits.h>
#define NGROUPS 16
#endif

#if defined(ISC) || \
    (defined(linux) && !defined(__GLIBC__)) || \
    (defined(__QNX__) && !defined(UNIXCONN))
/*
 *	Some OS's may not have this
 */

#define X_NO_SYS_UN 1

struct sockaddr_un {
	short	sun_family;
	char	sun_path[108];
};
#endif

#include "Xarch.h"

#endif /* _XOS_H_ */
