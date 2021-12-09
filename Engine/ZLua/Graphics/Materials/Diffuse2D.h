#pragma once
#include "Material.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Diffuse2D : public Material
{
public:
	float r, g, b;
	Diffuse2D(float r, float g, float b);
	Diffuse2D() = default;
	void init();
	void apply(glm::mat4 trans);
};

