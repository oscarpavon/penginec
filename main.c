#define GLFW
#include "windows.h"

#include "vector.h"
#include "model.h"

#include "stdio.h"



void ini_vec(vec3 vec_to_init , float x, float y, float z){
    vec_to_init[0] = x;
    vec_to_init[1] = y;
    vec_to_init[2] = z;   
}

void create_vertices(VertexArray* array){
    struct Vertex vert1 , vert2 , vert3;
    vec3 pos1, pos2,  pos3;
        
    ini_vec(pos1,-1.f,-1.f,0);
    ini_vec(pos2,1,-1.f,0);
    ini_vec(pos3,0,1.f,0);
    vert1.test = "vert1";
    vert2.test = "vert2";
    vert3.test = "vert3";

    glm_vec3_copy(pos1,vert1.postion);
    glm_vec3_copy(pos2,vert2.postion);
    glm_vec3_copy(pos3,vert3.postion);

    //printf("test \n");
    
    add_vextex_to_array(array,vert1); 
    add_vextex_to_array(array,vert2);
    add_vextex_to_array(array,vert3);
    
}

int main(){
    Window win;
    create_window(&win);

    


    VertexArray vertex_array;
    init_vertex_array(&vertex_array,1);



    create_vertices(&vertex_array);
    


    GLuint id_vertex_buffer;
    glGenBuffers(1,&id_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER,id_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_array.count * sizeof(struct Vertex) , vertex_array.vertices, GL_STATIC_DRAW);

   
    struct Model new_model;
    load_model("Game/models/triangle2.gltf",&new_model);
        

    printf("%s\n",vertex_array.vertices[0].test);
    printf("%s\n",vertex_array.vertices[1].test);
    printf("Flexible array member : %s\n",vertex_array.vertices2[1].test);

    while(!glfwWindowShouldClose(win.window)){

        glClearColor(1,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);  

        glBindBuffer(GL_ARRAY_BUFFER,id_vertex_buffer);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(struct Vertex),(void*)0);
        glDrawArrays(GL_TRIANGLES, 0 , 3);

        update_envents();
              
        glfwSwapBuffers(win.window);
    }
    
    glfwTerminate();
    return 1;
}

