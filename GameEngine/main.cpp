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
#include "Gun.h"
#include <cstdlib>
#include <ctime>

#include "irrklang/irrKlang.h"
irrklang::ISoundEngine* se = irrklang::createIrrKlangDevice();

void changeSong();
void createAsteroids(GameObjectManager* gom, int count, int maxSize);
void createShip(GameObjectManager* gom, int size);

int main()
{
	srand((unsigned int)time(NULL));
	GLFWwindow* window = WindowManager::getInstance().getWindow();
	Engine* engine = &Engine::getInstance();

	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	
	createShip(gom, 50.0f);
	createAsteroids(gom, 10, 100);

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

void createAsteroids(GameObjectManager* gom, int count, int maxSize)
{
	for (int i = 0; i < count; ++i)
	{
		float randSize = (float)(rand() % maxSize) + 50;
		float randRotation = (float)(rand() % 360) + 1;
		GameObject* asteroid = gom->create("Asteroid");
		asteroid->addComponent(new Body());
		asteroid->addComponent(new AsteroidMovement());
		asteroid->addComponent(new Collider(glm::vec2(asteroid->transform->position.x, asteroid->transform->position.y), randSize / 2.0f));
		asteroid->getComponent<Collider>()->setTag("Enemy");
		asteroid->transform->scale(glm::vec3(randSize, randSize, 0.0f));
		asteroid->transform->rotate(randRotation);
		asteroid->sprite->swapTexture("asteroid.png");
	}
}

void createShip(GameObjectManager* gom, int size)
{
	int width, height;
	glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height);

	GameObject* ship = gom->create(glm::vec3((float)width / 2.0f, (float)height / 2.0f, 0.0f), "Ship");
	ship->transform->scale(glm::vec3(size, size, 0.0f));
	ship->addComponent(new Body());
	ship->addComponent(new Movement());
	ship->addComponent(new Collider(glm::vec2(ship->transform->position.x, ship->transform->position.y), size / 2.0f));
	ship->addComponent(new Gun());
	ship->getComponent<Collider>()->setTag("Friend");
	ship->getComponent<Gun>()->rotation = 90.0f;
	ship->sprite->swapTexture("spaceship.png");
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