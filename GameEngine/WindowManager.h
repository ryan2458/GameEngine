#ifndef WINDOW_MANAGER_H
#define WINDOW_MANAGER_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

class WindowManager {
	//----Singleton Pattern-----
private:
	WindowManager();
	GLFWwindow* mainWindow;
public:
	static WindowManager& getInstance()
	{
		static WindowManager instance;
		return instance;
	}

	WindowManager(WindowManager const&)  = delete;
	void operator=(WindowManager const&) = delete;
	
	//----------------------------
	
	// calls GLFW initialization functions
	void initGLFW();
	// creates a window
	GLFWwindow* createWindow();
	// returns a pointer to the main window
	GLFWwindow* getWindow();
	// calls all functions that set glfw callbacks at once
	void setCallbacks(GLFWwindow* window);
};

#endif