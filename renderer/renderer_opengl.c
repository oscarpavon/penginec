#include "renderer_opengl.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


void print_shader_compile_log(GLuint shader, const char* path_for_error_debug){

  GLint isCompiled = 0;
  glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
  if(isCompiled == GL_FALSE){
    printf("Failed to compile shader: %s\n",path_for_error_debug);
    GLint lenght;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &lenght);
    GLchar error[lenght];
    glGetShaderInfoLog(shader, lenght, &lenght, &error[0]);
    printf("%s\n",error);
  }



}


GLint load_and_compile_shader(const char* source_code, GLenum type){
  FILE* file = fopen(source_code, "r");
  if(file == NULL){
    printf("Error when load file %s\n", source_code);
  }
  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  long readed = 0;
  printf("File byte size %li\n",file_size);

  char* real_source;
  rewind(file);
  real_source = (char*) malloc(sizeof(char) * (file_size+1) );
  if(real_source == NULL){
    printf("error when allocating memory\n");
  }

  readed = fread(real_source, sizeof(char), file_size, file);
  printf("Bytes readed = %li\n",readed);

    GLint shader = glCreateShader(type);
    glShaderSource(shader,1,&real_source,0);

    glCompileShader(shader);

    print_shader_compile_log(shader, source_code);
    return shader;
}

void init_renderer(){

}
