#include "minecrouft.h"

extern minecrouft_t minecrouft;

keyboard_t init_keyboard()
{
    keyboard_t keyboard = {0, 0, 0, 0, 0, 0};

    return (keyboard);
}

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

void cursor_callback(GLFWwindow* window, double cursor_x, double cursor_y)
{
    int width, height;
    float delta_x, delta_y, new_rot_y;

    glfwGetWindowSize(minecrouft.window, &width, &height);
    glfwSetCursorPos(minecrouft.window, width / 2, height / 2);
    delta_x = (float) (cursor_x - width / 2);
    delta_y = (float) (cursor_y - height / 2);
    minecrouft.player.rot_x += delta_x * ROTATION_SPEED;
    new_rot_y = delta_y * ROTATION_SPEED;
    if (minecrouft.player.rot_y + new_rot_y > 90)
        minecrouft.player.rot_y = 90;
    else if (minecrouft.player.rot_y + new_rot_y < -90)
        minecrouft.player.rot_y = -90;
    else
        minecrouft.player.rot_y += new_rot_y;
}

void proceed_pressed_keys()
{
    if (minecrouft.keyboard.w_is_pressed)
        move_forward(&minecrouft.player, &minecrouft.world);
    if (minecrouft.keyboard.a_is_pressed)
        move_left(&minecrouft.player, &minecrouft.world);
    if (minecrouft.keyboard.s_is_pressed)
        move_backward(&minecrouft.player, &minecrouft.world);
    if (minecrouft.keyboard.d_is_pressed)
        move_right(&minecrouft.player, &minecrouft.world);
    if (minecrouft.keyboard.space_is_pressed)
        minecrouft.player.pos.y += MOVEMENT_SPEED;
    if (minecrouft.keyboard.shift_is_pressed)
        minecrouft.player.pos.y -= MOVEMENT_SPEED;
}

