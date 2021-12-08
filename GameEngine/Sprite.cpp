/*
Authors: Ryan Aloof, Anne Tansengco
*/

#include "Sprite.h"

Sprite::Sprite(const std::string& texturePath) : Component("Sprite"), mMesh(new Mesh()), mTexture(new Texture(texturePath))
{
}

Sprite::~Sprite()
{
	delete mTexture;
	delete mMesh;
}

void Sprite::swapTexture(const std::string& texturePath)
{
	delete mTexture; // deallocating old texture
	mTexture = new Texture(texturePath); // creating new texture
}

Component* Sprite::clone()
{
	return nullptr; // implemented to satisfy compiler
}
