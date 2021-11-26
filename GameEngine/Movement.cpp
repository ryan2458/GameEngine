#include "Movement.h"
#include <cmath>
#include <iostream>
# define M_PI 3.14159265358979323846

Movement::Movement(float speed) : Component("Movement"), mBody(nullptr), mSpeed(speed)
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
		mTransform->angle -= 0.25f;
	}

	if (InputState::KeyPressed::right)
	{
		mTransform->angle += 0.25f;
	}

	if (InputState::KeyPressed::up)
	{
		glm::vec2 velocity = mBody->velocity;
		float radians = (mTransform->angle * (double)(M_PI / 180.0));

		velocity.x += mSpeed * (cos(radians) * (double)(180.0 / M_PI));
		velocity.y += mSpeed * (sin(radians) * (double)(180.0 / M_PI)); 

		mBody->velocity = velocity;
	}

	if (InputState::KeyPressed::down)
	{
		glm::vec2 velocity = mBody->velocity;
		float radians = (mTransform->angle * (double)(M_PI / 180.0));

		velocity.x -= mSpeed * (cos(radians) * (double)(180.0 / M_PI));
		velocity.y -= mSpeed * (sin(radians) * (double)(180.0 / M_PI));

		mBody->velocity = velocity;
	}
}

Component* Movement::clone()
{
	return nullptr;
}
