#pragma once

class Color
{
public:
	float R, G, B, A;
	Color();
	Color(float r, float g, float b, float a);
	~Color();

	static Color White;
	static Color Black;
	static Color Red;
	static Color Green;
	static Color Blue;
	static Color Yellow;
};

