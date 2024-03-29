#pragma once
//#include <box2d/box2d.h>
#include "Scene.h"

class World
{
//private:
//	b2Vec2 gravity;
//	b2World* world;
public:
	GLFWwindow* glWindow;
	Scene currScene;

	World(int width, int height, const char* title);
	int init();
	int draw();
	int end();
	void setScene(Scene scene);
};

void resized(GLFWwindow* window, int width, int height);