/*
Authors: Jordan Brooks, Anne Tansengco
File: Gun.h
Description: Contains header for code for a gun component
*/

#ifndef GUN_H
#define GUN_H

#include "Engine.h"
#include "Component.h"
#include "glm/vec3.hpp"

class Gun : public Component
{
private:
	GameObjectManager* gom;
	std::string projectileTag;
	std::string projectileTexture;
	float mTime;

	bool mIsAI; // is this a player or AI gun?
public:
	glm::vec3 position;
	float rotation;
	float FireRate;
	float projectileSize;
	float projectileAngle;

	Gun(float fireRate = 0.25f, float projectileAngle = 45.0f, float projectileSize = 50.0f, bool isAI = false, const std::string& projectileTag = "Friend", const std::string& texture = "square.png");
	~Gun();

	void update(float deltaTime) override;

	GameObject* createAndFireProjectile(float size = 50.0f);
	GameObject* createAndFireAIProjectile(float size = 25.0f);

	inline GameObjectManager* const getGameObjectManager() const { return gom; }
	inline void setProjectileTag(const std::string& tag) { projectileTag = tag; }
	inline void setProjectileTexture(const std::string& texture) { projectileTexture = texture; }
	inline Component* clone() override { return nullptr; }
};

#endif