#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "BasedObject.h"
#include <vector>

class GameObject;

class GameObjectManager : public BasedObject
{
private:
	std::vector<GameObject*> gameObjects;
public:
	GameObjectManager();

	void create();
	void destroy(GameObject* gameObject);

	void load()                  override;
	void init()                  override;
	void update(float deltaTime) override;
	void draw()                  override;
	void unload()                override;

};

#endif