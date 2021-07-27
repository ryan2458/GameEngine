#ifndef RENDERER_H
#define RENDERER_H

#include "Engine.h"

class Renderer {
private:
	Renderer() {}
public:
	static Renderer& getInstance()
	{
		static Renderer instance;
		return instance;
	}

	Renderer(Renderer const&) = delete;
	void operator=(Renderer const&) = delete;

	// begins the render loop
	void render(GLFWwindow* window);
};

#endif