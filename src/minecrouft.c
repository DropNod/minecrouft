#include "minecrouft.h"

minecrouft_t init_minecrouft()
{
    minecrouft_t minecrouft;

    minecrouft.window = glfwCreateWindow(1920, 1080, "Minecrouft", NULL, NULL);
    glfwMakeContextCurrent(minecrouft.window);
    glfwSetKeyCallback(minecrouft.window, key_callback);
    glfwSetInputMode(minecrouft.window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetCursorPos(minecrouft.window, 1280 / 2, 720 / 2);
    if (!minecrouft.window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    minecrouft.player = init_player(init_pos(0, 2, 0), 0, 0);
    minecrouft.world = init_world();
    minecrouft.textures = init_textures();
    minecrouft.keyboard = init_keyboard();
    return (minecrouft);
}
