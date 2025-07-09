#ifndef SHADERS
#define SHADERS

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

unsigned int newVertexShader(std::string path);
unsigned int newFragmentShader(std::string path);
unsigned int newShaderProgram(unsigned int vertex_shader, unsigned int fragment_shader);
bool isShaderProgramOK(unsigned int shaderProgram);

#endif