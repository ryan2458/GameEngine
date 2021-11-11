#include "Input.h"

Input::Input()
{
	
}

Input::~Input()
{
}

void Input::processBasicInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

