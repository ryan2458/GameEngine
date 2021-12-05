#ifndef ASTEROID_SPAWNER_H
#define ASTEROID_SPAWNER_H

#include "Component.h"

class AsteroidSpawner : public Component
{
private:
	float timer;
public:

	AsteroidSpawner(float timer = 5.0f, int initialSpawnCount = 5);
	~AsteroidSpawner();

	void update(float deltaTime) override;

	void createAsteroid();


	inline Component* clone() override { return nullptr; }
};

#endif