#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include "texture.h"

void loadTexture(Texture* texture, const char filename[100]) {
    glGenTextures(1, &texture->id); // generate texture name

    int width, height;

    texture->image = (Pixel*)SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGBA);
    if (texture->image == NULL) {
        printf('Could not load texture: %s\n', filename);
        printf('The error was: %s\n', SOIL_last_result());
    } else {
        printf('Texture was loaded: %s\n', filename);
    }

    glBindTexture(GL_TEXTURE_2D, texture->id); // bind texture to target (target, texture)
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, (Pixel*)texture->image);
    // 2 dimension texture image, last parameter is the image

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP); // set parameters

    float border_color[4] = {0, 0, 0, 0.7};
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color); // set border color

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}