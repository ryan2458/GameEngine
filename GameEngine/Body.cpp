#include "Body.h"

Body::Body(glm::vec2 pos, glm::vec2 accel) : Component("ShipBody"), 
	position(pos), velocity(glm::vec2(0.0f, 0.0f)), acceleration(accel)
{

}

Body::~Body()
{
}

void Body::update(float deltaTime)
{
	acceleration.x *= deltaTime;
	acceleration.y *= deltaTime;

	velocity += acceleration;

	position += velocity * deltaTime;

	getGameObject()->transform->position.x = position.x;
	getGameObject()->transform->position.y = position.y;
}

Component* Body::clone()
{
	return nullptr;
}

