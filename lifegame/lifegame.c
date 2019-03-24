#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#define X_MIN 4
#define X_MAX 156
#define Y_MIN 4
#define Y_MAX 140

UBYTE x1;
UBYTE y1;


void init();

void main() {
    init();
}

void init() {
    color(BLACK, WHITE, SOLID);
    for (x1 = X_MIN; x1 <= X_MAX; x1 += 8) {
        line(x1, Y_MIN, x1, Y_MAX);
        delay(16);
    }

    for (y1 = Y_MIN; y1 <= Y_MAX; y1 += 8) {
        line(X_MIN, y1, X_MAX, y1);
        delay(16);
    }

    for (x1 = X_MIN; x1 <= X_MAX; x1 += 8) {
        for (y1 = Y_MIN; y1 <= Y_MAX; y1 += 8) {
            circle(x1, y1, 2, M_FILL);
            delay(1);
        }
    }
}
