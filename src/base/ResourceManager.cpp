#include "base/ResourceManager.h"

#include <glad/glad.h>
#include <stb_image/stb_image.h>
#include <fstream>
#include <string>
#include <vector>

std::map<std::string, Shader> ResourceManager::m_Shaders;
std::map<std::string, Texture> ResourceManager::m_Textures;

unsigned int ResourceManager::loadShader(ShaderType type, const std::string& filePath) {
	std::string source;
	std::ifstream file(filePath, std::ios::in);
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			source.append(line + "\n");
		}
		file.close();
	}

	const char* cSource = source.c_str();
	unsigned int shader = glCreateShader(type);
	glShaderSource(shader, 1, &cSource, nullptr);
	glCompileShader(shader);

	int success;
	char infoLog[1024];
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
		std::cerr << "Shader compile error: " << infoLog << "\n";
	}

	return shader;
}

Shader ResourceManager::createShaderProgram(const std::string& name, const std::string& vertPath, const std::string& fragPath) {
	unsigned int vertexShader = loadShader(GL_VERTEX_SHADER, vertPath);
	unsigned int fragmentShader = loadShader(GL_FRAGMENT_SHADER, fragPath);
	
	unsigned int shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	int success;
	char infoLog[1024];
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 1024, nullptr, infoLog);
		std::cerr << "Shader program link error: " << infoLog << "\n";
	}

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	Shader shader(shaderProgram);

	m_Shaders.insert(std::pair<std::string, Shader>(name, shader));
	return shader;
}

Texture ResourceManager::createTexture(const std::string& name, const std::string& texturePath) {
	unsigned int tex;
	glCreateTextures(GL_TEXTURE_2D, 1, &tex);

	glTextureParameteri(tex, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTextureParameteri(tex, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTextureParameteri(tex, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTextureParameteri(tex, GL_TEXTURE_WRAP_T, GL_REPEAT);

	stbi_set_flip_vertically_on_load(true);
	int width, height, nrChannels;
	unsigned char* data = stbi_load(texturePath.c_str(), &width, &height, &nrChannels, 0);

	if (data) {
		glTextureStorage2D(tex, 1, GL_RGBA8, width, height);
		glTextureSubImage2D(tex, 0, 0, 0, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateTextureMipmap(tex);
	} else {
		std::cerr << "Resource Manager error: Failed to load texture.\n";
	}

	stbi_image_free(data);

	Texture texture(tex);
	m_Textures.insert(std::pair<std::string, Texture>(name, texture));
	return texture;
}

Shader ResourceManager::getShader(const std::string& name) {
	return m_Shaders[name];
}

Texture ResourceManager::getTexture(const std::string& name) {
	return m_Textures[name];
}

void ResourceManager::clear() {
	for (std::pair<std::string, Shader> pair : m_Shaders) {
		glDeleteProgram(pair.second.getHandle());
	}
	m_Shaders.clear();

	for (std::pair<std::string, Texture> pair : m_Textures) {
		const unsigned int handle = pair.second.getHandle();
		glDeleteTextures(1, &handle);
	}
	m_Textures.clear();

	std::cout << "Resource Manager: All resources cleared and destroyed.\n";
}
