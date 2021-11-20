#include "Material.h"

//Material::Material()
//{
//	colour = Colour(0, 0, 0);
//	shader = Shader();
//}

Material::Material(const char* fShader, const char* vShader)
{
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
	
}

void Material::init()
{

}