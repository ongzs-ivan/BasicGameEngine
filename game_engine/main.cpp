#include <GLFW/glfw3.h>
#include <Windows.h>
#include <gl/GLU.h>
#include <stdlib.h>

// Fmodex library
#include <fmod.hpp>
#include <fmod_errors.h>

#include <iostream>
#include <ctime>
#include <chrono>

#include "Application.h"
#include "util/ScreenRes.h"

int ScreenRes::screenWidth = 1280;
int ScreenRes::screenHeight = 800;

FMOD::System* m_fmodSystem;
FMOD::Sound* m_music;
FMOD::Channel* m_musicChannel;

void OnWindowResized(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Use ortho 2D view
	gluOrtho2D(0, width, 0, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void ERRCHECK(FMOD_RESULT result)
{
	if (result != FMOD_OK)
	{
		printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
	}
}

void initFmod()
{
	FMOD_RESULT result;
	unsigned int version;

	result = FMOD::System_Create(&m_fmodSystem);
	ERRCHECK(result);

	result = m_fmodSystem->getVersion(&version);
	ERRCHECK(result);

	if (version < FMOD_VERSION)
		printf("FMOD Error! You are using an old version of FMOD.", version, FMOD_VERSION);

	// initialize fmod system
	result = m_fmodSystem->init(32, FMOD_INIT_NORMAL, 0);
	ERRCHECK(result);

	// load and set up music
	result = m_fmodSystem->createStream("../media/ISAJI - Yaranaika.mp3", FMOD_SOFTWARE, 0, &m_music);
	ERRCHECK(result);

	// play the loaded mp3 music
	result = m_fmodSystem->playSound(FMOD_CHANNEL_FREE, m_music, false, &m_musicChannel);
	ERRCHECK(result);

	// set sound channel loop count
	m_musicChannel->setLoopCount(0);

	// set sound volume
	m_musicChannel->setVolume(0.25f);
}	

void updateFmod()
{
	m_fmodSystem->update();
}

int main(void)
{ 
	srand(time(NULL));

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(ScreenRes::screenWidth, ScreenRes::screenHeight, "Yaranaika?", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowSizeCallback(window, OnWindowResized);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	OnWindowResized(window, ScreenRes::screenWidth, ScreenRes::screenHeight);

	//Matrix matrix(Matrix::makeIdentityMatrix());
	
	initFmod();
	Application App;
	App.Start();

	glfwSwapInterval(0); //enable/disable vsync

	double LastFrameTime = glfwGetTime();
	double MaxFPS = 60.00;
	double MinDeltaTime = 1.0 / MaxFPS;


	//game loop
	while (!glfwWindowShouldClose(window))
	{
		// Begin render
		glClear(GL_COLOR_BUFFER_BIT);

		double ThisFrameTime = glfwGetTime();
		double DeltaTime = ThisFrameTime - LastFrameTime;

		//============================================================
		int MinSleepTimeTH = 10;
		// Gets the system to sleep
		int SleepTime = (MinDeltaTime - DeltaTime) * 1000 - MinSleepTimeTH;
		if (SleepTime >= MinSleepTimeTH)
			Sleep(SleepTime);

		// loop to "waste" extra cpu cycles
		while (DeltaTime < MinDeltaTime)
			DeltaTime = glfwGetTime() - LastFrameTime;
		//============================================================

		LastFrameTime = glfwGetTime();

		float FPS = 1.0 / DeltaTime;
		char str[32];
		sprintf_s(str, "%f, %f", FPS, (float)DeltaTime);
		glfwSetWindowTitle(window, str);

		//update(DeltaTime);
		App.Update(window, DeltaTime);
		App.Draw();
		updateFmod();

		if (glfwGetKey(window, GLFW_KEY_ESCAPE))
			break;

		// Renders everything into the window
		glfwSwapBuffers(window);

		// Checks for keyboard/mouse input
		glfwPollEvents();


	}

	glfwTerminate();
	return 0;
}