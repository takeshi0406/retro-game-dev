#include <gb/drawing.h>
#include "board.h"
#include "const.h"
#include "piece.h"
#include "sound.h"


void Board_init(Board* board) {
    UBYTE x1, y1;
    size_t i;
    for (i = 0; i < MAX_PIECES; i++) {
        Piece_init(&(board->pieces[i]), i, 8 - i, 0, 1);
    }

    for (x1 = X_MIN; x1 <= X_MAX; x1 += 16) {
        line(x1, Y_MIN, x1, Y_MAX);
    }

    for (y1 = Y_MIN; y1 <= Y_MAX; y1 += 16) {
        line(X_MIN, y1, X_MAX, y1);
    }
}


void Board_update(Board* board) {
    size_t i;
    for (i = 0; i < MAX_PIECES; i++) {
       Piece_move(&(board->pieces[i]));
    }
}

void Board_sound(Board* board) {
    size_t i;
    for (i = 0; i < MAX_PIECES; i++) {
        if (board->pieces[i].y + board->pieces[i].dy > 7) {
            sound1(board->pieces[i].x);
        };
    }
}
