#include "Engine.h"
#include "Gun.h"
#include "InputState.h"
#include "Body.h"
#include "Collider.h"
#include "Projectile.h"

Gun::Gun(float fireRate, const std::string& projectileTag, const std::string& texture) : Component("Gun"), position(glm::vec3(0.0f, 0.0f, 0.0f)), rotation(0.0f), gom(&Engine::getInstance().gameObjectManager),
	FireRate(fireRate), mTime(0.0f), projectileTag(projectileTag), projectileTexture(texture)
{
	setParent(gom->find("Ship"));
}

Gun::~Gun()
{
}

void Gun::update(float deltaTime)
{
	position = getGameObject()->transform->position;
	rotation = getGameObject()->transform->rotation;

	mTime += deltaTime;

	if (InputState::KeyPressed::space && mTime >= FireRate)
	{
		createAndFireProjectile();
		mTime = 0.0f;
	}
}

void Gun::createAndFireProjectile(float size)
{
	GameObject* projectile = gom->create(position, "Projectile");
	projectile->setParent(this);
	projectile->transform->rotate(rotation);
	projectile->addComponent(new Body());
	projectile->addComponent(new Projectile(rotation, 250.0f));
	projectile->addComponent(new Collider(glm::vec2(position.x, position.y), size / 2.0f));
	projectile->getComponent<Collider>()->setTag(projectileTag);
	projectile->init();
	projectile->sprite->swapTexture(projectileTexture);
}