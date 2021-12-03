#include "Collider.h"


Collider::Collider(glm::vec2 newPos, float newRadius) : Component("Collider"), position(newPos), radius(newRadius)
{
}

Collider::~Collider()
{
}

void Collider::init()
{

}

void Collider::update(float deltaTime)
{
	position.x = getGameObject()->getComponent<Transform>()->position.x;
	position.y = getGameObject()->getComponent<Transform>()->position.y;
}

void Collider::setName(const std::string& newName)
{
	getGameObject()->setName(newName);
}
