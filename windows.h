#ifndef WINDOWS_H
#define WINDOWS_H
#define GLFW_INCLUDE_ES2
#define GLFW_INCLUDE_GLEXT
#ifdef GLFW
    #include <GLFW/glfw3.h>
#endif // GLFW


typedef struct window{
    #ifdef GLFW
       GLFWwindow* window;
    #endif // GLFW
} Window;



void create_window(Window *win);
void update_envents();

#endif // !WINDOWS_H