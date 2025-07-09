#version 330 core
layout ( location = 0 ) aPos;
layout ( location = 1 ) aColor;

out vec3 ourColor;

int main()
{
  gl_Position = vec4(aPos, 1.0f);
  ourColor = aColor;
}