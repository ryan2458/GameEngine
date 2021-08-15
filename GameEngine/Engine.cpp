#include "Engine.h"
#include "Renderer.h"
#include "WindowManager.h"


void Engine::run()
{
	Renderer::getInstance().render(WindowManager::getInstance().getWindow());
}

float Engine::getDeltaTime()
{
	float finalTime = glfwGetTime();
	float deltaTime = finalTime - initialTime;
	initialTime = finalTime;
	return deltaTime;
}

Engine::Engine() : BasedObject("Engine"), initialTime(glfwGetTime())
{
	std::cout << "LOG: New Engine Instantiated." << std::endl;
	gameObjectManager.setParent(this);
}

Engine::~Engine()
{
}
