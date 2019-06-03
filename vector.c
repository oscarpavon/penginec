#include "vector.h"
#include <string.h>
#include <stdio.h>
#include "model.h"
void vector_add(vector *v, void *data_to_add){
     

}

int vector_init(vector* v, size_t init_capacity){
 
    return 0;
}

void* vector_get(vector* v, int index){
    if(index >= v->count)
        return NULL;
    
    return &v->data[index];
}

int init_vertex_array(VertexArray* array, size_t size){
    array->count = 0;
    array->vertices = calloc(size,sizeof(struct Vertex));
    array->size = sizeof(struct Vertex) * size;

}

void add_vextex_to_array(VertexArray *array, struct Vertex vertex){
    if(array->count == 0){
        memcpy(array->vertices,&vertex,sizeof(struct Vertex));
        array->count++;
        return;
    }
    array->size *=2;
    array->vertices = realloc(array->vertices,sizeof(struct Vertex) * array->size);
    if(!array->vertices){
        printf("array no allocated\n");
    }
    memcpy(&array->vertices[1],&vertex,sizeof(struct Vertex));
   
}