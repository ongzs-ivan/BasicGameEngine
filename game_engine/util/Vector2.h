#pragma once
#include <math.h>

class Vector2
{
public:
	float X, Y;

	Vector2();
	Vector2(float XValue, float YValue);

	Vector2 operator+(Vector2 OtherVector);
	Vector2 operator-(Vector2 OtherVector);
	Vector2 operator*(float OtherValue);
	Vector2 operator/(float OtherValue);
};