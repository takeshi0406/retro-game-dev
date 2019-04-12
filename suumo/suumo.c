#include <gb/gb.h>
#include "Player.h"

void main() {
    Player player;
    Player_init(&player, 0, 55, 75);
    delay(1000);
    Player_move(&player);
    //for (;;) {
    //}
}
