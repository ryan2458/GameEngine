/*
Author: Ryan Aloof
File: BasedObject.h
Last Edit: 12/6/2021
Description: Contains header for a BasedObject, the most based of all objects
*/

#ifndef BASED_OBJECT_H
#define BASED_OBJECT_H

#include <string>

/*
A BasedObject is the class all other classes derive from.  This class is abstract by design.  All deriving classes
may optionally override the provided virtual functions.

All classes, except for a select few, should inherit from BasedObject in some way, whether directly or indirectly.
This will allow for them to override the provided virtual functions as mentioned earlier, and allow the GameObjectManager
to easily iterate over all game objects and call the overrided functions if provided.
*/
class BasedObject
{
private:
	BasedObject* parent;
	std::string name;
public:
	// Constructs a BasedObject, assigns parent ptr to nullptr and name to value of name argument
	BasedObject(const std::string& name);
	virtual ~BasedObject() = 0;


	// NOT TO BE IMPLEMENTED IN BASEDOBJECT
	virtual void load();
	virtual void init();
	virtual void update(float deltaTime);
	virtual void draw();
	virtual void shutdown();
	virtual void unload(); 


	/*** Implementations ***/
	// Gets the object that parents this one
	inline BasedObject* getParent() { return parent; }
	// Sets the parent object for this BasedObject instance
	inline void setParent(BasedObject* newParent) { parent = newParent; }
	// Returns the name of the object
	inline const std::string& getName() const { return name; }
	// Sets the name of the object
	inline void setName(const std::string& newName) { name = newName; }
};

#endif