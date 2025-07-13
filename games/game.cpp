#include "../headers/initWindow.h"
#include "../headers/shaders.h"
#include "../headers/objects.h"
#include "../headers/textures.h"


bool working = true;

const unsigned int SCREEN_HEIGHT=1200, SCREEN_WIDTH=900;
const char* Title = "TEST GAME";

GLFWwindow* window = newWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title);

float verts[] =
{
  -0.5f,  0.5f,  0.0f,   1.0f, 0.5f, 0.5f,   0.0f, 1.0f,
  -0.5f, -0.5f,  0.0f,   0.5f, 1.0f, 0.5f,   0.0f, 0.0f,
   0.5f, -0.5f,  0.0f,   0.5f, 0.5f, 1.0f,   1.0f, 0.0f,
   0.5f,  0.5f,  0.0f,   1.0f, 0.5f, 1.0f,   1.0f, 1.0f
};


unsigned int indices[] = 
{
  0, 1, 2,
	0, 2, 3
};


void init()
{
	std::cout << "\nGAME_INITIALIZED\n" << std::endl;

  useWindow(window);
  working = isWindowOK(window);

  setTexWrapMethod(1);
  setTexFilterMethod(1);
}

int main()
{
  // INIT FUNCTION
  init();

  // PRE-MAIN LOOP
	unsigned int ourShader = newShaderProgram(
  	newVertexShader("shader/shader1.vs"),
  	newFragmentShader("shader/shader1.fs")
	);

  working = isShaderProgramOK(ourShader);

  Object rect (verts, 32, indices, 6, true, 1);

  if ( !working )
  {
    return -1;
  }

  // MAIN LOOP
  while (!glfwWindowShouldClose(window))
  {
    bg_color(0.0f, 0.0f, 0.0f, 1.0f);

    rect.render(ourShader);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(ourShader);
  glfwTerminate();

  return 0;
  
}
