#include <gb/gb.h>
#include "sprite.c"


void main(){
    UBYTE i, j;
    SPRITES_8x8;
    set_sprite_data(0, 0, sprite);
    set_sprite_tile(0, 0);
    for (i = 0; i != 8; i++) {
        for (j = 0; j != 8; j++) {
            move_sprite(i * 8 + j, i * 8 + 8, j * 8 + 8);
            SHOW_SPRITES;
            delay(100);
        }
    }
}
