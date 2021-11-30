#include "Component.h"
#include "WindowManager.h"
#include "GameObject.h"
#include "Renderer.h"
#include "Transform.h"

bool isVisible(glm::vec4& position, int width, int height);
void checkPosition(Transform* transform);

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
	checkPosition(transform);
	glm::vec2 size = glm::vec2(transform->scalar.x, transform->scalar.y);
	glm::vec2 position = glm::vec2(transform->position.x, transform->position.y);
	float angle = transform->angle;
	Renderer::getInstance().render(size, position, angle, sprite);
}

void checkPosition(Transform* transform)
{
	int width, height;
	glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height);

	if (transform->position.x < -50.0f)
	{
		transform->translate(glm::vec3((float)width, transform->position.y, 0.0f));
	}
	else if (transform->position.x > (float)width + 50.0f)
	{
		transform->translate(glm::vec3(0.0f, transform->position.y, 0.0f));
	}
	else if (transform->position.y < -50.0f)
	{
		transform->translate(glm::vec3(transform->position.x, (float)height, 0.0f));
	}
	else if (transform->position.y > (float)height + 50.0f)
	{
		int x = transform->position.x;
		//transform->translate(glm::vec3(0.0f, 0.0f, 0.0f));
		transform->translate(glm::vec3(x, 0.0f, 0.0f));
	}
}

bool isVisible(glm::vec4& position, int width, int height)
{
	return (position.x > 0 && position.x < width) && (position.y > 0 && position.y < height);
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
