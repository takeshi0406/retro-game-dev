#include "Player.h"
#include <gb/gb.h>
#include <gb/drawing.h>

#define RADIUS 2
#define X_MIN 4
#define X_MAX 156
#define Y_MIN 4
#define Y_MAX 140
#define X_NODES (X_MAX - X_MIN) / 8 + 1
#define Y_NODES (Y_MAX - Y_MIN) / 8 + 1


void Player_Init(Player *player, UBYTE x, UBYTE y) {
    player->x = x * 8 + 4;
    player->y = y * 8 + 4;
    color(BLACK, WHITE, SOLID);
    circle(player->x, player->y, RADIUS, M_FILL);
}

void Player_Move(Player *player, UBYTE dx, UBYTE dy) {
    UBYTE u_x = player->x + (dx * 8);
    UBYTE u_y = player->y + (dy * 8);
    color(WHITE, WHITE, SOLID);
    circle(player->x, player->y, RADIUS, M_FILL);
    if (X_MIN < u_x && u_x < X_MAX) {
        player->x = u_x;
    }
    if (Y_MIN < u_y && u_y < Y_MAX) {
        player->y = u_y;
    }
    color(BLACK, WHITE, SOLID);
    circle(player->x, player->y, RADIUS, M_FILL);
}
