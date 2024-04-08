#include "minecrouft.h"

extern minecrouft_t minecrouft;

void draw_line(pos_t pos1, pos_t pos2)
{
    glBegin(GL_LINES);
    glVertex3f(pos1.x, pos1.y, pos1.z);
    glVertex3f(pos2.x, pos2.y, pos2.z);
    glEnd();
}

// int* check_sides(pos_t pos) {
//     unsigned int* tableau = (int*)malloc(6 * sizeof(int));
//     chunk_t *chunk;


//     //gauche
//     tableau[0] = minecrouft.world.chunks[((int) pos.x - 1) / 16][(int) pos.z / 16]->blocks[((int) pos.x - 1) % 16][(int) pos.y][(int) pos.z % 16];
//     //droite
//     tableau[0] = minecrouft.world.chunks[((int) pos.x + 1) / 16][(int) pos.z / 16]->blocks[((int) pos.x + 1) % 16][(int) pos.y][(int) pos.z % 16];
//     //avant
//     tableau[0] = minecrouft.world.chunks[(int) pos.x / 16][((int) pos.z - 1) / 16]->blocks[((int) pos.x) % 16][(int) pos.y][(int) (pos.z - 1) % 16];
//     //arriere
//     tableau[0] = minecrouft.world.chunks[(int) pos.x / 16][((int) pos.z + 1) / 16]->blocks[((int) pos.x) % 16][(int) pos.y][(int) (pos.z + 1) % 16];
//     //haut
//     tableau[0] = minecrouft.world.chunks[(int) pos.x / 16][(int) pos.z / 16]->blocks[((int) pos.x) % 16][(int) pos.y + 1][(int) pos.z % 16];
//     //bas
//     tableau[0] = minecrouft.world.chunks[(int) pos.x / 16][(int) pos.z / 16]->blocks[((int) pos.x) % 16][(int) pos.y - 1][(int) pos.z % 16];


//     //haut
//     if (tableau == NULL) {
//         // Gérer l'échec de l'allocation de mémoire
//         exit(EXIT_FAILURE);
//     }

//     // Remplir le tableau avec des valeurs arbitraires
//     for (int i = 0; i < 6; i++) {
//         tableau[i] = i * 2;
//     }

//     return tableau;
// }

void draw_cube(pos_t pos)
{
    chunk_t *chunk;
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);

    // Face haute
    chunk = minecrouft.world.chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (chunk && !chunk->blocks[((int) pos.x) % 16][(int) pos.y + 1][(int) pos.z % 16])
    {
        glBindTexture(GL_TEXTURE_2D, minecrouft.textures.grass_carried);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 1.0, 1.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 1.0, 1.0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 1.0, 0.0);
        glEnd();
    }

    // Face basse
    chunk = minecrouft.world.chunks[(int) pos.x / 16][(int) pos.z / 16];
    if (pos.y && chunk && !chunk->blocks[((int) pos.x) % 16][(int) pos.y - 1][(int) pos.z % 16])
    {
        glBindTexture(GL_TEXTURE_2D, minecrouft.textures.dirt);
        glBegin(GL_QUADS);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 1.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 1.0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.0, 0.0);
        glEnd();
    }

    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.grass_side_carried);
    glBegin(GL_QUADS);

    // Face avant
    chunk = minecrouft.world.chunks[((int) pos.x) / 16][(int) ((int) pos.z + 1) / 16];
    if (chunk && !chunk->blocks[((int) pos.x) % 16][(int) pos.y][(int) (pos.z + 1) % 16])
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 1.0f);
    }

    // Face arrière
    chunk = minecrouft.world.chunks[((int) pos.x) / 16][(int) ((int) pos.z - 1) / 16];
    if (chunk && !chunk->blocks[((int) pos.x) % 16][(int) pos.y][(int) (pos.z - 1) % 16])
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.0, 0.0);
    }

    // Face droite
    chunk = minecrouft.world.chunks[((int) pos.x - 1) / 16][(int) pos.z / 16];
    if (chunk && !chunk->blocks[((int) pos.x - 1) % 16][(int) pos.y][(int) pos.z % 16])
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 1.0, 0.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 1.0, 1.0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 0.0, 1.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.0, 0.0);
    }

    // Face gauche
    chunk = minecrouft.world.chunks[((int) pos.x + 1) / 16][(int) pos.z / 16];
    if (chunk && !chunk->blocks[((int) pos.x + 1) % 16][(int) pos.y][(int) pos.z % 16])
    {
        glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0, 1.0, 1.0);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 1.0, 0.0);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, 0.0);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0, 0.0, 1.0);
    }

    glEnd();
    glPopMatrix();
}