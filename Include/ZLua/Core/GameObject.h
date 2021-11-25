#pragma once
#include "Mesh.h"
#include "vec2.h"
#include <box2d/box2d.h>

class GameObject
{
public:
	Mesh mesh;
	vec2 position;
	vec2 velocity;

	//Box 2D Variables
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape bodyShape;

	GameObject(Mesh mesh_, vec2 position_, b2World* world, float bx, float by);
	void draw();
};

