#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	m_position = Vector2(0, 0);
	emissionRate = 0;
	emissionCount = 0;
	m_sprite = nullptr;

	m_colorAffector = nullptr;
	m_scaleAffector = nullptr;
	m_rotateAffector = nullptr;
}

ParticleSystem::ParticleSystem(const Vector2& newPos, float newRate, Sprite* newSprite)
{
	m_position = newPos;
	emissionRate = newRate;
	emissionCount = 0;
	m_sprite = newSprite;

	m_colorAffector = nullptr;
	m_scaleAffector = nullptr;
	m_rotateAffector = nullptr;
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::Update(float deltaTime)
{
	Vector2 newVel;
	float newLife;

	// update particle count
	if (emissionCount >= emissionRate)
	{
		newVel = Vector2(rand() % 200 - 100, rand() % 200 - 100);
		newLife = rand() % 2 + 2;
		ParticleObject* NewParticle = new ParticleObject(m_sprite, newVel, newLife);
		NewParticle->setPosition(m_position);
		NewParticle->setScale(Vector2(0.25f, 0.25f));
		NewParticle->setColor(Color::White);
		NewParticle->setBlendMode(BlendingMode::Add);
		NewParticle->setAccel(Vector2(0.0f, -9.81f)); // temp gravity

		m_colorAffector = new ParticleAffectorColor(NewParticle->getColor(), Color::Black);
		m_scaleAffector = new ParticleAffectorScale(NewParticle->getScale(), Vector2(0.01f, 0.01f));
		m_rotateAffector = new ParticleAffectorRotate(NewParticle->getRotation(), 270.0f);
		// gravity affector

		m_particleList.push_back(NewParticle);
		emissionCount = 0;
	}
	else
	{
		emissionCount += deltaTime;
	}

	// update each particle
	std::list<ParticleObject*>::iterator iter = m_particleList.begin();
	while (iter != m_particleList.end())
	{
		ParticleObject* TempParticle = *iter;
		TempParticle->Update(deltaTime);
		m_colorAffector->affectParticleUpdate(TempParticle);
		m_scaleAffector->affectParticleUpdate(TempParticle);
		m_rotateAffector->affectParticleUpdate(TempParticle);
		//gravity affector


		if (TempParticle->m_life >= TempParticle->m_lifeMax)
		{
			delete TempParticle;
			iter = m_particleList.erase(iter);
		}
		else
		{
			iter++;
		}

	}
}

void ParticleSystem::Draw()
{
	std::list<ParticleObject*>::iterator iter = m_particleList.begin();
	while (iter != m_particleList.end())
	{
		ParticleObject* TempParticle = *iter;
		TempParticle->Draw();
		iter++;
	}
}
