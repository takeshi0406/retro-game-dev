#include <stdio.h>
#include <gb/gb.h>
#include <gb/drawing.h>

#define RADIUS 2
#define X_MIN 4
#define X_MAX 156
#define X_NODES (X_MAX - X_MIN) / 8 + 1
#define Y_MIN 4
#define Y_MAX 140
#define Y_NODES (Y_MAX - Y_MIN) / 8 + 1

UBYTE x1;
UBYTE y1;
UBYTE map[X_NODES][Y_NODES] = {0};


void init();

void main() {
    init();
}

void init() {
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
            color(WHITE, WHITE, SOLID);
            circle(x1, y1, RADIUS, M_FILL);
            delay(1);
        }
    }
}
