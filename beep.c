#include <gb/gb.h>
#include <stdio.h>
#define DELAY 400

void sound(UWORD f);

void main() {
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;


    while (1) {
        UBYTE joypad_state = joypad();
        
        if (joypad_state) {   
            NR10_REG = 0x06; 
            NR11_REG = 0x40;
            NR12_REG = 0x73;
            sound(1024);
            sound(1024);
            sound(1379);
            sound(1379);
            sound(1452);
            sound(1452);
            sound(1379);
            delay(DELAY);
            sound(1297);
            sound(1297);
            sound(1253);
            sound(1253);
            sound(1155);
            sound(1155);
            sound(1024);
            delay(DELAY);
        }
    }
}

void sound(UWORD f) {
    NR13_REG = (UBYTE)(f & 0x00FF);
    NR14_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
    delay(DELAY);
}
