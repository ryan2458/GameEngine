#include "GameObjectManager.h"
#include "Collider.h"
#include <iostream>

bool IsPointInCircle(float xa, float ya, float xc, float yc, float r);

GameObjectManager::GameObjectManager() : BasedObject("GameObjectManager")
{
}

GameObjectManager::~GameObjectManager()
{
	for (int i = (int)gameObjects.size() - 1; i >= 0; --i)
	{
		destroy(gameObjects.at(i));
	}
}

GameObject* GameObjectManager::createGameObject()
{
	GameObject* gameObject = new GameObject();
	gameObjects.push_back(gameObject);

	return gameObject;
}

GameObject* GameObjectManager::create()
{
	return createGameObject();
}

GameObject* GameObjectManager::create(const std::string& name)
{
	GameObject* gameObject = createGameObject();
	gameObject->setName(name);
	return gameObject;
}

GameObject* GameObjectManager::create(glm::vec3 location)
{
	GameObject* gameObject = createGameObject();
	gameObject->transform->translate(location);

	return gameObject;
}

GameObject* GameObjectManager::create(glm::vec3 location, const std::string& name)
{
	GameObject* gameObject = createGameObject();
	gameObject->transform->translate(location);
	gameObject->setName(name);
	return gameObject;
}

void GameObjectManager::destroy(GameObject*& gameObject)
{
	std::vector<GameObject*>::iterator it = std::find(gameObjects.begin(), gameObjects.end(), gameObject);
	delete gameObject;
	gameObjects.erase(it); // erases the pointer, not the object
	gameObject = nullptr;
}

void GameObjectManager::checkCollisions()
{
	for (GameObject* go : gameObjects)
	{
		for (GameObject* other : gameObjects)
		{
			Collider* c1 = go->getComponent<Collider>();
			Collider* c2 = other->getComponent<Collider>();

			if (!(go->getName() == "Projectile" && other->getName() == "Projectile"))
			{
				if (c1 != nullptr && c2 != nullptr && c1->getTag() != c2->getTag())
				{
					if (IsPointInCircle(c1->position.x, c1->position.y, c2->position.x, c2->position.y, c1->radius + c2->radius))
					{
						this->destroy(go);
						this->destroy(other);
						break;
					}
				}
			}
		}
	}
}

// source: https://stackoverflow.com/a/27342421/10470363
bool IsPointInCircle(float xa, float ya, float xc, float yc, float r)
{
	return ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) < r * r;
}

GameObject* GameObjectManager::find(const std::string& name)
{
	for (std::vector<GameObject*>::iterator it = gameObjects.begin(); it != gameObjects.end(); ++it)
	{
		if ((*it)->getName() == name)
		{
			return *it;
		}
	}

	return nullptr;
}

void GameObjectManager::load()
{
	for (GameObject* go : gameObjects)
	{
		go->load();
	}
}

void GameObjectManager::init()
{
	for (GameObject* go : gameObjects)
	{
		go->init();
	}
}

void GameObjectManager::update(float deltaTime)
{
	for (size_t i = 0; i < gameObjects.size(); ++i)
	{
		gameObjects.at(i)->update(deltaTime);
	}

	checkCollisions();
}

void GameObjectManager::draw()
{
	for (GameObject* go : gameObjects)
	{
		go->draw();
	}
}

void GameObjectManager::addObject(GameObject* toAdd)
{
	toAdd->setParent(this);
	gameObjects.push_back(toAdd);
}

void GameObjectManager::unload()
{

}
