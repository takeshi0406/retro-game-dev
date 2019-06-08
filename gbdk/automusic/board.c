#include "board.h"
#include "piece.h"


void Board_init(Board* board) {
    Piece_init(&(board->piece1), 0, 50, 50);
}

void Board_update(Board* board) {
    Piece_move(&(board->piece1), 1, 1);
}
