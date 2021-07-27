#include "Engine.h"
#include "Renderer.h"
#include "WindowManager.h"


void Engine::run()
{
	Renderer::getInstance().render(WindowManager::getInstance().getWindow());
}