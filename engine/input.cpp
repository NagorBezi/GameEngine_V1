#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool isKeyPressed (GLFWwindow* window, int key)
{
  return (glfwGetKey (window, key) == GLFW_PRESS);
}