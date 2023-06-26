#pragma once
#include <vector>
#include <glm/glm.hpp>

#include "game/Block.h"
#include "render/Mesh.h"

const int cWidth = 16;
const int cDepth = 16;
const int cHeight = 256;
const int cMaxBlocks = 65536;

class Chunk {
public:
	Chunk();

	void generate();
	void generateMesh();

	void setPosition(glm::vec2& position);
	glm::vec2& getPosition();

	void setBlock(glm::vec3& position, BlockType block);
	BlockType getBlock(glm::vec3& position);
private:
	glm::vec2 m_Position;
	std::vector<BlockType> m_Blocks;
	Mesh m_Mesh;
};
