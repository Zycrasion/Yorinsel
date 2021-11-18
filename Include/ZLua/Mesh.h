#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "Materials/Material.h"
#include "status.h"

class Mesh
{
public:
	std::vector<float> vertices;
	std::vector<int> indices;
	unsigned int EBO;
	Material mat;
	unsigned int VBO;
	unsigned int VAO;

	Mesh(std::vector<float> vertexes, std::vector<int> indices, Material mat);
	ZLUA_STATUS draw();
};

