#include "Renderer.h"

void Renderer::renderBox(float width, float height)
{
	float w = width / 2;
	float h = height / 2;
	float verts[12] = {
		w, h, 0,
		w, -h, 0,
		-w, h, 0,
		-w, -h, 0
	};
}

void Renderer::draw()
{

}