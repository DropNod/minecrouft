#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Définissez vos données de vertex et de texture
GLfloat vertices[] = {
    // Coordonnées        // Coordonnées de texture
     0.5f,  0.5f, 0.0f,   1.0f, 1.0f, // Haut droite
     0.5f, -0.5f, 0.0f,   1.0f, 0.0f, // Bas droite
    -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, // Bas gauche
    -0.5f,  0.5f, 0.0f,   0.0f, 1.0f  // Haut gauche
};

GLuint indices[] = {
    0, 1, 3, // Premier triangle
    1, 2, 3  // Deuxième triangle
};

GLuint VBO, VAO, EBO, texture;

// Chargez une texture à partir d'un fichier avec STB_Image
void load_texture(const char *texture_path) {
    int width, height, nrChannels;
    unsigned char *data = stbi_load(texture_path, &width, &height, &nrChannels, 0);
    if (data) {
        glGenTextures(1, &texture);
        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(data);
    } else {
        printf("Failed to load texture\n");
        exit(1);
    }
}

// Setup VBO, VAO, and EBO
void setup_buffers() {
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Positions attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)0);
    glEnableVertexAttribArray(0);

    // Texture coordinates attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}

// Render loop
void render_loop(GLFWwindow* window) {
    while (!glfwWindowShouldClose(window)) {
        // Render

        // Clear the color buffer
        glClear(GL_COLOR_BUFFER_BIT);

        // Bind texture
        glBindTexture(GL_TEXTURE_2D, texture);

        // Activate shader and bind VAO
        glBindVertexArray(VAO);

        // Draw the triangles
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        // Unbind VAO
        glBindVertexArray(0);

        // Swap buffers and poll events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        printf("Failed to initialize GLFW\n");
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "Texture Example", NULL, NULL);
    if (!window) {
        printf("Failed to create GLFW window\n");
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set up viewport
    glViewport(0, 0, 800, 600);

    // Load texture
    load_texture("container.jpg");

    // Set up buffers
    setup_buffers();

    // Render loop
    render_loop(window);

    // Terminate GLFW
    glfwTerminate();
    return 0;
}