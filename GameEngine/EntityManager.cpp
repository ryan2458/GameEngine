#include "EntityManager.h"

EntityManager::EntityManager() : currentId(0)
{
}

void EntityManager::createEntity(std::string name)
{
	entities.push_back(new Entity(currentId, name));
	currentId += 1;
}
