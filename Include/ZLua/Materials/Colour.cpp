#include "Colour.h"

Colour::Colour(float r, float g, float b)
{
	red = r;
	green = g;
	blue = b;
	alpha = 1.0f;
}

Colour::Colour(float r, float g, float b, float a)
{
	red = r;
	green = g;
	blue = b;
	alpha = a;
}

//Colour::Colour()
//{
//	red = 0.0f;
//	green = 0.0f;
//	blue = 0.0f;
//	alpha = 1.0f;
//}