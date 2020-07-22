#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "ParticleSystem.h"
#include "util/ScreenRes.h"

class Player : public GameObject
{
private:
	ParticleSystem* m_trail = nullptr;
public:
	Player(Vector2 newPos, Sprite* newSprite, ParticleSystem* newParticles);
	~Player();

	void Update(GLFWwindow* window, float DeltaTime) override;
	void Draw() override;
};

#endif