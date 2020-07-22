#ifndef PARTICLEAFFECTORCOLOR_H
#define PARTICLEAFFECTORCOLOR_H

#include "ParticleAffector.h"

class ParticleAffectorColor : public ParticleAffector
{
protected:
    Color colorStart;
    Color colorEnd;
    Color colorUpdate;

public:
    ParticleAffectorColor(const Color& Start, const Color& End);
    void setNewValues(Color newStart, Color newEnd);
    void affectParticleUpdate(ParticleObject* particle) override;
    
};

#endif