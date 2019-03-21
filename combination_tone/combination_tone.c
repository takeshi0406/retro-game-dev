#include <gb/gb.h>
#include <gb/drawing.h>
#define DELAY 2000

void sound1(UWORD f);
void sound2(UWORD f);


void main() {
    NR52_REG = 0x80;
    NR50_REG = 0x77;
    NR51_REG = 0xFF;

    gotogxy(1, 1);
    gprintf("====== Beep ======");
    
    gotogxy(2, 3);
    gprintf("Press any button");

    while (1) {
        UBYTE joypad_state = joypad();
        
        if (joypad_state) {   
            sound1(550);
            sound2(450);
            delay(DELAY);
            break;
        }
    }
}

void sound1(UWORD f) {
    NR10_REG = 0x00; 
    NR11_REG = 0x80;
    NR12_REG = 0xF0;
    NR13_REG = (UBYTE)(f & 0x00FF);
    NR14_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
}

void sound2(UWORD f) {
    NR21_REG = 0x80;
    NR22_REG = 0xF0;
    NR23_REG = (UBYTE)(f & 0x00FF);
    NR24_REG = (UBYTE)((f >> 8) & 0x00FF) + 0x80;
}