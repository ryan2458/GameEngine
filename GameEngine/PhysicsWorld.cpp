#include "PhysicsWorld.h"

PhysicsWorld::PhysicsWorld() : mGravity(b2Vec2(0.0f, 0.0f)), 
	mWorld(mGravity), World(&mWorld), velocityIterations(6), positionIterations(2)
{	
}

PhysicsWorld::~PhysicsWorld()
{
	/*while (!mBodies.empty())
	{
		World->DestroyBody(mBodies.back());
		mBodies.pop_back();
	}*/
}

//void PhysicsWorld::addBody(b2Body* body)
//{
//	mBodies.push_back(body);
//}
//
//void PhysicsWorld::removeBody(b2Body* body)
//{
//	std::vector<b2Body*>::iterator it = std::find(mBodies.begin(), mBodies.end(), body);
//	World->DestroyBody(body);
//	mBodies.erase(it);
//}

b2Body* PhysicsWorld::CreateBody(b2BodyDef* bodyDef)
{
	return mWorld.CreateBody(bodyDef);
}

void PhysicsWorld::Step()
{
	mWorld.Step(1.0f / 60.0f, velocityIterations, positionIterations);
}
