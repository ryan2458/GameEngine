/*
Author: Ryan Aloof
File: Movement.cpp
Description: Component that allows for an object to move via player input
*/

#include "Movement.h"
#include "GameObject.h"

Movement::Movement(float speed, float rotationSpeed) : Component("Movement"), mBody(nullptr), mTransform(nullptr), mSpeed(speed), 
	mRotationSpeed(rotationSpeed)
{
}

Movement::~Movement()
{
}

void Movement::init()
{
	// a Body and Transform component are required for this script to work
	mBody = getGameObject()->getComponent<Body>();
	mTransform = getGameObject()->getComponent<Transform>();
}

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
		// change forward direction based on player rotation
		float x = glm::cos(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;
		float y = glm::sin(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;

		mBody->acceleration.x += glm::cos(glm::radians(mTransform->rotation)) * 0.05f;
		mBody->acceleration.y += glm::sin(glm::radians(mTransform->rotation)) * 0.05f;

		mTransform->translate(glm::vec3(x, y, 0.0f));
	}

	if (InputState::KeyPressed::down)
	{
		// change backward direction based on player rotation
		float x = glm::cos(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;
		float y = glm::sin(glm::radians(mTransform->rotation)) * mSpeed * deltaTime;

		mBody->acceleration.x -= glm::cos(glm::radians(mTransform->rotation)) * 0.05f;
		mBody->acceleration.y -= glm::sin(glm::radians(mTransform->rotation)) * 0.05f;

		mTransform->translate(glm::vec3(-x, -y, 0.0f));
	}
}

// Implemented to make compiler happy
Component* Movement::clone()
{
	return nullptr;
}
