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
public:
	
	Movement(float speed = 0.25f);
	~Movement();

	void init() override;
	void update(float deltaTime) override;

	Component* clone() override;
};

#endif