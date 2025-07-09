#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

int success;
char infoLog[512];

unsigned int newVertexShader(std::string path)
{

  std::string vertexCode;
  std::ifstream vShaderFile;
  vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    vShaderFile.open(path);
    std::stringstream vShaderStream;

    vShaderStream << vShaderFile.rdbuf();

    vShaderFile.close();

    vertexCode = vShaderStream.str();
  }
  catch ( std::ifstream::failure e )
  {
    std::cout << "\nSHADER_FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    return 1;
  }

  const char* vShaderCode = vertexCode.c_str();

  unsigned int vertexShader;
  vertexShader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(vertexShader, 1, &vShaderCode, NULL);

  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if ( !success )
  {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "VERTEX_SHADER_COMPILATION_FAILED: " << infoLog << std::endl;
    return 1;
  }

  return vertexShader;

}

unsigned int newFragmentShader(std::string path)
{

  std::string fragmentCode;
  std::ifstream fShaderFile;
  fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

  try
  {
    fShaderFile.open(path);
    std::stringstream fShaderStream;

    fShaderStream << fShaderFile.rdbuf();

    fShaderFile.close();

    fragmentCode = fShaderStream.str();
  }
  catch ( std::ifstream::failure e )
  {
    std::cout << "\nSHADER_FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    return 1;
  }

  const char* fShaderCode = fragmentCode.c_str();

  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fShaderCode, NULL);

  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if ( !success )
  {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "FRAGMENT_SHADER_COMPILATION_FAILED: " << infoLog << std::endl;
    return 1;
  }

  return fragmentShader;

}

unsigned int newShaderProgram(unsigned int vertex_shader, unsigned int fragment_shader)
{
  unsigned int shaderP;
  shaderP = glCreateProgram();
  glAttachShader(shaderP, vertex_shader);
  glAttachShader(shaderP, fragment_shader);
  glLinkProgram(shaderP);

  return shaderP;
}

bool isShaderProgramOK(unsigned int shaderProgram)
{
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if ( !success )
  {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "\nSHADER_PROGRAM_LINKING_FAILED: " << infoLog << std::endl;
    return false;
  }

  return true;
}