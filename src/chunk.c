#include "minecrouft.h"

chunk_t *init_chunk()
{
    chunk_t *chunk;

    chunk = malloc(sizeof(chunk_t));
    chunk->blocks = malloc(16 * sizeof(unsigned int **));
    for (int x = 0; x < 16; x++)
    {
        chunk->blocks[x] = malloc(100 * sizeof(unsigned int *));
        for (int y = 0; y < 100; y++)
        {
            chunk->blocks[x][y] = malloc(16 * sizeof(unsigned int));
            for (int z = 0; z < 16; z++)
                chunk->blocks[x][y][z] = 0;
        }
    }
    //flat generation
    for (int x = 0; x < 16; x++)
    {
        for (int z = 0; z < 16; z++)
            chunk->blocks[x][0][z] = 1;
    }
    chunk->blocks[0][1][0] = 1;
    return (chunk);
}
