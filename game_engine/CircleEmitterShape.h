#ifndef CIRCLEEMITTERSHAPE_H
#define CIRCLEMITTERSHAPE_H

#include "EmitterShape.h"

class CircleEmitterShape : public EmitterShape
{
private:
	float radius;
public:
	CircleEmitterShape(float initialSize);
	void setCircleSize(float size);
	Vector2 getParticleEmissionPos(Vector2* particleSystemPos) override;
};

#endif
