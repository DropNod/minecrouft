#include "minecrouft.h"

extern minecrouft_t minecrouft;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE)
        glfwSetWindowShouldClose(window, GL_TRUE);
    else if (key == GLFW_KEY_W) {
        if (action == GLFW_PRESS)
            minecrouft.keyboard.w_is_pressed = 1;
        else if (action == GLFW_RELEASE)
            minecrouft.keyboard.w_is_pressed = 0;
    }
    else if (key == GLFW_KEY_A) {
        if (action == GLFW_PRESS)
            minecrouft.keyboard.a_is_pressed = 1;
        else if (action == GLFW_RELEASE)
            minecrouft.keyboard.a_is_pressed = 0;
    }
    else if (key == GLFW_KEY_S) {
        if (action == GLFW_PRESS)
            minecrouft.keyboard.s_is_pressed = 1;
        else if (action == GLFW_RELEASE)
            minecrouft.keyboard.s_is_pressed = 0;
    }
    else if (key == GLFW_KEY_D) {
        if (action == GLFW_PRESS)
            minecrouft.keyboard.d_is_pressed = 1;
        else if (action == GLFW_RELEASE)
            minecrouft.keyboard.d_is_pressed = 0;
    }
    else if (key == GLFW_KEY_SPACE) {
        if (action == GLFW_PRESS)
            minecrouft.keyboard.space_is_pressed = 1;
        else if (action == GLFW_RELEASE)
            minecrouft.keyboard.space_is_pressed = 0;
    }
    else if (key == GLFW_KEY_LEFT_SHIFT) {
        if (action == GLFW_PRESS)
            minecrouft.keyboard.shift_is_pressed = 1;
        else if (action == GLFW_RELEASE)
            minecrouft.keyboard.shift_is_pressed = 0;
    }
}

keyboard_t init_keyboard()
{
    keyboard_t keyboard = {0, 0, 0, 0, 0, 0};

    return (keyboard);
}