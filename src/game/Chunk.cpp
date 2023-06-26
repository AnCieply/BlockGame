#include "game/Chunk.h"

#include <iostream>

Chunk::Chunk()
	: m_Position(0, 0), m_Blocks(cMaxBlocks, 0) {  }
