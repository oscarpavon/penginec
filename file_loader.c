#include "stdlib.h"
#include "stdio.h"
void load_file(const char* path, char** buffer){
    FILE* f = fopen(path,"r");
    if(f == NULL){
        printf("error to load: %s\n", path);
    }
    
    fseek(f, 0 , SEEK_END);
    int size = ftell(f);
    *buffer = (char*)malloc(size+1);
    fclose(f);
    (*buffer)[size] = 0;
}

