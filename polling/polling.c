#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>


UWORD count;
UWORD known;
void joy_isr(void);

int main(void) {
    disable_interrupts();
    add_JOY(joy_isr);
    enable_interrupts();
    set_interrupts(JOY_IFLAG);
    count = 0;
    known = 0;

    // see https://github.com/hschmitt/gbdk/blob/d7707bf2b3c5433edcd37d53a1475fd51a9b9502/examples-gb/irq.c
    while (1) {
        if (count != known) {
            printf("count %d\n", count);
            known = count;
        }
        delay(100);
    }
}

void joy_isr(void) {
    count++;
}
