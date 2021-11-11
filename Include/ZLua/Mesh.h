#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "Shader.h"
#include "status.h"

class Mesh
{
public:
	std::vector<float> vertices;
	Shader shader;
	unsigned int VBO;
	unsigned int VAO;

	Mesh(std::vector<float> vertexes, unsigned int shader_);
	ZLUA_STATUS draw();
};

