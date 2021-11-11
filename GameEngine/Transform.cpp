#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Transform::Transform() : Component("Transform"), position(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), 
	scalar(glm::vec3(0.5f, 0.5f, 1.0f)), 
	angle(90.0f)
{
	
}

Transform::Transform(const Transform& copy) : Component(copy.getName())
{
	*this = copy;
}

Transform::~Transform()
{
}

Transform& Transform::operator=(const Transform& rhs)
{
	if (this != &rhs)
	{
		position = glm::vec4(rhs.getX(), rhs.getY(), 0.0f, 1.0f);
		scalar = glm::vec3(rhs.getScaleX(), rhs.getScaleY(), 1.0f);
		angle = rhs.getAngle();
	}

	return *this;
}

double Transform::getX() const
{
	return position.x;
}

double Transform::getY() const
{
	return position.y;
}

double Transform::getAngle() const
{
	return angle;
}

double Transform::getScaleX() const
{
	return scalar.x;
}

double Transform::getScaleY() const
{
	return scalar.y;
}

void Transform::setX(double newX)
{
	position.x = newX;
}

void Transform::setY(double newY)
{
	position.y = newY;
}

void Transform::setAngle(double newAngle)
{
	angle = newAngle;
}

void Transform::setScaleX(double newScaleX)
{
	scalar.x = newScaleX;
}

void Transform::setScaleY(double newScaleY)
{
	scalar.y = newScaleY;
}

void Transform::translate(glm::vec3 vector)
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, vector);
	position = trans * position;
}

void Transform::rotate(float radians)
{

}

void Transform::scale(glm::vec3 scalar)
{
}

Component* Transform::clone()
{
	return nullptr;
}
