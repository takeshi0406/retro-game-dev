#include <gb/gb.h>
#include <gb/drawing.h>


UWORD count;
void joy_isr(void);

int main(void) {
    disable_interrupts();
    add_JOY(joy_isr);
    enable_interrupts();
    set_interrupts(JOY_IFLAG);
    count = 0;
    while (1) {
        delay(1);
        if (count > 0) {
            gprintf("ok");
        } else {
            gprintf("ng");
        }
    }
}

void joy_isr(void) {
    count++;
}
