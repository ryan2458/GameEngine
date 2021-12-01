#include "Component.h"
#include "WindowManager.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"

void checkPosition(Transform& transform);

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
	checkPosition(*transform);
	Renderer::getInstance().render(*transform, *sprite);
	//checkPosition(transform);
	//glm::vec2 size = glm::vec2(transform->scalar.x, transform->scalar.y);
	//glm::vec2 position = glm::vec2(transform->position.x, transform->position.y);
	//float angle = transform->angle;
	//Renderer::getInstance().render(size, position, angle, sprite);
}

void checkPosition(Transform& transform)
{
	int width, height;
    glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height);

	if (transform.position.x < 0.0f)
	{
		transform.trans(glm::vec3((float)width, 0.0f, 0.0f));
	}

	if (transform.position.x > (float)width)
	{
		transform.trans(glm::vec3(-(float)width, 0.0f, 0.0f));
	}

	if (transform.position.y < 0.0f)
	{
		transform.trans(glm::vec3(0.0f, (float)height, 0.0f));
	}

	if (transform.position.y > (float)height)
	{
		transform.trans(glm::vec3(0.0f, -(float)height, 0.0f));
	}
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
