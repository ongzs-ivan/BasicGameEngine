#include "CircleEmitterShape.h"
#include <cstdlib>

CircleEmitterShape::CircleEmitterShape(float initialSize)
{
	radius = initialSize;
}

void CircleEmitterShape::setCircleSize(float size)
{
	radius = size;
}

Vector2 CircleEmitterShape::getParticleEmissionPos(Vector2* particleSystemPos)
{
	angle = 2 * M_PI * RandomNumber();
	r = radius * sqrt(RandomNumber());
	xPos = particleSystemPos->X + (r * cos(angle));
	yPos = particleSystemPos->Y + (r * sin(angle));

	// spawn location test
	//std::cout << "Spawned at: " << xPos << ", " << yPos << std::endl;
	return Vector2(float(xPos), float(yPos));
}