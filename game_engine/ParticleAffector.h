#ifndef PARTICLEAFFECTOR_H
#define PARTICLEAFFECTOR_H

#include "ParticleObject.h"

class ParticleAffector
{
protected:
	float percentage;

	// lerp function, a = start, b = end, t = interpolation value
	float Lerp(float a, float b, float t) { return a + t * (b - a); };
public:
	// This method is called from the particle system
	virtual void affectParticleUpdate(ParticleObject* particle) = 0;
};

#endif