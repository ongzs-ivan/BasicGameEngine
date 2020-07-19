#include "ParticleAffectorRotate.h"

ParticleAffectorRotate::ParticleAffectorRotate(const float& Start, const float& End)
{
	rotateStart = Start;
	rotateEnd = End;
	rotateUpdate = 0;
}

void ParticleAffectorRotate::affectParticleUpdate(ParticleObject* particle)
{
	percentage = particle->m_life / particle->m_lifeMax;

	rotateUpdate = Lerp(rotateStart, rotateEnd, percentage);

	particle->setRotation(rotateUpdate);
}