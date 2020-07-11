#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include "GameObject.h"
#include "ParticleObject.h"
#include "ParticleSystem.h"
#include "Sprite.h"

class Application
{
private:
	Sprite* Sprite1;
	Sprite* Sprite2;
	Sprite* m_dummySprite1;
	Sprite* m_dummySprite2;
	GameObject* TestObject1;
	GameObject* TestObject2;
	GameObject* TestObject3;
	GameObject* TestObject4;
	ParticleObject* TestParticle;
	ParticleSystem* TestSystem;

	float RotationOverTime = 0.f;

public:
	Application();
	~Application();


	void Start();
	void Update(float DeltaTime);
	void Draw();
};