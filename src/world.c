#include "minecrouft.h"

world_t init_world()
{
    world_t world;

    world.chunks = malloc(100 * sizeof(chunk_t));
    for (int x = 0; x < 100; x++)
        world.chunks[x] = calloc(WORLD_SIZE * sizeof(chunk_t), WORLD_SIZE * sizeof(chunk_t));
    return (world);
}
