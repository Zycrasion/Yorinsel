#include "Material.h"

//Material::Material()
//{
//	colour = Colour(0, 0, 0);
//	shader = Shader();
//}

Material::Material(float r, float g, float b, const char* fShader, const char* vShader)
{
	colour = Colour(r, g, b);
	shader = Shader(fShader, vShader);
}

void Material::setColour(float r, float g, float b)
{
	colour.red = r;
	colour.green = g;
	colour.blue = b;
}
Colour Material::getColour()
{
	return colour;
}

void Material::apply()
{
	shader.use();
	shader.setFloat("red", colour.red);
	shader.setFloat("blue", colour.blue);
	shader.setFloat("green", colour.green);
}

void Material::init()
{
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
}