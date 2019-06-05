#ifndef _BOARD_H_INCLUDED_
#define _BOARD_H_INCLUDED_

#include "piece.h"

typedef struct _Board {
    Piece piece1;
} Board;

void Board_init(Board* board);

#endif
