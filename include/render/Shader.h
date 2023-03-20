#pragma once

#include <glm/glm.hpp>
#include <string>

class Shader {
private:
	unsigned int m_Handle;
public:
	Shader();
	Shader(unsigned int handle);
	unsigned int getHandle();

	void setVec4(const std::string& name, float v0, float v1, float v2, float v3);
	void setMat4(const std::string& name, const glm::mat4& matrix);
};
