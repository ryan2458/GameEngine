#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Engine.h"
#include "BasedObject.h"
#include <vector>

class Component;

class GameObject : public BasedObject
{
private:
	std::vector<Component*> components;
public:
	GameObject();
	~GameObject() override;

	void add(Component* component);
	void remove(Component* component);
	void updateComponents();
};

#endif