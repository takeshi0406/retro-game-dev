#include <gb/gb.h>
#include "Player.h"
#include "Sound.h"
#include "stdio.h"


int main(void) {
    Player player;
    Sound sound;
    Player_init(&player, 0, 50, 75);
    Sound_init(&sound);
    for (;;) {
        Player_move(&player, joypad());
        Sound_play(&sound);
    }
}
