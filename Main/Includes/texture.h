#ifndef TEXTURE_H
#define TEXTURE_H

#include <GL/glut.h>

typedef GLubyte Pixel[];

typedef struct Texture {
    GLuint id;
    char filename[100];
    Pixel* image;
} Texture;

void loadTexture(Texture* texture, const char filename[100]);

#endif
