#ifndef PARTICLEAFFECTOR_H
#define PARTICLEAFFECTOR_H

#include "ParticleObject.h"

class ParticleAffector
{
public:
	virtual void AffectParticleUpdate(float DeltaTime, ParticleObject* Particle) = 0;
};

#endif