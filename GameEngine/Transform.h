/*
Authors: Ryan Aloof, Jordan Brooks
*/

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>

class Transform : public Component
{
public:
	glm::mat4 mTransform;
	glm::vec3 position;
	glm::vec3 scalar;
	float rotation;

	Transform();
	~Transform() override;

	Transform& translate(const glm::vec3& vector);
	Transform& rotate(const float angle);
	void scale(const glm::vec3& scale);

	Component* clone() override;
};

#endif