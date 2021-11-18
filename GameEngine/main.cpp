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

	Engine::getInstance().gameObjectManager.create();
	GameObject* myObj = Engine::getInstance().gameObjectManager.find("GameObject0");
	myObj->addComponent(new Transform());
	//myObj->addComponent(new Texture("awesomeface.png"));

	myObj->getComponent<Transform>()->setX(50.0);
	myObj->getComponent<Transform>()->setY(50.0);

	myObj->getComponent<Transform>()->setScaleX(100.0);
	myObj->getComponent<Transform>()->setScaleY(100.0);
	Transform* trans = myObj->getComponent<Transform>();

	while (!glfwWindowShouldClose(window))
	{
		if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
		{
			//trans->setX(trans->getX() - 0.25);
			trans->translate(glm::vec3(-0.25, 0, 0));
		}

		if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		{
			trans->setX(trans->getX() + 0.25);
		}

		if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
		{
			trans->setY(trans->getY() - 0.25);
		}

		if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
		{
			trans->setY(trans->getY() + 0.25);
		}

		if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
		{
			trans->setAngle(trans->getAngle() + 0.25);
		}

		if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
		{
			trans->setAngle(trans->getAngle() - 0.25);
		}

		Input::getInstance().processBasicInput(WindowManager::getInstance().getWindow());
		Renderer::setBackgroundColor(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

		Engine::getInstance().gameObjectManager.draw();

		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

