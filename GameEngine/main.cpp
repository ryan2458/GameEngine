#include "Engine.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "Component.h"
#include "Input.h"
#include "Movement.h"

void testFunction(GLFWwindow* window, GameObjectManager* gom, GameObject* myObj);

int main()
{
	//Engine::getInstance().run(); THE GOAL
	GLFWwindow* window = WindowManager::getInstance().getWindow();

	Engine* engine = &Engine::getInstance();
	
	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	gom->create();
	GameObject* myObj = gom->find("GameObject0");
	myObj->addComponent(new Body());
	myObj->addComponent(new Movement());

	myObj->transform->scalar.x = 100.0;
	myObj->transform->scalar.y = 100.0;

	gom->init();

	while (!glfwWindowShouldClose(window))
	{
		Input::getInstance().processBasicInput(window);
		//testFunction(window, gom, myObj);
		Renderer::setBackgroundColor(glm::vec4(0.1f, 0.3f, 0.3f, 1.0f));

		gom->update(engine->getDeltaTime());
		gom->draw();

		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

void testFunction(GLFWwindow* window, GameObjectManager* gom, GameObject* myObj)
{
	Body* body = myObj->getComponent<Body>();


	if (InputState::KeyPressed::left)
	{
		body->velocity.x -= 0.25f;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		body->velocity.x += 0.25f;
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		body->velocity.y -= 0.25f;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		body->velocity.y += 0.25f;
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