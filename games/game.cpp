#include "../headers/initWindow.h"
#include "../headers/shaders.h"
#include "../headers/objects.h"

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
  working = isWindowOK(window);
}

int main()
{
  // PRE-MAIN LOOP
	unsigned int ourShader = newShaderProgram(
  	newVertexShader("shader/shader1.vs"),
  	newFragmentShader("shader/shader2.fs")
	);

  working = isShaderProgramOK(ourShader);

  Object rect (verts, 32, indices, 6, true, 1);

  // MAIN LOOP
  while (!glfwWindowShouldClose(window) and working)
  {
    bg_color(0.0f, 0.0f, 0.0f, 1.0f);

    rect.render(ourShader);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(ourShader);
  glfwTerminate();
  
}
