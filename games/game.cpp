#include "../headers/initWindow.h"
#include "../headers/shaders.h"
#include "../headers/objects.h"


const unsigned int SCREEN_HEIGHT=1200, SCREEN_WIDTH=900;
const char* Title = "TEST GAME";

GLFWwindow* window = newWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title);


void init()
{
	std::cout << "\nGAME_INITIALIZED\n" << std::endl;

  float verts[] =
  {
    -0.5f,  0.5f,  0.0f,  1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.0f,  0.0f, 1.0f, 0.0f,
     0.5f, -0.5f,  0.0f,  0.0f, 0.0f, 1.0f
  };

  unsigned int indices[] = 
  {
    0, 1, 2
  };

  Object triangle (verts, indices, false, 1);

}

void update()
{

  while (!glfwWindowShouldClose(window))
  {
    bg_color(0.0f, 0.5f, 0.2f, 1.0f);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  
}

int main()
{

  init();
  if ( !isWindowOK(window) )
  {
    return -1;
  }

  update();

  return 0;

}