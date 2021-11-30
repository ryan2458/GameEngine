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
		// messes up matrix
		mTransform->angle -= mRotationSpeed * deltaTime;
		//float x_rotation = mTransform->angle - (mRotationSpeed * deltaTime);
		//mTransform->rotate(x_rotation);
		
		//glm::rotate(mTransform->position., mTransform->angle, glm::vec3(x_rotation, 0.0f, 0.0f));
	}

	if (InputState::KeyPressed::right)
	{
		mTransform->angle += mRotationSpeed * deltaTime;
	}

	if (InputState::KeyPressed::up)
	{
		float x = glm::cos(glm::radians(mTransform->angle)) * mSpeed * deltaTime;
		float y = glm::sin(glm::radians(mTransform->angle)) * mSpeed * deltaTime;
		//mTransform->translate(glm::vec3(x, y, 0.0f));

		mBody->velocity.x = x;
		mBody->velocity.y = y;

		//float radians = (mTransform->angle * (double)(M_PI / 180.0));
		//mBody->velocity.x += cos(radians) * mSpeed * deltaTime;
		//mBody->velocity.y += sin(radians) * mSpeed * deltaTime;
	}

	if (InputState::KeyPressed::down)
	{
		float radians = glm::radians(mTransform->angle);
		mBody->velocity.x -= cos(radians) * mSpeed * deltaTime;
		mBody->velocity.y -= sin(radians) * mSpeed * deltaTime;
	}
}

Component* Movement::clone()
{
	return nullptr;
}
