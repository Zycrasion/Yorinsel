#include "GameObject.h"

GameObject::GameObject(Mesh mesh_,vec2 position_, b2World* world,float bx, float by) : mesh(mesh_), position(position_)
{
	bodyDef.position.Set(position.x, position.y);
	body = world->CreateBody(&bodyDef);
	bodyShape.SetAsBox(bx, by);
}

void GameObject::draw()
{
	mesh.draw();
}