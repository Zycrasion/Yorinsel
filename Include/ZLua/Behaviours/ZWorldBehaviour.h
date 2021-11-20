#pragma once
#include "../Graphics/Renderer.h"

class ZWorldBehaviour
{
public:
	virtual void init() = 0;
	virtual void draw(Renderer currFrame) = 0;
	virtual void  end() = 0;
};

