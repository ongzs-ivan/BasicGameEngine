#include "GameObject.h"

GameObject::GameObject()
{
	ObjectPosition = Vector2(0.f, 0.f);
	ObjectRotation = 0.f;
	ObjectScale = Vector2(1.f, 1.f);

	ObjectSprite = nullptr;

	TranslateMatrix = Matrix::makeTranslationMatrix(ObjectPosition.X, ObjectPosition.Y, 0.f);
	RotateMatrix = Matrix::makeRotateMatrix(ObjectRotation, Vector(0.f, 0.f, 1.f));
	ScaleMatrix = Matrix::makeScaleMatrix(ObjectScale.X, ObjectScale.Y, 0.f);

	// Set the blend mode
	ObjectBlendMode = NORMAL;
}


GameObject::GameObject(Sprite* DesiredSprite)
{
	ObjectPosition = Vector2(0.f, 0.f);
	ObjectRotation = 0.f;
	ObjectScale = Vector2(1.f, 1.f);

	ObjectSprite = DesiredSprite;
	TranslateMatrix = Matrix::makeTranslationMatrix(ObjectPosition.X, ObjectPosition.Y, 0.f);
	RotateMatrix = Matrix::makeRotateMatrix(ObjectRotation, Vector(0.f, 0.f, 1.f));
	ScaleMatrix = Matrix::makeScaleMatrix(ObjectScale.X, ObjectScale.Y, 0.f);

	// Set the blend mode
	ObjectBlendMode = NORMAL;
}


GameObject::~GameObject()
{
}

void GameObject::SetPosition(const Vector2& DesiredPosition)
{
	ObjectPosition = DesiredPosition;
	TranslateMatrix = Matrix::makeTranslationMatrix(ObjectPosition.X, ObjectPosition.Y, 0.f);
}

void GameObject::SetRotation(float DesiredRotation)
{
	ObjectRotation = DesiredRotation;
	RotateMatrix = Matrix::makeRotateMatrix(ObjectRotation, Vector(0.f, 0.f, 1.f));
}

void GameObject::SetScale(const Vector2& DesiredScale)
{
	ObjectScale = DesiredScale;
	ScaleMatrix = Matrix::makeScaleMatrix(ObjectScale.X, ObjectScale.Y, 0.f);
}

void GameObject::SetColor(Color* DesiredColor)
{
	ObjectColor = DesiredColor;
}

void GameObject::SetBlendMode(BlendMode DesiredBlendMode)
{
	ObjectBlendMode = DesiredBlendMode;
}


void GameObject::Update(float DeltaTime)
{
}

void GameObject::Draw()
{
	TransformMatrix = TranslateMatrix * RotateMatrix * ScaleMatrix;
	glLoadMatrixf((GLfloat*)TransformMatrix.mVal);

	ObjectSprite->Draw(ObjectColor, ObjectBlendMode);
}
