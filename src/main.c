#include "minecrouft.h"

minecrouft_t minecrouft;

int main(void) {
    int width, height;
    int frame_count, fps;
    double current_time, delta_time, last_time;

    minecrouft = init_minecrouft();
    fps = 0;
    last_time = glfwGetTime();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    while (!glfwWindowShouldClose(minecrouft.window))
    {
        void proceed_pressed_keys();
        glfwGetFramebufferSize(minecrouft.window, &width, &height);
        glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, width / (float) height, 0.01, 1000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(minecrouft.player.rot_y, 1.0f, 0.0f, 0.0f);
        glRotatef(minecrouft.player.rot_x, 0.0f, 1.0f, 0.0f);
        gluLookAt(minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z, minecrouft.player.pos.x,  minecrouft.player.pos.y, minecrouft.player.pos.z + 1, 0.0, 1.0, 0.0);
        proceed_pressed_keys();
        current_time = glfwGetTime();
        delta_time = current_time - last_time;
        fps = 1 / delta_time; 
        last_time = current_time;

        // Debug
        printf("x=%f y=%f z=%f\n", minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z);
        printf("chunk_x=%d chunk_z=%d\n", (int) minecrouft.player.pos.x / 16, (int) minecrouft.player.pos.z / 16);
        printf("%dfps\n", fps);
        fflush(stdout);
        for (int i = -RENDER_DISTANCE; i <= RENDER_DISTANCE; i++)
        {
            for (int j = -RENDER_DISTANCE; j <= RENDER_DISTANCE; j++)
            {
                int chunk_x = (int) minecrouft.player.pos.x / 16 + i;
                int chunk_z = (int) minecrouft.player.pos.z / 16 + j;
                if (!minecrouft.world.chunks[chunk_x][chunk_z])
                    minecrouft.world.chunks[chunk_x][chunk_z] = init_chunk();
                for (int x = 0; x < 16; x++)
                {
                    for (int y = 0; y < 100; y++)
                    {
                        for (int z = 0; z < 16; z++)
                            if (minecrouft.world.chunks[chunk_x][chunk_z]->blocks[x][y][z] == 1)
                                draw_cube(init_pos(chunk_x * 16 + x, y, chunk_z * 16 + z));
                    }
                }
                glLineWidth(2);
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