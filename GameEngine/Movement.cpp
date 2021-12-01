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
		mTransform->rotate(mRotationSpeed * deltaTime * -1);
	}

	if (InputState::KeyPressed::right)
	{
		mTransform->rotate(mRotationSpeed * deltaTime);
	}

	if (InputState::KeyPressed::up)
	{
		float x = glm::cos(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;
		float y = glm::sin(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;

		mTransform->trans(glm::vec3(x, y, 0.0f));
	}

	if (InputState::KeyPressed::down)
	{
		float x = glm::cos(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;
		float y = glm::sin(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;
		mTransform->trans(glm::vec3(-x, -y, 0.0f));
	}
}

Component* Movement::clone()
{
	return nullptr;
}
