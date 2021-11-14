#pragma once
#include "Colour.h"
#include "../Shader.h"

class Material
{
protected:
	Colour colour;
	Shader shader;
public:
	Material(float r, float g, float b, const char* fShader, const char* vShader);
	//Material() = default;
	void setColour(float r, float g, float b);
	virtual void init();
	//void setTexture();
	Colour getColour();
	//void getTexture();
	void apply();
};

