#ifndef RENDERER_H
#define RENDERER_H

#include "Engine.h"

class Renderer {
private:
	Renderer() { std::cout << "LOG: New Renderer Instantiated." << std::endl; }
public:
	static Renderer& getInstance()
	{
		static Renderer instance;
		return instance;
	}

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete; // deletes instance if we reassign later

	// begins the render loop
	void render(GLFWwindow* window);
	void renderTextures();
};

#endif