#ifdef GLFW
        #include <GLFW/glfw3.h>
#endif // GLFW


struct Window{
    #ifdef GLFW
       GLFWwindow* window;
    #endif // GLFW
};

struct Window win;

void create_window(){
    #ifdef GLFW
        glfwInit();

        win.window = glfwCreateWindow(800,600,"C Engine", NULL, NULL);
    #endif


}

void update_envents(){
    #ifdef GLFW
        glfwPollEvents();
    #endif
}
