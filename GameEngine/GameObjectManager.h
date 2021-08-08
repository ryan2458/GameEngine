#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "BasedObject.h"
#include <vector>

class GameObject;

class GameObjectManager
{
private:
	std::vector<GameObject*> gameObjects;
public:
	GameObjectManager();

	void create();
	void destroy(GameObject* gameObject);
	void updateObjects();
};

#endif