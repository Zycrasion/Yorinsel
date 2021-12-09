#include "GameObject.h"


GameObject::GameObject(Mesh mesh_) : mesh(mesh_), trans(1.0f)
{

}

void GameObject::draw()
{
	mesh.draw(trans);
}

void GameObject::rotate(float angle)
{
	trans = glm::rotate(trans, glm::radians(angle), glm::vec3(0.f, 0.f, 1.f));    
}

void GameObject::move(float x, float y)
{
	trans = glm::translate(trans, glm::vec3(x, y, 0.f));
}

void GameObject::setPosition(float x, float y)
{
	trans = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.f));
}