#ifndef BODY_H
#define BODY_H

#include "Component.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Body : public Component
{
private:
	// planned to implement, never implemented
	float mass;
	float drag;
public:
	glm::vec3 velocity;
	glm::vec3 acceleration;

	Body(glm::vec3 accel = glm::vec3(0.0f, 0.0f, 0.0f));
	~Body();

	void update(float deltaTime) override;

	Component* clone() override;
};

#endif