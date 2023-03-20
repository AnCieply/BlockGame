#pragma once

#include "render/Mesh.h"
#include "render/Shader.h"
#include "render/Texture.h"

class Renderer {
private:
	static Renderer* m_Ptr;

	Renderer();
public:
	Renderer(const Renderer& obj) = delete;

	static Renderer* getInstance();

	void render(Mesh mesh, Shader shader, Texture texture);
};
