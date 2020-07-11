#ifndef APPLICATION_H
#define APPLICATION_H

#include <GLFW/glfw3.h>
#include "ParticleSystem.h"

class Application
{
private:
	Sprite* sprite1;
	Sprite* sprite2;

	ParticleSystem* particleSystem1;

	float RotationOverTime = 0.f;

public:
	Application();
	~Application();


	void Start();
	void Update(float DeltaTime);
	void Draw();
};

#endif