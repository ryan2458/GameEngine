#include "WindowManager.h"
#include "callbacks.h"

WindowManager::WindowManager()
{
	initGLFW();
	mainWindow = createWindow();
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

GLFWwindow* WindowManager::getWindow()
{
	if (mainWindow == NULL)
	{
		std::cout << "Window is NULL" << std::endl;
	}

	return mainWindow;
}

void WindowManager::setCallbacks(GLFWwindow* window)
{
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}
