#pragma once
#include <GLFW/glfw3.h>
#include "util/bitmap.h"
#include "util/matrix.h"
#include "util/Color.h"
#include <string>
#include <iostream>

enum class BlendingMode
{
	Alpha = 0,
	Add,
	Multiply
};


class Sprite
{
private:
	unsigned int SpriteWidth;
	unsigned int SpriteHeight;
	unsigned int SpriteTextureID;

public:
	Sprite();
	Sprite(const char* File);
	~Sprite();

	void Draw(const Color& newColor, BlendingMode blend);
};