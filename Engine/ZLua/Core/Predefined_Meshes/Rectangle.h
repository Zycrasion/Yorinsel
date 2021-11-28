#pragma once
#include "../Mesh.h"
#include "../../Graphics/Materials/Material.h"

Mesh* CreateRectangle(float width, float height, Material* material)
{
	width /= 2; height /= 2;
	std::vector<float> verts = {
		 width,  height, 0.0f,   1.0f, 1.0f,
		 width, -height, 0.0f,   1.0f, 0.0f,
		-width, -height, 0.0f,   0.0f, 0.0f,
		-width,  height, 0.0f,   0.0f, 1.0f
	};

	static std::vector<int> indices = {
		0,1,3,
		1,2,3
	};

	Mesh* Rectangle = new Mesh(verts, indices, material);
	return Rectangle;
}