/*
Author: Ryan Aloof
Description:
	Entity is a class that is mainly meant to hold an Id and name.  It should not hold components.  Components are
	handled by the singley instanced EntityManager class.  The sole purpose of this class is to provide a relational key that
	Component objects will link with.  The Component class will have an entityId that matches the specified Entity they are being
	added to.
*/

#include "Engine.h"
#include <string>

class Entity
{
private:
	unsigned int entityId;
	std::string name;
public:
	Entity(unsigned int entityId, std::string name);
	unsigned int getEntityId();
};