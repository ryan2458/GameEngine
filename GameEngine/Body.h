#ifndef BODY_H
#define BODY_H

#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

class Body : public Component
{
private:
	glm::vec3 position;
	glm::vec3 acceleration;
	float mass;
	float drag;
public:
	glm::vec3 velocity;

	Body(glm::vec3 pos = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 accel = glm::vec3(0.0f, 0.0f, 0.0f));
	~Body();

	void update(float deltaTime) override;

	Component* clone() override;
};

#endif