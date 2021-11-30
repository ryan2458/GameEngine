#include "AsteroidMovement.h"
#include "Body.h"

AsteroidMovement::AsteroidMovement() : Component("AsteroidMovement")
{
}

AsteroidMovement::~AsteroidMovement()
{
}

void AsteroidMovement::update(float deltaTime)
{
	getGameObject()->getComponent<Body>()->velocity.x = 5.0f * deltaTime;
}
