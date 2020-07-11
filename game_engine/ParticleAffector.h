#pragma once
#include "ParticleObject.h"

class ParticleAffector
{
public:
	virtual void AffectParticleUpdate(float DeltaTime, ParticleObject* Particle) = 0;
};
	