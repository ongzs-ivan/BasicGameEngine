#include "SquareEmitterShape.h"

SquareEmitterShape::SquareEmitterShape(float initialWidth, float initialHeight)
{
	halfWidth = initialWidth / 2;
	halfHeight = initialHeight / 2;
}

/// <summary>
/// Sets the size of the emitter according to the input size.
/// </summary>
/// <param name="newWidth"></param> Half of the squares width
/// <param name="newHeight"></param> Half of the squares height
void SquareEmitterShape::setSquareSize(float newWidth, float newHeight)
{
	halfWidth = newWidth / 2;
	halfHeight = newHeight / 2;
}

/// <summary>
/// Returns a randomized Vector location in the emitter's shape.
/// </summary>
Vector2 SquareEmitterShape::getParticleEmissionPos(Vector2* particleSystemPos)
{
	xPos = particleSystemPos->X + RandomNumber(-halfWidth, halfWidth);
	yPos = particleSystemPos->Y + RandomNumber(-halfHeight, halfHeight);

	return Vector2(float(xPos), float(yPos));
}