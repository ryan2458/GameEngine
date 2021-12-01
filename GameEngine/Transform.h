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
	~Transform();

	Transform& trans(const glm::vec3& vector);
	// keeping these for now just in case
	//void translate(glm::vec3 vector);
	//Transform& translate(const glm::vec3& vector);
	Transform& rotate(const float angle);
	void scale(const glm::vec3& scale);

	Component* clone() override;
};

#endif