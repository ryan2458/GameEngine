#include "Movement.h"
#include <cmath>
#include <iostream>
# define M_PI 3.14159265358979323846

Movement::Movement(float speed, float rotationSpeed) : Component("Movement"), mBody(nullptr), mTransform(nullptr), mSpeed(speed), 
	mRotationSpeed(rotationSpeed)
{
}

Movement::~Movement()
{
}

void Movement::init()
{
	mBody = getGameObject()->getComponent<Body>();
	mTransform = getGameObject()->getComponent<Transform>();
}

// TODO: Need linear drag
void Movement::update(float deltaTime)
{
	if (InputState::KeyPressed::left)
	{
		mTransform->angle -= mRotationSpeed * deltaTime;
	}

	if (InputState::KeyPressed::right)
	{
		mTransform->angle += mRotationSpeed * deltaTime;
	}

	if (InputState::KeyPressed::up)
	{
		float radians = (mTransform->angle * (double)(M_PI / 180.0));
		mBody->velocity.x += (cos(radians) * (double)(180.0 / M_PI)) * mSpeed * deltaTime;
		mBody->velocity.y += (sin(radians) * (double)(180.0 / M_PI)) * mSpeed * deltaTime;
	}

	if (InputState::KeyPressed::down)
	{
		float radians = (mTransform->angle * (double)(M_PI / 180.0));
		mBody->velocity.x -= (cos(radians) * (double)(180.0 / M_PI)) * mSpeed * deltaTime;
		mBody->velocity.y -= (sin(radians) * (double)(180.0 / M_PI)) * mSpeed * deltaTime;
	}
}

Component* Movement::clone()
{
	return nullptr;
}
