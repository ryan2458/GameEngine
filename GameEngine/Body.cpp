/*
Author: Ryan Aloof, Nick Gerth
Last Edit: 12/7/2021
File: Body.cpp
Description: Adds some basic physics movement to an object if this component is added
*/

#include "Body.h"
#include "GameObject.h"

Body::Body(glm::vec3 accel) : Component("ShipBody"), velocity(glm::vec3(0.0f, 0.0f, 0.0f)), acceleration(accel)
{

}

Body::~Body()
{
}

// Handles basic physics applications
// Physics courtesy of Nick Gerth
// Code courtesy of Ryan Aloof
void Body::update(float deltaTime)
{
	acceleration.x *= deltaTime;
	acceleration.y *= deltaTime;

	velocity += acceleration;

	getGameObject()->transform->translate(velocity);
}

Component* Body::clone()
{
	return nullptr;
}

