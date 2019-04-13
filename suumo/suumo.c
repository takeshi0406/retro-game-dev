#include <gb/gb.h>
#include "Player.h"
#include "stdio.h"


void main() {
    Player player;
    Player_init(&player, 0, 50, 75);
    for (;;) {
        Player_move(&player, joypad());
    }
}
