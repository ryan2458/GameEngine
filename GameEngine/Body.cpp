#include "Body.h"

Body::Body(glm::vec3 pos, glm::vec3 accel) : Component("ShipBody"), 
	position(pos), velocity(glm::vec3(0.0f, 0.0f, 0.0f)), acceleration(accel)
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


	getGameObject()->transform->translate(position);

	//getGameObject()->transform->position.x = position.x;
	//getGameObject()->transform->position.y = position.y;
}

Component* Body::clone()
{
	return nullptr;
}

