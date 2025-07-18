#ifndef INIT_WINDOW
#define INIT_WINDOW

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* newWindow(const unsigned int SCREEN_WIDTH, const unsigned int SCREEN_HEIGHT, const char* Title);
void bg_color(float red, float green, float blue, float alpha);
bool isWindowOK(GLFWwindow* window);
void useWindow (GLFWwindow* window);
void framebuffer_size_callback (GLFWwindow* window, int width, int height);
void windowSizeCallback(GLFWwindow* window);

#endif