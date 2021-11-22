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

void testFunction(GLFWwindow* window, GameObjectManager* gom, GameObject* myObj);

int main()
{
	//Engine::getInstance().run(); THE GOAL
	GLFWwindow* window = WindowManager::getInstance().getWindow();

	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	gom->create();
	GameObject* myObj = gom->find("GameObject0");

	myObj->transform->scalar.x = 100.0;
	myObj->transform->scalar.y = 100.0;

	while (!glfwWindowShouldClose(window))
	{
		testFunction(window, gom, myObj); // BAD EXAMPLE, JUST FOR TESTING
		Input::getInstance().processBasicInput(WindowManager::getInstance().getWindow());
		Renderer::setBackgroundColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

		Engine::getInstance().gameObjectManager.draw();

		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

void testFunction(GLFWwindow* window, GameObjectManager* gom, GameObject* myObj)
{
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		myObj->transform->position.x -= 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		myObj->transform->position.x += 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		myObj->transform->position.y -= 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		myObj->transform->position.y += 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		myObj->transform->angle += 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		myObj->transform->angle -= 0.25;
	}
}