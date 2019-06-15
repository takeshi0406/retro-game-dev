#include <gb/gb.h>
#include <stdio.h>
#include <piece.h>
#include <sound.h>
#include <board.h>



UWORD count;
void update_music(void);
void init_interrupts(void);


int main(void) {
    Board board;
    Board_init(&board);

    Sound_init();
    for (;;) {
        Board_update(&board);
        Board_sound(&board);
        delay(100);
    }
}
