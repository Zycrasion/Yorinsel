#include "vec2.h"

vec2::vec2()
{
	x = 0.0f;
	y = 0.0f;
}

vec2::vec2(float x_, float y_)
{
	x = x_;
	y = y_;
}

float* vec2::data()
{
	float _[] = { x,y };
	return _;
}

std::vector<float> fromList(std::vector<vec2> list,bool genTexCoords)
{
	std::vector<float> verts;
	for (int i = 0; i < list.size(); i++)
	{
		verts.push_back(list[i].x);
		verts.push_back(list[i].y);
		verts.push_back(0);
		if (genTexCoords)
		{
			verts.push_back(0);
			verts.push_back(0);
		}
	}
	return verts;
}

void vec2::add(const vec2& vec)
{
	x += vec.x;
	y += vec.y;
}
void vec2::add(const float I)
{
	x += I;
	y += y;
}
void vec2::rotate(const vec2& middle,float angle)
{
	float t_x = x;
	float t_y = y;
	x = cos(angle) * x - sin(angle) * y;
	y *= cos(angle);
}