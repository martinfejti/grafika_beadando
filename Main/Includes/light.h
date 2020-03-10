#define LIGHT_H

#include <GL/glut.h>

typedef struct Light {
    Glenum id;
    GLfloat position[4];
    Glfloat color[4];
    double intensity;
} Light;

void initLight();
void lightKeyboardNormalButtonHandler(unsigned char key, int x, int y);
void renderLight();