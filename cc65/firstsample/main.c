#include <conio.h>

// #define JOYPAD     (char*)0x4016
#define BTN_A      0x80
#define BTN_B      0x40
#define BTN_SELECT 0x20
#define BTN_START  0x10
#define BTN_UP     0x08
#define BTN_DOWN   0x04
#define BTN_LEFT   0x02
#define BTN_RIGHT  0x01
 
unsigned char padinfo[2][2];
 
//player:0=1P , 1=2P
void check_pad(unsigned char player)
{
    unsigned char i;
    *JOYPAD = 1;
    *JOYPAD = 0;
    padinfo[player][1] = padinfo[player][0];
    padinfo[player][0]= 0;
    for(i=0; i<8; i++) {
        padinfo[player][0] <<= 1;
        padinfo[player][0] += (*(JOYPAD + player) & 0x01);
    }
}
 
//ボタン押しっぱなし
char btndown(unsigned char player,unsigned char btn)
{
    if(padinfo[player][0] & btn) {
        return 1;
    } else {
        return 0;
    }
}
 
//ボタン押す
char btnpush(unsigned char player,unsigned char btn)
{
    if((padinfo[player][0] & btn) && 
         ! (padinfo[player][1] & btn)) {
        return 1;
    } else {
        return 0;
    }
}
 
void main(void)
{
    clrscr();
    cprintf("CHECK START\r\n");
    while(1)
    {
        check_pad(0);
        if ( btndown(0 , BTN_A     ) ) {
            cprintf("A,"     ); 
        }
        if ( btndown(0 , BTN_B     ) ) {
            cprintf("B,"     );
        }
        if ( btnpush(0 , BTN_SELECT) ) {
            cprintf("Select,");
        }
        if ( btnpush(0 , BTN_START ) ) {
            cprintf("Start," );
        }
        if ( btnpush(0 , BTN_UP    ) ) {
            cprintf("Up,"    );
        }
        if ( btnpush(0 , BTN_DOWN  ) ) {
            cprintf("Down,"  );
        }
        if ( btnpush(0 , BTN_LEFT  ) ) {
            cprintf("Left,"  );
        }
        if ( btnpush(0 , BTN_RIGHT ) ) {
            cprintf("Right," );
        }
 
        if (wherey() > 27) {
            clrscr();
            gotoxy(0, 0);
        }
    }
}
