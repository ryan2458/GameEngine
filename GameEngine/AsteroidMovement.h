#ifndef ASTEROID_MOVEMENT_H
#define ASTEROID_MOVEMENT_H

#include "Component.h"

class AsteroidMovement : public Component 
{
private:
	float mRotationAngle;
	float mForwardSpeed;
public:
	AsteroidMovement();
	~AsteroidMovement();

	void update(float deltaTime) override;
	inline float generateRandomAngle();

	inline Component* clone() override { return nullptr; }
};

#endif