#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_
#include <gb/gb.h>


typedef struct _Player {
    UBYTE x, y;
} Player;

void Player_Init(Player * player, UBYTE x, UBYTE y);
void Player_Draw(Player * player);


#endif
