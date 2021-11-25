#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "BasedObject.h"
#include "Transform.h"
#include <vector>

class Component;

class GameObject : public BasedObject
{
private:
	std::vector<Component*> components;
	static std::string generateDefaultName();

protected:
	// This should remain protected, if you wish to destroy a GameObject
	// outside of the context of itself
	// Call destroy() in GameObjectManager
	void destroy();

public:

	GameObject();
	~GameObject() override;

	Transform* const transform;

	template <class T>
	T* getComponent();

	Component* addComponent(Component* component);
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
	for (Component* comp : components)
	{
		if (dynamic_cast<T*>(comp) != nullptr)
		{
			return (T*)comp;
		}
	}

	return nullptr;
}
