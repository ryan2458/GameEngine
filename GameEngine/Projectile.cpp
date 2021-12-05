#include "Projectile.h"
#include "GameObject.h"
#include "Body.h"
#include "Gun.h"
#include "WindowManager.h"

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

	int width;
	int height;

	glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height);

	if (!isVisible(*(getGameObject()->transform), width, height))
	{
		GameObject* go = getGameObject();
		Engine::getInstance().gameObjectManager.destroy(go);
	}
}

bool Projectile::isVisible(Transform& transform, int width, int height)
{

	if (transform.position.x > width || transform.position.x < 0.0f)
	{
		return false;
	}

	if (transform.position.y > height || transform.position.y < 0.0f)
	{
		return false;
	}

	return true;
}
