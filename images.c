#include "images.h"
#define STB_IMAGE_IMPLEMENTATION
#include "third_party/stb_image.h"
Image load_image(const char* path){
  Image new_image;
  int height, width, chanels;
  unsigned char* data = NULL;

  data = stbi_load(path, &width, &height, &chanels, STBI_rgb);
  if(data == NULL){
    printf("Error in loading image %s\n",path);

  }
  new_image.heigth = height;
  new_image.width = width;
  new_image.pixels_data = data;
  return new_image;
}
