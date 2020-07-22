#include "Application.h"

Application::Application()
{
	sprite1 = nullptr;
	sprite2 = nullptr;
	sprite3 = nullptr;
	sprite4 = nullptr;
	background = nullptr;

	bg = nullptr;
	player = nullptr;

	particleSystem1 = nullptr;
	particleSystem2 = nullptr;
	particleSystem3 = nullptr;

}

Application::~Application()
{

}

/// <summary>
/// Initializes the sprites, game objects and particle systems. Sets up what will be rendered into the screen. 
/// </summary>
void Application::Start()
{
	std::cout << "Application started.\n";
	sprite1 = new Sprite("../media/star.bmp");		// player trail
	sprite2 = new Sprite("../media/flare_1.bmp");	// random flares
	sprite3 = new Sprite("../media/drill.bmp");		// player sprite
	sprite4 = new Sprite("../media/galaxy.bmp");
	background = new Sprite("../media/bg.bmp");		// background picture

	bg = new GameObject(background);
	bg->setPosition(Vector2(ScreenRes::screenWidth/2,ScreenRes::screenHeight/2));

	particleSystem1 = new ParticleSystem(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), 0.2f, sprite1);
	particleSystem2 = new ParticleSystem(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), 0.5f, sprite2);
	particleSystem3 = new ParticleSystem(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), 2.0f, sprite4);

	player = new Player(Vector2(ScreenRes::screenWidth / 2, ScreenRes::screenHeight / 2), sprite3, particleSystem1);
	player->setScale(Vector2(0.5f, 0.5f));
	player->setColor(Color::White);
	player->setBlendMode(BlendingMode::Add);

	particleSystem1->setEmitterType(new SquareEmitterShape(32.0f, 32.0f));
	particleSystem2->setEmitterType(new CircleEmitterShape(250.0f));
	particleSystem3->setEmitterType(new RingEmitterShape(350.0f, 400.0f));

	particleSystem1->setParticleInfo(Color(0.2f, 0.5f, 0.5f, 1.0f), Vector2(0.75f, 0.75f), Vector2(rand()% 200 - 100, rand()% 150 - 100), Vector2(0.0f, -9.81f), 0.0f);
	particleSystem1->setAffectorInfo(Color::Black, Vector2(0.25f, 0.25f), Vector2(rand() % 200 - 100, rand() % 150 - 100),Vector2(0.0f, -100.0f), 90.0f);

	particleSystem2->setParticleInfo(Color::Yellow, Vector2(1.0f, 1.0f), Vector2(rand() % 50 - 10, rand() % 50 - 10), Vector2(0.0f, -9.81f), 0.0f);
	particleSystem2->setAffectorInfo(Color(0.2f, 0.5f, 0.5f, 1.0f), Vector2(0.5f, 0.5f), Vector2(rand() % 70 - 50, rand() % 70 - 50), Vector2(0.0f, -100.0f), float(rand()%180 + 90));

	particleSystem3->setParticleInfo(Color::White, Vector2(1.0f, 1.0f), Vector2(rand() % 20 - 10, rand() % 20 - 10), Vector2(0.0f, -9.81f), 0.0f);
	particleSystem3->setAffectorInfo(Color::Black, Vector2(0.8f, 0.8f), Vector2(rand() % 30 - 20, rand() % 30 - 20), Vector2(0.0f, -20.0f), float(rand() % 360 - 180));

}

/// <summary>
/// Updates the positions and variables in all the game objects and particle systems.
/// </summary>
void Application::Update(GLFWwindow* window, float DeltaTime)
{
	particleSystem2->Update(DeltaTime);
	particleSystem3->Update(DeltaTime);
	player->Update(window, DeltaTime);

}

/// <summary>
/// Renders the sprites of the particle systems and game objects according to their updated values
/// </summary>
void Application::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	bg->Draw();
	particleSystem2->Draw();
	particleSystem3->Draw();
	player->Draw();
}