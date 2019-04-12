#include "Player.h"
#include <gb/gb.h>
#include <stdio.h>

unsigned char sprite[] = {
    0x5A,0x3C,0xE3,0x42,0x7C,0x99,0xEB,0xA5,
    0xFB,0xA5,0x66,0x99,0xE7,0x42,0x5A,0x3C
};

void Player_init(Player* player, UBYTE i, UBYTE x, UBYTE y) {
    player->i = i;
    player->x = x;
    player->y = y;
    printf("%d,", x);
    printf("%d,", player->x);
    /*
    SPRITES_8x8;
    set_sprite_data(0, 0, sprite);
    set_sprite_tile(0, 0);
    // move_sprite(player->i, player->x, player->y);
    */
    printf("%d,", player->x);
    // SHOW_SPRITES;
}

void Player_move(Player* player) {
    // player->x++;
    /*
    if (joystate & J_RIGHT) player->x++;
    else if (joystate & J_LEFT) player->x--;

    if (joystate & J_UP) player->y++;
    else if (joystate & J_DOWN) player->y--;
    */
    printf("%d,", player->i);
    printf("%d,", player->x);
    printf("%d,", player->y);

    move_sprite(0, 55, 70);
    //delay(10);
}


