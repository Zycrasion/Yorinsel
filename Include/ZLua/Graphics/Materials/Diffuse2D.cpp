#include "Diffuse2D.h"

Diffuse2D::Diffuse2D(float red, float green, float blue) : Material(
	"./Include/ZLua/Materials/Shaders/Diffuse2D/fragment.glsl",
	"./Include/ZLua/Materials/Shaders/Diffuse2D/vertex.glsl"
)
{
	r = red;
	g = green;
	b = blue;
}

void Diffuse2D::init()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}

void Diffuse2D::apply()
{
	shader.use();
	shader.setFloat("red", r);
	shader.setFloat("blue", g);
	shader.setFloat("green", b);
}

//Diffuse2D::Diffuse2D()
//{
//	float grey = 255.0f / 2.0f;
//	Material::Material(grey, grey, grey, pathToVertex, pathToFragment);
//}