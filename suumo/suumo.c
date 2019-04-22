#include <gb/gb.h>
#include "Player.h"
#include "Sound.h"
#include "stdio.h"


Sound sound;
UWORD count;
void update_music(void);
void init_interrupts(void);


int main(void) {
    Player player;
    Player_init(&player, 0, 50, 75);

    Sound_init(&sound);
    Sound_intro(&sound);
    init_interrupts();


    for (;;) {
        Player_move(&player, joypad());
    }
}


void init_interrupts(void) {
    disable_interrupts();
    add_TIM(update_music);
    enable_interrupts();
    TMA_REG = 0x00U;
    /* Set clock to 4096 Hertz */
    TAC_REG = 0x04U;
    set_interrupts(VBL_IFLAG | TIM_IFLAG);
}


void update_music(void) {
    count++;
    if (count > 0x03U) {
        Sound_play(&sound);
        count = 0;
    }
}
