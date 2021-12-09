#include "Scene.h"

Scene::Scene(std::string sceneName_, bool DebugMode_, ZWorldBehaviour* behave)
{
	sceneName = sceneName_;
	DebugMode = DebugMode_;
	behaviour = behave;
}

Scene::Scene()
{
	sceneName = "undefined";
	DebugMode = false;
}

void Scene::copy(Scene scene)
{
	sceneName = scene.name();
	DebugMode = scene.Debug();
	//Objects = scene.Objects;
}

std::string Scene::name()
{
	return sceneName;
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

//void Scene::add(Mesh* mesh)
//{
//	Meshes.push_back(mesh);
//}

void Scene::add(GameObject* mesh)
{
	Objects.push_back(mesh);
}

void Scene::draw()
{
	glClearColor(0.5f, 0.1f, 0.1f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	behaviour->draw();
	int n = (int) Objects.size();
	for (int i = 0; i < n; i++)
	{
		Objects[i]->draw();
	}
}