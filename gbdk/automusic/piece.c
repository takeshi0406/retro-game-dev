#include "piece.h"
#include "const.h"
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


void Piece_init(Piece* piece, UBYTE i, UBYTE x, UBYTE y, UBYTE dx, UBYTE dy) {
    piece->i = i * 1;
    piece->x = x;
    piece->y = y;
    piece->dx = dx * 1;
    piece->dy = dy * 1;

    SPRITES_8x16;
    set_sprite_data(piece->i, 0, sprite);
    set_sprite_tile(piece->i, 0);
    move_sprite(piece->i, piece->x * PIECE_SIZE + 24, piece->y * PIECE_SIZE + 24);

    set_sprite_data(piece->i + 1, 1, sprite);
    set_sprite_tile(piece->i + 1, 1);
    move_sprite(piece->i + 1, piece->x * PIECE_SIZE + 32, piece->y * PIECE_SIZE + 24);
    SHOW_SPRITES;
}


void Piece_move(Piece* piece) {
    if (piece->x + piece->dx > 7 | piece->x + piece->dx < 0) piece->dx = -piece->dx;
    if (piece->y + piece->dy > 7 | piece->y + piece->dy < 0) piece->dy = -piece->dy;

    piece->x += piece->dx;
    piece->y += piece->dy;
    move_sprite(piece->i, piece->x * PIECE_SIZE + 24, piece->y * PIECE_SIZE + 24);
    move_sprite(piece->i + 1, piece->x * PIECE_SIZE + 32, piece->y * PIECE_SIZE + 24);
}
