#pragma once
#include "Material.h"

class Diffuse2D : public Material
{
public:
	float r, g, b;
	Diffuse2D(float r, float g, float b);
	Diffuse2D() = default;
	void init();
	void apply();
};

