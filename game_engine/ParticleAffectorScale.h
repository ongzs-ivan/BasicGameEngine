#pragma once
#include "ParticleAffector.h"

class ParticleAffectorScale :
    public ParticleAffector
{
protected:
    Vector2 StartScale;
    Vector2 EndScale;
    void LerpScale(float DeltaTime, float StartScaleValue, float EndScaleValue, float& CurrentScaleValue);

public:
    ParticleAffectorScale(const Vector2& Start, const Vector2& End);
    void AffectParticleUpdate(float DeltaTime, ParticleObject* Particle) override;
};

