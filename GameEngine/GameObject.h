#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

// remove later when we have transform
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "BasedObject.h"
#include <vector>

class Component;

class GameObject : public BasedObject
{
private:
	std::vector<Component*> components;
	// temporary, will be moved to transform later
	//glm::vec2 size;
	//glm::vec2 position;

	static std::string generateDefaultName();
public:
	GameObject();
	//GameObject(glm::vec2 size, glm::vec2 position);
	~GameObject() override;

	template <class T>
	T* getComponent();

	void addComponent(Component* component);
	void removeComponent(Component* component);

	void addChild(GameObject* toAdd);
	void removeChild(GameObject* toRemove);

	void load()                  override;
	void init()                  override;
	void update(float deltaTime) override;
	void draw()                  override;
	void unload()                override;
};

#endif

template<class T>
inline T* GameObject::getComponent()
{
	T* returnComp = nullptr;

	for (Component* comp : components)
	{
		if (dynamic_cast<T*>(comp) != nullptr)
		{
			return (T*)comp;
		}
	}

	return nullptr;
}
