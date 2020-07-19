#include "GameObject.h"

GameObject::GameObject()
{
	m_position = Vector2(0.0f, 0.0f);
	m_rotation = 0.f;
	m_scale = Vector2(1.0f, 1.0f);
	m_blend = BlendingMode::Alpha;

	m_sprite = nullptr;
	TranslateMatrix = Matrix::makeTranslationMatrix(m_position.X, m_position.Y, 0.0f);
	RotateMatrix = Matrix::makeRotateMatrix(m_rotation, Vector(0.0f, 0.0f, 1.0f));
	ScaleMatrix = Matrix::makeScaleMatrix(m_scale.X, m_scale.Y, 0.0f);

}

GameObject::GameObject(Sprite* newSprite)
{
	m_position = Vector2(0.0f, 0.0f);
	m_rotation = 0.f;
	m_scale = Vector2(1.0f, 1.0f);
	m_blend = BlendingMode::Alpha;

	m_sprite = newSprite;
	TranslateMatrix = Matrix::makeTranslationMatrix(m_position.X, m_position.Y, 0.0f);
	RotateMatrix = Matrix::makeRotateMatrix(m_rotation, Vector(0.0f, 0.0f, 1.0f));
	ScaleMatrix = Matrix::makeScaleMatrix(m_scale.X, m_scale.Y, 0.0f);

}

GameObject::~GameObject()
{

}

void GameObject::setPosition(const Vector2& newPosition)
{
	m_position = newPosition;
	TranslateMatrix = Matrix::makeTranslationMatrix(m_position.X, m_position.Y, 0.0f);
}

void GameObject::setRotation(float newRotation)
{
	m_rotation = newRotation;
	RotateMatrix = Matrix::makeRotateMatrix(m_rotation, Vector(0.0f, 0.0f, 1.0f));
}

void GameObject::setScale(const Vector2& newScale)
{
	m_scale = newScale;
	ScaleMatrix = Matrix::makeScaleMatrix(m_scale.X, m_scale.Y, 1.0f);
}

void GameObject::setColor(const Color& newColor)
{
	m_color = newColor;
}

void GameObject::setBlendMode(BlendingMode newBlend)
{
	m_blend = newBlend;
}


void GameObject::Update(float DeltaTime)
{

}

void GameObject::Draw()
{
	TransformMatrix = TranslateMatrix * RotateMatrix * ScaleMatrix;
	glLoadMatrixf((GLfloat*)TransformMatrix.mVal);

	m_sprite->Draw(m_color, m_blend);
}
