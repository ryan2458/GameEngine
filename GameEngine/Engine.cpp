#include "Engine.h"
#include "Renderer.h"
#include "WindowManager.h"
#include "callbacks.h"


void Engine::run()
{
	Renderer::getInstance().renderEngine(WindowManager::getInstance().getWindow());
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
