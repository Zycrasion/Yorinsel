#pragma once
#include "../Core/Mesh.h"

class Renderer
{
public:
	std::vector<Mesh> meshes;
	void renderBox(float width, float height);
	void draw();
};