#ifndef PARTICLEOBJECT_H
#define PARTICLEOBJECT_H

#include "GameObject.h"

class ParticleObject : public GameObject
{
public:
	Vector2 m_velocity;
	Vector2 m_accel;
	float m_lifeMax;
	float m_life;
	ParticleObject();
	ParticleObject(Sprite* newSprite, const Vector2& newVelocity, float newLife);
	~ParticleObject();

	Vector2 getAccel() { return m_accel; };
	void setAccel(Vector2 newAccel);
	
	void Update(float deltaTime);
};

#endif