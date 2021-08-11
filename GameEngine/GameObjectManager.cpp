#include "GameObjectManager.h"
#include "GameObject.h"

GameObjectManager::GameObjectManager() : BasedObject("GameObjectManager")
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

void GameObjectManager::unload()
{
	
}
