#include "render/primitive.h"

unsigned char Vertex::getBytes() {
	return
		3 * sizeof(float) + 
		2 * sizeof(unsigned short);
}
