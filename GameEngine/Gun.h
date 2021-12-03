#ifndef GUN_H
#define GUN_H

#include "Component.h"
#include "glm/vec3.hpp"

class Gun : public Component
{
private:
	GameObjectManager* gom;
	std::string projectileTag;
	std::string projectileTexture;
	float mTime;
public:
	glm::vec3 position;
	float rotation;
	float FireRate;

	Gun(float fireRate = 0.25f, const std::string& projectileTag = "Friend", const std::string& texture = "square.png");
	~Gun();

	void update(float deltaTime) override;

	void createAndFireProjectile(float size = 50.0f);

	inline void setProjectileTag(const std::string& tag) { projectileTag = tag; }
	inline Component* clone() override { return nullptr; }
};

#endif