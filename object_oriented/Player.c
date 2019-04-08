#include "Player.h"
#include <gb/gb.h>
#include <gb/drawing.h>

#define RADIUS 2

void Player_Init(Player *player, UBYTE x, UBYTE y) {
    player->x = x;
    player->y = y;
}

void Player_Draw(Player *player) {
    color(BLACK, WHITE, SOLID);
    circle(player->x * 8 + 4, player->y * 8 + 4, RADIUS, M_FILL);
}
