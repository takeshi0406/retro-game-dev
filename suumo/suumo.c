#include <gb/gb.h>
#include "Player.h"
#include "stdio.h"

void test(Player* player) {
    printf("--- test\n");
    printf("player->i is %d.\n", player->i);
    printf("player->x is %d.\n", player->x);
    printf("player->y is %d.\n", player->y);
}

void main() {
    Player player;
    Player_init(&player, 0, 50, 75);
    printf("%d\n", player.x);
    delay(1000);
    test(&player);
    Player_move(&player);
}
