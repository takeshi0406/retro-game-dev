#include <gb/gb.h>
#include "sprite.c"

void main() {
    SPRITES_8x8;
    set_sprite_data(0, 8, sprite);
    set_sprite_tile(0, 0);
    move_sprite(0, 50, 50);
    SHOW_SPRITES;
    delay(400);
    set_sprite_data(0, 8, sprite);
    set_sprite_tile(0, 0);
    move_sprite(0, 100, 100);
    SHOW_SPRITES;
}
