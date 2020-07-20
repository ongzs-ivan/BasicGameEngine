#include "ParticleSystem.h"

ParticleSystem::ParticleSystem()
{
	m_position = Vector2(0, 0);
	emissionRate = 0;
	emissionCount = 0;
}

ParticleSystem::ParticleSystem(const Vector2& newPos, float newRate, Sprite* newSprite)
{
	m_position = newPos;
	emissionRate = newRate;
	emissionCount = 0;
	m_sprite = newSprite;

	m_shape = new RingEmitterShape(100.0f, 200.0f);
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::Update(float deltaTime)
{
	Vector2 newVel;
	float newLife;

	// update particle count / add new particle + effects
	if (emissionCount >= emissionRate)
	{
		//newVel = Vector2(rand() % 200 - 100, rand() % 200 - 100);
		newVel = Vector2(0.0f, 0.0f);
		//newLife = rand() % 2 + 1;
		newLife = 100.0f;
		newParticle = new ParticleObject(m_sprite, newVel, newLife);
		newParticle->setPosition(m_shape->getParticleEmissionPos(&m_position));
		newParticle->setScale(Vector2(1.0f, 1.0f));
		newParticle->setColor(Color::White);
		newParticle->setBlendMode(BlendingMode::Add);
		//newParticle->setAccel(Vector2(0.0f, -9.81f));

		m_colorAffector = new ParticleAffectorColor(newParticle->getColor(), Color::Black);
		m_scaleAffector = new ParticleAffectorScale(newParticle->getScale(), Vector2(0.25f, 0.25f));
		m_rotateAffector = new ParticleAffectorRotate(newParticle->getRotation(), 450.0f);
		//m_gravityAffector = new ParticleAffectorGravity(newParticle->getAccel(), Vector2(0.0f, -100.0f));

		addAffector(m_colorAffector);
		addAffector(m_scaleAffector);
		addAffector(m_rotateAffector);
		addAffector(m_gravityAffector);

		m_particleList.push_back(newParticle);
		emissionCount = 0;
	}
	else
	{
		emissionCount += deltaTime;
	}

	std::list<ParticleObject*>::iterator iter = m_particleList.begin();

	// update each particle
	while (iter != m_particleList.end())
	{
		ParticleObject* currentParticle = *iter;

		if (currentParticle->m_life >= currentParticle->m_lifeMax)
		{
			delete currentParticle;
			iter = m_particleList.erase(iter);
		}
		else
		{
			std::list<ParticleAffector*>::iterator iter2 = m_affectorList.begin();

			while (iter2 != m_affectorList.end())
			{
				ParticleAffector* currentAffector = *iter2;
				//currentAffector->affectParticleUpdate(currentParticle);

				iter2++;	
			}

			currentParticle->Update(deltaTime);
			iter++;
		}
	}
}

void ParticleSystem::Draw()
{
	std::list<ParticleObject*>::iterator iter = m_particleList.begin();
	while (iter != m_particleList.end())
	{
		ParticleObject* currentParticle = *iter;
		currentParticle->Draw();
		iter++;
	}
}

void ParticleSystem::addAffector(ParticleAffector* newAffector)
{
	m_affectorList.push_back(newAffector);
}