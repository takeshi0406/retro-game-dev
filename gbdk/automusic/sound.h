#ifndef _SOUND_H_INCLUDED_
#define _SOUND_H_INCLUDED_

#include <gb/gb.h>

typedef struct _Sound {
    UBYTE i;
} Sound;

void Sound_init(Sound* sound);
void Sound_play(Sound* sound);
void beep1(UWORD f);
void beep2(UWORD f);

#endif
