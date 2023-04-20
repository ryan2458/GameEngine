/*
Authors: Ryan Aloof, Anne Tansengco
*/

#ifndef SPRITE_H
#define SPRITE_H

#include "Component.h"
#include "Mesh.h"
#include "Texture.h"

class Sprite : public Component
{
private:
	Mesh* mMesh;
	Texture* mTexture;

public:
	Sprite(const std::string& texturePath = "square.png");
	~Sprite() override;

	void swapTexture(const std::string& texturePath);

	inline Texture* const getTexture() const { return mTexture; }
	inline Mesh* const getMesh() const { return mMesh; }

	Component* clone() override;
};

#endif