/*
Author: Nick Gerth
Last Edit: 12/3/2021
File: AsteroidSpawner.h
Description: Contains header for AsteroidSpawner.cpp
*/

#ifndef ASTEROID_SPAWNER_H
#define ASTEROID_SPAWNER_H

#include "Component.h"

class AsteroidSpawner : public Component
{
private:
	float timer;
public:

	AsteroidSpawner(float timer = 5.0f, int initialSpawnCount = 5);
	~AsteroidSpawner() override;

	// called each frame
	void update(float deltaTime) override;

	void createAsteroid();

	// clone is not used, but must be implemented since it's pure virtual in Component class
	inline Component* clone() override { return nullptr; }
};

#endif