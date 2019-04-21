#ifndef _SOUND_H_INCLUDED_
#define _SOUND_H_INCLUDED_

#include <gb/gb.h>

typedef struct _Sound {
    UBYTE i;
} Sound;

void Sound_init(Sound* sound);
void Sound_intro(Sound* sound);
void Sound_play(Sound* sound);
void beep(UWORD f);

#endif
