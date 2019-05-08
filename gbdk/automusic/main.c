#include <gb/gb.h>
#include <stdio.h>
#include <piece.h>


int main(void) {
    Piece piece[2];
    Piece_init(&piece[0], 0, 50, 50);
    Piece_init(&piece[1], 1, 55, 55);
    for (;;) {
        Piece_move(&piece, 1, 1);
        delay(100);
    }
}
