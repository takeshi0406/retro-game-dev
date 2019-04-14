#include "Sound.h"
#include <gb/gb.h>

static const UWORD score[] = {
    1024, 1024, 1379, 1379
};


void Sound_init(Sound* sound) {
    sound->i = 0;
    // initial register
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
}


void Sound_play(Sound* sound) {
    beep(score[sound->i]);
    if (sound->i < 4) {
        sound->i++;
    } else {
        sound->i = 0;
    }
}


// 周波数を受け取って音を鳴らす関数
void beep(UWORD f) {
    NR10_REG = 0x06; 
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = (UBYTE)(f & 0x00FF);
    NR14_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
}
