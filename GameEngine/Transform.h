#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>

class Transform : public Component
{
private:
	glm::vec4 position;
	glm::vec3 scalar;
	float angle;

public:
	Transform();
	Transform(const Transform& copy);
	~Transform();

	Transform& operator=(const Transform& rhs);

	double getX() const;
	double getY() const;
	double getAngle() const;
	double getScaleX() const;
	double getScaleY() const;

	void setX(double newX);
	void setY(double newY);
	void setAngle(double newAngle);
	void setScaleX(double newScaleX);
	void setScaleY(double newScaleY);

	void translate(glm::vec3 vector);
	void rotate(float radians);
	void scale(glm::vec3 scalar);

	Component* clone() override;
};

#endif