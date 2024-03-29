#include "windows.h"
#include <stdio.h>

void create_window(Window *win){
    #ifdef GLFW
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
        glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
        glfwInit();
        win->window = glfwCreateWindow(800,600,"Engine", glfwGetPrimaryMonitor() , NULL);
        glfwMakeContextCurrent(win->window);
        glfwSetWindowMonitor(win->window, glfwGetPrimaryMonitor(), 0 , 0 , 800, 600, 0);


    #endif


}

void update_envents(){
    #ifdef GLFW
        glfwPollEvents();
    #endif
}
