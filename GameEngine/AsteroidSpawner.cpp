/*
Author: Nick Gerth
Last Edit: 12/5/2021
File: AsteroidSpawner.cpp
Description: Periodically creates new asteroids via the GameObjectManager
*/

#include "AsteroidSpawner.h"
#include "Engine.h"
#include "WindowManager.h"
#include "Body.h"
#include "AsteroidMovement.h"
#include "Collider.h"

// initializes members and spawns an initial number of asteroids
AsteroidSpawner::AsteroidSpawner(float timer, int initialSpawnCount) : Component("AsteroidSpawner"), timer(timer)
{
	for (int i = 0; i < initialSpawnCount; ++i)
	{
		createAsteroid();
	}
}

AsteroidSpawner::~AsteroidSpawner()
{
}

void AsteroidSpawner::update(float deltaTime)
{
	// used to keep track of when we'll spawn another asteroid
	static float elapsedTime = 0.0f;

	elapsedTime += deltaTime;

	if (elapsedTime >= timer)
	{
		int width, height;
		glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height);

		elapsedTime = 0.0f;

		createAsteroid();
	}
}

/*
Function Name: createAsteroid()
parameters: none
pre-condition: none
returns: none
Description: creates a game object via the GameObjectManager that represents an asteroid
*/
void AsteroidSpawner::createAsteroid()
{
	int maxSize = 100.0f;

	float randSize = (float)(rand() % maxSize) + 50;
	float randRotation = (float)(rand() % 360) + 1;
	GameObject* asteroid = Engine::getInstance().gameObjectManager.create("Asteroid");
	asteroid->addComponent(new Body());
	asteroid->addComponent(new AsteroidMovement());
	asteroid->addComponent(new Collider(glm::vec2(asteroid->transform->position.x, asteroid->transform->position.y), randSize / 2.0f));
	asteroid->getComponent<Collider>()->setTag("Enemy");
	asteroid->transform->scale(glm::vec3(randSize, randSize, 0.0f));
	asteroid->transform->rotate(randRotation);
	asteroid->sprite->swapTexture("asteroid.png");
}
