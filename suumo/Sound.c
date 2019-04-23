#include "Sound.h"
#include <gb/gb.h>

static const UWORD score1[] = {
    1379, 1379, 1452, 1452,
    1339, 1339, 1452, 1452,
    1517, 1452, 1379, 1339,
    1339, 1379, 1452, 0,
    1379, 1379, 1452, 1452,
    1339, 1339, 1452, 1452,
    1517, 1452, 1379, 1339,
    1339, 1297, 1339, 0
};
static const UWORD score2[] = {
    1253,    0,  854,    0,
    1155,    0,  854,    0,
    1253,    0,  854,    0,
    1155, 1102, 1046, 1155,
    1253,    0,  854,    0,
    1155,    0,  854,    0,
    1253,    0,  854,    0,
    1102,    0, 1102, 1155,
};


void Sound_init(Sound* sound) {
    sound->i = 0;
    // initial register
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;
}

void Sound_intro() {
    NR41_REG = 0x1F;
    NR42_REG = 0xF1;
    NR43_REG = 0x35;
    NR44_REG = 0xC0;
    delay(500);
    NR41_REG = 0x1F;
    NR42_REG = 0xF1;
    NR43_REG = 0x35;
    NR44_REG = 0xC0;
    delay(500);
    NR41_REG = 0x1F;
    NR42_REG = 0xF1;
    NR43_REG = 0x35;
    NR44_REG = 0xC0;
    delay(500);
    NR41_REG = 0x07;
    NR42_REG = 0xC5;
    NR43_REG = 0x40;
    NR44_REG = 0xF0;
    delay(240);
}


void Sound_play(Sound* sound) {
    if (score1[sound->i]) {
        beep1(score1[sound->i]);
    }
    if (score2[sound->i]) {
        beep2(score2[sound->i]);
    }
    sound->i++;

    if (sound->i > 31) {
        sound->i = 0;
    }
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
