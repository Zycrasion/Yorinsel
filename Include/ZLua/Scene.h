#pragma once
#include "ZLua.h"

class Scene
{
public:
	std::string sceneName;
	bool DebugMode;
	
	std::vector<Mesh> Meshes;

	Scene();
	Scene(std::string sceneName_, bool DebugMode_);
	bool Debug();
	bool Debug(bool DebugMode_);
};

