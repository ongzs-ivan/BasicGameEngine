#include "ParticleAffectorGravity.h"

ParticleAffectorGravity::ParticleAffectorGravity(const Vector2 Start, const Vector2 End)
{
	accStart = Start;
	accEnd = End;
	accUpdate = Vector2(0.0f, 0.0f);
}

void ParticleAffectorGravity::affectParticleUpdate(ParticleObject* particle)
{
	percentage = particle->m_life / particle->m_lifeMax;

	accUpdate.X = Lerp(accStart.X, accEnd.X, percentage);
	accUpdate.Y = Lerp(accStart.Y, accEnd.Y, percentage);

	particle->setAccel(accUpdate);
}