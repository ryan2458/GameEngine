#ifndef MESH_H
#define MESH_H

#include "Engine.h"
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