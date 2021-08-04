#include "Entity.h"

Entity::Entity(unsigned int entityId, std::string name) : entityId(entityId), name(name)
{
}

unsigned int Entity::getEntityId()
{
	return entityId;
}
