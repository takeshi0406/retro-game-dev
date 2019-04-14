#include <gb/gb.h>
#include "Player.h"
#include "Sound.h"
#include "stdio.h"


Sound sound;
UWORD count = 0;
void update_music(void) {
    Sound_play(&sound);
}

int main(void) {
    Player player;
    Player_init(&player, 0, 50, 75);
    Sound_init(&sound);

    disable_interrupts();
    add_TIM(update_music);
    enable_interrupts();
    TMA_REG = 0x00U;
    /* Set clock to 4096 Hertz */
    TAC_REG = 0x04U;
    set_interrupts(VBL_IFLAG | TIM_IFLAG);

    for (;;) {
        Player_move(&player, joypad());
    }
}



