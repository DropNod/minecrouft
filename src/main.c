#include "minecrouft.h"

minecrouft_t minecrouft;

void drawCube(float x, float y, float z, GLuint textureID) {
    glPushMatrix();
    glTranslatef(x, y, z);

    // Face haute
    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.grass_carried);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, -0.5);
    glEnd();

    // Face basse
    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.dirt);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    // Face avant
    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.grass_side_carried);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5f, -0.5f, 0.5f);

    // Face gauche
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);

    // Face droite
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5, -0.5, 0.5);

    // Face arrière
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    glPopMatrix();
}

static void error_callback(int error, const char* description) {
    fputs(description, stderr);
}

void updateCameraRotation() {
    double mouseX, mouseY;
    glfwGetCursorPos(minecrouft.window, &mouseX, &mouseY);
    int width, height;
    glfwGetWindowSize(minecrouft.window, &width, &height);
    float deltaX = (float) (mouseX - width / 2);
    float deltaY = (float) (mouseY - height / 2);
    float sensitivity = 0.1f;
    minecrouft.player.rotX += deltaX * sensitivity;
    float newRotY = deltaY * sensitivity;
    if (minecrouft.player.rotY + newRotY > 90)
        minecrouft.player.rotY = 90;
    else if (minecrouft.player.rotY + newRotY < -90)
        minecrouft.player.rotY = -90;
    else
        minecrouft.player.rotY += newRotY;
    glfwSetCursorPos(minecrouft.window, width / 2, height / 2);
}

int main(void) {
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    minecrouft = init_minecrouft();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    while (!glfwWindowShouldClose(minecrouft.window))
    {
        updateCameraRotation();
        if (minecrouft.keyboard.w_is_pressed)
        {
            minecrouft.player.pos.x -= sin(minecrouft.player.rotX * (M_PI / 180)) * cos(minecrouft.player.rotY * (M_PI / 180)) * 1;
            minecrouft.player.pos.y -= sin(minecrouft.player.rotY * (M_PI / 180)) * 1;
            minecrouft.player.pos.z += cos(minecrouft.player.rotX * (M_PI / 180)) * cos(minecrouft.player.rotY * (M_PI / 180)) * 1;
        }
        if (minecrouft.keyboard.a_is_pressed)
        {
            minecrouft.player.pos.x -= sin(minecrouft.player.rotX * (M_PI / 180) - M_PI / 2) * 0.1;
            minecrouft.player.pos.z += cos(minecrouft.player.rotX * (M_PI / 180) - M_PI / 2) * 0.1;
        }
        if (minecrouft.keyboard.s_is_pressed)
        {
            minecrouft.player.pos.x += sin(minecrouft.player.rotX * (M_PI / 180)) * cos(minecrouft.player.rotY * (M_PI / 180)) * 0.1;
            minecrouft.player.pos.y += sin(minecrouft.player.rotY * (M_PI / 180)) * 0.1;
            minecrouft.player.pos.z -= cos(minecrouft.player.rotX * (M_PI / 180)) * cos(minecrouft.player.rotY * (M_PI / 180)) * 0.1;
        }
        if (minecrouft.keyboard.d_is_pressed)
        {
            minecrouft.player.pos.x += sin(minecrouft.player.rotX * (M_PI / 180) - M_PI / 2) * 0.1;
            minecrouft.player.pos.z -= cos(minecrouft.player.rotX * (M_PI / 180) - M_PI / 2) * 0.1;
        }
        if (minecrouft.keyboard.space_is_pressed)
            minecrouft.player.pos.y += 0.1;
        if (minecrouft.keyboard.shift_is_pressed)
            minecrouft.player.pos.y -= 0.1;
        float ratio;
        int width, height;
        glfwGetFramebufferSize(minecrouft.window, &width, &height);
        ratio = width / (float) height;


        glClearColor(135.0f / 255.0f, 206.0f / 255.0f, 235.0f / 255.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0, ratio, 1.0, 1000.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glRotatef(minecrouft.player.rotY, 1.0f, 0.0f, 0.0f);
        glRotatef(minecrouft.player.rotX, 0.0f, 1.0f, 0.0f);
        //printf("x=%f y=%f z=%f\n", minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z);
        gluLookAt(minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z, minecrouft.player.pos.x, minecrouft.player.pos.y, minecrouft.player.pos.z + 1, 0.0, 1.0, 0.0);
        for (int cx = -RENDER_DISTANCE; cx < RENDER_DISTANCE; cx++)
        {
            for (int cz = -RENDER_DISTANCE; cz < RENDER_DISTANCE; cz++)
            {
                int relX = (int) minecrouft.player.pos.x / 16 + cx + 50;
                int relZ = (int) minecrouft.player.pos.z / 16 + cz + 50;
                printf("relX=%d relY=%d\n", relX, relZ);
                fflush(stdout); 
                chunk_t *chunk = minecrouft.world.chunks[relX][relZ];
                if (!chunk)
                    chunk = init_chunk();
                for (int x = 0; x < 16; x++)
                {
                    for (int y = 0; y < 100; y++)
                    {
                        for (int z = 0; z < 16; z++)
                            if (chunk->blocks[x][y][z] == 1)
                                drawCube(relX * 16 + x - 50 * 16, y, relZ * 16 + z - 50 * 16, minecrouft.textures.cobblestone_mossy);
                    }
                }
            }
        }

        glfwSwapBuffers(minecrouft.window);
        glfwPollEvents();
    }

    glfwDestroyWindow(minecrouft.window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
}