#include "Diffuse2D.h"

Diffuse2D::Diffuse2D(float red, float green, float blue) : Material(red,green,blue,
	"./Include/ZLua/Materials/Shaders/Diffuse2D/fragment.glsl",
	"./Include/ZLua/Materials/Shaders/Diffuse2D/vertex.glsl"
)
{

}

//Diffuse2D::Diffuse2D()
//{
//	float grey = 255.0f / 2.0f;
//	Material::Material(grey, grey, grey, pathToVertex, pathToFragment);
//}