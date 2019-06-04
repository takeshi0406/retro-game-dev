#include <gb/gb.h>
#include <stdio.h>
#include <piece.h>
#include <sound.h>



Sound sound;
UWORD count;
void update_music(void);
void init_interrupts(void);


int main(void) {
    Piece piece[2];

    init_interrupts();
    Piece_init(&piece[0], 0, 50, 50);
    Piece_init(&piece[1], 1, 55, 55);
    for (;;) {
        Piece_move(&piece[0], 1, 0);
        Piece_move(&piece[1], 1, 0);
        delay(100);
        Piece_move(&piece[0], -1, 0);
        Piece_move(&piece[1], -1, 0);
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
