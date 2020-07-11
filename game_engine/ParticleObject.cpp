#include "ParticleObject.h"

ParticleObject::ParticleObject()
{
	Velocity = Acceleration = Vector2(0.f, 0.f);
	CurrentLifetime = MaxLifetime = 0;
}

ParticleObject::ParticleObject(Sprite* DesiredSprite, const Vector2& ParticleVelocity, const Vector2& ParticleAcceleration, float ParticleLifetime)
	: GameObject(DesiredSprite)
{
	Velocity = ParticleVelocity;
	Acceleration = ParticleAcceleration;
	CurrentLifetime = MaxLifetime = ParticleLifetime;
}

ParticleObject::~ParticleObject()
{
}

void ParticleObject::Update(float DeltaTime)
{
	// Apply acceleration (if any)
	Velocity = Velocity + (Acceleration * DeltaTime);

	// Update the position
	Vector2 NewPosition = getPosition() + (Velocity * DeltaTime);
	setPosition(NewPosition);

	// Decrease the lifetime of particle every update
	CurrentLifetime -= DeltaTime;
}
