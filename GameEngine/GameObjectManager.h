/*
Author: Ryan Aloof
*/

#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H


#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "BasedObject.h"

class GameObject;

class GameObjectManager : public BasedObject
{
private:
	std::vector<GameObject*> gameObjects;

	GameObject* createGameObject();
public:
	GameObjectManager();
	~GameObjectManager();

	GameObject* create();
	GameObject* create(const std::string& name);
	GameObject* create(glm::vec3 location);
	GameObject* create(glm::vec3 location, const std::string& name);

	void addObject(GameObject* toAdd);
	void destroy(GameObject*& gameObject);

	void checkCollisions();

	GameObject* find(const std::string& name);

	void load()                  override;
	void init()                  override;
	void update(float deltaTime) override;
	void draw()                  override;
	void unload()                override;
};

#endif