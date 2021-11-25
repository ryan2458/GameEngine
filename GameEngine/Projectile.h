#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "GameObject.h"

class Projectile : GameObject
{
private:
	glm::vec2 velocity;

public:
	Projectile(glm::vec2 vel);
	~Projectile();

	void update(float deltaTime) override;
};

#endif