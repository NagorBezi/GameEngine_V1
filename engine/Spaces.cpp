#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 global_scale (glm::mat4 model, glm::vec3 scale_vector)
{
	return glm::scale (model, scale_vector);
}

glm::mat4 global_rotate (glm::mat4 model, float amount, glm::vec3 axis)
{
	return glm::rotate (model, glm::radians(amount), axis);
}

glm::mat4 global_translate (glm::mat4 model, glm::vec3 translation_vector)
{
	return glm::translate (model, translation_vector);
}

glm::mat4 newProjMat (float FOV, const int SCREEN_WIDTH, const int SCREEN_HEIGHT, float near, float far)
{
	return glm::perspective (glm::radians(FOV), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, near, far);
}

void updateSpaces (glm::mat4 model, glm::mat4 view, glm::mat4 projection, unsigned int shaderProgram)
{
	int modelLoc = glGetUniformLocation(shaderProgram, "model");
	int viewLoc = glGetUniformLocation(shaderProgram, "view");
	int projLoc = glGetUniformLocation(shaderProgram, "projection");

	glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
}