#pragma once

#include <vector>
#include "render/primitive.h"

class Mesh {
private:
	std::vector<Vertex> m_Vertices;

	unsigned int m_VAO;
	unsigned int m_VBO;

	Vertex* m_GetData();
public:
	void build();
	void addVertex(Vertex vertex);
	void reset();

	unsigned int getHandle();
	int getVertexCount();
};
