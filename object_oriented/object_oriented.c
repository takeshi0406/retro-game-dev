#include "Player.h"
#include <gb/gb.h>
#include <rand.h>
#include <stdio.h>

static Player players[10];


int main(void) {
    UBYTE i, dx, dy;
    for (i = 0; i < 10; i++) {
        Player_Init(&players[i], 5, 5);
    }
    for (;;) {
        for (i = 0; i < 10; i++) {
            // ここでマイナスになる理由を調べる
            dx = rand() % 3;
            dy = rand() % 3;
            Player_Move(&players[i], dx, dy);
        }
        delay(10);
    }
}
