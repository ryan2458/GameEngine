/*
Author: Ryan Aloof
File: GameObjectManager.cpp
Description: Handles lifetimes of GameObjects, and updates objects every frame, destroys objects
*/

#include "GameObjectManager.h"
#include "Collider.h"
#include <iostream>

bool IsPointInCircle(float xa, float ya, float xc, float yc, float r);

GameObjectManager::GameObjectManager() : BasedObject("GameObjectManager")
{
}

GameObjectManager::~GameObjectManager()
{
	// destroy any remaining game objects
	for (int i = (int)gameObjects.size() - 1; i >= 0; --i)
	{
		destroy(gameObjects.at(i));
	}
}

/*
Function: createGameObject()
Returns: pointer to new game object instantiated
Description: creates a blank game object
*/
GameObject* GameObjectManager::createGameObject()
{
	GameObject* gameObject = new GameObject();
	gameObjects.push_back(gameObject);

	return gameObject;
}

/*
Function: create()
Returns: pointer to new game object instantiated
Description: creates a blank game object
*/
GameObject* GameObjectManager::create()
{
	return createGameObject();
}

/*
Function: create()
Params: a string representing the GameObject name
Returns: pointer to new game object instantiated
Description: creates a game object and sets its name to parameter [name]
*/
GameObject* GameObjectManager::create(const std::string& name)
{
	GameObject* gameObject = createGameObject();
	gameObject->setName(name);
	return gameObject;
}

/*
Function: create()
Params: a glm::vec3 representing location to be moved to
Returns: pointer to new game object instantiated
Description: creates a blank game object with its position translated to that of parameter [location]
*/
GameObject* GameObjectManager::create(glm::vec3 location)
{
	GameObject* gameObject = createGameObject();
	gameObject->transform->translate(location);

	return gameObject;
}

/*
Function: create()
Params: a location glm::vec3, a name std::string
Returns: pointer to new game object instantiated
Description: creates a game object with a name and location to be placed at
*/
GameObject* GameObjectManager::create(glm::vec3 location, const std::string& name)
{
	GameObject* gameObject = createGameObject();
	gameObject->transform->translate(location);
	gameObject->setName(name);
	return gameObject;
}

/*
Function: destroy()
params: reference to a pointer to a game object
description: finds a game object, deletes it, and erases it from the underlying game object collection
*/
void GameObjectManager::destroy(GameObject*& gameObject)
{
	std::vector<GameObject*>::iterator it = std::find(gameObjects.begin(), gameObjects.end(), gameObject);
	delete gameObject;
	gameObjects.erase(it); // erases the pointer, not the object
	gameObject = nullptr;
}

/*
Function: checkCollisions()
description: does a nested iteration through all game objects to find if any object colliders overlap
			 if they do, the game object manager destroys them
*/
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

 
/*
source: https://stackoverflow.com/a/27342421/10470363
Function: IsPointInCircle
Description: uses pythagoras forumla to determine if circle a and circle c overlap
*/
bool IsPointInCircle(float xa, float ya, float xc, float yc, float r)
{
	return ((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc)) < r * r;
}


/*
Function: find
params: name of GameObject to find
returns: a pointer to the game object if found, otherwise nullptr
description: searches for a game object in the GameObject collection by name
*/
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

/*
Function: load()
description: calls load for all game objects in the collection
*/
void GameObjectManager::load()
{
	for (GameObject* go : gameObjects)
	{
		go->load();
	}
}

/*
Function: init()
description: calls init for all game objects in the collection
*/
void GameObjectManager::init()
{
	for (GameObject* go : gameObjects)
	{
		go->init();
	}
}

/*
Function: update()
description: calls update for all game objects in the collection
			 also checks for collisions after all updates have been called
*/
void GameObjectManager::update(float deltaTime)
{
	for (size_t i = 0; i < gameObjects.size(); ++i)
	{
		gameObjects.at(i)->update(deltaTime);
	}

	checkCollisions();
}

/*
Function: draw()
description: calls draw for all game objects in the collection
*/
void GameObjectManager::draw()
{
	for (GameObject* go : gameObjects)
	{
		go->draw();
	}
}

/*
Function: addObject()
params: a pointer to the game object that should be added to the GameObjectManager collection
description: Adds a game object to the GameObjectManager
*/
void GameObjectManager::addObject(GameObject* toAdd)
{
	toAdd->setParent(this);
	gameObjects.push_back(toAdd);
}