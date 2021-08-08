#include "GameObjectManager.h"
#include "GameObject.h"

GameObjectManager::GameObjectManager()
{
}

void GameObjectManager::create()
{
	GameObject* gameObject = new GameObject();
	gameObjects.push_back(gameObject);
}

void GameObjectManager::destroy(GameObject* gameObject)
{
	std::vector<GameObject*>::iterator it = std::find(gameObjects.begin(), gameObjects.end(), gameObject);
	delete gameObject;
	gameObjects.erase(it);
}

void GameObjectManager::updateObjects()
{
	for (GameObject* go : gameObjects)
	{
		go->updateComponents();
	}
}
