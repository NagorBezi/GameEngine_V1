#include "../headers/Window.h"
#include "../headers/shaders.h"
#include "../headers/objectClass.h"
#include "../headers/textures.h"
#include "../headers/input.h"


bool working = true;

const unsigned int SCREEN_HEIGHT=1200, SCREEN_WIDTH=900;
const char* Title = "TEST GAME";

GLFWwindow* window = newWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title);

float verts[32] =
{
  -0.5f,  0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f,
  -0.5f, -0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f,
   0.5f, -0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f,
   0.5f,  0.5f,  0.0f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f
};

unsigned int indices[6] = 
{
  0, 1, 2,
	0, 2, 3
};

unsigned int ourShader;

Object rect;

void init()
{
	std::cout << "\nGAME_INITIALIZED\n" << std::endl;

  useWindow(window);
  working = isWindowOK(window);

	ourShader = newShaderProgram(
  	newVertexShader("shader/shader1.vs"),
  	newFragmentShader("shader/shader2.fs")
	);

  working = isShaderProgramOK(ourShader);

	rect.init(verts, 32, indices, 6, true, 1);

	scale(ourShader, glm::vec3(2.0f, 2.0f, 1.0f));
	rotate(ourShader, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
	translate(ourShader, glm::vec3(0.2f, 0.2f, 0.0f));

  setTexWrapMethod(1);
  setTexFilterMethod(2);
}

void input()
{
  if ( isKeyPressed(window, GLFW_KEY_ESCAPE) )
  {
    glfwSetWindowShouldClose(window, true);
  }
}

int main()
{
  // INIT FUNCTION
  init();

  // PRE-MAIN LOOP
  unsigned int texture = genTexture("games/textures/sigil.png");

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

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(ourShader);
  glfwTerminate();

  return 0;
  
}
