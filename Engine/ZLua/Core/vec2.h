#pragma once
#include <vector>
#include <iostream>
class vec2
{
public:
	float x, y;
	vec2();
	vec2(float x, float y);
	float* data();
};

std::vector<float> fromList(std::vector<vec2> list);