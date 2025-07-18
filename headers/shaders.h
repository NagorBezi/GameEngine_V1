#ifndef SHADERS
#define SHADERS

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

unsigned int newVertexShader(std::string path);
unsigned int newFragmentShader(std::string path);

unsigned int newShaderProgram(unsigned int vertex_shader, unsigned int fragment_shader);
bool isShaderProgramOK(unsigned int shaderProgram);

void scale (unsigned int shaderProgram, glm::vec3 S_vector);
void rotate (unsigned int shaderProgram, float amount, glm::vec3 axis);
void translate (unsigned int shaderProgram, glm::vec3 T_vector);

#endif