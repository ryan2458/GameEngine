#include "Component.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"

std::string GameObject::generateDefaultName()
{
	static int count = 0;
	static std::string defaultName = "GameObject0";
	defaultName.back() = std::to_string(count).back();
	count += 1;

	return defaultName;
}

GameObject::GameObject() : BasedObject(generateDefaultName())
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
	glm::vec2 size = glm::vec2(getComponent<Transform>()->getScaleX(), getComponent<Transform>()->getScaleY());
	glm::vec2 position = glm::vec2(getComponent<Transform>()->getX(), getComponent<Transform>()->getY());
	float angle = getComponent<Transform>()->getAngle();
	Renderer::getInstance().renderMesh(size, position, angle);
}

void GameObject::unload()
{
}
