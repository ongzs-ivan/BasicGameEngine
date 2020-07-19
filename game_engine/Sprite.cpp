#include "Sprite.h"

Sprite::Sprite()
{
	SpriteWidth = 50.f;
	SpriteHeight = 50.f;
	SpriteTextureID = 0;
}

Sprite::Sprite(const char* File)
{
	CBitmap bitmap(File);
	SpriteWidth = bitmap.GetWidth();
	SpriteHeight = bitmap.GetHeight();

	glGenTextures(1, &SpriteTextureID);
	glBindTexture(GL_TEXTURE_2D, SpriteTextureID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	// bilinear filtering.
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, bitmap.GetWidth(), bitmap.GetHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap.GetBits());

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	std::cout << bitmap.GetWidth() << " " << bitmap.GetHeight() << std::endl;
}

Sprite::~Sprite()
{
}

void Sprite::Draw(const Color& newColor, BlendingMode blend)
{
	float HalfWidth = SpriteWidth / 2.f;
	float HalfHeight = SpriteHeight / 2.f;

	// Binds texture to draw
	glBindTexture(GL_TEXTURE_2D, SpriteTextureID);

	// Sets the rgba channels
	glColor4f(newColor.R, newColor.G, newColor.B, newColor.A);

	// Sets blend mode
	switch (blend)
	{
	case BlendingMode::Alpha:
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		break;
	case BlendingMode::Add:
		glBlendFunc(GL_SRC_ALPHA, GL_ONE);
		break;
	case BlendingMode::Multiply:
		glBlendFunc(GL_ZERO, GL_SRC_COLOR);
		break;
	}

	glBegin(GL_TRIANGLES);
		glTexCoord2f(0, 1); glVertex2f(0 - HalfWidth, 0 + HalfHeight);
		glTexCoord2f(0, 0); glVertex2f(0 - HalfWidth, 0 - HalfHeight);
		glTexCoord2f(1, 0); glVertex2f(0 + HalfWidth, 0 - HalfHeight);

		glTexCoord2f(0, 1); glVertex2f(0 - HalfWidth, 0 + HalfHeight);
		glTexCoord2f(1, 1); glVertex2f(0 + HalfWidth, 0 + HalfHeight);
		glTexCoord2f(1, 0); glVertex2f(0 + HalfWidth, 0 - HalfHeight);
	glEnd();
}
