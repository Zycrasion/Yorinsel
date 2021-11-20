#pragma once
#include "Mesh.h"
#include "vec2.h"

class GameObject
{
	Mesh mesh;
	vec2 position;
	vec2 velocity;
	GameObject(Mesh* mesh);
};

