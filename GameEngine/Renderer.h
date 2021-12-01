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

	void setProjectionMatrix(float width, float height);

	static void setBackgroundColor(const glm::vec4& color);

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