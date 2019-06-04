#include "renderer_opengl.h"
GLint load_and_compile_shader(const char* source_code, GLenum type){  
    GLint shader = glCreateShader(type);
    glShaderSource(shader,1,&source_code,0);
    glCompileShader(shader);
    return shader;
}
