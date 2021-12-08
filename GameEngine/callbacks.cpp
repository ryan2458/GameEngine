/*
Author: Ryan Aloof
File: callbacks.cpp
Description: Contains definitions for OpenGL callback(s)
*/

#include "callbacks.h"
#include "Renderer.h"

// Function: framebuffer_size_callback()
// Params: A pointer to a GLFW window, the width of the window, the height of the window
// Description: Sets the viewport and projection matrix when the window gets resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	Renderer::getInstance().setProjectionMatrix(width, height); // concern about type conversion?
}