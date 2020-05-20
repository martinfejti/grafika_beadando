#include <GL/glut.h>
#include <math.h>
#include <string.h>
#include "game.h"
#include "model.h"
#include "draw.h"
#include "texture.h"
#include <obj/load.h>

#ifndef M_PI
    #define M_PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286
#endif

Model models[32];
Texture textures[3];
AnimatedGameObject earth;
AnimatedGameObject reactor;
AnimatedGameObject reactorTrail;

void loadModels() {
    load_model(&(models[0]), "Models/Earth/Earth.obj");
    scale_model(&(models[0]), 0.5, 0.5, 0.5);

    load_model(&(models[1]), "Models/Reactor/Reactor.obj");
    scale_model(&(models[1]), 0.05, 0.05, 0.05);

    for (int i = 1; i <=30; i++) {
        char str[100];
        sprintf(str, "%s%d%s", "Models/ReactorTrail/ReactorTrail_", i, ".obj");

        load_model(&(models[i+1]), str);
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

    earth.gameObject.model = &models[0];
    earth.gameObject.texture = &textures[0];
    earth.gameObject.posX = 0.0;
    earth.gameObject.posY = 0.0;
    earth.gameObject.posZ = 0.0;
    earth.gameObject.rotateX = 90.0;
    earth.gameObject.rotateY = 0.0;
    earth.gameObject.rotateZ = 0.0;
    earth.currentIndexModel = 0;
    earth.animationSpeedFactor = 40;

    reactor.gameObject.model = &models[1];
    reactor.gameObject.texture = &textures[1];
    reactor.gameObject.posX = 2.0;
    reactor.gameObject.posY = 0.0;
    reactor.gameObject.posZ = 0.0;
    reactor.gameObject.rotateX = 0.0;
    reactor.gameObject.rotateY = 180.0;
    reactor.gameObject.rotateZ = 0.0;
    reactor.currentIndexModel = 1;
    reactor.animationSpeedFactor = 20;

    reactorTrail.gameObject.model = &models[2];
    reactorTrail.gameObject.texture = &textures[2];
    reactorTrail.gameObject.posX = 2.0;
    reactorTrail.gameObject.posY = 0.0;
    reactorTrail.gameObject.posZ = 0.0;
    reactorTrail.gameObject.rotateX = 0.0;
    reactorTrail.gameObject.rotateY = 180.0;
    reactorTrail.gameObject.rotateZ = 0.0;
    reactorTrail.currentIndexModel = 1.51;
    reactorTrail.animationSpeedFactor = 40;
}

void renderGame() {
    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, earth.gameObject.texture->id);
        glTranslatef(earth.gameObject.posX, earth.gameObject.posY, earth.gameObject.posZ);
        glRotatef(earth.gameObject.rotateX, 1, 0, 0);
        glRotatef(earth.gameObject.rotateY, 0, 1, 0);
        glRotatef(earth.gameObject.rotateZ, 0, 0, 1);
        draw_model(earth.gameObject.model);
    glPopMatrix();

    glPushMatrix();
        glBindTexture(GL_TEXTURE_2D, reactor.gameObject.texture->id);
        glTranslatef(reactor.gameObject.posX, reactor.gameObject.posY, reactor.gameObject.posZ);
        glRotatef(reactor.gameObject.rotateX, 1, 0, 0);
        glRotatef(reactor.gameObject.rotateY, 0, 1, 0);
        glRotatef(reactor.gameObject.rotateZ, 0, 0, 1);
        draw_model(reactor.gameObject.model);
    glPopMatrix();

    GLfloat a1[4] = {0.5, 0.5, 0.5, 1.0};
    GLfloat a2[4] = {0.0, 0.0, 0.0, 1.0};

    glPushMatrix();
        glDisable(GL_LIGHTING);
        glDepthMask(GL_FALSE);
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT); 
        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, a1);

        glBindTexture(GL_TEXTURE_2D, reactorTrail.gameObject.texture->id);
        glTranslatef(reactor.gameObject.posX, reactor.gameObject.posY, reactor.gameObject.posZ);
        glRotatef(reactor.gameObject.rotateX, 1, 0, 0);
        glRotatef(reactor.gameObject.rotateY, 0, 1, 0);
        glRotatef(reactor.gameObject.rotateZ, 0, 0, 1);
        draw_model(reactorTrail.gameObject.model);

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

        glBindTexture(GL_TEXTURE_2D, reactorTrail.gameObject.texture->id);
        glTranslatef(reactor.gameObject.posX, reactor.gameObject.posY, reactor.gameObject.posZ);
        glRotatef(reactor.gameObject.rotateX, 1, 0, 0);
        glRotatef(reactor.gameObject.rotateY, 0, 1, 0);
        glRotatef(reactor.gameObject.rotateZ, 0, 0, 1);
        draw_model(reactorTrail.gameObject.model);

        glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, a2);
        glDepthMask(GL_TRUE);
        glDisable(GL_CULL_FACE);
        glEnable(GL_LIGHTING);
    glPopMatrix();
}

void updateGame(double dt) {
    double correctedDt = dt/1000;

    earth.gameObject.rotateZ += correctedDt * earth.animationSpeedFactor;

    reactorTrail.currentIndexModel += correctedDt * reactorTrail.animationSpeedFactor;
    if (reactorTrail.currentIndexModel > 31.49) {
        reactorTrail.currentIndexModel = 1.51;
    }
    reactorTrail.gameObject.model = &models[(int)round(reactorTrail.currentIndexModel)];
    
    reactor.gameObject.rotateY += correctedDt * reactor.animationSpeedFactor;
    reactor.gameObject.posZ = 2 * cos((reactor.gameObject.rotateY - 90) / 180 * M_PI);
    reactor.gameObject.posX = 2 * sin((reactor.gameObject.rotateY - 90) / 180 * M_PI);
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