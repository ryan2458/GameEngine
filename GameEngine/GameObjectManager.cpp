#include "GameObjectManager.h"
#include "GameObject.h"
#include "Transform.h"

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
	GameObject* gameObject = new GameObject();
	gameObject->addComponent(new Transform());
	gameObjects.push_back(gameObject);

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
}

void GameObjectManager::update(float deltaTime)
{
	for (GameObject* go : gameObjects)
	{
		go->update(deltaTime);
	}
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
