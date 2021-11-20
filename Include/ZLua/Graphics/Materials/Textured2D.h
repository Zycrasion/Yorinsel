#pragma once
#include "Material.h"
#include "Colour.h"
#include "../Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Textured2D : public Material
{
public:
	const char* texturePath;
	unsigned int texture;
	Textured2D(const char* texturePath);
	void init() override;
	void apply();
};
