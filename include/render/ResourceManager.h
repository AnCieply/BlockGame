#pragma once

#include <iostream>
#include <map>

#include "Shader.h"
#include "Texture.h"

using ShaderType = unsigned int;

class ResourceManager {
private:
	static std::map<std::string, Shader> m_Shaders;
	static std::map<std::string, Texture> m_Textures;

	static unsigned int loadShader(ShaderType type, const std::string& filePath);
public:
	static Shader createShaderProgram(const std::string& name, const std::string& vertPath, const std::string& fragPath);
	static Texture createTexture(const std::string& name, const std::string& texturePath);

	static Shader getShader(const std::string& name);
	static Texture getTexture(const std::string& name);

	static void clear();
};
