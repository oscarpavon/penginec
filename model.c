#include "model.h"
#define CGLTF_IMPLEMENTATION
#include "third_party/cgltf.h"
#include "stdio.h"
#include <cglm/vec3.h>
void load_primitives(cgltf_data* data){
    
    for(size_t i = 0 ; i < data->meshes[0].primitives_count ; i++){
       cgltf_accessor* position_accesor = &data->accessors[0];
       cgltf_buffer_view* position_buffer_view = position_accesor->buffer_view;
       const float* bufferpos = (float*)&position_buffer_view->buffer->data[position_accesor->offset + position_buffer_view->offset];

        for(size_t v = 0 ; v < position_accesor->count ; v++){
            struct Vertex vertex;
            //float x = 
        }
       
    }
    float points[4];
    cgltf_bool load_float = cgltf_accessor_read_float(&data->accessors[0],0,&points[0],1);
    
    
}

void load_model(const char* path , struct Model* model){
    cgltf_options options = {0};
    cgltf_data* data = NULL;
    cgltf_result result = cgltf_parse_file(&options, path , &data);
    if (result != cgltf_result_success){
         printf("Model no loaded: %s \n", path);
    return;        
    }
    load_primitives(data);
    printf("gltf loaded. \n");
    cgltf_free(data);
    
}

