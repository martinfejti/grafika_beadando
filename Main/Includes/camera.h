#define CAMERA_H

typedef struct Camera {
    double zoomFactor;
    double horizontalAngleRadian;
    double verticalAngleRadian;
    double mouseOriginalPositionX;
    double mouseOriginalPositionY;
} Camera;

void initCamera();