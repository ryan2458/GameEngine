#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"
#include "glm/vec2.hpp"
#include "GameObject.h"

class Collider : public Component
{
private:
	Transform* mTransform;
public:
	glm::vec2 position;
	float radius;

	Collider(glm::vec2 newPos, float newRadius);
	~Collider();

	void init() override;
	void update(float deltaTime) override;
	void setName(const std::string& newName);

	inline Component* clone() override { return nullptr; }
};

#endif