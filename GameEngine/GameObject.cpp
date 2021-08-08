#include "GameObject.h"
#include "Component.h"

GameObject::GameObject() : BasedObject("GameObject")
{
	
}

GameObject::~GameObject()
{

}

void GameObject::add(Component* component)
{
	components.push_back(component);
}

void GameObject::remove(Component* component)
{
	// TODO: CHECK W/ BAR TO SEE IF THIS IS HOW I FREE MEMORY
	std::vector<Component*>::iterator it = std::find(components.begin(), components.end(), component);
	delete component;
	components.erase(it);
}

void GameObject::updateComponents()
{
	for (int i = 0; i < components.size(); ++i)
	{
		components.at(i)->update(Engine::getInstance().getDeltaTime());
	}
}
