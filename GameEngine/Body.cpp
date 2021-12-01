#include "Body.h"
#include "GameObject.h"

Body::Body(glm::vec3 accel) : Component("ShipBody"), velocity(glm::vec3(0.0f, 0.0f, 0.0f)), acceleration(accel)
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

	getGameObject()->transform->trans(velocity);
}

Component* Body::clone()
{
	return nullptr;
}

