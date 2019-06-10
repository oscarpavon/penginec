#ifndef IMAGES_H
#define IMAGES_H

typedef struct image{
  unsigned short int width;
  unsigned short int heigth;
  unsigned char* pixels_data;
}Image;

Image load_image(const char* path);

#endif
