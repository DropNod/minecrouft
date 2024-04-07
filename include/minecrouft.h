#pragma once

#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "stb_image.h"

#define WIDTH 1920
#define HEIGHT 1080
#define RENDER_DISTANCE 1
#define WORLD_SIZE 100
#define MOVEMENT_SPEED 0.1
#define ROTATION_SPEED 0.1
#define PI 3.14159265359

typedef struct pos_s
{
    float x, y, z;
}   pos_t;
pos_t init_pos(float x, float y, float z);

typedef struct chunk_s
{
    unsigned int ***blocks;
}   chunk_t;
chunk_t *init_chunk();

typedef struct world_s
{
    chunk_t ***chunks;
}   world_t;
world_t init_world();

typedef struct player_s
{
    pos_t pos;
    float rot_x;
    float rot_y;
}   player_t;
player_t init_player(pos_t pos, float rot_x, float rot_y);
void move_forward(player_t *player, world_t *world);
void move_backward(player_t *player, world_t *world);
void move_left(player_t *player, world_t *world);
void move_right(player_t *player, world_t *world);

typedef struct textures_s
{
    GLuint cobblestone_mossy;
    GLuint grass_carried;
    GLuint grass_side_carried;
    GLuint dirt;
}   textures_t;
textures_t init_textures();

typedef struct keyboard_s
{
    char w_is_pressed;
    char a_is_pressed;
    char s_is_pressed;
    char d_is_pressed;
    char space_is_pressed;
    char shift_is_pressed;
}   keyboard_t;
keyboard_t init_keyboard();
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
void cursor_callback(GLFWwindow* window, double cursor_x, double cursor_y);
void proceed_pressed_keys();


typedef struct minecrouft_s
{
    GLFWwindow* window;
    player_t player;
    world_t world;
    textures_t textures;
    keyboard_t keyboard;
}   minecrouft_t;
minecrouft_t init_minecrouft();

//draw.c
void draw_line(pos_t pos1, pos_t pos2);
void draw_cube(pos_t pos);