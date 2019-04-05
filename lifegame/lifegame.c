#include <gb/gb.h>
#include <gb/drawing.h>
#include <rand.h>

#define RADIUS 2
#define X_MIN 4
#define X_MAX 156
#define X_NODES (X_MAX - X_MIN) / 8 + 1
#define Y_MIN 4
#define Y_MAX 140
#define Y_NODES (Y_MAX - Y_MIN) / 8 + 1

UBYTE current_map[X_NODES][Y_NODES] = {0};
UBYTE next_map[X_NODES][Y_NODES] = {0};
UBYTE joy;


void init(void);
void init_map(void);
void update_map(void);
UBYTE count_neighbors(UBYTE i, UBYTE j);
void draw(void);
void onjoy(void);
enum State {
    INPUT,
    DRAW
};


int main(void) {
    enum State state = INPUT;
    disable_interrupts();
    add_JOY(onjoy);
    enable_interrupts();
    set_interrupts(JOY_IFLAG);
    init();
    while (1) {
        switch (state) {
            case INPUT:
                init_map();
                draw();
                state = (joy == J_START) ? DRAW : INPUT;
                break;
            case DRAW:
                draw();
                update_map();
                state = (joy == J_B) ? INPUT : DRAW;
                break;
            default:
                break;
        }
    }
}


void onjoy(void) {
    joy = 1;
}


void init(void) {
    UBYTE x1, y1;
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


void init_map(void) {
    UBYTE i, j;
    for (i = 0; i < X_NODES; i++) {
        for (j = 0; j < Y_NODES; j++) {
            current_map[i][j] = rand() % 2;
        }
    }
}


void update_map(void) {
    UBYTE count, i, j;
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
    UBYTE k, l;
    UBYTE result = 0;
    for (k = 0; k < 3; k++) {
        for (l = 0; l < 3; l++) {
            if (k == 1 && l == 1) continue;
            if (i + k == 0 || i + k >= X_NODES) continue;
            if (j + l == 0 || j + l >= Y_NODES) continue;
            result += current_map[i + k - 1][j + l - 1];
        }
    }
    return result;
}


void draw(void) {
    UBYTE i, j;
    for (i = 0; i < X_NODES; i++) {
        for (j = 0; j < Y_NODES; j++) {
            color(current_map[i][j] ? BLACK : WHITE, WHITE, SOLID);
            circle(i * 8 + 4, j * 8 + 4, RADIUS, M_FILL);
        }
    }
}
