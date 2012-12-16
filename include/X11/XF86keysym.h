/* $XFree86: xc/include/XF86keysym.h,v 1.12 2001/12/26 22:28:25 dawes Exp $ */

/*
 * XFree86 vendor specific keysyms.
 *
 * The XFree86 keysym range is 0x1008FF01 - 0x1008FFFF.
 *
 * When adding new entries, the xc/lib/XKeysymDB file should also be
 * updated to make the new entries visible to Xlib.
 */

/*
 * ModeLock
 *
 * This one is old, and not really used any more since XKB offers this
 * functionality.
 */

#define XF86XK_ModeLock		0x1008FF01	/* Mode Switch Lock */

/*
 * Note, 0x1008FF02 - 0x1008FF0F are free and should be used for misc new
 * keysyms that don't fit into any of the groups below.
 */


/*
 * Keys found on some "Internet" keyboards.
 */
#define XF86XK_Standby		0x1008FF10
#define XF86XK_AudioLowerVolume	0x1008FF11
#define XF86XK_AudioMute	0x1008FF12
#define XF86XK_AudioRaiseVolume	0x1008FF13
#define XF86XK_AudioPlay	0x1008FF14
#define XF86XK_AudioStop	0x1008FF15
#define XF86XK_AudioPrev	0x1008FF16
#define XF86XK_AudioNext	0x1008FF17
#define XF86XK_HomePage		0x1008FF18
#define XF86XK_Mail		0x1008FF19
#define XF86XK_Start		0x1008FF1A
#define XF86XK_Search		0x1008FF1B
#define XF86XK_AudioRecord	0x1008FF1C

/* These are sometimes found on PDA's (e.g. Palm, PocketPC or elsewhere) */
#define XF86XK_Calculator	0x1008FF1D
#define XF86XK_Memo		0x1008FF1E
#define XF86XK_ToDoList		0x1008FF1F
#define XF86XK_Calendar		0x1008FF20
#define XF86XK_PowerDown	0x1008FF21
#define XF86XK_ContrastAdjust	0x1008FF22
#define XF86XK_RockerUp		0x1008FF23
#define XF86XK_RockerDown	0x1008FF24
#define XF86XK_RockerEnter	0x1008FF25

/* Some more "Internet" keyboard symbols */
#define XF86XK_Back		0x1008FF26
#define XF86XK_Forward		0x1008FF27
#define XF86XK_Stop		0x1008FF28
#define XF86XK_Refresh		0x1008FF29
#define XF86XK_PowerOff		0x1008FF2A
#define XF86XK_WakeUp		0x1008FF2B
#define XF86XK_Eject            0x1008FF2C
#define XF86XK_ScreenSaver      0x1008FF2D
#define XF86XK_WWW              0x1008FF2E
#define XF86XK_Sleep            0x1008FF2F
#define XF86XK_Favorites	0x1008FF30
#define XF86XK_AudioPause	0x1008FF31
#define XF86XK_AudioMedia	0x1008FF32
#define XF86XK_MyComputer	0x1008FF33
#define XF86XK_VendorHome	0x1008FF34
#define XF86XK_LightBulb	0x1008FF35
#define XF86XK_Shop		0x1008FF36
#define XF86XK_History		0x1008FF37
#define XF86XK_OpenURL		0x1008FF38
#define XF86XK_AddFavorite	0x1008FF39
#define XF86XK_HotLinks		0x1008FF3A
#define XF86XK_BrightnessAdjust	0x1008FF3B
#define XF86XK_Finance		0x1008FF3C
#define XF86XK_Community	0x1008FF3D
/* Allocate 0x1008FF3E-F next */
#define XF86XK_Launch0		0x1008FF40
#define XF86XK_Launch1		0x1008FF41
#define XF86XK_Launch2		0x1008FF42
#define XF86XK_Launch3		0x1008FF43
#define XF86XK_Launch4		0x1008FF44
#define XF86XK_Launch5		0x1008FF45
#define XF86XK_Launch6		0x1008FF46
#define XF86XK_Launch7		0x1008FF47
#define XF86XK_Launch8		0x1008FF48
#define XF86XK_Launch9		0x1008FF49
#define XF86XK_LaunchA		0x1008FF4A
#define XF86XK_LaunchB		0x1008FF4B
#define XF86XK_LaunchC		0x1008FF4C
#define XF86XK_LaunchD		0x1008FF4D
#define XF86XK_LaunchE		0x1008FF4E
#define XF86XK_LaunchF		0x1008FF4F


