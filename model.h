#ifndef MODEL_H
#define MODEL_H


#include "vector.h"

struct Model{
    VertexArray vertex_array;
    IndexArray index_array;

};

struct Geometry{

};



void load_model(const char* path, struct Model*);

#endif // !MODEL_H