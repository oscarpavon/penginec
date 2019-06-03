#define GLFW
#include "windows.h"
#include "GL/gl.h"
#include "vector.h"
#include "model.h"

#include "stdio.h"
void ini_vec(vec3 vec_to_init , float x, float y, float z){
    vec_to_init[0] = x;
    vec_to_init[1] = y;
    vec_to_init[2] = z;   
}

void create_vertices(){
    struct Vertex vert1 , vert2 , vert3;
    vec3 pos1, pos2,  pos3;
        
    ini_vec(pos1,0,1,0);
    ini_vec(pos2,1,0,0);
    ini_vec(pos3,1,1,0);
    glm_vec3_copy(pos1,vert1.postion);
    glm_vec3_copy(pos2,vert2.postion);
    glm_vec3_copy(pos3,vert3.postion);

    printf("test \n");
    

    
}

int main(){
    
    create_window();

    glfwMakeContextCurrent(win.window);

    create_vertices();

    while(!glfwWindowShouldClose(win.window)){

        glClearColor(1,0,0,0.3f);
        glClear(GL_COLOR_BUFFER_BIT);  

        update_envents();
              
        glfwSwapBuffers(win.window);
    }
    
    return 1;
}

