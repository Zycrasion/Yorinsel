#pragma once
#include "ZLua.h"

class World
{
public:
	GLFWwindow* glWindow;
	Scene currScene;
	

	World(int width, int height, const char* title);
	int init();
	int draw();
	int end();

	void setScene(const Scene& scene);
};

void resized(GLFWwindow* window, int width, int height);