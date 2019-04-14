#include "Player.h"
#include <gb/gb.h>
#include <stdio.h>

unsigned char sprite[] = {
    0x5A,0x3C,0xE3,0x42,0x7C,0x99,0xEB,0xA5,
    0xFB,0xA5,0x66,0x99,0xE7,0x42,0x5A,0x3C
};

void Player_init(Player* player, UBYTE i, UBYTE x, UBYTE y) {
    // copyのため？
    player->i = i * 1;
    player->x = x * 1;
    player->y = y * 1;
    SPRITES_8x8;
    set_sprite_data(0, 0, sprite);
    set_sprite_tile(0, 0);
    move_sprite(player->i, player->x, player->y);
    SHOW_SPRITES;
}

void Player_move(Player* player, UBYTE joystate) {
    if (!joystate) {
        return;
    }

    if (joystate & J_RIGHT) player->x++;
    else if (joystate & J_LEFT) player->x--;

    if (joystate & J_UP) player->y--;
    else if (joystate & J_DOWN) player->y++;

    move_sprite(player->i, player->x, player->y);
    delay(10);
}


