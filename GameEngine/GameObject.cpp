/*
File: GameObject.cpp
Author: Ryan Aloof, Anne Tansengco
Last Edit: 12/4/2021
Description: Handles generation, destruction, and component addition/removal for a game object
*/

#include "Component.h"
#include "WindowManager.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"

void checkPosition(Transform& transform);


/*
Function: generateDefaultName()
Pre-condition: none
Returns: a string used for the gameobject name
Description: Generates a default name for a GameObject if no name is provided at construction
*/
std::string GameObject::generateDefaultName()
{
	static int count = 0;
	static std::string defaultName = "GameObject0";
	defaultName.back() = std::to_string(count).back();
	count += 1;

	return defaultName;
}

GameObject::GameObject() : BasedObject(generateDefaultName()), transform(dynamic_cast<Transform*>(addComponent(new Transform()))),
	sprite(dynamic_cast<Sprite*>(addComponent(new Sprite())))	
{

}

GameObject::GameObject(const std::string& name) : BasedObject(name), transform(dynamic_cast<Transform*>(addComponent(new Transform()))),
	sprite(dynamic_cast<Sprite*>(addComponent(new Sprite())))
{

}

GameObject::~GameObject()
{
	destroy();
}

/*
Function: addComponent()
Parameters: component [a pointer to the component to add]
Pre-condition: memory for component must be allocated outside of call
Description: Adds the component to the GameObject and sets the components parent to this
Returns: A pointer to the component added
*/
Component* GameObject::addComponent(Component* component)
{
	components.push_back(component);
	component->setParent(this);
	return component;
}

/*
Function: removeComponent()
Parameters: component [a reference to a pointer to the component to remove]
Pre-condition: component must point to valid memory
Description: Removes the component from the GameObject and sets its pointer to nullptr
Returns: none
*/
void GameObject::removeComponent(Component*& component)
{
	std::vector<Component*>::iterator it = std::find(components.begin(), components.end(), component);
	delete component;
	components.erase(it);
	component = nullptr;
}

/*
Function: addChild()
Parameters: a pointer to a GameObject
Description: Adds the GameObject to the parent GameObject and sets the added GameObject to this
Returns: none
*/
void GameObject::addChild(GameObject* toAdd)
{
	toAdd->setParent(this);
}

/*
Function: removeChild()
Parameters: a pointer to a GameObject
Description: Removes the child GameObject from the parent GameObject
Returns: none
*/
void GameObject::removeChild(GameObject* toRemove)
{
	toRemove->setParent(nullptr);
}

/*
Function: load()
Description: Calls all overloaded load() functions for all the components.
Returns: none
*/
void GameObject::load()
{
	for (Component* comp : components)
	{
		comp->load();
	}
}

/*
Function: init()
Description: Calls all overloaded init() functions for all the components.
Returns: none
*/
void GameObject::init()
{
	for (Component* comp : components)
	{
		comp->init();
	}
}

/*
Function: update()
Description: Calls all overloaded update() functions for all the components.
Returns: none
Remarks: Note the use of a regular for-loop instead of a for-each.  This is to avoid issues related to invalid iterators
		 if game objects or components are deleted between updates
*/
void GameObject::update(float deltaTime)
{
	for (size_t i = 0; i < components.size(); ++i)
	{
		components.at(i)->update(deltaTime);
	}
}

/*
Function: draw()
Description: draws the GameObject to the screen via calls to the Renderer class
Returns: none
*/
void GameObject::draw()
{
	checkPosition(*transform);
	Renderer::getInstance().render(*transform, *sprite);
}

/*
Function: checkPosition()
Params: A reference to the GameObject's Transform (for position)
Description: Checks the position of an object via its Transform component.  If the object goes outside window bounds, its 
		     position is updated to appear on the opposite side of the screen via calls to translate in Transform
Returns: none
*/
void checkPosition(Transform& transform) 
{
	int width, height; // width and height of window
    glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height); // getting size of window

	if (transform.position.x < 0.0f) // if object position is outside the window to the left
	{
		transform.translate(glm::vec3((float)width, 0.0f, 0.0f)); // move object to far right of the screen
	}

	if (transform.position.x > (float)width) // if object position is outside the window to the right
	{
		transform.translate(glm::vec3(-(float)width, 0.0f, 0.0f)); // move object to the far left of the screen
	}

	if (transform.position.y < 0.0f) // if object position is outside the window at the top
	{
		transform.translate(glm::vec3(0.0f, (float)height, 0.0f)); // move object to bottom of screen
	}

	if (transform.position.y > (float)height) // if object position is outside the window at the bottom
	{
		transform.translate(glm::vec3(0.0f, -(float)height, 0.0f)); // move object to top of screen
	}
}

/*
Function: unload()
Description: Calls all overloaded unload() functions for all the components.
Returns: none
*/
void GameObject::unload()
{
	for (Component* comp : components)
	{
		comp->unload();
	}
}

/*
Function: destroy()
Description: removes and destroys all components on the object, if any
Returns: none
*/
void GameObject::destroy()
{
	while (!components.empty())
	{
		removeComponent(components.back());
	}
}
