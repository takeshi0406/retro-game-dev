#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_

#include "piece.h"

typedef struct _Board {
    Piece piece1;
    Piece piece2;
    UBYTE dx;
    UBYTE dy;
} Board;

void Board_init(Board* board);
void Board_update(Board* board);

#endif
