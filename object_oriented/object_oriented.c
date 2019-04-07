#include "Player.h"


int main(void) {
    Player player;

    Player_Init(&player, 10, 20);
    Player_Draw(&player);
}
