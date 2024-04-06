#include "minecrouft.h"

player_t init_player(pos_t pos, float rotX, float rotY)
{
    player_t player;
    player.pos = pos;
    player.rotX = rotX;
    player.rotY = rotY;
    return (player);
}