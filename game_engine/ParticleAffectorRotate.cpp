#include "ParticleAffectorRotate.h"

ParticleAffectorRotate::ParticleAffectorRotate(const float& Start, const float& End)
{
	rotateStart = Start;
	rotateEnd = End;
	rotateUpdate = 0;
}
/// <summary>
/// Updates the particles color to its target rotation. Transition rate is affected by how much lifespan it has left.
/// </summary>
void ParticleAffectorRotate::affectParticleUpdate(ParticleObject* particle)
{
	percentage = particle->m_life / particle->m_lifeMax;

	rotateUpdate = Lerp(rotateStart, rotateEnd, percentage);

	particle->setRotation(rotateUpdate);
}