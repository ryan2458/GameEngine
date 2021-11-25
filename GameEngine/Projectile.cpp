#include "Projectile.h"

Projectile::Projectile(glm::vec2 vel) : velocity(vel)
{
	GameObject* go = (GameObject*)getParent();
	transform->position = go->transform->position;
}

Projectile::~Projectile()
{
	destroy();
}

void Projectile::update(float deltaTime)
{
	transform->position.x += velocity.x * deltaTime;
	transform->position.y += velocity.y * deltaTime;
}
