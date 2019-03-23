#include <gb/gb.h>
#include <gb/drawing.h>
#include "sprite.c"


void main(){
    UBYTE i, j;
    SPRITES_8x16;
    // set_sprite_data(0, 0, sprite);
    // set_sprite_tile(0, 0);
    for (i = 0; i != 100; i++) {
        for (j = 0; j != 100; j++) {
            box(10, 10, 50, 50, M_NOFILL);
            // plot_point(20 + i, 20 + j);
            // move_sprite(i * 8 + j, i * 8 + 20, j * 16 + 20);
            // SHOW_SPRITES;
        }
    }
}
