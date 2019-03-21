#include <gb/gb.h>
#include "sprite.c"


void main(){
    UBYTE i;
    SPRITES_8x8;
    set_sprite_data(0, 0, sprite);
    set_sprite_tile(0, 0);
    // move_sprite(2, 55, 55);
    // move_sprite(3, 56, 59);
    for (i = 0; i != 20; i++) {
        move_sprite(i, i * 8, i * 8 + 8);
        SHOW_SPRITES;
        delay(100);
    }
}
