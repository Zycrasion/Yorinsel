#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>
#include "Mesh.h"
#include "../Behaviours/ZWorldBehaviour.h"
#include "GameObject.h"

class Scene
{
public:
	std::string sceneName;
	bool DebugMode;
	ZWorldBehaviour* behaviour;
	Renderer frame;
	
	std::vector<Mesh> Meshes;
	std::vector<GameObject> Objects;

	Scene();
	Scene(std::string sceneName_, bool DebugMode_, ZWorldBehaviour* o);

	void copy(Scene scene);
	std::string name();
	bool Debug();
	bool Debug(bool DebugMode_);

	void add(Mesh mesh);
	void draw();
};

