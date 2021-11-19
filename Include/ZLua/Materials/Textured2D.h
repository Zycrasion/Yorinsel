#pragma once
#include "Material.h"
#include "Colour.h"
#include "../Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Textured2D
{
public:
	const char* texturePath;
	unsigned int texture;
	Shader shader;
	Textured2D(const char* texturePath);
	void init();
	void apply();
};
