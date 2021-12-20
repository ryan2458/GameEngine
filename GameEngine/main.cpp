/*
Author: Ryan Aloof
Last Edit: 12/5/2021
File: main.cpp
Description: Handles all initial calls for creation of Game Engine and Game Objects to start a game of Asteroids
*/

#include "UnitTest.h"
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
#include "EnemySpawner.h"
#include "AsteroidSpawner.h"
#include <cstdlib>
#include <ctime>

#include "irrklang/irrKlang.h"
irrklang::ISoundEngine* se = irrklang::createIrrKlangDevice();

void changeSong();

// defined in order needed to be called for drawing
void createBackground(GameObjectManager* gom);
void createAsteroids(GameObjectManager* gom, int count, int maxSize);
void createPlayerShip(GameObjectManager* gom, int size);
void createSpawners(GameObjectManager* gom);


int main()
{
	srand((unsigned int)time(NULL)); // std::rand() is used in the application, so set the seed

	UnitTest test;
	
	if (test.passed())
	{
		std::cout << "LOG: TEST CASES::PASSED" << std::endl;
	}
	else
	{
		std::cout << "ERROR: TEST CASES::FAILED" << std::endl;
		glfwTerminate();
		return 0;
	}

	GLFWwindow* window = WindowManager::getInstance().getWindow(); // first call to getInstance() creates window
	Engine* engine = &Engine::getInstance(); // first call to getInstance() creates an Engine

	//se->play2D("splitters.mp3", true);

	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	
	/**** Setup objects at start of game ****/
	createBackground(gom);
	createPlayerShip(gom, 50.0f);
	createSpawners(gom);

	// Initializes all objects
	gom->init();

	// main render loop, one iteration is a single frame
	while (!glfwWindowShouldClose(window))
	{
		changeSong(); // allows user to press number keys to change the song playing
		Input::getInstance().processBasicInput(window); // listens for all keyboard input
		Renderer::setBackgroundColor(glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)); // sets background to black

		// update properties of all game objects and draw them to the screen
		gom->update(engine->getDeltaTime());
		gom->draw();

		WindowManager::getInstance().endFrame(); // endFrame() abstracts away some openGL calls
	}

	glfwTerminate();
	return 0;
}

/*
Function: createSpawners()
params: pointer to a GameObjectManager
pre-condition: an Engine must be instantiated to retrieve GameObjectManager
Description: Creates the game objects that hold the spawn component responsible for creating enemies and asteroids
*/
void createSpawners(GameObjectManager* gom)
{
	// z-coord in create is set to 2.0f so the GameObject isn't visible on the screen
	GameObject* asteroidSpawner = gom->create(glm::vec3(0.0f, 0.0f, 2.0f), "AsteroidSpawner");
	asteroidSpawner->addComponent(new AsteroidSpawner());

	GameObject* spawner = gom->create(glm::vec3(0.0f, 0.0f, 2.0f), "EnemySpawner");
	spawner->addComponent(new EnemySpawner(1, 5.0f));
}

/*
Function: createBackground()
params: pointer to a GameObjectManager
pre-condition: an Engine must be instantiated to retrieve GameObjectManager
Description: responsible for creating the background space image that is drawn below all other objects
*/
void createBackground(GameObjectManager* gom)
{
	GameObject* go = gom->create("Background");
	go->sprite->swapTexture("space.jpg");
	go->transform->translate(glm::vec3(0.0f, 0.0f, 0.0f));
	go->transform->scale(glm::vec3(1920.0f, 1080.0f, 0.0f));
}

/*
Function: createAsteroids()
params: pointer to a GameObjectManager, the number of asteroids to create, the max size of the asteroids
pre-condition: an Engine must be instantiated to retrieve GameObjectManager
Description: Creates asteroid objects with random size and rotations
*/
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

/*
Function: createPlayerShip()
params: pointer to a GameObjectManager, the size of the ship
pre-condition: an Engine must be instantiated to retrieve GameObjectManager
Description: creates a player ship and adds components needed for a player ship
*/
void createPlayerShip(GameObjectManager* gom, int size)
{
	int width, height;
	glfwGetWindowSize(WindowManager::getInstance().getWindow(), &width, &height);

	// spawns ship at center of screen
	GameObject* ship = gom->create(glm::vec3((float)width / 2.0f, (float)height / 2.0f, 0.0f), "Ship");

	ship->transform->scale(glm::vec3(size, size, 0.0f));
	ship->addComponent(new Body());
	ship->addComponent(new Movement());
	ship->addComponent(new Collider(glm::vec2(ship->transform->position.x, ship->transform->position.y), size / 2.0f));
	ship->addComponent(new Gun(0.0f, 45.0f, 25.0f));
	ship->getComponent<Collider>()->setTag("Friend");
	ship->getComponent<Gun>()->rotation = 90.0f;
	ship->getComponent<Gun>()->setProjectileTexture("firefox.png");
	ship->sprite->swapTexture("yellowShip.png");
}

/*
Function: changeSong()
pre-condition: an irrklang ISoundEngine* must be instantiated
Description: reads state of input keys and changes song based on key state
*/
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