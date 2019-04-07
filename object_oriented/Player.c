#include "Player.h"
#include <gb/drawing.h>


void Player_Init(Player * player, UBYTE x, UBYTE, y) {
    player->x = x;
    player->y = y;
};

void Player_Draw(Player * player) {
    color(BLACK, WHITE, SOLID);
    circle(i * 8 + 4, j * 8 + 4, RADIUS, M_FILL);
};