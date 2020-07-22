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
	particleVelI = Vector2(0.0f, 0.0f);
	particleVelF = Vector2(0.0f, 0.0f);
	particleAccI = Vector2(0.0f, -9.81f);
	particleAccF = Vector2(0.0f, -100.0f);

	m_shape = new SquareEmitterShape(75.0f, 50.0f);
}

ParticleSystem::~ParticleSystem()
{

}

void ParticleSystem::createNewParticle()
{
	newLife = rand() % 3 + 1;

	newParticle = new ParticleObject(m_sprite, particleVelI, newLife);
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

/// <summary>
/// Set the emitter to the input emitter type. Valid emitter inputs are either Circle, Ring and Square emiter shapes.
/// </summary>
void ParticleSystem::setEmitterType(EmitterShape* newEmitter)
{
	m_shape = newEmitter;
}

/// <summary>
/// Sets the initial parameters of the particle when it spawns
/// </summary>
void ParticleSystem::setParticleInfo(Color initialColor, Vector2 initialScale, Vector2 initalVel, Vector2 initialAcc, float initialRotation)
{
	particleColorI = initialColor;
	particleScaleI = initialScale;
	particleAccI = initialAcc;
	particleRotationI = initialRotation;
}

/// <summary>
/// Sets the target parameters for the particle to transition into
/// </summary>
void ParticleSystem::setAffectorInfo(Color finalColor, Vector2 finalScale, Vector2 finalVel, Vector2 finalAcc, float finalRotation)
{
	particleColorF = finalColor;
	particleScaleF = finalScale;
	particleAccF = finalAcc;
	particleRotationF = finalRotation;
}

/// <summary>
/// New particles are created at a specific rate (emissionRate) and are added into a list for particles. Each particle in the list is then updated until it reaches it's lifespan, whereby it will then be deleted. Particle affectors are then applied to each particle as well.  
/// </summary>
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

/// <summary>
/// Renders each particle in the particle list onto the screen.
/// </summary>
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

/// <summary>
/// Adds a new affector type to the list of particle affectors
/// </summary>
void ParticleSystem::addAffector(ParticleAffector* newAffector)
{
	m_affectorList.push_back(newAffector);
}