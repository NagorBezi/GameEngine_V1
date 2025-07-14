#ifndef TEXTURES_H
#define TEXTURES_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "stb_image.h"

void setTexWrapMethod (int method);
void setTexFilterMethod (int method);
unsigned int genTexture (const char* image_path);

#endif