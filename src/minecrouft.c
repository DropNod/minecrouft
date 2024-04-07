#include "minecrouft.h"

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}

minecrouft_t init_minecrouft()
{
    minecrouft_t minecrouft;

    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    minecrouft.window = glfwCreateWindow(WIDTH, HEIGHT, "Minecrouft", NULL, NULL);
    if (!minecrouft.window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(minecrouft.window);
    glfwSetKeyCallback(minecrouft.window, key_callback);
    glfwSetCursorPosCallback(minecrouft.window, cursor_callback);
    glfwSetInputMode(minecrouft.window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetCursorPos(minecrouft.window, WIDTH / 2, HEIGHT / 2);
    minecrouft.player = init_player(init_pos(0, 2, 0), 0, 0);
    minecrouft.world = init_world();
    minecrouft.textures = init_textures();
    minecrouft.keyboard = init_keyboard();
    return (minecrouft);
}
