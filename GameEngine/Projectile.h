/*
Authors: Jordan Brooks, Anne Tansengco
*/

#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Component.h"
#include "Engine.h"


class Transform;

class Projectile : public Component
{
private:
	float rotation;
	float projectileSpeed;
public:
	Projectile(float angle = 0.0f, float speed = 10.0f);
	~Projectile() override;

	void update(float deltaTime) override;

	bool isVisible(Transform& transform, int width, int height);

	inline Component* clone() override { return nullptr; }
};

#endif