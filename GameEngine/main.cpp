#include "Engine.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "Component.h"
#include "Input.h"
#include "GameObject.h"
#include "Transform.h"

int main()
{
	//Engine::getInstance().run(); THE GOAL
	GLFWwindow* window = WindowManager::getInstance().getWindow();
	Shader shader("vertex.shader", "fragment.shader");
	Texture texture("awesomeface.png");
	Mesh quadMesh;


	glm::vec2 position = glm::vec2(50.0f, 50.0f);
	glm::vec2 size = glm::vec2(100.0f, 100.0f);
	glm::vec4 tint = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	float angle = 180.0f;

	Engine::getInstance().gameObjectManager.create();
	//Engine::getInstance().gameObjectManager.create(&size, &position);
	GameObject* myObj = Engine::getInstance().gameObjectManager.find("GameObject0");
	myObj->addComponent(new Transform());

	myObj->getComponent<Transform>()->setX(50.0);
	myObj->getComponent<Transform>()->setY(50.0);

	myObj->getComponent<Transform>()->setScaleX(100.0);
	myObj->getComponent<Transform>()->setScaleY(100.0);

	while (!glfwWindowShouldClose(window))
	{
		Input::getInstance().processBasicInput(WindowManager::getInstance().getWindow());
		Renderer::setBackgroundColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

		/*Renderer::renderMesh(size, position, angle, nullptr, nullptr, nullptr, glm::vec4(0.2f, 0.3f, 0.1f, 1.0f));
		Renderer::renderMesh(size, glm::vec2(500.0f, 500.0f), 90.0f, nullptr, &texture);*/

		Engine::getInstance().gameObjectManager.draw();

		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

