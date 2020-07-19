#ifndef PARTICLEAFFECTORSCALE_H
#define PARTICLEAFFECTORSCALE_H

#include "ParticleAffector.h"

class ParticleAffectorScale : public ParticleAffector
{
protected:
    Vector2 scaleStart;
    Vector2 scaleEnd;
    Vector2 scaleUpdate;

public:
    ParticleAffectorScale(const Vector2& Start, const Vector2& End);
    void affectParticleUpdate(ParticleObject* particle) override;
};

#endif