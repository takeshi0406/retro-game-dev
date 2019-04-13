#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_

#include <gb/gb.h>
#define ufoBank 0

typedef struct _Player {
    UBYTE i, x, y;
} Player;

void Player_init(Player* player, UBYTE i, UBYTE x, UBYTE y);
void Player_move(Player* player, UBYTE joystate);

#endif
