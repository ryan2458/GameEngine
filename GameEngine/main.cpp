#include "Engine.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "Component.h"
#include "Input.h"
#include "Movement.h"


int main()
{
	GLFWwindow* window = WindowManager::getInstance().getWindow();
	Engine* engine = &Engine::getInstance();
	
	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	gom->create();

	GameObject* myObj = gom->find("GameObject0");
	myObj->addComponent(new Body());
	myObj->addComponent(new Movement());
	//myObj->sprite->swapTexture("awesomeface.png");

	myObj->transform->scalar.x = 100.0;
	myObj->transform->scalar.y = 100.0;

	gom->init();

	while (!glfwWindowShouldClose(window))
	{
		Input::getInstance().processBasicInput(window);
		Renderer::setBackgroundColor(glm::vec4(0.1f, 0.3f, 0.3f, 1.0f));

		gom->update(engine->getDeltaTime());
		gom->draw();

		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}