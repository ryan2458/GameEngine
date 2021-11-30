#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

Transform::Transform() : Component("Transform"), position(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), 
	scalar(glm::vec3(50.0f, 50.0f, 1.0f)), 
	angle(0.0f)
{
	
}

Transform::~Transform()
{
}

void Transform::translate(glm::vec3 vector)
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, vector);
	position = trans * position;
}

void Transform::rotate(float angle)
{
	glm::mat4 rot = glm::mat4(1.0f);
	rot = glm::rotate(glm::radians(angle), glm::vec3(position.x, position.y, position.z));
	position = rot * position;
}

void Transform::scale(glm::vec3 scalar)
{
}

// As it stands, I see no reason for this to be cloned.
Component* Transform::clone()
{
	return nullptr;
}
