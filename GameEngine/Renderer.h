#ifndef RENDERER_H
#define RENDERER_H

#include "Engine.h"
#include "Mesh.h"

class Texture;
class Shader;

class Renderer {
private:
	glm::mat4 projection;
	Renderer();
public:
	static Renderer& getInstance()
	{
		static Renderer instance;
		return instance;
	}

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete; // deletes instance if we reassign later

	void setProjectionMatrix(float width, float height);

	// begins the render loop
	void render(GLFWwindow* window);
	void renderTextures();

	static void setBackgroundColor(const glm::vec4& color);
	static void renderMesh(Mesh& mesh, const glm::vec2& size = glm::vec2(10.0f, 10.0f),
		const glm::vec2& position = glm::vec2(0.0f, 0.0f), 
		float angle = 90.0f,
		Texture* texture = nullptr,
		Shader* shader = nullptr,
		const glm::vec4& tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
};

#endif