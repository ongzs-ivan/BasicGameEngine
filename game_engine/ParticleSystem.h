#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <list>
#include "ParticleObject.h"
#include "ParticleAffectorColor.h"
#include "ParticleAffectorScale.h"
#include "ParticleAffectorRotate.h"
#include "ParticleAffectorGravity.h"
#include "CircleEmitterShape.h"
#include "SquareEmitterShape.h"
#include "RingEmitterShape.h"

class ParticleSystem
{
private:
	std::list<ParticleObject*> m_particleList;
	std::list<ParticleAffector*> m_affectorList;

	ParticleObject* newParticle		= nullptr;
	ParticleAffector* newAffector	= nullptr;

	Vector2 m_position;
	float emissionRate;
	float emissionCount;
	Sprite* m_sprite				= nullptr;

	ParticleAffectorColor* m_colorAffector		= nullptr;
	ParticleAffectorScale* m_scaleAffector		= nullptr;
	ParticleAffectorRotate* m_rotateAffector	= nullptr;
	ParticleAffectorGravity* m_gravityAffector	= nullptr;

	EmitterShape* m_shape			= nullptr;

public:
	ParticleSystem();
	ParticleSystem(const Vector2& newPos, float newRate, Sprite* newSprite);
	~ParticleSystem();

	void Update(float deltaTime);
	void Draw();
	void addAffector(ParticleAffector* newAffector);
};

#endif