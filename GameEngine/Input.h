#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <vector>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

class Input
{
private:
	Input();
	~Input();
public:
	static Input& getInstance()
	{
		static Input instance;
		return instance;
	}

	Input(Input const&) = delete;
	void operator=(Input const&) = delete;

	void processBasicInput(GLFWwindow* window);
};

#endif 