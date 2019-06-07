#include "board.h"
#include "piece.h"


void Board_init(Board* board) {
    Piece_init(&(board->piece1));
}
