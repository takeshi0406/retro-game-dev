#include <gb/drawing.h>
#include "board.h"
#include "const.h"
#include "piece.h"
#include "sound.h"


void Board_init(Board* board) {
    UBYTE x1, y1;
    Piece_init(&(board->piece1), 0, 0, 0, 1);
    Piece_init(&(board->piece2), 1, 1, 0, 1);
    Piece_init(&(board->piece3), 2, 2, 0, 1);
    Piece_init(&(board->piece4), 3, 3, 0, 1);

    for (x1 = X_MIN; x1 <= X_MAX; x1 += 16) {
        line(x1, Y_MIN, x1, Y_MAX);
    }

    for (y1 = Y_MIN; y1 <= Y_MAX; y1 += 16) {
        line(X_MIN, y1, X_MAX, y1);
    }
}


void Board_update(Board* board) {
    Piece_move(&(board->piece1));
    Piece_move(&(board->piece2));
    Piece_move(&(board->piece3));
    Piece_move(&(board->piece4));
}

void Board_sound(Board* board) {
    if ((&(board->piece1))->y < 1) {
        beep1(1379);
    };
}
