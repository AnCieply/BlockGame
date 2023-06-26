#include "render/Mesh.h"

void Mesh::build() {
	glCreateVertexArrays(1, &m_VAO);
	glCreateBuffers(1, &m_VBO);

	glNamedBufferData(m_VBO, sizeof(Vertex) * m_Vertices.size(), m_GetData(), GL_STATIC_DRAW);

	// Position.
	glEnableVertexArrayAttrib(m_VAO, 0);
	glVertexArrayAttribBinding(m_VAO, 0, 0);
	glVertexArrayAttribFormat(m_VAO, 0, 3, GL_FLOAT, false, 0);
	// UV.
	glEnableVertexArrayAttrib(m_VAO, 1);
	glVertexArrayAttribBinding(m_VAO, 1, 0);
	glVertexArrayAttribFormat(m_VAO, 1, 2, GL_UNSIGNED_SHORT, true, 3 * sizeof(float));

	glVertexArrayVertexBuffer(m_VAO, 0, m_VBO, 0, Vertex::getBytes());
}

void Mesh::addVertex(Vertex vertex) {
	m_Vertices.push_back(vertex);
}

void Mesh::reset() {
	m_Vertices.clear();
}

unsigned int Mesh::getHandle() {
	return m_VAO;
}

int Mesh::getVertexCount() {
	return m_Vertices.size();
}

Vertex* Mesh::m_GetData() {
	return &m_Vertices[0];
}
