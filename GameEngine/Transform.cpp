/*
Authors: Ryan Aloof, Jordan Brooks
*/

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

Transform& Transform::translate(const glm::vec3& vector)
{
	position += vector; // update position vector
	mTransform = glm::translate(mTransform, vector); // update position matrix with new vector
	return *this; // return reference to this to allow chained calls
}

Transform& Transform::rotate(const float angle)
{	
	rotation += angle; // update internal rotation

	glm::mat4 rot = glm::mat4(1.0f); // identity matrix
	rot = glm::translate(mTransform, glm::vec3(0.5f, 0.5f, 0.0f)); // offset to rotate about center of object
	rot = glm::rotate(rot, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate about z-axis
	mTransform = glm::translate(rot, glm::vec3(-0.5f, -0.5f, 0.0f)); // undo the offset

	return *this;
}

void Transform::scale(const glm::vec3& scale)
{
	scalar = scale; // set internal scale
	scalar.z = 1.0f; // avoids rendering issues
	mTransform = glm::scale(scalar); // apply scaling to transform matrix
}

// As it stands, I see no reason for this to be cloned.
Component* Transform::clone()
{
	return nullptr;
}
