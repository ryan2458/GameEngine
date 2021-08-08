#ifndef COMPONENT_H
#define COMPONENT_H

#include "BasedObject.h"

class GameObject;

// abstract
class Component : public BasedObject
{
public:
	Component(const std::string& name);
	virtual ~Component();
	GameObject* getGameObject() const;

	virtual Component* clone() = 0;
};

#endif