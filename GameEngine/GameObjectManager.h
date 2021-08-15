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
public:
	GameObjectManager();

	void create();
	void create(glm::vec2* size, glm::vec2* position);

	void addObject(GameObject* toAdd);

	void destroy(GameObject* gameObject);

	void load()                  override;
	void init()                  override;
	void update(float deltaTime) override;
	void draw()                  override;
	void unload()                override;

};

#endif