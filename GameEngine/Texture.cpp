#include "Texture.h"

Texture::Texture(const std::string& path) : filepath(path), textureId(0), textureBuffer(nullptr),
	width(0), height(0), channels(0)
{
	generateTexture(path);
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureId);
}

void Texture::generateTexture(const std::string& path)
{
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	stbi_set_flip_vertically_on_load(false);

	textureBuffer = stbi_load(path.c_str(), &width, &height, &channels, 4);

	if (textureBuffer)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureBuffer);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	stbi_image_free(textureBuffer);
}

void Texture::bind() const
{
	glBindTexture(GL_TEXTURE_2D, textureId);
}

void Texture::unbind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}
