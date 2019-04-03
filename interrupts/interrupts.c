#include <gb/gb.h>
#include <gb/drawing.h>
#include <stdio.h>


UWORD count;
void joy_isr(void);

int main(void) {
    gprintf("1");
    gprintf("2");
    disable_interrupts();
    add_JOY(joy_isr);
    enable_interrupts();
    set_interrupts(JOY_IFLAG);
    gprintf("3");
    // see https://github.com/hschmitt/gbdk/blob/d7707bf2b3c5433edcd37d53a1475fd51a9b9502/examples-gb/irq.c
    /*
    return 0;
    count = 0;
    while (1) {
        delay(1);
        if (count > 0) {
            gprintf("ok");
        } else {
            gprintf("ng");
        }
    }
    */
}

void joy_isr(void) {
    // count++;
}
