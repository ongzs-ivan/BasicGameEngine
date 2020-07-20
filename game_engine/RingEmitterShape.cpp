#include "RingEmitterShape.h"

RingEmitterShape::RingEmitterShape(float initialInner, float initialOuter)
{
	innerRadius = initialInner;
	outerRadius = initialOuter;
}

void RingEmitterShape::setRingSize(float newInner, float newOuter)
{
	innerRadius = newInner;
	outerRadius = newOuter;
}

Vector2 RingEmitterShape::getParticleEmissionPos(Vector2* particleSystemPos)
{
	angle = 2 * M_PI * RandomNumber();
	r = outerRadius * sqrt(RandomNumber());

	xPos = (r * cos(angle));
	yPos = (r * sin(angle));

	Vector temp = Vector(xPos, yPos, 0.0f);
	float length = temp.length();
	temp.normalize();

	xPos = particleSystemPos->X + temp.mVal[0] * (RandomNumber(innerRadius, outerRadius));
	yPos = particleSystemPos->Y + temp.mVal[1] * (RandomNumber(innerRadius, outerRadius));

	// spawn location test
	//std::cout << "Spawned at: " << randomizedX << ", " << randomizedY << std::endl;
	return Vector2(float(xPos), float(yPos));
}