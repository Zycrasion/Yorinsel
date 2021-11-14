#include "Diffuse2D.h"

Diffuse2D::Diffuse2D(float red, float green, float blue)
{
	Material::Material(red, green, blue, pathToFragment, pathToVertex);
}

//Diffuse2D::Diffuse2D()
//{
//	float grey = 255.0f / 2.0f;
//	Material::Material(grey, grey, grey, pathToVertex, pathToFragment);
//}