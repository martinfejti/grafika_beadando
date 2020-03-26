#include "GL/glut.h"

#include "callbacks.h"

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