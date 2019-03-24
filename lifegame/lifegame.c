#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

void main() {
    UBYTE x1 = 20;
    UBYTE y1 = 20;
    UBYTE i = 0;
    UBYTE j = 0;

    color(BLACK, WHITE, SOLID);

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            circle(x1 + i * 8, y1 + j * 8, 2, M_FILL);
        }
    }
}
