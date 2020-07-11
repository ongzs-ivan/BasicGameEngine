#include "Color.h"

Color::Color()
{
	R = 1.0f;
	G = 1.0f;
	B = 1.0f;
	A = 1.0f;
}

Color::~Color()
{
		
}

Color::Color(float r, float g, float b, float a)
{
	R = r;
	G = g;
	B = b;
	A = a;
}

Color Color::White	= Color(1.0f, 1.0f, 1.0f, 1.0f);
Color Color::Black	= Color(0.0f, 0.0f, 0.0f, 1.0f);
Color Color::Red	= Color(1.0f, 0.0f, 0.0f, 1.0f);
Color Color::Green	= Color(0.0f, 1.0f, 0.0f, 1.0f);
Color Color::Blue	= Color(0.0f, 0.0f, 1.0f, 1.0f);