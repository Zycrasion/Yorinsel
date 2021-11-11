#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "Mesh.h"

class Scene
{
public:
	std::string sceneName;
	bool DebugMode;
	
	std::vector<Mesh> Meshes;

	Scene();
	Scene(std::string sceneName_, bool DebugMode_);

	void copy(Scene scene);
	std::string name();
	bool Debug();
	bool Debug(bool DebugMode_);

	void add(Mesh mesh);
	void draw();
};

