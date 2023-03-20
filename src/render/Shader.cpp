#include "render/Shader.h"

#include <glad/glad.h>

Shader::Shader()
	: m_Handle(0) {  }

Shader::Shader(unsigned int handle) 
	: m_Handle(handle) {  }

unsigned int Shader::getHandle() {
	return m_Handle;
}

void Shader::setVec4(const std::string& name, float v0, float v1, float v2, float v3) {
	int location = glGetUniformLocation(m_Handle, name.c_str());
	glUseProgram(m_Handle);
	glUniform4f(location, v0, v1, v2, v3);
}

void Shader::setMat4(const std::string& name, const glm::mat4& matrix) {
	int location = glGetUniformLocation(m_Handle, name.c_str());
	glUseProgram(m_Handle);
	glUniformMatrix4fv(location, 1, true, &matrix[0][0]);
}
