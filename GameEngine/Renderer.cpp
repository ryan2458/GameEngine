#include "Renderer.h"
#include "Sprite.h"

void Renderer::render(GLFWwindow* window)
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

void Renderer::renderTextures()
{
	GLint textureUnits;
	glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &textureUnits);

	for (int i = 0; i < textureUnits; ++i)
	{
		glActiveTexture(GL_TEXTURE0 + i);
		glBindTexture(GL_TEXTURE_2D, GL_TEXTURE0 + i);
	}
}