#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_

#include "piece.h"

typedef struct _Board {
    Piece piece1;
    UBYTE t;
} Board;

void Board_init(Board* board);
void Board_update(Board* board);

#endif
