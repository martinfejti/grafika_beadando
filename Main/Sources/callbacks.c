#include <GL/glut.h>

#include "callbacks.h"
#include "camera.h"
#include "game.h"
#include "light.h"
#include "helpmenu.h"

#ifndef WINDOW_VIEWPORT_RATIO
    #define WINDOW_VIEWPORT_RATIO 4/3   // screen ratio 4:3
#endif

void setCallbacks() {
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseHandler);
    glutMouseWheelFunc(mouseScrollHandler);
    glutMotionFunc(mouseMotionHandler);
    glutKeyboardFunc(keyboardNormalButtonHandler);
    glutSpecialFunc(keyboardSpecialButtonHandler);
    glutIdleFunc(idle);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();
        renderCamera();
        renderLight();
        renderGame();
        renderHelpMenuIfVisible();
    glPopMatrix();
    glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height) {
    int x, y, w, h;
    double ratio = (double)width / height;
    double viewportRatio = WINDOW_VIEWPORT_RATIO;

    if (ratio > viewportRatio) {
        w = (int)((double)height * viewportRatio);
        h = height;
        x = (width - w) / 2;
        y = 0;
    } else {
        w = width;
        h = (int)((double)width / viewportRatio);
        x = 0;
        y = (height - h) / 2;
    }

    glViewport(x, y, w, h);
}

void mouseHandler(int button, int state, int x, int y) {
    cameraMouseHandler(button, state, x, y);
    
    glutPostRedisplay();
}

void mouseScrollHandler(int wheel, int direction, int x, int y) {
    cameraMouseScrollHandler(wheel, direction, x, y);

    glutPostRedisplay();
}

void mouseMotionHandler(int x, int y) {
    cameraMouseMotionHandler(x, y);

    glutPostRedisplay();
}

void keyboardNormalButtonHandler(unsigned char key, int x, int y) {
    lightKeyboardNormalButtonHandler(key, x, y);

    glutPostRedisplay();
}

void keyboardSpecialButtonHandler(int key, int x, int y) {
    helpmenuKeyboardSpecialButtonHandler(key, x, y);
    gameKeyboardSpecialButtonHandler(key, x, y);

    glutPostRedisplay();
}

void idle() {
	static double lastFrameTime = 0;	
	double currentTime = glutGet(GLUT_ELAPSED_TIME);
    double dt = (double)currentTime - lastFrameTime; //ms
	
    if(dt > 1000.0 / 30) {
        updateGame(dt);

        glutPostRedisplay();
        lastFrameTime = currentTime;
    }
}