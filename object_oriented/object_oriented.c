#include "Player.h"
#include <gb/gb.h>
#include <rand.h>

int main(void) {
    Player player;
    Player_Init(&player, 1, 2);
    while (1) {
        Player_Move(&player, 1, 1);
        delay(100);
    }
}
