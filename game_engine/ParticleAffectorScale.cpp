#include "ParticleAffectorScale.h"

ParticleAffectorScale::ParticleAffectorScale(const Vector2& Start, const Vector2& End)
{
	scaleStart = Start;
	scaleEnd = End;
	scaleUpdate = Vector2(0.0f, 0.0f);
}

void ParticleAffectorScale::setNewValues(Vector2 newStart, Vector2 newEnd)
{
	scaleStart = newStart;
	scaleEnd = newEnd;
}

/// <summary>
/// Updates the particles color to its target scale. Transition rate is affected by how much lifespan it has left.
/// </summary>
void ParticleAffectorScale::affectParticleUpdate(ParticleObject* particle)
{
	percentage = particle->m_life / particle->m_lifeMax;

	scaleUpdate.X = Lerp(scaleStart.X, scaleEnd.X, percentage);
	scaleUpdate.Y = Lerp(scaleStart.Y, scaleEnd.Y, percentage);

	particle->setScale(scaleUpdate);
}
