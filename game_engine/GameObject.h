#pragma once
#include "util/matrix.h"
#include "util/Vector2.h"
#include "Sprite.h"


class GameObject
{
protected:
	Vector2 ObjectPosition;
	float ObjectRotation;
	Vector2 ObjectScale;

	Sprite* ObjectSprite;
	Matrix TransformMatrix, TranslateMatrix, RotateMatrix, ScaleMatrix;
	Color* ObjectColor = &Color::White;
	BlendMode ObjectBlendMode;

public:
	GameObject();
	GameObject(Sprite* DesiredSprite);
	~GameObject();
	Vector2 GetPosition() { return ObjectPosition; }
	float GetRotation() { return ObjectRotation; }
	Vector2 GetScale() { return ObjectScale; }
	Color* GetColor() { return ObjectColor; }
	void SetPosition(const Vector2& DesiredPosition);
	void SetRotation(float DesiredRotation);
	void SetScale(const Vector2& DesiredScale);
	void SetColor(Color* DesiredColor);
	void SetBlendMode(BlendMode DesiredBlendMode);

	void Update(float DeltaTime);
	void Draw();
};
