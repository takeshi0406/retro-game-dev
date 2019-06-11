#include "piece.h"
#include "stdio.h"

const unsigned char sprite[] = {
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xF0, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF,
    0xF0, 0xFF, 0xFF, 0xFF
};

void Piece_init(Piece* piece, UBYTE i, UBYTE x, UBYTE y) {
    piece->i = i * 1;
    piece->x = x * 1;
    piece->y = y * 1;
    SPRITES_8x16;
    set_sprite_data(piece->i, 0, sprite);
    set_sprite_tile(piece->i, 0);
    move_sprite(piece->i, piece->x, piece->y);

    set_sprite_data(piece->i + 1, 1, sprite);
    set_sprite_tile(piece->i + 1, 1);
    move_sprite(piece->i + 1, piece->x + 8, piece->y);
    SHOW_SPRITES;
}

void Piece_move(Piece* piece, UBYTE dx, UBYTE dy) {
    piece->x += dx;
    piece->y += dy;
    move_sprite(piece->i, piece->x, piece->y);
    move_sprite(piece->i + 1, piece->x + 8, piece->y);
}
