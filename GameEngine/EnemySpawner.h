/*
Author: Jordan Brooks
*/

#ifndef ENEMY_SPAWNER_H
#define ENEMY_SPAWNER_H

#include "Component.h"

class GameObjectManager;

class EnemySpawner : public Component
{
private:
	GameObjectManager* gom;
	int spawnCount;
	int spawnTime;

public:
	EnemySpawner(int count, int time);
	~EnemySpawner() override;

	void update(float deltaTime) override;

	inline Component* clone() override { return nullptr; }
};

#endif