#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "Body.h"
#include "InputState.h"
#include "Transform.h"

class Movement : public Component
{
private:
	Body* mBody;
	Transform* mTransform;
	float mSpeed;
	float mRotationSpeed;

public:
	
	Movement(float speed = 100.00f, float rotationSpeed = 200.00f);
	~Movement();

	void init() override;
	void update(float deltaTime) override;

	Component* clone() override;
};

#endif