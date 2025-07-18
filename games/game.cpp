#include "../headers/Window.h"
#include "../headers/Spaces.h"
#include "../headers/shaders.h"
#include "../headers/objectClass.h"
#include "../headers/textures.h"
#include "../headers/input.h"


bool working = true;


const unsigned int SCREEN_HEIGHT=900, SCREEN_WIDTH=900;
const char* Title = "TEST GAME";
GLFWwindow* window = newWindow(SCREEN_HEIGHT, SCREEN_WIDTH, Title);


float fov = 45.0;
glm::mat4 model = glm::mat4(1.0f);
glm::mat4 view = glm::mat4(1.0f);
glm::mat4 projection = newProjMat(fov, SCREEN_WIDTH, SCREEN_HEIGHT, 0.1f, 100.0f);


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

	view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
	model = global_rotate(model, -55.0f, glm::vec3(1.0f, 0.0f, 0.0f));

	ourShader = newShaderProgram(
  	newVertexShader("shader/shader1.vs"),
  	newFragmentShader("shader/shader2.fs")
	);

  working = isShaderProgramOK(ourShader);

	rect.init(verts, 32, indices, 6, true, 1);

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
  unsigned int texture = genTexture("games/textures/crate-texture.jpg");

  if ( !working )
  {
    return -1;
  }

  windowSizeCallback(window);

  // MAIN LOOP
  while (!glfwWindowShouldClose(window))
  {
    input();
    bg_color(0.0f, 0.0f, 0.25f, 1.0f);

    rect.render_T(ourShader, texture);

		updateSpaces(model, view, projection, ourShader);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(ourShader);
  glfwTerminate();

  return 0;
  
}
