#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>

typedef struct Camera {
    double zoomFactor;
    double horizontalAngleRadian;
    double verticalAngleRadian;
    double mouseOriginalPositionX;
    double mouseOriginalPositionY;
    bool startCapturingMouseMovements;
} Camera;

void initCamera();
void renderCamera();
void cameraMouseMotionHandler(int x, int y);
void cameraMouseHandler(int button, int state, int x, int y);
void cameraMouseScrollHandler(int wheel, int direction, int x, int y);

#endif
