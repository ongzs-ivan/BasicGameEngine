#include "ParticleAffectorColor.h"

#define OUT

void ParticleAffectorColor::LerpColor(float DeltaTime, float StartColorChannel, float EndColorChannel, float& CurrentColorChannel)
{
	if (StartColorChannel < EndColorChannel && CurrentColorChannel < EndColorChannel)
		CurrentColorChannel += DeltaTime;
	else if (StartColorChannel > EndColorChannel && CurrentColorChannel > EndColorChannel)
		CurrentColorChannel -= DeltaTime;
}

ParticleAffectorColor::ParticleAffectorColor(Color* Start, Color* End)
{
	StartColor = Start;
	EndColor = End;
}

void ParticleAffectorColor::AffectParticleUpdate(float DeltaTime, ParticleObject* Particle)
{
	Color CurrentColor = *Particle->getColor();

	float ParticleDeltaTime = DeltaTime / Particle->MaxLifetime;

	LerpColor(ParticleDeltaTime, StartColor->R, EndColor->R, OUT CurrentColor.R);
	LerpColor(ParticleDeltaTime, StartColor->G, EndColor->G, OUT CurrentColor.G);
	LerpColor(ParticleDeltaTime, StartColor->B, EndColor->B, OUT CurrentColor.B);
	LerpColor(ParticleDeltaTime, StartColor->A, EndColor->A, OUT CurrentColor.A);

	Color* NewColor = new Color(CurrentColor.R, CurrentColor.G, CurrentColor.B, CurrentColor.A);

	Particle->setColor(NewColor);
}
