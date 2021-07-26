#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>

#include "callbacks.h"

class Engine {
public:
	Engine();
	// calls GLFW initialization functions
	void initGLFW();
	// it's in the fucking name
	GLFWwindow* createWindow();
	// calls all functions that set glfw callbacks at once
	void setCallbacks(GLFWwindow* window);
	// begins the render loop
	void render(GLFWwindow* window);
	// calls initialization, rendering, and basic setup functions 
	void runEngine();
};
