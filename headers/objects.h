#ifndef OBJECTS_H
#define OBJECTS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>


class Object
{
  unsigned int VAO, VBO, EBO;
  int number_of_indices;

public:

  Object (float vertices[], int no_of_verts, 
    unsigned int indices[], int no_of_indices, 
    bool has_texture, int count)
  {
    number_of_indices = no_of_indices;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, no_of_verts*sizeof(float), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, no_of_indices*sizeof(unsigned int), indices, GL_STATIC_DRAW);

    if ( !has_texture )
    {
      // Position attribute
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
      // Color attribute
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
      glEnableVertexAttribArray(1);
    }
    else
    {
      // Position attribute
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
      // Color attribute
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(3*sizeof(float)));
      glEnableVertexAttribArray(1);
      // Texture attribute
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
      glEnableVertexAttribArray(2);
    }

    glBindBuffer(GL_ARRAY_BUFFER, count-1);
    glBindVertexArray(count-1);

  }

  void render (unsigned int shaderProgram)
  {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, number_of_indices, GL_UNSIGNED_INT, 0);
  }

  void render_T (unsigned int shaderProgram, unsigned int texture)
  {
    glUseProgram(shaderProgram);
    glBindTexture(GL_TEXTURE_2D, texture);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, number_of_indices, GL_UNSIGNED_INT, 0);
  }

};

#endif 