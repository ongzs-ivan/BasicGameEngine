#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <list>
#include "ParticleObject.h"
#include "ParticleAffectorColor.h"
#include "ParticleAffectorScale.h"

class ParticleSystem
{
private:
	std::list<ParticleObject*> ParticleList;
	Vector2 Position;
	float EmissionRate;
	float EmissionCount;
	Sprite* ParticleSprite;

public:
	ParticleSystem();
	ParticleSystem(const Vector2& DesiredPosition, float DesiredEmissionRate, Sprite* DesiredSprite);
	~ParticleSystem();

	void Update(float DeltaTime);
	void Draw();
};

#endif