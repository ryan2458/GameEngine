/*
Author: Ryan Aloof
Description: Runs unit tests to check if application started successfully
*/

#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include "Engine.h"
#include "WindowManager.h"
#include "Renderer.h"
#include "Sprite.h"

class UnitTest
{
public:
	bool passed();
	bool TestEngine();
	bool TestGameObjectManager();
	bool TestRenderer();
	bool TestWindowManager();
	bool TestSprite(const std::string& texturePath);
};

#endif

inline bool UnitTest::passed()
{
	return TestEngine() && TestGameObjectManager() && TestWindowManager() && TestRenderer()
		&& TestSprite("awesomeface.png");
}

inline bool UnitTest::TestEngine()
{
	Engine* engine = &Engine::getInstance();

	return engine != nullptr;
}

inline bool UnitTest::TestGameObjectManager()
{
	GameObjectManager* gom = &Engine::getInstance().gameObjectManager;

	return gom != nullptr;
}

inline bool UnitTest::TestRenderer()
{
	Renderer* renderer = &Renderer::getInstance();

	return renderer != nullptr;
}

inline bool UnitTest::TestWindowManager()
{
	WindowManager* wManager = &WindowManager::getInstance();

	return wManager != nullptr;
}

inline bool UnitTest::TestSprite(const std::string& texturePath)
{
	Sprite sprite(texturePath);

	return sprite.getTexture()->getTexturePath() == texturePath;
}