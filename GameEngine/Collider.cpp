/*
Author: Nick gerth
Last Edit: 12/7/2021
File: Collider.cpp
Description: Handles initialization and position updates for a component that represents a circle collider
*/

#include "Collider.h"

// Initializes and assigns position and radius at construction
Collider::Collider(glm::vec2 newPos, float newRadius) : Component("Collider"), position(newPos), radius(newRadius)
{
}

Collider::~Collider()
{
}

void Collider::update(float deltaTime)
{
	// update our position to that of the game object we're attached to
	position.x = getGameObject()->getComponent<Transform>()->position.x;
	position.y = getGameObject()->getComponent<Transform>()->position.y;
}

void Collider::setName(const std::string& newName)
{
	getGameObject()->setName(newName);
}
