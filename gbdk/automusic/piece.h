#ifndef _PIECE_H_INCLUDED_
#define _PIECE_H_INCLUDED_

#include <gb/gb.h>

typedef struct _Piece {
    UBYTE i, x, y;
} Piece;

void Piece_init(Piece* piece, UBYTE i, UBYTE x, UBYTE y);
void Piece_move(Piece* piece, UBYTE dx, UBYTE dy);

#endif
