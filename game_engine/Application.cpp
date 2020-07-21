#include "Application.h"

Application::Application()
{
	sprite1 = nullptr;
	sprite2 = nullptr;
	sprite3 = nullptr;
	background = nullptr;

	bg = nullptr;

	particleSystem1 = nullptr;
	particleSystem2 = nullptr;
	particleSystem3 = nullptr;

}

Application::~Application()
{

}

void Application::Start()
{
	std::cout << "Yaranaika?\n";
	sprite1 = new Sprite("../media/yaranaika.bmp");
	sprite2 = new Sprite("../media/star.bmp");
	sprite3 = new Sprite("../media/yaranaika2.bmp");
	background = new Sprite("../media/yaranaika_wp.bmp");

	bg = new GameObject(background);
	bg->setPosition(Vector2(ScreenRes::screenWidth/2,ScreenRes::screenHeight/2));
	bg->setColor(Color(0.5f, 0.5f, 0.5f, 0.5f));

	particleSystem1 = new ParticleSystem(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), 2.0f, sprite3);
	particleSystem2 = new ParticleSystem(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), 0.5f, sprite2);
	particleSystem3 = new ParticleSystem(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), 0.2f, sprite1);

	particleSystem1->setEmitterType(new RingEmitterShape(375.0f, 400.0f));
	particleSystem2->setEmitterType(new CircleEmitterShape(250.0f));
	particleSystem3->setEmitterType(new SquareEmitterShape(25.0f, 25.0f));

	particleSystem2->setParticleInfo(Color::Red, Vector2(0.75f, 0.75f), Vector2(0.0f, -9.81f), 0.0f);
	particleSystem2->setAffectorInfo(Color::Green, Vector2(0.25f, 0.25f), Vector2(0.0f, -100.0f), 180);

	particleSystem3->setParticleInfo(Color::White, Vector2(0.75f, 0.75f), Vector2(0.0f, -9.81f), 0.0f);
	particleSystem3->setAffectorInfo(Color(0.5f, 0.5f, 0.5f, 0.5f), Vector2(0.25f, 0.25f), Vector2(0.0f, -200.0f), float(rand() % 360 + 360));

}

void Application::Update(GLFWwindow* window, float DeltaTime)
{
	bg->Update(DeltaTime);
	particleSystem1->Update(DeltaTime);
	particleSystem2->Update(DeltaTime);
	particleSystem3->Update(DeltaTime);

	if (glfwGetKey(window, 'A')) particleSystem3->m_position.X -= 10.0f;
	if (glfwGetKey(window, 'D')) particleSystem3->m_position.X += 10.0f;
	if (glfwGetKey(window, 'W')) particleSystem3->m_position.Y += 10.0f;
	if (glfwGetKey(window, 'S')) particleSystem3->m_position.Y -= 10.0f;

	if (particleSystem3->m_position.X < 0) 
		particleSystem3->m_position.X = 0.0f;
	if (particleSystem3->m_position.X > ScreenRes::screenWidth) 
		particleSystem3->m_position.X = ScreenRes::screenWidth;
	if (particleSystem3->m_position.Y < 0) 
		particleSystem3->m_position.Y = 0.0f;
	if (particleSystem3->m_position.Y > ScreenRes::screenHeight) 
		particleSystem3->m_position.Y = ScreenRes::screenHeight;
}

void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	bg->Draw();
	particleSystem1->Draw();
	particleSystem2->Draw();
	particleSystem3->Draw();
}