#include "Texture.h"

Texture::Texture(const std::string& path) : filepath(path), ID(0), textureBuffer(nullptr),
	width(0), height(0), channels(0)
{
	generateTexture(path);
}

Texture::~Texture()
{
	glDeleteTextures(1, &ID);
}

void Texture::generateTexture(const std::string& path)
{
	glGenTextures(1, &ID);
	glBindTexture(GL_TEXTURE_2D, ID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	stbi_set_flip_vertically_on_load(true);

	textureBuffer = stbi_load(path.c_str(), &width, &height, &channels, 4);

	if (textureBuffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(textureBuffer);
}