/*
Author: Nick Gerth
*/

#ifndef COLLIDER_H
#define COLLIDER_H

#include "Component.h"
#include "glm/vec2.hpp"
#include "GameObject.h"

class Collider : public Component
{
private:
	std::string collisionTag;
public:
	glm::vec2 position;
	float radius;

	Collider(glm::vec2 newPos, float newRadius);
	~Collider();

	void update(float deltaTime) override;
	void setName(const std::string& newName);

	inline void setTag(const std::string& tag) { collisionTag = tag; }
	inline const std::string& getTag() const { return collisionTag; }

	inline Component* clone() override { return nullptr; }
};

#endif