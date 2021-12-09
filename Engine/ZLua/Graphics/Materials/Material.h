#pragma once
#include "Colour.h"
#include "../Shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Material
{
protected:
	Colour colour;
	Shader shader;
public:
	Material(const char* fShader, const char* vShader);
	//Material() = default;
	void setColour(float r, float g, float b);
	virtual  void init();
	//void setTexture();
	Colour getColour();
	//void getTexture();
	virtual void apply(glm::mat4 trans);
};

