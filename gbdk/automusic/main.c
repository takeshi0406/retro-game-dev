#include <gb/gb.h>
#include <stdio.h>
#include <piece.h>
#include <sound.h>
#include <board.h>



Sound sound;
UWORD count;
void update_music(void);
void init_interrupts(void);


int main(void) {
    Board board;
    Board_init(&board);

    //init_interrupts();
    for (;;) {
        Board_update(&board);
        delay(100);
    }
}


void init_interrupts(void) {
    Sound_init(&sound);

    disable_interrupts();
    add_TIM(update_music);
    enable_interrupts();
    TMA_REG = 0x00U;
    // Set clock to 4096 Hertz
    TAC_REG = 0x04U;
    set_interrupts(VBL_IFLAG | TIM_IFLAG);
}


void update_music(void) {
    count++;
    if (count > 0x03U) {
        Sound_play(&sound);
        count = 0;
    }
}
