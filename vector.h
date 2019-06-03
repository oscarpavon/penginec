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

int vector_init(vector*, size_t);
void vector_add(vector*,void*);
unsigned int vector_size(vector*);
void* vector_get(vector* v, int index);


#endif // !VECTOR_H