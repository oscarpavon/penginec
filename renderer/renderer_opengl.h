#ifndef RENDERER_OPENGL_H
#define RENDERER_OPENGL_H

#include <GLES2/gl2.h>

GLint load_and_compile_shader(const char* , GLenum);
void init_renderer();
#endif // !RENDERER_OPENGL_H

