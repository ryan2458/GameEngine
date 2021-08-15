#include "Transform.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Transform::Transform() : Component("Transform"), position(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)), 
	scale(glm::vec3(0.5f, 0.5f, 0.5f)), 
	angle(90.0f)
{

}

Transform::~Transform()
{
}

double Transform::getX()
{
	return position.x;
}

double Transform::getY()
{
	return position.y;
}

double Transform::getAngle()
{
	return angle;
}

double Transform::getScaleX()
{
	return scale.x;
}

double Transform::getScaleY()
{
	return scale.y;
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
	scale.x = newScaleX;
}

void Transform::setScaleY(double newScaleY)
{
	scale.y = newScaleY;
}

void Transform::translate(glm::vec3 vector)
{
	glm::mat4 trans = glm::mat4(1.0f);
	trans = glm::translate(trans, vector);
	position = trans * position;
}
