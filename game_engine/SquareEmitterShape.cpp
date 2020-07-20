#include "SquareEmitterShape.h"

SquareEmitterShape::SquareEmitterShape(float initialWidth, float initialHeight)
{
	halfWidth = initialWidth / 2;
	halfHeight = initialHeight / 2;
}

void SquareEmitterShape::setSquareSize(float newWidth, float newHeight)
{
	halfWidth = newWidth / 2;
	halfHeight = newHeight / 2;
}

Vector2 SquareEmitterShape::getParticleEmissionPos(Vector2* particleSystemPos)
{
	xPos = particleSystemPos->X + RandomNumber(-halfWidth, halfWidth);
	yPos = particleSystemPos->X + RandomNumber(-halfHeight, halfHeight);

	return Vector2(float(xPos), float(yPos));
}