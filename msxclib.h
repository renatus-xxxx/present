#ifndef __MSXCLIB_H__
#define __MSXCLIB_H__

/* From "Introduction to MSX-C" */
/* ISBN: 4-7561-0057-0          */
#include <msxalib.h>

void screen(int md);
void color(int fg, int bg, int bd);
char snsmat(int mt);

#endif /* __MSXCLIB_H__ */
