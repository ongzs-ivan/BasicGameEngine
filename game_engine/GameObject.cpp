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

/// <summary>
/// Sets the game object's position to the input vector.
/// </summary>
void GameObject::setPosition(const Vector2& newPosition)
{
	m_position = newPosition;
	TranslateMatrix = Matrix::makeTranslationMatrix(m_position.X, m_position.Y, 0.0f);
}

/// <summary>
/// Sets the game object's rotation to the input rotation.
/// </summary>
void GameObject::setRotation(float newRotation)
{
	m_rotation = newRotation;
	RotateMatrix = Matrix::makeRotateMatrix(m_rotation, Vector(0.0f, 0.0f, 1.0f));
}

/// <summary>
/// Sets the game object's scale to the input vector.
/// </summary>
void GameObject::setScale(const Vector2& newScale)
{
	m_scale = newScale;
	ScaleMatrix = Matrix::makeScaleMatrix(m_scale.X, m_scale.Y, 1.0f);
}

/// <summary>
/// Sets the game object's sprite color to the input color.
/// </summary>
void GameObject::setColor(const Color& newColor)
{
	m_color = newColor;
}

/// <summary>
/// Sets the blending mode to which the game object's sprite will render by.
/// </summary>
void GameObject::setBlendMode(BlendingMode newBlend)
{
	m_blend = newBlend;
}

/// <summary>
/// Updates the variables of the game object upon function call.
/// </summary>
void GameObject::Update(GLFWwindow* window, float DeltaTime)
{

}

/// <summary>
///  Renders the game object onto the screen according to its current values.
/// </summary>
void GameObject::Draw()
{
	TransformMatrix = TranslateMatrix * RotateMatrix * ScaleMatrix;
	glLoadMatrixf((GLfloat*)TransformMatrix.mVal);

	m_sprite->Draw(m_color, m_blend);
}
