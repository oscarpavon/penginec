#include "windows.h"

#include "vector.h"
#include "model.h"

#include "stdio.h"

#include "renderer/renderer_opengl.h"

#include <cglm/call.h>
#include <cglm/mat4.h>
#include <cglm/affine.h>
#include <cglm/vec3.h>


#include "images.h"


int main(){
    Window win;
    create_window(&win);

    init_renderer();

    glEnable(GL_DEPTH_TEST);


    struct Model new_model;
    load_model("Game/models/character-test.gltf",&new_model);

    VertexArray vertex_array = new_model.vertex_array;

    GLuint id_vertex_buffer;
    glGenBuffers(1,&id_vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER,id_vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_array.count * sizeof(struct Vertex) , vertex_array.vertices, GL_STATIC_DRAW);

    GLuint id_index_buffer;
    glGenBuffers(1,&id_index_buffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id_index_buffer);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                new_model.index_array.count * sizeof(unsigned short int), 
                new_model.index_array.indices , GL_STATIC_DRAW);


    free(new_model.vertex_array.vertices);
    free(new_model.index_array.indices);

    GLuint vert_shader = load_and_compile_shader("Game/shaders/gles/simple_vert.glsl", GL_VERTEX_SHADER);
    GLuint frag_shader = load_and_compile_shader("Game/shaders/gles/texture.glsl", GL_FRAGMENT_SHADER);
    GLuint shader = glCreateProgram();
    glAttachShader(shader, vert_shader);
    glAttachShader(shader, frag_shader);
    glLinkProgram(shader);



    Image loaded_image = load_image("Game/textures/character2.jpg");
    GLuint image_buffer;

    glGenTextures(1, &image_buffer);
    glBindTexture(GL_TEXTURE_2D, image_buffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, loaded_image.width, loaded_image.heigth, 0, GL_RGB, GL_UNSIGNED_BYTE, loaded_image.pixels_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    GLenum error = glGetError();
    if(error != GL_NO_ERROR){
      printf("Something was wrong\n");
      printf("Error %08x \n",error);
    }

    mat4 mvp;
    glmc_mat4_identity(mvp);

    vec3 axis;
    glmc_vec3_one(axis);
    axis[0] = 0;
    axis[2] = 0;

    while(!glfwWindowShouldClose(win.window)){

        glClearColor(1,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glmc_rotate(mvp, 0.005f, axis);
        glUniformMatrix4fv(0, 1, GL_FALSE, &mvp[0][0]);


        glUseProgram(shader);
        glBindTexture(GL_TEXTURE_2D, image_buffer);
        //glUniform1i(glGetUniformLocation(shader, "texture_sampler"), 0);

        GLenum error = glGetError();
        if(error != GL_NO_ERROR){
          printf("Something was worng in bind texture\n");
          printf("Error %08x \n",error);
        }

        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(struct Vertex),(void*)0);
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1,2, GL_FLOAT, GL_FALSE, sizeof(struct Vertex), (void*)offsetof(struct Vertex, uv));
        // glBindBuffer(GL_ARRAY_BUFFER,id_vertex_buffer);
        //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id_index_buffer);

        glDrawElements(GL_TRIANGLES, new_model.index_array.count , GL_UNSIGNED_SHORT, (void*)0);

        update_envents();
        glfwSwapBuffers(win.window);
    }
    glfwTerminate();
    return 1;
}

