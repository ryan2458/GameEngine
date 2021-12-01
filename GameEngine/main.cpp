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
#include "Collider.h"
#include <cstdlib>
#include <ctime>

#include "irrklang/irrKlang.h"
irrklang::ISoundEngine* se = irrklang::createIrrKlangDevice();

void changeSong();

int main()
{
	srand((unsigned int)time(NULL));
	GLFWwindow* window = WindowManager::getInstance().getWindow();
	Engine* engine = &Engine::getInstance();

	//se->play2D("splitters.mp3");

	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	gom->create();
	
	GameObject* myObj = gom->find("GameObject0");
	myObj->addComponent(new Body());
	myObj->addComponent(new Movement());
	myObj->addComponent(new Collider(glm::vec2(myObj->transform->position.x, myObj->transform->position.y), 25.0f));
	myObj->sprite->swapTexture("spaceship.png");
	//myObj->transform->trans(glm::vec3(0.0f, 0.0f, 0.0f));
	myObj->setName("Ship");
	myObj->transform->trans(glm::vec3(400.0f, 300.0f, 0.0f));

	gom->create();
	GameObject* asteroid = gom->find("GameObject1");
	asteroid->addComponent(new Body());
	asteroid->addComponent(new AsteroidMovement());
	asteroid->sprite->swapTexture("awesomeface.png");
	asteroid->addComponent(new Collider(glm::vec2(asteroid->transform->position.x, asteroid->transform->position.y), 25.0f));
	asteroid->setName("Asteroid");

	gom->create();
	GameObject* asteroid2 = gom->find("GameObject2");
	asteroid2->addComponent(new Body());
	asteroid2->addComponent(new AsteroidMovement());
	asteroid2->sprite->swapTexture("awesomeface.png");
	asteroid2->addComponent(new Collider(glm::vec2(asteroid2->transform->position.x, asteroid2->transform->position.y), 25.0f));
	asteroid2->setName("Asteroid");


	gom->create();
	GameObject* asteroid3 = gom->find("GameObject3");
	asteroid3->addComponent(new Body());
	asteroid3->addComponent(new AsteroidMovement());
	asteroid3->sprite->swapTexture("awesomeface.png");
	asteroid3->addComponent(new Collider(glm::vec2(asteroid3->transform->position.x, asteroid3->transform->position.y), 25.0f));
	asteroid3->setName("Asteroid");


	gom->create();
	GameObject* asteroid4 = gom->find("GameObject4");
	asteroid4->addComponent(new Body());
	asteroid4->addComponent(new AsteroidMovement());
	asteroid4->sprite->swapTexture("awesomeface.png");
	asteroid4->addComponent(new Collider(glm::vec2(asteroid4->transform->position.x, asteroid4->transform->position.y), 25.0f));
	asteroid4->setName("Asteroid");



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