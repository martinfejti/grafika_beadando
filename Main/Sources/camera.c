#include "camera.h"

Camera camera;

void initCamera() {
    camera.zoomFactor = 0;
    camera.horizontalAngleRadian = 0;
    camera.horizontalAngleRadian = 1;
    camera.mouseOriginalPositionX = 0;
    camera.mouseOriginalPositionY = 0;
}