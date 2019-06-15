#include "sound.h"
#include <gb/gb.h>

const UWORD SOUND_SCORE[8] = {
    587, 880, 932, 1046, 1145, 1319, 1397, 1760
};


void sound1(UWORD i) {
    beep1(SOUND_SCORE[i]);
}


// 周波数を受け取って音を鳴らす関数
void beep1(UWORD f) {
    NR10_REG = 0x06; 
    NR11_REG = 0x40;
    NR12_REG = 0x73;
    NR13_REG = (UBYTE)(f & 0x00FF);
    NR14_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
}

void beep2(UWORD f) {
    NR21_REG = 0x40;
    NR22_REG = 0x73;
    NR23_REG = (UBYTE)(f & 0x00FF);
    NR24_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
}

void Sound_init(void) {
    // initial register
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
}
