/*
Authors: Jordan Brooks, Anne Tansengco
*/

#include "Projectile.h"
#include "GameObject.h"
#include "Body.h"
#include "Gun.h"
#include "WindowManager.h"

Projectile::Projectile(float angle, float speed) : Component("Projectile"), rotation(angle), projectileSpeed(speed)
{
	// :D
}

Projectile::~Projectile()
{
	// :D
}

void Projectile::update(float deltaTime)
{
	// setting x and y velocity relative to rotation of parent object
	getGameObject()->getComponent<Body>()->velocity.x = glm::cos(glm::radians(rotation)) * projectileSpeed * deltaTime;
	getGameObject()->getComponent<Body>()->velocity.y = glm::sin(glm::radians(rotation)) * projectileSpeed * deltaTime;

	int width; // width
	int height; // height

	glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height); // getting window size

	if (!isVisible(*(getGameObject()->transform), width, height)) // if object is not visible
	{
		GameObject* go = getGameObject(); // setting a pointer to game object
		Engine::getInstance().gameObjectManager.destroy(go); // destroy game object
	}
}

bool Projectile::isVisible(Transform& transform, int width, int height)
{
	if (transform.position.x > width || transform.position.x < 0.0f) // if object is outside the horizontal window content boundary
	{
		return false;
	}

	if (transform.position.y > height || transform.position.y < 0.0f) // if object is outside the vertical window content boundary
	{
		return false;
	}

	return true; // otherwise it is visible
}
