#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Body.h"
#include "InputState.h"

class Movement : public Component
{
private:
	Body* mBody;
	Transform* mTransform;
	float mSpeed;
	float mRotationSpeed;
public:
	
	Movement(float speed = 25.00f, float rotationSpeed = 100.00f);
	~Movement();

	void init() override;
	void update(float deltaTime) override;

	Component* clone() override;
};

#endif