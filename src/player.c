#include "minecrouft.h"

player_t init_player(pos_t pos, float rot_x, float rot_y)
{
    player_t player;
    player.pos = pos;
    player.rot_x = rot_x;
    player.rot_y = rot_y;
    return (player);
}

void move_forward(player_t *player, world_t *world)
{
    pos_t pos, new_pos;
    chunk_t *chunk;

    pos = player->pos;
    new_pos.x = pos.x - sin(player->rot_x * (PI / 180)) * cos(player->rot_y * (PI / 180)) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) new_pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) new_pos.x % 16][(int) pos.y][(int) pos.z % 16])
        new_pos.x = pos.x;
    new_pos.y = pos.y - sin(player->rot_y * (PI / 180)) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) pos.x % 16][(int) new_pos.y][(int) pos.z % 16])
       new_pos.y = pos.y;
    new_pos.z = pos.z + cos(player->rot_x * (PI / 180)) * cos(player->rot_y * (PI / 180)) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) pos.x % 16][(int) pos.y][(int) new_pos.z % 16])
        new_pos.z = pos.z;
    player->pos = new_pos;
}


void move_backward(player_t *player, world_t *world)
{
    pos_t pos, new_pos;
    chunk_t *chunk;

    pos = player->pos;
    new_pos.x = pos.x + sin(player->rot_x * (PI / 180)) * cos(player->rot_y * (PI / 180)) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) new_pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) new_pos.x % 16][(int) pos.y][(int) pos.z % 16])
        new_pos.x = pos.x;
    new_pos.y = pos.y + sin(player->rot_y * (PI / 180)) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) pos.x % 16][(int) new_pos.y][(int) pos.z % 16])
       new_pos.y = pos.y;
    new_pos.z = pos.z - cos(player->rot_x * (PI / 180)) * cos(player->rot_y * (PI / 180)) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) pos.x % 16][(int) pos.y][(int) new_pos.z % 16])
        new_pos.z = pos.z;
    player->pos = new_pos;
}


void move_left(player_t *player, world_t *world)
{
    pos_t pos, new_pos;
    chunk_t *chunk;

    pos = player->pos;
    new_pos.x = pos.x - sin(player->rot_x * (PI / 180) - PI / 2) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) new_pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) new_pos.x % 16][(int) pos.y][(int) pos.z % 16])
        new_pos.x = pos.x;
    new_pos.y = pos.y;
    new_pos.z = pos.z + cos(player->rot_x * (PI / 180) - PI / 2) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) pos.x % 16][(int) pos.y][(int) new_pos.z % 16])
        new_pos.z = pos.z;
    player->pos = new_pos;
}

void move_right(player_t *player, world_t *world)
{
    pos_t pos, new_pos;
    chunk_t *chunk;

    pos = player->pos;
    new_pos.x = pos.x + sin(player->rot_x * (PI / 180) - PI / 2) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) new_pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) new_pos.x % 16][(int) pos.y][(int) pos.z % 16])
        new_pos.x = pos.x;
    new_pos.y = pos.y;
    new_pos.z = pos.z - cos(player->rot_x * (PI / 180) - PI / 2) * MOVEMENT_SPEED;
    chunk = world->chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && chunk->blocks[(int) pos.x % 16][(int) pos.y][(int) new_pos.z % 16])
        new_pos.z = pos.z;
    player->pos = new_pos;
}