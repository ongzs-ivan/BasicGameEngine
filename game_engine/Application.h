#ifndef APPLICATION_H
#define APPLICATION_H

#include <GLFW/glfw3.h>
#include "ParticleSystem.h"
#include "util/ScreenRes.h"

class Application
{
private:
	Sprite* sprite1;
	Sprite* sprite2;
	Sprite* sprite3;
	Sprite* background;

	GameObject* bg;

	ParticleSystem* particleSystem1;
	ParticleSystem* particleSystem2;
	ParticleSystem* particleSystem3;



public:
	Application();
	~Application();


	void Start();
	void Update(GLFWwindow* window, float DeltaTime);
	void Draw();
};

#endif