/*
Author: Ryan Aloof
Description: Handles logic for rendering and drawing objects to screen.  This class follows a singleton pattern
*/

#ifndef RENDERER_H
#define RENDERER_H

#include "Shader.h"
#include "Sprite.h"
#include "Transform.h"

class Renderer {
private:
	glm::mat4 projection;
	// these should not be changed
	Mesh defaultMesh;
	Texture defaultTexture;
	Shader defaultShader;
	// ---------------------------
	Renderer();
public:
	static Renderer& getInstance()
	{
		static Renderer instance;
		return instance;
	}

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete; // deletes instance if we reassign later

	// don't worry about implementing this
	void renderEngine(GLFWwindow* window);

	/*
	Description: sets the projection matrix for opengl to use
	*/
	void setProjectionMatrix(float width, float height);


	/*
	Description: sets background color of window using rgba
	*/
	static void setBackgroundColor(const glm::vec4& color);

	/*
	Function(s): render
	Params: overloaded, but ultimately makes call using a size, position, angle, Mesh, Texture, Shader, and tint
	Description: Handles logic to call into OpenGL to render and draw the object passed in from whichever draw() function
				 called render.  Implementation really isn't necessary for the user to know
	*/

	static void render(Transform& transform, Sprite& sprite, 
		Shader* shader = nullptr, 
		const glm::vec4& tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	static void render(Transform& transform, 
		Mesh* mesh = nullptr, 
		Texture* texture = nullptr, 
		Shader* shader = nullptr, 
		const glm::vec4& tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	static void render(const glm::vec2& size = glm::vec2(10.0f, 10.0f),
		const glm::vec2& position = glm::vec2(0.0f, 0.0f), 
		float angle = 90.0f,
		Mesh* mesh = nullptr,
		Texture* texture = nullptr,
		Shader* shader = nullptr,
		const glm::vec4& tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	static void render(const glm::vec2& size = glm::vec2(10.0f, 10.0f),
		const glm::vec2& position = glm::vec2(0.0f, 0.0f),
		float angle = 90.0f,
		Sprite* sprite = nullptr,
		Shader* shader = nullptr,
		const glm::vec4& tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
};

#endif