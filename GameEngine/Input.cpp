/*
Authors: Anne Tansengco
*/

#include "Input.h"

Input::Input()
{
	// :()
}

Input::~Input()
{
	// :)
}

void Input::processBasicInput(GLFWwindow* window)
{
	// *********** MISC ***********

	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}

	// ****************************

	// *********** MOVEMENT ************

	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
	{
		InputState::KeyPressed::left = true;
	}
	else
	{
		InputState::KeyPressed::left = false;
	}

	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
	{
		InputState::KeyPressed::right = true;
	}
	else
	{
		InputState::KeyPressed::right = false;
	}

	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
	{
		InputState::KeyPressed::up = true;
	}
	else
	{
		InputState::KeyPressed::up = false;
	}

	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
	{
		InputState::KeyPressed::down = true;
	}
	else
	{
		InputState::KeyPressed::down = false;
	}

	if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
	{
		InputState::KeyPressed::e = true;
	}
	else
	{
		InputState::KeyPressed::e = false;
	}

	if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
	{
		InputState::KeyPressed::q = true;
	}
	else
	{
		InputState::KeyPressed::q = false;
	}

	// **************************


	// ****** SONG SELECTION BUTTONS **********

	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
	{
		InputState::KeyPressed::key_1 = true;
	}
	else
	{
		InputState::KeyPressed::key_1 = false;
	}

	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
	{
		InputState::KeyPressed::key_2 = true;
	}
	else
	{
		InputState::KeyPressed::key_2 = false;
	}

	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
	{
		InputState::KeyPressed::key_3 = true;
	}
	else
	{
		InputState::KeyPressed::key_3 = false;
	}

	if (glfwGetKey(window, GLFW_KEY_4) == GLFW_PRESS)
	{
		InputState::KeyPressed::key_4 = true;
	}
	else
	{
		InputState::KeyPressed::key_4 = false;
	}

	// *****************************

	
	// ******** WEAPON BUTTONS **********

	if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		InputState::KeyPressed::space = true;
	}
	else
	{
		InputState::KeyPressed::space = false;
	}
}

