#ifndef TEXTURE_H
#define TEXTURE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include <string>

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
	inline std::string getTexturePath() const { return filepath; }

	void bind() const;
	void unbind() const;
};



#endif