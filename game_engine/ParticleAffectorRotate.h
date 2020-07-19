#ifndef PARTICLEAFFECTORROTATE_H
#define PARTICLEAFFECTORROTATE_H

#include "ParticleAffector.h"

class ParticleAffectorRotate : public ParticleAffector
{
protected:
	float rotateStart;
	float rotateEnd;
	float rotateUpdate;

public:
	ParticleAffectorRotate(const float& Start, const float& End);
	void affectParticleUpdate(ParticleObject* particle) override;
};

#endif