#pragma once
#include <vector>
#include <iostream>
class vec2
{
public:
	float x, y;
	vec2();
	vec2(float x, float y);
	void add(const vec2& vec);
	void add(const float I);

	void rotate(const vec2& middle,float angle);

	float* data();
};

std::vector<float> fromList(std::vector<vec2> list, bool _);