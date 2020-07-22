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

	Sprite* m_sprite = nullptr;


	Color particleColorI;
	Color particleColorF;
	Vector2 particleScaleI;
	Vector2 particleScaleF;
	float particleRotationI;
	float particleRotationF;
	Vector2 particleVelI;
	Vector2 particleVelF;
	Vector2 particleAccI;
	Vector2 particleAccF;

	float emissionRate = 0;
	float emissionCount = 0;
	float newLife;

	EmitterShape* m_shape = nullptr;
	ParticleAffectorColor* m_colorAffector		= nullptr;
	ParticleAffectorScale* m_scaleAffector		= nullptr;
	ParticleAffectorRotate* m_rotateAffector	= nullptr;
	ParticleAffectorGravity* m_gravityAffector	= nullptr;

	void createNewParticle();

public:
	Vector2 m_position;

	ParticleSystem();
	ParticleSystem(const Vector2& newPos, float newRate, Sprite* newSprite);
	~ParticleSystem();

	void setEmitterType(EmitterShape* newEmitter);
	void setParticleInfo(Color initialColor, Vector2 initialScale, Vector2 initialVel, Vector2 initialAcc, float initialRotation);
	void setAffectorInfo(Color finalColor, Vector2 finalScale, Vector2 finalVel, Vector2 finalAcc, float finalRotation);

	void Update(float deltaTime);
	void Draw();
	void addAffector(ParticleAffector* newAffector);
};

#endif