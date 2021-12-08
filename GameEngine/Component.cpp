/*
Author: Ryan Aloof
File: Component.cpp
Description: Stub implementations for abstract Component class
*/

#include "Component.h"

Component::Component(const std::string& name) : BasedObject(name)
{

}

Component::~Component()
{

}

// calls get parent with an unsafe cast
GameObject* Component::getGameObject()
{
	return (GameObject*)getParent();
}


