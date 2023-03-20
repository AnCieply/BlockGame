#pragma once

#include <glad/glad.h>

struct Vertex {
	float x, y, z;
	unsigned char r, g, b, a;
	unsigned short u, v;

	static unsigned char getBytes();
};
