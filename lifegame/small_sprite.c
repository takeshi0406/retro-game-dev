#include <gb/gb.h>
#include "sprite.c"


void main(){
	SPRITES_8x8;
	set_sprite_data(0, 8, sprite);
	set_sprite_tile(0, 0);
	move_sprite(1, 55 + 8, 75);
		
	set_sprite_data(8, 8, sprite);
	set_sprite_tile(2, 8);
	move_sprite(2, 55, 75);
    SHOW_SPRITES;
}
