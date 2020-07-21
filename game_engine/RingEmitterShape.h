#ifndef RINGEMITTERSHAPE_H
#define RINGEMITTERSHAPE_H

#include "EmitterShape.h"
#include "util/vector.h"

class RingEmitterShape : public EmitterShape
{
private:
	double innerRadius, outerRadius;
	Vector temp;
public:
	RingEmitterShape(float initialInner, float initialOuter);
	void setRingSize(float newInner, float newOuter);
	Vector2 getParticleEmissionPos(Vector2* particleSystemPos) override;
};

#endif
