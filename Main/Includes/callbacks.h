#include <GL/glut.h>

void setCallbacks();
void display();
void reshape(GLsizei width, GLsizei height);
void mouseHandler(int button, int state, int x, int y);
void mouseScrollHandler(int wheel, int direction, int x, int y);
void mouseMotionHandler(int x, int y);
void keyboardNormalButtonHandler(unsigned char key, int x, int y);
void keyboardSpecialButtonHandler(int key, int x, int y);
void idle();