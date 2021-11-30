#ifndef ASTEROID_MOVEMENT_H
#define ASTEROID_MOVEMENT_H

#include "Component.h"

class AsteroidMovement : public Component 
{
public:
	AsteroidMovement();
	~AsteroidMovement();

	void update(float deltaTime) override;

	inline Component* clone() override { return nullptr; }
};

#endif