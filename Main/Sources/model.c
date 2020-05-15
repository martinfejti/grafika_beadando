#include <stdio.h>
#include <GL/glut.h>
#include "model.h"
#include <obj/load.h>

#ifndef INVALID_VERTEX_INDEX
  #define INVALID_VERTEX_INDEX 0
#endif

#ifndef LINE_BUFFER_SIZE
 #define LINE_BUFFER_SIZE 1024
#endif

void scale_model(struct Model* model, double sx, double sy, double sz)
{
    int i;

    for (i = 0; i < model->n_vertices; ++i) {
        model->vertices[i].x *= sx;
        model->vertices[i].y *= sy;
        model->vertices[i].z *= sz;
    }
}
