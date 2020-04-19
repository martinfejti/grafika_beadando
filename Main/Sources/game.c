#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include "game.h"
#include "model.h"
#include "draw.h"
#include "texture.h"

#ifndef M_PI
    #define M_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#endif

Model models[32];
Texture textures[3];
AnimatedGameObject earth;
AnimatedGameObject reactor;
AnimatedGameObject reactorTrail;

void loadModels() {
    load_model("Models/Earth/Earth.obj", &(models[0]));
    scale_model(&(models[0], 0.5, 0.5, 0.5);

    load_model("Models/Reactor/Reactor.obj", &(models[1]);
    scale_model(&(models[1]), 0.05, 0.05, 0.05);

    for (int i = 1; i <=30; i++) {
        char str[100];
        sprintf(str, "%s%d", "Models/ReactorTrail/ReactorTrail_", i, ".obj");

        load_model(str, &(models[i+1]));
        scale_model(&(models[i+1]), 0.05, 0.05, 0.05);
    }
}

void loadTextures() {
    loadTexture(&(textures[0]), "Textures/Earth/Earth.png");
    loadTexture(&(textures[1]), "Textures/Reactor/Reactor.png");
    loadTexture(&(textures[2]), "Textures/ReactorTrail/ReactorTrail.png");
}

void initGame() {
    loadModels();
    loadTextures();

    earth.model = &models[0];
    earth.texture = &textures[0];
    earth.posX = 0.0;
    earth.posY = 0.0;
    earth.posZ = 0.0;
    earth.rotateX = 90.0;
    earth.rotateY = 0.0;
    earth.rotateZ = 0.0;
    earth.currentModelIndex = 0;
    earth.animationSpeedFactor = 40;

    reactor.model = &models[1];
    reactor.texture = &textures[1];
    reactor.posX = 2.0;
    reactor.posY = 0.0;
    reactor.posZ = 0.0;
    reactor.rotateX = 0.0;
    reactor.rotateY = 180.0;
    reactor.rotateZ = 0.0;
    reactor.currentModelIndex = 1;
    reactor.animationSpeedFactor = 20;

    reactorTrail.model = &models[2];
    reactorTrail.texture = &textures[2];
    reactorTrail.posX = 2.0;
    reactorTrail.posY = 0.0;
    reactorTrail.posZ = 0.0;
    reactorTrail.rotateX = 0.0;
    reactorTrail.rotateY = 180.0;
    reactorTrail.rotateZ = 0.0;
    reactorTrail.currentModelIndex = 1.51;
    reactorTrail.animationSpeedFactor = 40;
}

void renderGame() {
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, earth.texture->id);
        glTranslatef(earth.posX, earth.posY, earth.posZ);
        glRotatef(earth.rotateX, 1, 0, 0);
        glRotatef(earth.rotateY, 0, 1, 0);
        glRotatef(earth.rotateZ, 0, 0, 1);
        draw_model(earth.model);
    glPopMatrix();

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, reactor.texture->id);
        glTranslatef(reactor.posX, reactor.posY, reactor.posZ);
        glRotatef(reactor.rotateX, 1, 0, 0);
        glRotatef(reactor.rotateY, 0, 1, 0);
        glRotatef(reactor.rotateZ, 0, 0, 1);
        draw_model(reactor.model);
    glPopMatrix();

    GLfloat a1[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat a2[4] = {0.0, 0.0, 0.0, 1.0};

    glPushMatrix();
        glDisable(GL_LIGHTING);
        glDepthMask(GL_FALSE);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT); 
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, a1);

        glBindTexture(GL_TEXTURE_2D, reactorTrail.texture->id);
        glTranslatef(reactor.posX, reactor.posY, reactor.posZ);
        glRotatef(reactor.rotateX, 1, 0, 0);
        glRotatef(reactor.rotateY, 0, 1, 0);
        glRotatef(reactor.rotateZ, 0, 0, 1);
        draw_model(reactorTrail.model);

        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, a2);
        glDepthMask(GL_TRUE);
        glDisable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
    glPopMatrix();

    glPushMatrix();
        glDisable(GL_LIGHTING);
        glDepthMask(GL_FALSE);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK); 
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, a1);

        glBindTexture(GL_TEXTURE_2D, reactorTrail.texture->id);
        glTranslatef(reactor.posX, reactor.posY, reactor.posZ);
        glRotatef(reactor.rotateX, 1, 0, 0);
        glRotatef(reactor.rotateY, 0, 1, 0);
        glRotatef(reactor.rotateZ, 0, 0, 1);
        draw_model(reactorTrail.model);

        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, a2);
        glDepthMask(GL_TRUE);
        glDisable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}

void updateGame(double dt) {
    double correctedDt = dt/1000;

    earth.rotateZ += correctedDt * eart.animationSpeedFactor;

    reactorTrail.currentIndexModel += correctedDt * reactorTrail.animationSpeedFactor;
    if (reactorTrail.currentIndexModel > 31.49) {
        reactorTrail.currentIndexModel = 1.51;
    }
    reactorTrail.model = &models[(int)round(reactorTrail.currentIndexModel)];
    
    reactor.rotateY += correctedDt * reactor.animationSpeedFactor;
    reactor.posZ = 2 * cos((reactor.rotateY - 90) / 180 * M_PI);
    reactor.posX = 2 * sin((reactor.rotateY - 90) / 180 * M_PI);
}

void gameKeyboardSpecialButtonHandler(unsigned char key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            reactor.animationSpeedFactor += 1;
            break;
        case GLUT_KEY_DOWN:
            reactor.animationSpeedFactor -= 1;
            break;
    }

	if (reactor.animationSpeedFactor > 1000) {
		reactor.animationSpeedFactor = 1000;
	}

	if (reactor.animationSpeedFactor < 0.0) {
		reactor.animationSpeedFactor = 0.0;
	}
};