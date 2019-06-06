#include "vector.h"
#include <string.h>
#include <stdio.h>
#include "vertex.h"
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
    return 0;
}

int init_index_array(IndexArray* array, size_t size){
    array->count = 0;
    array->indices = calloc(size,sizeof(unsigned short int));
    array->size = sizeof(unsigned short int) * size;
    return 0;
}

void add_index_to_array(IndexArray* array, unsigned short int value){
    if(array->count == 0){
        memcpy(array->indices,&value,sizeof(unsigned short int));
        array->count++;
        return;
    }

    array->count++;
    array->size += sizeof(unsigned short int);
    array->indices = realloc(array->indices,sizeof(unsigned short int) * array->size);
    if(!array->indices){
        printf("array no allocated\n");
    }
    memcpy(&array->indices[array->count-1],&value,sizeof(unsigned short int));
    
}

void add_vextex_to_array(VertexArray *array, struct Vertex vertex){
    if(array->count == 0){
        memcpy(array->vertices,&vertex,sizeof(struct Vertex));
        array->count++;
        return;
    }

    array->count++;
    array->size += sizeof(struct Vertex);
    array->vertices = realloc(array->vertices,sizeof(struct Vertex) * array->size);
    if(!array->vertices){
        printf("array no allocated\n");
    }
    memcpy(&array->vertices[array->count-1],&vertex,sizeof(struct Vertex));
    //array->vertices2[array->count-1] = vertex;
   
}