#include "Collider.h"


Collider::Collider(glm::vec2 newPos, float newRadius) : Component("Collider"), mTransform(nullptr), position(newPos), radius(newRadius)
{
}

Collider::~Collider()
{
}

void Collider::init()
{
	mTransform = getGameObject()->getComponent<Transform>();
}

void Collider::update(float deltaTime)
{
	position.x = mTransform->position.x;
	position.y = mTransform->position.y;
}

void Collider::setName(const std::string& newName)
{
	getGameObject()->setName(newName);
}
