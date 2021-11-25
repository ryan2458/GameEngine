#include "RigidBody.h"
#include "GameObject.h"
#include <iostream>
#define M_PI 3.14159265358979323846  /* pi */

RigidBody::RigidBody(float posX, float posY, int type)
	: Component("RigidBody"), world(PhysicsWorld::getInstance().World), bodyDef(b2BodyDef()), mGravity(world->GetGravity()), body(nullptr)
{
	switch (type)
	{
	case 1:
		bodyDef.type = b2_staticBody;
		break;
	case 2:
		bodyDef.type = b2_dynamicBody;
		break;
	case 3:
		bodyDef.type = b2_kinematicBody;
		break;
	default:
		bodyDef.type = b2_staticBody;
		break;
	}

	box.SetAsBox(1.0f, 1.0f);
	bodyDef.position.Set(posX, posY);
	bodyDef.fixedRotation = false;
	bodyDef.angularDamping = 10000.0f;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &box;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 0.3f;

	body = PhysicsWorld::getInstance().CreateBody(&bodyDef);
	body->CreateFixture(&fixtureDef);
}

RigidBody::~RigidBody()
{
	world->DestroyBody(body);
}

void RigidBody::initBody()
{

}

b2Body& RigidBody::getBody()
{
	return *body;
}

void RigidBody::translate(float x, float y, float angle)
{
	float radians = angle * (double)(M_PI / 180.0);
	body->SetTransform(body->GetTransform().p + b2Vec2(x, y), radians);
}

void RigidBody::update(float deltaTime)
{
	GameObject* go = getGameObject();
	Transform* transform = go->getComponent<Transform>();
	
	b2Transform trans = body->GetTransform();
	transform->position.x = trans.p.x;
	transform->position.y = trans.p.y;
	transform->angle = (trans.q.GetAngle() * (double)(180.0/M_PI));

	std::cout << "( " << trans.p.x << ", " << trans.p.y << " )" << ", " << trans.q.GetAngle() << std::endl;
}

Component* RigidBody::clone()
{
	return nullptr;
}
