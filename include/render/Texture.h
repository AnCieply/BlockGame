#pragma once

class Texture {
private:
	unsigned int m_Handle;

public:
	Texture();
	Texture(unsigned int handle);
	unsigned int getHandle();
};
