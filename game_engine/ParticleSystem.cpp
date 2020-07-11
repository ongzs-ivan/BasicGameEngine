#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	Position = Vector2(0, 0);
	EmissionRate = 0;
	EmissionCount = 0;
	ParticleSprite = nullptr;
}

ParticleSystem::ParticleSystem(const Vector2& DesiredPosition, float DesiredEmissionRate, Sprite* DesiredSprite)
{
	Position = DesiredPosition;
	EmissionRate = DesiredEmissionRate;
	EmissionCount = 0;
	ParticleSprite = DesiredSprite;
}

ParticleSystem::~ParticleSystem()
{
}

void ParticleSystem::Update(float DeltaTime)
{
	// color, scale, rotate, point gravity affectors
	Vector2 RandVelocity;
	float RandLifetime;
	// Check if it needs to create a new particle
	if (EmissionCount >= EmissionRate)
	{
		RandVelocity = Vector2(rand() % 200 - 100, rand() % 200 - 100);
		RandLifetime = rand() % 2 + 0.5;
		ParticleObject* NewParticle = new ParticleObject(ParticleSprite, RandVelocity, Vector2(0, -150), RandLifetime);
		NewParticle->SetPosition(Position);
		NewParticle->SetScale(Vector2(3.25f, 3.25f));
		NewParticle->SetColor(&Color::White);
		NewParticle->SetBlendMode(ADDITIVE);

		ParticleList.push_back(NewParticle);
		EmissionCount = 0;
	}
	else
	{
		EmissionCount += DeltaTime;
	}


	// Update the particles' movement
	std::list<ParticleObject*>::iterator iter = ParticleList.begin();
	while (iter != ParticleList.end())
	{
		ParticleObject* TempParticle = *iter;
		ParticleAffectorColor AffectorColor(TempParticle->GetColor(), &Color::Blue);
		ParticleAffectorScale AffectorScale(TempParticle->GetScale(), Vector2(0.f, 0.f));
		TempParticle->Update(DeltaTime);
		AffectorColor.AffectParticleUpdate(DeltaTime, TempParticle);
		AffectorScale.AffectParticleUpdate(DeltaTime, TempParticle);


		if (TempParticle->CurrentLifetime <= 0)
		{
			delete TempParticle;
			iter = ParticleList.erase(iter);
		}
		else
		{
			iter++;
		}

	}
}

void ParticleSystem::Draw()
{
	std::list<ParticleObject*>::iterator iter = ParticleList.begin();
	while (iter != ParticleList.end())
	{
		ParticleObject* TempParticle = *iter;
		TempParticle->Draw();
		iter++;
	}
}
