#include <gb/gb.h>
#include <stdio.h>

void main() {
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;


    while (1) {
        UBYTE joypad_state = joypad();
        UWORD freq;
        
        if (joypad_state) {   
            NR10_REG = 0x06; 
            NR11_REG = 0x40;
            NR12_REG = 0x73;
            freq = 2024;


            sound(freq);
            delay(400);
        }
    }
}

void sound(UWORD f) {
    // UWORD x = f;
    NR13_REG = (UBYTE)(f & 0x00FF);
    NR14_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
}
