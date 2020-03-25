#include "model.h"
#include "texture.h"

typedef struct GameObject {
    Texture* texture;
    Model* model;
    double posX;
    double posY;
    double posZ;
    double rotateX;
    double rotateY;
    double rotateZ;
} GameObject;

typedef struct AnimatedGameObject {
    struct GameObject;
    double currentIndexModel;
    double animationSpeedFactor;
} AnimatedGameObject;

void initGame();
void renderGame();
void gameKeyboardSpecialButtonHandler(unsigned char key, int x, int y);
void updateGame(double dt);
