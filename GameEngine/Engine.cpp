#include "Engine.h"
#include "callbacks.h"
#include <iostream>

Engine::Engine() { };

void Engine::initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* Engine::createWindow()
{
	GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to open window." << std::endl;
		return window;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // how does this work?
	{
		std::cout << "Failed to initialize GLAD." << std::endl;
		return window;
	}

	std::cout << "Window creation success!" << std::endl;

	return window;
}

void Engine::runEngine()
{
	initGLFW();
	GLFWwindow* window = createWindow();

	if (window == NULL)
	{
		return;
	}

	setCallbacks(window);
	render(window);
}

void Engine::setCallbacks(GLFWwindow* window)
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Engine::render(GLFWwindow* window)
{
	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
}