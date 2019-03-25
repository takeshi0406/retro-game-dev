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

UBYTE map[X_NODES][Y_NODES] = {0};


void init();
void update_map();
void draw();

void main() {
    init();
    while (1) {
        update_map();
        draw();
        delay(200);
    }
}

void init() {
    UBYTE x1;
    UBYTE y1;
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


void update_map() {
    map[20][2] = 1;
}

void draw() {
    UBYTE i;
    UBYTE j;
    UBYTE c;
    for (i = 0; i <= X_NODES; i++) {
        for (j = 0; j <= Y_NODES; j++) {
            if (map[i][j]) {
                c = BLACK;
            } else {
                c = WHITE;
            }
            color(c, WHITE, SOLID);
            circle(i * 8 + 4, j * 8 + 4, RADIUS, M_FILL);
            delay(1);
        }
    }
}
