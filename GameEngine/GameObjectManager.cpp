#include "GameObjectManager.h"
#include "Collider.h"
#include <iostream>

bool IsPointInCircle(float xa, float ya, float xc, float yc, float r);

GameObject* GameObjectManager::createGameObject()
{
	GameObject* gameObject = new GameObject();
	gameObject->addComponent(new Transform());
	gameObjects.push_back(gameObject);

	return gameObject;
}

GameObjectManager::GameObjectManager() : BasedObject("GameObjectManager")
{
}

GameObjectManager::~GameObjectManager()
{
	while (!gameObjects.empty())
	{
		destroy(gameObjects.back());
	}
}

GameObject* GameObjectManager::create()
{
	return createGameObject();
}

//GameObject* GameObjectManager::create()
//{
//	GameObject* gameObject = createGameObject();
//	//gameObject->setName(name);
//}

GameObject* GameObjectManager::create(glm::vec3 location)
{
	GameObject* gameObject = createGameObject();
	gameObject->transform->trans(location);

	return gameObject;
}

// Ask Bar if gameObject is actually getting deleted here
// Change code back to not setting gameObject to nullptr
// Make it so gameObject is not a ref to a pointer
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
			if (go != other && go->getName() != other->getName())
			{
				Collider* c1 = go->getComponent<Collider>();
				Collider* c2 = other->getComponent<Collider>();

				if (c1 != nullptr && c2 != nullptr)
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
	for (GameObject* go : gameObjects)
	{
		go->update(deltaTime);
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
