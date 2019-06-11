#include <gb/drawing.h>
#include "board.h"
#include "piece.h"

#define X_MIN 16
#define X_MAX 144
#define X_NODES (X_MAX - X_MIN) / 16 + 1
#define Y_MIN 8
#define Y_MAX 136
#define Y_NODES (Y_MAX - Y_MIN) / 16 + 1

void Board_init(Board* board) {
    UBYTE x1, y1;
    Piece_init(&(board->piece1), 0, X_MIN + 8, Y_MIN + 16);

    for (x1 = X_MIN; x1 <= X_MAX; x1 += 16) {
        line(x1, Y_MIN, x1, Y_MAX);
        delay(16);
    }

    for (y1 = Y_MIN; y1 <= Y_MAX; y1 += 16) {
        line(X_MIN, y1, X_MAX, y1);
        delay(16);
    }
}

void Board_update(Board* board) {
    Piece_move(&(board->piece1), 16, 16);
}
