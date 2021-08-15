#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>

class Transform : public Component
{
private:
	glm::vec4 position;
	glm::vec3 scale;
	float angle;

public:
	Transform();
	~Transform();

	double getX();
	double getY();
	double getAngle();
	double getScaleX();
	double getScaleY();

	void setX(double newX);
	void setY(double newY);
	void setAngle(double newAngle);
	void setScaleX(double newScaleX);
	void setScaleY(double newScaleY);

	void translate(glm::vec3 vector);
	void rotate(float radians);
	void scale(glm::vec3 scalar);
};

#endif