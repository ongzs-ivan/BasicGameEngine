#pragma once
#include "GameObject.h"

class ParticleObject :
	public GameObject
{
public:
	Vector2 Velocity, Acceleration;
	float MaxLifetime, CurrentLifetime;
	ParticleObject();
	ParticleObject(Sprite* DesiredSprite, const Vector2& ParticleVelocity, const Vector2& ParticleAcceleration, float ParticleLifetime);
	~ParticleObject();
	void Update(float DeltaTime);
};