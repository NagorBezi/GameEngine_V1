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


float verts[192] =
{
  -0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, // 0
  -0.5f, -0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // 1
   0.5f, -0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // 2
   0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // 3

	-0.5f,  0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, // 4
  -0.5f, -0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // 5
   0.5f, -0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // 6
   0.5f,  0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // 7

	-0.5f,  0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, // 8
	-0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // 9
	-0.5f, -0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // 10
	-0.5f, -0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // 11

   0.5f,  0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, // 12
	 0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // 13
	 0.5f, -0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // 14
	 0.5f, -0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // 15

	-0.5f, -0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, // 16
	-0.5f, -0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // 17
	 0.5f, -0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // 18
	 0.5f, -0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // 19

	-0.5f,  0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 1.0f, // 20
	-0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   0.0f, 0.0f, // 21
	 0.5f,  0.5f,  -0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 0.0f, // 22
	 0.5f,  0.5f,   0.5f,   1.0f, 1.0f, 1.0f,   1.0f, 1.0f, // 23

};
unsigned int indices[36] = 
{
	0, 1, 2,
	0, 2, 3,

	4, 5, 6,
	4, 6, 7,

	8, 9, 10,
	8, 10, 11,

	12, 13, 14,
	12, 14, 15,

	16, 17, 18,
	16, 18, 19,

	20, 21, 22,
	20, 22, 23
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

	rect.init(verts, 192, indices, 36, true, 1);

  setTexWrapMethod(2);
  setTexFilterMethod(1);
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
	glEnable(GL_DEPTH_TEST);

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
		glClear(GL_DEPTH_BUFFER_BIT);

    rect.render_T(ourShader, texture);

		updateSpaces(model, view, projection, ourShader);

    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glDeleteProgram(ourShader);
  glfwTerminate();

  return 0;
  
}
