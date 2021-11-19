#pragma once
#include "Material.h"
#include "Colour.h"


class Textured2D : public Material
{
public:
	const char* texturePath;
	unsigned int texture;
	Textured2D(const char* texturePath);
	void init();
	void apply();
};
