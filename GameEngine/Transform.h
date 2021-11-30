#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>

class Transform : public Component
{
public:
	glm::vec4 position;
	glm::vec3 scalar;
	float angle;

	Transform();
	~Transform();

	// keeping these for now just in case
	void translate(glm::vec3 vector);
	void rotate(float radians);
	void scale(glm::vec3 scalar);

	Component* clone() override;
};

#endif