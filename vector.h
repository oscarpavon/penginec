#ifndef VECTOR_H
#define VECTOR_H


#include <stdlib.h>

typedef struct _vector{    
    size_t limit;
    size_t size;
    size_t element_size;
    size_t count;
    void* data[]; 
}vector;


typedef struct vertex_array{    
    size_t limit;
    size_t size;
    size_t count;
    struct Vertex* vertices; 
}VertexArray;

int vector_init(vector*, size_t);
void vector_add(vector*,void*);
unsigned int vector_size(vector*);
void* vector_get(vector* v, int index);

int init_vertex_array(VertexArray* array, size_t size);

void add_vextex_to_array(VertexArray*, struct Vertex);
#endif // !VECTOR_H