#include "Player.h"
#include <gb/gb.h>
#include <stdio.h>

const unsigned char sprite[] = {
    0xF1, 0xFF, 0x0F, 0x0F,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0xFF, 0xFF, 0x00, 0x0C
};

void Player_init(Player* player, UBYTE i, UBYTE x, UBYTE y) {
    // copyのため？
    player->i = i * 1;
    player->x = x * 1;
    player->y = y * 1;
    SPRITES_8x16;
    set_sprite_data(player->i, 0, sprite);
    set_sprite_data(player->i + 2, 0, sprite);
    set_sprite_prop(player->i + 2, S_FLIPX);
    set_sprite_tile(player->i, 0);
    set_sprite_tile(player->i + 2, 0);
    move_sprite(player->i, player->x, player->y);
    move_sprite(player->i + 2, player->x + 7, player->y);
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
    move_sprite(player->i + 2, player->x + 7, player->y);
    delay(10);
}
