#include <gb/gb.h>
#include <gb/drawing.h>

int main(void) {
    char DOREMI[]={
        131, 131, 273, 273, 455, 455, 273, 0,
        201, 201, 180, 180, 150, 150, 131, 0
    };
    int i = 0;

    NR50_REG = 0xFF;
    NR51_REG = 0xFF;
    NR52_REG = 0x80;
    
    gotogxy(1, 1);
    gprintf("====== Beep ======");
    
    gotogxy(2, 3);
    gprintf("Press any button");


    
    while (1) {
        if (joypad()) {        

            NR11_REG = 0x70U;
            NR12_REG = 0xE0U;
            NR13_REG = 0x0BU;
            if (DOREMI[i]) NR14_REG = DOREMI[i] | 0x80;
            NR51_REG |= 0x0AU;
            delay(400);
            i++;
        }
    }
}
