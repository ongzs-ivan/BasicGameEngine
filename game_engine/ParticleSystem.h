#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <list>
#include "ParticleObject.h"
#include "ParticleAffectorColor.h"
#include "ParticleAffectorScale.h"
#include "ParticleAffectorRotate.h"

class ParticleSystem
{
private:
	std::list<ParticleObject*> m_particleList;
	Vector2 m_position;
	float emissionRate;
	float emissionCount;
	Sprite* m_sprite;

	ParticleAffectorColor* m_colorAffector;
	ParticleAffectorScale* m_scaleAffector;
	ParticleAffectorRotate* m_rotateAffector;

public:
	ParticleSystem();
	ParticleSystem(const Vector2& newPos, float newRate, Sprite* newSprite);
	~ParticleSystem();

	void Update(float deltaTime);
	void Draw();
};

#endif