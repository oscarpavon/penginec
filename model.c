#include "model.h"
#define CGLTF_IMPLEMENTATION
#include "third_party/cgltf.h"
#include "stdio.h"
#include <cglm/vec3.h>

void load_uv(cgltf_data* data, VertexArray* out_vertex_array){
  printf("loading uv data \n");

  for(size_t i = 0 ; i < data->accessors[2].count ; i++){

    cgltf_accessor_read_float(&data->accessors[2], i, &out_vertex_array->vertices->uv[0], 2);

  }


}
void load_indices(cgltf_data* data, IndexArray* index_array){
    init_index_array(index_array,data->meshes[0].primitives[0].indices->count);

    for(size_t i = 0 ; i < data->meshes[0].primitives[0].indices->count ; i++){
        unsigned short int index= cgltf_accessor_read_index(data->meshes[0].primitives[0].indices,i);
        add_index_to_array(index_array,index);
    }



}

void load_primitives(cgltf_data* data, VertexArray* out_vertex_array){
    init_vertex_array(out_vertex_array,data->accessors[0].count);

    //struct Vertex vertices[4];
    float points[3] = {0,0,0};
    cgltf_bool load_float = cgltf_accessor_read_float(&data->accessors[0],2,&points[0],3);

    for(size_t v = 0 ; v < data->accessors[0].count ; v++){
            struct Vertex vertex;

            cgltf_accessor_read_float(&data->accessors[0],v,&vertex.postion[0],3);
            //vertices[v] = vertex;
            add_vextex_to_array(out_vertex_array,vertex);
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

    load_primitives(data,&model->vertex_array);
    load_indices(data, &model->index_array);
    load_uv(data,&model->vertex_array);
    printf("gltf loaded. \n");
    cgltf_free(data);
}
