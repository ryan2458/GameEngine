/*
Authors: Jordan Brooks, Anne Tansengco
*/

#include "Gun.h"
#include "InputState.h"
#include "Body.h"
#include "Collider.h"
#include "Projectile.h"
#include <cstdlib>

Gun::Gun(float fireRate, float projectileAngle, float projectileSize, bool isAI, const std::string& projectileTag, const std::string& texture) : Component("Gun"), position(glm::vec3(0.0f, 0.0f, 0.0f)), rotation(0.0f), gom(&Engine::getInstance().gameObjectManager),
	FireRate(fireRate), projectileAngle(projectileAngle), projectileSize(projectileSize), mTime(0.0f), mIsAI(isAI), projectileTag(projectileTag), projectileTexture(texture)
{
	setParent(gom->find("Ship"));
}

Gun::~Gun()
{
}

void Gun::update(float deltaTime)
{
	// update position and rotation of gun
	position = getGameObject()->transform->position;
	rotation = getGameObject()->transform->rotation;

	mTime += deltaTime;

	if (mTime >= FireRate)
	{
		// is this a player or an enemy ship?
		if (!mIsAI && InputState::KeyPressed::space)
		{
			createAndFireProjectile(projectileSize);
		}
		else if(mIsAI)
		{
			createAndFireAIProjectile(projectileSize);
		}

		mTime = 0.0f;
	}
}


GameObject* Gun::createAndFireProjectile(float size)
{
	// create a game object representing a projectile
	GameObject* gameObject = gom->create(position, "Projectile");
	gameObject->transform->rotate(rotation);
	gameObject->transform->scale(glm::vec3(size, size, 0.0f));

	// add components needed for projectile
	gameObject->addComponent(new Body());
	gameObject->addComponent(new Projectile(rotation, 250.0f));
	gameObject->addComponent(new Collider(glm::vec2(position.x, position.y), size / 2.0f));
	gameObject->getComponent<Collider>()->setTag(projectileTag);
	gameObject->init();
	gameObject->sprite->swapTexture(projectileTexture);

	return gameObject;
}

GameObject* Gun::createAndFireAIProjectile(float size)
{
	GameObject* gameObject = gom->create(position, "Projectile");
	gameObject->transform->rotate(projectileAngle);
	gameObject->transform->scale(glm::vec3(size, size, 0.0f));
	gameObject->addComponent(new Body());
	gameObject->addComponent(new Projectile(projectileAngle, 250.0f));
	gameObject->addComponent(new Collider(glm::vec2(position.x, position.y), size / 2.0f));
	gameObject->getComponent<Collider>()->setTag(projectileTag);
	gameObject->init();
	gameObject->sprite->swapTexture(projectileTexture);

	return gameObject;
}