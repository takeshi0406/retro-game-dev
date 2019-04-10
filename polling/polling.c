#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>


UWORD count;
UWORD known;
void joy_isr(void);

int main(void) {
    count = 0;
    known = 0;

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
