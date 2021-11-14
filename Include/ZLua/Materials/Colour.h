#pragma once
class Colour
{
public:
	float red, green, blue,alpha;
	Colour(float r, float g, float b);
	Colour(float r, float g, float b, float a);
	Colour() = default;
};

