#ifndef SQUAREEMITTERSHAPE_H
#define SQUAREEMITTERSHAPE_H

#include "EmitterShape.h"

class SquareEmitterShape : public EmitterShape
{
private:
	float halfWidth;
	float halfHeight;
public:
	SquareEmitterShape(float initialWidth, float initialHeight);
	void setSquareSize(float newWidth, float newHeight);
	Vector2 getParticleEmissionPos(Vector2* particleSystemPos) override;
};

#endif