#ifndef SPACES_H
#define SPACES_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 global_scale (glm::mat4 model, glm::vec3 scale_vector);
glm::mat4 global_rotate (glm::mat4 model, float amount, glm::vec3 axis);
glm::mat4 global_translate (glm::mat4 model, glm::vec3 translation_vector);

glm::mat4 newProjMat (float FOV, const int SCREEN_WIDTH, const int SCREEN_HEIGHT, float near, float far);
void updateSpaces (glm::mat4 model, glm::mat4 view, glm::mat4 projection, unsigned int shaderProgram);

#endif