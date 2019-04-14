#include <gb/gb.h>
#include "Player.h"
#include "Sound.h"
#include "stdio.h"


Sound sound;
void update_music(void) {
    //printf("test");
    beep(1000);
    //Sound_play(&sound);
}

int main(void) {
    Player player;
    Player_init(&player, 0, 50, 75);
    Sound_init(&sound);

    // 初期化
    disable_interrupts();
    add_TIM(update_music);
    set_interrupts(TIM_IFLAG);
    enable_interrupts();

    for (;;) {
        Player_move(&player, joypad());
    }
}



