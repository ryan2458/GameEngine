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
	delete mTexture;
	mTexture = new Texture(texturePath);
}

Component* Sprite::clone()
{
	return nullptr;
}
