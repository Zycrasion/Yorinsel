#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;
class Shader
{
public:
	unsigned int ID;
	Shader();
	Shader(unsigned int ID_);
	Shader(const char* fragmentPath, const char* vertexPath);
	unsigned int getID();
	void setID(unsigned int ID_);
	void use();
	void setBool(const string& name, bool value);
	void setInt(const string& name, int value);
	void setFloat(const string& name, float value);
};