#include "game/Chunk.h"

#include "base/Coordinate.h"

#include <iostream>

Chunk::Chunk()
	: m_Position(0, 0), m_Blocks(cMaxBlocks, AIR) {  }

void Chunk::generate() {
	for (int x = 0; x < cWidth; x++) {
		for (int y = 0; y < cHeight; y++) {
			for (int z = 0; z < cDepth; z++) {
				int index = DtFIndex(x, y, z);
				BlockType b = AIR;
				if (y < 64) b = STONE;
				else if (y < 127) b = DIRT;
				else if (y == 128) b = GRASS;
				m_Blocks[index] = b;
			}
		}
	}
}

void Chunk::generateMesh() {

}

void Chunk::setPosition(glm::vec2& position) {
	m_Position = position;
}

glm::vec2& Chunk::getPosition() {
	return m_Position;
}

void Chunk::setBlock(glm::vec3& position, BlockType block) {
	m_Blocks[DtFIndex(position.x, position.y, position.z)] = block;
}

BlockType Chunk::getBlock(glm::vec3& position) {
	return m_Blocks[DtFIndex(position.x, position.y, position.z)];
}
