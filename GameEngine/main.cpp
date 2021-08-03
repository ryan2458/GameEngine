#include "Engine.h"

#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "WindowManager.h"
#include "Renderer.h"

int main()
{
	//Engine::getInstance().run(); THE GOAL
	GLFWwindow* window = WindowManager::getInstance().getWindow();
	Shader shader("vertexShader.shader", "fragmentShader.shader");
	Texture texture("awesomeface.png");
	Mesh quadMesh;

	glm::vec2 position = glm::vec2(1.0f, 1.0f);
	glm::vec2 size = glm::vec2(100.0f, 100.0f);
	glm::vec4 tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	float angle = 180.0f;

	// TODO: ADD CAMERA WITH ORTHOGRAPHIC PROJECTION
	while (!glfwWindowShouldClose(window))
	{
		Renderer::setBackgroundColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

		// TODO: Add default texture (white square), default shader, default mesh (square mesh)
		//Renderer::renderMesh(size, position, angle, &quadMesh, &texture, &shader, tint);
		Renderer::renderMesh(size, position, angle);


		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

