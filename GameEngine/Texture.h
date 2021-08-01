#ifndef TEXTURE_H
#define TEXTURE_H

#include "Engine.h"

class Texture
{
private:
	std::string filepath;
	unsigned int textureId;
	unsigned char* textureBuffer;
	int width, height, channels;
public:
	Texture(const std::string& path);
	~Texture();
	void generateTexture(const std::string& path);


	inline int getWidth()  const { return width; }
	inline int getHeight() const { return height; }

	void bind() const;
	void unbind() const;
};



#endif