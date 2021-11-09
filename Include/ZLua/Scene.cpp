#include "Scene.h"

Scene::Scene(std::string sceneName_, bool DebugMode_)
{
	sceneName = sceneName_;
	DebugMode = DebugMode_;
}

Scene::Scene()
{
	sceneName = "undefined";
	DebugMode = false;
}

bool Scene::Debug()
{
	return DebugMode;
}

bool Scene::Debug(bool DebugMode_)
{
	DebugMode = DebugMode_;
	return DebugMode;
}