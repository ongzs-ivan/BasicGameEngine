#include "ParticleAffectorGravity.h"

ParticleAffectorGravity::ParticleAffectorGravity(const Vector2 Start, const Vector2 End)
{
	accStart = Start;
	accEnd = End;
	accUpdate = Vector2(0.0f, 0.0f);
}

void ParticleAffectorGravity::setNewValues(Vector2 newStart, Vector2 newEnd)
{
	accStart = newStart;
	accEnd = newEnd;
}

/// <summary>
/// Updates the particles acceleration to a target acceeleration. Transition rate is affected by how much lifespan it has left.
/// </summary>
void ParticleAffectorGravity::affectParticleUpdate(ParticleObject* particle)
{
	percentage = particle->m_life / particle->m_lifeMax;

	accUpdate.X = Lerp(accStart.X, accEnd.X, percentage);
	accUpdate.Y = Lerp(accStart.Y, accEnd.Y, percentage);

	particle->setAccel(accUpdate);
}