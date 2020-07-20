#ifndef PARTICLEAFFECTORGRAVITY_H
#define PARTICLEAFFECTORGRAVITY_H

#include "ParticleAffector.h"

class ParticleAffectorGravity : public ParticleAffector
{
protected:
	Vector2 accStart;
	Vector2 accEnd;
	Vector2 accUpdate;

public:
	ParticleAffectorGravity(const Vector2 Start, const Vector2 End);
	void affectParticleUpdate(ParticleObject* particle) override;
};

#endif