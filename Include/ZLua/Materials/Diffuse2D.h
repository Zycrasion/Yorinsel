#pragma once
#include "Material.h"

class Diffuse2D : public Material
{
public:
	const char* pathToVertex = "./Include/ZLua/Materials/Shaders/Diffuse2D/vertex.glsl";
	const char* pathToFragment = "./Include/ZLua/Materials/Shaders/Diffuse2D/fragment.glsl";
	Diffuse2D(float r, float g, float b);
	Diffuse2D() = default;
};

