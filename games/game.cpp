#include "../headers/Window.h"
#include "../headers/shaders.h"
#include "../headers/objects.h"
#include "../headers/textures.h"
#include "../headers/input.h"


bool working = true;

const unsigned int SCREEN_HEIGHT=1200, SCREEN_WIDTH=900;
const char* Title = "TEST GAME";

GLFWwindow* window = newWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title);

float verts[] =
{
  -0.5f,  0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
  -0.5f, -0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
   0.5f, -0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
   0.5f,  0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f
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
  setTexFilterMethod(2);
}

void input()
{
  if (isKeyPressed(window, GLFW_KEY_ESCAPE))
  {
    glfwSetWindowShouldClose(window, true);
  }
}

int main()
{
  // INIT FUNCTION
  init();

  // PRE-MAIN LOOP
	unsigned int ourShader = newShaderProgram(
  	newVertexShader("shader/shader1.vs"),
  	newFragmentShader("shader/shader2.fs")
	);

  working = isShaderProgramOK(ourShader);

  unsigned int texture = genTexture("games/textures/sigil.png");

  Object rect (verts, 32, indices, 6, true, 1);

  if ( !working )
  {
    return -1;
  }

  windowSizeCallback(window);

  // MAIN LOOP
  while (!glfwWindowShouldClose(window))
  {
    input();

    bg_color(0.0f, 0.0f, 0.0f, 1.0f);

    rect.render_T(ourShader, texture);

		rect.scale(ourShader, glm::vec3(2.0f, 2.0f, 0.0f));
		rect.rotate(ourShader, 45.0f, glm::vec3(0.0f, 0.0f, 1.0f));
		rect.translate(ourShader, glm::vec3(0.2f, 0.2f, 0.0f));

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(ourShader);
  glfwTerminate();

  return 0;
  
}
