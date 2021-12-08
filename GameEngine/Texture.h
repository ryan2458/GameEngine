/*
Author: Ryan Aloof
File: Texture.h
Description: Handles logic for creating and binding/unbinding textures in opengl
*/

#ifndef TEXTURE_H
#define TEXTURE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include <string>

class Texture
{
private:
	// where the texture is located
	std::string filepath;
	// id associated with the texture
	unsigned int textureId;
	// texture buffer for opengl
	unsigned char* textureBuffer;
	// width, height, and number of color channels
	int width, height, channels;
public:
	Texture(const std::string& path);
	~Texture();

	// generates a texture using the specified file path
	void generateTexture(const std::string& path);

	inline int getWidth()  const { return width; }
	inline int getHeight() const { return height; }
	inline std::string getTexturePath() const { return filepath; }

	// binds the texture
	void bind() const;
	// unbinds the texture
	void unbind() const;
};



#endif