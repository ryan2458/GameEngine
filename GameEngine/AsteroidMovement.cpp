#include "AsteroidMovement.h"
#include "Body.h"
#include <cstdlib>

AsteroidMovement::AsteroidMovement() : Component("AsteroidMovement"), mRotationTimer(0.0f), mRotationAngle(generateRandomAngle()),
	mForwardSpeed(25.0f)
{
}

AsteroidMovement::~AsteroidMovement()
{
}

void AsteroidMovement::update(float deltaTime)
{
	mRotationTimer += 1.0f * deltaTime;

	if (mRotationTimer >= 5.0f)
	{
		mRotationTimer = 0.0f;
		mRotationAngle = generateRandomAngle();
	}

	getGameObject()->getComponent<Body>()->velocity.x = glm::cos(glm::radians(mRotationAngle)) * mForwardSpeed * deltaTime;
	getGameObject()->getComponent<Body>()->velocity.y = glm::sin(glm::radians(mRotationAngle)) * mForwardSpeed * deltaTime;
}

inline float AsteroidMovement::generateRandomAngle()
{
	return (float)((rand() % 360) + 1);
}