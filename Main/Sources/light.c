#include <GL/glut.h>
#include "light.h"

Light light;

void initLight() {
    light.id = GL_LIGHT0;
    light.position[0] = 100;
    light.position[1] = 100;
    light.position[2] = 100;
    light.position[3] = 0;
    light.color[0] = 1;
    light.color[1] = 1;
    light.color[2] = 1;
    light.color[3] = 1;
    light.intensity = 1.0;
    glEnable(GL_LIGHT0);
}

void lightKeyboardNormalButtonHandler(unsigned char key, int x, int y) {
    switch (key) {
        case '+': 
            light.intensity += 0.025;
            break;
        case: '-':
            light.intensity -= 0.025;
            break;
    }

    if (light.intensity > 1.5) {
        light.intensity = 1.5;
    }

    if (light.intensity < 0) {
        light.intensity = 0;
    }
}

void renderLight() {
    GLfloat colorCorrectedByIntensity[] = {
        light.color[0] * light.intensity;
        light.color[1] * light.intensity;
        light.color[2] * light.intensity;
        light.color[3];
    };

    glLightfv(light.id, GL_POSITION, light.position);
    glLightfv(light.id, GL_AMBIENT, colorCorrectedByIntensity);
    glLightfv(light.id, GL_DIFFUSE, colorCorrectedByIntensity);
    glLightfv(light.id, GL_SPECULAR, colorCorrectedByIntensity);
}
