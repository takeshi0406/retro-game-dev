#include <gb/gb.h>
// #include "sprite.c"
#include <gb/drawing.h>


void main(){
    UBYTE i, j;
    for (i = 0; i != 4; i++) {
        for (j = 0; j != 8; j++) {
            gprintf("Hello World!");
        }
    }
}
