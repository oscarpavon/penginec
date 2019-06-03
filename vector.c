#include "vector.h"
#include <string.h>
#include <stdio.h>

void vector_add(vector *v, void *data_to_add){
    if(v->count == 0){
         memcpy(v->data,data_to_add,v->element_size);
         v->count++;
         return;
    }      

    
    v->size *= 2;
    v->count++;
    
    
    //v = realloc(v, sizeof(vector) + sizeof(void*) * v->size * 2);
    
    v->data[0] = realloc(v->data[0], v->size * 2);    

   // memcpy(&v->data[v->count-1],data_to_add,v->element_size);
       //memcpy(&v->data[1],data_to_add,v->element_size);
       //memcpy(v->data+(v->element_size*(v->count-1)),data_to_add,v->element_size);
    if(!v){
        printf("error in reallocation\n");
        
        return;
    } 
    memcpy(v->data[1],data_to_add,v->element_size);
    

}

int vector_init(vector* v, size_t init_capacity){
    v->count = 0;
    v->data = malloc(init_capacity * v->element_size);
    if(!v->data[0]) return -1;

    v->size = init_capacity * v->element_size;
    return 0;
}

void* vector_get(vector* v, int index){
    if(index >= v->count)
        return NULL;
    
    return &v->data[index];
}