#include "model.h"
#define CGLTF_IMPLEMENTATION
#include "third_party/cgltf.h"
#include "stdio.h"
#include <cglm/vec3.h>
void load_primitives(cgltf_data* data){
    
    struct Vertex vertices[4];
   
    float points[3] = {0,0,0};
    cgltf_bool load_float = cgltf_accessor_read_float(&data->accessors[0],2,&points[0],3);

    for(size_t v = 0 ; v < data->accessors[0].count ; v++){
            struct Vertex vertex;
            vertex.test = "";
            cgltf_accessor_read_float(&data->accessors[0],v,&vertex.postion[0],3);
            vertices[v] = vertex;
    }
    
}

void load_model(const char* path , struct Model* model){
    cgltf_options options = {0};
    cgltf_data* data = NULL;
    cgltf_result result = cgltf_parse_file(&options, path , &data);
    if (result != cgltf_result_success){
         printf("Model no loaded: %s \n", path);
    return;        
    }
    cgltf_load_buffers(&options,data,path);

    load_primitives(data);
    printf("gltf loaded. \n");
    cgltf_free(data);
    
}

