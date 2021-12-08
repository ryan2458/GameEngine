/*
Author: Nick Gerth
Last Edit: 12/7/2021
File: AsteroidMovement.cpp
Description: Adds movement to a Game Object (simulating how an asteroid would move, hence "AsteroidMovement"
*/

#include "AsteroidMovement.h"
#include "GameObject.h"
#include "Body.h"
#include <cstdlib>

AsteroidMovement::AsteroidMovement() : Component("AsteroidMovement"), mRotationAngle(generateRandomAngle()),
	mForwardSpeed(25.0f)
{
}

AsteroidMovement::~AsteroidMovement()
{
}

void AsteroidMovement::update(float deltaTime)
{
	// Update the velocity depending on rotation of object
	getGameObject()->getComponent<Body>()->velocity.x = glm::cos(glm::radians(mRotationAngle)) * mForwardSpeed * deltaTime;
	getGameObject()->getComponent<Body>()->velocity.y = glm::sin(glm::radians(mRotationAngle)) * mForwardSpeed * deltaTime;
}

void AsteroidMovement::setForwardSpeed(float newSpeed)
{
	mForwardSpeed = newSpeed;
}

// generates a random angle for the object, used for which direction it will move toward
inline float AsteroidMovement::generateRandomAngle()
{
	return (float)((rand() % 360) + 1);
}