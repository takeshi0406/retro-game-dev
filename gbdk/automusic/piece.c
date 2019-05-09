#include "piece.h"
#include "stdio.h"

const unsigned char sprite[] = {
    0xFF, 0xFF, 0xFF, 0xFF,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x1F, 0x00, 0x3F,
    0x00, 0x7F, 0x00, 0x77
};

void Piece_init(Piece* piece, UBYTE i, UBYTE x, UBYTE y) {
    piece->i = i * 1;
    piece->x = x * 1;
    piece->y = y * 1;
    SPRITES_8x8;
    set_sprite_data(piece->i, 0, sprite);
    set_sprite_tile(piece->i, 0);
    move_sprite(piece->i, piece->x, piece->y);
    SHOW_SPRITES;
}

void Piece_move(Piece* piece, UBYTE dx, UBYTE dy) {
    piece->x += dx;
    piece->y += dy;
    move_sprite(piece->i, piece->x, piece->y);
}
