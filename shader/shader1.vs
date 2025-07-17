#version 330 core
layout ( location = 0 ) in vec3 aPos;
layout ( location = 1 ) in vec3 aColor;
layout ( location = 2 ) in vec2 aTexCoord;

out vec3 ourColor;
out vec2 ourTexCoord;

uniform mat4 scale;
uniform mat4 rotate;
uniform mat4 translate;

void main()
{
  gl_Position = scale * rotate * translate * vec4(aPos.x, aPos.y, aPos.z , 1.0f);
  ourColor = aColor;
  ourTexCoord = aTexCoord;
}