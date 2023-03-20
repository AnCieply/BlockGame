#include "render/primitive.h"

unsigned char Vertex::getBytes() {
	return
		3 * sizeof(float) + 
		4 * sizeof(unsigned char) +
		2 * sizeof(unsigned short);
}
