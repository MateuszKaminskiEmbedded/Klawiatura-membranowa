#ifndef _KEYPAD_H
#define _KEYPAD_H

#include <xc.h>

typedef unsigned char uchar_t;

void Keypad_Init(void);
uchar_t Keypad_ScanKey(void);

#endif /* _KEYPAD_H */