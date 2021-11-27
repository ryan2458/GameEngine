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

GameObject::GameObject() : BasedObject(generateDefaultName()), transform(dynamic_cast<Transform*>(addComponent(new Transform()))),
	sprite(dynamic_cast<Sprite*>(addComponent(new Sprite())))	
{

}

GameObject::~GameObject()
{
	destroy();
}

Component* GameObject::addComponent(Component* component)
{
	components.push_back(component);
	component->setParent(this);
	return component;
}

void GameObject::removeComponent(Component* component)
{
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
	for (Component* comp : components)
	{
		comp->load();
	}
}

void GameObject::init()
{
	for (Component* comp : components)
	{
		comp->init();
	}
}

void GameObject::update(float deltaTime)
{
	for (Component* comp : components)
	{
		comp->update(deltaTime);
	}
}

void GameObject::draw()
{
	glm::vec2 size = glm::vec2(transform->scalar.x, transform->scalar.y);
	glm::vec2 position = glm::vec2(transform->position.x, transform->position.y);
	float angle = transform->angle;
	Renderer::getInstance().render(size, position, angle, sprite);
}

void GameObject::unload()
{
	for (Component* comp : components)
	{
		comp->unload();
	}
}

void GameObject::destroy()
{
	unload();
	while (!components.empty())
	{
		removeComponent(components.back());
	}
}
