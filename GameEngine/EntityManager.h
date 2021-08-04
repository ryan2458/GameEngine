/*
Author: Ryan Aloof
Description:
	EntityManager is a singley instanced class that contains Entities.  It is intended that the System class
	will have control over EntityManager and therefore no other classes should be calling it.  Functions that wish to interface with
	the EntityManager must interface via System.
*/


#include <vector>
#include <string>

#include "Engine.h"
#include "Entity.h"
#include "Component.h"

class EntityManager
{
private:
	// remove this, use hashtable instead ****
	struct EntityInstance {
		std::vector<Component&> components;
		Entity& entity;
	};

	// incremented like an AUTO INCREMENT in SQL.  This should not be manipulated outside of createEntity
	unsigned int currentId;
	EntityManager();
	std::vector<Entity*> entities;
public:
	static EntityManager& getInstance()
	{
		static EntityManager instance; // thread-safe in C++ 11
		return instance;
	}

	EntityManager(EntityManager const&) = delete;
	void operator=(EntityManager const&) = delete;

	void createEntity(std::string name);

};