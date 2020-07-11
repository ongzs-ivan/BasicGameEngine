#include "Application.h"

Application::Application()
{
	Sprite1 = nullptr;
	Sprite2 = nullptr;

	TestObject1 = nullptr;
	TestObject2 = nullptr;
	TestObject3 = nullptr;
	TestObject4 = nullptr;

	TestParticle = nullptr;
	TestSystem = nullptr;
}

Application::~Application()
{

}

void Application::Start()
{
	std::cout << "Application started\n";
	Sprite1 = new Sprite("../media/star.bmp");
	Sprite2 = new Sprite("../media/explosion.bmp");
	//m_dummySprite2 = new Sprite();
	//TestObject1 = new GameObject(Vector2(420, 240), 70, Vector2(1, 1), m_dummySprite, new Color(1.0f, 1.0f, 1.0f, 1.0f), NORMAL);
	//TestObject2 = new GameObject(Vector2(320, 240), 40, Vector2(1, 1), m_dummySprite2, new Color(1.0f, 1.0f, 1.0f, 1.0f), ADDITIVE);
	//TestObject3 = new GameObject(Vector2(220, 240), 70, Vector2(1, 1), m_dummySprite, new Color(0.0f, 1.0f, 1.0f, 1.0f), MULTIPLY);
	//TestObject4 = new GameObject(Vector2(520, 240), 70, Vector2(1, 1), m_dummySprite2, Color(1.0f, 1.0f, 1.0f, 1.0f), NORMAL);


	//TestObject1 = new GameObject(Sprite1);
	//TestObject1->SetPosition(Vector2(420, 240));
	//TestObject1->SetRotation(45.f);
	//TestObject1->SetScale(Vector2(0.75f, 1.f));
	//
	//TestObject2 = new GameObject(Sprite1);
	//TestObject2->SetColor(new Color(0.5f, 0.5f, 0.5f, 1.0f));
	//TestObject2->SetBlendMode(ADDITIVE);

	//TestParticle = new ParticleObject(Sprite1, Vector2(50.f, 50.f), Vector2(50.f, 50.f), 5.f);
	//TestParticle->SetPosition(Vector2(320, 240));
	//TestParticle->SetRotation(45.f);
	//TestParticle->SetScale(Vector2(1.f, 1.f));
	//TestParticle->SetColor(new Color(1.0f, 1.0f, 1.0f, 1.0f));
	//TestParticle->SetBlendMode(ADDITIVE);

	TestSystem = new ParticleSystem(Vector2(320, 320), 0.01f, Sprite1);
}

void Application::Update(float DeltaTime)
{
	RotationOverTime += DeltaTime;
	//TestObject1->SetRotation(25 * RotationOverTime);
	//TestObject2->SetScale(Vector2(sin(RotationOverTime) * 1.5f, sin(RotationOverTime) + 1.5f));

	//TestParticle->Update(DeltaTime);
	TestSystem->Update(DeltaTime);
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//TestObject1->Draw();
	//TestObject2->Draw();
	//TestParticle->Draw();
	TestSystem->Draw();
}