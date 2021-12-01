#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>

Transform::Transform() : Component("Transform"), mTransform(glm::mat4(1.0f)), position(glm::vec3(0.0f, 0.0f, 0.0f)),
	scalar(glm::vec3(50.0f, 50.0f, 1.0f)), 
	rotation(0.0f)
{
	
}

Transform::~Transform()
{
}

Transform& Transform::trans(const glm::vec3& vector)
{
	position += vector;
	mTransform = glm::translate(mTransform, vector);
	return *this;
}

//void Transform::translate(glm::vec3 vector)
//{
//	glm::mat4 trans = glm::mat4(1.0f);
//	trans = glm::translate(trans, vector);
//	position = trans * position;
//}

Transform& Transform::rotate(const float angle)
{	
	rotation += angle;

	glm::mat4 rot = glm::mat4(1.0f);
	rot = glm::translate(mTransform, glm::vec3(0.5f, 0.5f, 0.0f));
	rot = glm::rotate(rot, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	mTransform = glm::translate(rot, glm::vec3(-0.5f, -0.5f, 0.0f));

	return *this;
}

void Transform::scale(const glm::vec3& scale)
{
	scalar = scale;
	scalar.z = 1.0f;
	mTransform = glm::scale(scalar);
}

// As it stands, I see no reason for this to be cloned.
Component* Transform::clone()
{
	return nullptr;
}
