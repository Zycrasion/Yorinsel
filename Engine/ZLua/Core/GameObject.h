#pragma once
#include "Mesh.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class GameObject
{
public:
	Mesh mesh;
	glm::mat4 trans;
	GameObject(Mesh mesh);
	void draw();
	void rotate(float);
	void move(float, float);
	void setPosition(float, float);
};

