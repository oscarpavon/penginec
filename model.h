#ifndef MODEL_H
#define MODEL_H

#include <cglm/vec3.h>
struct Model{

};

struct Geometry{

};

struct Vertex{
    vec3 postion;
    char* test;
};

void load_model(const char* path, struct Model*);

#endif // !MODEL_H