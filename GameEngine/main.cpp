#include "Engine.h"
#include "Shader.h"
#include "Mesh.h"
#include "Texture.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "Component.h"
#include "Input.h"
#include "Body.h"

void testFunction(GLFWwindow* window, GameObjectManager* gom, GameObject* myObj);
void fire(GameObjectManager* gom, GameObject* parent);

int main()
{
	//Engine::getInstance().run(); THE GOAL
	GLFWwindow* window = WindowManager::getInstance().getWindow();

	Engine* engine = &Engine::getInstance();
	
	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;
	gom->create();
	GameObject* myObj = gom->find("GameObject0");

	//PhysicsWorld* pw = &PhysicsWorld::getInstance();
	//pw->Step();
	//myObj->addComponent(new RigidBody(0.0f, 0.0f, 2));
	//myObj->getComponent<RigidBody>()->initBody();
	myObj->addComponent(new Body());


	myObj->transform->scalar.x = 100.0;
	myObj->transform->scalar.y = 100.0;

	while (!glfwWindowShouldClose(window))
	{
		testFunction(window, gom, myObj);
		Input::getInstance().processBasicInput(window);
		Renderer::setBackgroundColor(glm::vec4(0.1f, 0.3f, 0.3f, 1.0f));

		gom->update(engine->getDeltaTime());
		gom->draw();

		//pw->Step();
		WindowManager::getInstance().endFrame();
	}

	glfwTerminate();
	return 0;
}

void fire(GameObjectManager* gom, GameObject* parent)
{
	// starting to fuck up the architecture
	parent->addChild(gom->create(parent->transform->position));
}

void testFunction(GLFWwindow* window, GameObjectManager* gom, GameObject* myObj)
{
	//RigidBody* rb = myObj->getComponent<RigidBody>();
	Body* body = myObj->getComponent<Body>();


	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		//rb->translate(-0.25, 0.0f);
		//rb->getBody().ApplyForce(b2Vec2(-25.0f, 0.0f), rb->getBody().GetLocalCenter(), true);
		//myObj->transform->position.x -= 0.25;
		body->velocity.x -= 0.25f;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		body->velocity.x += 0.25f;
		//rb->getBody().ApplyForce(b2Vec2(25.0f, 0.0f), rb->getBody().GetLocalCenter(), true);
		//rb->translate(0.25, 0.0f);
		//myObj->transform->position.x += 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		body->velocity.y -= 0.25f;
		
		//rb->getBody().ApplyForce(b2Vec2(0.0f, -25.0f), rb->getBody().GetLocalCenter(), true);
		//rb->translate(0.0f, -0.25f);
		//myObj->transform->position.y -= 1000.25;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		body->velocity.y += 0.25f;
		//rb->getBody().ApplyForce(b2Vec2(0.0f, 25.0f), rb->getBody().GetLocalCenter(), true);
		//rb->translate(0.0f, 0.25f);
		//myObj->transform->position.y += 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		//rb->getBody().SetTransform(rb->getBody().GetWorldCenter(), rb->getBody().GetAngle() + 100.25f);
		myObj->transform->angle += 0.25;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		myObj->transform->angle -= 0.25;
	}
}