#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

void main() {
    UBYTE x1 = 4;
    UWORD y1 = 4;

    color(BLACK, WHITE, SOLID);

    for (x1 = 4; x1 < 160; x1 += 8) {
        line(x1, 4, x1, 152);
        for (y1 = 4; y1 < 160; y1 += 8) {
            line(4, y1, 152, y1);
            circle(x1, y1, 2, M_FILL);
        }
    }
}
