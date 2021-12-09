#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "../Graphics/Materials/Material.h"
#include "../Graphics/Materials/Textured2D.h"
#include "./status.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Mesh
{
public:
	std::vector<float> vertices;
	std::vector<int> indices;
	unsigned int EBO;
	Material *mat;
	unsigned int VBO;
	unsigned int VAO;

	Mesh(std::vector<float> vertexes, std::vector<int> indices, Material* mat);
	void draw(glm::mat4 trans);
	//~Mesh();
};

