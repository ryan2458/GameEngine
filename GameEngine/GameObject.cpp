#include "GameObject.h"
#include "Component.h"
#include "Renderer.h"

GameObject::GameObject() : BasedObject("GameObject")
{
	size = glm::vec2(10.0f, 10.0f);
	position = glm::vec2(0.0f, 0.0f);
}

GameObject::GameObject(glm::vec2 size, glm::vec2 position) : BasedObject("GameObject"), size(size), position(position)
{

}

GameObject::~GameObject()
{

}

void GameObject::addComponent(Component* component)
{
	components.push_back(component);
	component->setParent(this);
}

void GameObject::removeComponent(Component* component)
{
	// TODO: CHECK W/ BAR TO SEE IF THIS IS HOW I FREE MEMORY
	std::vector<Component*>::iterator it = std::find(components.begin(), components.end(), component);
	delete component;
	components.erase(it);
}

void GameObject::addChild(GameObject* toAdd)
{
	toAdd->setParent(this);
}

void GameObject::removeChild(GameObject* toRemove)
{
	toRemove->setParent(nullptr);
}

void GameObject::load()
{
}

void GameObject::init()
{
}

void GameObject::update(float deltaTime)
{
	for (int i = 0; i < components.size(); ++i)
	{
		components.at(i)->update(deltaTime);
	}
}

void GameObject::draw()
{
	Renderer::getInstance().renderMesh(size, position);
}

void GameObject::unload()
{
}
