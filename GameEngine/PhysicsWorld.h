#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include "box2d/box2d.h"
#include <vector>

class PhysicsWorld
{
private:
	b2Vec2 mGravity;
	b2World mWorld;

	int32 velocityIterations;
	int32 positionIterations;

	//std::vector<b2Body*> mBodies;

	PhysicsWorld();
	~PhysicsWorld();

public:
	b2World* const& World;

	static PhysicsWorld& getInstance()
	{
		static PhysicsWorld instance;
		return instance;
	}

	b2Body* CreateBody(b2BodyDef* bodyDef);

	//void addBody(b2Body* body);
	//void removeBody(b2Body* body);

	void Step();

	PhysicsWorld(PhysicsWorld const&) = delete;
	void operator=(PhysicsWorld const&) = delete;
};

#endif