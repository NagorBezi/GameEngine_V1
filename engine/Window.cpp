#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>


GLFWwindow* newWindow(const unsigned int SCREEN_WIDTH, const unsigned int SCREEN_HEIGHT, const char* Title)
{

  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, Title, NULL, NULL);

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

void useWindow (GLFWwindow* window)
{
  glfwMakeContextCurrent(window);
}

void framebuffer_size_callback (GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

void windowSizeCallback(GLFWwindow* window)
{
  glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}
