#ifndef BODY_H
#define BODY_H

#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

class Body : public Component
{
private:
	glm::vec2 position;
	glm::vec2 acceleration;
public:
	glm::vec2 velocity;

	Body(glm::vec2 pos = glm::vec2(0.0f, 0.0f), glm::vec2 accel = glm::vec2(0.0f, 0.0f));
	~Body();

	void update(float deltaTime) override;

	Component* clone() override;
};

#endif