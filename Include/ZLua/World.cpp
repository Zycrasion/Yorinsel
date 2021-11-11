#include "World.h"

void resized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}


World::World(int width, int height, const char* title)
{
	if (!glfwInit())
		throw std::runtime_error("ERROR::INIT Unable to Init GLFW3. CODE: INIT1");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (glWindow == NULL)
	{
		glfwTerminate();
		throw std::runtime_error("ERROR::INIT::WINDOW Unable to create A Window. CODE: INIT2");
    }

	glfwMakeContextCurrent(glWindow);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		throw std::runtime_error("ERROR::INIT::GLAD Unable To Init Glad. CODE: INIT3");

	glViewport(0, 0, width, height);
	glfwSetFramebufferSizeCallback(glWindow, resized);
}

int World::init()
{
	return 0;
}

int World::draw()
{
	while (!glfwWindowShouldClose(glWindow))
	{

		currScene.draw();

		glfwSwapBuffers(glWindow);
		glfwPollEvents();
	}
	return 0;
}

int World::end()
{
	glfwTerminate();
	return 0;
}

void World::setScene(Scene scene)
{
	currScene = scene;
}

