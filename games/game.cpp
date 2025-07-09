#include "../headers/initWindow.h"
#include "../headers/shaders.h"
#include "../headers/objects.h"


bool working = true;

const unsigned int SCREEN_HEIGHT=1200, SCREEN_WIDTH=900;
const char* Title = "TEST GAME";

GLFWwindow* window = newWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title);

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


void init()
{
	std::cout << "\nGAME_INITIALIZED\n" << std::endl;
  //triangle.num_of_verts = 3;
  working = isWindowOK(window);
}

void update()
{
  unsigned int ourShader = newShaderProgram(
    newVertexShader("shader/shader1.vs"),
    newFragmentShader("shader/shader1.fs")
  );

  working = working = isShaderProgramOK(ourShader);

  Object triangle (verts, 18, indices, 3, false, 1);

  while (!glfwWindowShouldClose(window) and working)
  {
    bg_color(0.0f, 0.0f, 0.0f, 1.0f);

    triangle.render(ourShader);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  
}

int main()
{

  init();
  if ( !working )
  {
    return -1;
  }

  update();

  return 0;

}