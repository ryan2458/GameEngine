#include "Renderer.h"

Renderer::Renderer() : defaultTexture(Texture("awesomeface.png")), defaultShader(Shader("vertex.shader", "fragment.shader")),
	defaultMesh(Mesh()) // initializing with mesh not needed, but added for style
{
	std::cout << "LOG: New Renderer Instantiated." << std::endl;
	setProjectionMatrix(800.0f, 600.0f);
}

void Renderer::renderEngine(GLFWwindow* window)
{
}

void Renderer::setProjectionMatrix(float width, float height)
{
	projection = glm::ortho(0.0f, width, height, 0.0f, -1.0f, 1.0f);
}

void Renderer::setBackgroundColor(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::render(const glm::vec2& size, const glm::vec2& position,
	float angle, Mesh* mesh, Texture* texture, Shader* shader, const glm::vec4& tint)
{
	if (mesh == nullptr)
	{
		mesh = &Renderer::getInstance().defaultMesh;
	}
	if (texture == nullptr)
	{
		texture = &Renderer::getInstance().defaultTexture;
	}
	if (shader == nullptr)
	{
		shader = &Renderer::getInstance().defaultShader;
	}

	shader->use();
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(position, 0.0f));

	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

	model = glm::scale(model, glm::vec3(size, 1.0f));

	shader->setMatrix4("model", model);
	shader->setMatrix4("projection", getInstance().projection);
	shader->setVector4f("spriteColor", tint);

	if (texture != nullptr)
	{
		glActiveTexture(GL_TEXTURE0);
		texture->bind();
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	mesh->bind();

	glDrawArrays(GL_TRIANGLES, 0, 6);
	mesh->unbind();

	if (texture != nullptr)
	{
		texture->unbind();
	}
}

void Renderer::render(const glm::vec2& size, const glm::vec2& position, float angle, 
	Sprite* sprite, Shader* shader, const glm::vec4& tint)
{
	render(size, position, angle, sprite->getMesh(), sprite->getTexture(), shader, tint);
}


