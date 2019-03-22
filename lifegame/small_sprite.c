#include <gb/gb.h>
#include "sprite.c"


void main(){
    UBYTE i, j;
    SPRITES_8x16;
    set_sprite_data(0, 0, sprite);
    set_sprite_tile(0, 0);
    for (i = 0; i != 8; i++) {
        for (j = 0; j != 4; j++) {
            move_sprite(i * 8 + j, i * 8 + 20, j * 16 + 20);
            delay(500);
            SHOW_SPRITES;
        }
    }
}
