#ifndef MODEL_H
#define MODEL_H

#include <stdio.h>
#include <obj/load.h>

struct TokenArray {
    char** tokens;
    int n_tokens;
};
/*
struct Vertex {
    double x;
    double y;
    double z;
};

struct TextureVertex {
    double u;
    double v;
};

struct FacePoint {
    int vertex_index;
    int texture_index;
    int normal_index;
};

struct Triangle {
    struct FacePoint points[3];
};
*/
struct Quad {
    struct FacePoint points[4];
};
/*
typedef struct Model {
    int n_vertices;
    int n_texture_vertices;
    int n_normals;
    int n_triangles;
    int n_quads;
    struct Vertex* vertices;
    struct TextureVertex* texture_vertices;
    struct Vertex* normals;
    struct Triangle* triangles;
    struct Quad* quads;
} Model;
*/
/**
 * Scale the loaded model.
 */
void scale_model(struct Model* model, double sx, double sy, double sz);

#endif