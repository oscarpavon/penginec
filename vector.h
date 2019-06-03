#ifndef VECTOR_H
#define VECTOR_H


#include <stdlib.h>

typedef struct _vector{
    void* data;
    size_t limit;
    size_t size;
}vector;

void vector_add(vector*,void*);
unsigned int vector_size(vector*);


#endif // !VECTOR_H