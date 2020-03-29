#include <GL/glut.h>

#include "callbacks.h"
#include "camera.h"
#include "game.h"
#include "light.h"
#include "helpmenu.h"

#define GL_CLAMP_TO_EDGE 0x812F

void initOpenGLConfig() {
    glShadeModel(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_AUTO_NORMAL);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClearDepth(1.0);

    //camera related stuff
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(WINDOW_ASPECT_RATIO, WINDOW_VIEWPORT_RATIO, 0.01, 1000.0);

    //texture related stuff
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);
	glEnable(GL_TEXTURE_2D);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    //lighting related stuff
    glEnable(GL_LIGHTING);
    GLfloat glob_ambient[] = {0.0, 0.0, 0.0, 1.0};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, glob_ambient);

    //transparency realted
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(WINDOW_DEFAULT_WIDTH, WINDOW_DEFAULT_HEIGHT);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    int window = glutCreateWindow("Game");
    glutSetWindow(window);

    initOpenGLConfig();
    initCamera();
    initLight();
    initGame();
    initHelpMenu();

    setCallbacks();

    glutMainLoop();
    return 0;
}
