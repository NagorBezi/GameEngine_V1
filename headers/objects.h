#ifndef OBJECTS_H
#define OBJECTS_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Object
{
public:
  unsigned int shaderProgram;
  unsigned int VAO, VBO, EBO;
  int num_of_verts;
  Object (float vertices[], unsigned int indices[], bool has_texture, int count)
  {

    num_of_verts = sizeof(vertices) / sizeof(float);

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

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
      glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)0);
      glEnableVertexAttribArray(0);
      // Color attribute
      glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6*sizeof(float), (void*)(3*sizeof(float)));
      glEnableVertexAttribArray(1);
      // Texture attribute
      glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8*sizeof(float), (void*)(6*sizeof(float)));
      glEnableVertexAttribArray(2);
    }

    glBindBuffer(GL_ARRAY_BUFFER, count-1);
    glBindVertexArray(count-1);

  }

  void render ()
  {
    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, num_of_verts, GL_UNSIGNED_INT, 0);
  }

};

#endif 