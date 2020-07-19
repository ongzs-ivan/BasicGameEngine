#include <GLFW/glfw3.h>
#include <Windows.h>
#include <gl/GLU.h>
#include <stdlib.h>

// Fmodex library
//#include <fmod.hpp>
//#include <fmod_errors.h>

#include <iostream>
#include <ctime>
//#include <chrono>

#include "Application.h"
#include "util/ScreenRes.h"

int ScreenRes::screenWidth = 1280;
int ScreenRes::screenHeight = 800;

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



int main(void)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(ScreenRes::screenWidth, ScreenRes::screenHeight, "Hello World", NULL, NULL);
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
		App.Update(DeltaTime);
		App.Draw();

		// Renders everything into the window
		glfwSwapBuffers(window);

		// Checks for keyboard/mouse input
		glfwPollEvents();


	}

	glfwTerminate();
	return 0;
}