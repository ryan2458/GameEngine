#include "WindowManager.h"
#include "callbacks.h"



WindowManager::WindowManager()
{
	std::cout << "LOG: New WindowManager Instantiated." << std::endl;
	initGLFW();
	mainWindow = createWindow();
	setCallbacks();
}

void WindowManager::initGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow* WindowManager::createWindow()
{
	GLFWwindow* window = glfwCreateWindow(800, 600, "Engine", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "ERROR: Failed to open window." << std::endl;
		return window;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // how does this work?
	{
		std::cout << "ERROR: Failed to initialize GLAD." << std::endl;
		return window;
	}

	std::cout << "LOG: Window creation success!" << std::endl;

	return window;
}

GLFWwindow* WindowManager::getWindow()
{
	if (mainWindow == NULL)
	{
		std::cout << "WARNING: Window is NULL" << std::endl;
	}

	return mainWindow;
}

void WindowManager::endFrame()
{
	glfwSwapBuffers(mainWindow);
	glfwPollEvents();
}

void WindowManager::setCallbacks()
{
	glfwSetFramebufferSizeCallback(mainWindow, framebuffer_size_callback);
}
