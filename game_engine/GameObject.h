#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "util/matrix.h"
#include "util/Vector2.h"
#include "Sprite.h"

class GameObject
{
protected:
	Vector2 m_position;
	float m_rotation;
	Vector2 m_scale;

	Sprite* m_sprite;
	Matrix TransformMatrix, TranslateMatrix, RotateMatrix, ScaleMatrix;
	Color m_color = Color::White;
	BlendingMode m_blend;

public:
	GameObject();
	GameObject(Sprite* newSprite);
	~GameObject();

	Vector2 getPosition() { return m_position; }
	void setPosition(const Vector2& newPosition);

	float getRotation() { return m_rotation; }
	void setRotation(float newRotation);

	Vector2 getScale() { return m_scale; }
	void setScale(const Vector2& newScale);

	Color getColor() { return m_color; }
	void setColor(const Color& newColor);

	void setBlendMode(BlendingMode newBlend);

	virtual void Update(GLFWwindow* window, float DeltaTime);
	virtual void Draw();
};

#endif
