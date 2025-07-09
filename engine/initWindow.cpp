#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


GLFWwindow* newWindow(const unsigned int SCREEN_HEIGHT, const unsigned int SCREEN_WIDTH, const char* Title)
{

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title, NULL, NULL);

  return window;

}

bool isWindowOK(GLFWwindow* window)
{
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return false;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return false;
  }

  return true;
}

void bg_color(float red, float green, float blue, float alpha = 1.0f)
{
  glClearColor(red, green, blue, alpha);
  glClear(GL_COLOR_BUFFER_BIT);
}

