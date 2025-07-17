#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include "../headers/stb_image.h"


void setTexWrapMethod (int method)
{
  // -> 1 is for repeat
  // -> 2 is for mirrored repeat
  // -> 3 is for clamp to edge
  if ( method == 1)
  {
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  }
  else if ( method == 2 )
  {
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
  }
  else if ( method == 3 )
  {
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  }
  else
  {
    std::cout << "\nPlease enter 1, 2, or 3. Check engine/textures.cpp" << std::endl;
  }
}

void setTexFilterMethod (int method)
{
	// -> 1 is for nearest
	// -> 2 is for linear
	if ( method == 1 )
	{
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	}
	else if ( method == 2 )
	{
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	}
	else 
	{
		std::cout << "\nPlease enter 1 or 2. Check engine/textures.cpp" << std::endl;
	}
}

unsigned int genTexture (const char* image_path)
{
	stbi_set_flip_vertically_on_load(true);
	
  int width, height, nrChannels;
  unsigned char* data = stbi_load(image_path, &width, &height, &nrChannels, 0);
  
  unsigned int texture;
  if (data)
  {
    glGenTextures (1, &texture);
    glBindTexture (GL_TEXTURE_2D, texture); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
    std::cout << "\nFailed to load image" << std::endl;
    return 0;
  }

  stbi_image_free(data);
  return texture;
}