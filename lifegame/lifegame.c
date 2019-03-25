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

UBYTE current_map[X_NODES][Y_NODES] = {0};
UBYTE next_map[X_NODES][Y_NODES] = {0};


void init();
void init_map();
void update_map();
UBYTE count_neighbors(UBYTE i, UBYTE j);
void draw();

void main() {
    init();
    init_map();
    while (1) {
        draw();
        update_map();
        delay(20);
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

void init_map() {
    current_map[5][5] = 1;
    current_map[5][6] = 1;
    current_map[5][7] = 1;
    current_map[6][6] = 1;
    current_map[6][7] = 1;
    current_map[6][8] = 1;
}


void update_map() {
    UBYTE i;
    UBYTE j;
    UBYTE count;
    for (i = 0; i < X_NODES; i++) {
        for (j = 0; j < Y_NODES; j++) {
            count = count_neighbors(i, j);
            if (current_map[i][j]) {
                if (count <= 1 || count >= 4) {
                    next_map[i][j] = 0;
                } else {
                    next_map[i][j] = 1;
                }
            } else {
                if (count == 3) {
                    next_map[i][j] = 1;
                } else {
                    next_map[i][j] = 0;
                }
            }
        }
    }

    for (i = 0; i < X_NODES; i++) {
        for (j = 0; j < Y_NODES; j++) {
            current_map[i][j] = next_map[i][j];
        }
    }
}

UBYTE count_neighbors(UBYTE i, UBYTE j) {
    UBYTE k;
    UBYTE l;
    UBYTE result = 0;
    for (k = 0; k < 3; k++) {
        for (l = 0; l < 3; l++) {
            if (k == 1 && l == 1) continue;
            if (i < k || i + k >= X_NODES) continue;
            if (j < l || j + l >= Y_NODES) continue;
            result += current_map[i + k - 1][j + l - 1];
        }
    }
    return result;
}

void draw() {
    UBYTE i;
    UBYTE j;
    UBYTE c;
    for (i = 0; i < X_NODES; i++) {
        for (j = 0; j < Y_NODES; j++) {
            if (current_map[i][j]) {
                c = BLACK;
            } else {
                c = WHITE;
            }
            color(c, WHITE, SOLID);
            circle(i * 8 + 4, j * 8 + 4, RADIUS, M_FILL);
        }
    }
}
