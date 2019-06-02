#include <gb/gb.h>
#include <stdio.h>
#include <piece.h>
#include <sound.h>


int main(void) {
    Piece piece[2];
    Piece_init(&piece[0], 0, 50, 50);
    Piece_init(&piece[1], 1, 55, 55);
    for (;;) {
        Piece_move(&piece[0], 1, 0);
        Piece_move(&piece[1], 1, 0);
        delay(100);
        Piece_move(&piece[0], -1, 0);
        Piece_move(&piece[1], -1, 0);
        delay(100);
    }
}
