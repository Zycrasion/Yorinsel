#version 330 core
layout (location = 0) in vec3 aPos;
uniform float red;
uniform float blue;
uniform float green;
out vec3 col;
void main()
{
	gl_Position = vec4(aPos,1.0);
	col = vec3(red,green,blue);
}