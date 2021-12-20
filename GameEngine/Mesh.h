/*
Author: Ryan Aloof
File: Mesh.h
Description: Contains header for description of a Mesh in OpenGL
*/

#ifndef MESH_H
#define MESH_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Mesh
{
private:
	// vertex buffer object id
	unsigned int vbo;
	// vertex array object id
	unsigned int vao; 

	// initializes the rendering data for a Mesh
	void initRenderData();
public:
	Mesh();
	~Mesh();

	// binds the Mesh using the associated vao id
	void bind() const;
	// unbinds the mesh
	void unbind() const;

};

#endif