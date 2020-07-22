#include "ParticleAffectorColor.h"

ParticleAffectorColor::ParticleAffectorColor(const Color& Start, const Color& End)
{
	colorStart = Start;
	colorEnd = End;
	colorUpdate = Color::White;
}

/// <summary>
/// Updates the particles color to its target color. Transition rate is affected by how much lifespan it has left.
/// </summary>
void ParticleAffectorColor::affectParticleUpdate(ParticleObject* particle)
{
	percentage = particle->m_life / particle->m_lifeMax;

	colorUpdate.R = Lerp(colorStart.R, colorEnd.R, percentage);
	colorUpdate.G = Lerp(colorStart.G, colorEnd.G, percentage);
	colorUpdate.B = Lerp(colorStart.B, colorEnd.B, percentage);
	colorUpdate.A = Lerp(colorStart.A, colorEnd.A, percentage);

	particle->setColor(colorUpdate);
}
