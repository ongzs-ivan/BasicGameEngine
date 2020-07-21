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

	particleColorI = Color::White;
	particleColorF = Color::Black;
	particleScaleI = Vector2(1.0f, 1.0f);
	particleScaleF = Vector2(0.25f, 0.25f);
	particleRotationI = 0.0f;
	particleRotationF = 450.0f;
	particleAccI = Vector2(0.0f, -9.81f);
	particleAccF = Vector2(0.0f, -100.0f);

	m_shape = new SquareEmitterShape(75.0f, 50.0f);
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::createNewParticle()
{
	newVel = Vector2(rand() % 200 - 100, rand() % 125 - 100);
	newLife = rand() % 3 + 1;

	newParticle = new ParticleObject(m_sprite, newVel, newLife);
	newParticle->setBlendMode(BlendingMode::Add);

	newParticle->setPosition(m_shape->getParticleEmissionPos(&m_position));
	newParticle->setRotation(particleRotationI);
	newParticle->setScale(particleScaleI);
	newParticle->setColor(particleColorI);
	newParticle->setAccel(particleAccI);

	m_scaleAffector		= new ParticleAffectorScale(newParticle->getScale(), particleScaleF);
	m_colorAffector		= new ParticleAffectorColor(newParticle->getColor(), particleColorF);
	m_rotateAffector	= new ParticleAffectorRotate(newParticle->getRotation(), particleRotationF);
	m_gravityAffector	= new ParticleAffectorGravity(newParticle->getAccel(), particleAccF);

	addAffector(m_colorAffector);
	addAffector(m_scaleAffector);
	addAffector(m_rotateAffector);
	addAffector(m_gravityAffector);
}

void ParticleSystem::setEmitterType(EmitterShape* newEmitter)
{
	m_shape = newEmitter;
}

void ParticleSystem::setParticleInfo(Color initialColor, Vector2 initialScale, Vector2 initialAcc, float initialRotation)
{
	particleColorI = initialColor;
	particleScaleI = initialScale;
	particleAccI = initialAcc;
	particleRotationI = initialRotation;
}

void ParticleSystem::setAffectorInfo(Color finalColor, Vector2 finalScale, Vector2 finalAcc, float finalRotation)
{
	particleColorF = finalColor;
	particleScaleF = finalScale;
	particleAccF = finalAcc;
	particleRotationF = finalRotation;
}

void ParticleSystem::Update(float deltaTime)
{

	// update particle count / add new particle + effects
	if (emissionCount >= emissionRate)
	{
		createNewParticle();

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
			currentParticle = nullptr;
			iter = m_particleList.erase(iter);
		}
		else
		{
			std::list<ParticleAffector*>::iterator iter2 = m_affectorList.begin();

			while (iter2 != m_affectorList.end())
			{
				ParticleAffector* currentAffector = *iter2;
				currentAffector->affectParticleUpdate(currentParticle);

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