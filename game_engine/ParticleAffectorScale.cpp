#include "ParticleAffectorScale.h"

void ParticleAffectorScale::LerpScale(float DeltaTime, float StartScaleValue, float EndScaleValue, float& CurrentScaleValue)
{
	if (StartScaleValue < EndScaleValue && CurrentScaleValue < EndScaleValue)
		CurrentScaleValue += DeltaTime;
	else if (StartScaleValue > EndScaleValue && CurrentScaleValue > EndScaleValue)
		CurrentScaleValue -= DeltaTime;
}

ParticleAffectorScale::ParticleAffectorScale(const Vector2& Start, const Vector2& End)
{
	StartScale = Start;
	EndScale = End;
}

void ParticleAffectorScale::AffectParticleUpdate(float DeltaTime, ParticleObject* Particle)
{
	Vector2 CurrentScale = Particle->getScale();

	float ParticleDeltaTime = DeltaTime / Particle->MaxLifetime;

	LerpScale(ParticleDeltaTime, StartScale.X, EndScale.X, CurrentScale.X);
	LerpScale(ParticleDeltaTime, StartScale.Y, EndScale.Y, CurrentScale.Y);

	Particle->setScale(CurrentScale);
}
