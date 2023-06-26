#include "base/Coordinate.h"

#include "game/Chunk.h"

int DtFIndex(int x, int y, int z) {
	int index = x * cHeight * cDepth + y * cDepth + z;
	return index;
}
