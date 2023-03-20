#include "render/Texture.h"

Texture::Texture()
	: m_Handle(0) {  }

Texture::Texture(unsigned int handle)
	: m_Handle(handle) {  }

unsigned int Texture::getHandle() {
	return m_Handle;
}
