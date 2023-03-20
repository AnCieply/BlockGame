#include "render/Renderer.h"

Renderer* Renderer::m_Ptr = nullptr;

Renderer::Renderer() {  }

Renderer* Renderer::getInstance() {
	if (m_Ptr == nullptr) {
		m_Ptr = new Renderer();
		return m_Ptr;
	}
	else {
		return m_Ptr;
	}
}

void Renderer::render(Mesh mesh, Shader shader, Texture texture) {
	glUseProgram(shader.getHandle());
	glBindTextureUnit(0, texture.getHandle());
	glBindVertexArray(mesh.getHandle());
	glDrawArrays(GL_TRIANGLES, 0, mesh.getVertexCount());
}
