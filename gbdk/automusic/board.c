#include "board.h"
#include "piece.h"


void Board_init(Board* board) {
    Piece_init(&(board->piece1), 0, 20, 20);
}

void Board_update(Board* board) {
    // Piece_move(&(board->piece1), 16, 16);
}
