#pragma once
#include "Material.h"
#include "Colour.h"
#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#endif


class Textured2D : public Material
{
public:
	const char* texturePath;
	unsigned int texture;
	Textured2D(const char* texturePath);
	void init();
	void apply();
};

