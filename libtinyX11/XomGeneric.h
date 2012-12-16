/* $XConsortium: XomGeneric.h,v 1.2 94/01/20 18:03:32 rws Exp $ */
/*
 * Copyright 1992, 1993 by TOSHIBA Corp.
 *
 * Permission to use, copy, modify, and distribute this software and its
 * documentation for any purpose and without fee is hereby granted, provided
 * that the above copyright notice appear in all copies and that both that
 * copyright notice and this permission notice appear in supporting
 * documentation, and that the name of TOSHIBA not be used in advertising
 * or publicity pertaining to distribution of the software without specific,
 * written prior permission. TOSHIBA make no representations about the
 * suitability of this software for any purpose.  It is provided "as is"
 * without express or implied warranty.
 *
 * TOSHIBA DISCLAIM ALL WARRANTIES WITH REGARD TO THIS SOFTWARE, INCLUDING
 * ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO EVENT SHALL
 * TOSHIBA BE LIABLE FOR ANY SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES OR
 * ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
 * WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION,
 * ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS
 * SOFTWARE.
 *
 * Author: Katsuhisa Yano	TOSHIBA Corp.
 *			   	mopi@osa.ilab.toshiba.co.jp
 */

#ifndef _XOMGENERIC_H_
#define _XOMGENERIC_H_

#include "XlcPublic.h"

#define XOM_GENERIC(om)		(&((XOMGeneric) om)->gen)
#define XOC_GENERIC(font_set)	(&((XOCGeneric) font_set)->gen)

typedef enum {
    XOMMultiByte,
    XOMWideChar
} XOMTextType;

typedef struct _FontDataRec {
    char *name;
    XlcSide side;
} FontDataRec, *FontData;

typedef struct _OMDataRec {
    int charset_count;
    XlcCharSet *charset_list;
    int font_data_count;
    FontData font_data;
} OMDataRec, *OMData;

typedef struct _XOMGenericPart {
    int data_num;
    OMData data;
    Bool on_demand_loading;
    char *object_name;
} XOMGenericPart;

typedef struct _XOMGenericRec {
    XOMMethods methods;
    XOMCoreRec core;
    XOMGenericPart gen;
} XOMGenericRec, *XOMGeneric;

/*
 * XOC dependent data
 */

typedef struct _FontSetRec {
    int id;
    int charset_count;
    XlcCharSet *charset_list;
    int font_data_count;
    FontData font_data;
    char *font_name;
    XFontStruct *info;
    XFontStruct *font;
    XlcSide side;
    Bool is_xchar2b;
} FontSetRec, *FontSet;

typedef struct _XOCGenericPart {
    XlcConv mbs_to_cs;
    XlcConv wcs_to_cs;
    int font_set_num;
    FontSet font_set;
} XOCGenericPart;

typedef struct _XOCGenericRec {
    XOCMethods methods;
    XOCCoreRec core;	
    XOCGenericPart gen;
} XOCGenericRec, *XOCGeneric;

_XFUNCPROTOBEGIN

extern XOM _XomGenericOpenOM(
#if NeedFunctionPrototypes
    XLCd		/* lcd */,
    Display*		/* dpy */,
    XrmDatabase		/* rdb */,
    _Xconst char*	/* res_name */,
    _Xconst char*	/* res_class */
#endif
);

extern XlcConv _XomInitConverter(
#if NeedFunctionPrototypes
    XOC			/* oc */,
    XOMTextType		/* type */
#endif
);

extern int _XomConvert(
#if NeedFunctionPrototypes
    XOC			/* oc */,
    XlcConv		/* conv */,
    XPointer*		/* from */,
    int*		/* from_left */,
    XPointer*		/* to */,
    int*		/* to_left */,
    XPointer*		/* args */,
    int			/* num_args */
#endif
);

_XFUNCPROTOEND

#endif  /* _XOMGENERIC_H_ */
