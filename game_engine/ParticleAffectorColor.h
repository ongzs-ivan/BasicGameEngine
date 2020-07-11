#pragma once
#include "ParticleAffector.h"

class ParticleAffectorColor :
    public ParticleAffector
{
protected:
    Color* StartColor;
    Color* EndColor;
    void LerpColor(float DeltaTime, float StartColorChannel, float EndColorChannel, float& CurrentColorChannel);

public:
    ParticleAffectorColor(Color* Start, Color* End);
    void AffectParticleUpdate(float DeltaTime, ParticleObject* Particle) override;

};

