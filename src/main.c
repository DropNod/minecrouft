#include "minecrouft.h"

minecrouft_t minecrouft;

int main(void) {
    int width, height;
    chunk_t *chunk;

    minecrouft = init_minecrouft();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_BACK);
    while (!glfwWindowShouldClose(minecrouft.window))
    {
        void proceed_pressed_keys();
        glfwGetFramebufferSize(minecrouft.window, &width, &height);
        glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, width / (float) height, 1.0, 1000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(minecrouft.player.rot_y, 1.0f, 0.0f, 0.0f);
        glRotatef(minecrouft.player.rot_x, 0.0f, 1.0f, 0.0f);
        gluLookAt(minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z, minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z + 1, 0.0, 1.0, 0.0);
        proceed_pressed_keys();
        //printf("x=%f y=%f z=%f\n", minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z);
        //fflush(stdout);
        for (int i = -RENDER_DISTANCE; i <= RENDER_DISTANCE; i++)
        {
            for (int j = -RENDER_DISTANCE; j <= RENDER_DISTANCE; j++)
            {
                int chunk_x = (int) minecrouft.player.pos.x / 16 + i;
                int chunk_z = (int) minecrouft.player.pos.z / 16 + j;
                printf("chunk_x=%d chunk_z=%d\n", chunk_x + WORLD_SIZE / 2, chunk_z + WORLD_SIZE / 2);
                chunk = minecrouft.world.chunks[chunk_x + WORLD_SIZE / 2][chunk_z + WORLD_SIZE / 2];
                if (!chunk)
                    chunk = init_chunk();
                for (int x = 0; x < 16; x++)
                {
                    for (int y = 0; y < 100; y++)
                    {
                        for (int z = 0; z < 16; z++)
                            if (chunk->blocks[x][y][z] == 1)
                                draw_cube(init_pos(chunk_x * 16 + x, y, chunk_z * 16 + z));
                    }
                }
                glColor3f(1.f, 0.f, 0.f);
                draw_line(init_pos(chunk_x * 16, 0, chunk_z * 16), init_pos(chunk_x * 16, 100, chunk_z * 16));
                draw_line(init_pos(chunk_x * 16 + 16, 0, chunk_z * 16), init_pos(chunk_x * 16 + 16, 100, chunk_z * 16));
                draw_line(init_pos(chunk_x * 16, 0, chunk_z * 16 + 16), init_pos(chunk_x * 16, 100, chunk_z * 16  + 16));
                draw_line(init_pos(chunk_x * 16 + 16, 0, chunk_z * 16 + 16), init_pos(chunk_x * 16 + 16, 100, chunk_z * 16 + 16));
                glColor3f(1.f, 1.f, 1.f);
            }
        }

        glfwSwapBuffers(minecrouft.window);
        glfwPollEvents();
    }
    glfwDestroyWindow(minecrouft.window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}