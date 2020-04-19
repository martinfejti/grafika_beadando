#ifndef LIGHT_H
#define LIGHT_H

#include <GL/glut.h>

typedef struct Light {
    GLenum id;
    GLfloat position[4];
    GLfloat color[4];
    double intensity;
} Light;

void initLight();
void lightKeyboardNormalButtonHandler(unsigned char key, int x, int y);
void renderLight();

#endif