#include "Projectile.h"
#include "GameObject.h"
#include "Body.h"

Projectile::Projectile(float angle, float speed) : Component("Projectile"), rotation(angle), projectileSpeed(speed)
{
}

Projectile::~Projectile()
{
}

void Projectile::update(float deltaTime)
{
	getGameObject()->getComponent<Body>()->velocity.x = glm::cos(glm::radians(rotation)) * projectileSpeed * deltaTime;
	getGameObject()->getComponent<Body>()->velocity.y = glm::sin(glm::radians(rotation)) * projectileSpeed * deltaTime;
}
