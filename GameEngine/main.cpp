#include "Engine.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "Component.h"
#include "Input.h"
#include "Movement.h"
#include "AsteroidMovement.h"

#include "irrklang/irrKlang.h"
irrklang::ISoundEngine* se = irrklang::createIrrKlangDevice();

void changeSong();

int main()
{
	GLFWwindow* window = WindowManager::getInstance().getWindow();
	Engine* engine = &Engine::getInstance();

	//se->play2D("splitters.mp3");

	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	gom->create();
	
	GameObject* myObj = gom->find("GameObject0");
	myObj->addComponent(new Body());
	myObj->addComponent(new Movement());
	myObj->sprite->swapTexture("spaceship.png");
	//myObj->transform->trans(glm::vec3(0.0f, 0.0f, 0.0f));
	myObj->transform->scale(glm::vec3(50.0f, 50.0f, 0.0f));


	gom->create();
	GameObject* asteroid = gom->find("GameObject1");
	asteroid->addComponent(new Body());
	asteroid->addComponent(new AsteroidMovement());
	asteroid->sprite->swapTexture("awesomeface.png");











	gom->init();

	while (!glfwWindowShouldClose(window))
	{
		changeSong();
		Input::getInstance().processBasicInput(window);
		Renderer::setBackgroundColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));

		gom->update(engine->getDeltaTime());
		gom->draw();

		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

void changeSong()
{

	if (InputState::KeyPressed::key_1)
	{
		if (!se->isCurrentlyPlaying("space.mp3"))
		{
			se->stopAllSounds();
			se->play2D("space.mp3", true);
		}
			
	}

	if (InputState::KeyPressed::key_2)
	{
		if (!se->isCurrentlyPlaying("lava.mp3"))
		{ 
			se->stopAllSounds();
			se->play2D("lava.mp3", true);
		}
			
	}

	if (InputState::KeyPressed::key_3)
	{
		if (!se->isCurrentlyPlaying("yellow.mp3"))
		{
			se->stopAllSounds();
			se->play2D("yellow.mp3", true);
		}	
	}

	if (InputState::KeyPressed::key_4)
	{
		if (!se->isCurrentlyPlaying("splitters.mp3"))
		{
			se->stopAllSounds();
			se->play2D("splitters.mp3", true);
		}
	}
}