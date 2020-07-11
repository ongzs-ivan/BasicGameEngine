#include "Application.h"

Application::Application()
{
	sprite1 = nullptr;
	sprite2 = nullptr;

	particleSystem1 = nullptr;
}

Application::~Application()
{

}

void Application::Start()
{
	std::cout << "Application started\n";
	sprite1 = new Sprite("../media/star.bmp");
	sprite2 = new Sprite("../media/explosion.bmp");

	particleSystem1 = new ParticleSystem(Vector2(320, 320), 0.01f, sprite1);
}

void Application::Update(float DeltaTime)
{
	RotationOverTime += DeltaTime;
	//TestObject1->SetRotation(25 * RotationOverTime);
	//TestObject2->SetScale(Vector2(sin(RotationOverTime) * 1.5f, sin(RotationOverTime) + 1.5f));

	particleSystem1->Update(DeltaTime);
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	particleSystem1->Draw();
}