#ifndef _PIECE_H_INCLUDED_
#define _PIECE_H_INCLUDED_

#include <gb/gb.h>

typedef struct _Piece {
    UBYTE i, x, y, dx, dy;
} Piece;

void Piece_init(Piece* piece, UBYTE i, UBYTE x, UBYTE y, UBYTE dx, UBYTE dy);
void Piece_move(Piece* piece);

#endif
