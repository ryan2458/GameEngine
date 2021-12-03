#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Component.h"

class Projectile : public Component
{
private:
	float rotation;
	float projectileSpeed;
public:
	Projectile(float angle = 0.0f, float speed = 10.0f);
	~Projectile();

	void update(float deltaTime) override;

	inline Component* clone() override { return nullptr; }
};

#endif