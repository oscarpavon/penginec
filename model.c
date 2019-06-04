#include "model.h"
#define CGLTF_IMPLEMENTATION
#include "third_party/cgltf.h"
#include "stdio.h"
void load_model(const char* path , struct Model* model){
    cgltf_options options = {0};
    cgltf_data* data = NULL;
    cgltf_result result = cgltf_parse_file(&options, path , &data);
    if (result != cgltf_result_success){
         printf("Model no loaded: %s \n", path);
    return;        
    }

    printf("gltf loaded. \n");
    cgltf_free(data);
    
}