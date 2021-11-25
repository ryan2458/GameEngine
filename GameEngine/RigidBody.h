#ifndef RIGID_BODY_2D_H
#define RIGID_BODY_2D_H

#include "Component.h"
#include "PhysicsWorld.h"


class RigidBody : public Component
{
private:
	b2BodyDef bodyDef;
	b2Body* body;

	b2PolygonShape box; //outline of collider, move to BoxCollider
	//b2FixtureDef fixtureDef;

	b2World* const& world;
	b2Vec2 mGravity;
public:
	// NOTE: if unexpected behavior, look into scoped vs unscoped enums
	//static enum class Type { STATIC, DYNAMIC, KINEMATIC };

	RigidBody(float posX, float posY, int type = 1);
	~RigidBody();

	void initBody();
	b2Body& getBody();

	// TEMPORARY: removing later
	void translate(float x, float y, float angle);

	void update(float deltaTime) override;

	Component* clone() override;
};

#endif