#ifndef _PLAYER_H_INCLUDED_
#define _PLAYER_H_INCLUDED_
#include <gb/gb.h>

typedef struct _Player {
    UBYTE x, y;
} Player;

void Player_Init(const Player *player, const UBYTE x, const UBYTE y);
void Player_Move(const Player *player, const UBYTE dx, const UBYTE dy);

#endif
