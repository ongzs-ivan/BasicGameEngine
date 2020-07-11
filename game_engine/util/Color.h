#pragma once

class Color
{
public:
	float R, G, B, A;
	static Color White;
	static Color Red;
	static Color Green;
	static Color Blue;
	Color(float r, float g, float b, float a)
	{
		R = r;
		G = g;
		B = b;
		A = a;
	}
};

