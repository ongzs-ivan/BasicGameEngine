#include "ParticleObject.h"

ParticleObject::ParticleObject()
{
	m_velocity = m_accel = Vector2(0.0f, 0.0f);
	m_life = m_lifeMax = 0;
}

ParticleObject::ParticleObject(Sprite* newSprite, const Vector2& newVelocity, float newLife) : GameObject(newSprite)
{
	m_velocity = newVelocity;
	m_lifeMax = newLife;
}

ParticleObject::~ParticleObject()
{
}

void ParticleObject::setAccel(Vector2 newAccel)
{
	m_accel = newAccel;
}

void ParticleObject::Update(float deltaTime)
{
	// Apply acceleration (if any)
	m_velocity = m_velocity + (m_accel * deltaTime);

	// Update the position
	Vector2 NewPosition = getPosition() + (m_velocity * deltaTime);
	setPosition(NewPosition);

	// Decrease the lifetime of particle every update
	m_life += deltaTime;
}
