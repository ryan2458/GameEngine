#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include "Engine.h"
#include <vector>

class VertexBuffer
{
private:
	unsigned int bufferId;

public:
	VertexBuffer(const void* data, unsigned int size);
	~VertexBuffer();

	void Bind() const;
	void Unbind() const;
};


#endif
