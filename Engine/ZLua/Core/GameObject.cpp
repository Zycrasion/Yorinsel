#include "GameObject.h"

GameObject::GameObject(Mesh mesh_) : mesh(mesh_)
{
}

void GameObject::draw()
{
	mesh.draw();
}