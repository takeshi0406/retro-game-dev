#include <gb/drawing.h>
#include "board.h"
#include "const.h"
#include "piece.h"


void Board_init(Board* board) {
    UBYTE x1, y1;
    Piece_init(&(board->piece1), 0, 0, 0, -1);
    Piece_init(&(board->piece2), 1, 1, 0, -1);

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
}
