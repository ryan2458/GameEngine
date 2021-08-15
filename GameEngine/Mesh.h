#ifndef MESH_H
#define MESH_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

class Mesh
{
private:
	unsigned int vbo;
	unsigned int vao; 

	void initRenderData();
public:
	Mesh();
	~Mesh();

	void bind() const;
	void unbind() const;

};

#endif