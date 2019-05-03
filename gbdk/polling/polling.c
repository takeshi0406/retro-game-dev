#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>


int main(void) {
    UWORD count = 0;
    UWORD known = 0;

    for (;;) {
        if (joypad() == J_A) {
            count++;
        }
        if (count != known) {
            printf("count %d\n", count);
            known = count;
        }
        delay(100);
    }
}
