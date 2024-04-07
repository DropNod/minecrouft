#include "minecrouft.h"

extern minecrouft_t minecrouft;

void draw_line(pos_t pos1, pos_t pos2)
{
    glBegin(GL_LINES);
    glVertex3f(pos1.x, pos1.y, pos1.z);
    glVertex3f(pos2.x, pos2.y, pos2.z);
    glEnd();
}

void draw_cube(pos_t pos)
{
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);

    // Face haute
    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.grass_carried);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 1.0, 0.0);

    glEnd();

    // Face basse
    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.dirt);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 0.0, 1.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 0.0, 1.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.0, 0.0);

    glEnd();

    // Face avant
    glBindTexture(GL_TEXTURE_2D, minecrouft.textures.grass_side_carried);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 1.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0f, 0.0f, 1.0f);

    // Face arrière
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.0, 0.0);

    // Face gauche
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.0, 1.0, 0.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.0, 0.0, 0.0);

    // Face droite
    glTexCoord2f(0.0f, 0.0f); glVertex3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0, 1.0, 0.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(1.0, 0.0, 1.0);

    glEnd();
    glPopMatrix();
}