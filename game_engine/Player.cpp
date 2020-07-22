#include "Player.h"

Player::Player(Vector2 newPos, Sprite* newSprite, ParticleSystem* newParticles)
{
	m_position = newPos;
	m_rotation = 0.0f;
	m_scale = Vector2(1.0f, 1.0f);
	m_blend = BlendingMode::Add;

	m_sprite = newSprite;
	m_trail = newParticles;

	TranslateMatrix = Matrix::makeTranslationMatrix(m_position.X, m_position.Y, 0.0f);
	RotateMatrix = Matrix::makeRotateMatrix(m_rotation, Vector(0.0f, 0.0f, 1.0f));
	ScaleMatrix = Matrix::makeScaleMatrix(m_scale.X, m_scale.Y, 0.0f);
}

Player::~Player()
{

}

void Player::Update(GLFWwindow* window, float DeltaTime)
{
	if (glfwGetKey(window, 'A')) m_position.X -= 10.0f;
	if (glfwGetKey(window, 'D')) m_position.X += 10.0f;
	if (glfwGetKey(window, 'W')) m_position.Y += 10.0f;
	if (glfwGetKey(window, 'S')) m_position.Y -= 10.0f;

	if (m_position.X < 0)
		m_position.X = 0.0f;
	if (m_position.X > ScreenRes::screenWidth)
		m_position.X = ScreenRes::screenWidth;
	if (m_position.Y < 0)
		m_position.Y = 0.0f;
	if (m_position.Y > ScreenRes::screenHeight)
		m_position.Y = ScreenRes::screenHeight;

	m_trail->m_position.X = m_position.X;
	m_trail->m_position.Y = m_position.Y;
	m_trail->Update(DeltaTime);
}

void Player::Draw()
{
	m_trail->Draw(); 

	TranslateMatrix = Matrix::makeTranslationMatrix(m_position.X, m_position.Y, 0.0f);
	TransformMatrix = TranslateMatrix * RotateMatrix * ScaleMatrix;
	glLoadMatrixf((GLfloat*)TransformMatrix.mVal);
	m_sprite->Draw(m_color, m_blend);
}