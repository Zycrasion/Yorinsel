#pragma once
#include "Mesh.h"
#include "vec2.h"

class GameObject
{
public:
	Mesh mesh;
	vec2 position;
	vec2 velocity;
	GameObject(Mesh mesh);
	void draw();
};

