#include "Player.h"
#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>


int main(void) {
    Player player;
    UBYTE dx, dy;
    Player_Init(&player, 5, 5);
    while (1) {
        dx = rand() % 3;
        dy = rand() % 3;
        Player_Move(&player, dx, dy);
        delay(10);
    }
}
