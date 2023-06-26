#pragma once

#include <glad/glad.h>

struct Vertex {
	float x, y, z;
	unsigned short u, v;

	static unsigned char getBytes();
};
