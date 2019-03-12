#include <gb/gb.h>
#include <stdio.h>

UWORD scale_frequency[] = {
 // C    C+   D    D+   E    F    F+   G    G+   A    A+   B  // Oct
   44, 156, 262, 363, 457, 547, 631, 710, 786, 854, 923, 986,// 2
 1046,1102,1155,1205,1253,1297,1339,1379,1417,1452,1486,1517,// 3
 1546,1575,1602,1627,1650,1673,1694,1714,1732,1750,1767,1783,// 4
 1798,1812,1825,1837,1849,1860,1871,1881,1890,1899,1907,1915,// 5
 1923,1930,1936,1943,1949,1954,1959,1964,1969,1974,1978,1982,// 6
 1985,1988,1992,1995,1998,2001,2004,2006,2009,2011,2013,2015,// 7
 2017
};

void main(){
    // these registers must be in this specific order!
    NR52_REG = 0x80; // is 1000 0000 in binary and turns on sound
    NR50_REG = 0x77; // sets the volume for both left and right channel just set to max 0x77
    NR51_REG = 0xFF; // is 1111 1111 in binary, select which chanels we want to use in this case all of them. One bit for the L one bit for the R of all four channels


    while(1) {
        UBYTE joypad_state = joypad();
        UBYTE freq;
        
        if(joypad_state) {   
            NR10_REG = 0x06; 
            NR11_REG = 0x40;
            NR12_REG = 0x73;  

            // 262
            freq = 2017;

            NR13_REG = (UBYTE)(freq & 0x00FF);
            // b7:開始フラグ=1 / b6:カウンタ再生フラグ=0 / b2-0:周波数(11ビットの上位3ビット)
            NR14_REG = (UBYTE)((freq >> 8) & 0x00FF) + 0x80;
            delay(400);

        }
    }
}
