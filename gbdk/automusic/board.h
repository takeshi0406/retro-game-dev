#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_

#include "piece.h"
#include "const.h"

typedef struct _Board {
    Piece pieces[MAX_PIECES];
    UBYTE dx;
    UBYTE dy;
} Board;

void Board_init(Board* board);
void Board_update(Board* board);
void Board_sound(Board* board);

#endif
