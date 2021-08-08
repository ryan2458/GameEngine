#include "Component.h"

Component::Component(const std::string& name) : BasedObject(name)
{

}

Component::~Component()
{

}

GameObject* Component::getGameObject() const
{
	return nullptr;
}
