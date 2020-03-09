#include <stdbool.h>
#include <math.h>
#include <GL/glu.h>
#include <GL/glext.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include "camera.h"

#define FALSE 0
#define TRUE 1

Camera camera;

void initCamera() {
    camera.zoomFactor = 10;
    camera.horizontalAngleRadian = 0;
    camera.horizontalAngleRadian = 1;
    camera.mouseOriginalPositionX = 0;
    camera.mouseOriginalPositionY = 0;
    camera.startCapturingMouseMovements = FALSE;
}

void renderCamera() {
    gluLookAt(
        camera.zoomFactor * sin(camera.verticalAngleRadian) * sin(camera.horizontalAngleRadian), // eyeX
        camera.zoomFactor * cos(camera.verticalAngleRadian), // eyeY
        camera.zoomFactor * sin(camera.verticalAngleRadian) * cos(camera.horizontalAngleRadian), // eyeZ
        0, // centerX
        0, // centerY
        0, // centerZ
        sin(camera.verticalAngleRadian - 3.14/2) * sin(camera.horizontalAngleRadian), // upX
        cos(camera.verticalAngleRadian - 3.14/2), // upY
        sin(camera.verticalAngleRadian - 3.14/2) * cos(camera.horizontalAngleRadian) // upZ
    );
}

void cameraMouseMotionHandler(int x, int y) {
    if (camera.startCapturingMouseMovements) {
        camera.horizontalAngleRadian -= (x - camera.mouseOriginalPositionX) * 0.01;
        camera.verticalAngleRadian -= (y - camera.mouseOriginalPositionY) * 0.01;

        camera.mouseOriginalPositionX = x;
        camera.mouseOriginalPositionY = y;
    }
}

void cameraMouseHandler(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            camera.startCapturingMouseMovements = TRUE;
            camera.mouseOriginalPositionX = x;
            camera.mouseOriginalPositionY = y;
        }

        if (state == GLUT_UP) {
            camera.startCapturingMouseMovements = FALSE;
        }
    }
    // button could be right/left/middle
    // state could be up/down
    // probelms with imports!!!
}

void cameraMouseScrollHandler(int wheel, int direction, int x, int y) {
    direction *= (-1);
    camera.zoomFactor += 0.1 * direction;

    if (camera.zoomFactor > 20) {
        camera.zoomFactor = 20;
    } 
    if (camera.zoomFactor < 5) {
        camera.zoomFactor = 5;
    }
}
