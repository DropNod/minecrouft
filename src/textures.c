#define STB_IMAGE_IMPLEMENTATION
#include "minecrouft.h"

static GLuint load_texture(char* filepath) {
    GLuint texture;
    int width, height, nrChannels;
    unsigned char *data;

    data = stbi_load(filepath, &width, &height, &nrChannels, 0);
    if (!data)
    {
        fprintf(stderr, "Can't load image\n");
        exit(1);
    }
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, nrChannels == 4 ? GL_RGBA : GL_RGB, width, height, 0, nrChannels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
    return texture;
}

textures_t init_textures()
{
    textures_t textures;

    textures.cobblestone_mossy = load_texture("assets/cobblestone_mossy.png");
    textures.grass_carried = load_texture("assets/grass_carried.png");
    textures.grass_side_carried = load_texture("assets/grass_side_carried.png");
    textures.dirt = load_texture("assets/dirt.png");
    return (textures);
}